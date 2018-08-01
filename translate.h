#ifndef translate_h
#define translate_h

#include "ast.h"
#include "semantic.h"
#include "medCode.h"

static char nodeType[23][32]={
	"Program",
	"ExtDefList",
	"ExtDef",
	"ExtDecList",
	"Specifier",
	"TYPE",
	"StructSpecifier",
	"OptTag",
	"Tag",
	"VarDec",
	"FunDec",
	"VarList",
	"ParamDec",
	"CompSt",
	"StmtList",
	"Stmt",
	"DefList",
	"Def",
	"DecList",
	"Dec",
	"Exp",
	"Relop",
	"Args"
};

// Determine the type of nonterminal
int vnType(char *name);

void translate(Node *pNode);

/*
  * Translate exp.
  * option = 0: Passive: The upper layer of the place only provides the position, and there is no left value. If you fill in any, the upper layer will be used directly, for example, you can fill in the immediate data.
  * option = 1: Active: The place is a variable given by the upper layer, please put your result in place.
  * If place==NULL, then this layer does not generate a variable.
*/
void translateExp(Node *pNode, char *place, int option);

// Translation parameter list
void translateArgs(Node* pNode, int funIndex, int pnum, int count);

// Translate conditional codes, jump according to the label from the upper layer
void translateCond(Node* pNode, char* labelTrue, char* labelFalse);

void getLocation(Node*pNode, char* place);


#endif




