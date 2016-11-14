%{ 
  	#include "ast.h"
  	#include "semantic.h"
  	
  	extern int yylex(void);
  	extern char* yytext;
  	extern int yylineno;

	typedef union{	
		int numI;  /* 变量值 */
		float numF;
		int index;  /* 用于存放 变量数组索引 或 一元操作符值 或 多元操作符索引 */
		Node *node; /* 结点地址 */
	}yystype;
	#define YYSTYPE yystype

  	void yyerror(char* s);
%}  

%union{
	int numI; /* 变量值 */
	float numF;
	int index; /* 变量数组索引 */
	Node *node; /* 结点地址 */
};

%locations
%start Program0
%token <numI> INT_NUM 
%token <numF> FLOAT_NUM
%token <index> ID INT FLOAT STRUCT RETURN IF ELSE WHILE GE LE Equal Unequal And Or 

%right '='
%left Or
%left And
%left RELOP
%left GE LE Equal Unequal '>' '<'
%left '+' '-'
%left '*' '/'
%right '!' UMINUS
%left '(' ')' '[' ']' '.'
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%type<node> Program ExtDefList ExtDef ExtDecList Specifier StructSpecifier OptTag Tag VarDec FunDec VarList ParamDec CompSt StmtList
%type<node> Stmt DefList Def DecList Dec Exp Relop Args  TYPE
%type<index> '=' '>' '<' '+' '-' '*' '/' ',' ';' '(' ')' '[' ']' '{' '}' '.' '!'

%%
Program0: Program {NodeExecute($1, 0); NodeFree($1);} 
	;

Program: ExtDefList {$$ = set_vn("Program", 1, $1);}
	;

ExtDefList: {$$ = NULL;}
	| ExtDef ExtDefList {$$ = set_vn("ExtDefList", 2, $1, $2);}
	;

ExtDef: Specifier ExtDecList ';' //变量定义:检查是否重定义Error type 3
		{
			$$ = set_vn("ExtDef", 3, $1, $2, set_terminal($3));
			addType($1->type);
		}  
	| Specifier ';' {$$ = set_vn("ExtDef", 2, $1, set_terminal($2));}
	| Specifier FunDec ';'     //函数声明
		{
			$$ = set_vn("ExtDef", 3, $1, $2, set_terminal($3));
			Func *pFunc = funcFind($2->index);
			if(pFunc && pFunc->tag == 1)  //申明不一致
				printf("Semantic Error at Line %d: Inconsistent declaration of function \"%s\".\n", yylineno, G_Var[pFunc->nameIndex].mark);   
			else
				funcDeclare($1->type, $2->index, yylineno);
		}
	| Specifier FunDec CompSt  //函数定义:检查实际返回类型与函数类型是否匹配Error type 8
		{
			$$ = set_vn("ExtDef", 3, $1, $2, $3);
			addLevel($2->index);
			Func* pFunc = funcFind($2->index);
			if(pFunc){
				if(pFunc->tag == 1){
					if(pFunc->pnum != pNum || pFunc->type != rtype)  //申明与定义不一致
						printf("Semantic Error at Line %d: Inconsistent definition with declaration of function \"%s\".\n", yylineno, G_Var[pFunc->nameIndex].mark);
					else{
						pFunc->tag = 2;
						if(pFunc->type!=0 && rtype!=0 && rtype != pFunc->type)   //实际返回类型和函数定义的返回类型比较
                			printf("Semantic Error at Line %d: Type mismatched for return.\n", yylineno);
					}
				}
				else{
					printf("Semantic Error at Line %d: Redefined Function \"%s\".\n", yylineno, G_Var[$2->index].mark);
				}
			}
			else		
				funcDefine($1->type, $2->index, yylineno);
			rtype = 0;
		}
	| Specifier error ';' 
	{
		$$ = set_vn("ExtDef", 3, $1, set_terminal(0), set_terminal($3));
		addType($1->type);
		printf("Syntax Error at Line %d: Something wrong with ExtDecList before \";\".\n", @2.last_line);
	}
	| error ';'
	{
		$$ = set_vn("ExtDef", 2, set_terminal(0), set_terminal($2));
		printf("Syntax Error at Line %d: Something wrong with Specifier before \";\".\n", @1.last_line);
	}
	;

