#ifndef semantic_h
#define semantic_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

#define MAX_DEMINSION 10

/************************ Defining the symbol table structure ************************/

struct var
{
    int nameIndex;             // Name
    int type;                  // Type of the variable
    int level;                 // The function which the variable belongs to
    int deminsion;             // Dimension if it's an array
    int size[MAX_DEMINSION];   // 0 while it is not an array
    struct var *next;          
}*varHead, *varTail;


struct func
{
    int tag;            // 1 indicates a declaration, 2 indicates a definition
    int nameIndex;      // Name
    int type;           // Return Type
    int pnum;           // Number of parameters
    int line;           // The line number of the statement
    struct func *next;  
}*funcHead, *funcTail;


int deminsion;          // Array Dimension
int size[MAX_DEMINSION];// Range of each dimension of the array
int pNum;               // Number of parameters
int rpNum;              // Number of arguements
int memNum;             // Number of members
int listNum;            // Number of variables every line
int decNum;             // Number of variables
int type;               // Return Type of the function
int rtype;              // Return value
int curFunc;            // Current index of the function


struct struc
{
    int nameIndex;      // Name
    int memNum;         // Number of members
    int level;          // The function which the variable belongs to
    struct struc *next; 
}*strucHead, *strucTail;


typedef struct var Var;
typedef struct func Func;
typedef struct struc Struc;
extern bool error;

/************************ Defining the symbol table ************************/

void initTable();

void destroyTable();

/*=================Variable symbol table==============*/
void varTable(int index, int deminsion, int *size);

void addType(int type);

void addLevel(int level);

Var* varFind(int index);

int varType(int index);

int varDeminsion(int index);

int sameLevel(int index);


/*=================Function symbol table==============*/
void funcDeclare(int type, int index, int line);

void funcDefine(int type, int index, int line);

Func* funcFind(int index);

void undefFunc();

int funcType(int index);

int paraNum(int index);


/*=================Struct symbol table==============*/
void strucTable(int num,...);

Struc* strucFind(int index);

int strucMem(int type, int index);

int strucMatch(int type1, int type2);

int structSize(Struc* pStruc);

int structOffset(Struc* pStruc, int index);

#endif 
