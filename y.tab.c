/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "part3.y"

	#define _GNU_SOURCE
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	typedef enum {false,true} bool;
	typedef struct node
	{
		char *token;
		struct node *left;
		struct node *right;
		char *code;
		char *var;
		char *label;
		char *truelabel;
		char *falselabel;
		int sum;
	} node;

	typedef struct Arguments
	{
		char * name;
		char * type;
		char * len;
	}Arguments;

    	typedef struct Function 
	{
        char * name;
		struct Arguments * args;
        char *returnType; 
		int countArgs;
		int findreturn;
    	} Function;

	typedef struct Varaiables
	{	int isArg;
		char *name;
		char *value;
		char *type;
		char * len;
	}Varaiable;

	typedef struct code
	{	
		int place;
		char *name;
		Varaiable * var;
		int countvar;
		int countfunc;
		Function ** func;
		struct code * nextLVL;
		struct code * beforeLVL;
	}code;
	
	char * exprtype(node *,code*);
	Arguments * mkArgs(node *,int *);
	void addFunc(char * name,Arguments * args,node *returnType,int countArgs,code*);
	void addvar(Arguments * args,int,int,code * CODEscope);
	code* mkcode(char *);
	node* mknode(char* token, node *left, node *right);
	void Printtree(node *tree);
	void printTabs(int n);
	int yylex();
	int yyerror(char *e);
	void push(code* from,char*);
	int printlevel=0;
	code* mycode=NULL;
	code* lestcode(code * codey);
	static int scope=0;
	void syntaxMKscope(node *tree,code * scope);
	char* findfunc(node * tree,code * CODEscope,int* count);
	char *findvar(node * tree,code * CODEscope);
	Arguments * callfuncargs(code *,node *tree,int * count);
	int flagMain=false;
	static node * firstNode;
	int POPParams(Arguments * args,int count);
	void addCode(node* node,char *code,char *var,char *label,char *truelabel,char *falselabel);
	void addCode2(node* node,char *code,char *var,char *label,char *truelabel,char *falselabel);
	char* freshVar();
	char* freshLabel();
	char* gen(char*,char*,char*,char*,char*);
	char* mystrcat(char*des,char*src);
	char* mystrcat2(char*des,char*src);
	char *replaceWord(const char *s, const char *oldW, const char *newW);
	static int t=0;
	static int l=0;
	static int line=0;
	char * mkspace(char *label);
	void calc3AC(node * tree);	

#line 163 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    COMMENT = 258,
    WHILE = 259,
    IF = 260,
    ELSE = 261,
    FOR = 262,
    RETURN = 263,
    BOOL = 264,
    STRING = 265,
    CHARPTR = 266,
    CHAR = 267,
    INT = 268,
    INTPTR = 269,
    PROCEDUR = 270,
    AND = 271,
    ADDRESS = 272,
    EQL = 273,
    ASSINGMENT = 274,
    OR = 275,
    LENGTH = 276,
    GREATEREQL = 277,
    GREATER = 278,
    LESSEQL = 279,
    LESS = 280,
    NOTEQL = 281,
    NOT = 282,
    DIVISION = 283,
    PLUS = 284,
    MINUS = 285,
    MULTI = 286,
    VARIABLE = 287,
    STRING_LTL = 288,
    REAL_LTL = 289,
    CHAR_LTL = 290,
    NULLL = 291,
    MAIN = 292,
    IDENTIFIER = 293,
    SEMICOLON = 294,
    COMMA = 295,
    OPENPAREN = 296,
    CLOSEPAREN = 297,
    OPENBRACKET = 298,
    CLOSEBRACKET = 299,
    OPENBRACE = 300,
    CLOSEBRACE = 301,
    DECIMAL_LTL = 302,
    HEX_LTL = 303,
    BOOLTRUE = 304,
    BOOLFALSE = 305,
    REAL = 306,
    REALPTR = 307,
    FUNCTION = 308,
    COLON = 309,
    DEREFRENCE = 310
  };
#endif
/* Tokens.  */
#define COMMENT 258
#define WHILE 259
#define IF 260
#define ELSE 261
#define FOR 262
#define RETURN 263
#define BOOL 264
#define STRING 265
#define CHARPTR 266
#define CHAR 267
#define INT 268
#define INTPTR 269
#define PROCEDUR 270
#define AND 271
#define ADDRESS 272
#define EQL 273
#define ASSINGMENT 274
#define OR 275
#define LENGTH 276
#define GREATEREQL 277
#define GREATER 278
#define LESSEQL 279
#define LESS 280
#define NOTEQL 281
#define NOT 282
#define DIVISION 283
#define PLUS 284
#define MINUS 285
#define MULTI 286
#define VARIABLE 287
#define STRING_LTL 288
#define REAL_LTL 289
#define CHAR_LTL 290
#define NULLL 291
#define MAIN 292
#define IDENTIFIER 293
#define SEMICOLON 294
#define COMMA 295
#define OPENPAREN 296
#define CLOSEPAREN 297
#define OPENBRACKET 298
#define CLOSEBRACKET 299
#define OPENBRACE 300
#define CLOSEBRACE 301
#define DECIMAL_LTL 302
#define HEX_LTL 303
#define BOOLTRUE 304
#define BOOLFALSE 305
#define REAL 306
#define REALPTR 307
#define FUNCTION 308
#define COLON 309
#define DEREFRENCE 310

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 94 "part3.y"

    struct node *node;
    char *string;

#line 327 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   548

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  198

#define YYUNDEFTOK  2
#define YYMAXUTOK   310


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   126,   126,   128,   130,   130,   132,   139,   140,   142,
     147,   153,   154,   156,   157,   159,   165,   165,   167,   172,
     173,   175,   176,   177,   178,   179,   180,   181,   182,   184,
     185,   186,   187,   188,   189,   190,   191,   194,   194,   197,
     197,   197,   197,   199,   205,   214,   224,   232,   233,   234,
     235,   237,   242,   246,   247,   248,   250,   251,   252,   253,
     254,   255,   256,   258,   259,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   282,   284,   285,   287,   288,   289,   292,   300,   301,
     302,   307,   308,   309,   311,   313
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COMMENT", "WHILE", "IF", "ELSE", "FOR",
  "RETURN", "BOOL", "STRING", "CHARPTR", "CHAR", "INT", "INTPTR",
  "PROCEDUR", "AND", "ADDRESS", "EQL", "ASSINGMENT", "OR", "LENGTH",
  "GREATEREQL", "GREATER", "LESSEQL", "LESS", "NOTEQL", "NOT", "DIVISION",
  "PLUS", "MINUS", "MULTI", "VARIABLE", "STRING_LTL", "REAL_LTL",
  "CHAR_LTL", "NULLL", "MAIN", "IDENTIFIER", "SEMICOLON", "COMMA",
  "OPENPAREN", "CLOSEPAREN", "OPENBRACKET", "CLOSEBRACKET", "OPENBRACE",
  "CLOSEBRACE", "DECIMAL_LTL", "HEX_LTL", "BOOLTRUE", "BOOLFALSE", "REAL",
  "REALPTR", "FUNCTION", "COLON", "DEREFRENCE", "$accept", "project",
  "program", "cmmnt", "main", "procedures", "procedure", "para_pro",
  "para_list", "pro_body", "declears", "declear", "var_id", "type_id",
  "type_pro", "stmnts", "stmnt_block", "new_block", "stmnt",
  "assmnt_stmnt", "lhs", "expr", "address_expr", "derefrence_expr",
  "expr_list", "paren_expr", "call_func", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310
};
# endif

