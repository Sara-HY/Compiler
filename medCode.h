#ifndef medcode_h
#define medcode_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * GOTO x       (GOTO  , , , x)
 * RETURN x     (RETURN, , , x)
 * ARG x        (ARG   , , , x)
 * PARAM x      (PARAM , , , x)
 * READ x       (READ  , , , x)
 * WRITE x      (WRITE , , , x)
 * LABEL x :    (LABEL, , , x)
 * FUNCTION f : (FUNCTION, , , f)
 * DEC x [size] (DEC, size, , x)
 * x := y       (:=, y , , x)
 * x := &y      (:=, &y, , x)
 * x := *y      (:=, *y, , x)
 * *x := y      (:=, y, , *x)
 * x := CALL f  (CALL, f, , x)
 * x := y + z   (+, y, z, x)
 * x := y - z   (-, y, z, x)
 * x := y * z   (*, y, z, x)
 * x := y / z   (/, y, z, x)
 * IF x [relop] y GOTO z  (<, x, y, z) (>, x, y, z) (Equal, x, y, z) (UnEqual, x, y, z) (LE, x, y, z) (GE, x, y, z)
 */

static char codeType[21][32]={
	"GOTO",
	"RETURN",
	"ARG",
	"PARAM",
	"READ",
	"WRITE",
	"LABEL", 
	"FUNCTION", 
	"DEC",
	":=",
	"CALL",
	"+",
	"-",
	"*",
	"/",
	"<",
	">",
	"==",
	"!=",
	"<=",
	">="
};

//双向循环链表，存储代码在内存中的表示
typedef struct interCodes {
	char args[4][32];
	struct interCodes *prev; 
	struct interCodes *next;
}InterCodes;

//label,temp的计数器，用于生成新的label，temp
static int tempCount=0, labelCount=0;
//代码buff链表的头指针
static InterCodes* codeHead = NULL, *codeTail = NULL;
//是否本次有优化
static int optd = 0;
//优化选项
static int opt = 1;

//初始化中间代码表示
void initCode();

//释放中间代码表示
void destroyCode();

//生成新的label，名称放在提供好的name里面。
void newLabel(char* name);

//生成新的临时变量，名称放在提供好的name里面。
void newTemp(char* name);

int typeCode(char* code);

//添加一条代码，指明这条代码的词数，然后传入各个词语，各个词语都是char*，即传入多个字符串
void addCode(char* code0, char* code1, char* code2, char* code3);

//将内存中的代码打印到文件中，传入新文件路径，并顺便清理内存中的代码存储
void printCode(FILE *target_file1, FILE *target_file2);

//关闭优化
void closeOpt();

#endif


