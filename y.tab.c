/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "jac.y" /* yacc.c:339  */

    #include <stdio.h>
	#include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"
//	#include "ast.h"
    int yylex(void);
	extern int num_line;
	extern int num_col;
	extern char * yytext;
	//extern Node * tree;
    void yyerror (const char *s);
	int flag=1;

#line 81 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    BOOL = 258,
    BOOLLIT = 259,
    CLASS = 260,
    DO = 261,
    DOTLENGTH = 262,
    DOUBLE = 263,
    ELSE = 264,
    IF = 265,
    INT = 266,
    PARSEINT = 267,
    PRINT = 268,
    PUBLIC = 269,
    RETURN = 270,
    STATIC = 271,
    STRING = 272,
    VOID = 273,
    WHILE = 274,
    OCURV = 275,
    CCURV = 276,
    OBRACE = 277,
    CBRACE = 278,
    OSQUARE = 279,
    CSQUARE = 280,
    AND = 281,
    OR = 282,
    LT = 283,
    GT = 284,
    EQ = 285,
    NEQ = 286,
    LEQ = 287,
    GEQ = 288,
    PLUS = 289,
    MINUS = 290,
    STAR = 291,
    DIV = 292,
    MOD = 293,
    NOT = 294,
    ASSIGN = 295,
    SEMI = 296,
    COMMA = 297,
    RESERVED = 298,
    NEWLINE = 299,
    STRLIT = 300,
    DECLIT = 301,
    REALLIT = 302,
    ID = 303
  };
#endif
/* Tokens.  */
#define BOOL 258
#define BOOLLIT 259
#define CLASS 260
#define DO 261
#define DOTLENGTH 262
#define DOUBLE 263
#define ELSE 264
#define IF 265
#define INT 266
#define PARSEINT 267
#define PRINT 268
#define PUBLIC 269
#define RETURN 270
#define STATIC 271
#define STRING 272
#define VOID 273
#define WHILE 274
#define OCURV 275
#define CCURV 276
#define OBRACE 277
#define CBRACE 278
#define OSQUARE 279
#define CSQUARE 280
#define AND 281
#define OR 282
#define LT 283
#define GT 284
#define EQ 285
#define NEQ 286
#define LEQ 287
#define GEQ 288
#define PLUS 289
#define MINUS 290
#define STAR 291
#define DIV 292
#define MOD 293
#define NOT 294
#define ASSIGN 295
#define SEMI 296
#define COMMA 297
#define RESERVED 298
#define NEWLINE 299
#define STRLIT 300
#define DECLIT 301
#define REALLIT 302
#define ID 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "jac.y" /* yacc.c:355  */

	char * string;
	struct node *node;

#line 222 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 239 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   307

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   113,   113,   116,   117,   118,   119,   121,   122,   124,
     125,   128,   131,   133,   134,   136,   138,   139,   140,   144,
     145,   149,   150,   153,   154,   155,   158,   159,   160,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   175,   176,
     180,   181,   184,   185,   186,   187,   190,   191,   194,   197,
     198,   201,   202,   204,   205,   208,   209,   212,   213,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   239
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOL", "BOOLLIT", "CLASS", "DO",
  "DOTLENGTH", "DOUBLE", "ELSE", "IF", "INT", "PARSEINT", "PRINT",
  "PUBLIC", "RETURN", "STATIC", "STRING", "VOID", "WHILE", "OCURV",
  "CCURV", "OBRACE", "CBRACE", "OSQUARE", "CSQUARE", "AND", "OR", "LT",
  "GT", "EQ", "NEQ", "LEQ", "GEQ", "PLUS", "MINUS", "STAR", "DIV", "MOD",
  "NOT", "ASSIGN", "SEMI", "COMMA", "RESERVED", "NEWLINE", "STRLIT",
  "DECLIT", "REALLIT", "ID", "$accept", "Program", "SubProgram",
  "FieldDecl", "SubFieldDecl", "MethodDecl", "MethodHeader",
  "OptFormalParams", "MethodBody", "SubMethodBody", "FormalParams",
  "SubFormalParams", "VarDecl", "SubVarDecl", "Type", "Statement",
  "MultipleStatements", "ExprStrlit", "OptAMIPA", "OptExpr", "Assignment",
  "MethodInvocation", "MultipleCommaExpr", "OptExprCommaExprs",
  "ParseArgs", "OptDotLength", "Expr", "Empty", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

#define YYPACT_NINF -31

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-31)))

