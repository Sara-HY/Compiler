#include "ast.h"

int G_iVarMaxIndex = 0;  /* 变量最大个数 */
int G_iVarCurIndex = -1; /* 变量当前索引 */

Node *set_int(int value) {
    Node *p;
    size_t sizeNode;
    /* 分配结点空间 */
    sizeNode = sizeof(Node);
 
    if((p = (Node *)malloc(sizeNode)) == NULL)
        yyerror("out of memory");  
    /* 复制内容 */
    p->kind = TYPE_CONST;
    p->type = TYPE_NUM;
    p->numI = value;
 
    return p;
}

Node *set_float(float value){
    Node *p;
    size_t sizeNode;
    /* 分配结点空间 */
    sizeNode = sizeof(Node);
 
    if((p = (Node *)malloc(sizeNode)) == NULL)
        yyerror("out of memory");  
    /* 复制内容 */
    p->kind = TYPE_CONST;
    p->type = TYPE_FLOAT;
    p->numF = value;
 
    return p;
}

Node *set_var(int value) {
    Node *p;
    size_t sizeNode;
    /* 分配结点空间 */
    sizeNode = sizeof(Node);
 
    if((p = (Node *)malloc(sizeNode)) == NULL)
        yyerror("out of memory");
    /* 复制内容 */
    p->kind = TYPE_VAR;
    p->index = value;
    return p;
}

Node *set_terminal(int value){
    Node *p;
    size_t sizeNode;
    /* 分配结点空间 */
    sizeNode = sizeof(Node);
 
    if((p = (Node *)malloc(sizeNode)) == NULL)
        yyerror("out of memory");
    /* 复制内容 */
    p->kind = TYPE_TERMINAL;
    p->index = value;
    return p;
}

Node *set_vn(char* name, int num, ...) {
    va_list valist;
    Node *p;
    size_t sizeNode;
    int i;
    /* 分配结点空间 */
    sizeNode = sizeof(Node);
    if((p = (Node *)malloc(sizeNode)) == NULL)
        yyerror("out of memory");
    /* 复制内容 */
    p->kind = TYPE_UNTREMINAL;
    strcpy(p->vn.name, name);
    p->vn.num = num;
    va_start(valist, num);
    p->vn.node = (Node **)malloc(num * sizeof(Node *));
    for(i = 0; i < num; i++)
        p->vn.node[i] = va_arg(valist, Node*);
    va_end(valist);

    if(num == 1){
        p->index = p->vn.node[0]->index;
        p->type = p->vn.node[0]->type;
    }

    return p;
}

void add_var(char *mark){   
    strcpy(G_Var[G_iVarMaxIndex].mark, mark); 
    G_iVarCurIndex = G_iVarMaxIndex;
    G_iVarMaxIndex++;
}

void NodeFree(Node *p){
    int i;
    if(!p) 
        return;
    if(p->kind == TYPE_UNTREMINAL){
        for(i = 0; i < p->vn.num; i++){
            NodeFree(p->vn.node[i]);
            p->vn.node[i] = NULL;
        }
        p->vn.node = NULL;
    }
    free(p);
    p = NULL;
}

void tabprint(FILE* target_file, int num){
    int i = 0;
    for(i=0; i<num; i++){
        fprintf(target_file, "\t");
    }
}


int NodeExecute(Node *p, int num){
    int i = 0;

    if(p == NULL)
        return 0;
    switch(p->kind){
        case TYPE_CONST:  tabprint(target_file, num);
                        if(p->type == TYPE_FLOAT)
                            fprintf(target_file, "FLOAT_NUM: %.3f\n", p->numF); 
                        else 
                            fprintf(target_file, "INT_NUM: %d\n", p->numI);
                        return 0;
        case TYPE_VAR: tabprint(target_file, num);
                        fprintf(target_file, "Iden: %s\n", G_Var[p->index].mark);
                        return 0;
        case TYPE_TERMINAL: tabprint(target_file, num);
                            fprintf(target_file, "%s\n", G_Def[p->index].name);
                            return 0;
        case TYPE_UNTREMINAL:   tabprint(target_file, num);
                                fprintf(target_file, "%s\n", p->vn.name);
                                for(i=0; i<(p->vn.num); i++)
                                    NodeExecute(p->vn.node[i], num+1);
                                return 0;
        default: return 0;
    }
}







