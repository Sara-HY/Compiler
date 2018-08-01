#include "semantic.h"
#include "ast.h"

/************************ Build the symbol table ************************/ 
void initTable()
{
    varHead = (Var *)malloc(sizeof(Var));         
    varHead->next = NULL;
    varTail = varHead;

    funcHead = (Func *)malloc(sizeof(Func));      
    funcHead->next = NULL;      
    funcTail = funcHead;
    pNum = 1;
    add_var("write");
    funcDefine(-3, G_iVarCurIndex, 0);
    add_var("write_param");
    pNum = 0;
    add_var("read");
    funcDefine(-2, G_iVarCurIndex, 0);
    add_var("read_param");

    strucHead = (Struc *)malloc(sizeof(Struc));
    strucHead->next = NULL;
    strucTail = strucHead;             
}


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


/*=================Variable symbol table==============*/
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


void addLevel(int level){
    Var* pVar = varHead->next;
    int i;
    for(i = 0; i< decNum && pVar!=NULL; i++){
        pVar->level = level;
        pVar = pVar->next;
    }
    decNum = 0;
}


Var* varFind(int index)
{
	Var* pVar = varHead->next;

    while(pVar != NULL){
        if(!strcmp(G_Var[pVar->nameIndex].mark, G_Var[index].mark)){
            return pVar;    //return 1 while existing
        }
        pVar = pVar->next;
    }
    return NULL;            
}


int varType(int index)
{
	Var* pVar = (Var *)malloc(sizeof(Var));
    pVar = varHead->next;
    while(pVar != NULL){
        if(!strcmp(G_Var[pVar->nameIndex].mark, G_Var[index].mark))
            return pVar->type;
        pVar = pVar->next;
    }
    return -1;
}


int varDeminsion(int index)
{
    Var* pVar = (Var *)malloc(sizeof(Var));
    pVar = varHead->next;
    while(pVar != NULL){
        if(!strcmp(G_Var[pVar->nameIndex].mark, G_Var[index].mark))
            return pVar->deminsion;
        pVar = pVar->next;
    }
    return -1;
}


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

/*=================Function symbol table==============*/
void funcDeclare(int type, int index, int line)
{

    Func *pFunc = (Func *)malloc(sizeof(Func));

    pFunc->tag = 1;    
    pFunc->type = type;
    pFunc->nameIndex = index;
    pFunc->line = line;
    pFunc->pnum = pNum;
    pNum = 0;          //Clear the number of arguments

    funcTail->next = pFunc; 
    funcTail = pFunc;
    pFunc->next = NULL;
}


void funcDefine(int type, int index, int line)
{
    Func *pFunc = (Func *)malloc(sizeof(Func));

    pFunc->tag = 2;     
    pFunc->type = type;
    pFunc->nameIndex = index;
    pFunc->line = line;
    pFunc->pnum = pNum;
    pNum = 0;          //Clear the number of arguments
    if(pFunc->type!=0 && rtype!=0 && rtype != pFunc->type){ 
        error = true;
        printf("Semantic Error at Line %d: Type mismatched for return.\n", yylineno);
    }

    funcTail->next = pFunc;  
    funcTail = pFunc;
    pFunc->next = NULL;
}


Func* funcFind(int index)
{
	int flag=0;
    Func* pFun = funcHead->next;

    while(pFun!=NULL){
        if(!strcmp(G_Var[pFun->nameIndex].mark, G_Var[index].mark))
            return pFun;    //return 1 while existing
        pFun = pFun->next;
    }
    return NULL;       
}

/* Find whether there is a function that's only declaration no definition*/
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


int funcType(int index)
{
	Func* pFun = funcHead->next;
    while(pFun != NULL){
        if(!strcmp(G_Var[pFun->nameIndex].mark, G_Var[index].mark))
            return pFun->type;
        pFun = pFun->next;
    }
    return -1;
}


int paraNum(int index)
{	
	Func* pFun = funcHead->next;
    while(pFun != NULL){
        if(!strcmp(G_Var[pFun->nameIndex].mark, G_Var[index].mark))
            return pFun->pnum;
        pFun = pFun->next;
    }
    return -1;
}

/*==================Struct symbol table==============*/
void strucTable(int num,...)
{   
    va_list valist; 
    Struc *pStruc = (Struc *)malloc(sizeof(Struc));/
    Node *temp = (Node *)malloc(sizeof(Node));

    pStruc->memNum = memNum;
    memNum = 0;

    va_start(valist, num);           // Initialize parameters which number is num
    temp = va_arg(valist, Node*);    // Take the second node in the variable length parameter list
    pStruc->nameIndex = temp->index;

    strucTail->next = pStruc;
    strucTail = pStruc;
    pStruc->next = NULL;
}


Struc* strucFind(int index)
{
    Struc* pStruc = strucHead->next;

    while(pStruc != NULL){
        if(!strcmp(G_Var[pStruc->nameIndex].mark, G_Var[index].mark))
            return pStruc;
        pStruc = pStruc->next;
    }
    return NULL;
}


int strucMem(int type, int index){
    int i;

    Struc* pStruc = strucHead->next;

    while(pStruc != NULL){
        if(!strcmp(G_Var[pStruc->nameIndex].mark, G_Var[type].mark)){
            for(i = 1; i <= pStruc->memNum; i++){
               // printf("%s %s\n\n\n\n", G_Var[pStruc->nameIndex + i].mark, G_Var[index].mark);
                if(!strcmp(G_Var[pStruc->nameIndex + i].mark, G_Var[index].mark))
                    return 1;     
            }
        }
        pStruc = pStruc->next;
    }
    return 0;
}


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
                        return 0;    
                }
                if(i > num)
                    return 1;
            }
        }
    }
    return 0;
}

/* Get the size of the structure */
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

/* Get the offset of a domain (which must be present in the structure) from the head within the structure. */
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