ExtDecList: VarDec 
	{
		$$ = set_vn("ExtDecList", 1, $1); 
		$$->index = $1->index;
		if(varFind($1->index) != NULL && sameLevel($1->index))
			printf("Semantic Error at Line %d: Redefined Variable \"%s\".\n", yylineno, G_Var[$1->index].mark);
		else
			varTable($1->index, $1->size);
	}
	| VarDec ',' ExtDecList 
	{
		$$ = set_vn("ExtDecList", 3, $1, set_terminal($2), $3); 
		$$->index = $1->index;
		if(varFind($1->index) != NULL && sameLevel($1->index))
			printf("Semantic Error at Line %d: Redefined Variable \"%s\".\n", yylineno, G_Var[$1->index].mark);
        else
        	varTable($1->index, $1->size);
	}
	;

Specifier: TYPE {$$ = set_vn("Specifier", 1, $1); $$->type = $1->type;}
	| StructSpecifier {$$ = set_vn("Specifier", 1, $1); $$->type = $1->type;}
	;

TYPE: INT      {$$ = set_vn("TYPE", 1, set_terminal($1)); $$->type = TYPE_NUM;}
	| FLOAT    {$$ = set_vn("TYPE", 1, set_terminal($1)); $$->type = TYPE_FLOAT;}
	;

StructSpecifier: STRUCT OptTag '{' DefList '}' //结构体定义:检查是否重定义Error type 16
				{
					$$ = set_vn("StructSpecifier", 5, set_terminal($1), $2, set_terminal($3), $4, set_terminal($5));
					$$->type = $2->index;
					addLevel($1);
					if($2!=NULL && strucFind($2->index))
						printf("Semantic Error at Line %d: Duplicated name \"%s\".\n", yylineno, G_Var[$2->index].mark);
					else if($2 != NULL)
						strucTable(1, $2);
				}
	| STRUCT Tag   //结构体引用:检查是否未定义就引用Error type 17
		{
			$$ = set_vn("StructSpecifier", 2, set_terminal($1), $2);
			$$->type = $2->index;
			if(!strucFind($2->index))
				printf("Semantic Error at Line %d: undefined structure \"%s\".\n", yylineno, G_Var[$2->index].mark);
			$$->type = $2->index;
		}
	;

OptTag: {$$ = NULL;}
	| ID {$$ = set_vn("OptTag", 1, set_var($1)); $$->index = $1;}
	;

Tag: ID {$$ = set_vn("Tag", 1, set_var($1)); $$->index = $1; $$->kind = TYPE_STRUCT;}
	;

VarDec: ID 
	{
		$$ = set_vn("VarDec", 1, set_var($1));
		$$->index = $1;
		$$->size = 0;
		memNum += 1;
		listNum += 1;
	}
	| VarDec '[' INT_NUM ']' 
	{
		$$ = set_vn("VarDec", 4, $1, set_terminal($2), set_int($3), set_terminal($4));
		$$->index = $1->index;
		$$->size = $3;
		memNum += 1;
		listNum += 1;
	}
	| VarDec '[' error ']' 
	{
		$$ = set_vn("VarDec", 4, $1, set_terminal($2), set_terminal(0), set_terminal($4));
		$$->index = $1->index;
		$$->size = 0;
		memNum += 1;
		listNum += 1;
		printf("Syntax Error at Line %d: Missing a integer between [].\n", @3.last_line);
	}
	;

FunDec: ID '(' VarList ')'  //函数定义:检查是否重复定义Error type 4
	{
		$$ = set_vn("FunDec", 4, set_var($1), set_terminal($2), $3, set_terminal($4));
		$$->index = $1;
		addLevel($1);
	}
	| ID '(' error ')' 
	{
		$$ = set_vn("FunDec", 4, set_var($1), set_terminal($2), set_terminal(0), set_terminal($4));
		$$->index = $1;
		addLevel($1);
		printf("Syntax Error at Line %d: Something wrong with VarList between ().\n", @3.last_line);
	}
	| ID '(' ')'  //函数定义:检查是否重复定义Error type 4
	{
		$$ = set_vn("FunDec", 3, set_var($1), set_terminal($2), set_terminal($3));
		$$->index = $1;
	}
	| ID error ')' 
	{
		$$ = set_vn("FunDec", 3, set_var($1), set_terminal(0), set_terminal($3));
		$$->index = $1;
		printf("Syntax Error at Line %d: Missing \"(\".\n", @2.last_line);
	}
	;

