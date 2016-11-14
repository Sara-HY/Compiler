#include "semantic.h"
#include "ast.h"

/************************ 建立符号表 ************************/ 
/*初始化符号表*/
void initTable()
{
    varHead = (Var *)malloc(sizeof(Var));         //变量符号表头指针
    varHead->next = NULL;
    varTail = varHead;//变量符号表尾指针

    funcHead = (Func *)malloc(sizeof(Func));      //函数符号表头指针
    funcHead->next = NULL;         //函数符号表尾指针
    funcTail = funcHead;
    pNum = 1;
    add_var("write");
    funcDefine(-3, G_iVarCurIndex, 0);
    add_var("write_param");
    pNum = 0;
    add_var("read");
    funcDefine(-2, G_iVarCurIndex, 0);
    add_var("read_param");

    strucHead = (Struc *)malloc(sizeof(Struc));//结构体符号表头指针
    strucHead->next = NULL;
    strucTail = strucHead;             //结构体符号表尾指针
}

/*删除符号表*/
void destroyTable()
{
    Var* pVar;
    Func* pFun;
    Struc* pStruc;
    while(varHead != NULL){
        pVar = varHead->next;
        free(varHead);
        varHead = pVar;
    }
    while(funcHead != NULL){
        pFun = funcHead->next;
        free(funcHead);
        funcHead = pFun;
    }
    while(strucHead != NULL){
        pStruc = strucHead->next;
        free(strucHead);
        strucHead = pStruc;
    }
}


/*=================创建、查询变量符号表==============*/
/*建立变量符号表*/
void varTable(int index, int deminsion, int *size)
{
	Var *pVar = (Var *)malloc(sizeof(Var));

	pVar->nameIndex = index;
    pVar->deminsion = deminsion;
    for(int i = 0; i < deminsion; i++)
        pVar->size[deminsion - i] = size[i];
    deminsion = 0;
    pVar->level = -1;

    pVar->next = varHead->next;
    varHead->next = pVar;
    //printf("%d %s\n", temp->index, G_Var[temp->index].mark);
}

/*为变量说明类型*/
void addType(int type){
    Var* pVar = varHead->next;
    int i;
    for(i = 0; i< listNum && pVar!=NULL; i++){
        pVar->type = type;
        pVar = pVar->next;
    }
    decNum += listNum;
    listNum = 0;
}

/*为变量说明层数*/
void addLevel(int level){
    Var* pVar = varHead->next;
    int i;
    for(i = 0; i< decNum && pVar!=NULL; i++){
        pVar->level = level;
        pVar = pVar->next;
    }
    decNum = 0;
}

/*查找变量是否已经定义,是返回1，否返回0*/
Var* varFind(int index)
{
	Var* pVar = varHead->next;

    while(pVar != NULL){
        if(!strcmp(G_Var[pVar->nameIndex].mark, G_Var[index].mark)){
            return pVar;    //存在返回1
        }
        pVar = pVar->next;
    }
    return NULL;            //不存在返回0
}

/*查找变量类型*/
int varType(int index)
{
	Var* pVar = (Var *)malloc(sizeof(Var));
    pVar = varHead->next;
    while(pVar != NULL){
        if(!strcmp(G_Var[pVar->nameIndex].mark, G_Var[index].mark))
            return pVar->type;//返回变量类型
        pVar = pVar->next;
    }
    return -1;
}

/*查找变量大小*/
int varDeminsion(int index)
{
    Var* pVar = (Var *)malloc(sizeof(Var));
    pVar = varHead->next;
    while(pVar != NULL){
        if(!strcmp(G_Var[pVar->nameIndex].mark, G_Var[index].mark))
            return pVar->deminsion;//返回变量类型
        pVar = pVar->next;
    }
    return -1;
}

/*查找变量层数*/
int sameLevel(int index)
{
    Var* pVar = varHead->next;
    while(pVar != NULL){
        if(!strcmp(G_Var[pVar->nameIndex].mark, G_Var[index].mark) && pVar->level == -1)
            return 1;
        pVar = pVar->next;
    }
    return 0;
}

/*=================创建、查询函数符号表==============*/
/*建立函数符号表,函数声明*/
void funcDeclare(int type, int index, int line)
{

    Func *pFunc = (Func *)malloc(sizeof(Func));

    pFunc->tag = 1;      //标志为申明
    pFunc->type = type;
    pFunc->nameIndex = index;
    pFunc->line = line;
    pFunc->pnum = pNum;
    pNum = 0;   //将实参个数清0

    funcTail->next = pFunc;  //尾指针指向下一个空结点
    funcTail = pFunc;
    pFunc->next = NULL;
}

/*建立函数符号表,函数定义*/
void funcDefine(int type, int index, int line)
{
    Func *pFunc = (Func *)malloc(sizeof(Func));

    pFunc->tag = 2;      //标志为定义
    pFunc->type = type;
    pFunc->nameIndex = index;
    pFunc->line = line;
    pFunc->pnum = pNum;
    pNum = 0;   //将实参个数清0
    if(pFunc->type!=0 && rtype!=0 && rtype != pFunc->type){ //实际返回类型和函数定义的返回类型比较{
        error = true;
        printf("Semantic Error at Line %d: Type mismatched for return.\n", yylineno);
    }

    funcTail->next = pFunc;  //尾指针指向下一个空结点
    funcTail = pFunc;
    pFunc->next = NULL;
}