#define YYPACT_NINF (-167)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-56)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,    13,    19,  -167,  -167,  -167,  -167,    -7,   -16,    -6,
    -167,  -167,    24,    32,    33,    37,    54,    54,    13,    35,
      51,    56,    42,    58,    60,    54,    61,    13,    25,    13,
      13,  -167,    13,    54,  -167,    64,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,   100,  -167,    63,    67,  -167,    69,    76,
      16,  -167,  -167,    66,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,    74,    80,    88,  -167,    13,    54,  -167,   218,
      78,    75,    13,    89,   243,   -27,    94,   243,  -167,  -167,
    -167,  -167,     4,   243,  -167,  -167,  -167,  -167,  -167,   -21,
    -167,  -167,    95,   119,   467,   121,   122,    13,  -167,    25,
     101,   243,   -13,   485,  -167,  -167,   102,   105,   123,  -167,
     243,   243,  -167,   364,    10,   104,   243,    13,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,    13,  -167,    13,   243,   385,   243,    13,   243,    -2,
    -167,   448,   107,   279,  -167,  -167,   243,   406,  -167,   503,
     517,  -167,   517,    53,    53,    53,    53,    53,   132,    73,
      73,   132,  -167,   112,   427,   131,   296,  -167,   313,  -167,
     243,   243,  -167,   134,    88,   330,  -167,    13,   131,  -167,
    -167,  -167,   148,  -167,  -167,  -167,   347,  -167,   183,  -167,
    -167,  -167,   131,   113,    13,  -167,  -167,  -167
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     5,     0,     8,     4,     1,     2,     0,     0,     0,
       3,     7,     0,     0,     0,     0,    12,    12,     5,    20,
       0,    11,     0,     0,     0,     0,     0,     5,     0,     5,
       5,    19,     5,     0,    21,     0,    27,    23,    24,    26,
      25,    28,    13,     0,     8,     0,     0,    14,     0,     0,
      17,     6,    10,     0,    29,    30,    35,    31,    32,    34,
      33,    36,     0,     0,    38,    22,     5,     0,    16,    15,
       0,     0,     5,     0,     0,     0,     0,     0,    77,    76,
      75,    83,    82,     0,     8,    73,    74,    79,    78,     0,
      50,    37,     0,     0,     0,    70,    71,     5,     9,     0,
       0,     0,    82,     0,    70,    71,    84,     0,     0,    69,
      93,     0,    95,     0,     5,    88,     0,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,    72,     5,     0,     0,     0,     5,     0,     0,
      80,    92,     0,     0,    56,    17,     0,     0,    47,    51,
      63,    57,    64,    59,    60,    61,    62,    58,    68,    65,
      66,    67,    48,     0,     0,     0,     0,    49,     0,    85,
       0,    93,    94,    81,    38,     0,    89,     5,     0,    42,
      41,    40,    44,    39,    81,    86,     0,    91,     0,    90,
      18,    46,     0,     0,     5,    45,    87,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -167,  -167,  -167,     0,  -167,   -20,   -98,   139,   124,   -22,
      14,   -59,   -18,    62,  -167,   -14,  -166,  -167,   -65,  -167,
    -167,   -68,   -67,   -66,    -9,  -167,  -167
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,    44,    10,     7,    11,    20,    21,    45,
      64,   181,    22,    42,    62,    69,   182,    90,   183,    92,
      93,    94,   104,   105,   142,   112,    97
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       3,     4,    95,    96,    91,    68,   103,    31,     8,   109,
      46,   106,   191,     1,   107,   113,     1,   115,    24,     5,
     116,    12,    13,   -53,    50,    63,   195,    33,   110,    43,
     136,    63,    14,   135,    34,    35,    36,    37,    38,    39,
     169,   170,   141,   143,    70,   110,     9,   111,   147,    71,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,     9,   114,    15,   164,   180,   166,     9,
     168,   120,   100,    16,    17,    25,    40,    41,   175,    18,
     180,   127,   128,   129,   130,    54,    55,    56,    57,    58,
      59,   120,    19,    26,   180,    27,    28,   132,    95,    96,
      29,   127,   186,   141,   130,    30,    32,    48,    49,    51,
      65,    95,    96,    52,   145,    68,    53,   148,    13,    66,
      67,    95,    96,    91,    98,    95,    96,    60,    61,    99,
     101,   162,   108,   163,   117,    72,    73,   167,   118,    74,
     -54,   -55,   134,   139,   140,   138,    63,   146,    75,   172,
     120,   177,    76,   -52,   192,   196,    23,    47,    77,   174,
     188,   133,   187,    67,    78,    79,    80,    81,     0,    82,
     179,     0,    83,     0,     0,     0,    84,   190,    85,    86,
      87,    88,     0,     0,     9,     0,    89,    72,    73,     0,
       0,    74,     0,     0,   197,     0,     0,     0,     0,     0,
      75,     0,     0,     0,    76,     0,     0,     0,     0,     0,
      77,     0,     0,     0,     0,     0,    78,    79,    80,    81,
       0,    82,    72,    73,    83,     0,    74,     0,    84,   194,
      85,    86,    87,    88,     0,    75,     0,     0,    89,    76,
       0,     0,     0,     0,     0,    77,     0,     0,     0,     0,
       0,    78,    79,    80,    81,     0,    82,     0,     0,    83,
      75,     0,     0,    84,    76,    85,    86,    87,    88,     0,
      77,     0,     0,    89,     0,     0,    78,    79,    80,    81,
       0,   102,     0,     0,    83,     0,     0,     0,     0,     0,
      85,    86,    87,    88,     0,   119,     0,   120,    89,   121,
       0,   122,   123,   124,   125,   126,     0,   127,   128,   129,
     130,     0,   119,     0,   120,     0,   121,     0,   122,   123,
     124,   125,   126,   173,   127,   128,   129,   130,     0,   119,
       0,   120,     0,   121,     0,   122,   123,   124,   125,   126,
     184,   127,   128,   129,   130,     0,   119,     0,   120,     0,
     121,     0,   122,   123,   124,   125,   126,   185,   127,   128,
     129,   130,     0,   119,     0,   120,     0,   121,     0,   122,
     123,   124,   125,   126,   189,   127,   128,   129,   130,     0,
     119,     0,   120,     0,   121,     0,   122,   123,   124,   125,
     126,   193,   127,   128,   129,   130,     0,     0,     0,     0,
       0,   119,     0,   120,     0,   121,   144,   122,   123,   124,
     125,   126,     0,   127,   128,   129,   130,     0,     0,     0,
       0,     0,   119,     0,   120,     0,   121,   165,   122,   123,
     124,   125,   126,     0,   127,   128,   129,   130,     0,     0,
       0,     0,     0,   119,     0,   120,     0,   121,   176,   122,
     123,   124,   125,   126,     0,   127,   128,   129,   130,     0,
       0,     0,     0,     0,   119,     0,   120,     0,   121,   178,
     122,   123,   124,   125,   126,     0,   127,   128,   129,   130,
       0,     0,     0,   119,     0,   120,     0,   121,   171,   122,
     123,   124,   125,   126,     0,   127,   128,   129,   130,     0,
       0,   119,     0,   120,     0,   121,   131,   122,   123,   124,
     125,   126,     0,   127,   128,   129,   130,     0,     0,   119,
       0,   120,     0,   121,   137,   122,   123,   124,   125,   126,
       0,   127,   128,   129,   130,   120,     0,     0,     0,   122,
     123,   124,   125,   126,     0,   127,   128,   129,   130
};

