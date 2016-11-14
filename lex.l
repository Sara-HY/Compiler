%{
	#include <stdio.h>
	#include <ctype.h>
	#include <string.h>
	#include <stdbool.h>

	#include "ast.h"
	#include "semantic.h"
	#include "yacc.tab.h"

	struct VarDefine G_Def[MAX_DEFS];            //存储的变量数组
	extern void add_var(char *);  //在内存中添加变量

	#define ERRORCHAR  500
	#define ERRORINT8  500
	#define ERRORINT16 501
	#define ERRORFLOAT 502

	#define MAXSTR     32
	
	static char KeyWord[7][MAXSTR]={
		"int",
		"float",
		"struct",
		"return",
		"if",
		"else",
		"while"
	};

 	int yycolumn = 1;
    #define YY_USER_ACTION \
		yylloc.first_line = yylloc.last_line = yylineno; \
		yylloc.first_column = yycolumn; \
		yylloc.last_column = yycolumn + yyleng - 1; \
		yycolumn += yyleng;
	bool error = false;

	char str[MAXSTR];
	int id_or_keyword(char *);
%}

letter [A-Za-z]

n_decimal [1-9]
decimal  [0-9]

n_octonary[1-7]
octonary [0-7]
un_octonary [8-9A-Za-z]

n_hexadecimal [1-9A-Fa-f]
hexadecimal [0-9A-Fa-f]
un_hexadecimal [G-Zg-z]

nextline [\n]
ignore [\t\040]

%option yylineno
%start COMMENT1 COMMENT2

%%
"//"             {BEGIN COMMENT1;}
<COMMENT1>\n     {BEGIN 0; yycolumn=1;}
<COMMENT1>[^\n]+ {}

"/*"               {BEGIN COMMENT2;}
<COMMENT2>\n       {yycolumn=1;}
<COMMENT2>"*/"     {BEGIN 0;}
<COMMENT2>[^"*/"]+ {}

{decimal}|{n_decimal}{decimal}+                           {strcpy(str, yytext); yylval.numI = atoi(yytext); return INT_NUM;}
[0]([x]|[X])({hexadecimal}|{n_hexadecimal}{hexadecimal}+) {strcpy(str, yytext); yylval.numI = strtol(yytext, NULL, 16); return INT_NUM;}
[0]([x]|[X])({hexadecimal}|{n_hexadecimal}{hexadecimal}+)*{un_hexadecimal}+({un_hexadecimal}|{hexadecimal})*   {error = true; printf("Lexical error at line %d: Illegal hexadecimal number \"%s\".\n", yylineno, yytext); return INT_NUM;}
[0]({octonary}|{n_octonary}{octonary}+)                   {strcpy(str, yytext); yylval.numI = strtol(yytext, NULL, 8); return INT_NUM;}
[0]({octonary}|{n_octonary}{octonary}+)*{un_octonary}+({un_octonary}|{octonary})*     {error = true; printf("Lexical error at line %d: Illegal octonary number \"%s\".\n", yylineno, yytext); return INT_NUM;}
{decimal}+[.]{decimal}+                                   {strcpy(str, yytext); yylval.numF = atof(yytext); return FLOAT_NUM;}
{decimal}*[.]{decimal}*([E]|[e]){decimal}+				  {strcpy(str, yytext); yylval.numF = atof(yytext); return FLOAT_NUM;}
{decimal}*[.]{decimal}*([E]|[e])  						  {error = true; printf("Lexical error at line %d: Illegal float number \"%s\".\n", yylineno, yytext); return FLOAT_NUM;}