#define YYTABLE_NINF -80

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,   -25,    24,     5,   -31,   -31,    43,   -31,   -13,    18,
     -31,   -31,   -31,   -31,   -31,    29,   -31,   -31,   -31,    14,
     -10,   -31,   -31,    30,   139,   -31,    22,   -30,   -31,     1,
     159,    34,    36,    40,   184,    45,    58,   -31,   -14,   -31,
      27,   -31,     8,   -31,   -31,   -31,   -31,    52,    61,   -31,
      31,   -31,   -31,    35,   -31,    66,   184,    19,   181,   -31,
     163,   184,   184,   184,   -31,   -31,    15,    53,   -31,   -31,
     -31,   268,   -31,   184,    58,    72,    55,   109,   184,    56,
     -31,    75,   -31,   -31,   -31,    77,   212,    84,    83,   -31,
      91,   268,    93,   225,   -31,   -31,   -31,   -31,   -31,   -31,
     -31,   184,   184,   184,   184,   184,   184,   184,   184,   238,
     -31,   -31,    98,   107,   268,   -31,   268,   105,    90,   -31,
     111,    99,   -31,   184,   159,   -31,   184,   122,   -31,   -31,
     274,    94,   -31,   -31,   162,   162,   -31,   -31,   159,   -31,
     -31,   104,   -31,    56,   -31,   -31,    29,   251,   123,   260,
     -31,   -31,   184,   -31,   118,   127,   159,   149,   268,   -31,
     -31,   -31,   -31
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,    79,     0,     3,     0,     0,
       2,     6,     4,     5,     8,     0,    26,    28,    27,     0,
       0,    79,    11,    79,     0,    16,    79,     0,     9,     0,
       0,     0,     0,     0,    79,     0,     0,    15,     0,    17,
       0,    18,     0,    42,    43,    44,    45,     0,     0,    13,
       0,    14,     7,     0,    37,     0,     0,     0,     0,    76,
       0,     0,     0,     0,    77,    78,    79,     0,    59,    60,
      61,    46,    47,     0,     0,     0,    38,     0,     0,    79,
      35,     0,    12,    79,    10,     0,     0,     0,     0,    41,
       0,    40,     0,     0,    70,    71,    72,    57,    73,    58,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      39,    29,     0,     0,    79,    54,    48,     0,     0,    24,
       0,    19,    21,     0,     0,    56,     0,     0,    75,    74,
      62,    63,    68,    66,    64,    69,    67,    65,     0,    50,
      49,    53,    51,    79,    23,    20,     0,     0,    31,     0,
      34,    32,     0,    25,     0,     0,     0,     0,    52,    22,
      33,    30,    55
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,
     -31,   -31,   -31,    33,    -7,   -20,   103,   -31,   -31,   -31,
     -23,   -22,   -31,   -31,   -21,   -31,   -15,    -5
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,    12,    27,    13,    19,    48,    22,    24,
      49,   121,    39,   118,    20,    74,    75,    90,    42,    67,
      68,    69,   141,   113,    70,    98,    71,    46
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       7,    43,    44,    45,    41,     1,    77,    43,    44,    45,
      55,    52,    53,    43,    44,    45,    25,    40,    28,    50,
      87,    51,    97,     3,     4,    16,    78,     5,    14,    72,
      17,    76,    16,    18,    15,    77,    21,    17,    23,    47,
      18,    86,    54,    91,     8,    93,    94,    95,    96,    80,
      26,    43,    44,    45,    56,    78,    57,     9,   109,    29,
      58,    99,   114,   116,    30,    73,    10,    88,    31,    76,
      32,    33,   115,    34,   119,    79,    81,    35,   122,    83,
      36,   -79,    82,    84,    11,    85,   130,   131,   132,   133,
     134,   135,   136,   137,   100,   111,   -45,   123,   117,   -79,
     120,    43,    44,    45,   148,   125,    38,   126,   147,   142,
     112,   149,   127,    59,   128,    43,    44,    45,   151,   139,
     101,    32,   103,   104,   105,   106,   107,   108,   140,    60,
     -79,   144,   156,    43,    44,    45,   161,   158,   119,   154,
      29,   146,    16,    61,    62,    30,   152,    17,    63,    31,
      18,    32,    33,   143,    34,    64,    65,    66,    35,   145,
      29,    36,    37,   150,    92,    30,   159,    59,   160,    31,
     162,    32,    33,     0,    34,    32,   153,   110,    35,     0,
     -79,    36,     0,    60,     0,    59,     0,    38,    59,     0,
     103,   104,     0,    32,   107,   108,    32,    61,    62,     0,
     -79,    60,    63,     0,    60,     0,     0,    38,     0,    64,
      65,    66,     0,     0,     0,    61,    62,     0,    61,    62,
      63,     0,     0,    63,     0,     0,    89,    64,    65,    66,
      64,    65,    66,   124,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   108,   129,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   108,   138,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   108,   155,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,   157,   101,   102,   103,   104,
     105,   106,   107,   108,   101,   102,   103,   104,   105,   106,
     107,   108,   103,   104,   105,   106,   107,   108
};

