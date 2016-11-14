#include "translate.h"

//当前的struct定义处，用于嵌套定义struct的访问。
static Struc* curStruct = NULL;
//当前数组单元大小。
static int curSize = 4;
//当前函数参数表，用来确定某一个变量是结构体的引用还是结构体本身。
static Func* curFun = NULL;

//确定非终结符
int vnType(char *name)
{
	for(int i=0; i<23; i++){
		if(!strcmp(name, nodeType[i]))
			return i;
	}
	return -1;
}

void translate(Node *pNode)
{
	if(pNode == NULL)
		return;
	int type = vnType(pNode->vn.name);
	switch(type){
		case 4: //Specifier
			return ;
		case 10: //FunDec   (FUNCTION, , , f) (PARAM , , , x)
			addCode("FUNCTION", "", "", G_Var[pNode->vn.node[0]->index].mark);
			Func *pFunc = funcFind(pNode->vn.node[0]->index);
			for(int i = 1; i <= pFunc->pnum; i++){
				Struc *pStruc = strucFind(pNode->vn.node[0]->index + i);
				if(pStruc)
					addCode("PARAM", "", "", G_Var[pNode->vn.node[0]->index + (++i)].mark);
				else
					addCode("PARAM", "", "", G_Var[pNode->vn.node[0]->index + i].mark);
			}
			curFun = pFunc;
			break;
		case 15: //Stmt
			switch(pNode->vn.num){
				case 2: //Exp
					translateExp(pNode->vn.node[0], NULL, 0);
					break;
				case 1: //CompSt
					translate(pNode->vn.node[0]);
					break;
				case 3: {//return
					char temp[32];
					translateExp(pNode->vn.node[1], temp, 0);
					addCode("RETURN", "", "", temp); //(RETURN, , , x)
					break;
				}
				case 5: //if, while
					if(pNode->vn.node[0]->index == 265){ //if
						char label1[32], label2[32];
						newLabel(label1);
						newLabel(label2);
						translateCond(pNode->vn.node[2], label1, label2);
						addCode("LABEL", "", "", label1); //(LABEL, , , x)
						translate(pNode->vn.node[4]);
						addCode("LABEL", "", "", label2);
					}
					else{ //while
						char label1[32],label2[32],label3[32];

						newLabel(label1);
						newLabel(label2);
						newLabel(label3);
						addCode("LABEL", "", "", label1);
						translateCond(pNode->vn.node[2],label2,label3);
						addCode("LABEL", "", "", label2);
						translate(pNode->vn.node[4]);
						addCode("GOTO", "", "", label1);
						addCode("LABEL", "", "", label3);
					}
					break;
				case 7: {//if-else
					char label1[32], label2[32], label3[32];

					newLabel(label1);
					newLabel(label2);
					newLabel(label3);
					translateCond(pNode->vn.node[2], label1, label2);
					addCode("LABEL", "", "", label1); //(LABEL, , , x)
					translate(pNode->vn.node[4]);
					addCode("GOTO", "", "", label3); //(GOTO  , , , x)
					addCode("LABEL", "", "", label2);
					translate(pNode->vn.node[6]);
					addCode("LABEL", "", "", label3);
					break;
				}
			}
			break;
		case 19: {//Dec
			Node* p = pNode->vn.node[0]->vn.node[0];
			Var *pVar = varFind(p->index);
			if(pVar->deminsion != 0){
				p = p->vn.node[0];
				Var *pVar = varFind(p->index);
				if(pVar->deminsion != 0){
					printf("IR Error: Variable \"%s\" is multi-dimensional array type or parameters of array type.\n", G_Var[p->index].mark);
					exit(0);
				}
			}
			if(pVar->type >= 0){ //struct size
				// printf("index : %d %s\n", pVar->type, G_Var[pVar->nameIndex].mark);
				char length[8];
				sprintf(length, "%d", structSize(strucFind(pVar->type)));
				// printf("index : %d\n", pVar->type);
				addCode("DEC", length, "", G_Var[pVar->nameIndex].mark);  //(DEC, size, , x)
			}
			if(pNode->vn.num == 3){
				translateExp(pNode->vn.node[2], G_Var[pVar->nameIndex].mark, 1);
			}
			break;
		}
		default:
			for(int i = 0; i < pNode->vn.num; i++)
				translate(pNode->vn.node[i]);
			break;
	}
}

