#ifndef semantic_h
#define semantic_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

#define MAX_DEMINSION 10

/************************ 定义符号表结构 ************************/
/*变量符号表的结点*/
struct var
{
    int nameIndex;             // 变量名
    int type;                  // 变量类型
    int level;                 // 变量所处的函数
    int deminsion;             // 数组维度
    int size[MAX_DEMINSION];   // 数组时不为0 一般变量为0
    struct var *next;          // 链表指针
}*varHead, *varTail;

/*函数符号表的结点*/
struct func
{
    int tag;            // 1表示声明，2表示定义
    int nameIndex;      // 函数名
    int type;           // 函数类型
    int pnum;           // 形参数个数
    int line;           // 申明行数
    struct func *next;  // 链表指针
}*funcHead, *funcTail;

int deminsion;          // 记录数组的维度
int size[MAX_DEMINSION];// 记录数组的每个维度的范围
int pNum;               // 记录形参参数的个数
int rpNum;              // 记录函数实参个数
int memNum;             // 记录成员个数
int listNum;            // 记录每行定义的变量数目
int decNum;             // 记录变量定义个数
int type;               // 正在定义函数的返回类型
int rtype;              // 函数返回值
int curFunc;            // 当前函数索引 

/*结构体符号表的结点*/
struct struc
{
    int nameIndex;      // 结构类型名
    int memNum;         // 记录成员个数
    int level;         // 变量所处的函数
    struct struc *next; // 链表指针
}*strucHead, *strucTail;

typedef struct var Var;
typedef struct func Func;
typedef struct struc Struc;
extern bool error;

/************************ 建立符号表 ************************/

/*初始化符号表*/
void initTable();

/*删除符号表*/
void destroyTable();

/*=================变量符号表==============*/
/*建立变量符号表*/
void varTable(int index, int deminsion, int *size);

/*为变量说明类型*/
void addType(int type);

/*为变量说明层数*/
void addLevel(int level);

/*查找变量是否已经定义,是返回1，否返回0*/
Var* varFind(int index);

/*查找变量类型*/
int varType(int index);

/*查找变量大小*/
int varDeminsion(int index);

/*查找变量层数*/
int sameLevel(int index);

/*=================函数符号表==============*/
/*建立函数符号表,函数声明*/
void funcDeclare(int type, int index, int line);

/*建立函数符号表,函数定义*/
void funcDefine(int type, int index, int line);

/*查找函数是否已经定义,是返回1，否返回0*/
Func* funcFind(int index);

/*查找是否存在只声明没有定义的函数*/
void undefFunc();

/*查找函数类型*/
int funcType(int index);

/*查找函数的形参个数*/
int paraNum(int index);

/*=================结构体符号表==============*/
/*建立结构体符号表*/
void strucTable(int num,...);

/*查找结构体是否已经定义,是返回1，否返回0*/
Struc* strucFind(int index);

/*查找结构类型*/
int strucMem(int type, int index);

/*结构匹配*/
int strucMatch(int type1, int type2);

//得到结构体的大小；得到一个域(一定在该结构体中存在)在结构体内从头部开始的偏移量。
int structSize(Struc* pStruc);

int structOffset(Struc* pStruc, int index);

#endif 
