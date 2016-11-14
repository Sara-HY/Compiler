#include "finCode.h"

int dataLoc(char* name)
{
	if(name[0]=='#')
		return -1;
	if(name[0]=='*'||name[0]=='&')
		name++;
	for(int i=0; i<dataNum; i++){	
		if(!strcmp(name, dataFlow[i].name))
			return dataFlow[i].location;
	}
	return -1;
}

void dataAdd(char* name, int size)
{
	if(name[0]=='#')
		return;
	if(name[0]=='*'||name[0]=='&')
		name++;
	if(dataLoc(name)!=-1)
		return;
	dataFlow[dataNum].location = totalSize;
	totalSize += size;
	strcpy(dataFlow[dataNum++].name, name);
}

void regAlloc(FILE *target_file, char* name, int num)
{
	char temp[8];
	sprintf(temp, "$t%d", num);
	if(name[0]=='*'){
		fprintf(target_file, "lw %s,%d($sp)\n", temp, dataLoc(name));
		fprintf(target_file, "add %s,%s,$sp\n", temp, temp);
		fprintf(target_file, "lw %s,0(%s)\n", temp, temp);
	}
	else if(name[0]=='&'){
		fprintf(target_file, "li %s,%d\n", temp, dataLoc(name));
	}
	else if(name[0]=='#'){
		fprintf(target_file, "li %s,%s\n", temp, &name[1]);
	}
	else{
		fprintf(target_file, "lw %s,%d($sp)\n", temp, dataLoc(name));
	}
}


void finCode(FILE *target_file, InterCodes* pCode)
{
	codeHead = pCode;
	fprintf(target_file, "%s\n",".data");
	fprintf(target_file, "%s\n","_prompt: .asciiz \"Enter an integer:\"");
	fprintf(target_file, "%s\n","_ret: .asciiz \"\\n\"");
	fprintf(target_file, "%s\n",".globl main");
	fprintf(target_file, "%s\n",".text");
	fprintf(target_file, "%s\n","read:");
	fprintf(target_file, "%s\n","li $v0, 4");
	fprintf(target_file, "%s\n","la $a0, _prompt");
	fprintf(target_file, "%s\n","syscall");
	fprintf(target_file, "%s\n","li $v0, 5");
	fprintf(target_file, "%s\n","syscall");
	fprintf(target_file, "%s\n","jr $ra");
	fprintf(target_file, "%s\n","write:");
	fprintf(target_file, "%s\n","li $v0, 1");
	fprintf(target_file, "%s\n","syscall");
	fprintf(target_file, "%s\n","li $v0, 4");
	fprintf(target_file, "%s\n","la $a0, _ret");
	fprintf(target_file, "%s\n","syscall");
	fprintf(target_file, "%s\n","move $v0, $0");
	fprintf(target_file, "%s\n","jr $ra");
	InterCodes *p = codeHead->next, *q;
	do{
		q = p->next;
		while(q != NULL){
			if(!strcmp(q->args[0], "FUNCTION"))
				break;
			q = q->next;
		}
		instructions(target_file, p, q);
		p = q;
	}while(p != NULL);
}

//将对应的中间代码转换为相关指令
void instructions(FILE *target_file, InterCodes* pHead, InterCodes* pTail)
{
	fprintf(target_file, "%s:\n", pHead->args[3]);
	dataADDs(pHead, pTail);
	fprintf(target_file, "addi $sp, $sp, -%d\n", totalSize);
	instruction(target_file, pHead, pTail);
}

void dataADDs(InterCodes* pHead, InterCodes* pTail)
{
	InterCodes *pCode = pHead->next;
	while(pCode != pTail){
		int type = typeCode(pCode->args[0]);
		switch(type){
			case 0: //"GOTO" (GOTO  , , , x)
				dataAdd(pCode->args[3], 4);
				break;
			case 8:{ //DEC (DEC, size, , x)
				int temp = strtol(pCode->args[1], NULL, 10);
				dataAdd(pCode->args[3], temp);
				break;
			}
			case 9: //":="   (:=, y , , x) (:=, &y, , x) (:=, *y, , x) (:=, y, , *x)
				dataAdd(pCode->args[1], 4);
				dataAdd(pCode->args[3], 4);
				break;
			case 10: //"CALL" (CALL, f, , x)
				dataAdd(pCode->args[3], 4);
				break;
			case 11: case 12: case 13: case 14: // "+" (+, y, z, x) "-" (-, y, z, x) "*" (*, y, z, x) "/" (/, y, z, x)
				dataAdd(pCode->args[1], 4);
				dataAdd(pCode->args[2], 4);
				dataAdd(pCode->args[3], 4);
				break;
			case 15: case 16: case 17: case 18: case 19: case 20:  //(<, x, y, z) (>, x, y, z) (Equal, x, y, z) (UnEqual, x, y, z) (LE, x, y, z) (GE, x, y, z)
				dataAdd(pCode->args[1], 4);
				dataAdd(pCode->args[2], 4);
				break;
			default: ;
		}
		pCode = pCode->next;
	}
}

