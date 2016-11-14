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

//确定非终结符的类型
int vnType(char *name);

void translate(Node *pNode);

/* 
 * 翻译exp，其中的option表示place的主动、被动。 
 * 0：被动：place上层仅仅提供了位置，可以没有左值。你填写任何，上层会直接使用，比如填写立即数也可以。
 * 1：主动：place是由上层给定的，确定的变量，请将你的结果放入place
 * 如果place==NULL,则本层不要生成变量返回该exp的结果。
 */
void translateExp(Node *pNode, char *place, int option);

//翻译参数列表。需要当前函数定义中的参数表，当前是第几个参数。
void translateArgs(Node* pNode, int funIndex, int pnum, int count);

//翻译COND，由上层提供跳转label
void translateCond(Node* pNode, char* labelTrue, char* labelFalse);

//得到这个exp的地址。
void getLocation(Node*pNode, char* place);


#endif




