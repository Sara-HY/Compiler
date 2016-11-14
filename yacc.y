%{ 
  	#include "ast.h"
  	#include "semantic.h"
  	#include "medCode.h"
  	#include "translate.h"
  	
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
  	Node *treeHead;
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
%type<node> Stmt DefList Def DecList Dec Exp Relop Args TYPE
%type<index> '=' '>' '<' '+' '-' '*' '/' ',' ';' '(' ')' '[' ']' '{' '}' '.' '!'

%%
Program0: Program {NodeExecute(treeFile, $1, 0); treeHead = $1;} 
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
			if(pFunc && pFunc->tag == 1){  //申明不一致
				error = true;
				printf("Semantic Error at Line %d: Inconsistent declaration of function \"%s\".\n", yylineno, G_Var[pFunc->nameIndex].mark);   
			}
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
					if(pFunc->pnum != pNum || pFunc->type != rtype){  //申明与定义不一致
						error = true;
						printf("Semantic Error at Line %d: Inconsistent definition with declaration of function \"%s\".\n", yylineno, G_Var[pFunc->nameIndex].mark);
					}
					else{
						pFunc->tag = 2;
						if(pFunc->type!=0 && rtype!=0 && rtype != pFunc->type){  //实际返回类型和函数定义的返回类型比较
							error = true;
                			printf("Semantic Error at Line %d: Type mismatched for return.\n", yylineno);
						}
					}
				}
				else{
					error = true;
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
		error = true;
		printf("Syntax Error at Line %d: Something wrong with ExtDecList before \";\".\n", @2.last_line);
	}
	| error ';'
	{
		error = true;
		$$ = set_vn("ExtDef", 2, set_terminal(0), set_terminal($2));
		printf("Syntax Error at Line %d: Something wrong with Specifier before \";\".\n", @1.last_line);
	}
	;

ExtDecList: VarDec 
	{
		$$ = set_vn("ExtDecList", 1, $1); 
		$$->index = $1->index;
		if(varFind($1->index) != NULL && sameLevel($1->index)){
			error = true;
			printf("Semantic Error at Line %d: Redefined Variable \"%s\".\n", yylineno, G_Var[$1->index].mark);
		}
		else
			varTable($1->index, deminsion, size);
	}
	| VarDec ',' ExtDecList 
	{
		$$ = set_vn("ExtDecList", 3, $1, set_terminal($2), $3); 
		$$->index = $1->index;
		if(varFind($1->index) != NULL && sameLevel($1->index)){
			error = true;
			printf("Semantic Error at Line %d: Redefined Variable \"%s\".\n", yylineno, G_Var[$1->index].mark);
		}
        else
        	varTable($1->index, deminsion, size);
	}
	;

Specifier: TYPE {$$ = set_vn("Specifier", 1, $1); $$->type = $1->type; type = $1->type;}
	| StructSpecifier {$$ = set_vn("Specifier", 1, $1); $$->type = $1->type;}
	;

TYPE: INT      {$$ = set_vn("TYPE", 1, set_terminal($1)); $$->type = TYPE_NUM;}
	| FLOAT    {$$ = set_vn("TYPE", 1, set_terminal($1)); $$->type = TYPE_FLOAT;}
	;

StructSpecifier: STRUCT OptTag '{' DefList '}' //结构体定义:检查是否重定义Error type 16
				{
					$$ = set_vn("StructSpecifier", 5, set_terminal($1), $2, set_terminal($3), $4, set_terminal($5));
					if($2 != NULL)
						$$->type = $2->index;
					addLevel($1);
					if($2!=NULL && strucFind($2->index)){
						error = true;
						printf("Semantic Error at Line %d: Duplicated name \"%s\".\n", yylineno, G_Var[$2->index].mark);
					}
					else if($2 != NULL)
						strucTable(1, $2);
				}
	| STRUCT Tag   //结构体引用:检查是否未定义就引用Error type 17
		{
			$$ = set_vn("StructSpecifier", 2, set_terminal($1), $2);
			$$->type = $2->index;
			if(!strucFind($2->index)){
				error = true;
				printf("Semantic Error at Line %d: undefined structure \"%s\".\n", yylineno, G_Var[$2->index].mark);
			}
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
		$$->deminsion = 0;
		memNum += 1;
		listNum += 1;
	}
	| VarDec '[' INT_NUM ']' 
	{
		$$ = set_vn("VarDec", 4, $1, set_terminal($2), set_int($3), set_terminal($4));
		$$->index = $1->index;
		size[deminsion] = $3;
		memNum += 1;
		listNum += 1;
		deminsion += 1;
	}
	| VarDec '[' error ']' 
	{
		$$ = set_vn("VarDec", 4, $1, set_terminal($2), set_terminal(0), set_terminal($4));
		$$->index = $1->index;
		$$->deminsion = 0;
		memNum += 1;
		listNum += 1;
		deminsion += 1;
		error = true;
		printf("Syntax Error at Line %d: Missing a integer between [].\n", @3.last_line);
	}
	;

