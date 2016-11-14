
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
 
  	#include "ast.h"
  	#include "semantic.h"
  	#include "medCode.h"
  	#include "translate.h"
  	
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

  	void yyerror(char* s);
  	Node *treeHead;


/* Line 189 of yacc.c  */
#line 96 "yacc.tab.c"

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
     RELOP = 274,
     UMINUS = 275,
     LOWER_THAN_ELSE = 276
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 23 "yacc.y"

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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   506

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNRULES -- Number of states.  */
#define YYNSTATES  174

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   276

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,     2,     2,     2,     2,     2,
      29,    30,    25,    23,    35,    24,    33,    26,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
      22,    19,    21,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,     2,    32,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      15,    16,    17,    18,    20,    28,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     8,    11,    15,    18,    22,
      26,    30,    33,    35,    39,    41,    43,    45,    47,    53,
      56,    57,    59,    61,    63,    68,    73,    78,    83,    87,
      91,    95,    97,   101,   104,   109,   112,   113,   116,   119,
     122,   124,   128,   132,   138,   144,   149,   157,   165,   173,
     180,   186,   192,   197,   198,   201,   205,   209,   211,   215,
     219,   221,   225,   229,   233,   237,   241,   245,   249,   253,
     257,   261,   265,   268,   271,   274,   279,   283,   287,   292,
     296,   300,   302,   304,   306,   308,   310,   312,   314,   316,
     318,   322,   326
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      40,     0,    -1,    41,    -1,    42,    -1,    -1,    43,    42,
      -1,    45,    44,    36,    -1,    45,    36,    -1,    45,    51,
      36,    -1,    45,    51,    54,    -1,    45,     1,    36,    -1,
       1,    36,    -1,    50,    -1,    50,    35,    44,    -1,    46,
      -1,    47,    -1,     6,    -1,     7,    -1,     8,    48,    37,
      57,    38,    -1,     8,    49,    -1,    -1,     5,    -1,     5,
      -1,     5,    -1,    50,    31,     3,    32,    -1,    50,    31,
       1,    32,    -1,     5,    29,    52,    30,    -1,     5,    29,
       1,    30,    -1,     5,    29,    30,    -1,     5,     1,    30,
      -1,    53,    35,    52,    -1,    53,    -1,     1,    35,    52,
      -1,    45,    50,    -1,    37,    57,    55,    38,    -1,     1,
      38,    -1,    -1,    56,    55,    -1,    61,    36,    -1,     1,
      36,    -1,    54,    -1,     9,    61,    36,    -1,     9,     1,
      36,    -1,    10,    29,    61,    30,    56,    -1,    10,    29,
       1,    30,    56,    -1,    10,     1,    30,    56,    -1,    10,
      29,    61,    30,    56,    11,    56,    -1,    10,    29,    61,
      30,     1,    11,    56,    -1,    10,    29,     1,    30,    56,
      11,    56,    -1,    10,     1,    30,    56,    11,    56,    -1,
      12,    29,    61,    30,    56,    -1,    12,    29,     1,    30,
      56,    -1,    12,     1,    30,    56,    -1,    -1,    58,    57,
      -1,    45,    59,    36,    -1,    45,     1,    36,    -1,    60,
      -1,    60,    35,    59,    -1,     1,    35,    59,    -1,    50,
      -1,    50,    19,    61,    -1,     1,    19,    61,    -1,    61,
      19,    61,    -1,    61,    17,    61,    -1,    61,    18,    61,
      -1,    61,    62,    61,    -1,    61,    23,    61,    -1,    61,
      24,    61,    -1,    61,    25,    61,    -1,    61,    26,    61,
      -1,    29,    61,    30,    -1,     1,    30,    -1,    24,    61,
      -1,    27,    61,    -1,     5,    29,    63,    30,    -1,     5,
      29,    30,    -1,     5,     1,    30,    -1,    61,    31,    61,
      32,    -1,    61,    31,     1,    -1,    61,    33,     5,    -1,
       5,    -1,     3,    -1,     4,    -1,    15,    -1,    16,    -1,
      22,    -1,    14,    -1,    21,    -1,    13,    -1,    61,    35,
      63,    -1,     1,    35,    63,    -1,    61,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    53,    53,    56,    59,    60,    63,    68,    69,    80,
     108,   115,   123,   134,   147,   148,   151,   152,   155,   168,
     180,   181,   184,   187,   195,   204,   217,   224,   233,   239,
     249,   250,   251,   259,   274,   275,   283,   284,   287,   288,
     294,   295,   296,   302,   303,   309,   315,   316,   322,   328,
     334,   335,   341,   348,   349,   352,   357,   366,   367,   372,
     380,   392,   403,   412,   444,   454,   464,   465,   485,   505,
     525,   545,   551,   558,   568,   578,   604,   628,   636,   655,
     664,   682,   696,   703,   712,   713,   714,   715,   716,   717,
     720,   725,   732
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_NUM", "FLOAT_NUM", "ID", "INT",
  "FLOAT", "STRUCT", "RETURN", "IF", "ELSE", "WHILE", "GE", "LE", "Equal",
  "Unequal", "And", "Or", "'='", "RELOP", "'>'", "'<'", "'+'", "'-'",
  "'*'", "'/'", "'!'", "UMINUS", "'('", "')'", "'['", "']'", "'.'",
  "LOWER_THAN_ELSE", "','", "';'", "'{'", "'}'", "$accept", "Program0",
  "Program", "ExtDefList", "ExtDef", "ExtDecList", "Specifier", "TYPE",
  "StructSpecifier", "OptTag", "Tag", "VarDec", "FunDec", "VarList",
  "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def", "DecList",
  "Dec", "Exp", "Relop", "Args", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,    61,
     274,    62,    60,    43,    45,    42,    47,    33,   275,    40,
      41,    91,    93,    46,   276,    44,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    42,    42,    43,    43,    43,    43,
      43,    43,    44,    44,    45,    45,    46,    46,    47,    47,
      48,    48,    49,    50,    50,    50,    51,    51,    51,    51,
      52,    52,    52,    53,    54,    54,    55,    55,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    57,    57,    58,    58,    59,    59,    59,
      60,    60,    60,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    62,    62,    62,    62,    62,    62,
      63,    63,    63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     2,     3,     2,     3,     3,
       3,     2,     1,     3,     1,     1,     1,     1,     5,     2,
       0,     1,     1,     1,     4,     4,     4,     4,     3,     3,
       3,     1,     3,     2,     4,     2,     0,     2,     2,     2,
       1,     3,     3,     5,     5,     4,     7,     7,     7,     6,
       5,     5,     4,     0,     2,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     4,     3,     3,     4,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    16,    17,    20,     0,     2,     3,     0,     0,
      14,    15,    11,    22,     0,    19,     1,     5,     0,     0,
       7,     0,    12,     0,    53,    10,     0,     0,     6,     0,
       0,     0,     8,    53,     9,     0,     0,    53,    29,     0,
      28,     0,     0,    31,     0,     0,    23,    13,    35,     0,
       0,    60,     0,    57,    18,    54,    27,     0,    33,    26,
       0,    25,    24,     0,    82,    83,     0,     0,     0,     0,
       0,     0,     0,    40,     0,     0,     0,     0,     0,    56,
       0,    55,     0,     0,    32,    30,    72,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,    74,     0,
      34,    37,    89,    87,    84,    85,     0,     0,     0,    88,
      86,     0,     0,     0,     0,     0,     0,    38,     0,    62,
       0,    59,    61,    58,    77,     0,    76,    92,     0,    42,
      41,     0,     0,     0,     0,     0,     0,    71,    64,    65,
      63,    67,    68,    69,    70,    79,     0,    80,    66,     0,
       0,    75,    45,     0,     0,    52,     0,     0,    78,    91,
      90,     0,    44,     0,    43,    51,    50,    49,     0,     0,
       0,    48,    47,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    21,    35,    10,    11,    14,
      15,    51,    23,    42,    43,    73,    74,    75,    36,    37,
      52,    53,    76,   118,   128
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -101
static const yytype_int16 yypact[] =
{
     498,   -11,  -101,  -101,    27,    42,  -101,  -101,   498,     7,
    -101,  -101,  -101,    13,    51,  -101,  -101,  -101,    80,    29,
    -101,    97,    40,     0,   160,  -101,    81,    66,  -101,    90,
     144,   113,  -101,   160,  -101,    76,   116,   160,  -101,   -19,
    -101,   144,   139,   137,   142,   143,  -101,  -101,  -101,    75,
     -17,   -10,   135,   145,  -101,  -101,  -101,   219,   146,  -101,
     219,  -101,  -101,    56,  -101,  -101,   169,   212,    23,    26,
     218,   218,   218,  -101,   140,    75,   280,   218,   100,  -101,
     218,  -101,   100,   161,  -101,  -101,  -101,  -101,   167,   205,
      -1,   304,   173,   245,   177,   251,   181,    67,    67,   351,
    -101,  -101,  -101,  -101,  -101,  -101,   218,   218,   218,  -101,
    -101,   218,   218,   218,   218,   257,   207,  -101,   218,   435,
     -12,  -101,   435,  -101,  -101,   -15,  -101,   328,   184,  -101,
    -101,   136,   188,   372,   136,   194,   393,  -101,   470,   456,
     435,    64,    64,    67,    67,   181,   414,  -101,   435,   263,
     263,  -101,   217,   105,   152,  -101,   105,   136,  -101,  -101,
    -101,   136,   220,   114,   222,  -101,  -101,  -101,   136,   136,
     136,  -101,  -101,  -101
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,  -101,   229,  -101,   200,     6,  -101,  -101,  -101,
    -101,     8,  -101,     2,  -101,   215,   165,  -100,    70,  -101,
      65,  -101,   -67,  -101,     9
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -82
static const yytype_int16 yytable[] =
{
      91,    31,    77,    97,    98,    99,     9,    77,    18,    80,
     119,    56,    19,   122,     9,    86,    57,    22,    78,    79,
     149,    29,   127,    78,    92,    12,   133,    94,   136,    86,
      26,   152,    13,    41,   155,   129,    32,    33,    22,   138,
     139,   140,    16,    20,   141,   142,   143,   144,   146,    58,
     -21,   148,    93,   162,   164,    95,   165,   166,    27,    84,
     -23,   167,    85,    41,   -23,   -23,    41,    39,   171,   172,
     173,    29,     2,     3,     4,    30,    63,    50,    64,    65,
      66,    46,   127,   127,    67,    68,    86,    69,    24,   113,
     114,    44,    87,    45,    48,   115,    40,   116,   115,    70,
     116,   120,    71,    49,    72,    46,    63,    55,    64,    65,
      66,    38,    33,   -36,    67,    68,    25,    69,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   169,   -72,   -72,   -72,   -72,
     -72,   -72,    71,    28,    72,   -72,   -72,    63,   -72,    64,
      65,    66,    33,   121,    86,    67,    68,   123,    69,    46,
      87,    48,    48,   163,    54,    64,    65,    66,   159,   160,
      70,    67,    68,    71,    69,    72,     2,     3,     4,    59,
      88,    81,    60,    33,    61,    62,    70,    29,   100,    71,
      82,    72,   -81,   -81,   -81,   -81,   -81,   -81,   -81,    33,
     -81,   -81,   -81,   -81,   -81,   -81,    57,   124,    89,   -81,
     -81,   -81,   -81,   131,   -81,   -81,   125,   134,    64,    65,
      66,    86,   147,    90,   151,    64,    65,    66,   153,    96,
      83,    64,    65,    66,   156,     2,     3,     4,   161,    70,
      47,   168,    71,   170,    72,   126,    70,    17,    34,    71,
     101,    72,    70,     0,     0,    71,   132,    72,    64,    65,
      66,     0,   135,     0,    64,    65,    66,     0,   145,     0,
      64,    65,    66,     0,   125,     0,    64,    65,    66,    70,
       0,     0,    71,     0,    72,    70,     0,     0,    71,     0,
      72,    70,     0,     0,    71,     0,    72,    70,     0,     0,
      71,     0,    72,   102,   103,   104,   105,   106,   107,   108,
       0,   109,   110,   111,   112,   113,   114,     0,     0,     0,
       0,   115,     0,   116,     0,     0,   117,   102,   103,   104,
     105,   106,   107,   108,     0,   109,   110,   111,   112,   113,
     114,     0,     0,     0,     0,   115,     0,   116,     0,     0,
     130,   102,   103,   104,   105,   106,   107,   108,     0,   109,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
       0,   116,     0,   150,   102,   103,   104,   105,   106,   107,
     108,     0,   109,   110,   111,   112,   113,   114,     0,     0,
       0,   137,   115,     0,   116,   102,   103,   104,   105,   106,
     107,   108,     0,   109,   110,   111,   112,   113,   114,     0,
       0,     0,   154,   115,     0,   116,   102,   103,   104,   105,
     106,   107,   108,     0,   109,   110,   111,   112,   113,   114,
       0,     0,     0,   157,   115,     0,   116,   102,   103,   104,
     105,   106,   107,   108,     0,   109,   110,   111,   112,   113,
     114,     0,     0,     0,     0,   115,   158,   116,   102,   103,
     104,   105,   106,   107,   108,     0,   109,   110,   111,   112,
     113,   114,     0,     0,     0,     0,   115,     0,   116,   102,
     103,   104,   105,   106,     0,     0,     0,   109,   110,   111,
     112,   113,   114,   102,   103,   104,   105,   115,     0,   116,
       0,   109,   110,   111,   112,   113,   114,     0,    -4,     1,
       0,   115,     0,   116,     2,     3,     4
};

static const yytype_int16 yycheck[] =
{
      67,     1,    19,    70,    71,    72,     0,    19,     1,    19,
      77,    30,     5,    80,     8,    30,    35,     9,    35,    36,
      35,    31,    89,    35,     1,    36,    93,     1,    95,    30,
       1,   131,     5,    27,   134,    36,    36,    37,    30,   106,
     107,   108,     0,    36,   111,   112,   113,   114,   115,    41,
      37,   118,    29,   153,   154,    29,   156,   157,    29,    57,
      31,   161,    60,    57,    35,    36,    60,     1,   168,   169,
     170,    31,     6,     7,     8,    35,     1,     1,     3,     4,
       5,     5,   149,   150,     9,    10,    30,    12,    37,    25,
      26,     1,    36,     3,    38,    31,    30,    33,    31,    24,
      33,     1,    27,    33,    29,     5,     1,    37,     3,     4,
       5,    30,    37,    38,     9,    10,    36,    12,    13,    14,
      15,    16,    17,    18,    19,    11,    21,    22,    23,    24,
      25,    26,    27,    36,    29,    30,    31,     1,    33,     3,
       4,     5,    37,    78,    30,     9,    10,    82,    12,     5,
      36,    38,    38,     1,    38,     3,     4,     5,   149,   150,
      24,     9,    10,    27,    12,    29,     6,     7,     8,    30,
       1,    36,    35,    37,    32,    32,    24,    31,    38,    27,
      35,    29,    13,    14,    15,    16,    17,    18,    19,    37,
      21,    22,    23,    24,    25,    26,    35,    30,    29,    30,
      31,    32,    33,    30,    35,    36,     1,    30,     3,     4,
       5,    30,     5,     1,    30,     3,     4,     5,    30,     1,
       1,     3,     4,     5,    30,     6,     7,     8,    11,    24,
      30,    11,    27,    11,    29,    30,    24,     8,    23,    27,
      75,    29,    24,    -1,    -1,    27,     1,    29,     3,     4,
       5,    -1,     1,    -1,     3,     4,     5,    -1,     1,    -1,
       3,     4,     5,    -1,     1,    -1,     3,     4,     5,    24,
      -1,    -1,    27,    -1,    29,    24,    -1,    -1,    27,    -1,
      29,    24,    -1,    -1,    27,    -1,    29,    24,    -1,    -1,
      27,    -1,    29,    13,    14,    15,    16,    17,    18,    19,
      -1,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      -1,    31,    -1,    33,    -1,    -1,    36,    13,    14,    15,
      16,    17,    18,    19,    -1,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    -1,    31,    -1,    33,    -1,    -1,
      36,    13,    14,    15,    16,    17,    18,    19,    -1,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    31,
      -1,    33,    -1,    35,    13,    14,    15,    16,    17,    18,
      19,    -1,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    31,    -1,    33,    13,    14,    15,    16,    17,
      18,    19,    -1,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    31,    -1,    33,    13,    14,    15,    16,
      17,    18,    19,    -1,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    31,    -1,    33,    13,    14,    15,
      16,    17,    18,    19,    -1,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    -1,    31,    32,    33,    13,    14,
      15,    16,    17,    18,    19,    -1,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    31,    -1,    33,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    26,    13,    14,    15,    16,    31,    -1,    33,
      -1,    21,    22,    23,    24,    25,    26,    -1,     0,     1,
      -1,    31,    -1,    33,     6,     7,     8
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     6,     7,     8,    40,    41,    42,    43,    45,
      46,    47,    36,     5,    48,    49,     0,    42,     1,     5,
      36,    44,    50,    51,    37,    36,     1,    29,    36,    31,
      35,     1,    36,    37,    54,    45,    57,    58,    30,     1,
      30,    45,    52,    53,     1,     3,     5,    44,    38,    57,
       1,    50,    59,    60,    38,    57,    30,    35,    50,    30,
      35,    32,    32,     1,     3,     4,     5,     9,    10,    12,
      24,    27,    29,    54,    55,    56,    61,    19,    35,    36,
      19,    36,    35,     1,    52,    52,    30,    36,     1,    29,
       1,    61,     1,    29,     1,    29,     1,    61,    61,    61,
      38,    55,    13,    14,    15,    16,    17,    18,    19,    21,
      22,    23,    24,    25,    26,    31,    33,    36,    62,    61,
       1,    59,    61,    59,    30,     1,    30,    61,    63,    36,
      36,    30,     1,    61,    30,     1,    61,    30,    61,    61,
      61,    61,    61,    61,    61,     1,    61,     5,    61,    35,
      35,    30,    56,    30,    30,    56,    30,    30,    32,    63,
      63,    11,    56,     1,    56,    56,    56,    56,    11,    11,
      11,    56,    56,    56
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
#line 53 "yacc.y"
    {NodeExecute(treeFile, (yyvsp[(1) - (1)].node), 0); treeHead = (yyvsp[(1) - (1)].node);;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 56 "yacc.y"
    {(yyval.node) = set_vn("Program", 1, (yyvsp[(1) - (1)].node));;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 59 "yacc.y"
    {(yyval.node) = NULL;;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 60 "yacc.y"
    {(yyval.node) = set_vn("ExtDefList", 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 64 "yacc.y"
    {
			(yyval.node) = set_vn("ExtDef", 3, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), set_terminal((yyvsp[(3) - (3)].index)));
			addType((yyvsp[(1) - (3)].node)->type);
		;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 68 "yacc.y"
    {(yyval.node) = set_vn("ExtDef", 2, (yyvsp[(1) - (2)].node), set_terminal((yyvsp[(2) - (2)].index)));;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 70 "yacc.y"
    {
			(yyval.node) = set_vn("ExtDef", 3, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), set_terminal((yyvsp[(3) - (3)].index)));
			Func *pFunc = funcFind((yyvsp[(2) - (3)].node)->index);
			if(pFunc && pFunc->tag == 1){  //申明不一致
				error = true;
				printf("Semantic Error at Line %d: Inconsistent declaration of function \"%s\".\n", yylineno, G_Var[pFunc->nameIndex].mark);   
			}
			else
				funcDeclare((yyvsp[(1) - (3)].node)->type, (yyvsp[(2) - (3)].node)->index, yylineno);
		;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 81 "yacc.y"
    {
			(yyval.node) = set_vn("ExtDef", 3, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node));
			addLevel((yyvsp[(2) - (3)].node)->index);
			Func* pFunc = funcFind((yyvsp[(2) - (3)].node)->index);
			if(pFunc){
				if(pFunc->tag == 1){
					if(pFunc->pnum != pNum || pFunc->type != rtype){  //申明与定义不一致
						error = true;
						printf("Semantic Error at Line %d: Inconsistent definition with declaration of function \"%s\".\n", yylineno, G_Var[pFunc->nameIndex].mark);
					}
					else{
						pFunc->tag = 2;
						if(pFunc->type!=0 && rtype!=0 && rtype != pFunc->type){  //实际返回类型和函数定义的返回类型比较
							error = true;
                			printf("Semantic Error at Line %d: Type mismatched for return.\n", yylineno);
						}
					}
				}
				else{
					error = true;
					printf("Semantic Error at Line %d: Redefined Function \"%s\".\n", yylineno, G_Var[(yyvsp[(2) - (3)].node)->index].mark);
				}
			}
			else		
				funcDefine((yyvsp[(1) - (3)].node)->type, (yyvsp[(2) - (3)].node)->index, yylineno);
			rtype = 0;
		;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 109 "yacc.y"
    {
		(yyval.node) = set_vn("ExtDef", 3, (yyvsp[(1) - (3)].node), set_terminal(0), set_terminal((yyvsp[(3) - (3)].index)));
		addType((yyvsp[(1) - (3)].node)->type);
		error = true;
		printf("Syntax Error at Line %d: Something wrong with ExtDecList before \";\".\n", (yylsp[(2) - (3)]).last_line);
	;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 116 "yacc.y"
    {
		error = true;
		(yyval.node) = set_vn("ExtDef", 2, set_terminal(0), set_terminal((yyvsp[(2) - (2)].index)));
		printf("Syntax Error at Line %d: Something wrong with Specifier before \";\".\n", (yylsp[(1) - (2)]).last_line);
	;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 124 "yacc.y"
    {
		(yyval.node) = set_vn("ExtDecList", 1, (yyvsp[(1) - (1)].node)); 
		(yyval.node)->index = (yyvsp[(1) - (1)].node)->index;
		if(varFind((yyvsp[(1) - (1)].node)->index) != NULL && sameLevel((yyvsp[(1) - (1)].node)->index)){
			error = true;
			printf("Semantic Error at Line %d: Redefined Variable \"%s\".\n", yylineno, G_Var[(yyvsp[(1) - (1)].node)->index].mark);
		}
		else
			varTable((yyvsp[(1) - (1)].node)->index, deminsion, size);
	;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 135 "yacc.y"
    {
		(yyval.node) = set_vn("ExtDecList", 3, (yyvsp[(1) - (3)].node), set_terminal((yyvsp[(2) - (3)].index)), (yyvsp[(3) - (3)].node)); 
		(yyval.node)->index = (yyvsp[(1) - (3)].node)->index;
		if(varFind((yyvsp[(1) - (3)].node)->index) != NULL && sameLevel((yyvsp[(1) - (3)].node)->index)){
			error = true;
			printf("Semantic Error at Line %d: Redefined Variable \"%s\".\n", yylineno, G_Var[(yyvsp[(1) - (3)].node)->index].mark);
		}
        else
        	varTable((yyvsp[(1) - (3)].node)->index, deminsion, size);
	;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 147 "yacc.y"
    {(yyval.node) = set_vn("Specifier", 1, (yyvsp[(1) - (1)].node)); (yyval.node)->type = (yyvsp[(1) - (1)].node)->type; type = (yyvsp[(1) - (1)].node)->type;;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 148 "yacc.y"
    {(yyval.node) = set_vn("Specifier", 1, (yyvsp[(1) - (1)].node)); (yyval.node)->type = (yyvsp[(1) - (1)].node)->type;;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 151 "yacc.y"
    {(yyval.node) = set_vn("TYPE", 1, set_terminal((yyvsp[(1) - (1)].index))); (yyval.node)->type = TYPE_NUM;;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 152 "yacc.y"
    {(yyval.node) = set_vn("TYPE", 1, set_terminal((yyvsp[(1) - (1)].index))); (yyval.node)->type = TYPE_FLOAT;;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 156 "yacc.y"
    {
					(yyval.node) = set_vn("StructSpecifier", 5, set_terminal((yyvsp[(1) - (5)].index)), (yyvsp[(2) - (5)].node), set_terminal((yyvsp[(3) - (5)].index)), (yyvsp[(4) - (5)].node), set_terminal((yyvsp[(5) - (5)].index)));
					if((yyvsp[(2) - (5)].node) != NULL)
						(yyval.node)->type = (yyvsp[(2) - (5)].node)->index;
					addLevel((yyvsp[(1) - (5)].index));
					if((yyvsp[(2) - (5)].node)!=NULL && strucFind((yyvsp[(2) - (5)].node)->index)){
						error = true;
						printf("Semantic Error at Line %d: Duplicated name \"%s\".\n", yylineno, G_Var[(yyvsp[(2) - (5)].node)->index].mark);
					}
					else if((yyvsp[(2) - (5)].node) != NULL)
						strucTable(1, (yyvsp[(2) - (5)].node));
				;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 169 "yacc.y"
    {
			(yyval.node) = set_vn("StructSpecifier", 2, set_terminal((yyvsp[(1) - (2)].index)), (yyvsp[(2) - (2)].node));
			(yyval.node)->type = (yyvsp[(2) - (2)].node)->index;
			if(!strucFind((yyvsp[(2) - (2)].node)->index)){
				error = true;
				printf("Semantic Error at Line %d: undefined structure \"%s\".\n", yylineno, G_Var[(yyvsp[(2) - (2)].node)->index].mark);
			}
			(yyval.node)->type = (yyvsp[(2) - (2)].node)->index;
		;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 180 "yacc.y"
    {(yyval.node) = NULL;;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 181 "yacc.y"
    {(yyval.node) = set_vn("OptTag", 1, set_var((yyvsp[(1) - (1)].index))); (yyval.node)->index = (yyvsp[(1) - (1)].index);;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 184 "yacc.y"
    {(yyval.node) = set_vn("Tag", 1, set_var((yyvsp[(1) - (1)].index))); (yyval.node)->index = (yyvsp[(1) - (1)].index); (yyval.node)->kind = TYPE_STRUCT;;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 188 "yacc.y"
    {
		(yyval.node) = set_vn("VarDec", 1, set_var((yyvsp[(1) - (1)].index)));
		(yyval.node)->index = (yyvsp[(1) - (1)].index);
		(yyval.node)->deminsion = 0;
		memNum += 1;
		listNum += 1;
	;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 196 "yacc.y"
    {
		(yyval.node) = set_vn("VarDec", 4, (yyvsp[(1) - (4)].node), set_terminal((yyvsp[(2) - (4)].index)), set_int((yyvsp[(3) - (4)].numI)), set_terminal((yyvsp[(4) - (4)].index)));
		(yyval.node)->index = (yyvsp[(1) - (4)].node)->index;
		size[deminsion] = (yyvsp[(3) - (4)].numI);
		memNum += 1;
		listNum += 1;
		deminsion += 1;
	;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 205 "yacc.y"
    {
		(yyval.node) = set_vn("VarDec", 4, (yyvsp[(1) - (4)].node), set_terminal((yyvsp[(2) - (4)].index)), set_terminal(0), set_terminal((yyvsp[(4) - (4)].index)));
		(yyval.node)->index = (yyvsp[(1) - (4)].node)->index;
		(yyval.node)->deminsion = 0;
		memNum += 1;
		listNum += 1;
		deminsion += 1;
		error = true;
		printf("Syntax Error at Line %d: Missing a integer between [].\n", (yylsp[(3) - (4)]).last_line);
	;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 218 "yacc.y"
    {
		(yyval.node) = set_vn("FunDec", 4, set_var((yyvsp[(1) - (4)].index)), set_terminal((yyvsp[(2) - (4)].index)), (yyvsp[(3) - (4)].node), set_terminal((yyvsp[(4) - (4)].index)));
		(yyval.node)->index = (yyvsp[(1) - (4)].index);
		curFunc = (yyvsp[(1) - (4)].index);
		addLevel((yyvsp[(1) - (4)].index));	
	;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 225 "yacc.y"
    {
		(yyval.node) = set_vn("FunDec", 4, set_var((yyvsp[(1) - (4)].index)), set_terminal((yyvsp[(2) - (4)].index)), set_terminal(0), set_terminal((yyvsp[(4) - (4)].index)));
		(yyval.node)->index = (yyvsp[(1) - (4)].index);
		curFunc = (yyvsp[(1) - (4)].index);
		addLevel((yyvsp[(1) - (4)].index));
		error = true;
		printf("Syntax Error at Line %d: Something wrong with VarList between ().\n", (yylsp[(3) - (4)]).last_line);
	;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 234 "yacc.y"
    {
		(yyval.node) = set_vn("FunDec", 3, set_var((yyvsp[(1) - (3)].index)), set_terminal((yyvsp[(2) - (3)].index)), set_terminal((yyvsp[(3) - (3)].index)));
		(yyval.node)->index = (yyvsp[(1) - (3)].index);
		curFunc = (yyvsp[(1) - (3)].index);
	;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 240 "yacc.y"
    {
		(yyval.node) = set_vn("FunDec", 3, set_var((yyvsp[(1) - (3)].index)), set_terminal(0), set_terminal((yyvsp[(3) - (3)].index)));
		(yyval.node)->index = (yyvsp[(1) - (3)].index);
		curFunc = (yyvsp[(1) - (3)].index);
		error = true;
		printf("Syntax Error at Line %d: Missing \"(\".\n", (yylsp[(2) - (3)]).last_line);
	;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 249 "yacc.y"
    {(yyval.node) = set_vn("VarList", 3, (yyvsp[(1) - (3)].node), set_terminal((yyvsp[(2) - (3)].index)), (yyvsp[(3) - (3)].node));;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 250 "yacc.y"
    {(yyval.node) = set_vn("VarList", 1, (yyvsp[(1) - (1)].node));;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 252 "yacc.y"
    {
		(yyval.node) = set_vn("VarList", 3, set_terminal(0), set_terminal((yyvsp[(2) - (3)].index)), (yyvsp[(3) - (3)].node));
		error = true;
		printf("Syntax Error at Line %d: Something wrong with ParamDec.\n", (yylsp[(1) - (3)]).last_line);
	;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 260 "yacc.y"
    {
		(yyval.node) = set_vn("ParamDec", 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
		if(varFind((yyvsp[(2) - (2)].node)->index) != NULL && sameLevel((yyvsp[(2) - (2)].node)->index)){
			error = true;
			printf("Semantic Error at Line %d: Redefined Variable \"%s\".\n", yylineno, G_Var[(yyvsp[(2) - (2)].node)->index].mark);
		}
        else{
        	varTable((yyvsp[(2) - (2)].node)->index, deminsion, size);
        	addType((yyvsp[(1) - (2)].node)->type);
        }
		pNum += 1;
	;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 274 "yacc.y"
    {(yyval.node) = set_vn("CompSt", 4, set_terminal((yyvsp[(1) - (4)].index)), (yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node), set_terminal((yyvsp[(4) - (4)].index)));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 276 "yacc.y"
    {
		(yyval.node) = set_vn("CompSt", 2, set_terminal(0), set_terminal((yyvsp[(2) - (2)].index)));
		error = true;
		printf("Syntax Error at Line %d: Missing \"{\".\n", (yylsp[(1) - (2)]).first_line);
	;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 283 "yacc.y"
    {(yyval.node) = NULL;;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 284 "yacc.y"
    {(yyval.node) = set_vn("StmtList", 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); (yyval.node)->type = (yyvsp[(1) - (2)].node)->type; ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 287 "yacc.y"
    {(yyval.node) = set_vn("Stmt", 2, (yyvsp[(1) - (2)].node), set_terminal((yyvsp[(2) - (2)].index)));;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 289 "yacc.y"
    {
		(yyval.node) = set_vn("Stmt", 2, set_terminal(0), set_terminal((yyvsp[(2) - (2)].index)));
		error = true;
		printf("Syntax Error at Line %d: Something wrong with expression before \";\".\n", (yylsp[(1) - (2)]).last_line);
	;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 294 "yacc.y"
    {(yyval.node) = set_vn("Stmt", 1, (yyvsp[(1) - (1)].node));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 295 "yacc.y"
    {(yyval.node) = set_vn("Stmt", 3, set_terminal((yyvsp[(1) - (3)].index)), (yyvsp[(2) - (3)].node), set_terminal((yyvsp[(3) - (3)].index))); rtype = (yyvsp[(2) - (3)].node)->type; ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 297 "yacc.y"
    {
		(yyval.node) = set_vn("Stmt", 3, set_terminal((yyvsp[(1) - (3)].index)), set_terminal(0), set_terminal((yyvsp[(3) - (3)].index))); 
		error = true;
		printf("Syntax Error at Line %d: Something wrong with expression before \";\".\n", (yylsp[(2) - (3)]).last_line);
	;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 302 "yacc.y"
    {(yyval.node) = set_vn("Stmt", 5, set_terminal((yyvsp[(1) - (5)].index)), set_terminal((yyvsp[(2) - (5)].index)), (yyvsp[(3) - (5)].node), set_terminal((yyvsp[(4) - (5)].index)), (yyvsp[(5) - (5)].node));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 304 "yacc.y"
    {
		(yyval.node) = set_vn("Stmt", 5, set_terminal((yyvsp[(1) - (5)].index)), set_terminal((yyvsp[(2) - (5)].index)), set_terminal(0), set_terminal((yyvsp[(4) - (5)].index)), (yyvsp[(5) - (5)].node));
		error = true;
		printf("Syntax Error at Line %d: Something wrong with expression between ().\n", (yylsp[(3) - (5)]).last_line);
	;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 310 "yacc.y"
    {
		(yyval.node) = set_vn("Stmt", 4, set_terminal((yyvsp[(1) - (4)].index)), set_terminal(0), set_terminal((yyvsp[(3) - (4)].index)), (yyvsp[(4) - (4)].node));
		error = true;
		printf("Syntax Error at Line %d: Missing \"(\".\n", (yylsp[(2) - (4)]).last_line);
	;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 315 "yacc.y"
    {(yyval.node) = set_vn("Stmt", 7, set_terminal((yyvsp[(1) - (7)].index)), set_terminal((yyvsp[(2) - (7)].index)), (yyvsp[(3) - (7)].node), set_terminal((yyvsp[(4) - (7)].index)), (yyvsp[(5) - (7)].node), set_terminal((yyvsp[(6) - (7)].index)), (yyvsp[(7) - (7)].node));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 317 "yacc.y"
    {
		(yyval.node) = set_vn("Stmt", 7, set_terminal((yyvsp[(1) - (7)].index)), set_terminal((yyvsp[(2) - (7)].index)), (yyvsp[(3) - (7)].node), set_terminal((yyvsp[(4) - (7)].index)), set_terminal(0), set_terminal((yyvsp[(6) - (7)].index)), (yyvsp[(7) - (7)].node));
		error = true;
		printf("Syntax Error at Line %d: Missing \";\".\n", (yylsp[(5) - (7)]).last_line);
	;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 323 "yacc.y"
    {
		(yyval.node) = set_vn("Stmt", 7, set_terminal((yyvsp[(1) - (7)].index)), set_terminal((yyvsp[(2) - (7)].index)), set_terminal(0), set_terminal((yyvsp[(4) - (7)].index)), (yyvsp[(5) - (7)].node), set_terminal((yyvsp[(6) - (7)].index)), (yyvsp[(7) - (7)].node));
		error = true;
		printf("Syntax Error at Line %d: Something wrong with expression between ().\n", (yylsp[(3) - (7)]).last_line);
	;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 329 "yacc.y"
    {
		(yyval.node) = set_vn("Stmt", 6, set_terminal((yyvsp[(1) - (6)].index)), set_terminal(0), set_terminal((yyvsp[(3) - (6)].index)), (yyvsp[(4) - (6)].node), set_terminal((yyvsp[(5) - (6)].index)), (yyvsp[(6) - (6)].node));
		error = true;
		printf("Syntax Error at Line %d: missing \"(\".\n", (yylsp[(2) - (6)]).last_line);
	;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 334 "yacc.y"
    {(yyval.node) = set_vn("Stmt", 5, set_terminal((yyvsp[(1) - (5)].index)), set_terminal((yyvsp[(2) - (5)].index)), (yyvsp[(3) - (5)].node), set_terminal((yyvsp[(4) - (5)].index)), (yyvsp[(5) - (5)].node));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 336 "yacc.y"
    {
		(yyval.node) = set_vn("Stmt", 5, set_terminal((yyvsp[(1) - (5)].index)), set_terminal((yyvsp[(2) - (5)].index)), set_terminal(0), set_terminal((yyvsp[(4) - (5)].index)), (yyvsp[(5) - (5)].node));
		error = true;
		printf("Syntax Error at Line %d: Something wrong with expression between ().\n", (yylsp[(3) - (5)]).last_line);
	;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 341 "yacc.y"
    {
		(yyval.node) = set_vn("Stmt", 4, set_terminal((yyvsp[(1) - (4)].index)), set_terminal(0), set_terminal((yyvsp[(3) - (4)].index)), (yyvsp[(4) - (4)].node));
		error = true;
		printf("Syntax Error at Line %d: Missing \"(\".\n", (yylsp[(2) - (4)]).last_line);
	;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 348 "yacc.y"
    {(yyval.node) = NULL;;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 349 "yacc.y"
    {(yyval.node) = set_vn("DefList", 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 353 "yacc.y"
    {
		(yyval.node) = set_vn("Def", 3, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), set_terminal((yyvsp[(3) - (3)].index)));
		addType((yyvsp[(1) - (3)].node)->type);
	;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 358 "yacc.y"
    {
		(yyval.node) = set_vn("Def", 3, (yyvsp[(1) - (3)].node), set_terminal(0), set_terminal((yyvsp[(3) - (3)].index)));
		addType((yyvsp[(1) - (3)].node)->type);
		error = true;
		printf("Syntax Error at Line %d: Unnecessary \",\".\n", (yylsp[(2) - (3)]).last_line);
	;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 366 "yacc.y"
    {(yyval.node) = set_vn("DecList", 1, (yyvsp[(1) - (1)].node)); (yyval.node)->index = (yyvsp[(1) - (1)].node)->index;;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 368 "yacc.y"
    {
		(yyval.node) = set_vn("DefList", 3, (yyvsp[(1) - (3)].node), set_terminal((yyvsp[(2) - (3)].index)), (yyvsp[(3) - (3)].node));
		(yyval.node)->index = (yyvsp[(1) - (3)].node)->index;
	;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 373 "yacc.y"
    {
		(yyval.node) = set_vn("DefList", 3, set_terminal(0), set_terminal((yyvsp[(2) - (3)].index)), (yyvsp[(3) - (3)].node));
		error = true;
		printf("Syntax Error at Line %d: Something wrong with declaration.\n", (yylsp[(1) - (3)]).last_line);
	;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 381 "yacc.y"
    {
		(yyval.node) = set_vn("Dec", 1, (yyvsp[(1) - (1)].node));
		(yyval.node)->index = (yyvsp[(1) - (1)].node)->index; 
		if(varFind((yyvsp[(1) - (1)].node)->index) != NULL && sameLevel((yyvsp[(1) - (1)].node)->index)){
			error = true;
			printf("Semantic Error at Line %d: Redefined Variable \"%s\".\n", yylineno, G_Var[(yyvsp[(1) - (1)].node)->index].mark);
		}
        else
        	varTable((yyvsp[(1) - (1)].node)->index, deminsion, size);

	;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 393 "yacc.y"
    {
		(yyval.node) = set_vn("Dec", 3, (yyvsp[(1) - (3)].node), set_terminal((yyvsp[(2) - (3)].index)), (yyvsp[(3) - (3)].node));
		(yyval.node)->index = (yyvsp[(1) - (3)].node)->index;
		if(varFind((yyvsp[(1) - (3)].node)->index) != NULL && sameLevel((yyvsp[(1) - (3)].node)->index)){
			error = true;
			printf("Semantic Error at Line %d: Redefined Variable \"%s\".\n", yylineno, G_Var[(yyvsp[(1) - (3)].node)->index].mark);
		}
        else
        	varTable((yyvsp[(1) - (3)].node)->index, deminsion, size);
	;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 404 "yacc.y"
    {
		(yyval.node) = set_vn("Dec", 3, set_terminal(0), set_terminal((yyvsp[(2) - (3)].index)), (yyvsp[(3) - (3)].node));
		(yyval.node)->index = (yyvsp[(3) - (3)].node)->index;
		error = true;
		printf("Syntax Error at Line %d: Missing the variable.\n", (yylsp[(1) - (3)]).last_line);
	;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 413 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 3, (yyvsp[(1) - (3)].node), set_terminal((yyvsp[(2) - (3)].index)), (yyvsp[(3) - (3)].node));
		(yyval.node)->type = (yyvsp[(1) - (3)].node)->type;
		(yyval.node)->deminsion = (yyvsp[(1) - (3)].node)->deminsion;
		// printf("%d %d %d %d \n\n", $1->type, $3->type, $1->deminsion, $3->deminsion);
		if((yyvsp[(1) - (3)].node)->type < 0 && (yyvsp[(3) - (3)].node)->type < 0){
			if((yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for assignment.\n", yylineno);
			}
			else if((yyvsp[(1) - (3)].node)->deminsion == 0 && (yyvsp[(3) - (3)].node)->deminsion!=0 && (yyvsp[(3) - (3)].node)->deminsion != varFind((yyvsp[(3) - (3)].node)->index)->deminsion){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for assignment.\n", yylineno);
			}
			else if((yyvsp[(3) - (3)].node)->deminsion == 0 && (yyvsp[(1) - (3)].node)->deminsion!=0 && (yyvsp[(1) - (3)].node)->deminsion != varFind((yyvsp[(1) - (3)].node)->index)->deminsion){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for assignment.\n", yylineno);
			}
		}
		else if((yyvsp[(1) - (3)].node)->type >= 0 && (yyvsp[(3) - (3)].node)->type >= 0){
			//printf("%d %d %s %s\n\n", $1->type, $2->type, G_Var[$1->type].mark, G_Var[$2->type].mark);
			if(!strucMatch((yyvsp[(1) - (3)].node)->type, (yyvsp[(3) - (3)].node)->type)){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for assignment.\n", yylineno);
			}
		}
		if((yyvsp[(1) - (3)].node)->kind == TYPE_CONST){
			error = true;
			printf("Semantic Error at Line %d: The left-hand side of an assignment must be a variable.\n", yylineno);
		}
	;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 445 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 3, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].index), (yyvsp[(3) - (3)].node)); 
		(yyval.node)->type = (yyvsp[(1) - (3)].node)->type; 
		(yyval.node)->deminsion = (yyvsp[(1) - (3)].node)->deminsion;
		if((yyvsp[(1) - (3)].node)->type != TYPE_NUM || (yyvsp[(3) - (3)].node)->type != TYPE_NUM){
			error = true;
			printf("Semantic Error at Line %d: Only integer can be used as Bool.\n", yylineno);	
		}
	;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 455 "yacc.y"
    { 
		(yyval.node) = set_vn("Exp", 3, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].index), (yyvsp[(3) - (3)].node)); 
		(yyval.node)->type = (yyvsp[(1) - (3)].node)->type; 
		(yyval.node)->deminsion = (yyvsp[(1) - (3)].node)->deminsion;
		if((yyvsp[(1) - (3)].node)->type != TYPE_NUM || (yyvsp[(3) - (3)].node)->type != TYPE_NUM){
			error = true;
			printf("Semantic Error at Line %d: Only integer can be used as Bool.\n", yylineno);	
		}
	;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 464 "yacc.y"
    {(yyval.node) = set_vn("Exp", 3, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node)); (yyval.node)->type = (yyvsp[(1) - (3)].node)->type; (yyval.node)->deminsion = (yyvsp[(1) - (3)].node)->deminsion;;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 466 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 3, (yyvsp[(1) - (3)].node), set_terminal((yyvsp[(2) - (3)].index)), (yyvsp[(3) - (3)].node));
		(yyval.node)->type = (yyvsp[(1) - (3)].node)->type;
		(yyval.node)->deminsion = (yyvsp[(1) - (3)].node)->deminsion;
		if((yyvsp[(1) - (3)].node)->type < 0 && (yyvsp[(3) - (3)].node)->type < 0){
			if((yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
			}
			else if((yyvsp[(1) - (3)].node)->deminsion == 0 && (yyvsp[(3) - (3)].node)->deminsion!=0 && (yyvsp[(3) - (3)].node)->deminsion != varFind((yyvsp[(3) - (3)].node)->index)->deminsion){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
			}
			else if((yyvsp[(3) - (3)].node)->deminsion == 0 && (yyvsp[(1) - (3)].node)->deminsion!=0 && (yyvsp[(1) - (3)].node)->deminsion != varFind((yyvsp[(1) - (3)].node)->index)->deminsion){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
			}
		}
	;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 486 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 3, (yyvsp[(1) - (3)].node), set_terminal((yyvsp[(2) - (3)].index)), (yyvsp[(3) - (3)].node));
		(yyval.node)->type = (yyvsp[(1) - (3)].node)->type;
		(yyval.node)->deminsion = (yyvsp[(1) - (3)].node)->deminsion;
		if((yyvsp[(1) - (3)].node)->type < 0 && (yyvsp[(3) - (3)].node)->type < 0){
			if((yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
			}
			else if((yyvsp[(1) - (3)].node)->deminsion == 0 &&  (yyvsp[(3) - (3)].node)->deminsion!=0 && (yyvsp[(3) - (3)].node)->deminsion != varFind((yyvsp[(3) - (3)].node)->index)->deminsion){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
			}
			else if((yyvsp[(3) - (3)].node)->deminsion == 0 &&  (yyvsp[(1) - (3)].node)->deminsion!=0 && (yyvsp[(1) - (3)].node)->deminsion != varFind((yyvsp[(1) - (3)].node)->index)->deminsion){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
			}
		}
	;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 506 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 3, (yyvsp[(1) - (3)].node), set_terminal((yyvsp[(2) - (3)].index)), (yyvsp[(3) - (3)].node));
		(yyval.node)->type = (yyvsp[(1) - (3)].node)->type;
		(yyval.node)->deminsion = (yyvsp[(1) - (3)].node)->deminsion;
		if((yyvsp[(1) - (3)].node)->type < 0 && (yyvsp[(3) - (3)].node)->type < 0){
			if((yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
			}
			else if((yyvsp[(1) - (3)].node)->deminsion == 0 &&  (yyvsp[(3) - (3)].node)->deminsion!=0 && (yyvsp[(3) - (3)].node)->deminsion != varFind((yyvsp[(3) - (3)].node)->index)->deminsion){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
			}
			else if((yyvsp[(3) - (3)].node)->deminsion == 0 &&  (yyvsp[(1) - (3)].node)->deminsion!=0 && (yyvsp[(1) - (3)].node)->deminsion != varFind((yyvsp[(1) - (3)].node)->index)->deminsion){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
			}
		}
	;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 526 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 3, (yyvsp[(1) - (3)].node), set_terminal((yyvsp[(2) - (3)].index)), (yyvsp[(3) - (3)].node));
		(yyval.node)->type = (yyvsp[(1) - (3)].node)->type;
		(yyval.node)->deminsion = (yyvsp[(1) - (3)].node)->deminsion;
		if((yyvsp[(1) - (3)].node)->type < 0 && (yyvsp[(3) - (3)].node)->type < 0){
			if((yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
			}
			else if((yyvsp[(1) - (3)].node)->deminsion == 0 &&  (yyvsp[(3) - (3)].node)->deminsion!=0 && (yyvsp[(3) - (3)].node)->deminsion != varFind((yyvsp[(3) - (3)].node)->index)->deminsion){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
			}
			else if((yyvsp[(3) - (3)].node)->deminsion == 0 &&  (yyvsp[(1) - (3)].node)->deminsion!=0 && (yyvsp[(1) - (3)].node)->deminsion != varFind((yyvsp[(1) - (3)].node)->index)->deminsion){
				error = true;
				printf("Semantic Error at Line %d: Type mismatched for operand.\n", yylineno);
			}
		}
	;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 546 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 3, set_terminal((yyvsp[(1) - (3)].index)), (yyvsp[(2) - (3)].node), set_terminal((yyvsp[(3) - (3)].index))); 
		(yyval.node)->type = (yyvsp[(2) - (3)].node)->type; 
		(yyval.node)->deminsion = 0;
	;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 552 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 2, set_terminal(0), set_terminal((yyvsp[(2) - (2)].index))); 
		(yyval.node)->deminsion = 0;
		error = true;
		printf("Syntax Error at Line %d: Missing \"(\".\n", (yylsp[(1) - (2)]).last_line);
	;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 559 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 2, set_terminal((yyvsp[(1) - (2)].index)), (yyvsp[(2) - (2)].node)); 
		(yyval.node)->type = (yyvsp[(2) - (2)].node)->type; 
		(yyval.node)->deminsion = 0;
		if((yyval.node)->type>0){
			error = true;
			printf("Semantic Error at Line %d: Only integer and float can use \"-\".\n", yylineno);	
		}
	;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 569 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 2, set_terminal((yyvsp[(1) - (2)].index)), (yyvsp[(2) - (2)].node)); 
		(yyval.node)->type = (yyvsp[(2) - (2)].node)->type; 
		(yyval.node)->deminsion = 0;
		if((yyvsp[(2) - (2)].node)->type != TYPE_NUM){
			error = true;
			printf("Semantic Error at Line %d: Only integer can use \"!\".\n", yylineno);	
		}
	;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 579 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 4, set_var((yyvsp[(1) - (4)].index)), set_terminal((yyvsp[(2) - (4)].index)), (yyvsp[(3) - (4)].node), set_terminal((yyvsp[(4) - (4)].index)));
		(yyval.node)->index = (yyvsp[(1) - (4)].index);
		(yyval.node)->deminsion = 0;
		if(varFind((yyvsp[(1) - (4)].index)) == NULL && funcFind((yyvsp[(1) - (4)].index)) == NULL && strcmp(G_Var[curFunc].mark, G_Var[(yyvsp[(1) - (4)].index)].mark)){
			error = true;
			printf("Semantic Error at Line %d: undefined Function \"%s\".\n", yylineno, G_Var[(yyvsp[(1) - (4)].index)].mark);
		}
		else if((funcFind((yyvsp[(1) - (4)].index)) == NULL || !strcmp(G_Var[curFunc].mark, G_Var[(yyvsp[(1) - (4)].index)].mark)) && varFind((yyvsp[(1) - (4)].index)) != NULL){
			error = true;
			printf("Semantic Error at Line %d: \"%s\" is not a function.\n", yylineno, G_Var[(yyvsp[(1) - (4)].index)].mark);
		}
		else{
			if((funcFind((yyvsp[(1) - (4)].index)) != NULL && paraNum((yyvsp[(1) - (4)].index)) != rpNum) || (!strcmp(G_Var[curFunc].mark, G_Var[(yyvsp[(1) - (4)].index)].mark) && rpNum != pNum)){
				error = true;
				printf("Semantic Error at Line %d: arguement number mismatches for the parameter number of function \"%s\" .\n", yylineno, G_Var[(yyvsp[(1) - (4)].index)].mark);
			}
			if(funcFind((yyvsp[(1) - (4)].index)) != NULL)
				(yyval.node)->type = funcType((yyvsp[(1) - (4)].index));
			else
				(yyval.node)->type = type;

		}
		rpNum = 0;   //将实参个数清0
	;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 605 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 3, set_var((yyvsp[(1) - (3)].index)), set_terminal((yyvsp[(2) - (3)].index)), set_terminal((yyvsp[(3) - (3)].index))); 
		(yyval.node)->index = (yyvsp[(1) - (3)].index); 
		(yyval.node)->deminsion = 0;
		if(varFind((yyvsp[(1) - (3)].index)) == NULL && funcFind((yyvsp[(1) - (3)].index)) == NULL && strcmp(G_Var[curFunc].mark, G_Var[(yyvsp[(1) - (3)].index)].mark)){
			error = true;
			printf("Semantic Error at Line %d: undefined Function \"%s\".\n", yylineno, G_Var[(yyvsp[(1) - (3)].index)].mark);
		}
		else if((funcFind((yyvsp[(1) - (3)].index)) == NULL || !strcmp(G_Var[curFunc].mark, G_Var[(yyvsp[(1) - (3)].index)].mark)) && varFind((yyvsp[(1) - (3)].index)) != NULL){
			error = true;
			printf("Semantic Error at Line %d: \"%s\" is not a function.\n", yylineno, G_Var[(yyvsp[(1) - (3)].index)].mark);
		}
		else{
			if(paraNum((yyvsp[(1) - (3)].index)) != 0){
				error = true;
				printf("Semantic Error at Line %d: arguement number mismatches for the parameter number of function \"%s\" .\n", yylineno, G_Var[(yyvsp[(1) - (3)].index)].mark);
			}
			if(funcFind((yyvsp[(1) - (3)].index)) != NULL)
				(yyval.node)->type = funcType((yyvsp[(1) - (3)].index));
			else
				(yyval.node)->type = type;
		}
	;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 629 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 3, set_var((yyvsp[(1) - (3)].index)), set_terminal(0), set_terminal((yyvsp[(3) - (3)].index))); 
		(yyval.node)->index = (yyvsp[(1) - (3)].index); 
		(yyval.node)->deminsion = 0;
		error = true;
		printf("Syntax Error at Line %d: Missing \"(\".\n", (yylsp[(2) - (3)]).last_line);
	;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 637 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 4, (yyvsp[(1) - (4)].node), set_terminal((yyvsp[(2) - (4)].index)), (yyvsp[(3) - (4)].node), set_terminal((yyvsp[(4) - (4)].index)));
		(yyval.node)->index = (yyvsp[(1) - (4)].node)->index;
		(yyval.node)->type = (yyvsp[(1) - (4)].node)->type;
		(yyval.node)->deminsion = (yyvsp[(1) - (4)].node)->deminsion + 1;
		if(varFind((yyvsp[(1) - (4)].node)->index) != NULL && (varDeminsion((yyvsp[(1) - (4)].node)->index) == 0||funcFind((yyvsp[(1) - (4)].node)->index) != NULL)){
			error = true;
	        printf("Semantic Error at Line %d: \"%s\" is not an array.\n", yylineno, G_Var[(yyvsp[(1) - (4)].node)->index].mark);
		}
	    else if(varFind((yyvsp[(1) - (4)].node)->index) == NULL ){
	    	error = true;
	        printf("Semantic Error at Line %d: undefined Array \"%s\".\n", yylineno, G_Var[(yyvsp[(1) - (4)].node)->index].mark);
	    }
		if((yyvsp[(3) - (4)].node)->type != TYPE_NUM){
			error = true;
			printf("Semantic Error at Line %d: \"%.1f\" is not a integer.\n", yylineno, (yyvsp[(3) - (4)].node)->numF);	
		}
	;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 656 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 4, (yyvsp[(1) - (3)].node), set_terminal((yyvsp[(2) - (3)].index)), set_terminal(0));
		(yyval.node)->index = (yyvsp[(1) - (3)].node)->index;
		(yyval.node)->type = (yyvsp[(1) - (3)].node)->type;
		(yyval.node)->deminsion = (yyvsp[(1) - (3)].node)->deminsion;
		error = true;
		printf("Syntax Error at Line %d: Missing \"]\".\n", (yylsp[(3) - (3)]).last_line);
	;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 665 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 3, (yyvsp[(1) - (3)].node), set_terminal((yyvsp[(2) - (3)].index)), set_var((yyvsp[(3) - (3)].index)));
		(yyval.node)->type = varType((yyvsp[(3) - (3)].index));
		(yyval.node)->deminsion = (yyvsp[(1) - (3)].node)->deminsion;
		if(varFind((yyvsp[(1) - (3)].node)->index) == NULL){
			error = true;
			printf("Semantic Error at Line %d: undefined struct variable \"%s\".\n", yylineno, G_Var[(yyvsp[(1) - (3)].node)->index].mark);
		}
		else if((yyvsp[(1) - (3)].node)->type < 0){
			error = true;
			printf("Semantic Error at Line %d: Illegal use of \".\".\n", yylineno);
		}
		else if(!strucMem(varType((yyvsp[(1) - (3)].node)->index), (yyvsp[(3) - (3)].index))){
			error = true;
			printf("Semantic Error at Line %d: Non-existent filed \"%s\".\n", yylineno, G_Var[(yyvsp[(3) - (3)].index)].mark);
		}
	;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 683 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 1, set_var((yyvsp[(1) - (1)].index)));
		if(varFind((yyvsp[(1) - (1)].index)) == NULL){
			error = true;
			printf("Semantic Error at Line %d: Undefined variable \"%s\".\n", yylineno, G_Var[(yyvsp[(1) - (1)].index)].mark);
		}
		else{
			(yyval.node)->type = varType((yyvsp[(1) - (1)].index));
			(yyval.node)->kind = TYPE_VAR;
			(yyval.node)->deminsion = 0;
			(yyval.node)->index = (yyvsp[(1) - (1)].index);
		}
	;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 697 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 1, set_int((yyvsp[(1) - (1)].numI)));
		(yyval.node)->type = TYPE_NUM;
		(yyval.node)->deminsion = 0;
		(yyval.node)->numI = (yyvsp[(1) - (1)].numI);
	;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 704 "yacc.y"
    {
		(yyval.node) = set_vn("Exp", 1, set_float((yyvsp[(1) - (1)].numF)));
		(yyval.node)->type = TYPE_FLOAT;
		(yyval.node)->deminsion = 0;
		(yyval.node)->numF = (yyvsp[(1) - (1)].numF);
	;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 712 "yacc.y"
    {(yyval.node) = set_terminal((yyvsp[(1) - (1)].index));;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 713 "yacc.y"
    {(yyval.node) = set_terminal((yyvsp[(1) - (1)].index));;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 714 "yacc.y"
    {(yyval.node) = set_terminal((yyvsp[(1) - (1)].index));;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 715 "yacc.y"
    {(yyval.node) = set_terminal((yyvsp[(1) - (1)].index));;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 716 "yacc.y"
    {(yyval.node) = set_terminal((yyvsp[(1) - (1)].index));;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 717 "yacc.y"
    {(yyval.node) = set_terminal((yyvsp[(1) - (1)].index));;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 721 "yacc.y"
    {
		(yyval.node) = set_vn("Args", 3, (yyvsp[(1) - (3)].node), set_terminal((yyvsp[(2) - (3)].index)), (yyvsp[(3) - (3)].node)); 
		rpNum += 1;
	;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 726 "yacc.y"
    {
		(yyval.node) = set_vn("Args", 3, set_terminal(0), set_terminal((yyvsp[(2) - (3)].index)), (yyvsp[(3) - (3)].node)); 
		rpNum += 1;
		error = true;
		printf("Syntax Error at Line %d: Something wrong with your expression.\n", (yylsp[(1) - (3)]).last_line);
	;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 733 "yacc.y"
    {	
		(yyval.node) = set_vn("Args", 1, (yyvsp[(1) - (1)].node));
		rpNum += 1;
	;}
    break;



/* Line 1455 of yacc.c  */
#line 2763 "yacc.tab.c"
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
#line 738 "yacc.y"
 

void yyerror(char* s){
    printf("%s at line %d.\n", s, yylineno);
    error = true;
    return ;     
}

int main(int argc, char **argv){      
	extern FILE* yyin;
	char tree_filename[32], med_filename[32], fin_filename[32];
	
	if(argc != 2){
		printf("Please input the source and target file!\n");
		return 0;
	}

	if((yyin = fopen(argv[1], "r")) == NULL){
		printf("Cannot open the source file!\n");
		return 0;
	}
	char *pos = strchr(argv[1], '.');

	strncpy(tree_filename, argv[1], pos-argv[1]);
	tree_filename[pos-argv[1]] = '\0';
	strcat(tree_filename, ".tree");

	strncpy(med_filename, argv[1], pos-argv[1]);
	med_filename[pos-argv[1]] = '\0';
	strcat(med_filename, ".med");

	strncpy(fin_filename, argv[1], pos-argv[1]);
	fin_filename[pos-argv[1]] = '\0';
	strcat(fin_filename, ".asm");

	treeFile = fopen(tree_filename, "w");

	//printf("starting!\n");
	//yydebug = 1;
	initTable();
	yyparse(); 
	fclose(yyin);
	fclose(treeFile);
	undefFunc();

	if(error == false){
		initCode();
		translate(treeHead);
		FILE *medFile = fopen(med_filename, "w");
		FILE *finFile = fopen(fin_filename, "w");
		printCode(medFile, finFile);
		fclose(medFile);
		fclose(finFile);
		destroyCode();
	}
	NodeFree(treeHead);
    destroyTable();
    
	// printf("ending!\n");

	
	return 0; 
}  
 