static const yytype_int16 yycheck[] =
{
       5,    24,    24,    24,    24,     5,    20,    30,    30,    30,
      30,    41,    42,    36,    36,    36,    21,    24,    23,    26,
       1,    26,     7,    48,     0,     3,    40,    22,    41,    34,
       8,    36,     3,    11,    16,    20,    22,     8,    48,    17,
      11,    56,    41,    58,     1,    60,    61,    62,    63,    41,
      20,    74,    74,    74,    20,    40,    20,    14,    73,     1,
      20,    66,    77,    78,     6,    20,    23,    48,    10,    74,
      12,    13,    77,    15,    79,    48,    24,    19,    83,    48,
      22,    23,    21,    48,    41,    19,   101,   102,   103,   104,
     105,   106,   107,   108,    41,    23,    41,    20,    42,    41,
      25,   124,   124,   124,   124,    21,    48,    24,   123,   114,
       1,   126,    21,     4,    21,   138,   138,   138,   138,    21,
      26,    12,    28,    29,    30,    31,    32,    33,    21,    20,
      21,    41,     9,   156,   156,   156,   156,   152,   143,   146,
       1,    42,     3,    34,    35,     6,    42,     8,    39,    10,
      11,    12,    13,    48,    15,    46,    47,    48,    19,    48,
       1,    22,    23,    41,     1,     6,    48,     4,    41,    10,
      21,    12,    13,    -1,    15,    12,   143,    74,    19,    -1,
      41,    22,    -1,    20,    -1,     4,    -1,    48,     4,    -1,
      28,    29,    -1,    12,    32,    33,    12,    34,    35,    -1,
      41,    20,    39,    -1,    20,    -1,    -1,    48,    -1,    46,
      47,    48,    -1,    -1,    -1,    34,    35,    -1,    34,    35,
      39,    -1,    -1,    39,    -1,    -1,    45,    46,    47,    48,
      46,    47,    48,    21,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    21,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    21,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    21,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    26,    27,    28,    29,    30,    31,
      32,    33,    28,    29,    30,    31,    32,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    50,    48,     0,    22,    51,    76,     1,    14,
      23,    41,    52,    54,    41,    16,     3,     8,    11,    55,
      63,    22,    57,    48,    58,    76,    20,    53,    76,     1,
       6,    10,    12,    13,    15,    19,    22,    23,    48,    61,
      63,    64,    67,    69,    70,    73,    76,    17,    56,    59,
      63,    76,    41,    42,    41,    64,    20,    20,    20,     4,
      20,    34,    35,    39,    46,    47,    48,    68,    69,    70,
      73,    75,    76,    20,    64,    65,    76,    20,    40,    48,
      41,    24,    21,    48,    48,    19,    75,     1,    48,    45,
      66,    75,     1,    75,    75,    75,    75,     7,    74,    76,
      41,    26,    27,    28,    29,    30,    31,    32,    33,    75,
      65,    23,     1,    72,    75,    76,    75,    42,    62,    76,
      25,    60,    76,    20,    21,    21,    24,    21,    21,    21,
      75,    75,    75,    75,    75,    75,    75,    75,    21,    21,
      21,    71,    76,    48,    41,    48,    42,    75,    64,    75,
      41,    64,    42,    62,    63,    21,     9,    25,    75,    48,
      41,    64,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    51,    51,    52,    52,    53,
      53,    54,    55,    56,    56,    57,    58,    58,    58,    59,
      59,    60,    60,    61,    62,    62,    63,    63,    63,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    65,    65,
      66,    66,    67,    67,    67,    67,    68,    68,    69,    70,
      70,    71,    71,    72,    72,    73,    73,    74,    74,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     1,     2,     2,     2,     6,     2,     1,
       3,     4,     5,     1,     1,     3,     1,     2,     2,     3,
       4,     1,     4,     4,     1,     3,     1,     1,     1,     3,
       7,     5,     5,     7,     5,     2,     3,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     4,
       4,     1,     3,     2,     1,     7,     4,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     3,     3,     1,     1,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
#line 113 "jac.y" /* yacc.c:1646  */
    {;}
#line 1457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 116 "jac.y" /* yacc.c:1646  */
    {;}
#line 1463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 117 "jac.y" /* yacc.c:1646  */
    {;}
#line 1469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 118 "jac.y" /* yacc.c:1646  */
    {;}
#line 1475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 119 "jac.y" /* yacc.c:1646  */
    {;}
#line 1481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 121 "jac.y" /* yacc.c:1646  */
    {;}
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 122 "jac.y" /* yacc.c:1646  */
    {;}
#line 1493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 124 "jac.y" /* yacc.c:1646  */
    {;}
#line 1499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 125 "jac.y" /* yacc.c:1646  */
    {;}
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 128 "jac.y" /* yacc.c:1646  */
    {;}
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 131 "jac.y" /* yacc.c:1646  */
    {;}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 133 "jac.y" /* yacc.c:1646  */
    {;}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 134 "jac.y" /* yacc.c:1646  */
    {;}
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 136 "jac.y" /* yacc.c:1646  */
    {;}
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 138 "jac.y" /* yacc.c:1646  */
    {;}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 139 "jac.y" /* yacc.c:1646  */
    {;}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 140 "jac.y" /* yacc.c:1646  */
    {;}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 144 "jac.y" /* yacc.c:1646  */
    {;}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 145 "jac.y" /* yacc.c:1646  */
    {;}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 149 "jac.y" /* yacc.c:1646  */
    {;}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 150 "jac.y" /* yacc.c:1646  */
    {;}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 153 "jac.y" /* yacc.c:1646  */
    {;}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 154 "jac.y" /* yacc.c:1646  */
    {;}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 155 "jac.y" /* yacc.c:1646  */
    {;}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 158 "jac.y" /* yacc.c:1646  */
    {;}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 159 "jac.y" /* yacc.c:1646  */
    {;}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 160 "jac.y" /* yacc.c:1646  */
    {;}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 163 "jac.y" /* yacc.c:1646  */
    {;}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 164 "jac.y" /* yacc.c:1646  */
    {;}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 165 "jac.y" /* yacc.c:1646  */
    {;}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 166 "jac.y" /* yacc.c:1646  */
    {;}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 167 "jac.y" /* yacc.c:1646  */
    {;}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 168 "jac.y" /* yacc.c:1646  */
    {;}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 169 "jac.y" /* yacc.c:1646  */
    {;}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 170 "jac.y" /* yacc.c:1646  */
    {;}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 171 "jac.y" /* yacc.c:1646  */
    {;}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 175 "jac.y" /* yacc.c:1646  */
    {;}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 176 "jac.y" /* yacc.c:1646  */
    {;}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 180 "jac.y" /* yacc.c:1646  */
    {;}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 181 "jac.y" /* yacc.c:1646  */
    {;}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 184 "jac.y" /* yacc.c:1646  */
    {;}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 185 "jac.y" /* yacc.c:1646  */
    {;}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 186 "jac.y" /* yacc.c:1646  */
    {;}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 187 "jac.y" /* yacc.c:1646  */
    {;}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 190 "jac.y" /* yacc.c:1646  */
    {;}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 191 "jac.y" /* yacc.c:1646  */
    {;}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 194 "jac.y" /* yacc.c:1646  */
    {;}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 197 "jac.y" /* yacc.c:1646  */
    {;}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 198 "jac.y" /* yacc.c:1646  */
    {;}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 201 "jac.y" /* yacc.c:1646  */
    {;}
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 202 "jac.y" /* yacc.c:1646  */
    {;}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 204 "jac.y" /* yacc.c:1646  */
    {;}
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 205 "jac.y" /* yacc.c:1646  */
    {;}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 208 "jac.y" /* yacc.c:1646  */
    {;}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 209 "jac.y" /* yacc.c:1646  */
    {;}
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 212 "jac.y" /* yacc.c:1646  */
    {;}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 213 "jac.y" /* yacc.c:1646  */
    {;}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 216 "jac.y" /* yacc.c:1646  */
    {;}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 217 "jac.y" /* yacc.c:1646  */
    {;}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 218 "jac.y" /* yacc.c:1646  */
    {;}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 219 "jac.y" /* yacc.c:1646  */
    {;}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 220 "jac.y" /* yacc.c:1646  */
    {;}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 221 "jac.y" /* yacc.c:1646  */
    {;}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 222 "jac.y" /* yacc.c:1646  */
    {;}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 223 "jac.y" /* yacc.c:1646  */
    {;}
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 224 "jac.y" /* yacc.c:1646  */
    {;}
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 225 "jac.y" /* yacc.c:1646  */
    {;}
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 226 "jac.y" /* yacc.c:1646  */
    {;}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 227 "jac.y" /* yacc.c:1646  */
    {;}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 228 "jac.y" /* yacc.c:1646  */
    {;}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 229 "jac.y" /* yacc.c:1646  */
    {;}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 230 "jac.y" /* yacc.c:1646  */
    {;}
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 231 "jac.y" /* yacc.c:1646  */
    {;}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 232 "jac.y" /* yacc.c:1646  */
    {;}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 233 "jac.y" /* yacc.c:1646  */
    {;}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 234 "jac.y" /* yacc.c:1646  */
    {;}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 235 "jac.y" /* yacc.c:1646  */
    {;}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 239 "jac.y" /* yacc.c:1646  */
    {;}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1923 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 242 "jac.y" /* yacc.c:1906  */


void yyerror (const char *s){
	printf ("Line %d, col %d: %s: %s\n",num_line, (int)(num_col- strlen(yytext)+1), s, yytext);
}