VarList: ParamDec ',' VarList {$$ = set_vn("VarList", 3, $1, set_terminal($2), $3);}
	| ParamDec {$$ = set_vn("VarList", 1, $1);}
	| error ',' VarList 
	{
		$$ = set_vn("VarList", 3, set_terminal(0), set_terminal($2), $3);
		printf("Syntax Error at Line %d: Something wrong with ParamDec.\n", @1.last_line);
	}
	;

ParamDec: Specifier VarDec 
	{
		$$ = set_vn("ParamDec", 2, $1, $2);
		if(varFind($2->index) != NULL && sameLevel($2->index)){
			printf("Semantic Error at Line %d: Redefined Variable \"%s\".\n", yylineno, G_Var[$2->index].mark);
		}
        else{
        	varTable($2->index, $2->size);
        	addType($1->type);
        }
		pNum += 1;
	}
	;

CompSt: '{' DefList StmtList '}' {$$ = set_vn("CompSt", 4, set_terminal($1), $2, $3, set_terminal($4)); }
	| error '}' 
	{
		$$ = set_vn("CompSt", 2, set_terminal(0), set_terminal($2));
		printf("Syntax Error at Line %d: Missing \"{\".\n", @1.first_line);
	}
	;

StmtList: {$$ = NULL;}
	| Stmt StmtList {$$ = set_vn("StmtList", 2, $1, $2); $$->type = $1->type; }
	;

Stmt: Exp ';'                                   {$$ = set_vn("Stmt", 2, $1, set_terminal($2));}
	| error ';' 
	{
		$$ = set_vn("Stmt", 2, set_terminal(0), set_terminal($2));
		printf("Syntax Error at Line %d: Something wrong with expression before \";\".\n", @1.last_line);
	}
	| CompSt                                    {$$ = set_vn("Stmt", 1, $1);}
	| RETURN Exp ';'                            {$$ = set_vn("Stmt", 3, set_terminal($1), $2, set_terminal($3)); rtype = $2->type; }
	| RETURN error ';' 
	{
		$$ = set_vn("Stmt", 3, set_terminal($1), set_terminal(0), set_terminal($3)); 
		printf("Syntax Error at Line %d: Something wrong with expression before \";\".\n", @2.last_line);
	}
	| IF '(' Exp ')' Stmt %prec LOWER_THAN_ELSE {$$ = set_vn("Stmt", 5, set_terminal($1), set_terminal($2), $3, set_terminal($4), $5);}
	| IF '(' error ')' Stmt %prec LOWER_THAN_ELSE
	{
		$$ = set_vn("Stmt", 5, set_terminal($1), set_terminal($2), set_terminal(0), set_terminal($4), $5);
		printf("Syntax Error at Line %d: Something wrong with expression between ().\n", @3.last_line);
	}
	| IF error ')' Stmt %prec LOWER_THAN_ELSE 
	{
		$$ = set_vn("Stmt", 4, set_terminal($1), set_terminal(0), set_terminal($3), $4);
		printf("Syntax Error at Line %d: Missing \"(\".\n", @2.last_line);
	}
	| IF '(' Exp ')' Stmt ELSE Stmt             {$$ = set_vn("Stmt", 7, set_terminal($1), set_terminal($2), $3, set_terminal($4), $5, set_terminal($6), $7);}
	| IF '(' Exp ')' error ELSE Stmt 
	{
		$$ = set_vn("Stmt", 7, set_terminal($1), set_terminal($2), $3, set_terminal($4), set_terminal(0), set_terminal($6), $7);
		printf("Syntax Error at Line %d: Missing \";\".\n", @5.last_line);
	}
	| IF '(' error ')' Stmt ELSE Stmt 
	{
		$$ = set_vn("Stmt", 7, set_terminal($1), set_terminal($2), set_terminal(0), set_terminal($4), $5, set_terminal($6), $7);
		printf("Syntax Error at Line %d: Something wrong with expression between ().\n", @3.last_line);
	}
	| IF error ')' Stmt ELSE Stmt 
	{
		$$ = set_vn("Stmt", 6, set_terminal($1), set_terminal(0), set_terminal($3), $4, set_terminal($5), $6);
		printf("Syntax Error at Line %d: missing \"(\".\n", @2.last_line);
	}
	| WHILE '(' Exp ')' Stmt                    {$$ = set_vn("Stmt", 5, set_terminal($1), set_terminal($2), $3, set_terminal($4), $5);}
	| WHILE '(' error ')' Stmt 
	{
		$$ = set_vn("Stmt", 5, set_terminal($1), set_terminal($2), set_terminal(0), set_terminal($4), $5);
		printf("Syntax Error at Line %d: Something wrong with expression between ().\n", @3.last_line);
	}
	| WHILE error ')' Stmt {
		$$ = set_vn("Stmt", 4, set_terminal($1), set_terminal(0), set_terminal($3), $4);
		printf("Syntax Error at Line %d: Missing \"(\".\n", @2.last_line);
	}
	;

