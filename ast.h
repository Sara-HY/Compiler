#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

#define AST_GLOBALS 
#define MAX_VARS 100            // 最多变量数 
#define MAX_DEFS 20             // 最多保留字数  
// #define MAX_BUFF_COLS 40        // 分析语句每行最多字符
// #define MAX_BUFF_ROWS 40        // 分析语句最多行数
// #define PARSE_DEBUG             // 是否打印调试信息的开关

/*************************** 定义语法树类型 ***************************/
/* 定义树结点的权举类型 */
typedef enum {TYPE_CONST, TYPE_VAR, TYPR_FUN, TYPE_ARRAY, TYPE_STRUCT, TYPE_TERMINAL, TYPE_UNTREMINAL} NodeEnum;
typedef enum {TYPE_NUM = -2, TYPE_FLOAT} Type;

/* 非终结符 */
typedef struct{
	char name[32]; 	        // 非终结符名称
	int num;  		        // 非终结符个数
	struct NodeTag **node; 	// 非终结符地址
} VN_Node;
 
typedef struct NodeTag{
	NodeEnum kind;         // 树结点类型
    Type type;             // 变量类型
  	int numI;              // 整型数
    float numF;            // 浮点数
  	int index; 	           // 索引 
    int level;	           // 变量所在层数
    int size;              // 数组时不为0 一般变量为0
  	VN_Node vn;            // 非终结符对象
}Node;

struct VarIndex
{
 	int val;
 	char mark[32];
};  //自定义变量索引

struct VarDefine
{
	int index;
	char name[32];
};

struct VarIndex G_Var[MAX_VARS]; // 变量内存数组
extern struct VarDefine G_Def[MAX_DEFS];  // 存储的变量数组
extern int G_iVarMaxIndex;       // 变量目前总数
extern int G_iVarCurIndex;       // 当前操作变量索引
FILE *target_file;
extern int yylineno;             // 行号
extern char* yytext;             // 词
void yyerror(char *s);       // 错误处理函数

/*************************** 建立语法树 ***************************/
/* 属性操作类型 */
Node *set_vn(char* name, int num, ...);
Node *set_var(int value);
Node *set_int(int value);
Node *set_float(float value);
Node *set_terminal(int value);

/* 树结点操作 */
void NodeFree(Node *p);
int NodeExecute(Node *p, int num);

void add_var(char *);





