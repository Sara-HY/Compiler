#include "medCode.h"
#include "finCode.h"

//初始化中间代码表示
void initCode(){
	codeHead = (InterCodes *)malloc(sizeof(InterCodes));
	codeHead->prev = NULL;
	codeHead->next = NULL;

	codeTail = codeHead;
}

//释放中间代码表示
void destroyCode()
{
	InterCodes *pCode;
	while(codeHead){
		pCode = codeHead->next;
		free(codeHead);
		codeHead = pCode;
	}
}

//生成新的label，名称放在提供好的name里面。
void newLabel(char* name)
{
	char label[16];

	strcpy(name, "label");
	itoa(labelCount, label, 10);
	labelCount++;
	strcat(name, label);
}

//生成新的临时变量，名称放在提供好的name里面。
void newTemp(char* name)
{
	char temp[16];

	strcpy(name, "t");
	itoa(tempCount, temp, 10);
	tempCount++;
	strcat(name, temp);
}

//添加一条代码，指明这条代码的词数，然后传入各个词语，各个词语都是char*，即传入多个字符串
void addCode(char* code0, char* code1, char* code2, char* code3)
{
	InterCodes *pCode = (InterCodes *)malloc(sizeof(InterCodes));

	strcpy(pCode->args[0], code0);
	strcpy(pCode->args[1], code1);
	strcpy(pCode->args[2], code2);
	strcpy(pCode->args[3], code3);

	codeTail->next = pCode;
	pCode->prev = codeTail;
	pCode->next = NULL; 
	codeTail = pCode;
}

//将内存中的代码打印到文件中，传入新文件路径，并顺便清理内存中的代码存储
void printCode(FILE *target_file1, FILE *target_file2)
{
	int type;
	InterCodes *pCode = codeHead->next;
	while(pCode){
		type = typeCode(pCode->args[0]);
		switch(type){
			case 0: case 1: case 2: case 3: case 4: case 5:
				fprintf(target_file1, "%s %s\n", pCode->args[0], pCode->args[3]);
				break;
			case 6: case 7:
				fprintf(target_file1, "%s %s :\n", pCode->args[0], pCode->args[3]);
				break;
			case 8:
				fprintf(target_file1, "DEC %s %s\n", pCode->args[3], pCode->args[1]);
				break;
			case 9: //:=
				fprintf(target_file1, "%s := %s\n", pCode->args[3], pCode->args[1]);
				break;
			case 10:
				fprintf(target_file1, "%s := CALL %s\n", pCode->args[3], pCode->args[1]);
				break;
			case 11:
				fprintf(target_file1, "%s := %s + %s\n", pCode->args[3], pCode->args[1], pCode->args[2]);
				break;
			case 12:
				fprintf(target_file1, "%s := %s - %s\n", pCode->args[3], pCode->args[1], pCode->args[2]);
				break;
			case 13:
				fprintf(target_file1, "%s := %s * %s\n", pCode->args[3], pCode->args[1], pCode->args[2]);
				break;
			case 14:
				fprintf(target_file1, "%s := %s / %s\n", pCode->args[3], pCode->args[1], pCode->args[2]);
				break;
			case 15:
				fprintf(target_file1, "IF %s < %s GOTO %s\n", pCode->args[1], pCode->args[2], pCode->args[3]);
				break;
			case 16:
				fprintf(target_file1, "IF %s > %s GOTO %s\n", pCode->args[1], pCode->args[2], pCode->args[3]);
				break;
			case 17:
				fprintf(target_file1, "IF %s == %s GOTO %s\n", pCode->args[1], pCode->args[2], pCode->args[3]);
				break;
			case 18:
				fprintf(target_file1, "IF %s != %s GOTO %s\n", pCode->args[1], pCode->args[2], pCode->args[3]);
				break;
			case 19:
				fprintf(target_file1, "IF %s LE %s GOTO %s\n", pCode->args[1], pCode->args[2], pCode->args[3]);
				break;
			case 20:
				fprintf(target_file1, "IF %s GE %s GOTO %s\n", pCode->args[1], pCode->args[2], pCode->args[3]);
				break;	
		}
		pCode = pCode->next;
	}
	finCode(target_file2, codeHead);
}

int typeCode(char* code)
{
	unsigned i, j;

	for(i=0; i<21; i++){
		if(!strcmp(code, codeType[i]))
			return i;
	}
	return -1;
}