DefList: {$$ = NULL;}
	| Def DefList {$$ = set_vn("DefList", 2, $1, $2);}
	;

Def: Specifier DecList ';'  //变量或数组定义:检查变量是否重定义 Error type 3
	{
		$$ = set_vn("Def", 3, $1, $2, set_terminal($3));
		addType($1->type);
	}
	| Specifier error ';' 
	{
		$$ = set_vn("Def", 3, $1, set_terminal(0), set_terminal($3));
		addType($1->type);
		printf("Syntax Error at Line %d: Unnecessary \",\".\n", @2.last_line);
	}
	;

DecList: Dec {$$ = set_vn("DecList", 1, $1); $$->index = $1->index;}
	| Dec ',' DecList 
	{
		$$ = set_vn("DefList", 3, $1, set_terminal($2), $3);
		$$->index = $1->index;
	}
	| error ',' DecList 
	{
		$$ = set_vn("DefList", 3, set_terminal(0), set_terminal($2), $3);
		printf("Syntax Error at Line %d: Something wrong with declaration.\n", @1.last_line);
	}
	;

Dec: VarDec 
	{
		$$ = set_vn("Dec", 1, $1);
		$$->index = $1->index; 
		if(varFind($1->index) != NULL && sameLevel($1->index))
			printf("Semantic Error at Line %d: Redefined Variable \"%s\".\n", yylineno, G_Var[$1->index].mark);
        else
        	varTable($1->index, $1->size);

	}
	| VarDec '=' Exp 
	{
		$$ = set_vn("Dec", 3, $1, set_terminal($2), $3);
		$$->index = $1->index;
		if(varFind($1->index) != NULL && sameLevel($1->index))
			printf("Semantic Error at Line %d: Redefined Variable \"%s\".\n", yylineno, G_Var[$1->index].mark);
        else
        	varTable($1->index, $1->size);
	}
	| error '=' Exp 
	{
		$$ = set_vn("Dec", 3, set_terminal(0), set_terminal($2), $3);
		$$->index = $3->index;
		printf("Syntax Error at Line %d: Missing the variable.\n", @1.last_line);
	}
	;