void translateExp(Node *pNode, char *place, int option)
{
	//'(' Exp ')' 
	if(pNode->vn.node[0]->index == '(')  
		return translateExp(pNode->vn.node[1], place, option);
	//Exp '=' Exp 
	else if(pNode->vn.num == 3 && pNode->vn.node[1]->index == '='){ 
		char temp[32];
		translateExp(pNode->vn.node[0], temp, 0);
		translateExp(pNode->vn.node[2], temp, 1);
		if(place != NULL){
			if(option == 0)
				strcpy(place, temp);
			else
				addCode(":=", temp, "", place);    //(:=, y , , x)
		}
	}
	// ID '(' ')' 
	else if(pNode->vn.num == 3 && pNode->vn.node[1]->index == '('){
		if(place == NULL){
			if(!strcmp(G_Var[pNode->vn.node[0]->index].mark, "read"))
				return;
			char temp[32];
			newTemp(temp);
			addCode("CALL", G_Var[pNode->vn.node[0]->index].mark, "", temp); //(CALL, f, , x)
		}
		else{
			if(option == 0)
				newTemp(place);
			if(!strcmp(G_Var[pNode->vn.node[0]->index].mark, "read")){
				addCode("READ" , "", "", place); //(READ  , , , x)	
			}
			else
				addCode("CALL", G_Var[pNode->vn.node[0]->index].mark, "", place); //(CALL, f, , x)
		}
	}
	// ID '(' Args ')'  
	else if(pNode->vn.num == 4 && pNode->vn.node[1]->index == '('){
		if(place == NULL){
			if(!strcmp(G_Var[pNode->vn.node[0]->index].mark, "write")){
				char temp[32];
				translateExp(pNode->vn.node[2]->vn.node[0], temp, 0);
				addCode("WRITE", "", "", temp);    //(WRITE , , , x)
			}
			else{
				Func *pFunc = funcFind(pNode->vn.node[0]->index);
				translateArgs(pNode->vn.node[2], pFunc->nameIndex, pFunc->pnum, 0);
				char temp[32];
				newTemp(temp);
				addCode("CALL", G_Var[pNode->vn.node[0]->index].mark, "", temp); //(CALL, f, , x)
			}
		}
		else{
			if(!strcmp(G_Var[pNode->vn.node[0]->index].mark, "write")){
				char temp[32];
				translateExp(pNode->vn.node[2], temp, 0);
				addCode("WRITE", "", "", temp);    //(WRITE , , , x)
				if(option == 0)
					strcpy(place, "#0");
				else
					addCode(":=", "#0", "", place);    //(:=, y , , x)
			}
			else{
				Func *pFunc = funcFind(pNode->vn.node[0]->index);
				translateArgs(pNode->vn.node[2], pFunc->nameIndex, pFunc->pnum, 0);
				if(option == 0)
					newTemp(place);
				addCode("CALL", G_Var[pNode->vn.node[0]->index].mark, "", place); //(CALL, f, , x)
			}
		}
	}
	if(place == NULL){
		return;
	}
	// INT_NUM   //整型常数
	if(pNode->vn.num == 1 && pNode->vn.node[0]->type == TYPE_NUM){
		// printf("%d\n", pNode->vn.node[0]->numI);
		if(option == 0)
			sprintf(place, "#%d", pNode->vn.node[0]->numI);
		else{
			char temp[32];
			sprintf(temp, "#%d", pNode->vn.node[0]->numI);
			addCode(":=", temp, "", place);
		}
	}
	// ID 
	else if(pNode->vn.num == 1 && pNode->vn.node[0]->kind == TYPE_VAR){
		if(option == 0){
			strcpy(place, G_Var[pNode->vn.node[0]->index].mark);
		}
		else
			addCode(":=", G_Var[pNode->vn.node[0]->index].mark, "", place);
	}
	// Exp '+' Exp  Exp '-' Exp  Exp '*' Exp  Exp '/' Exp 
	else if((pNode->vn.num == 3) && (pNode->vn.node[1]->index == '+' || pNode->vn.node[1]->index == '-' || pNode->vn.node[1]->index == '*' ||pNode->vn.node[1]->index == '/')){
		char temp1[32], temp2[32];
		translateExp(pNode->vn.node[0], temp1, 0);
		translateExp(pNode->vn.node[2], temp2, 0);
		//temp1 == 0 * /
		if((temp1[0] == '#' && temp1[1] == '0') && (pNode->vn.node[1]->index == '*' || pNode->vn.node[1]->index == '/')){
			if(option == 0)
				strcpy(place, "#0");
			else
				addCode(":=", "#0", "", place);
		}
		//temp2 == 0 * /
		if((temp2[0] == '#' && temp2[1] == '0') && (pNode->vn.node[1]->index == '*' || pNode->vn.node[1]->index == '/')){
			if(option == 0)
				strcpy(place, "#0");
			else
				addCode(":=", "#0", "", place);
		}
		//temp1 temp2均为常数
		else if(temp1[0]=='#' && temp2[0]=='#'){
			int op1 = strtol(&temp1[1], NULL, 10);
			int op2 = strtol(&temp2[1], NULL, 10);
			if(pNode->vn.node[1]->index == '+'){
				if(option==0)
					sprintf(place, "#%d", op1+op2);
				else{
					char temp[32];
					sprintf(temp, "#%d", op1+op2);
					addCode(":=", temp, "", place);
				}
			}
			else if(pNode->vn.node[1]->index == '-'){
				if(option==0)
					sprintf(place, "#%d", op1-op2);
				else{
					char temp[32];
					sprintf(temp, "#%d", op1-op2);
					addCode(":=", temp, "", place);
				}
			}
			else if(pNode->vn.node[1]->index == '*'){
				if(option==0)
					sprintf(place, "#%d", op1*op2);
				else{
					char temp[32];
					sprintf(temp, "#%d", op1*op2);
					addCode(":=", temp, "", place);
				}
			}
			else{
				if(option==0)
					sprintf(place, "#%d", op1/op2);
				else{
					char temp[32];
					sprintf(temp, "#%d", op1/op2);
					addCode(":=", temp, "", place);
				}
			}
		}
		//temp2 == 0
		else if(temp2[0]=='#' && temp2[1]=='0'){
			if(option == 0)
				strcpy(place, temp1);
			else
				addCode(":=", temp1, "", place);
		}
		//temp1 == 0 +
		else if(temp1[0]=='#' && temp1[1]=='0' && pNode->vn.node[1]->index == '+'){
			if(option == 0)
				strcpy(place, temp2);
			else
				addCode(":=", temp2, "", place);
		}
		else{
			char op[2];
			op[0] = pNode->vn.node[1]->index;
			op[1] = '\0';
			if(option==0)
				newTemp(place);
			addCode(op, temp1, temp2, place); //(op, y, z, x)
		}
	}
	// '-' Exp
	else if(pNode->vn.node[0]->index == '-'){
		char temp[32];
		translateExp(pNode->vn.node[1], temp, 0);
		//常数
		if(temp[0] == '#'){
			int op = strtol(&temp[1], NULL, 10);
			if(option == 0)
				sprintf(place, "#%d", -op);
			else{
				char temp[32];
				sprintf(temp, "#%d", -op);
				addCode(":=", temp, "", place);
			}
		}
		else{
			if(option == 0)
				newTemp(place);
			addCode("-", "#0", temp, place);
		}
	}
	// '!' Exp 、Exp Relop Exp 、Exp And Exp 、Exp Or Exp 
	else if(pNode->vn.node[0]->index == '!' || pNode->vn.node[1]->index == 274 || pNode->vn.node[1]->index == 272 || pNode->vn.node[1]->index == 273){
		char label1[32], label2[32];
		newLabel(label1);
		newLabel(label2);
		if(option == 0)
			newTemp(place);
		addCode(":=", "#0", "", place);
		translateCond(pNode, label1, label2);
		addCode("LABEL", "", "", label1);
		addCode(":=", "#1", "", place);
		addCode("LABEL", "", "", label2);
	}
	// Exp '[' Exp ']' 
	else if(pNode->vn.num == 4 && pNode->vn.node[1]->index == '['){
		char temp1[32], temp2[32];
		getLocation(pNode->vn.node[0], temp1);
		translateExp(pNode->vn.node[2], temp2, 0);
		//EXP2 == 0
		if(temp2[0]=='#' && temp2[1]=='0'){
			char temp[32];
			if(temp1[0] == '&')
				strcpy(temp, &temp1[1]);
			else
				sprintf(temp, "*%s", temp1);
			if(option == 0)
				strcpy(place, temp);
			else
				addCode(":=", temp, "", place);
		}
		//EXP2为常数
		else if(temp2[0] == '#')
		{
			int op = strtol(&temp2[1], NULL, 10);

			char temp[32], offset[32];
			sprintf(offset, "#%d", op * curSize);

			newTemp(temp);
			addCode("+", temp1, offset, temp);

			char result[32];
			sprintf(result, "*%s", temp);

			if(option==0)
				strcpy(place, result);
			else
				addCode(":=", result, "", place);
		}
		else
		{
			char temp[32], offset[32], result[32], num[32];
			sprintf(num, "#%d", curSize);
			newTemp(temp);
			newTemp(offset);
			addCode("*", temp2, num, offset);
			addCode("+", temp1, offset, temp);
			sprintf(result, "*%s", temp);

			if(option == 0)
				strcpy(place, result);
			else
				addCode(":=", result, "", place);
		}
	}
	// Exp '.' ID 
	else if(pNode->vn.num == 3 && pNode->vn.node[1]->index == '.'){
		//close_opt();
		char left[32], temp[32], result[32];

		getLocation(pNode->vn.node[0], left);

		int offseti = structOffset(curStruct, pNode->vn.node[2]->index);
		char offset[32];
		sprintf(offset, "#%d", offseti);

		newTemp(temp);
		addCode("+", left, offset, temp);

		sprintf(result, "*%s", temp);
		if(option == 0)
			strcpy(place, result);
		else
			addCode(":=", result, "", place);
	}
}