FunDec: ID '(' VarList ')'  //函数定义:检查是否重复定义Error type 4
	{
		$$ = set_vn("FunDec", 4, set_var($1), set_terminal($2), $3, set_terminal($4));
		$$->index = $1;
		curFunc = $1;
		addLevel($1);	
	}
	| ID '(' error ')' 
	{
		$$ = set_vn("FunDec", 4, set_var($1), set_terminal($2), set_terminal(0), set_terminal($4));
		$$->index = $1;
		curFunc = $1;
		addLevel($1);
		error = true;
		printf("Syntax Error at Line %d: Something wrong with VarList between ().\n", @3.last_line);
	}
	| ID '(' ')'  //函数定义:检查是否重复定义Error type 4
	{
		$$ = set_vn("FunDec", 3, set_var($1), set_terminal($2), set_terminal($3));
		$$->index = $1;
		curFunc = $1;
	}
	| ID error ')' 
	{
		$$ = set_vn("FunDec", 3, set_var($1), set_terminal(0), set_terminal($3));
		$$->index = $1;
		curFunc = $1;
		error = true;
		printf("Syntax Error at Line %d: Missing \"(\".\n", @2.last_line);
	}
	;

VarList: ParamDec ',' VarList {$$ = set_vn("VarList", 3, $1, set_terminal($2), $3);}
	| ParamDec {$$ = set_vn("VarList", 1, $1);}
	| error ',' VarList 
	{
		$$ = set_vn("VarList", 3, set_terminal(0), set_terminal($2), $3);
		error = true;
		printf("Syntax Error at Line %d: Something wrong with ParamDec.\n", @1.last_line);
	}
	;

ParamDec: Specifier VarDec 
	{
		$$ = set_vn("ParamDec", 2, $1, $2);
		if(varFind($2->index) != NULL && sameLevel($2->index)){
			error = true;
			printf("Semantic Error at Line %d: Redefined Variable \"%s\".\n", yylineno, G_Var[$2->index].mark);
		}
        else{
        	varTable($2->index, deminsion, size);
        	addType($1->type);
        }
		pNum += 1;
	}
	;

