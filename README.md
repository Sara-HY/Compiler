## C-- COMPILER

It is a simple compiler for C--, a subset of C, including lexical analysis, syntactic analysis, semantic analysis, intermediate code generation and object code generation.

The generated object code is MIPS32 Instructions, which can run on any MIPS simulators, such as *QtSPIM*.

* The errors which the compiler can analyze: images/errors.png.
* The codes transfer process: images/codes.png.

### Implementation Stage

#### 1. Lexical Analysis
**Regular Expression** matching method.
  - Codes: lex.l, lex_unit_test.l (For Unit Test).
  - Result: test.txt

#### 2. Syntactic Analysis
Word Stream --> Syntax Tree (Multiway Tree). A Bottom-up analysis technique, **LALR(1)**, which is used in Bison default.
  - Codes: ash.h, ash.c, yacc.y
  - Result: test.tree 
	
#### 3. Semantic Analysis
Build and Maintain **Symbol Table**.
  - Codes: semantic.h, semantic.c
  - Result: test.tree 

#### 4. Intermediate Code Generation (Quad)
Modular -- the source language can be separated from the target language.
  - Codes: translate.h, translate.c, medCode.h, medCode.c
  - Result: test.med 

#### 5. Object Code Generation (MIPS32)
The Simple Register Allocation Algorithm -- putting all variables in memory.
  - Codes: finCode.h, finCode.c
  - Result: test.asm

### Environment
* Flex: GNU Flex version 2.5.4
* Bison: GNU Bison version 2.4.1
* Compiler: GCC version 4.9.2
* Simulator: QtSPIM version 9.1.9

###  Run
```
$ make
$ compiler test.c
```