/*查找函数是否已经定义,是返回1，否返回0*/
Func* funcFind(int index)
{
	int flag=0;
    Func* pFun = funcHead->next;

    while(pFun!=NULL){
        if(!strcmp(G_Var[pFun->nameIndex].mark, G_Var[index].mark))
            return pFun;    //存在返回1
        pFun = pFun->next;
    }
    return NULL;        //不存在返回0
}

/*查找是否存在只声明没有定义的函数*/
void undefFunc()
{
    Func* pFun = funcHead->next;
    while(pFun != NULL){
        if(pFun->tag == 1){
            error = true;
            printf("Semantic Error at Line %d: Undefined function \"%s\".\n", pFun->line, G_Var[pFun->nameIndex].mark);
        }
        pFun = pFun->next;
    }
}

/*查找函数类型*/
int funcType(int index)
{
	Func* pFun = funcHead->next;
    while(pFun != NULL){
        if(!strcmp(G_Var[pFun->nameIndex].mark, G_Var[index].mark))
            return pFun->type;//返回函数类型
        pFun = pFun->next;
    }
    return -1;
}

/*查找函数的形参个数*/
int paraNum(int index)
{	
	Func* pFun = funcHead->next;
    while(pFun != NULL){
        if(!strcmp(G_Var[pFun->nameIndex].mark, G_Var[index].mark))
            return pFun->pnum;//返回形参个数
        pFun = pFun->next;
    }
    return -1;
}

/*=================结构体符号表==============*/
/*建立结构体符号表*/
void strucTable(int num,...)
{   
    va_list valist; //定义变长参数列表
    Struc *pStruc = (Struc *)malloc(sizeof(Struc));//memNum新生成的父节点
    Node *temp = (Node *)malloc(sizeof(Node));

    pStruc->memNum = memNum;
    memNum = 0;

    va_start(valist, num);           //初始化变长参数为num后的参数
    temp = va_arg(valist, Node*);    //取变长参数列表中的第二个结点
    pStruc->nameIndex = temp->index;

    strucTail->next = pStruc;
    strucTail = pStruc;
    pStruc->next = NULL;
}


/*查找结构是否已经定义,是返回1，否返回0*/
Struc* strucFind(int index)
{
    Struc* pStruc = strucHead->next;

    while(pStruc != NULL){
        if(!strcmp(G_Var[pStruc->nameIndex].mark, G_Var[index].mark))
            return pStruc;     //存在返回1
        pStruc = pStruc->next;
    }
    return NULL;//不存在返回0
}

/*查找结构成员*/
int strucMem(int type, int index){
    int i;

    Struc* pStruc = strucHead->next;

    while(pStruc != NULL){
        if(!strcmp(G_Var[pStruc->nameIndex].mark, G_Var[type].mark)){
            for(i = 1; i <= pStruc->memNum; i++){
               // printf("%s %s\n\n\n\n", G_Var[pStruc->nameIndex + i].mark, G_Var[index].mark);
                if(!strcmp(G_Var[pStruc->nameIndex + i].mark, G_Var[index].mark))
                    return 1;     //存在返回1
            }
        }
        pStruc = pStruc->next;
    }
    return 0;//不存在返回0
}

/*结构匹配*/
int strucMatch(int type1, int type2)
{
    int i = 0, num = 0;
    Struc* pStruc1 = strucHead->next;
    Struc* pStruc2 = strucHead->next;

    for(; pStruc1 != NULL; pStruc1 = pStruc1->next){
        for(pStruc2 = pStruc1->next; pStruc2 != NULL; pStruc2 = pStruc2->next){
            if(pStruc1->memNum == pStruc2->memNum){
                num = pStruc1->memNum;
                for(i = 1; i <= num; i++){
                    //printf("%d %s %s %d %d\n\n\n\n", num, G_Var[pStruc1->nameIndex + i].mark, G_Var[pStruc2->nameIndex + i].mark, varType(pStruc1->nameIndex + i), varType(pStruc2->nameIndex + i));
                    if(varType(pStruc1->nameIndex + i) != varType(pStruc2->nameIndex + i))
                        return 0;     //不匹配返回0
                }
                if(i > num)
                    return 1;
            }
        }
    }
    return 0;
}

//得到结构体的大小；得到一个域(一定在该结构体中存在)在结构体内从头部开始的偏移量。
int structSize(Struc* pStruc)
{
    int count = 0;
    for(int i = 1; i <= pStruc->memNum; i++){
        Var *pVar = varFind(pStruc->nameIndex + i);
        if(pVar->size == 0)
            count +=4;
        else{
            for(int j = 0; j < pVar->deminsion; j++)
                count += pVar->size[j] * 4;
        }
    }
    return count;
}

int structOffset(Struc* pStruc, int index){
    int count = 0;
    for(int i = 1; i <= pStruc->memNum; i++){
        Var *pVar = varFind(pStruc->nameIndex + i);
        if(pVar->deminsion == 0)
            count += 4;
        else{
            for(int j = 0; j < pVar->deminsion; j++)
                count += pVar->size[j] * 4;
        }
        if(!strcmp(G_Var[pVar->nameIndex].mark, G_Var[index].mark))
            return count;
    }
}