CompSt: '{' DefList StmtList '}' {$$ = set_vn("CompSt", 4, set_terminal($1), $2, $3, set_terminal($4));}
	| error '}' 
	{
		$$ = set_vn("CompSt", 2, set_terminal(0), set_terminal($2));
		error = true;
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
		error = true;
		printf("Syntax Error at Line %d: Something wrong with expression before \";\".\n", @1.last_line);
	}
	| CompSt                                    {$$ = set_vn("Stmt", 1, $1);}
	| RETURN Exp ';'                            {$$ = set_vn("Stmt", 3, set_terminal($1), $2, set_terminal($3)); rtype = $2->type; }
	| RETURN error ';' 
	{
		$$ = set_vn("Stmt", 3, set_terminal($1), set_terminal(0), set_terminal($3)); 
		error = true;
		printf("Syntax Error at Line %d: Something wrong with expression before \";\".\n", @2.last_line);
	}
	| IF '(' Exp ')' Stmt %prec LOWER_THAN_ELSE {$$ = set_vn("Stmt", 5, set_terminal($1), set_terminal($2), $3, set_terminal($4), $5);}
	| IF '(' error ')' Stmt %prec LOWER_THAN_ELSE
	{
		$$ = set_vn("Stmt", 5, set_terminal($1), set_terminal($2), set_terminal(0), set_terminal($4), $5);
		error = true;
		printf("Syntax Error at Line %d: Something wrong with expression between ().\n", @3.last_line);
	}
	| IF error ')' Stmt %prec LOWER_THAN_ELSE 
	{
		$$ = set_vn("Stmt", 4, set_terminal($1), set_terminal(0), set_terminal($3), $4);
		error = true;
		printf("Syntax Error at Line %d: Missing \"(\".\n", @2.last_line);
	}
	| IF '(' Exp ')' Stmt ELSE Stmt             {$$ = set_vn("Stmt", 7, set_terminal($1), set_terminal($2), $3, set_terminal($4), $5, set_terminal($6), $7);}
	| IF '(' Exp ')' error ELSE Stmt 
	{
		$$ = set_vn("Stmt", 7, set_terminal($1), set_terminal($2), $3, set_terminal($4), set_terminal(0), set_terminal($6), $7);
		error = true;
		printf("Syntax Error at Line %d: Missing \";\".\n", @5.last_line);
	}
	| IF '(' error ')' Stmt ELSE Stmt 
	{
		$$ = set_vn("Stmt", 7, set_terminal($1), set_terminal($2), set_terminal(0), set_terminal($4), $5, set_terminal($6), $7);
		error = true;
		printf("Syntax Error at Line %d: Something wrong with expression between ().\n", @3.last_line);
	}
	| IF error ')' Stmt ELSE Stmt 
	{
		$$ = set_vn("Stmt", 6, set_terminal($1), set_terminal(0), set_terminal($3), $4, set_terminal($5), $6);
		error = true;
		printf("Syntax Error at Line %d: missing \"(\".\n", @2.last_line);
	}
	| WHILE '(' Exp ')' Stmt                    {$$ = set_vn("Stmt", 5, set_terminal($1), set_terminal($2), $3, set_terminal($4), $5);}
	| WHILE '(' error ')' Stmt 
	{
		$$ = set_vn("Stmt", 5, set_terminal($1), set_terminal($2), set_terminal(0), set_terminal($4), $5);
		error = true;
		printf("Syntax Error at Line %d: Something wrong with expression between ().\n", @3.last_line);
	}
	| WHILE error ')' Stmt {
		$$ = set_vn("Stmt", 4, set_terminal($1), set_terminal(0), set_terminal($3), $4);
		error = true;
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
		error = true;
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
		error = true;
		printf("Syntax Error at Line %d: Something wrong with declaration.\n", @1.last_line);
	}
	;

Dec: VarDec 
	{
		$$ = set_vn("Dec", 1, $1);
		$$->index = $1->index; 
		if(varFind($1->index) != NULL && sameLevel($1->index)){
			error = true;
			printf("Semantic Error at Line %d: Redefined Variable \"%s\".\n", yylineno, G_Var[$1->index].mark);
		}
        else
        	varTable($1->index, deminsion, size);

	}
	| VarDec '=' Exp 
	{
		$$ = set_vn("Dec", 3, $1, set_terminal($2), $3);
		$$->index = $1->index;
		if(varFind($1->index) != NULL && sameLevel($1->index)){
			error = true;
			printf("Semantic Error at Line %d: Redefined Variable \"%s\".\n", yylineno, G_Var[$1->index].mark);
		}
        else
        	varTable($1->index, deminsion, size);
	}
	| error '=' Exp 
	{
		$$ = set_vn("Dec", 3, set_terminal(0), set_terminal($2), $3);
		$$->index = $3->index;
		error = true;
		printf("Syntax Error at Line %d: Missing the variable.\n", @1.last_line);
	}
	;

