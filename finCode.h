#ifndef fincode_h
#define fincode_h

#include "medCode.h"
#define MAXDATA 1024

typedef struct data
{
	char name[32];
	int location;
}DATA;

static InterCodes* codeHead;
static int argCount = 0;
static int totalSize = 0;
static int dataNum = 0;
static DATA dataFlow[MAXDATA];

int daraLoc(char* name);
void dataAdd(char* name, int size);
void regAlloc(FILE *target_file, char* name, int num);

void dataADDs(InterCodes* pHead, InterCodes* pTail);
void instruction(FILE *target_file, InterCodes* pHead, InterCodes* pTail);

/* Convert the intermediate codes to final instructions */
void instructions(FILE *target_file, InterCodes* pHead, InterCodes* pTail);
void finCode(FILE *target_file, InterCodes* pCode);

#endif