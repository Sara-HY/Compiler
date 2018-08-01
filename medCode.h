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

typedef struct interCodes {
	char args[4][32];
	struct interCodes *prev; 
	struct interCodes *next;
}InterCodes;

/* Label/temp counter, to generate a new label, temp */
static int tempCount=0, labelCount=0;

static InterCodes* codeHead = NULL, *codeTail = NULL;


/* Initialize the representation of intermediate code */
void initCode();

void destroyCode();

/* Generate the new label */
void newLabel(char* name);

/* Generate the new temp variables */
void newTemp(char* name);

int typeCode(char* code);

void addCode(char* code0, char* code1, char* code2, char* code3);

void printCode(FILE *target_file1, FILE *target_file2);

#endif