Exp:  Exp '=' Exp  //检查等号左右类型匹配判断Error type 5, 操作符左右类型Error type 7
	{
		$$ = set_vn("Exp", 3, $1, set_terminal($2), $3);
		$$->type = $1->type;
		$$->deminsion = $1->deminsion;
		// printf("%d %d %d %d \n\n", $1->type, $3->type, $1->deminsion, $3->deminsion);
		if($1->type < 0 && $3->type < 0){
			if($1->type != $3->type){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for assignment.\n", yylineno);
			}
			else if($1->deminsion == 0 && $3->deminsion!=0 && $3->deminsion != varFind($3->index)->deminsion){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for assignment.\n", yylineno);
			}
			else if($3->deminsion == 0 && $1->deminsion!=0 && $1->deminsion != varFind($1->index)->deminsion){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for assignment.\n", yylineno);
			}
		}
		else if($1->type >= 0 && $3->type >= 0){
			//printf("%d %d %s %s\n\n", $1->type, $2->type, G_Var[$1->type].mark, G_Var[$2->type].mark);
			if(!strucMatch($1->type, $3->type)){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for assignment.\n", yylineno);
			}
		}
		if($1->kind == TYPE_CONST){
			error = true;
			printf("Semantic Error at Line %d: The left-hand side of an assignment must be a variable.\n", yylineno);
		}
	}
	| Exp And Exp 
	{
		$$ = set_vn("Exp", 3, $1, $2, $3); 
		$$->type = $1->type; 
		$$->deminsion = $1->deminsion;
		if($1->type != TYPE_NUM || $3->type != TYPE_NUM){
			error = true;
			printf("Semantic Error at Line %d: Only integer can be used as Bool.\n", yylineno);	
		}
	}
	| Exp Or Exp  
	{ 
		$$ = set_vn("Exp", 3, $1, $2, $3); 
		$$->type = $1->type; 
		$$->deminsion = $1->deminsion;
		if($1->type != TYPE_NUM || $3->type != TYPE_NUM){
			error = true;
			printf("Semantic Error at Line %d: Only integer can be used as Bool.\n", yylineno);	
		}
	}
	| Exp Relop Exp {$$ = set_vn("Exp", 3, $1, $2, $3); $$->type = $1->type; $$->deminsion = $1->deminsion;}
	| Exp '+' Exp 
	{
		$$ = set_vn("Exp", 3, $1, set_terminal($2), $3);
		$$->type = $1->type;
		$$->deminsion = $1->deminsion;
		if($1->type < 0 && $3->type < 0){
			if($1->type != $3->type){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
			}
			else if($1->deminsion == 0 && $3->deminsion!=0 && $3->deminsion != varFind($3->index)->deminsion){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
			}
			else if($3->deminsion == 0 && $1->deminsion!=0 && $1->deminsion != varFind($1->index)->deminsion){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
			}
		}
	}
	| Exp '-' Exp 
	{
		$$ = set_vn("Exp", 3, $1, set_terminal($2), $3);
		$$->type = $1->type;
		$$->deminsion = $1->deminsion;
		if($1->type < 0 && $3->type < 0){
			if($1->type != $3->type){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
			}
			else if($1->deminsion == 0 &&  $3->deminsion!=0 && $3->deminsion != varFind($3->index)->deminsion){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
			}
			else if($3->deminsion == 0 &&  $1->deminsion!=0 && $1->deminsion != varFind($1->index)->deminsion){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
			}
		}
	}
	| Exp '*' Exp 
	{
		$$ = set_vn("Exp", 3, $1, set_terminal($2), $3);
		$$->type = $1->type;
		$$->deminsion = $1->deminsion;
		if($1->type < 0 && $3->type < 0){
			if($1->type != $3->type){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
			}
			else if($1->deminsion == 0 &&  $3->deminsion!=0 && $3->deminsion != varFind($3->index)->deminsion){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
			}
			else if($3->deminsion == 0 &&  $1->deminsion!=0 && $1->deminsion != varFind($1->index)->deminsion){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
			}
		}
	}
	| Exp '/' Exp 
	{
		$$ = set_vn("Exp", 3, $1, set_terminal($2), $3);
		$$->type = $1->type;
		$$->deminsion = $1->deminsion;
		if($1->type < 0 && $3->type < 0){
			if($1->type != $3->type){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
			}
			else if($1->deminsion == 0 &&  $3->deminsion!=0 && $3->deminsion != varFind($3->index)->deminsion){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
			}
			else if($3->deminsion == 0 &&  $1->deminsion!=0 && $1->deminsion != varFind($1->index)->deminsion){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
			}
		}
	}
	| '(' Exp ')'     
	{
		$$ = set_vn("Exp", 3, set_terminal($1), $2, set_terminal($3)); 
		$$->type = $2->type; 
		$$->deminsion = 0;
	}
	| error ')' 
	{
		$$ = set_vn("Exp", 2, set_terminal(0), set_terminal($2)); 
		$$->deminsion = 0;
		error = true;
		printf("Syntax Error at Line %d: Missing \"(\".\n", @1.last_line);
	}
	| '-' Exp %prec UMINUS  
	{
		$$ = set_vn("Exp", 2, set_terminal($1), $2); 
		$$->type = $2->type; 
		$$->deminsion = 0;
		if($$->type>0){
			error = true;
			printf("Semantic Error at Line %d: Only integer and float can use \"-\".\n", yylineno);	
		}
	}
	| '!' Exp         
	{
		$$ = set_vn("Exp", 2, set_terminal($1), $2); 
		$$->type = $2->type; 
		$$->deminsion = 0;
		if($2->type != TYPE_NUM){
			error = true;
			printf("Semantic Error at Line %d: Only integer can use \"!\".\n", yylineno);	
		}
	}
	| ID '(' Args ')'  //函数引用:检查是否未定义就调用Error type 2 
	{
		$$ = set_vn("Exp", 4, set_var($1), set_terminal($2), $3, set_terminal($4));
		$$->index = $1;
		$$->deminsion = 0;
		if(varFind($1) == NULL && funcFind($1) == NULL && strcmp(G_Var[curFunc].mark, G_Var[$1].mark)){
			error = true;
			printf("Semantic Error at Line %d: undefined Function \"%s\".\n", yylineno, G_Var[$1].mark);
		}
		else if((funcFind($1) == NULL || !strcmp(G_Var[curFunc].mark, G_Var[$1].mark)) && varFind($1) != NULL){
			error = true;
			printf("Semantic Error at Line %d: \"%s\" is not a function.\n", yylineno, G_Var[$1].mark);
		}
		else{
			if((funcFind($1) != NULL && paraNum($1) != rpNum) || (!strcmp(G_Var[curFunc].mark, G_Var[$1].mark) && rpNum != pNum)){
				error = true;
				printf("Semantic Error at Line %d: arguement number mismatches for the parameter number of function \"%s\" .\n", yylineno, G_Var[$1].mark);
			}
			if(funcFind($1) != NULL)
				$$->type = funcType($1);
			else
				$$->type = type;

		}
		rpNum = 0;   //将实参个数清0
	}
	| ID '(' ')'      
	{
		$$ = set_vn("Exp", 3, set_var($1), set_terminal($2), set_terminal($3)); 
		$$->index = $1; 
		$$->deminsion = 0;
		if(varFind($1) == NULL && funcFind($1) == NULL && strcmp(G_Var[curFunc].mark, G_Var[$1].mark)){
			error = true;
			printf("Semantic Error at Line %d: undefined Function \"%s\".\n", yylineno, G_Var[$1].mark);
		}
		else if((funcFind($1) == NULL || !strcmp(G_Var[curFunc].mark, G_Var[$1].mark)) && varFind($1) != NULL){
			error = true;
			printf("Semantic Error at Line %d: \"%s\" is not a function.\n", yylineno, G_Var[$1].mark);
		}
		else{
			if(paraNum($1) != 0){
				error = true;
				printf("Semantic Error at Line %d: arguement number mismatches for the parameter number of function \"%s\" .\n", yylineno, G_Var[$1].mark);
			}
			if(funcFind($1) != NULL)
				$$->type = funcType($1);
			else
				$$->type = type;
		}
	}
	| ID error ')' 
	{
		$$ = set_vn("Exp", 3, set_var($1), set_terminal(0), set_terminal($3)); 
		$$->index = $1; 
		$$->deminsion = 0;
		error = true;
		printf("Syntax Error at Line %d: Missing \"(\".\n", @2.last_line);
	}
	| Exp '[' Exp ']' 
	{
		$$ = set_vn("Exp", 4, $1, set_terminal($2), $3, set_terminal($4));
		$$->index = $1->index;
		$$->type = $1->type;
		$$->deminsion = $1->deminsion + 1;
		if(varFind($1->index) != NULL && (varDeminsion($1->index) == 0||funcFind($1->index) != NULL)){
			error = true;
	        printf("Semantic Error at Line %d: \"%s\" is not an array.\n", yylineno, G_Var[$1->index].mark);
		}
	    else if(varFind($1->index) == NULL ){
	    	error = true;
	        printf("Semantic Error at Line %d: undefined Array \"%s\".\n", yylineno, G_Var[$1->index].mark);
	    }
		if($3->type != TYPE_NUM){
			error = true;
			printf("Semantic Error at Line %d: \"%.1f\" is not a integer.\n", yylineno, $3->numF);	
		}
	}
	| Exp '[' error 
	{
		$$ = set_vn("Exp", 4, $1, set_terminal($2), set_terminal(0));
		$$->index = $1->index;
		$$->type = $1->type;
		$$->deminsion = $1->deminsion;
		error = true;
		printf("Syntax Error at Line %d: Missing \"]\".\n", @3.last_line);
	}
	| Exp '.' ID      //结构体引用:检查点号引用Error type 13
	{
		$$ = set_vn("Exp", 3, $1, set_terminal($2), set_var($3));
		$$->type = varType($3);
		$$->deminsion = $1->deminsion;
		if(varFind($1->index) == NULL){
			error = true;
			printf("Semantic Error at Line %d: undefined struct variable \"%s\".\n", yylineno, G_Var[$1->index].mark);
		}
		else if($1->type < 0){
			error = true;
			printf("Semantic Error at Line %d: Illegal use of \".\".\n", yylineno);
		}
		else if(!strucMem(varType($1->index), $3)){
			error = true;
			printf("Semantic Error at Line %d: Non-existent filed \"%s\".\n", yylineno, G_Var[$3].mark);
		}
	}	
	| ID      //变量引用:检查是否定义Error type 1 
	{
		$$ = set_vn("Exp", 1, set_var($1));
		if(varFind($1) == NULL){
			error = true;
			printf("Semantic Error at Line %d: Undefined variable \"%s\".\n", yylineno, G_Var[$1].mark);
		}
		else{
			$$->type = varType($1);
			$$->kind = TYPE_VAR;
			$$->deminsion = 0;
			$$->index = $1;
		}
	}
	| INT_NUM   //整型常数
	{
		$$ = set_vn("Exp", 1, set_int($1));
		$$->type = TYPE_NUM;
		$$->deminsion = 0;
		$$->numI = $1;
	}
	| FLOAT_NUM	//浮点型常数
	{
		$$ = set_vn("Exp", 1, set_float($1));
		$$->type = TYPE_FLOAT;
		$$->deminsion = 0;
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
		error = true;
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
    printf("%s at line %d.\n", s, yylineno);
    error = true;
    return ;     
}