";"   {yylval.index = ';'; strcpy(G_Def[yylval.index].name, ";"); return ';';}
","   {yylval.index = ','; strcpy(G_Def[yylval.index].name, ","); return ',';}
"="   {yylval.index = '='; strcpy(G_Def[yylval.index].name, "="); return '=';}
">"   {yylval.index = '>'; strcpy(G_Def[yylval.index].name, ">"); return '>';}
"<"   {yylval.index = '<'; strcpy(G_Def[yylval.index].name, "<"); return '<';}
">="  {yylval.index = GE; strcpy(G_Def[yylval.index].name, ">="); return GE;}
"<="  {yylval.index = LE; strcpy(G_Def[yylval.index].name, "<="); return LE;}
"=="  {yylval.index = Equal; strcpy(G_Def[yylval.index].name, "=="); return Equal;}
"!="  {yylval.index = Unequal; strcpy(G_Def[yylval.index].name, "!="); return Unequal;}
"+"   {yylval.index = '+'; strcpy(G_Def[yylval.index].name, "+"); return '+';}
"-"   {yylval.index = '-'; strcpy(G_Def[yylval.index].name, "-"); return '-';}
"*"   {yylval.index = '*'; strcpy(G_Def[yylval.index].name, "*"); return '*';}
"/"   {yylval.index = '/'; strcpy(G_Def[yylval.index].name, "/"); return '/';}
"&&"  {yylval.index = And; strcpy(G_Def[yylval.index].name, "&&"); return And;}
"||"  {yylval.index = Or; strcpy(G_Def[yylval.index].name, "||"); return Or;}
"."   {yylval.index = '.'; strcpy(G_Def[yylval.index].name, "."); return '.';}
"!"   {yylval.index = '!'; strcpy(G_Def[yylval.index].name, "!"); return '!';}
"("   {yylval.index = '('; strcpy(G_Def[yylval.index].name, "("); return '(';}
")"   {yylval.index = ')'; strcpy(G_Def[yylval.index].name, ")"); return ')';}
"["   {yylval.index = '['; strcpy(G_Def[yylval.index].name, "["); return '[';}
"]"   {yylval.index = ']'; strcpy(G_Def[yylval.index].name, "]"); return ']';}
"{"   {yylval.index = '{'; strcpy(G_Def[yylval.index].name, "{"); return '{';}
"}"   {yylval.index = '}'; strcpy(G_Def[yylval.index].name, "}"); return '}';}

{letter}({letter}|{decimal})*  {int i; i = id_or_keyword(yytext); strcpy(str, yytext); return i;}
{nextline}  {yycolumn=1;}
{ignore}+   {}
.           {error = true; printf("Lexical error at line %d: Mysterious characters \"%s\".\n", yylineno, yytext);}
%%

int id_or_keyword(char* str)
{
	unsigned i, j;

	for(i=0; i<7; i++){
		if(!strcmp(str, KeyWord[i]))
			break;
	}
	if(i<7){
		yylval.index = i + 261; 
		strcpy(G_Def[yylval.index].name, yytext); 
		return i + 261;
	}
	else{
		add_var(yytext); 
 		yylval.index = G_iVarCurIndex; 
		return ID;
	}
}

int yywrap(){ 
	return 1; 
}

/*
int main()
{
	int c, i, flag1=0, temp=0, flag2=0;
	char source[40], target[40];
	FILE *target_file;

	strcpy(source, "test.c");
	strcpy(target, "test.txt");

	if((yyin = fopen(source, "r")) == NULL)
	{
		printf("Cannot open the source file!\n");
		return 0;
	}
	target_file = fopen(target, "w");
	while((c = yylex()) != 0){		
		if(flag1 == 0){
			fprintf(target_file, "line  1: ");
			flag1 = 1;
		}
		if(c == '\n'){
			temp = 1;
		}
		else{
			if(temp == 1){
				temp = 0;
				fprintf(target_file, "\nline %2d: ", yylineno);
			}
			if(c == ERRORCHAR)
				fprintf(target_file, "[%3d, \"%s\"]\t", c, yytext);
			else if(c == ERRORINT8)
				fprintf(target_file, "[%3d, \"%s\"]\t", c, yytext);
			else if(c == ERRORINT16)
				fprintf(target_file, "[%3d, \"%s\"]\t", c, yytext);
			else if(c == ERRORFLOAT)
				fprintf(target_file, "[%3d, \"%s\"]\t", c, yytext);
			else if(c == 256)
				fprintf(target_file, "[%3d, %2d]\t", c, atoi(yytext));
			else if(c == 257)
				fprintf(target_file, "[%3d, %2ld]\t", c, strtol(yytext, NULL, 8));
			else if(c == 258)
				fprintf(target_file, "[%3d, %2ld]\t", c, strtol(yytext, NULL, 16));
			else if(c == 259)
				fprintf(target_file, "[%3d, %2f]\t", c, atof(yytext));
			else
				fprintf(target_file, "[%3d, \"%s\"]\t", c, yytext);
		}
	}
	fclose(yyin);
	fclose(target_file);
	return 0;
}
*/