void translateArgs(Node* pNode, int funIndex, int pnum, int count)
{
	//Exp ',' Args 
	if(pNode->vn.num == 3)
		translateArgs(pNode->vn.node[2], funIndex, pnum, count+1);
	// Exp
	if(count < pnum){
		Struc *pStruc = strucFind(funIndex + count + 1);
		if(pStruc){ //struct 
			char temp[32];
			getLocation(pNode->vn.node[0], temp);
			addCode("ARG", "", "", temp);
		}
		else{
			Var* pVar = varFind(funIndex + count + 1);
			if(pVar->deminsion == 0){
				char temp[32];
				translateExp(pNode->vn.node[0], temp, 0);
				addCode("ARG", "", "", temp);
			}
			else{
				printf("IR: Can't deal with using array as args.\n");
				exit(0);
			}
		}
	}
}

void translateCond(Node* pNode, char* labelTrue, char* labelFalse)
{
	if(pNode->vn.node[0]->index == '!')
		return translateCond(pNode->vn.node[1], labelFalse, labelTrue);
	// exp relop exp
	if(pNode->vn.num == 3 && (pNode->vn.node[1]->index == '<' || pNode->vn.node[1]->index == '>' || pNode->vn.node[1]->index == 268 || pNode->vn.node[1]->index == 269 || pNode->vn.node[1]->index == 270 || pNode->vn.node[1]->index == 271))
	{
		char temp1[32], temp2[32];
		translateExp(pNode->vn.node[0], temp1, 0);
		translateExp(pNode->vn.node[2], temp2, 0);

		//temp1 temp2为常数
		if(temp1[0]=='#' && temp2[0]=='#'){
			int op1 = strtol(&temp1[1], NULL, 10);
			int op2 = strtol(&temp2[1], NULL, 10);
			switch(pNode->vn.node[1]->index){
				case '>':
					if(op1 > op2)
						addCode("GOTO", "", "", labelTrue);
					else
						addCode("GOTO", "", "", labelFalse);
					break;
				case '<':
					if(op1 < op2)
						addCode("GOTO", "", "", labelTrue);
					else
						addCode("GOTO", "", "", labelFalse);
					break;
				case 268: //>=
					if(op1 >= op2)
						addCode("GOTO", "", "", labelTrue);
					else
						addCode("GOTO", "", "", labelFalse);
					break;
				case 269: //<=
					if(op1 <= op2)
						addCode("GOTO", "", "", labelTrue);
					else
						addCode("GOTO", "", "", labelFalse);
					break;
				case 270: //==
					if(op1 == op2)
						addCode("GOTO", "", "", labelTrue);
					else
						addCode("GOTO", "", "", labelFalse);
					break;
				case 271: //!=
					if(op1 != op2)
						addCode("GOTO", "", "", labelTrue);
					else
						addCode("GOTO", "", "", labelFalse);
					break;
			}
		}
		else{
			addCode(G_Def[pNode->vn.node[1]->index].name, temp1, temp2, labelTrue);
			addCode("GOTO", "", "", labelFalse);
		}
	}
	// exp and exp
	else if(pNode->vn.num == 3 && pNode->vn.node[1]->index == 272)
	{
		char label[32];
		newLabel(label);
		translateCond(pNode->vn.node[0], label, labelFalse);
		addCode("LABEL", "", "", label);
		translateCond(pNode->vn.node[2], labelTrue, labelFalse);
	}
	// exp or exp
	else if(pNode->vn.num == 3 && pNode->vn.node[1]->index == 273)
	{
		char label[32];
		newLabel(label);
		translateCond(pNode->vn.node[0], labelTrue, label);
		addCode("LABEL", "", "", label);
		translateCond(pNode->vn.node[2], labelTrue, labelFalse);
	}
	// if while
	else
	{
		char temp[32];
		translateExp(pNode, temp, 0);
		if(temp[0]=='#'){
			if(temp[1]=='0')
				addCode("GOTO", "", "", labelFalse);
			else
				addCode("GOTO", "", "", labelTrue);
		}
		else
		{
			addCode("!=", temp, "#0", labelTrue);
			addCode("GOTO", "", "", labelFalse);
		}
	}
}