int main(int argc, char **argv){      
	extern FILE* yyin;
	char tree_filename[32], med_filename[32], fin_filename[32];
	
	if(argc != 2){
		printf("Please input the source and target file!\n");
		return 0;
	}

	if((yyin = fopen(argv[1], "r")) == NULL){
		printf("Cannot open the source file!\n");
		return 0;
	}
	char *pos = strchr(argv[1], '.');

	if(!pos){
		strncpy(tree_filename, argv[1], pos-argv[1]);
		tree_filename[pos-argv[1]] = '\0';
		strcat(tree_filename, ".tree");

		strncpy(med_filename, argv[1], pos-argv[1]);
		med_filename[pos-argv[1]] = '\0';
		strcat(med_filename, ".med");

		strncpy(fin_filename, argv[1], pos-argv[1]);
		fin_filename[pos-argv[1]] = '\0';
		strcat(fin_filename, ".asm");
	}
	else{
		strncpy(tree_filename, argv[1]);
		strcat(tree_filename, ".tree");

		strncpy(med_filename, argv[1]);
		strcat(med_filename, ".med");
		
		strncpy(tree_filename, argv[1]);
		strcat(tree_filename, ".asm");
	}

	treeFile = fopen(tree_filename, "w");

	//printf("starting!\n");
	//yydebug = 1;
	initTable();
	yyparse(); 
	fclose(yyin);
	fclose(treeFile);
	undefFunc();

	if(error == false){
		initCode();
		translate(treeHead);
		FILE *medFile = fopen(med_filename, "w");
		FILE *finFile = fopen(fin_filename, "w");
		printCode(medFile, finFile);
		fclose(medFile);
		fclose(finFile);
		destroyCode();
	}
	NodeFree(treeHead);
    destroyTable();
    
	// printf("ending!\n");

	
	return 0; 
}  
 
