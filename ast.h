#ifndef ast_h
#define ast_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>

#define AST_GLOBALS 
#define MAX_VARS 100               // Maximum number of Varblies
#define MAX_DEFS 100               // Maximum number of Keywords
// #define MAX_BUFF_COLS 40        // Maximum number of Characters every line
// #define MAX_BUFF_ROWS 40        // Maximum number of lines
// #define PARSE_DEBUG             // Whether to print the debugging information

/*************************** Define the type of syntax tree  ***************************/
/* Enumerated type of the tree node */
typedef enum {TYPE_CONST, TYPE_VAR, TYPR_FUN, TYPE_ARRAY, TYPE_STRUCT, TYPE_TERMINAL, TYPE_UNTREMINAL} NodeEnum;
typedef enum {TYPE_NUM = -2, TYPE_FLOAT} Type;

/* Nonterminal */
typedef struct{
	char name[32]; 	        // Name
	int num;  		          // Number of Nonterminals 
	struct NodeTag **node; 	
} VN_Node;
 
typedef struct NodeTag{
	NodeEnum kind;           // Enumerated type
    Type type;             // Variable type
  	int numI;              // Int
    float numF;            // Float
  	int index; 	           // Index
    int level;	           // Level of the variable
    int deminsion;         // 0 while it is not an array
  	VN_Node vn;            // Nonterminal Struct
}Node;

struct VarIndex
{
 	int val;
 	char mark[32];
};

struct VarDefine
{
	int index;
	char name[32];
};

extern Node *treeHead;
struct VarIndex G_Var[MAX_VARS];          // Variable index array
extern struct VarDefine G_Def[MAX_DEFS];  // Variable array
extern int G_iVarMaxIndex;                // Current total number of variables
extern int G_iVarCurIndex;                // Current variable index
FILE *treeFile;
extern int yylineno;                      // Line number
extern char* yytext;                      
extern bool error;
void yyerror(char *s);                    // Refactoring the error function

/*************************** Build the synax tree ***************************/
/* Attribute type related functions */
Node *set_vn(char* name, int num, ...);
Node *set_var(int value);
Node *set_int(int value);
Node *set_float(float value);
Node *set_terminal(int value);

/* Tree node related functions */
void NodeFree(Node *p);
int NodeExecute(FILE* target_file, Node *p, int num);

void add_var(char *);


#endif


