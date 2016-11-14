%{
	#include <stdio.h>
	#include <ctype.h>
	#include <string.h>

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

	enum {
    INT10 = 256,
    INT8 = 257,
    INT16 = 258,
    FLOAT_NUM = 259,
    ID = 260,
    GE = 261,
    LE = 262,
    Equal = 263,
    Unequal = 264,
    And = 265,
    Or = 266,
    INT = 267,
    FLOAT = 268, 
    STRUCT = 268,
    RETURN = 270,
    IF = 271,
    ELSE = 272,
    WHILE = 273,
    UMINUS = 274,
    LOWER_THAN_ELSE = 275
  };

	char str[MAXSTR];
	int id_or_keyword(char *);
%}

letter [_A-Za-z]

n_decimal [1-9]
decimal  [0-9]

n_octonary [1-7]
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
<COMMENT1>\n     {BEGIN 0; return '\n';}
<COMMENT1>[^\n]+ {}

"/*"               {BEGIN COMMENT2;}
<COMMENT2>\n       {}
<COMMENT2>"*/"     {BEGIN 0;}
<COMMENT2>[^"*/"]+ {}

{decimal}|{n_decimal}{decimal}+                           {return INT10;}
[0]([x]|[X]){hexadecimal}|{n_hexadecimal}{hexadecimal}+   {return INT16;}
[0]([x]|[X])({hexadecimal}|{n_hexadecimal}{hexadecimal}+)*{un_hexadecimal}+({un_hexadecimal}|{hexadecimal})*   {printf("Lexical error at line %d: Illegal hexadecimal number \'%s\'\n", yylineno, yytext); return ERRORINT16;}
[0]({octonary}|{n_octonary}{octonary}+)                   {return INT8;}
[0]({octonary}|{n_octonary}{octonary}+)*{un_octonary}+({un_octonary}|{octonary})*     {printf("Lexical error at line %d: Illegal octonary number \'%s\'\n", yylineno, yytext); return ERRORINT8;}

{decimal}+[.]{decimal}+                                   {return FLOAT_NUM;}
{decimal}*[.]{decimal}*([E]|[e]){decimal}+				  {return FLOAT_NUM;}
{decimal}*[.]{decimal}*([E]|[e])  						  {printf("Lexical error at line %d: Illegal float number \'%s\'\n", yylineno, yytext); return ERRORFLOAT;}


";"   {return ';';}
","   {return ',';}
"="   {return '=';}
">"   {return '>';}
"<"   {return '<';}
">="  {return GE;}
"<="  {return LE;}
"=="  {return Equal;}
"!="  {return Unequal;}
"+"   {return '+';}
"-"   {return '-';}
"*"   {return '*';}
"/"   {return '/';}
"&&"  {return And;}
"||"  {return Or;}
"."   {return '.';}
"!"   {return '!';}
"("   {return '(';}
")"   {return ')';}
"["   {return '[';}
"]"   {return ']';}
"{"   {return '{';}
"}"   {return '}';}

{letter}({letter}|{decimal})*  {int i; i = id_or_keyword(yytext); return i;}
{nextline}  {return '\n';}
{ignore}+   {}
.           {printf("Lexical error at line %d: Mysterious characters \'%s\'\n", yylineno, yytext); return ERRORCHAR;}
%%

int id_or_keyword(char* str)
{
	unsigned i, j;

	for(i=0; i<7; i++){
		if(!strcmp(str, KeyWord[i]))
			break;
	}
	if(i<7){
		return i + 267;
	}
	else{
		return ID;
	}
}

int yywrap(){ 
	return 1; 
}

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