Exp:  Exp '=' Exp  //检查等号左右类型匹配判断Error type 5, 操作符左右类型Error type 7
	{
		$$ = set_vn("Exp", 3, $1, set_terminal($2), $3);
		$$->type = $1->type;
		if($1->type < 0 && $3->type < 0 && ($1->type != $3->type || $1->size != 0 || $3->size != 0))
			printf("Semantic Error at Line %d: Type mismatched for assignment.\n", yylineno);
		else if($1->type>=0 && $3->type>=0){
			//printf("%d %d %s %s\n\n", $1->type, $2->type, G_Var[$1->type].mark, G_Var[$2->type].mark);
			if(!strucMatch($1->type, $3->type))
				printf("Semantic Error at Line %d: Type mismatched for assignment.\n", yylineno);
		}
		if($1->kind == TYPE_CONST)
			printf("Semantic Error at Line %d: The left-hand side of an assignment must be a variable.\n", yylineno);
	}
	| Exp And Exp 
	{
		$$ = set_vn("Exp", 3, $1, $2, $3); 
		$$->type = $1->type; 
		$$->size = $1->size;
		if($1->type != TYPE_NUM || $3->type != TYPE_NUM)
			printf("Semantic Error at Line %d: Only integer can be used as Bool.\n", yylineno);	
	}
	| Exp Or Exp  
	{ 
		$$ = set_vn("Exp", 3, $1, $2, $3); 
		$$->type = $1->type; 
		$$->size = $1->size;
		if($1->type != TYPE_NUM || $3->type != TYPE_NUM)
			printf("Semantic Error at Line %d: Only integer can be used as Bool.\n", yylineno);	
	}
	| Exp Relop Exp {$$ = set_vn("Exp", 3, $1, $2, $3); $$->type = $1->type; $$->size = $1->size;}
	| Exp '+' Exp 
	{
		$$ = set_vn("Exp", 3, $1, set_terminal($2), $3);
		$$->type = $1->type;
		$$->size = $1->size;
		if($1->type < 0 && $3->type < 0 && ($1->type != $3->type || $1->size != 0 || $3->size != 0))
			printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
	}
	| Exp '-' Exp 
	{
		$$ = set_vn("Exp", 3, $1, set_terminal($2), $3);
		$$->type = $1->type;
		$$->size = $1->size;
		if($1->type < 0 && $3->type < 0 && ($1->type != $3->type || $1->size != 0 || $3->size != 0))
			printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
	}
	| Exp '*' Exp 
	{
		$$ = set_vn("Exp", 3, $1, set_terminal($2), $3);
		$$->type = $1->type;
		$$->size = $1->size;
		if($1->type < 0 && $3->type < 0 && ($1->type != $3->type || $1->size != 0 || $3->size != 0))
			printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
	}
	| Exp '/' Exp 
	{
		$$ = set_vn("Exp", 3, $1, set_terminal($2), $3);
		$$->type = $1->type;
		$$->size = $1->size;
		if($1->type < 0 && $3->type < 0 && ($1->type != $3->type || $1->size != 0 || $3->size != 0))
			printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
	}
	| '(' Exp ')'     {$$ = set_vn("Exp", 3, set_terminal($1), $2, set_terminal($3)); $$->type = $2->type; $$->size = 0;}
	| error ')' 
	{
		$$ = set_vn("Exp", 2, set_terminal(0), set_terminal($2)); 
		$$->size = 0;
		printf("Syntax Error at Line %d: Missing \"(\".\n", @1.last_line);
	}
	| '-' Exp %prec UMINUS  
	{
		$$ = set_vn("Exp", 2, set_terminal($1), $2); 
		$$->type = $2->type; 
		$$->size = 0;
		if($$->type>0)
			printf("Semantic Error at Line %d: Only integer and float can use \"-\".\n", yylineno);	
	}
	| '!' Exp         
	{
		$$ = set_vn("Exp", 2, set_terminal($1), $2); 
		$$->type = $2->type; 
		$$->size = 0;
		if($2->type != TYPE_NUM)
			printf("Semantic Error at Line %d: Only integer can use \"!\".\n", yylineno);	
	}
	| ID '(' Args ')'  //函数引用:检查是否未定义就调用Error type 2 
	{
		$$ = set_vn("Exp", 4, set_var($1), set_terminal($2), $3, set_terminal($4));
		$$->index = $1;
		$$->size = 0;
		if(varFind($1) == NULL && funcFind($1) == NULL)
			printf("Semantic Error at Line %d: undefined Function \"%s\".\n", yylineno, G_Var[$1].mark);
		else if(funcFind($1) == NULL && varFind($1) != NULL)
			printf("Semantic Error at Line %d: \"%s\" is not a function.\n", yylineno, G_Var[$1].mark);
		else{
			$$->type = funcType($1);
			if(paraNum($1) != rpNum)
				printf("Semantic Error at Line %d: arguement number mismatches for the parameter number of function \"%s\" .\n", yylineno, G_Var[$1].mark);
		}
	}
	| ID '(' ')'      
	{
		$$ = set_vn("Exp", 3, set_var($1), set_terminal($2), set_terminal($3)); 
		$$->index = $1; 
		$$->size = 0;
		if(varFind($1) == NULL && funcFind($1) == NULL)
			printf("Semantic Error at Line %d: undefined Function \"%s\".\n", yylineno, G_Var[$1].mark);
		else if(funcFind($1) == NULL && varFind($1) != NULL)
			printf("Semantic Error at Line %d: \"%s\" is not a function.\n", yylineno, G_Var[$1].mark);
		else{
			$$->type = funcType($1);
			if(paraNum($1) != 0)
				printf("Semantic Error at Line %d: arguement number mismatches for the parameter number of function \"%s\" .\n", yylineno, G_Var[$1].mark);
		}
	}
	| ID error ')' 
	{
		$$ = set_vn("Exp", 3, set_var($1), set_terminal(0), set_terminal($3)); 
		$$->index = $1; 
		$$->size = 0;
		printf("Syntax Error at Line %d: Missing \"(\".\n", @2.last_line);
	}
	| Exp '[' Exp ']' 
	{
		$$ = set_vn("Exp", 4, $1, set_terminal($2), $3, set_terminal($4));
		$$->index = $1->index;
		$$->type = $1->type;
		$$->size = $1->size;
		if(varFind($1->index) != NULL && (varSize($1->index) == 0||funcFind($1->index) != NULL))
	        printf("Semantic Error at Line %d: \"%s\" is not an array.\n", yylineno, G_Var[$1->index].mark);
	    else if(varFind($1->index) == NULL )
	        printf("Semantic Error at Line %d: undefined Array \"%s\".\n", yylineno, G_Var[$1->index].mark);
		if($3->type != TYPE_NUM)
			printf("Semantic Error at Line %d: \"%.1f\" is not a integer.\n", yylineno, $3->numF);	
	}
	| Exp '[' error 
	{
		$$ = set_vn("Exp", 4, $1, set_terminal($2), set_terminal(0));
		$$->index = $1->index;
		$$->type = $1->type;
		$$->size = $1->size;
		printf("Syntax Error at Line %d: Missing \"]\".\n", @3.last_line);
	}
	| Exp '.' ID      //结构体引用:检查点号引用Error type 13
	{
		$$->type = $1->type;
		$$->size = $1->size;
		if(varFind($1->index) == NULL)
			printf("Semantic Error at Line %d: undefined struct variable \"%s\".\n", yylineno, G_Var[$1->index].mark);
		else if($1->type < 0)
			printf("Semantic Error at Line %d: Illegal use of \".\".\n", yylineno);
		else if(!strucMem(varType($1->type), $3))
			printf("Semantic Error at Line %d: Non-existent filed \"%s\".\n", yylineno, G_Var[$3].mark);
	}	
	| ID      //变量引用:检查是否定义Error type 1 
	{
		$$ = set_vn("Factor", 1, set_var($1));
		if(varFind($1) == NULL){
			printf("Semantic Error at Line %d: Undefined variable \"%s\".\n", yylineno, G_Var[$1].mark);
		}
		else{
			$$ = set_vn("Factor", 1, set_var($1));
			$$->type = varType($1);
			$$->kind = TYPE_VAR;
			$$->index = $1;
		}
	}
	| INT_NUM   //整型常数
	{
		$$ = set_vn("Factor", 1, set_int($1));
		$$->kind = TYPE_CONST;
		$$->type = TYPE_NUM;
		$$->numI = $1;
	}
	| FLOAT_NUM	//浮点型常数
	{
		$$ = set_vn("Factor", 1, set_float($1));
		$$->kind = TYPE_CONST;
		$$->type = TYPE_FLOAT;
		$$->numF = $1;
	}
	;