void instruction(FILE *target_file, InterCodes* pHead, InterCodes* pTail)
{
	InterCodes *pCode = pHead->next;
	while(pCode != pTail){
		int type = typeCode(pCode->args[0]);
		switch(type){
			case 0: //"GOTO" (GOTO  , , , x)
				fprintf(target_file, "j %s\n", pCode->args[3]);
				break;
			case 1: //return
				regAlloc(target_file, pCode->args[3], 0);
				fprintf(target_file, "move $v0,$t0\n");
				fprintf(target_file, "addi $sp, $sp, %d\n", totalSize);
				fprintf(target_file, "jr $ra\n");
				break;
			case 2: //ARG
				regAlloc(target_file, pCode->args[3], 0);
				fprintf(target_file, "move $a%d,$t0\n", argCount);
				argCount++;
				break;
			case 3: { //PARAM
				int paraCount = 0;
				InterCodes *q = pCode;
				while(!strcmp(q->next->args[0], "PARAM")){
					q = q->next;
					paraCount++;
				}
				fprintf(target_file, "sw $a%d,%d($sp)\n", paraCount, dataLoc(pCode->args[3]));
				break;
			}
			case 4: //READ
				fprintf(target_file, "addi $sp, $sp, -4\n");
				fprintf(target_file, "sw $ra, 0($sp)\n");
				fprintf(target_file, "jal read\n");
				fprintf(target_file, "lw $ra, 0($sp)\n");
				fprintf(target_file, "addi $sp, $sp, 4\n");
				if(pCode->args[3][0] == '*'){
					fprintf(target_file, "lw $t0, %d($sp)\n", dataLoc(pCode->args[3]));
					fprintf(target_file, "add $t0, $t0, $sp\n");
					fprintf(target_file, "sw $v0, 0($t0)\n");
				}
				else
					fprintf(target_file, "sw $v0,%d($sp)\n",dataLoc(pCode->args[3]));
				break;
			case 5: //WRITE
				regAlloc(target_file, pCode->args[3], 0);
				fprintf(target_file, "move $a0, $t0\n");
				fprintf(target_file, "addi $sp, $sp, -4\n");
				fprintf(target_file, "sw $ra, 0($sp)\n");
				fprintf(target_file, "jal write\n");
				fprintf(target_file, "lw $ra, 0($sp)\n");
				fprintf(target_file, "addi $sp, $sp, 4\n");
				break;
			case 6:
				fprintf(target_file, "%s:\n", pCode->args[3]);
				break;
			case 8: //DEC (DEC, size, , x)
				fprintf(target_file, "%s:\n", pCode->args[3]);
				break;
			case 9: //":="   (:=, y , , x) (:=, &y, , x) (:=, *y, , x) (:=, y, , *x)
				regAlloc(target_file, pCode->args[1], 0);
				if(pCode->args[3][0]=='*'){
					fprintf(target_file, "lw $t1, %d($sp)\n", dataLoc(pCode->args[3]));
					fprintf(target_file, "add $t1, $t1, $sp\n");
					fprintf(target_file, "sw $t0, 0($t1)\n");
				}
				else
					fprintf(target_file, "sw $t0, %d($sp)\n", dataLoc(pCode->args[3]));
				break;
			case 10: //"CALL" (CALL, f, , x)
				argCount = 0;
				fprintf(target_file, "addi $sp, $sp, -4\n");
				fprintf(target_file, "sw $ra, 0($sp)\n");
				fprintf(target_file, "jal %s\n",pCode->args[1]);
				fprintf(target_file, "lw $ra, 0($sp)\n");
				fprintf(target_file, "addi $sp, $sp, 4\n");
				if(pCode->args[3][0]=='*'){
					fprintf(target_file, "lw $t0, %d($sp)\n", dataLoc(pCode->args[3]));
					fprintf(target_file, "add $t0, $t0 ,$sp\n");
					fprintf(target_file, "sw $v0, 0($t0)\n");
				}
				else
					fprintf(target_file, "sw $v0,%d($sp)\n", dataLoc(pCode->args[3]));
				break;
			case 11: // "+" (+, y, z, x) 
				regAlloc(target_file, pCode->args[1], 0);
				regAlloc(target_file, pCode->args[2], 1);
				fprintf(target_file, "add $t0, $t0, $t1\n");
				if(pCode->args[3][0] == '*'){
					fprintf(target_file, "lw $t1, %d($sp)\n", dataLoc(pCode->args[3]));
					fprintf(target_file, "add $t1, $t1 ,$sp\n");
					fprintf(target_file, "sw $t0, 0($t1)\n");
				}
				else
					fprintf(target_file, "sw $t0, %d($sp)\n", dataLoc(pCode->args[3]));
				break;
			case 12: //"-" (-, y, z, x) 
				regAlloc(target_file, pCode->args[1], 0);
				regAlloc(target_file, pCode->args[2], 1);
				fprintf(target_file, "sub $t0, $t0, $t1\n");
				if(pCode->args[3][0] == '*'){
					fprintf(target_file, "lw $t1, %d($sp)\n", dataLoc(pCode->args[3]));
					fprintf(target_file, "add $t1, $t1 ,$sp\n");
					fprintf(target_file, "sw $t0, 0($t1)\n");
				}
				else
					fprintf(target_file, "sw $t0, %d($sp)\n", dataLoc(pCode->args[3]));
				break;
			case 13: //"*" (*, y, z, x)
				regAlloc(target_file, pCode->args[1], 0);
				regAlloc(target_file, pCode->args[2], 1);
				fprintf(target_file, "mul $t0, $t0, $t1\n");
				if(pCode->args[3][0] == '*'){
					fprintf(target_file, "lw $t1, %d($sp)\n", dataLoc(pCode->args[3]));
					fprintf(target_file, "add $t1, $t1 ,$sp\n");
					fprintf(target_file, "sw $t0, 0($t1)\n");
				}
				else
					fprintf(target_file, "sw $t0, %d($sp)\n", dataLoc(pCode->args[3]));
				break;
			case 14: // "/" (/, y, z, x)
				regAlloc(target_file, pCode->args[1], 0);
				regAlloc(target_file, pCode->args[2], 1);
				fprintf(target_file, "div $t0, $t1\n");
				fprintf(target_file, "mflo $t0\n");
				if(pCode->args[3][0] == '*'){
					fprintf(target_file, "lw $t1, %d($sp)\n", dataLoc(pCode->args[3]));
					fprintf(target_file, "add $t1, $t1 ,$sp\n");
					fprintf(target_file, "sw $t0, 0($t1)\n");
				}
				else
					fprintf(target_file, "sw $t0, %d($sp)\n", dataLoc(pCode->args[3]));
				break;
			case 15: //(<, x, y, z)  
				regAlloc(target_file, pCode->args[1], 0);
				regAlloc(target_file, pCode->args[2], 1);
				fprintf(target_file, "%s $t0,$t1,%s\n", "blt", pCode->args[3]);
				break;
			case 16: //(>, x, y, z) 
				regAlloc(target_file, pCode->args[1], 0);
				regAlloc(target_file, pCode->args[2], 1);
				fprintf(target_file, "%s $t0,$t1,%s\n", "bgt", pCode->args[3]);
				break;
			case 17: //(Equal, x, y, z)
				regAlloc(target_file, pCode->args[1], 0);
				regAlloc(target_file, pCode->args[2], 1);
				fprintf(target_file, "%s $t0,$t1,%s\n", "beq", pCode->args[3]);
				break;
			case 18: //(UnEqual, x, y, z)
				regAlloc(target_file, pCode->args[1], 0);
				regAlloc(target_file, pCode->args[2], 1);
				fprintf(target_file, "%s $t0,$t1,%s\n", "bne", pCode->args[3]);
				break;
			case 19: //(LE, x, y, z)
				regAlloc(target_file, pCode->args[1], 0);
				regAlloc(target_file, pCode->args[2], 1);
				fprintf(target_file, "%s $t0,$t1,%s\n", "ble", pCode->args[3]);
				break;
			case 20: //(GE, x, y, z)
				regAlloc(target_file, pCode->args[1], 0);
				regAlloc(target_file, pCode->args[2], 1);
				fprintf(target_file, "%s $t0,$t1,%s\n", "bge", pCode->args[3]);
				break;
			default: ;
		}
		pCode = pCode->next;
	}
}