void getLocation(Node*pNode, char* place)
{
	//ID
	if(pNode->vn.num == 1){
		Var* pVar = varFind(pNode->vn.node[0]->index);
		if(pVar->type > 0)  //struct
			curStruct = strucFind(pVar->type);
		else
			curSize = 4;
		for(int i=1; i<=curFun->pnum; i++)
			if(!strcmp(G_Var[curFun->nameIndex + i].mark, G_Var[pVar->nameIndex].mark)){
				strcpy(place, G_Var[pNode->vn.node[0]->index].mark);
				return;
			}
		sprintf(place, "&%s", G_Var[pNode->vn.node[0]->index].mark);
	}
	// exp [ exp ]
	else if(pNode->vn.num == 4 && pNode->vn.node[1]->index == '['){
		char temp1[32],temp2[32];

		getLocation(pNode->vn.node[0], temp1);
		translateExp(pNode->vn.node[2], temp2, 0);
		// temp2为0
		if(temp2[0]=='#'&& temp2[1]=='0'){
			strcpy(place, temp1);
		}
		// temp2为非0常数
		else if(temp2[0]=='#'){
			int op = strtol(&temp2[1], NULL, 10);
			char temp[32],offset[32];
			newTemp(temp);
			sprintf(offset, "#%d", op * curSize);
			addCode("+", temp1, offset, temp);
			strcpy(place, temp);
		}
		else{
			char temp[32], offset[32], num[32];
			sprintf(num, "#%d", curSize);
			newTemp(temp);
			newTemp(offset);
			addCode("*", temp2, num, offset);
			addCode("+", temp1, offset, temp);;
			strcpy(place, temp);
		}
	}
	//exp . id
	else{
		char left[32];
		getLocation(pNode->vn.node[0], left);
		int offseti = structOffset(curStruct, pNode->vn.node[2]->index);
		char offset[32];
		sprintf(offset, "#%d", offseti);
		newTemp(place);
		addCode("+", left, offset, place);

		Var* pVar = varFind(pNode->vn.node[2]->index);
		if(pVar->type > 0){
			curStruct = strucFind(pVar->type);
		}
	}
}






