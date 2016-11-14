
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "yacc.y"
 
	#include <ctype.h>
	#include <stdio.h>
   	#include <string.h>
  	#include <stdlib.h>
  	#include <stdarg.h>
  	#include "ast.h"
  	
  	extern int yylex(void);
  	extern char* yytext;
  	extern int yylineno;

	typedef union{	
		int numI;  /* 变量值 */
		float numF;
		int index;  /* 用于存放 变量数组索引 或 一元操作符值 或 多元操作符索引 */
		Node *node; /* 结点地址 */
	}yystype;
	#define YYSTYPE yystype

  	// void yyerror(char* s);


/* Line 189 of yacc.c  */
#line 97 "yacc.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_NUM = 258,
     FLOAT_NUM = 259,
     ID = 260,
     INT = 261,
     FLOAT = 262,
     STRUCT = 263,
     RETURN = 264,
     IF = 265,
     ELSE = 266,
     WHILE = 267,
     GE = 268,
     LE = 269,
     Equal = 270,
     Unequal = 271,
     And = 272,
     Or = 273,
     UMINUS = 274,
     LOWER_THAN_ELSE = 275
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 24 "yacc.y"

	int numI; /* 变量值 */
	float numF;
	int index; /* 变量数组索引 */
	Node *node; /* 结点地址 */