static const yytype_int16 yycheck[] =
{
       0,     1,    69,    69,    69,    64,    74,    25,    15,    77,
      32,    38,   178,     3,    41,    83,     3,    38,    18,     0,
      41,    37,    38,    19,    44,    15,   192,    27,    41,    29,
      43,    15,    38,   101,     9,    10,    11,    12,    13,    14,
      42,    43,   110,   111,    66,    41,    53,    43,   116,    67,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    53,    84,    41,   134,   165,   136,    53,
     138,    18,    72,    41,    41,    40,    51,    52,   146,    42,
     178,    28,    29,    30,    31,     9,    10,    11,    12,    13,
      14,    18,    38,    42,   192,    39,    54,    97,   165,   165,
      42,    28,   170,   171,    31,    45,    45,    43,     8,    46,
      44,   178,   178,    46,   114,   174,    47,   117,    38,    45,
      32,   188,   188,   188,    46,   192,   192,    51,    52,    54,
      41,   131,    38,   133,    39,     4,     5,   137,    19,     8,
      19,    19,    41,    38,    21,    43,    15,    43,    17,    42,
      18,    39,    21,    19,     6,    42,    17,    33,    27,   145,
     174,    99,   171,    32,    33,    34,    35,    36,    -1,    38,
      39,    -1,    41,    -1,    -1,    -1,    45,   177,    47,    48,
      49,    50,    -1,    -1,    53,    -1,    55,     4,     5,    -1,
      -1,     8,    -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      -1,    38,     4,     5,    41,    -1,     8,    -1,    45,    46,
      47,    48,    49,    50,    -1,    17,    -1,    -1,    55,    21,
      -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    -1,    38,    -1,    -1,    41,
      17,    -1,    -1,    45,    21,    47,    48,    49,    50,    -1,
      27,    -1,    -1,    55,    -1,    -1,    33,    34,    35,    36,
      -1,    38,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    50,    -1,    16,    -1,    18,    55,    20,
      -1,    22,    23,    24,    25,    26,    -1,    28,    29,    30,
      31,    -1,    16,    -1,    18,    -1,    20,    -1,    22,    23,
      24,    25,    26,    44,    28,    29,    30,    31,    -1,    16,
      -1,    18,    -1,    20,    -1,    22,    23,    24,    25,    26,
      44,    28,    29,    30,    31,    -1,    16,    -1,    18,    -1,
      20,    -1,    22,    23,    24,    25,    26,    44,    28,    29,
      30,    31,    -1,    16,    -1,    18,    -1,    20,    -1,    22,
      23,    24,    25,    26,    44,    28,    29,    30,    31,    -1,
      16,    -1,    18,    -1,    20,    -1,    22,    23,    24,    25,
      26,    44,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,    16,    -1,    18,    -1,    20,    42,    22,    23,    24,
      25,    26,    -1,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    16,    -1,    18,    -1,    20,    42,    22,    23,
      24,    25,    26,    -1,    28,    29,    30,    31,    -1,    -1,
      -1,    -1,    -1,    16,    -1,    18,    -1,    20,    42,    22,
      23,    24,    25,    26,    -1,    28,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    16,    -1,    18,    -1,    20,    42,
      22,    23,    24,    25,    26,    -1,    28,    29,    30,    31,
      -1,    -1,    -1,    16,    -1,    18,    -1,    20,    40,    22,
      23,    24,    25,    26,    -1,    28,    29,    30,    31,    -1,
      -1,    16,    -1,    18,    -1,    20,    39,    22,    23,    24,
      25,    26,    -1,    28,    29,    30,    31,    -1,    -1,    16,
      -1,    18,    -1,    20,    39,    22,    23,    24,    25,    26,
      -1,    28,    29,    30,    31,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    28,    29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    57,    59,    59,     0,    58,    61,    15,    53,
      60,    62,    37,    38,    38,    41,    41,    41,    42,    38,
      63,    64,    68,    63,    59,    40,    42,    39,    54,    42,
      45,    68,    45,    59,     9,    10,    11,    12,    13,    14,
      51,    52,    69,    59,    59,    65,    65,    64,    43,     8,
      61,    46,    46,    47,     9,    10,    11,    12,    13,    14,
      51,    52,    70,    15,    66,    44,    45,    32,    67,    71,
      65,    68,     4,     5,     8,    17,    21,    27,    33,    34,
      35,    36,    38,    41,    45,    47,    48,    49,    50,    55,
      73,    74,    75,    76,    77,    78,    79,    82,    46,    54,
      59,    41,    38,    77,    78,    79,    38,    41,    38,    77,
      41,    43,    81,    77,    61,    38,    41,    39,    19,    16,
      18,    20,    22,    23,    24,    25,    26,    28,    29,    30,
      31,    39,    59,    69,    41,    77,    43,    39,    43,    38,
      21,    77,    80,    77,    42,    59,    43,    77,    59,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    59,    59,    77,    42,    77,    59,    77,    42,
      43,    40,    42,    44,    66,    77,    42,    39,    42,    39,
      62,    67,    72,    74,    44,    44,    77,    80,    71,    44,
      59,    72,     6,    44,    46,    72,    42,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    59,    59,    60,    61,    61,    62,
      62,    63,    63,    64,    64,    65,    66,    66,    67,    68,
      68,    69,    69,    69,    69,    69,    69,    69,    69,    70,
      70,    70,    70,    70,    70,    70,    70,    71,    71,    72,
      72,    72,    72,    73,    74,    74,    74,    74,    74,    74,
      74,    75,    76,    76,    76,    76,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    78,    78,    78,    78,    79,    79,
      79,    80,    80,    80,    81,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     8,     2,     0,    11,
       8,     1,     0,     3,     4,     4,     2,     0,     7,     3,
       1,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     0,     1,
       1,     1,     1,     7,     5,     7,     6,     3,     3,     4,
       1,     3,     4,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     1,     1,     2,     4,     5,     7,     2,     4,
       5,     3,     1,     0,     3,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 126 "part3.y"
                       {firstNode = (yyvsp[0].node); syntaxMKscope((yyvsp[0].node),mycode);  calc3AC((yyvsp[0].node));}
#line 1708 "y.tab.c"
    break;

  case 3:
#line 128 "part3.y"
                        {(yyval.node)=mknode("CODE",(yyvsp[-1].node),(yyvsp[0].node));  }
#line 1714 "y.tab.c"
    break;

  case 4:
#line 130 "part3.y"
                     {;}
#line 1720 "y.tab.c"
    break;

  case 6:
#line 133 "part3.y"
{
(yyval.node)=mknode("Main",mknode("ARGS",NULL,(yyvsp[-1].node)),NULL);
t=0;

}
#line 1730 "y.tab.c"
    break;

  case 7:
#line 139 "part3.y"
                                  {(yyval.node)=mknode("procedures",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1736 "y.tab.c"
    break;

  case 8:
#line 140 "part3.y"
          {(yyval.node)=NULL;}
#line 1742 "y.tab.c"
    break;

  case 9:
#line 143 "part3.y"
{ 
		(yyval.node)=mknode("FUNC",mknode((yyvsp[-9].string),mknode("",NULL,NULL),mknode("ARGS",(yyvsp[-7].node),mknode("Return",(yyvsp[-3].node),NULL))),mknode("",(yyvsp[-1].node),NULL));
		t=0; 
}
#line 1751 "y.tab.c"
    break;

  case 10:
#line 148 "part3.y"
{
	(yyval.node)=mknode("PROC",mknode((yyvsp[-6].string),mknode("",NULL,NULL),NULL),mknode("ARGS",(yyvsp[-4].node),(yyvsp[-1].node)));
	t=0; 
}
#line 1760 "y.tab.c"
    break;

  case 11:
#line 153 "part3.y"
                    {(yyval.node)=(yyvsp[0].node);}
#line 1766 "y.tab.c"
    break;

  case 12:
#line 154 "part3.y"
  {(yyval.node)=NULL;}
#line 1772 "y.tab.c"
    break;

  case 13:
#line 156 "part3.y"
                                {(yyval.node)=mknode("(",(yyvsp[0].node),mknode("",(yyvsp[-2].node),mknode(")",NULL,NULL)));}
#line 1778 "y.tab.c"
    break;

  case 14:
#line 157 "part3.y"
                                                {(yyval.node)=mknode("",(yyvsp[-3].node),mknode("",(yyvsp[0].node),NULL));}
#line 1784 "y.tab.c"
    break;

  case 15:
#line 160 "part3.y"
{
	(yyval.node)=mknode("BODY", mknode(" ",(yyvsp[-2].node),NULL),mknode(" ",(yyvsp[-1].node),mknode(" ",(yyvsp[0].node),mknode(" ",NULL,NULL))));
	
}
#line 1793 "y.tab.c"
    break;

  case 16:
#line 165 "part3.y"
                            {(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1799 "y.tab.c"
    break;

  case 17:
#line 165 "part3.y"
                                                     {(yyval.node)=NULL;}
#line 1805 "y.tab.c"
    break;

  case 18:
#line 168 "part3.y"
{
	(yyval.node)=mknode("var", (yyvsp[-3].node),(yyvsp[-5].node));
}
#line 1813 "y.tab.c"
    break;

  case 19:
#line 172 "part3.y"
                                {(yyval.node)=mknode((yyvsp[-2].string), mknode(" ", (yyvsp[0].node), NULL),NULL);}
#line 1819 "y.tab.c"
    break;

  case 20:
#line 173 "part3.y"
                     {(yyval.node)=mknode((yyvsp[0].string), NULL, NULL);}
#line 1825 "y.tab.c"
    break;

  case 21:
#line 175 "part3.y"
              {(yyval.node)=mknode("boolean", NULL, NULL);}
#line 1831 "y.tab.c"
    break;

  case 22:
#line 176 "part3.y"
                                                      {(yyval.node)=mknode("string", mknode("[",mknode("$3",NULL,NULL),NULL), NULL);}
#line 1837 "y.tab.c"
    break;

  case 23:
#line 177 "part3.y"
               {(yyval.node)=mknode("char", NULL, NULL);}
#line 1843 "y.tab.c"
    break;

  case 24:
#line 178 "part3.y"
              {(yyval.node)=mknode("int", NULL, NULL);}
#line 1849 "y.tab.c"
    break;

  case 25:
#line 179 "part3.y"
               {(yyval.node)=mknode("real", NULL, NULL);}
#line 1855 "y.tab.c"
    break;

  case 26:
#line 180 "part3.y"
                 {(yyval.node)=mknode("int*", NULL, NULL);}
#line 1861 "y.tab.c"
    break;

  case 27:
#line 181 "part3.y"
                  {(yyval.node)=mknode("char*", NULL, NULL);}
#line 1867 "y.tab.c"
    break;

  case 28:
#line 182 "part3.y"
                  {(yyval.node)=mknode("real*", NULL, NULL);}
#line 1873 "y.tab.c"
    break;

  case 29:
#line 184 "part3.y"
               {(yyval.node)=mknode("boolean", NULL, NULL);}
#line 1879 "y.tab.c"
    break;

  case 30:
#line 185 "part3.y"
                 {(yyval.node)=mknode("string", NULL, NULL);}
#line 1885 "y.tab.c"
    break;

  case 31:
#line 186 "part3.y"
               {(yyval.node)=mknode("char", NULL, NULL);}
#line 1891 "y.tab.c"
    break;

  case 32:
#line 187 "part3.y"
              {(yyval.node)=mknode("int", NULL, NULL);}
#line 1897 "y.tab.c"
    break;

  case 33:
#line 188 "part3.y"
               {(yyval.node)=mknode("real", NULL, NULL);}
#line 1903 "y.tab.c"
    break;

  case 34:
#line 189 "part3.y"
                 {(yyval.node)=mknode("int*", NULL, NULL);}
#line 1909 "y.tab.c"
    break;

  case 35:
#line 190 "part3.y"
                  {(yyval.node)=mknode("char*", NULL, NULL);}
#line 1915 "y.tab.c"
    break;

  case 36:
#line 191 "part3.y"
                  {(yyval.node)=mknode("real*", NULL, NULL);}
#line 1921 "y.tab.c"
    break;

  case 37:
#line 194 "part3.y"
                       { (yyval.node)=mknode("stmnts",(yyvsp[-1].node),(yyvsp[0].node)); if(strcmp((yyvsp[0].node)->token, "if") == 0||strcmp((yyvsp[0].node)->token, "if-else") == 0||strcmp((yyvsp[0].node)->token, "while") == 0){ if((yyval.node)->sum==0) {addCode((yyvsp[0].node),NULL,NULL,freshLabel(),NULL,NULL); (yyval.node)->sum=1;}}   }
#line 1927 "y.tab.c"
    break;

  case 38:
#line 194 "part3.y"
                                                                                                                                                                                                                                          {(yyval.node)=NULL;}
#line 1933 "y.tab.c"
    break;

  case 39:
#line 197 "part3.y"
                   {(yyval.node)=(yyvsp[0].node); if(strcmp((yyvsp[0].node)->token, "if") == 0||strcmp((yyvsp[0].node)->token, "if-else") == 0||strcmp((yyvsp[0].node)->token, "while") == 0) addCode((yyvsp[0].node),NULL,NULL,freshLabel(),NULL,NULL);}
#line 1939 "y.tab.c"
    break;

  case 40:
#line 197 "part3.y"
                                                                                                                                                                                       {(yyval.node)=(yyvsp[0].node);}
#line 1945 "y.tab.c"
    break;

  case 41:
#line 197 "part3.y"
                                                                                                                                                                                                          {(yyval.node)=(yyvsp[0].node);}
#line 1951 "y.tab.c"
    break;

  case 42:
#line 197 "part3.y"
                                                                                                                                                                                                                               {(yyval.node)=mknode("",NULL,NULL);}
#line 1957 "y.tab.c"
    break;

  case 43:
#line 200 "part3.y"
{
	(yyval.node)=mknode("{",(yyvsp[-5].node),mknode("", (yyvsp[-3].node),mknode("", (yyvsp[-2].node),("}",NULL,NULL))));
	
}
#line 1966 "y.tab.c"
    break;

  case 44:
#line 206 "part3.y"
{
	(yyval.node)=mknode("if",
	mknode("(", (yyvsp[-2].node), 
	mknode(")",NULL,NULL)),(yyvsp[0].node));
	addCode((yyvsp[-2].node),NULL,NULL,NULL,freshLabel(),NULL);
	
	
}
#line 1979 "y.tab.c"
    break;

  case 45:
#line 215 "part3.y"
{
	(yyval.node)=mknode("if-else",
	mknode("", (yyvsp[-4].node), 
	mknode("",NULL,NULL)),
	mknode("",(yyvsp[-2].node),
	mknode("",(yyvsp[0].node),NULL)));
	addCode((yyvsp[-4].node),NULL,NULL,NULL,freshLabel(),NULL);
	addCode((yyvsp[-4].node),NULL,NULL,NULL,NULL,freshLabel());
}
#line 1993 "y.tab.c"
    break;

  case 46:
#line 225 "part3.y"
{
	(yyval.node)=mknode("while",
	mknode("(", (yyvsp[-2].node), 
	mknode(")",NULL,NULL)),(yyvsp[0].node));
addCode((yyval.node),NULL,NULL,NULL,freshLabel(),NULL);
	addCode((yyval.node),NULL,NULL,NULL,NULL,freshLabel());
}
#line 2005 "y.tab.c"
    break;

  case 47:
#line 232 "part3.y"
                               {(yyval.node)=mknode("assmnt_stmnt",(yyvsp[-2].node),NULL);  }
#line 2011 "y.tab.c"
    break;

  case 48:
#line 233 "part3.y"
                       {(yyval.node)=(yyvsp[-2].node);}
#line 2017 "y.tab.c"
    break;

  case 49:
#line 234 "part3.y"
                              {(yyval.node)=mknode("return",(yyvsp[-2].node),NULL);}
#line 2023 "y.tab.c"
    break;

  case 50:
#line 235 "part3.y"
            {(yyval.node)=(yyvsp[0].node);}
#line 2029 "y.tab.c"
    break;

  case 51:
#line 238 "part3.y"
{
	(yyval.node)=mknode("=",(yyvsp[-2].node),(yyvsp[0].node));
}
#line 2037 "y.tab.c"
    break;

  case 52:
#line 243 "part3.y"
{
	(yyval.node)=mknode((yyvsp[-3].string), mknode("[",(yyvsp[-1].node),mknode("]",NULL,NULL)), NULL);
}
#line 2045 "y.tab.c"
    break;

  case 53:
#line 246 "part3.y"
             {(yyval.node)=mknode((yyvsp[0].string),NULL,NULL);}
#line 2051 "y.tab.c"
    break;

  case 54:
#line 247 "part3.y"
               {(yyval.node)=(yyvsp[0].node);}
#line 2057 "y.tab.c"
    break;

  case 55:
#line 248 "part3.y"
                 {(yyval.node)=(yyvsp[0].node);}
#line 2063 "y.tab.c"
    break;

  case 56:
#line 250 "part3.y"
                                 {(yyval.node)=mknode("(",(yyvsp[-1].node),mknode(")",NULL,NULL));}
#line 2069 "y.tab.c"
    break;

  case 57:
#line 251 "part3.y"
                  {(yyval.node)=mknode("==",(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2075 "y.tab.c"
    break;

  case 58:
#line 252 "part3.y"
                           {(yyval.node)=mknode("!=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2081 "y.tab.c"
    break;

  case 59:
#line 253 "part3.y"
                               {(yyval.node)=mknode(">=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2087 "y.tab.c"
    break;

  case 60:
#line 254 "part3.y"
                            {(yyval.node)=mknode(">",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2093 "y.tab.c"
    break;

  case 61:
#line 255 "part3.y"
                            {(yyval.node)=mknode("<=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2099 "y.tab.c"
    break;

  case 62:
#line 256 "part3.y"
                         {(yyval.node)=mknode("<",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2105 "y.tab.c"
    break;

  case 63:
#line 258 "part3.y"
                        {(yyval.node)=mknode("&&",(yyvsp[-2].node),(yyvsp[0].node)); addCode((yyvsp[-2].node),NULL,NULL,NULL,freshLabel(),NULL); }
#line 2111 "y.tab.c"
    break;

  case 64:
#line 259 "part3.y"
                       {(yyval.node)=mknode("||",(yyvsp[-2].node),(yyvsp[0].node)); addCode((yyvsp[-2].node),NULL,NULL,NULL,NULL,freshLabel());  }
#line 2117 "y.tab.c"
    break;

  case 65:
#line 261 "part3.y"
                         {(yyval.node)=mknode("+",(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2123 "y.tab.c"
    break;

  case 66:
#line 262 "part3.y"
                          {(yyval.node)=mknode("-",(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2129 "y.tab.c"
    break;

  case 67:
#line 263 "part3.y"
                          {(yyval.node)=mknode("*",(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2135 "y.tab.c"
    break;

  case 68:
#line 264 "part3.y"
                             {(yyval.node)=mknode("/",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2141 "y.tab.c"
    break;

  case 69:
#line 265 "part3.y"
                   {(yyval.node)=mknode("!",(yyvsp[0].node),NULL);}
#line 2147 "y.tab.c"
    break;

  case 70:
#line 266 "part3.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 2153 "y.tab.c"
    break;

  case 71:
#line 267 "part3.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 2159 "y.tab.c"
    break;

  case 72:
#line 268 "part3.y"
                          {(yyval.node)=(yyvsp[-1].node);}
#line 2165 "y.tab.c"
    break;

  case 73:
#line 269 "part3.y"
                      {(yyval.node)=mknode((yyvsp[0].string),mknode("INT",NULL,NULL),NULL);}
#line 2171 "y.tab.c"
    break;

  case 74:
#line 270 "part3.y"
                  {(yyval.node)=mknode((yyvsp[0].string),mknode("HEX", NULL, NULL),NULL);}
#line 2177 "y.tab.c"
    break;

  case 75:
#line 271 "part3.y"
                   {(yyval.node)=mknode((yyvsp[0].string),mknode("CHAR", NULL, NULL),NULL);}
#line 2183 "y.tab.c"
    break;

  case 76:
#line 272 "part3.y"
                   {(yyval.node)=mknode((yyvsp[0].string),mknode("REAL", NULL, NULL),NULL);}
#line 2189 "y.tab.c"
    break;

  case 77:
#line 273 "part3.y"
                     {(yyval.node)=mknode((yyvsp[0].string),mknode("STRING", NULL, NULL),NULL);}
#line 2195 "y.tab.c"
    break;

  case 78:
#line 274 "part3.y"
                    {(yyval.node)=mknode((yyvsp[0].string),mknode("BOOLEAN", NULL, NULL),NULL);}
#line 2201 "y.tab.c"
    break;

  case 79:
#line 275 "part3.y"
                   {(yyval.node)=mknode((yyvsp[0].string),mknode("BOOLEAN", NULL, NULL),NULL); }
#line 2207 "y.tab.c"
    break;

  case 80:
#line 277 "part3.y"
        {
		(yyval.node)=mknode("|",
		mknode((yyvsp[-1].string),NULL,NULL),
		mknode("|",NULL,NULL));
	}
#line 2217 "y.tab.c"
    break;

  case 81:
#line 283 "part3.y"
        {(yyval.node)=mknode("solovar",mknode((yyvsp[-3].string),mknode("[",(yyvsp[-1].node),mknode("]",NULL,NULL)),NULL),NULL);}
#line 2223 "y.tab.c"
    break;

  case 82:
#line 284 "part3.y"
                     {(yyval.node)=mknode("solovar",mknode((yyvsp[0].string),NULL,NULL),NULL);}
#line 2229 "y.tab.c"
    break;

  case 83:
#line 285 "part3.y"
                {(yyval.node)=mknode("null",NULL,NULL);}
#line 2235 "y.tab.c"
    break;

  case 84:
#line 287 "part3.y"
                                 {(yyval.node)=mknode("&",mknode((yyvsp[0].string),NULL,NULL),NULL);}
#line 2241 "y.tab.c"
    break;

  case 85:
#line 288 "part3.y"
                                                  {(yyval.node)=mknode("&",mknode("(",mknode((yyvsp[-1].string),NULL,NULL),NULL),mknode(")",NULL,NULL));}
#line 2247 "y.tab.c"
    break;

  case 86:
#line 290 "part3.y"
        {(yyval.node)=mknode("&", mknode((yyvsp[-3].string),mknode("[",(yyvsp[-1].node),mknode("]",NULL,NULL)),NULL),NULL);
	}
#line 2254 "y.tab.c"
    break;

  case 87:
#line 293 "part3.y"
        {
		(yyval.node)=mknode("&",
		mknode("(", 
		mknode((yyvsp[-4].string),mknode("[",(yyvsp[-2].node),mknode("]",NULL,NULL)),NULL)
		,mknode(")",NULL,NULL)),NULL);
	}
#line 2265 "y.tab.c"
    break;

  case 88:
#line 300 "part3.y"
                                       {(yyval.node)=mknode("^",mknode((yyvsp[0].string),NULL,NULL),NULL);addCode((yyval.node),"",mystrcat("*",(yyvsp[0].string)),NULL,NULL,NULL);}
#line 2271 "y.tab.c"
    break;

  case 89:
#line 301 "part3.y"
                                               {(yyval.node)=mknode("^",mknode("(",(yyvsp[-1].node),NULL),mknode(")",NULL,NULL));addCode((yyval.node),(yyvsp[-1].node)->code,mystrcat("*",(yyvsp[-1].node)->var),NULL,NULL,NULL);}
#line 2277 "y.tab.c"
    break;

  case 90:
#line 303 "part3.y"
        {(yyval.node)=mknode((yyvsp[-4].string), mknode((yyvsp[-3].string),mknode("[",(yyvsp[-1].node),mknode("]",NULL,NULL)),NULL), NULL);
	}
#line 2284 "y.tab.c"
    break;

  case 91:
#line 307 "part3.y"
                                {(yyval.node)=mknode("expr_list",(yyvsp[-2].node),mknode(",",(yyvsp[0].node),NULL));}
#line 2290 "y.tab.c"
    break;

  case 92:
#line 308 "part3.y"
               {(yyval.node)=mknode("expr_list",(yyvsp[0].node),NULL);}
#line 2296 "y.tab.c"
    break;

  case 93:
#line 309 "part3.y"
          {(yyval.node)=NULL;}
#line 2302 "y.tab.c"
    break;

  case 94:
#line 311 "part3.y"
                                          {(yyval.node)=(yyvsp[-1].node);}
#line 2308 "y.tab.c"
    break;

  case 95:
#line 313 "part3.y"
                                 {(yyval.node)=mknode("Call func",mknode((yyvsp[-1].string),NULL,NULL),mknode("ARGS",(yyvsp[0].node),NULL)); 

}
#line 2316 "y.tab.c"
    break;


#line 2320 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 316 "part3.y"

	#include "lex.yy.c"
int main()
{
	FILE * f=fopen("out3AC.txt","w+");
	int x= yyparse();
	if(x==0)
	{
		printf("Code Valid\n");
	}
	fprintf(f,"%s",firstNode->code);
	printf("%s",firstNode->code);
	return x;
	
}

Arguments * callfuncargs(code * CODEscope,node *tree,int * count)
{
	Arguments  *arr=NULL,ar[50];
	char* type,*len;
	while(tree!=NULL)
	{
		ar[(*count)++].type=exprtype(tree->left,CODEscope);
		if(tree->right!=NULL)
			tree=tree->right->left;
		else
			tree=NULL;
	}
	arr=(Arguments*)malloc(sizeof(Arguments)*(*count));
	for(int i=0;i<*count;i++)
		arr[i].type=ar[i].type;
	return arr;
}
char* findfunc(node * tree,code * CODEscope,int * countParams)
{
	code*temp=CODEscope;
	Arguments* args;
	int find=false,flag=true;
	while(temp!=NULL)
	{
		for(int i=0;i<temp->countfunc;i++)
		if(strcmp(tree->left->token,temp->func[i]->name)==0)
		{
			find=true;
			flag=true;
			int count=0;
			args=callfuncargs(CODEscope,tree->right->left,&count);
			if(count==temp->func[i]->countArgs)
			{
				for(int j=0,t=count-1;j<count;j++,t--)
				{
					if(strcmp(args[j].type,temp->func[i]->args[t].type)!=0)
						flag=false;
				}
				if(flag==true){
					if(countParams!= NULL)
						*countParams = POPParams(args,count);
					return temp->func[i]->returnType;
				}
			}
		}
		temp=temp->beforeLVL;
	}
	printf("Semantic ERORR\nCannot use Function [%s] before it has been declared in scope %s in func/proc %s\n",tree->left->token,CODEscope->name,mycode->func[mycode->countfunc-1]->name);
	if(find==true)
		printf("Function has been found but with other args type \n");
		exit(1);
}
char *findvar(node * tree,code * CODEscope)
{
	code*temp=CODEscope;
	if(strcmp(tree->token,"solovar")==0)
		tree=tree->left;
	while(temp!=NULL)
	{
		for(int i=0;i<temp->countvar;i++)
		if(strcmp(tree->token,temp->var[i].name)==0)
		{
			if(tree->left!=NULL && strcmp(tree->left->token,"[")==0)
			{
				if(strcmp(temp->var[i].type,"string")==0)
					if(strcmp(exprtype(tree->left->left,CODEscope),"int")==0)
					{
						return "char";
					}
					else
					{
						printf("Semantic Error\nindex can be only type of integer Format(<string>[<int>]) in func/proc [%s]\n",mycode->func[mycode->countfunc-1]->name);
						exit(1);
					}
				else
				{
					printf("Semantic Error\n[] operation can be only applied on string Format (<string>[<int>]) in func/proc %s\n",mycode->func[mycode->countfunc-1]->name);
					exit(1);
				}
			}
			else
			return temp->var[i].type;
		}
		temp=temp->beforeLVL;
	}
	printf("Semantic Error\nusing variable %s not found in func/proc %s\nor it has been used before declaring it\n",tree->token,mycode->func[mycode->countfunc-1]->name);
	exit(1);
	
}
char * exprtype(node * tree,code* CODEscope){
	char* msg=(char*)malloc(sizeof(char)*7);
	msg="";
	if(strcmp(tree->token,"null")==0)
		msg="NULL";
	else
	if(tree->left!=NULL){
		if(strcmp(tree->left->token,"INT")==0)
			msg= "int";
		if(strcmp(tree->left->token,"HEX")==0)
			msg= "hex";
		if(strcmp(tree->left->token,"CHAR")==0)
			msg= "char";
		if(strcmp(tree->left->token,"REAL")==0)
			msg= "real";
		if(strcmp(tree->left->token,"STRING")==0)
			msg= "string";
		if(strcmp(tree->left->token,"BOOLEAN")==0)
			msg= "boolean";
		if(strcmp(tree->token,"!")==0)
		if(strcmp(exprtype(tree->left,CODEscope),"boolean")==0)
			msg="boolean";
		else{
			printf("Semantic Error\nOperation ! can be applied only on bool data type\n");
			exit(1);
		}
		if(strcmp(tree->token,"|")==0)
		if(strcmp(exprtype(tree->left,CODEscope),"string")==0)
		msg="int";
		else{
			printf("Semantic Error\nOperation Length [||] can be only applied to string types in func/proc [%s]\n",mycode->func[mycode->countfunc-1]->name);
			exit(1);
		}
		if(strcmp(tree->token,"==")==0||strcmp(tree->token,"!=")==0){
			if(strcmp(exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope))==0&&strcmp(exprtype(tree->right,CODEscope),"string")!=0)
			msg="boolean";
			else{
				printf("Semantic Error\nOperation [%s] can be applied only on similar data types <bool>,<int>,<real>,<char>\n",tree->token);
				exit(1);
			}
		}
		if(strcmp(tree->token,">=")==0||strcmp(tree->token,">")==0||strcmp(tree->token,"<=")==0||strcmp(tree->token,"<")==0)
		{
			if((strcmp(exprtype(tree->left,CODEscope),"int")==0||strcmp(exprtype(tree->left,CODEscope),"real")==0)&&(strcmp(exprtype(tree->right,CODEscope),"int")==0||strcmp(exprtype(tree->right,CODEscope),"real")==0))
			msg="boolean";
			else{
				printf("Semantic Error\nOperation [%s] can only be applied on ,<int>,<real>\n",tree->token);
				exit(1);
			}
		}
		if(strcmp(tree->token,"&&")==0||strcmp(tree->token,"||")==0){
			if(strcmp(exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope))==0&&strcmp(exprtype(tree->right,CODEscope),"boolean")==0)
			msg="boolean";
			else{
			printf("Semantic Error\ncan't apply [%s] between [%s] and [%s] in func/proc [%s]\n",tree->token,exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope),mycode->func[mycode->countfunc-1]->name);
				exit(1);
			}
		}
		if(strcmp(tree->token,"-")==0||strcmp(tree->token,"+")==0)
		{
			if((strcmp(exprtype(tree->left,CODEscope),"int")==0||strcmp(exprtype(tree->left,CODEscope),"real")==0)&&(strcmp(exprtype(tree->right,CODEscope),"int")==0||strcmp(exprtype(tree->right,CODEscope),"real")==0))
			{
			if(strcmp(exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope))==0&&strcmp(exprtype(tree->left,CODEscope),"int")==0)
			msg="int";
			else
			msg="real";
			}
			if(strcmp(exprtype(tree->right,CODEscope),"int")==0&&(strcmp(exprtype(tree->left,CODEscope),"char*")==0||strcmp(exprtype(tree->right,CODEscope),"int*")==0||strcmp(exprtype(tree->right,CODEscope),"real*")==0)){
				msg=exprtype(tree->left,CODEscope);
			}
			else if(strcmp(msg,"")==0)
			{
				printf("Semantic Error\nOperation [%s] is only applied to <int>,<real>\n",tree->token);
				exit(1);
			}
		}
		if(strcmp(tree->token,"*")==0||strcmp(tree->token,"/")==0){
			if((strcmp(exprtype(tree->left,CODEscope),"int")==0||strcmp(exprtype(tree->left,CODEscope),"real")==0)&&(strcmp(exprtype(tree->right,CODEscope),"int")==0||strcmp(exprtype(tree->right,CODEscope),"real")==0)){
			if(strcmp(exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope))==0&&strcmp(exprtype(tree->left,CODEscope),"int")==0)
			msg="int";
			else
			msg="real";
			}
			else
			{
				printf("Semantic Error\nOperation [%s] is only applied to <int>,<real>\n",tree->token);
				exit(1);
			}
		}
		if(strcmp(tree->token,"&")==0){
			if(strcmp(tree->left->token,"(")==0)
				msg=exprtype(tree->left->left,CODEscope);
			else{
				msg=exprtype(tree->left,CODEscope);
				}
			if(strcmp(msg,"char")==0)
			msg="char*";
			else
			if(strcmp(msg,"int")==0)
			msg="int*";
			else
			if(strcmp(msg,"real")==0)
			msg="real*";
			else
			{
				printf("Semantic Error\nOperation [%s] can be applied only to <int>,<real>,<char>,<string>[<int>]\n",tree->token);
				exit(1);
			}
		}
		if(strcmp(tree->token,"^")==0){
			if(strcmp(tree->left->token,"(")==0)
				msg=exprtype(tree->left->left,CODEscope);
			else
				msg=exprtype(tree->left,CODEscope);
			
			if(strcmp(msg,"char*")==0)
			msg="char";
			else
			if(strcmp(msg,"int*")==0)
			msg="int";
			else
			if(strcmp(msg,"real*")==0)
			msg="real";
			else
			{
				printf("Semantic Error\n[%s] can be applied only on pointers\n",tree->token);
				exit(1);
			}
		}
		if(strcmp(tree->token,"(")==0)
			msg=exprtype(tree->left,CODEscope);
		if(strcmp(tree->token,"Call func")==0)
			msg=findfunc(tree,CODEscope,NULL);
	}
	if(strcmp(msg,"")==0)
		msg=findvar(tree,CODEscope);
	return msg;
}
void push(code* from,char* name){
	code * point;
	if(mycode==NULL)
		mycode=mkcode(name);
	else{
	point=mycode;
	while(point->nextLVL!=NULL)
		point=point->nextLVL;
	point->nextLVL=mkcode(name);
	point->nextLVL->beforeLVL=from;
	}
}

code* mkcode(char* name)
{	
	code *newlvl = (code*)malloc(sizeof(code));
	newlvl->place=++scope;
	newlvl->name=name;
	newlvl->var=NULL;
	newlvl->countvar=0;
	newlvl->func=NULL;
	newlvl->countfunc=0;
	newlvl->nextLVL=NULL;
	newlvl->beforeLVL=NULL;
	return newlvl;
}

void addvar(Arguments * args,int countvars,int isArg,code * CODEscope){
	if(countvars==0)
	return;
	Varaiable* temp;
	code * codey=CODEscope;
	for(int i=0;i<countvars;i++)
		for(int j=0;j<countvars;j++)
	if(i!=j && strcmp(args[j].name,args[i].name)==0 ){
		printf("Can't declare variables mory than one time [%s]\n",args[i].name);
		code * t=codey->beforeLVL;
		while(t->beforeLVL!=NULL && t->beforeLVL->countfunc==0)
			t=t->beforeLVL;
		if(t->func!=NULL)
		printf(",in func %s\n",t->func[t->countfunc-1]->name);
			else
		printf("\n");
		exit(1);
	}
	if(codey->var==NULL){ 
		codey->var=(Varaiable*) malloc(sizeof(Varaiable)*countvars);
	}
	else
	{
		temp=codey->var;
		codey->var=(Varaiable*) malloc(sizeof(Varaiable)*(codey->countvar+countvars));
		for(int i=0;i<codey->countvar;i++){
			for(int j=0;j<countvars;j++){
				if(strcmp(temp[i].name,args[j].name)==0 ){
					printf("Semantic Error\ncan't declare var [%s] in the same scope more than one time",temp[i].name);
					code * t=codey->beforeLVL;
					while(t->beforeLVL!=NULL && t->beforeLVL->countfunc==0)
						t=t->beforeLVL;
					if(t->func!=NULL)
					printf(",in func %s\n",t->func[t->countfunc-1]->name);
					else
					printf("\n");
					exit(1);
				}
			}
			codey->var[i]=temp[i];	
		}
	}
	for(int j=0;j<countvars;j++){
		codey->var[codey->countvar].name=args[j].name;
		codey->var[codey->countvar].value=NULL;
		codey->var[codey->countvar].isArg=isArg;
		codey->var[codey->countvar].len=args[j].len;
		codey->var[(codey->countvar)++].type=args[j].type;
	}
}

void addFunc(char * name,Arguments * args,node *returnType,int countArgs,code * CODEscope){
	Function** temp;
	code * codey=CODEscope;
	for(int i=0;i<countArgs;i++)
		for(int j=0;j<countArgs;j++)
	if(i!=j && strcmp(args[j].name,args[i].name)==0 )
	{
		printf("Can't declare variable [%s] more that one time in func [%s]\n",args[i].name,name);
		exit(1);
	}
	if(codey->func==NULL)
	{ 
		codey->func=(Function**) malloc(sizeof(Function*));
	}
	else
	{
		temp=codey->func;
		codey->func=(Function**) malloc(sizeof(Function*)*(codey->countfunc+1));
		for(int i=0;i<codey->countfunc;i++)
		{
				if(strcmp(temp[i]->name,name)==0 )
				{
					printf("Semantic Error\ncan't declare function [%s] more than one time in the same scope \n",temp[i]->name);
					exit(1);
				}
				codey->func[i]=temp[i];
		}
	}
		codey->func[codey->countfunc]=(Function*) malloc(sizeof(Function));
		codey->func[codey->countfunc]->name=name;
		codey->func[codey->countfunc]->args=args;
		if(returnType==NULL)
		codey->func[codey->countfunc]->returnType=NULL;
		else{
		if(strcmp(returnType->token,"string")==0)
			{
				printf("Semantic Error\nFunction [%s] can't return string data type\n",name);
				exit(1);
			}
		codey->func[codey->countfunc]->returnType=returnType->token;
		}
		codey->func[codey->countfunc]->countArgs=countArgs;
		codey->func[codey->countfunc]->findreturn=false;
		++(codey->countfunc);
}

Arguments * mkArgs(node *tree,int *count){
	Arguments  *arr=NULL,ar[50];
	char* type,*len;
	if(tree!=NULL)
	{
		node * temp1=tree,*temp=tree;
		do{
		if(strcmp(temp1->token, "")==0)
		{
			temp=temp1->right->left;
			temp1=temp1->left;
			
			
			if(strcmp(temp->token, "(")==0||strcmp(temp->token, "var")==0)
		{
			type=temp->left->token;
			if(temp->left->left!=NULL)
			len=temp->left->left->left->token;
			node * treee;
			treee=temp->right->left;
			do{
			ar[*count].name=treee->token;
			ar[*count].type=type;
			ar[*count].len=len;
			(*count)++;
			if(treee->left==NULL)
				treee=NULL;
			else
				treee=treee->left->left;
			}while(treee!=NULL);
		}
		}
		}while(strcmp(temp1->token, "(")!=0&&strcmp(temp->token, "var")!=0);
		temp=temp1;
		if(strcmp(temp->token, "(")==0||strcmp(temp->token, "var")==0)
		{
			type=temp->left->token;
			node * treee;
			if(strcmp(temp->token, "var")==0)
			treee=temp->right;
			else
			treee=temp->right->left;
			if(temp->left->left!=NULL)
			len=temp->left->left->left->token;
			do{
			ar[*count].name=treee->token;
			ar[*count].type=type;
			ar[*count].len=len;
			(*count)++;
			if(treee->left==NULL)
				treee=NULL;
			else
				treee=treee->left->left;
			}while(treee!=NULL);
		}
		arr=(Arguments*)malloc(sizeof(Arguments)*(*count));
		for(int i=0;i<*count;i++)
		{
			for(int j=0;j<*count;j++){
			}
			arr[i].name=ar[i].name;
			arr[i].type=ar[i].type;
		}
	}
	return arr;
}

node* mknode (char *token, node *left, node *right)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->left=left;
	newnode->right=right;
	newnode->token=token;
	newnode->code=NULL;
	newnode->var=NULL;
	newnode->label=NULL;
	newnode->truelabel=NULL;
	newnode->falselabel=NULL;
    newnode->sum=0;
	return newnode;
}

int yyerror(char *e)
{
	int yydebug=1; 
	fflush(stdout);
	fprintf(stderr,"Error %s at line %d\n" ,e,yylineno);
	fprintf(stderr, "does not accept '%s'\n",yytext);
	exit(0);
	return 0;
}
code* lestcode(code * codey)
{
	code * CODEscope=codey;
	if(CODEscope!=NULL)
	while(CODEscope->nextLVL!=NULL)
		CODEscope=CODEscope->nextLVL;
	return CODEscope;
}

void syntaxMKscope(node *tree,code * CODEscope){
	if(strcmp(tree->token, "=") == 0 ){
		if(!(strcmp(exprtype(tree->right,CODEscope),"NULL")==0&& (strcmp(exprtype(tree->left,CODEscope),"real*")==0||strcmp(exprtype(tree->left,CODEscope),"int*")==0||strcmp(exprtype(tree->left,CODEscope),"char*")==0)))
		if(strcmp(exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope))!=0)
		{
			printf("Semntic Error\nCannot assign [%s] to [%s] in func/proc %s\n",exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope),mycode->func[mycode->countfunc-1]->name);
			exit(1);
		}
	}
	else if(strcmp(tree->token, "var") == 0)
	{
		int countvar=0;
		Arguments * var=mkArgs(tree,&countvar);
		addvar(var,countvar,0,CODEscope);
	}
	else if(strcmp(tree->token, "if") == 0)
	{
		if(strcmp(exprtype(tree->left->left,CODEscope),"boolean")!=0)
		{
			printf("Semantic Error\nIF condition must be of kind boolean\n");
			exit(1);
		}
		if(strcmp(tree->right->token,"{")!=0)
		{
			push(CODEscope,tree->token);
			if (tree->left) 
				syntaxMKscope(tree->left,lestcode( CODEscope->nextLVL));
			if (tree->right)
				syntaxMKscope(tree->right,lestcode( CODEscope->nextLVL));
        	scope--;
			return;
		}	
	}
		else if(strcmp(tree->token, "while") == 0)
	{
		if(strcmp(exprtype(tree->left->left,CODEscope),"boolean")!=0)
		{
printf("Semantic Error\nWhile Condition must be a boolean expreession\n");
			exit(1);
		}
		if(strcmp(tree->right->token,"{")!=0)
		{
			push(CODEscope,tree->token);
			if (tree->left) 
				syntaxMKscope(tree->left,lestcode( CODEscope->nextLVL));
			if (tree->right)
				syntaxMKscope(tree->right,lestcode( CODEscope->nextLVL));
        	scope--;
			return;
		}
	}
	else if(strcmp(tree->token, "FUNC") == 0 )
	{
        int count=0;
		Arguments * arg=mkArgs(tree->left->right->left,&count);
		addFunc(tree->left->token,arg,tree->left->right->right->left,count,CODEscope);
		push(CODEscope,tree->token);
		addvar(arg,count,1,lestcode(CODEscope));
	if (tree->left) 
		syntaxMKscope(tree->left,lestcode( CODEscope->nextLVL));
	
	if (tree->right)
		syntaxMKscope(tree->right,lestcode( CODEscope->nextLVL));
		if(CODEscope->func[CODEscope->countfunc-1]->findreturn==false)
		{
			printf("Semantic Error\nFunction [%s] must return a value\n",tree->left->token);
			exit(1);
		}
        scope--;		
		return;
	}
    else if(strcmp(tree->token, "PROC") == 0)
	{
		
        int count=0;
		Arguments * arg=mkArgs(tree->right->left,&count);
		addFunc(tree->left->token,arg,NULL,count,CODEscope);
		push(CODEscope,tree->token);
		addvar(arg,count,1,lestcode(CODEscope));
	if (tree->left) 
		syntaxMKscope(tree->left,lestcode( CODEscope->nextLVL));
	
	if (tree->right)
		syntaxMKscope(tree->right,lestcode( CODEscope->nextLVL));
		scope--;	
		return;
    }
	else if(strcmp(tree->token, "Call func") == 0)
	{
		int count=0;
		findfunc(tree,CODEscope,&count);
		tree->sum=count;
	  }
	else if(strcmp(tree->token, "CODE") == 0)
	{
		push(NULL,tree->token);
	if (tree->left) 
		syntaxMKscope(tree->left,mycode);
	
	if (tree->right)
		syntaxMKscope(tree->right,mycode);
		scope--;
		return;
	}
    else if(strcmp(tree->token, "Main") == 0)
	{
		if(flagMain==true && strcmp(CODEscope->name,"CODE")==0)
		{
			printf("Main can't be in function/procedure\n");
			exit(1);
		}
		flagMain=true;
		addFunc(tree->token,NULL,NULL,0,CODEscope);
		push(CODEscope,tree->token);
	if (tree->left) 
		syntaxMKscope(tree->left,lestcode( CODEscope->nextLVL));
	if (tree->right)
		syntaxMKscope(tree->right,lestcode( CODEscope->nextLVL));
        scope--;
		return;
    }       
	else if(strcmp(tree->token, "if-else") == 0)
	{
		if(strcmp(exprtype(tree->left->left,CODEscope),"boolean")!=0)
		{
			printf("Semantic Error\nIF condition must be of kind boolean\n");
			exit(1);
		}

		if(strcmp(tree->right->left->token,"{")!=0)
		{
			push(CODEscope,tree->token);
			syntaxMKscope(tree->right->left,lestcode( CODEscope->nextLVL));
			scope--;
			push(CODEscope,tree->token);
			syntaxMKscope(tree->right->right->left,lestcode( CODEscope->nextLVL));
        	scope--;
			return;
		}
	}
	else if(strcmp(tree->token, "return") == 0)
	{
		code * temp= CODEscope;
		int flag=true;
		while(strcmp(temp->name,"FUNC")!=0&&strcmp(temp->name,"PROC")!=0&&strcmp(temp->name,"CODE")!=0)
		{
			temp=temp->beforeLVL;
			flag=false;
		}
		if(flag==false)
		{
			if(strcmp(exprtype(tree->left,CODEscope),temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->returnType))
			{
			printf("ERORR,return no some type in func %s \n",temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->name);
			printf("%s ,%s %s\n",exprtype(tree->left,CODEscope),temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->returnType,temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->name);
			exit(1);
			}
		}
		else{
		if(temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->returnType!=NULL){
		if(0==strcmp(exprtype(tree->left,CODEscope),temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->returnType)){
			temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->findreturn=true;
		}
		else{
			printf("Semantic Error\nreturn type is not as declared in Function [%s] \n",temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->name);
		    	printf("returned [%s] supposed to be [%s] Function [%s]\n",exprtype(tree->left,CODEscope),temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->returnType,temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->name);
			exit(1);
		}
		}
		else
		{
			printf("Semantic Error\nProcedure cannot have return type [%s]\n",temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->name);
			exit(1);
		}  
		}
	}
	else if(strcmp(tree->token, "{") == 0)
	{
    push(CODEscope,tree->token);
	if (tree->left) 
		syntaxMKscope(tree->left,lestcode( CODEscope->nextLVL));
	if (tree->right)
		syntaxMKscope(tree->right,lestcode( CODEscope->nextLVL));
        scope--;
		return;				
	}
	else if(strcmp(tree->token, "solovar") == 0 )
	{
		findvar(tree->left,CODEscope);
	}
	if (tree->left) 
		syntaxMKscope(tree->left,CODEscope);
	
	if (tree->right)
		syntaxMKscope(tree->right,CODEscope);
}

int POPParams(Arguments * args,int count){
	int size=0;
	for(int i =0;i<count;i++)
	{
		if(strcmp(args[i].type,"int")==0)
			size += 4;
		else if(strcmp(args[i].type,"char")==0)
			size += 1;
		else if(strcmp(args[i].type,"real")==0)
			size += 8;
		else if(strcmp(args[i].type,"string")==0)
			size += atoi(args[i].len);
		else if(strcmp(args[i].type,"boolean")==0)
			size += 4;
		else if(strcmp(args[i].type,"int*")==0)
			size += 4;
		else if(strcmp(args[i].type,"char*")==0)
			size += 4;
		else if(strcmp(args[i].type,"real*")==0)
			size += 4;
	}
	return size;
}

void addCode(node* node,char *code,char *var,char *label,char *truelabel,char *falselabel){
		if(code!=NULL){
		node->code=(char*)malloc(sizeof(char)*(1+strlen(code)));
		strcpy(node->code,code);
		}
		else if(node->code==NULL)
		{
		node->code=(char*)malloc(sizeof(char)*2);
		strcpy(node->code,"");
		}
		if(var!=NULL){
		node->var=(char*)malloc(sizeof(char)*(1+strlen(var)));
		strcpy(node->var,var);
		}
		else if(node->var==NULL)
		{
		node->var=(char*)malloc(sizeof(char)*2);
		strcpy(node->var,"");
		}
		if(label!=NULL&& node->label==NULL){
		node->label=(char*)malloc(sizeof(char)*(1+strlen(label)));
		strcpy(node->label,label);
		}
		if(truelabel!=NULL && node->truelabel==NULL){
		node->truelabel=(char*)malloc(sizeof(char)*(1+strlen(truelabel)));
		strcpy(node->truelabel,truelabel);
		}
		if(falselabel!=NULL && node->falselabel==NULL){
		node->falselabel=(char*)malloc(sizeof(char)*(1+strlen(falselabel)));
		strcpy(node->falselabel,falselabel);
		}
	}
void addCode2(node* node,char *code,char *var,char *label,char *truelabel,char *falselabel)
	{
		if(code!=NULL){
		node->code=(char*)malloc(sizeof(char)*(1+strlen(code)));
		strcpy(node->code,code);
		}
		else if(node->code==NULL)
		{
		node->code=(char*)malloc(sizeof(char)*2);
		strcpy(node->code,"");
		}

		if(var!=NULL){
		node->var=(char*)malloc(sizeof(char)*(1+strlen(var)));
		strcpy(node->var,var);
		}
		else if(node->var==NULL)
		{
		node->var=(char*)malloc(sizeof(char)*2);
		strcpy(node->var,"");
		}

		if(label!=NULL){
		node->label=(char*)malloc(sizeof(char)*(1+strlen(label)));
		strcpy(node->label,label);
		}

		if(truelabel!=NULL){
		node->truelabel=(char*)malloc(sizeof(char)*(1+strlen(truelabel)));
		strcpy(node->truelabel,truelabel);
		}
		
		if(falselabel!=NULL && node->falselabel==NULL){
		node->falselabel=(char*)malloc(sizeof(char)*(1+strlen(falselabel)));
		strcpy(node->falselabel,falselabel);
		}
	}
	char* freshVar(){
		char* x;
		asprintf(&x,"t%d",t++);
		return x;
	}
	char* freshLabel(){
		char* x;
		asprintf(&x,"L%d",++l);
		return x;
	}
	char* gen(char*s1,char*s2,char*s3,char*s4,char*s5)
	{
		char* x;
		asprintf(&x,"%s %s %s %s %s\n",s1,s2,s3,s4,s5);
		return x;
	}
char* mystrcat(char*des,char*src){
		char* tamp=des;
		char* num;
		asprintf(&num,"%d ",line++);
		if(src!=NULL){
			if(des==NULL){
				des=(char*)malloc((strlen(src)+1)*sizeof(char));
				strcpy(des,src);
				return des;
			}
		des=(char*)malloc((strlen(des)+strlen(src)+1+strlen(num))*sizeof(char));
		if(tamp!=NULL){
		strcat(des,tamp);
		}
		if(src!=NULL)
		{
		strcat(des,src);
		}
		}
		return des;
	}
char *replaceWord(const char *s, const char *oldW, const char *newW) 
{ 
    char *result; 
    int i, cnt = 0; 
    int newWlen = strlen(newW); 
    int oldWlen = strlen(oldW); 
    for (i=0;s[i]!='\0';i++) 
    { 
        if (strstr(&s[i],oldW) == &s[i]) 
        { 
            cnt++; 
            i += oldWlen-1; 
        } 
    } 
    result=(char*)malloc(i+cnt*(newWlen-oldWlen)+1); 
    i = 0; 
    while (*s) 
    { 
        if (strstr(s, oldW) == s) 
        { 
            strcpy(&result[i], newW); 
            i += newWlen; 
            s += oldWlen; 
        } 
        else
            result[i++] = *s++; 
    }
    result[i] = '\0'; 
    return result; 
} 

char * mkspace(char *label)
{
	char * msg;
	char x=' ';
	int len = strlen(mystrcat(label,"\0"));
	if(label==NULL || !strcmp(label,""))
		msg="";
	else
		{
		asprintf(&msg,"%c",x);
		while(len<5){
			asprintf(&msg,"%c%s",x,msg);
			len++;
		}
		asprintf(&label,"%s: ",mystrcat(label,"\0"));
		msg=mystrcat(msg,label);
		}
		return msg;
}

void calc3AC(node * tree)
{
	if(strcmp(tree->token, "=") == 0 )
	{ if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
	   addCode(tree,mystrcat(tree->right->code,gen(tree->left->var,"=",tree->right->var,"","")),NULL,NULL,NULL,NULL); 
	   return;  
	}
	else if(strcmp(tree->token, "if") == 0)
	{ 
		if(tree->left->left)
		addCode(tree->left->left,NULL,NULL,NULL,NULL,tree->label);
		if(tree->right)
		addCode2(tree->right,NULL,NULL,tree->label,NULL,NULL);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		addCode(tree,mystrcat(tree->left->left->code,mystrcat(mkspace(tree->left->left->label),mystrcat(mkspace(tree->left->left->truelabel),mystrcat(tree->right->code,mkspace(tree->truelabel))))),NULL,NULL,NULL,NULL);
		return;
	}
else if(strcmp(tree->token, "if-else") == 0)
	{ 
		if(tree->right->left)
		addCode(tree->right->left,NULL,NULL,tree->label,NULL,NULL);			
		if(tree->right->right->left)
		addCode2(tree->right->right->left,NULL,NULL,tree->label,NULL,tree->label);
		if(tree->right->left)
		addCode2(tree->right->left,NULL,NULL,tree->label,NULL,tree->label);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		addCode(tree,mystrcat(mystrcat(tree->left->left->code,mystrcat(mkspace(tree->left->left->truelabel),tree->right->left->code))
		,mystrcat(mystrcat("goto ",mystrcat(mystrcat(tree->label,"\n"),mystrcat(mkspace(tree->left->left->falselabel),tree->right->right->left->code))),mkspace(tree->label))),NULL,NULL,NULL,NULL);
	return;
	}
	else if(strcmp(tree->token, "while") == 0)
	{ 
		if(tree->left->left)
			addCode(tree->left->left,NULL,NULL,NULL,tree->falselabel,tree->label);
		if(tree->right)
			addCode2(tree->right,NULL,NULL,tree->label,NULL,NULL);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			addCode(tree,mystrcat(mystrcat(mystrcat( mkspace(tree->truelabel),tree->left->left->code),mkspace(tree->falselabel)),
				mystrcat(tree->right->code,mystrcat(mystrcat("\tgoto ",mystrcat(tree->truelabel,"\n")),mkspace(tree->label)))),NULL,NULL,NULL,NULL);
		return ;
	}
	else if(strcmp(tree->token, "stmnts") == 0)
	{ 
		if(tree->right!=NULL)
			if(strcmp(tree->right->token, "if-else") == 0||strcmp(tree->right->token, "while") == 0)
				addCode2(tree->right,NULL,NULL,tree->label,NULL,NULL);
        if(tree->right!=NULL && tree->left!=NULL)
        if(strcmp(tree->left->right->token, "if") == 0||strcmp(tree->left->right->token, "if-else") == 0||strcmp(tree->left->right->token, "while") == 0)
				addCode2(tree->right,NULL,NULL,NULL,tree->left->right->label,NULL);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			if(tree->right!=NULL && tree->left!=NULL)
                if((strcmp(tree->right->token, "while") == 0||strcmp(tree->right->token, "if-else") == 0)&&(strcmp(tree->left->right->token, "if") == 0||strcmp(tree->left->right->token, "if-else") == 0||strcmp(tree->left->right->token, "while") == 0))
                    addCode(tree,mystrcat(tree->left->code,&tree->right->code[8]),NULL,NULL,NULL,NULL);
                    else
					addCode(tree,mystrcat(tree->left->code,tree->right->code),NULL,NULL,NULL,NULL);
			else if(tree->right!=NULL)
            {
                if(strcmp(tree->right->token, "if-else") == 0||strcmp(tree->right->token, "while") == 0)
                    addCode(tree,tree->right->code,NULL,NULL,NULL,NULL);
                    else        
				    addCode(tree,mystrcat(tree->right->code ,mkspace(tree->right->label)),NULL,NULL,NULL,NULL);
            }else
				addCode(tree,"",NULL,NULL,NULL,NULL);	
	return;
	}
    else if(strcmp(tree->token, "PROC") == 0)
	{ if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
	 char*x; asprintf(&x," %s:\n",tree->left->token);addCode(tree,mystrcat(x,tree->right->right->code),NULL,NULL,NULL,NULL);
		return;
	}
	else if(strcmp(tree->token, "FUNC") == 0)
	{
		 if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
	 char*x; asprintf(&x," %s:\n",tree->left->token);addCode(tree,mystrcat(x,tree->right->left->code),NULL,NULL,NULL,NULL);
		return;
	}
		else if(strcmp(tree->token, "expr_list") == 0)
	{
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			if(tree->right==NULL)
				addCode(tree,mystrcat(tree->left->code,mystrcat("PushParam ",mystrcat(tree->left->var,"\n"))),NULL,NULL,NULL,NULL);
			else
				addCode(tree,mystrcat(mystrcat(tree->left->code,mystrcat("PushParam ",mystrcat(tree->left->var,"\n"))),tree->right->left->code),NULL,NULL,NULL,NULL);
	}	
	else if(strcmp(tree->token, "Call func") == 0)
	{ 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		char * x,*parm=(char*)malloc(sizeof(char));
		if(tree->right->left==NULL)
			strcpy(parm,"");
		else
			parm=tree->right->left->code;
		addCode(tree,NULL,freshVar(),NULL,NULL,NULL);
		asprintf(&x,"%s%s = LCALL %s\n‪\tPopParams %d‬‬‬‬\n",parm,tree->var,tree->left->token,tree->sum);
		addCode(tree,x,NULL,NULL,NULL,NULL);
		return;
	}
	else if(strcmp(tree->token, "CODE") == 0)
	{ if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		 if(tree->left)
			addCode(tree,mystrcat(tree->left->code,tree->right->code),NULL,NULL,NULL,NULL);
		else
			addCode(tree,tree->right->code,NULL,NULL,NULL,NULL);
		tree->code=replaceWord(tree->code, "\n\n", "\n") ;
		char x='a',*y,*z;

		while (x<='z')
		{
			asprintf(&y,"\n%c",x);
			asprintf(&z,"\n\t%c",x);
			tree->code=replaceWord(tree->code, y, z) ;
			x++;
		}
		x='A';
				while (x<='Z')
		{
			asprintf(&y,"\n%c",x);
			asprintf(&z,"\n\t%c",x);
			tree->code=replaceWord(tree->code, y, z) ;
			x++;
		}
		return;
	}
    else if(strcmp(tree->token, "BODY") == 0)
	{ 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		if(tree->right->right->left){
		
		if(tree->right->right->left->code[strlen(mystrcat(tree->right->right->left->code,"\0"))-2]==':')
			addCode(tree,mystrcat(mystrcat("\tBeginFunc‬‬\n",tree->right->right->left->code),"EndFunc\n"),NULL,NULL,NULL,NULL);
		else
		    addCode(tree,mystrcat(mystrcat("\tBeginFunc‬‬\n",tree->right->right->left->code),"\tEndFunc\n"),NULL,NULL,NULL,NULL);
		}
		else		 addCode(tree,mystrcat("\tBeginFunc‬‬\n","\tEndFunc\n"),NULL,NULL,NULL,NULL);
		return;
	}
    else if(strcmp(tree->token, "Main") == 0)
	{ 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		
		addCode(tree,mystrcat(" Main:\n",tree->left->right->code),NULL,NULL,NULL,NULL);
          return;   
    } 
	    else if(strcmp(tree->token, "procedures") == 0)
	{ if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		if(tree->left!=NULL) addCode(tree,mystrcat(tree->left->code,tree->right->code),NULL,NULL,NULL,NULL);else addCode(tree,tree->right->code,NULL,NULL,NULL,NULL);
    return;
	}        

	else if(strcmp(tree->token, "return") == 0)
	{
		
		 if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);

		addCode(tree,mystrcat(tree->left->code,gen("return",tree->left->var,"","","")),NULL,NULL,NULL,NULL);
		return;
	}
	else if(strcmp(tree->token, "{") == 0)
	{ 
		if(tree->right->right->left) addCode(tree,NULL,NULL,tree->right->right->left->label,tree->right->right->left->truelabel,tree->right->right->left->falselabel); 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		if(tree->right->right->left) addCode(tree,tree->right->right->left->code,tree->right->right->left->var,NULL,NULL,NULL); 
		return;			
	}
	else if(strcmp(tree->token, "}") == 0)
	{ if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);           
    }
	else if(strcmp(tree->token, "assmnt_stmnt") == 0)
	{ if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
                     addCode(tree,tree->left->code,tree->left->var,tree->left->label,tree->left->truelabel,tree->left->falselabel); 
					 return;   
    }
	
    else if(strcmp(tree->token, "+") == 0 || 
            strcmp(tree->token, "*") == 0 || 
            strcmp(tree->token, "-") == 0 || 
            strcmp(tree->token, "/") == 0 )
	{
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		addCode(tree,NULL,freshVar(),NULL,NULL,NULL);
		addCode(tree,mystrcat(mystrcat(tree->left->code,tree->right->code),gen(tree->var,"=",tree->left->var,tree->token,tree->right->var)),NULL,NULL,NULL,NULL);
    return;}
    
	else if(strcmp(tree->token, "&") == 0)
	{ 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
				if((tree->left->left == NULL))
				addCode(tree,"",mystrcat("&",(tree->left->token)),NULL,NULL,NULL);
			else if(strcmp(tree->left->left->token,"[")==0)
					{
						char *x,*fv1,*fv2;
						asprintf(&fv1,"%s",freshVar()); 
						asprintf(&fv2,"%s",freshVar());
						asprintf(&x,"\t%s = &%s\n\t%s = %s + %s\n",fv1,tree->left->token,fv2,fv1,tree->left->left->left->var);
						addCode(tree,mystrcat(tree->left->left->left->code,x),fv2,NULL,NULL,NULL);
					}
				else if (tree->left->left->left==NULL)
				addCode(tree,"",mystrcat("&",(tree->left->left->token)),NULL,NULL,NULL);
			else
			{
				char *x,*fv1,*fv2;
				asprintf(&fv1,"%s",freshVar());
				asprintf(&fv2,"%s",freshVar()); 
				asprintf(&x,"\t%s = &%s\n\t%s = %s + %s\n",fv1,tree->left->left->token,fv2,fv1,tree->left->left->left->left->var); 
				addCode(tree,mystrcat(tree->left->left->left->left->code,x),fv2,NULL,NULL,NULL);
			}
	return;}
	else if(strcmp(tree->token, "^") == 0 )
	{ 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			if((tree->left->left == NULL))
				addCode(tree,"",mystrcat("*",(tree->left->token)),NULL,NULL,NULL);
			else
			{
				addCode(tree,"",mystrcat("*",(tree->left->left->token)),NULL,NULL,NULL);
			}
			
	return;}
	else if(strcmp(tree->token, "==") == 0 || 
			strcmp(tree->token, ">") == 0 || 
			strcmp(tree->token, ">=") == 0 || 
			strcmp(tree->token, "<") == 0 || 
			strcmp(tree->token, "<=") == 0 || 
			strcmp(tree->token, "!=") == 0) 
	{ 

		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			addCode(tree,mystrcat(mystrcat(tree->left->code,tree->right->code),mystrcat(gen("if",tree->left->var,tree->token,tree->right->var,mystrcat("goto ",mystrcat(tree->truelabel,"\n")))
				,mystrcat("\tgoto ",mystrcat(tree->falselabel,"\n")))),NULL,NULL,NULL,NULL);
	return;}
	else if(strcmp(tree->token, "(") == 0)
	{
			addCode(tree->left,NULL,NULL,NULL,tree->truelabel,tree->falselabel);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		addCode(tree,tree->left->code,tree->left->var,NULL,NULL,NULL);
	return;}
	else if(strcmp(tree->token, "!") == 0)
	{ 
		addCode(tree->left,NULL,NULL,NULL,tree->truelabel,tree->falselabel);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
				
		 addCode(tree,tree->left->code,NULL,NULL,NULL,NULL);
		
	return;}
	else if(strcmp(tree->token, "||") == 0) 
	{
		addCode(tree->left,NULL,NULL,NULL,tree->truelabel,NULL);
		addCode(tree->right,NULL,NULL,NULL,tree->truelabel,tree->falselabel);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		addCode(tree,mystrcat(tree->left->code,mystrcat(mkspace(tree->left->falselabel),tree->right->code)),NULL,NULL,NULL,NULL);
	return;}
	else if(strcmp(tree->token, "&&") == 0 )
	{
		
		addCode(tree->left,NULL,NULL,NULL,NULL,tree->falselabel);
		addCode(tree->right,NULL,NULL,NULL,tree->truelabel,tree->falselabel);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			addCode(tree,mystrcat(tree->left->code,mystrcat(mkspace(tree->left->truelabel),tree->right->code)),NULL,NULL,NULL,NULL);
	return;}
	else if(strcmp(tree->token, "null") == 0 )
	{ 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		addCode(tree,"",tree->token,NULL,NULL,NULL);
	return;}	
	else if(strcmp(tree->token, "solovar") == 0 )
	{ 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			if(tree->left->left==NULL)
				addCode(tree,"",tree->left->token,NULL,NULL,NULL);
			else
			{
				char *x,*fv1,*fv2; asprintf(&fv1,"%s",freshVar()); asprintf(&fv2,"%s",freshVar()); asprintf(&x,"\t%s = &%s\n\t%s = %s + %s\n",fv1,tree->left->token,fv2,fv1,tree->left->left->left->var); addCode(tree,mystrcat(tree->left->left->left->code,x),mystrcat("*",fv2),NULL,NULL,NULL);
			}	
	return;}
	else if((tree->left!=NULL)&&
			(strcmp(tree->left->token,"INT")==0||
			strcmp(tree->left->token,"HEX")==0||
			strcmp(tree->left->token,"CHAR")==0||
			strcmp(tree->left->token,"REAL")==0||
			strcmp(tree->left->token,"STRING")==0||
			strcmp(tree->left->token,"BOOLEAN")==0))
			{

			if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			if(strcmp(tree->left->token,"STRING")==0)
			addCode(tree,"",tree->token,NULL,NULL,NULL);
			else
			if(strcmp(tree->left->token,"BOOLEAN")==0)
			{
			if(strcmp(tree->token,"true")==0 && tree->truelabel!=NULL)	
			addCode(tree,mystrcat("goto ",mystrcat(tree->truelabel,"\n")),tree->token,NULL,NULL,NULL);
			else if(strcmp(tree->token,"false")==0 && tree->falselabel!=NULL)
			addCode(tree,mystrcat("goto ",mystrcat(tree->falselabel,"\n")),tree->token,NULL,NULL,NULL);
			else
			addCode(tree,tree->token,tree->token,NULL,NULL,NULL);
			}
			else
			addCode(tree,"",tree->token,NULL,NULL,NULL);
			return;}
	else if(strcmp(tree->token, "") == 0||strcmp(tree->token, " ") == 0)
	{
		if(tree->left)
		addCode(tree->left,NULL,NULL,tree->label,tree->truelabel,tree->falselabel);
		if(tree->right)
		addCode(tree->right,NULL,NULL,tree->label,tree->truelabel,tree->falselabel);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		if(tree->left && tree->right)
			addCode(tree,mystrcat(tree->left->code,tree->right->code),tree->right->var,NULL,NULL,NULL);
		else if(tree->left)
			addCode(tree,tree->left->code,tree->left->var,NULL,NULL,NULL);	
		else if(tree->right)
			addCode(tree,tree->right->code,tree->right->var,NULL,NULL,NULL);	
	return;
	}
	else
	{
	if (tree->left) 
		calc3AC(tree->left);
	if (tree->right)
		calc3AC(tree->right);
addCode(tree,"",tree->token,NULL,NULL,NULL);
	return;}
	if (tree->left) 
		calc3AC(tree->left);
	
	if (tree->right)
		calc3AC(tree->right);
}