Relop: Equal  {$$ = set_terminal($1);}
	| Unequal  {$$ = set_terminal($1);}
	| '<'  {$$ = set_terminal($1);}
	| LE   {$$ = set_terminal($1);}
	| '>'  {$$ = set_terminal($1);}
	| GE   {$$ = set_terminal($1);}
	;

Args: Exp ',' Args   //记录形参个数
	{
		$$ = set_vn("Args", 3, $1, set_terminal($2), $3); 
		rpNum += 1;
	}
	| error ',' Args 
	{
		$$ = set_vn("Args", 3, set_terminal(0), set_terminal($2), $3); 
		rpNum += 1;
		printf("Syntax Error at Line %d: Something wrong with your expression.\n", @1.last_line);
	}
	| Exp     //记录形参个数
	{	
		$$ = set_vn("Args", 1, $1);
		rpNum += 1;
	}
	;
%% 

void yyerror(char* s){
    return ;     
}

int main(){      
	extern FILE* yyin;
	char source[40], target[40];

	strcpy(source, "./test.c");
	strcpy(target, "./test.out");

	if((yyin = fopen(source, "r")) == NULL)
	{
		printf("Cannot open the source file!\n");
		return 0;
	}
	target_file = fopen(target, "w");

	printf("starting!\n");
	// yydebug = 1;
	initTable();
	yyparse(); 
	undefFunc();
    destroyTable();
	printf("ending!\n");

	fclose(yyin);
	fclose(target_file);
	return 0; 
}  
 