/* Line 214 of yacc.c  */
#line 162 "yacc.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 187 "yacc.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   294

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNRULES -- Number of states.  */
#define YYNSTATES  120

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   275

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,     2,     2,     2,     2,     2,
      28,    29,    24,    22,    34,    23,    32,    25,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      21,    19,    20,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,     2,    31,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    27,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    13,    16,    20,    24,
      26,    30,    32,    34,    36,    38,    44,    47,    48,    50,
      52,    54,    59,    64,    68,    72,    74,    77,    82,    83,
      86,    89,    91,    95,   101,   109,   115,   116,   119,   123,
     125,   129,   131,   135,   139,   143,   147,   151,   155,   159,
     163,   167,   171,   174,   177,   182,   186,   191,   195,   197,
     199,   201,   203,   205,   207,   209,   211,   213,   217
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      39,     0,    -1,    40,    -1,    -1,    41,    40,    -1,    43,
      42,    35,    -1,    43,    35,    -1,    43,    49,    35,    -1,
      43,    49,    52,    -1,    48,    -1,    48,    34,    42,    -1,
      44,    -1,    45,    -1,     6,    -1,     7,    -1,     8,    46,
      36,    55,    37,    -1,     8,    47,    -1,    -1,     5,    -1,
       5,    -1,     5,    -1,    48,    30,     3,    31,    -1,     5,
      28,    50,    29,    -1,     5,    28,    29,    -1,    51,    34,
      50,    -1,    51,    -1,    43,    48,    -1,    36,    55,    53,
      37,    -1,    -1,    54,    53,    -1,    59,    35,    -1,    52,
      -1,     9,    59,    35,    -1,    10,    28,    59,    29,    54,
      -1,    10,    28,    59,    29,    54,    11,    54,    -1,    12,
      28,    59,    29,    54,    -1,    -1,    56,    55,    -1,    43,
      57,    35,    -1,    58,    -1,    58,    34,    57,    -1,    48,
      -1,    48,    19,    59,    -1,    59,    19,    59,    -1,    59,
      17,    59,    -1,    59,    18,    59,    -1,    59,    60,    59,
      -1,    59,    22,    59,    -1,    59,    23,    59,    -1,    59,
      24,    59,    -1,    59,    25,    59,    -1,    28,    59,    29,
      -1,    23,    59,    -1,    26,    59,    -1,     5,    28,    61,
      29,    -1,     5,    28,    29,    -1,    59,    30,    59,    31,
      -1,    59,    32,     5,    -1,     5,    -1,     3,    -1,     4,
      -1,    15,    -1,    16,    -1,    21,    -1,    14,    -1,    20,
      -1,    13,    -1,    59,    34,    61,    -1,    59,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    56,    56,    59,    60,    63,    68,    69,    78,   103,
     112,   123,   124,   127,   128,   131,   141,   151,   152,   155,
     158,   166,   176,   182,   189,   190,   193,   207,   210,   211,
     214,   215,   216,   217,   218,   219,   222,   223,   226,   233,
     234,   241,   251,   262,   276,   277,   278,   279,   287,   295,
     303,   311,   312,   313,   314,   329,   344,   357,   368,   381,
     388,   397,   398,   399,   400,   401,   402,   405,   410
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_NUM", "FLOAT_NUM", "ID", "INT",
  "FLOAT", "STRUCT", "RETURN", "IF", "ELSE", "WHILE", "GE", "LE", "Equal",
  "Unequal", "And", "Or", "'='", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'",
  "'!'", "UMINUS", "'('", "')'", "'['", "']'", "'.'", "LOWER_THAN_ELSE",
  "','", "';'", "'{'", "'}'", "$accept", "Program", "ExtDefList", "ExtDef",
  "ExtDecList", "Specifier", "TYPE", "StructSpecifier", "OptTag", "Tag",
  "VarDec", "FunDec", "VarList", "ParamDec", "CompSt", "StmtList", "Stmt",
  "DefList", "Def", "DecList", "Dec", "Exp", "Relop", "Args", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,    61,
      62,    60,    43,    45,    42,    47,    33,   274,    40,    41,
      91,    93,    46,   275,    44,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    41,    41,    42,
      42,    43,    43,    44,    44,    45,    45,    46,    46,    47,
      48,    48,    49,    49,    50,    50,    51,    52,    53,    53,
      54,    54,    54,    54,    54,    54,    55,    55,    56,    57,
      57,    58,    58,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    60,    60,    60,    60,    60,    60,    61,    61
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     2,     3,     3,     1,
       3,     1,     1,     1,     1,     5,     2,     0,     1,     1,
       1,     4,     4,     3,     3,     1,     2,     4,     0,     2,
       2,     1,     3,     5,     7,     5,     0,     2,     3,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     4,     3,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    13,    14,    17,     0,     2,     3,     0,    11,    12,
      19,     0,    16,     1,     4,    20,     6,     0,     9,     0,
      36,     0,     5,     0,     0,     7,    36,     8,     0,     0,
      36,    23,     0,     0,    25,     0,    20,    10,    28,    41,
       0,    39,    15,    37,    26,    22,     0,    21,    59,    60,
      58,     0,     0,     0,     0,     0,     0,    31,     0,    28,
       0,     0,    38,     0,    24,     0,     0,     0,     0,    52,
      53,     0,    27,    29,    66,    64,    61,    62,     0,     0,
       0,    65,    63,     0,     0,     0,     0,     0,     0,    30,
       0,    42,    40,    55,    68,     0,    32,     0,     0,    51,
      44,    45,    43,    47,    48,    49,    50,     0,    57,    46,
       0,    54,     0,     0,    56,    67,    33,    35,     0,    34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    17,    28,     8,     9,    11,    12,
      18,    19,    33,    34,    57,    58,    59,    29,    30,    40,
      41,    60,    90,    95
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -89
static const yytype_int16 yypact[] =
{
      77,   -89,   -89,    16,    26,   -89,    77,     3,   -89,   -89,
      -5,     4,   -89,   -89,   -89,    28,   -89,    22,   -21,    10,
      77,    12,   -89,    55,    56,   -89,    77,   -89,    56,    23,
      77,   -89,    56,    34,    30,    35,   -89,   -89,    39,    -7,
      36,    38,   -89,   -89,    44,   -89,    77,   -89,   -89,   -89,
      49,    65,    52,    58,    65,    65,    65,   -89,    53,    39,
      81,    65,   -89,    56,   -89,    50,   104,    65,    65,    20,
      20,   149,   -89,   -89,   -89,   -89,   -89,   -89,    65,    65,
      65,   -89,   -89,    65,    65,    65,    65,    65,    87,   -89,
      65,   229,   -89,   -89,   127,    78,   -89,   169,   189,   -89,
     262,   249,   229,    57,    57,    20,    20,   209,   -89,   229,
      65,   -89,    39,    39,   -89,   -89,    97,   -89,    39,   -89
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -89,   -89,   103,   -89,    86,     1,   -89,   -89,   -89,   -89,
     -26,   -89,    66,   -89,    95,    71,   -88,   -15,   -89,    68,
     -89,   -51,   -89,     5
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -19
static const yytype_int8 yytable[] =
{
      66,     7,    39,    69,    70,    71,    44,     7,    15,    23,
      91,    38,    61,    24,    94,    43,    97,    98,     1,     2,
       3,    10,    32,    23,   116,   117,    13,   100,   101,   102,
     119,   -18,   103,   104,   105,   106,   107,    39,    16,   109,
      20,    31,    48,    49,    50,    25,    26,    32,    51,    52,
      87,    53,    88,    48,    49,    50,    21,    22,    35,    94,
      42,    36,    54,    45,    46,    55,    47,    56,    48,    49,
      50,    62,    63,    54,    23,    26,    55,    65,    56,    93,
      67,    85,    86,     1,     2,     3,    68,    87,    54,    88,
      72,    55,   108,    56,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,   111,   118,    14,
      37,    87,    64,    88,    27,   115,    89,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      73,    92,     0,     0,    87,     0,    88,     0,     0,    96,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,     0,     0,     0,     0,    87,     0,    88,
       0,   110,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,     0,     0,     0,    99,    87,
       0,    88,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,     0,     0,     0,   112,    87,
       0,    88,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,     0,     0,     0,   113,    87,
       0,    88,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,     0,     0,     0,     0,    87,
     114,    88,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,     0,     0,     0,     0,    87,
       0,    88,    74,    75,    76,    77,    78,     0,     0,    81,
      82,    83,    84,    85,    86,    74,    75,    76,    77,    87,
       0,    88,    81,    82,    83,    84,    85,    86,     0,     0,
       0,     0,    87,     0,    88
};

static const yytype_int8 yycheck[] =
{
      51,     0,    28,    54,    55,    56,    32,     6,     5,    30,
      61,    26,    19,    34,    65,    30,    67,    68,     6,     7,
       8,     5,    21,    30,   112,   113,     0,    78,    79,    80,
     118,    36,    83,    84,    85,    86,    87,    63,    35,    90,
      36,    29,     3,     4,     5,    35,    36,    46,     9,    10,
      30,    12,    32,     3,     4,     5,    28,    35,     3,   110,
      37,     5,    23,    29,    34,    26,    31,    28,     3,     4,
       5,    35,    34,    23,    30,    36,    26,    28,    28,    29,
      28,    24,    25,     6,     7,     8,    28,    30,    23,    32,
      37,    26,     5,    28,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    29,    11,     6,
      24,    30,    46,    32,    19,   110,    35,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      59,    63,    -1,    -1,    30,    -1,    32,    -1,    -1,    35,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    30,    -1,    32,
      -1,    34,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    29,    30,
      -1,    32,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    29,    30,
      -1,    32,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    29,    30,
      -1,    32,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    30,
      31,    32,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    30,
      -1,    32,    13,    14,    15,    16,    17,    -1,    -1,    20,
      21,    22,    23,    24,    25,    13,    14,    15,    16,    30,
      -1,    32,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    30,    -1,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,    39,    40,    41,    43,    44,    45,
       5,    46,    47,     0,    40,     5,    35,    42,    48,    49,
      36,    28,    35,    30,    34,    35,    36,    52,    43,    55,
      56,    29,    43,    50,    51,     3,     5,    42,    55,    48,
      57,    58,    37,    55,    48,    29,    34,    31,     3,     4,
       5,     9,    10,    12,    23,    26,    28,    52,    53,    54,
      59,    19,    35,    34,    50,    28,    59,    28,    28,    59,
      59,    59,    37,    53,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    30,    32,    35,
      60,    59,    57,    29,    59,    61,    35,    59,    59,    29,
      59,    59,    59,    59,    59,    59,    59,    59,     5,    59,
      34,    29,    29,    29,    31,    61,    54,    54,    11,    54
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 56 "yacc.y"
    {(yyval.node) = set_vn("Program", 1, (yyvsp[(1) - (1)].node));;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 59 "yacc.y"
    {(yyval.node) = NULL;;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 60 "yacc.y"
    {(yyval.node) = set_vn("ExtDefList", 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 64 "yacc.y"
    {
			(yyval.node) = set_vn("ExtDef", 3, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), set_terminal((yyvsp[(3) - (3)].index)));
			addType((yyvsp[(1) - (3)].node)->type);
		;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 68 "yacc.y"
    {(yyval.node) = set_vn("ExtDef", 2, (yyvsp[(1) - (2)].node), set_terminal((yyvsp[(2) - (2)].index)));;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 70 "yacc.y"
    {
			(yyval.node) = set_vn("ExtDef", 3, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), set_terminal((yyvsp[(3) - (3)].index)));
			Func *pFunc = funcFind((yyvsp[(2) - (3)].node)->index);
			if(pFunc && pFunc->tag == 1)  //申明不一致
				printf("Semantic Error at Line %d: Inconsistent declaration of function \"%s\".\n", yylineno, G_Var[pFunc->nameIndex].mark);   
			else
				funcDeclare((yyvsp[(1) - (3)].node)->type, (yyvsp[(2) - (3)].node)->index, yylineno);
		;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 79 "yacc.y"
    {
			(yyval.node) = set_vn("ExtDef", 3, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node));
			addLevel((yyvsp[(2) - (3)].node)->index);
			Func* pFunc = funcFind((yyvsp[(2) - (3)].node)->index);
			if(pFunc){
				if(pFunc->tag == 1){
					if(pFunc->pnum != pNum || pFunc->type != rtype)  //申明与定义不一致
						printf("Semantic Error at Line %d: Inconsistent definition with declaration of function \"%s\".\n", yylineno, G_Var[pFunc->nameIndex].mark);
					else{
						pFunc->tag = 2;
						if(pFunc->type!=0 && rtype!=0 && rtype != pFunc->type)   //实际返回类型和函数定义的返回类型比较
                			printf("Semantic Error at Line %d: Type mismatched for return.\n", yylineno);
					}
				}
				else{
					printf("Semantic Error at Line %d: Redefined Function \"%s\".\n", yylineno, G_Var[(yyvsp[(2) - (3)].node)->index].mark);
				}
			}
			else		
				funcDefine((yyvsp[(1) - (3)].node)->type, (yyvsp[(2) - (3)].node)->index, yylineno);
			rtype = 0;
		;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 104 "yacc.y"
    {
		(yyval.node) = set_vn("ExtDecList", 1, (yyvsp[(1) - (1)].node)); 
		(yyval.node)->index = (yyvsp[(1) - (1)].node)->index;
		if(varFind((yyvsp[(1) - (1)].node)->index) != NULL && sameLevel((yyvsp[(1) - (1)].node)->index))
			printf("Semantic Error at Line %d: Redefined Variable \"%s\".\n", yylineno, G_Var[(yyvsp[(1) - (1)].node)->index].mark);
		else
			varTable((yyvsp[(1) - (1)].node)->index, (yyvsp[(1) - (1)].node)->size);
	;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 113 "yacc.y"
    {
		(yyval.node) = set_vn("ExtDecList", 3, (yyvsp[(1) - (3)].node), set_terminal((yyvsp[(2) - (3)].index)), (yyvsp[(3) - (3)].node)); 
		(yyval.node)->index = (yyvsp[(1) - (3)].node)->index;
		if(varFind((yyvsp[(1) - (3)].node)->index) != NULL && sameLevel((yyvsp[(1) - (3)].node)->index))
			printf("Semantic Error at Line %d: Redefined Variable \"%s\".\n", yylineno, G_Var[(yyvsp[(1) - (3)].node)->index].mark);
        else
        	varTable((yyvsp[(1) - (3)].node)->index, (yyvsp[(1) - (3)].node)->size);
	;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 123 "yacc.y"
    {(yyval.node) = set_vn("Specifier", 1, (yyvsp[(1) - (1)].node)); (yyval.node)->type = (yyvsp[(1) - (1)].node)->type;;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 124 "yacc.y"
    {(yyval.node) = set_vn("Specifier", 1, (yyvsp[(1) - (1)].node)); (yyval.node)->type = (yyvsp[(1) - (1)].node)->type;;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 127 "yacc.y"
    {(yyval.node) = set_vn("TYPE", 1, set_terminal((yyvsp[(1) - (1)].index))); (yyval.node)->type = TYPE_NUM;;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 128 "yacc.y"
    {(yyval.node) = set_vn("TYPE", 1, set_terminal((yyvsp[(1) - (1)].index))); (yyval.node)->type = TYPE_FLOAT;;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 132 "yacc.y"
    {
					(yyval.node) = set_vn("StructSpecifier", 5, set_terminal((yyvsp[(1) - (5)].index)), (yyvsp[(2) - (5)].node), set_terminal((yyvsp[(3) - (5)].index)), (yyvsp[(4) - (5)].node), set_terminal((yyvsp[(5) - (5)].index)));
					(yyval.node)->type = (yyvsp[(2) - (5)].node)->index;
					addLevel((yyvsp[(1) - (5)].index));
					if((yyvsp[(2) - (5)].node)!=NULL && strucFind((yyvsp[(2) - (5)].node)->index))
						printf("Semantic Error at Line %d: Duplicated name \"%s\".\n", yylineno, G_Var[(yyvsp[(2) - (5)].node)->index].mark);
					else if((yyvsp[(2) - (5)].node) != NULL)
						strucTable(1, (yyvsp[(2) - (5)].node));
				;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 142 "yacc.y"
    {
			(yyval.node) = set_vn("StructSpecifier", 2, set_terminal((yyvsp[(1) - (2)].index)), (yyvsp[(2) - (2)].node));
			(yyval.node)->type = (yyvsp[(2) - (2)].node)->index;
			if(!strucFind((yyvsp[(2) - (2)].node)->index))
				printf("Semantic Error at Line %d: undefined structure \"%s\".\n", yylineno, G_Var[(yyvsp[(2) - (2)].node)->index].mark);
			(yyval.node)->type = (yyvsp[(2) - (2)].node)->index;
		;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 151 "yacc.y"
    {(yyval.node) = NULL;;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 152 "yacc.y"
    {(yyval.node) = set_vn("OptTag", 1, set_var((yyvsp[(1) - (1)].index))); (yyval.node)->index = (yyvsp[(1) - (1)].index);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 155 "yacc.y"
    {(yyval.node) = set_vn("Tag", 1, set_var((yyvsp[(1) - (1)].index))); (yyval.node)->index = (yyvsp[(1) - (1)].index); (yyval.node)->kind = TYPE_STRUCT;;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 159 "yacc.y"
    {
		(yyval.node) = set_vn("VarDec", 1, set_var((yyvsp[(1) - (1)].index)));
		(yyval.node)->index = (yyvsp[(1) - (1)].index);
		(yyval.node)->size = 0;
		memNum += 1;
		listNum += 1;
	;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 167 "yacc.y"
    {
		(yyval.node) = set_vn("VarDec", 4, (yyvsp[(1) - (4)].node), set_terminal((yyvsp[(2) - (4)].index)), set_int((yyvsp[(3) - (4)].numI)), set_terminal((yyvsp[(4) - (4)].index)));
		(yyval.node)->index = (yyvsp[(1) - (4)].node)->index;
		(yyval.node)->size = (yyvsp[(3) - (4)].numI);
		memNum += 1;
		listNum += 1;
	;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 177 "yacc.y"
    {
		(yyval.node) = set_vn("FunDec", 4, set_var((yyvsp[(1) - (4)].index)), set_terminal((yyvsp[(2) - (4)].index)), (yyvsp[(3) - (4)].node), set_terminal((yyvsp[(4) - (4)].index)));
		(yyval.node)->index = (yyvsp[(1) - (4)].index);
		addLevel((yyvsp[(1) - (4)].index));
	;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 183 "yacc.y"
    {
		(yyval.node) = set_vn("FunDec", 3, set_var((yyvsp[(1) - (3)].index)), set_terminal((yyvsp[(2) - (3)].index)), set_terminal((yyvsp[(3) - (3)].index)));
		(yyval.node)->index = (yyvsp[(1) - (3)].index);
	;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 189 "yacc.y"
    {(yyval.node) = set_vn("VarList", 3, (yyvsp[(1) - (3)].node), set_terminal((yyvsp[(2) - (3)].index)), (yyvsp[(3) - (3)].node));;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 190 "yacc.y"
    {(yyval.node) = set_vn("VarList", 1, (yyvsp[(1) - (1)].node));;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 194 "yacc.y"
    {
		(yyval.node) = set_vn("ParamDec", 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
		if(varFind((yyvsp[(2) - (2)].node)->index) != NULL && sameLevel((yyvsp[(2) - (2)].node)->index)){
			printf("Semantic Error at Line %d: Redefined Variable \"%s\".\n", yylineno, G_Var[(yyvsp[(2) - (2)].node)->index].mark);
		}
        else{
        	varTable((yyvsp[(2) - (2)].node)->index, (yyvsp[(2) - (2)].node)->size);
        	addType((yyvsp[(1) - (2)].node)->type);
        }
		pNum += 1;
	;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 207 "yacc.y"
    {(yyval.node) = set_vn("CompSt", 4, set_terminal((yyvsp[(1) - (4)].index)), (yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node), set_terminal((yyvsp[(4) - (4)].index))); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 210 "yacc.y"
    {(yyval.node) = NULL;;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 211 "yacc.y"
    {(yyval.node) = set_vn("StmtList", 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); (yyval.node)->type = (yyvsp[(1) - (2)].node)->type; ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 214 "yacc.y"
    {(yyval.node) = set_vn("Stmt", 2, (yyvsp[(1) - (2)].node), set_terminal((yyvsp[(2) - (2)].index)));;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 215 "yacc.y"
    {(yyval.node) = set_vn("Stmt", 1, (yyvsp[(1) - (1)].node));;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 216 "yacc.y"
    {(yyval.node) = set_vn("Stmt", 3, set_terminal((yyvsp[(1) - (3)].index)), (yyvsp[(2) - (3)].node), set_terminal((yyvsp[(3) - (3)].index))); rtype = (yyvsp[(2) - (3)].node)->type; ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 217 "yacc.y"
    {(yyval.node) = set_vn("Stmt", 5, set_terminal((yyvsp[(1) - (5)].index)), set_terminal((yyvsp[(2) - (5)].index)), (yyvsp[(3) - (5)].node), set_terminal((yyvsp[(4) - (5)].index)), (yyvsp[(5) - (5)].node));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 218 "yacc.y"
    {(yyval.node) = set_vn("Stmt", 7, set_terminal((yyvsp[(1) - (7)].index)), set_terminal((yyvsp[(2) - (7)].index)), (yyvsp[(3) - (7)].node), set_terminal((yyvsp[(4) - (7)].index)), (yyvsp[(5) - (7)].node), set_terminal((yyvsp[(6) - (7)].index)), (yyvsp[(7) - (7)].node));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 219 "yacc.y"
    {(yyval.node) = set_vn("Stmt", 5, set_terminal((yyvsp[(1) - (5)].index)), set_terminal((yyvsp[(2) - (5)].index)), (yyvsp[(3) - (5)].node), set_terminal((yyvsp[(4) - (5)].index)), (yyvsp[(5) - (5)].node));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 222 "yacc.y"
    {(yyval.node) = NULL;;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 223 "yacc.y"
    {(yyval.node) = set_vn("DefList", 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 227 "yacc.y"
    {
		(yyval.node) = set_vn("Def", 3, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), set_terminal((yyvsp[(3) - (3)].index)));
		addType((yyvsp[(1) - (3)].node)->type);
	;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 233 "yacc.y"
    {(yyval.node) = set_vn("DecList", 1, (yyvsp[(1) - (1)].node)); (yyval.node)->index = (yyvsp[(1) - (1)].node)->index;;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 235 "yacc.y"
    {
		(yyval.node) = set_vn("DefList", 3, (yyvsp[(1) - (3)].node), set_terminal((yyvsp[(2) - (3)].index)), (yyvsp[(3) - (3)].node));
		(yyval.node)->index = (yyvsp[(1) - (3)].node)->index;
	;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 242 "yacc.y"
    {
		(yyval.node) = set_vn("Dec", 1, (yyvsp[(1) - (1)].node));
		(yyval.node)->index = (yyvsp[(1) - (1)].node)->index; 
		if(varFind((yyvsp[(1) - (1)].node)->index) != NULL && sameLevel((yyvsp[(1) - (1)].node)->index))
			printf("Semantic Error at Line %d: Redefined Variable \"%s\".\n", yylineno, G_Var[(yyvsp[(1) - (1)].node)->index].mark);
        else
        	varTable((yyvsp[(1) - (1)].node)->index, (yyvsp[(1) - (1)].node)->size);

	;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 252 "yacc.y"
    {
		(yyval.node) = set_vn("Dec", 3, (yyvsp[(1) - (3)].node), set_terminal((yyvsp[(2) - (3)].index)), (yyvsp[(3) - (3)].node));
		(yyval.node)->index = (yyvsp[(1) - (3)].node)->index;
		if(varFind((yyvsp[(1) - (3)].node)->index) != NULL && sameLevel((yyvsp[(1) - (3)].node)->index))
			printf("Semantic Error at Line %d: Redefined Variable \"%s\".\n", yylineno, G_Var[(yyvsp[(1) - (3)].node)->index].mark);
        else
        	varTable((yyvsp[(1) - (3)].node)->index, (yyvsp[(1) - (3)].node)->size);
	;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 263 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 3, (yyvsp[(1) - (3)].node), set_terminal((yyvsp[(2) - (3)].index)), (yyvsp[(3) - (3)].node));
		(yyval.node)->type = (yyvsp[(1) - (3)].node)->type;
		if((yyvsp[(1) - (3)].node)->type < 0 && (yyvsp[(3) - (3)].node)->type < 0 && ((yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type || (yyvsp[(1) - (3)].node)->size != 0 || (yyvsp[(3) - (3)].node)->size != 0))
			printf("Semantic Error at Line %d: Type mismatched for assignment.\n", yylineno);
		else if((yyvsp[(1) - (3)].node)->type>=0 && (yyvsp[(3) - (3)].node)->type>=0){
			//printf("%d %d %s %s\n\n", $1->type, $2->type, G_Var[$1->type].mark, G_Var[$2->type].mark);
			if(!strucMatch((yyvsp[(1) - (3)].node)->type, (yyvsp[(3) - (3)].node)->type))
				printf("Semantic Error at Line %d: Type mismatched for assignment.\n", yylineno);
		}
		if((yyvsp[(1) - (3)].node)->kind == TYPE_CONST)
			printf("Semantic Error at Line %d: The left-hand side of an assignment must be a variable.\n", yylineno);
	;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 276 "yacc.y"
    { (yyval.node) = set_vn("Exp", 3, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].index), (yyvsp[(3) - (3)].node)); (yyval.node)->type = (yyvsp[(1) - (3)].node)->type; (yyval.node)->size = (yyvsp[(1) - (3)].node)->size;;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 277 "yacc.y"
    { (yyval.node) = set_vn("Exp", 3, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].index), (yyvsp[(3) - (3)].node)); (yyval.node)->type = (yyvsp[(1) - (3)].node)->type; (yyval.node)->size = (yyvsp[(1) - (3)].node)->size;;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 278 "yacc.y"
    {(yyval.node) = set_vn("Exp", 3, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->type = (yyvsp[(1) - (3)].node)->type; (yyval.node)->size = (yyvsp[(1) - (3)].node)->size;;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 280 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 3, (yyvsp[(1) - (3)].node), set_terminal((yyvsp[(2) - (3)].index)), (yyvsp[(3) - (3)].node));
		(yyval.node)->type = (yyvsp[(1) - (3)].node)->type;
		(yyval.node)->size = (yyvsp[(1) - (3)].node)->size;
		if((yyvsp[(1) - (3)].node)->type < 0 && (yyvsp[(3) - (3)].node)->type < 0 && ((yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type || (yyvsp[(1) - (3)].node)->size != 0 || (yyvsp[(3) - (3)].node)->size != 0))
			printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
	;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 288 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 3, (yyvsp[(1) - (3)].node), set_terminal((yyvsp[(2) - (3)].index)), (yyvsp[(3) - (3)].node));
		(yyval.node)->type = (yyvsp[(1) - (3)].node)->type;
		(yyval.node)->size = (yyvsp[(1) - (3)].node)->size;
		if((yyvsp[(1) - (3)].node)->type < 0 && (yyvsp[(3) - (3)].node)->type < 0 && ((yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type || (yyvsp[(1) - (3)].node)->size != 0 || (yyvsp[(3) - (3)].node)->size != 0))
			printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
	;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 296 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 3, (yyvsp[(1) - (3)].node), set_terminal((yyvsp[(2) - (3)].index)), (yyvsp[(3) - (3)].node));
		(yyval.node)->type = (yyvsp[(1) - (3)].node)->type;
		(yyval.node)->size = (yyvsp[(1) - (3)].node)->size;
		if((yyvsp[(1) - (3)].node)->type < 0 && (yyvsp[(3) - (3)].node)->type < 0 && ((yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type || (yyvsp[(1) - (3)].node)->size != 0 || (yyvsp[(3) - (3)].node)->size != 0))
			printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
	;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 304 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 3, (yyvsp[(1) - (3)].node), set_terminal((yyvsp[(2) - (3)].index)), (yyvsp[(3) - (3)].node));
		(yyval.node)->type = (yyvsp[(1) - (3)].node)->type;
		(yyval.node)->size = (yyvsp[(1) - (3)].node)->size;
		if((yyvsp[(1) - (3)].node)->type < 0 && (yyvsp[(3) - (3)].node)->type < 0 && ((yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type || (yyvsp[(1) - (3)].node)->size != 0 || (yyvsp[(3) - (3)].node)->size != 0))
			printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
	;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 311 "yacc.y"
    {(yyval.node) = set_vn("Exp", 3, set_terminal((yyvsp[(1) - (3)].index)), (yyvsp[(2) - (3)].node), set_terminal((yyvsp[(3) - (3)].index))); (yyval.node)->type = (yyvsp[(2) - (3)].node)->type; (yyval.node)->size = 0;;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 312 "yacc.y"
    {(yyval.node) = set_vn("Exp", 2, set_terminal((yyvsp[(1) - (2)].index)), (yyvsp[(2) - (2)].node)); (yyval.node)->type = (yyvsp[(2) - (2)].node)->type; (yyval.node)->size = 0;;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 313 "yacc.y"
    {(yyval.node) = set_vn("Exp", 2, set_terminal((yyvsp[(1) - (2)].index)), (yyvsp[(2) - (2)].node)); (yyval.node)->type = (yyvsp[(2) - (2)].node)->type; (yyval.node)->size = 0;;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 315 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 4, set_var((yyvsp[(1) - (4)].index)), set_terminal((yyvsp[(2) - (4)].index)), (yyvsp[(3) - (4)].node), set_terminal((yyvsp[(4) - (4)].index)));
		(yyval.node)->index = (yyvsp[(1) - (4)].index);
		(yyval.node)->size = 0;
		if(varFind((yyvsp[(1) - (4)].index)) == NULL && funcFind((yyvsp[(1) - (4)].index)) == NULL)
			printf("Semantic Error at Line %d: undefined Function \"%s\".\n", yylineno, G_Var[(yyvsp[(1) - (4)].index)].mark);
		else if(funcFind((yyvsp[(1) - (4)].index)) == NULL && varFind((yyvsp[(1) - (4)].index)) != NULL)
			printf("Semantic Error at Line %d: \"%s\" is not a function.\n", yylineno, G_Var[(yyvsp[(1) - (4)].index)].mark);
		else{
			(yyval.node)->type = funcType((yyvsp[(1) - (4)].index));
			if(paraNum((yyvsp[(1) - (4)].index)) != rpNum)
				printf("Semantic Error at Line %d: arguement number mismatches for the parameter number of function \"%s\" .\n", yylineno, G_Var[(yyvsp[(1) - (4)].index)].mark);
		}
	;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 330 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 3, set_var((yyvsp[(1) - (3)].index)), set_terminal((yyvsp[(2) - (3)].index)), set_terminal((yyvsp[(3) - (3)].index))); 
		(yyval.node)->index = (yyvsp[(1) - (3)].index); 
		(yyval.node)->size = 0;
		if(varFind((yyvsp[(1) - (3)].index)) == NULL && funcFind((yyvsp[(1) - (3)].index)) == NULL)
			printf("Semantic Error at Line %d: undefined Function \"%s\".\n", yylineno, G_Var[(yyvsp[(1) - (3)].index)].mark);
		else if(funcFind((yyvsp[(1) - (3)].index)) == NULL && varFind((yyvsp[(1) - (3)].index)) != NULL)
			printf("Semantic Error at Line %d: \"%s\" is not a function.\n", yylineno, G_Var[(yyvsp[(1) - (3)].index)].mark);
		else{
			(yyval.node)->type = funcType((yyvsp[(1) - (3)].index));
			if(paraNum((yyvsp[(1) - (3)].index)) != 0)
				printf("Semantic Error at Line %d: arguement number mismatches for the parameter number of function \"%s\" .\n", yylineno, G_Var[(yyvsp[(1) - (3)].index)].mark);
		}
	;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 345 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 4, (yyvsp[(1) - (4)].node), set_terminal((yyvsp[(2) - (4)].index)), (yyvsp[(3) - (4)].node), set_terminal((yyvsp[(4) - (4)].index)));
		(yyval.node)->index = (yyvsp[(1) - (4)].node)->index;
		(yyval.node)->type = (yyvsp[(1) - (4)].node)->type;
		(yyval.node)->size = (yyvsp[(1) - (4)].node)->size;
		if(varFind((yyvsp[(1) - (4)].node)->index) != NULL && (varSize((yyvsp[(1) - (4)].node)->index) == 0||funcFind((yyvsp[(1) - (4)].node)->index) != NULL))
	        printf("Semantic Error at Line %d: \"%s\" is not an array.\n", yylineno, G_Var[(yyvsp[(1) - (4)].node)->index].mark);
	    else if(varFind((yyvsp[(1) - (4)].node)->index) == NULL )
	        printf("Semantic Error at Line %d: undefined Array \"%s\".\n", yylineno, G_Var[(yyvsp[(1) - (4)].node)->index].mark);
		if((yyvsp[(3) - (4)].node)->type != TYPE_NUM)
			printf("Semantic Error at Line %d: \"%.1f\" is not a integer.\n", yylineno, (yyvsp[(3) - (4)].node)->numF);	
	;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 358 "yacc.y"
    {
		(yyval.node)->type = (yyvsp[(1) - (3)].node)->type;
		(yyval.node)->size = (yyvsp[(1) - (3)].node)->size;
		if(varFind((yyvsp[(1) - (3)].node)->index) == NULL)
			printf("Semantic Error at Line %d: undefined struct variable \"%s\".\n", yylineno, G_Var[(yyvsp[(1) - (3)].node)->index].mark);
		else if((yyvsp[(1) - (3)].node)->type < 0)
			printf("Semantic Error at Line %d: Illegal use of \".\".\n", yylineno);
		else if(!strucMem(varType((yyvsp[(1) - (3)].node)->type), (yyvsp[(3) - (3)].index)))
			printf("Semantic Error at Line %d: Non-existent filed \"%s\".\n", yylineno, G_Var[(yyvsp[(3) - (3)].index)].mark);
	;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 369 "yacc.y"
    {
		(yyval.node) = set_vn("Factor", 1, set_var((yyvsp[(1) - (1)].index)));
		if(varFind((yyvsp[(1) - (1)].index)) == NULL){
			printf("Semantic Error at Line %d: Undefined variable \"%s\".\n", yylineno, G_Var[(yyvsp[(1) - (1)].index)].mark);
		}
		else{
			(yyval.node) = set_vn("Factor", 1, set_var((yyvsp[(1) - (1)].index)));
			(yyval.node)->type = varType((yyvsp[(1) - (1)].index));
			(yyval.node)->kind = TYPE_VAR;
			(yyval.node)->index = (yyvsp[(1) - (1)].index);
		}
	;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 382 "yacc.y"
    {
		(yyval.node) = set_vn("Factor", 1, set_int((yyvsp[(1) - (1)].numI)));
		(yyval.node)->kind = TYPE_CONST;
		(yyval.node)->type = TYPE_NUM;
		(yyval.node)->numI = (yyvsp[(1) - (1)].numI);
	;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 389 "yacc.y"
    {
		(yyval.node) = set_vn("Factor", 1, set_float((yyvsp[(1) - (1)].numF)));
		(yyval.node)->kind = TYPE_CONST;
		(yyval.node)->type = TYPE_FLOAT;
		(yyval.node)->numF = (yyvsp[(1) - (1)].numF);
	;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 397 "yacc.y"
    {(yyval.node) = set_terminal((yyvsp[(1) - (1)].index));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 398 "yacc.y"
    {(yyval.node) = set_terminal((yyvsp[(1) - (1)].index));;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 399 "yacc.y"
    {(yyval.node) = set_terminal((yyvsp[(1) - (1)].index));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 400 "yacc.y"
    {(yyval.node) = set_terminal((yyvsp[(1) - (1)].index));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 401 "yacc.y"
    {(yyval.node) = set_terminal((yyvsp[(1) - (1)].index));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 402 "yacc.y"
    {(yyval.node) = set_terminal((yyvsp[(1) - (1)].index));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 406 "yacc.y"
    {
		(yyval.node) = set_vn("Args", 3, (yyvsp[(1) - (3)].node), set_terminal((yyvsp[(2) - (3)].index)), (yyvsp[(3) - (3)].node)); 
		rpNum += 1;
	;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 411 "yacc.y"
    {	
		(yyval.node) = set_vn("Args", 1, (yyvsp[(1) - (1)].node));
		rpNum += 1;
	;}
    break;



/* Line 1455 of yacc.c  */
#line 2239 "yacc.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 416 "yacc.y"
 

void yyerror(char* s){
    fprintf(stderr, "line %d: %s before \"%s\"\n", yylineno, s, yytext);
    return ;     
}

int main(){      
	extern FILE* yyin;
	char source[40], target[40];

	strcpy(source, "./test.c");
	strcpy(target, "./test.out");

	if((yyin = fopen(source, "r")) == NULL)
	{
		printf("Cannot open the source file!\n");
		return 0;
	}
	target_file = fopen(target, "w");

	varHead = (Var *)malloc(sizeof(Var));         //变量符号表头指针
	varHead->next = NULL;
    varTail = varHead;//变量符号表尾指针

    funcHead = (Func *)malloc(sizeof(Func));      //函数符号表头指针
    funcHead->next = NULL;         //函数符号表尾指针
    funcTail = funcHead;

    strucHead = (Struc *)malloc(sizeof(Struc));//结构体符号表头指针
    strucHead->next = NULL;
    strucTail = strucHead;             //结构体符号表尾指针

	printf("starting!\n");
	// yydebug = 1;
	yyparse(); 
	Func* pFun = funcHead->next;
    while(pFun != NULL){
        if(pFun->tag == 1)
           printf("Semantic Error at Line %d: Undefined function \"%s\".\n", pFun->line, G_Var[pFun->nameIndex].mark);
        pFun = pFun->next;
    }
	printf("ending!\n");
	fclose(yyin);
	fclose(target_file);
	return 0; 
}  
 
