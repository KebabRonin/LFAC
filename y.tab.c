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
#line 1 "limbaj.y"

#include <stdio.h>
#include <string.h>
#include "code.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
int yydebug=1; 

struct Tip_Date* now_declaring = NULL;
char parameters[100][100];
char structNames[100][100];
int nr_parametri = 0;
char* typeOf;
char* nume_typeof;
int is_char = 0;
int is_string = 0;
int is_int = 0;
int is_float = 0;
float f;
int tipuri_expresii[100];
char elemente_expresie[100][100];
int nr_expresii = 0;
int nr_elemente_expresie = 0;
int is_eval = 0;
char parametri[100][100];

struct AstNode* buildAST(char* root, struct AstNode* left, struct AstNode* right, int type);
void freeAST(struct AstNode* self);
int EvalAST(struct AstNode* root);

void new_entry_sy(char* nume, int is_const, char* tip, char* valoare, struct list* matrix);
void new_entry_fn(char* nume, struct Tip_Date* ret, struct list* param);
void export_sy_table();
void export_fn_table();


#line 108 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    ID = 258,
    TIP = 259,
    ASSIGN = 260,
    NR = 261,
    CMP_OP = 262,
    CLASS = 263,
    STRING = 264,
    FLOAT = 265,
    CHAR = 266,
    BOOL = 267,
    BGIN = 268,
    END = 269,
    CONST = 270,
    IF = 271,
    WHILE = 272,
    DO = 273,
    ELSE = 274,
    FOR = 275,
    BOOLAND = 276,
    BOOLOR = 277,
    TYPEOF = 278,
    EVAL = 279,
    GLOBDEF = 280,
    FNCDEF = 281,
    STRUCTDEF = 282
  };
#endif
/* Tokens.  */
#define ID 258
#define TIP 259
#define ASSIGN 260
#define NR 261
#define CMP_OP 262
#define CLASS 263
#define STRING 264
#define FLOAT 265
#define CHAR 266
#define BOOL 267
#define BGIN 268
#define END 269
#define CONST 270
#define IF 271
#define WHILE 272
#define DO 273
#define ELSE 274
#define FOR 275
#define BOOLAND 276
#define BOOLOR 277
#define TYPEOF 278
#define EVAL 279
#define GLOBDEF 280
#define FNCDEF 281
#define STRUCTDEF 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 38 "limbaj.y"

int intval;
char* strval;
char charval;
float floatval;
struct Tip_Date* tipD;
struct list* ls;
struct simbol* symbol;
struct AstNode* ast;

#line 225 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
#define YYLAST   241

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  181

#define YYUNDEFTOK  2
#define YYMAXUTOK   282


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
      33,    34,    30,    28,    39,    29,    40,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    32,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    62,    62,    65,    66,    66,    69,    70,    70,    73,
      74,    77,    78,    83,    84,    87,    88,    88,    93,    94,
      97,    98,   105,   110,    98,   118,   121,   124,   127,   130,
     133,   182,   183,   195,   199,   203,   207,   213,   214,   217,
     218,   221,   230,   231,   234,   235,   239,   240,   241,   242,
     246,   265,   286,   287,   313,   340,   341,   342,   345,   346,
     347,   348,   351,   352,   355,   358,   361,   364,   367,   370,
     371,   372,   373,   381,   382,   385,   404,   418,   424,   430,
     436,   442,   443,   452,   461,   470,   479,   494,   538,   582,
     637
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "TIP", "ASSIGN", "NR", "CMP_OP",
  "CLASS", "STRING", "FLOAT", "CHAR", "BOOL", "BGIN", "END", "CONST", "IF",
  "WHILE", "DO", "ELSE", "FOR", "BOOLAND", "BOOLOR", "TYPEOF", "EVAL",
  "GLOBDEF", "FNCDEF", "STRUCTDEF", "'+'", "'-'", "'*'", "'/'", "';'",
  "'('", "')'", "'{'", "'}'", "'['", "']'", "','", "'.'", "$accept",
  "progr", "declaratii_globale", "$@1", "declaratii_globale_atomic", "$@2",
  "declaratii_fnc", "declaratii_fnc_atomic", "declaratii_structuri",
  "lista_date_membru", "$@3", "opt_lista_id",
  "declaratii_structuri_atomic", "$@4", "$@5", "$@6", "tip_date", "typeof",
  "lista_array", "lista_id", "lista_param", "lista_param_non_void",
  "param", "bloc", "instr_bloc", "list", "assignment", "statement",
  "control_statement", "if_statement", "else_statement", "while_statement",
  "do_while_statement", "for_statement", "boolean_expr_atomic",
  "boolean_expr", "lista_apel", "param_apel", "eval", "expresie", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    43,    45,
      42,    47,    59,    40,    41,   123,   125,    91,    93,    44,
      46
};
# endif

#define YYPACT_NINF (-113)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-58)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      14,  -113,    29,    37,  -113,  -113,  -113,    62,    28,    28,
    -113,    77,  -113,    99,     5,    73,  -113,  -113,   104,   100,
     158,  -113,  -113,  -113,   130,   110,   132,   108,   134,    40,
    -113,   116,   135,   128,   138,   146,  -113,   170,  -113,   137,
     148,  -113,  -113,  -113,  -113,  -113,  -113,    59,  -113,  -113,
    -113,  -113,  -113,   110,   136,   125,   -16,    28,  -113,     8,
     179,     7,   144,   144,   180,   172,  -113,  -113,   188,   110,
    -113,   160,   148,  -113,    24,   155,   177,   110,   110,   110,
     110,  -113,   194,  -113,   198,   199,   175,   171,  -113,   181,
    -113,  -113,   -24,  -113,   185,   110,   214,   144,  -113,     4,
     129,    27,    17,   192,   125,   195,   184,  -113,  -113,    64,
     221,  -113,    35,    35,  -113,  -113,   110,   125,   125,   193,
      28,  -113,  -113,   223,   125,   191,   224,    47,    98,   144,
     144,   128,   110,   128,  -113,   144,   144,  -113,  -113,  -113,
     191,   225,  -113,   180,  -113,    63,  -113,  -113,   110,  -113,
     209,  -113,   213,   191,  -113,    54,    38,   110,    94,  -113,
    -113,   191,   128,  -113,   201,   188,   191,  -113,   132,   132,
    -113,  -113,   200,  -113,   196,    -8,   128,   204,  -113,  -113,
    -113
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     4,     0,     9,     6,     1,    11,    13,     5,    10,
      20,     0,    25,     0,     0,     0,     7,    29,     0,    14,
       0,     2,    27,    26,     0,     0,     0,     0,     0,    31,
      43,     0,     0,     0,     0,     0,    56,     0,    52,     0,
      47,    58,    59,    60,    61,    55,    28,    31,    82,    83,
      84,    85,    86,     0,     0,    31,     0,    37,    21,     0,
       0,     0,     0,     0,     0,     0,    44,    57,     0,     0,
      42,     0,    48,    46,     0,    87,     0,     0,     0,     0,
       0,    30,    33,     8,     0,     0,     0,    38,    39,     0,
      75,    54,     0,    73,     0,     0,     0,     0,    72,     0,
       0,     0,     0,     0,    31,     0,     0,    49,    90,     0,
       0,    81,    77,    79,    78,    80,     0,    31,    31,     0,
       0,    15,    53,     0,    31,    50,     0,     0,     0,     0,
       0,     0,     0,     0,    45,     0,     0,    76,    89,    88,
      34,    35,    41,     0,    40,     0,    74,    32,     0,    69,
      70,    71,    63,    68,    65,     0,     0,     0,     0,    22,
      16,    51,     0,    62,     0,     0,    36,    12,    19,     0,
      64,    66,     0,    23,    18,     0,     0,     0,    17,    67,
      24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,    -3,    -5,   -33,   -89,
    -113,  -113,   117,  -113,  -112,   -56,   -61,   -20,   -19,  -113,
    -113,  -113,  -113,  -113,  -113,   -35,   164,   118,  -113,   -23
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     8,    26,     7,     9,    11,   145,
     169,   173,    19,    89,   168,   177,    85,    36,    61,    56,
      86,    87,    88,    21,    65,    37,    38,    66,    67,    41,
     163,    42,    43,    44,    98,    99,    92,    93,    45,   100
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    40,    54,    17,    17,    16,    18,   105,   102,    23,
     122,    90,    95,    24,    75,   123,    83,    71,    72,   152,
      29,   154,    82,    84,   178,   129,   130,    90,   101,     5,
      76,    84,    12,    31,    32,    33,    13,    34,   131,     1,
      15,    35,    91,    14,    39,    40,   106,    96,   129,   130,
     170,    15,    17,   134,   112,   113,   114,   115,   108,   129,
     130,   133,   127,     6,   179,    79,    80,    12,   129,   130,
     165,    13,   125,    59,   128,   129,   130,    60,    14,   174,
     175,   149,    71,    72,   141,   142,    15,   158,   164,    10,
      20,   147,    74,   140,   150,   151,    60,    29,   138,   159,
     155,   156,    22,   123,   172,   132,    25,    27,    28,   153,
      31,    32,    33,    47,    34,    17,    48,    15,    35,    49,
      50,    51,    52,    39,    40,   161,    77,    78,    79,    80,
     167,    29,   111,    46,   166,    55,   132,    58,    71,    72,
      17,    57,   160,    53,    31,    32,    33,    47,    34,    62,
      48,    15,    35,    49,    50,    51,    52,    77,    78,    79,
      80,    29,    60,    64,    77,    78,    79,    80,    63,    73,
      81,    68,    30,    29,    31,    32,    33,    97,    34,    69,
     -57,    15,    35,    29,    70,    94,    31,    32,    33,   103,
      34,   104,   107,    15,    35,   110,    31,    32,    33,   116,
      34,   117,   118,    15,    35,    77,    78,    79,    80,   119,
     120,   111,    77,    78,    79,    80,   121,   126,   137,    77,
      78,    79,    80,   124,   139,   135,    90,   136,   143,   148,
     157,   130,   162,   171,   176,    84,   180,   144,   109,     0,
       0,   146
};

static const yytype_int16 yycheck[] =
{
      20,    20,    25,     8,     9,     8,     9,    68,    64,     4,
      34,     3,     5,     8,    47,    39,    32,    37,    37,   131,
       3,   133,    55,    39,    32,    21,    22,     3,    63,     0,
      53,    39,     4,    16,    17,    18,     8,    20,    34,    25,
      23,    24,    34,    15,    64,    64,    69,    40,    21,    22,
     162,    23,    57,    36,    77,    78,    79,    80,    34,    21,
      22,    34,    97,    26,   176,    30,    31,     4,    21,    22,
      32,     8,    95,    33,    97,    21,    22,    37,    15,   168,
     169,    34,   102,   102,   117,   118,    23,   143,    34,    27,
      13,   124,    33,   116,   129,   130,    37,     3,    34,    36,
     135,   136,     3,    39,   165,     7,    33,     3,     8,   132,
      16,    17,    18,     3,    20,   120,     6,    23,    24,     9,
      10,    11,    12,   143,   143,   148,    28,    29,    30,    31,
      36,     3,    34,     3,   157,     3,     7,     3,   158,   158,
     145,    33,   145,    33,    16,    17,    18,     3,    20,    33,
       6,    23,    24,     9,    10,    11,    12,    28,    29,    30,
      31,     3,    37,    35,    28,    29,    30,    31,    33,    32,
      34,    33,    14,     3,    16,    17,    18,    33,    20,    33,
      32,    23,    24,     3,    14,     6,    16,    17,    18,    17,
      20,     3,    32,    23,    24,    40,    16,    17,    18,     5,
      20,     3,     3,    23,    24,    28,    29,    30,    31,    34,
      39,    34,    28,    29,    30,    31,    35,     3,    34,    28,
      29,    30,    31,    38,     3,    33,     3,    32,    35,     5,
       5,    22,    19,    32,    34,    39,    32,   120,    74,    -1,
      -1,   123
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    25,    42,    43,    44,     0,    26,    47,    45,    48,
      27,    49,     4,     8,    15,    23,    57,    58,    57,    53,
      13,    64,     3,     4,     8,    33,    46,     3,     8,     3,
      14,    16,    17,    18,    20,    24,    58,    66,    67,    68,
      69,    70,    72,    73,    74,    79,     3,     3,     6,     9,
      10,    11,    12,    33,    80,     3,    60,    33,     3,    33,
      37,    59,    33,    33,    35,    65,    68,    69,    33,    33,
      14,    68,    69,    32,    33,    59,    80,    28,    29,    30,
      31,    34,    59,    32,    39,    57,    61,    62,    63,    54,
       3,    34,    77,    78,     6,     5,    40,    33,    75,    76,
      80,    76,    66,    17,     3,    67,    80,    32,    34,    77,
      40,    34,    80,    80,    80,    80,     5,     3,     3,    34,
      39,    35,    34,    39,    38,    80,     3,    76,    80,    21,
      22,    34,     7,    34,    36,    33,    32,    34,    34,     3,
      80,    59,    59,    35,    63,    50,    78,    59,     5,    34,
      76,    76,    65,    80,    65,    76,    76,     5,    66,    36,
      57,    80,    19,    71,    34,    32,    80,    36,    55,    51,
      65,    32,    67,    52,    60,    60,    34,    56,    32,    65,
      32
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    44,    43,    45,    46,    45,    47,
      47,    48,    48,    49,    49,    50,    51,    50,    52,    52,
      53,    54,    55,    56,    53,    57,    57,    57,    57,    57,
      58,    59,    59,    60,    60,    60,    60,    61,    61,    62,
      62,    63,    64,    64,    65,    65,    66,    66,    66,    66,
      67,    67,    68,    68,    68,    68,    68,    68,    69,    69,
      69,    69,    70,    70,    71,    72,    73,    74,    75,    76,
      76,    76,    76,    77,    77,    78,    79,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     0,     0,     3,     0,     0,     5,     0,
       2,     0,     9,     0,     2,     0,     0,     5,     1,     0,
       0,     0,     0,     0,    11,     1,     2,     2,     3,     1,
       4,     0,     4,     2,     4,     4,     6,     0,     1,     1,
       3,     3,     3,     2,     1,     3,     2,     1,     2,     3,
       4,     6,     1,     4,     3,     1,     1,     1,     1,     1,
       1,     1,     6,     5,     2,     5,     7,     9,     3,     3,
       3,     3,     1,     1,     3,     1,     4,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     2,     4,     4,
       3
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
#line 62 "limbaj.y"
                                                                   {printf("program corect sintactic\n");}
#line 1541 "y.tab.c"
    break;

  case 4:
#line 66 "limbaj.y"
                                             { make_sym_table(0); }
#line 1547 "y.tab.c"
    break;

  case 5:
#line 66 "limbaj.y"
                                                                                              {export_sy_table();}
#line 1553 "y.tab.c"
    break;

  case 7:
#line 70 "limbaj.y"
                                                                        {now_declaring = (yyvsp[0].tipD);}
#line 1559 "y.tab.c"
    break;

  case 10:
#line 74 "limbaj.y"
                                                          {export_fn_table();}
#line 1565 "y.tab.c"
    break;

  case 12:
#line 78 "limbaj.y"
                                                                                                {
																						new_entry_fn((yyvsp[-6].strval), (yyvsp[-7].tipD), (yyvsp[-4].ls));
																					}
#line 1573 "y.tab.c"
    break;

  case 14:
#line 84 "limbaj.y"
                                                                   {export_sy_table();}
#line 1579 "y.tab.c"
    break;

  case 16:
#line 88 "limbaj.y"
                                                                {
					now_declaring = (yyvsp[0].tipD); 
					}
#line 1587 "y.tab.c"
    break;

  case 21:
#line 98 "limbaj.y"
                                                                                 {
					userdef_table.dimensiune[userdef_table.nr_dimensiuni] = (char*) (malloc(sizeof(struct UserDef))); 
					((struct UserDef*)(userdef_table.dimensiune[userdef_table.nr_dimensiuni]))->nume = strdup((yyvsp[0].strval));
					strcpy(structNames[userdef_table.nr_dimensiuni], (yyvsp[0].strval));
					((struct UserDef*)(userdef_table.dimensiune[userdef_table.nr_dimensiuni]))->date = malloc(sizeof(struct tabela_simboluri));
					make_sym_table((((struct UserDef*)(userdef_table.dimensiune[userdef_table.nr_dimensiuni]))->date));
					userdef_table.nr_dimensiuni++;
					}
#line 1600 "y.tab.c"
    break;

  case 22:
#line 105 "limbaj.y"
                                                                    {
						now_declaring = malloc(sizeof(struct Tip_Date));
						now_declaring->is_const = 0;
						now_declaring->tip = strdup((yyvsp[-4].strval));
						make_sym_table(0);
					}
#line 1611 "y.tab.c"
    break;

  case 23:
#line 110 "limbaj.y"
                                                       {
						now_declaring->is_const = 0;
						free(now_declaring->tip);
						free(now_declaring);
						now_declaring = 0;
					}
#line 1622 "y.tab.c"
    break;

  case 25:
#line 118 "limbaj.y"
               {(yyval.tipD) = malloc(sizeof(struct Tip_Date)); (yyval.tipD)->tip = strdup((yyvsp[0].strval)); (yyval.tipD)->is_const = 0; 
				(yyval.tipD)->size = malloc(sizeof(struct list)); (yyval.tipD)->size->nr_dimensiuni=0;
				}
#line 1630 "y.tab.c"
    break;

  case 26:
#line 121 "limbaj.y"
                             {(yyval.tipD) = malloc(sizeof(struct Tip_Date)); (yyval.tipD)->tip = strdup((yyvsp[0].strval)); (yyval.tipD)->is_const = 1;
				(yyval.tipD)->size = malloc(sizeof(struct list)); (yyval.tipD)->size->nr_dimensiuni=0;
				}
#line 1638 "y.tab.c"
    break;

  case 27:
#line 124 "limbaj.y"
                            {(yyval.tipD) = malloc(sizeof(struct Tip_Date)); (yyval.tipD)->tip = strdup((yyvsp[0].strval)); (yyval.tipD)->is_const = 0;
				(yyval.tipD)->size = malloc(sizeof(struct list)); (yyval.tipD)->size->nr_dimensiuni=0;
				}
#line 1646 "y.tab.c"
    break;

  case 28:
#line 127 "limbaj.y"
                                  {(yyval.tipD) = malloc(sizeof(struct Tip_Date)); (yyval.tipD)->tip = strdup((yyvsp[0].strval)); (yyval.tipD)->is_const = 1;
				(yyval.tipD)->size = malloc(sizeof(struct list)); (yyval.tipD)->size->nr_dimensiuni=0;
				}
#line 1654 "y.tab.c"
    break;

  case 29:
#line 130 "limbaj.y"
                          {(yyval.tipD) = NULL;}
#line 1660 "y.tab.c"
    break;

  case 30:
#line 133 "limbaj.y"
                                {
									verify_expresie(tipuri_expresii,nr_expresii);
									
									if(nr_elemente_expresie == 1)
									{
										if(is_char==1)
										{
											printf("TypeOf('%c') : %s\n",nume_typeof,typeOf);
											is_char=0;
										}
										else if(is_string==1)
										{
											printf("TypeOf(\"%s\") : %s\n",nume_typeof,typeOf);
											is_string=0;
										}
										else if(is_int==1)
										{
											printf("TypeOf(%d) : %s\n",nume_typeof,typeOf);
											is_int=0;
										}
										else if(is_float==1)
										{
											printf("TypeOf(%f) : %s\n",f,typeOf);
											is_float=0;
										}
										else
										{
											printf("TypeOf(%s) : %s\n",nume_typeof,typeOf);
										}
									}
									else
									{
										printf("TypeOf() : %s\n",typeOf);
										// int i=0;
										// printf("TypeOf(");
										// for(i=0;i<nr_elemente_expresie;i++)
										// {
										// 	printf("%s",elemente_expresie[i]);
										// }
										// printf(") : %s\n",typeOf);
									}
									
									nr_expresii=0;
									nr_elemente_expresie = 0;
									memset(tipuri_expresii, 0, sizeof(tipuri_expresii));
									memset(elemente_expresie, 0, sizeof(elemente_expresie));
	   							}
#line 1712 "y.tab.c"
    break;

  case 31:
#line 182 "limbaj.y"
                          {(yyval.ls) = malloc(sizeof(struct list)); (yyval.ls)->nr_dimensiuni=0;}
#line 1718 "y.tab.c"
    break;

  case 32:
#line 183 "limbaj.y"
                                                 { 
										(yyval.ls) = (yyvsp[0].ls); 
										if((yyval.ls)->nr_dimensiuni == 5)
										{
											yyerror("ERROR:Array has too many dimensions.");
     										exit(0);
										}
										(yyval.ls)->dimensiune[(yyval.ls)->nr_dimensiuni]    = malloc(sizeof(int)); 
										*((int*)((yyval.ls)->dimensiune[(yyval.ls)->nr_dimensiuni]))   = (yyvsp[-2].intval); 
										(yyval.ls)->nr_dimensiuni++;}
#line 1733 "y.tab.c"
    break;

  case 33:
#line 195 "limbaj.y"
                          {
				// printf("list_id :%s %d %s howmany:%d\n", now_declaring->tip, now_declaring->is_const, $1, $2->nr_dimensiuni);
				new_entry_sy((yyvsp[-1].strval), now_declaring->is_const, now_declaring->tip, 0, (yyvsp[0].ls));
			}
#line 1742 "y.tab.c"
    break;

  case 34:
#line 199 "limbaj.y"
                                                  {
				// printf("list_id :%s %d %s howmany:%d\n", now_declaring->tip, now_declaring->is_const, $1, $2->nr_dimensiuni);
				new_entry_sy((yyvsp[-3].strval), now_declaring->is_const, now_declaring->tip, /*$4*/0, (yyvsp[-2].ls));
			}
#line 1751 "y.tab.c"
    break;

  case 35:
#line 203 "limbaj.y"
                                               {
			// printf("list_id :%s %d %s howmany:%d\n", now_declaring->tip, now_declaring->is_const, $3, $4->nr_dimensiuni);
			new_entry_sy((yyvsp[-1].strval), now_declaring->is_const, now_declaring->tip, 0, (yyvsp[0].ls));
			}
#line 1760 "y.tab.c"
    break;

  case 36:
#line 207 "limbaj.y"
                                                               {
				// printf("list_id :%s %d %s howmany:%d\n", now_declaring->tip, now_declaring->is_const, $3, $4->nr_dimensiuni);
				new_entry_sy((yyvsp[-3].strval), now_declaring->is_const, now_declaring->tip, /*$6*/0, (yyvsp[-2].ls));
			}
#line 1769 "y.tab.c"
    break;

  case 37:
#line 213 "limbaj.y"
                          {(yyval.ls) = malloc(sizeof(struct list)); (yyval.ls)->nr_dimensiuni = 0;}
#line 1775 "y.tab.c"
    break;

  case 39:
#line 217 "limbaj.y"
                             {(yyval.ls) = malloc(sizeof(struct list)); (yyval.ls)->dimensiune[0] = (yyvsp[0].symbol); (yyval.ls)->nr_dimensiuni = 1;}
#line 1781 "y.tab.c"
    break;

  case 40:
#line 218 "limbaj.y"
                                                           {(yyval.ls) = (yyvsp[-2].ls); (yyval.ls)->dimensiune[(yyval.ls)->nr_dimensiuni++] = (yyvsp[0].symbol);}
#line 1787 "y.tab.c"
    break;

  case 41:
#line 221 "limbaj.y"
                                {
									(yyval.symbol) = malloc(sizeof(struct simbol)); 
									free((yyvsp[-2].tipD)->size);
									(yyvsp[-2].tipD)->size = (yyvsp[0].ls);
									(yyval.symbol)->tip = (yyvsp[-2].tipD);
									(yyval.symbol)->nume = strdup((yyvsp[-1].strval)); 
									(yyval.symbol)->valoare = 0;
								}
#line 1800 "y.tab.c"
    break;

  case 50:
#line 246 "limbaj.y"
                                            {
									if(exists_variable((yyvsp[-3].strval))<0)
									{
										char* error[100];
										strcpy(error,"Variable \"");
										strcat(error,(yyvsp[-3].strval));
										strcat(error, "\" is not declared.");
										yyerror(strdup(error));
										exit(0);
									}
									check_arrayList((yyvsp[-3].strval), (yyvsp[-2].ls));
									verify_assignement((yyvsp[-3].strval),tipuri_expresii,nr_expresii);
									nr_expresii=0;
									memset(tipuri_expresii, 0, sizeof(tipuri_expresii));

									int val = exists_variable((yyvsp[-3].strval));
									assign(val, (yyvsp[0].ast));
									freeAST((yyvsp[0].ast));
								}
#line 1824 "y.tab.c"
    break;

  case 51:
#line 265 "limbaj.y"
                                                                {
									if(exists_variable((yyvsp[-5].strval))<0)
									{
										char* error[100];
										strcpy(error,"Variable \"");
										strcat(error,(yyvsp[-5].strval));
										strcat(error, "\" is not declared.");
										yyerror(strdup(error));
										exit(0);
									}
									check_arrayList((yyvsp[-5].strval), (yyvsp[-4].ls));
									verify_assignement((yyvsp[-5].strval),tipuri_expresii,nr_expresii);
									nr_expresii=0;
									memset(tipuri_expresii, 0, sizeof(tipuri_expresii));

									int val = exists_variable((yyvsp[-5].strval));
									assign(val, (yyvsp[0].ast));
									freeAST((yyvsp[0].ast));
								}
#line 1848 "y.tab.c"
    break;

  case 53:
#line 287 "limbaj.y"
                                        {
										if(exists_function((yyvsp[-3].strval))>=0)
										{
											printf("%s function exists.\n",(yyvsp[-3].strval));
											verify_parameters((yyvsp[-3].strval),parameters,nr_parametri);
											if(verify_no_parameters((yyvsp[-3].strval))==1)
											{
												char* error[100];
												strcpy(error,"Function \"");
												strcat(error,(yyvsp[-3].strval));
												strcat(error, "\" isn't supposed to have parameters.");
												yyerror(strdup(error));
												exit(0);
											}
											nr_parametri = 0;
										}
										else
										{
											char* error[100];
											strcpy(error,"Function \"");
											strcat(error,(yyvsp[-3].strval));
											strcat(error, "\" is not declared.");
											yyerror(strdup(error));
											exit(0);
										}
									}
#line 1879 "y.tab.c"
    break;

  case 54:
#line 313 "limbaj.y"
                                {
							if(exists_function((yyvsp[-2].strval))>=0)
							{
								printf("%s function exists.\n",(yyvsp[-2].strval));
								verify_parameters((yyvsp[-2].strval),parameters,nr_parametri);

								if(verify_no_parameters((yyvsp[-2].strval))==1)
								{
									char* error[100];
									strcpy(error,"Function \"");
									strcat(error,(yyvsp[-2].strval));
									strcat(error, "\" isn't supposed to have parameters.");
									yyerror(strdup(error));
									exit(0);
								}
								nr_parametri = 0;
							}
							else
							{
								char* error[100];
								strcpy(error,"Function \"");
								strcat(error,(yyvsp[-2].strval));
								strcat(error, "\" is not declared.");
								yyerror(strdup(error));
								exit(0);
							}
						}
#line 1911 "y.tab.c"
    break;

  case 68:
#line 367 "limbaj.y"
                                               {}
#line 1917 "y.tab.c"
    break;

  case 72:
#line 373 "limbaj.y"
                                                {
										verify_expresie(tipuri_expresii,nr_expresii);
										nr_expresii=0;
										memset(tipuri_expresii, 0, sizeof(tipuri_expresii));
			 						}
#line 1927 "y.tab.c"
    break;

  case 73:
#line 381 "limbaj.y"
                        {}
#line 1933 "y.tab.c"
    break;

  case 74:
#line 382 "limbaj.y"
                                         {}
#line 1939 "y.tab.c"
    break;

  case 75:
#line 385 "limbaj.y"
                {
					if(exists_variable((yyvsp[0].strval))>=0)
					{
						strcpy(parameters[nr_parametri],(yyvsp[0].strval));
						nr_parametri++;
					}
					else
					{
						char* error[100];
						strcpy(error,"Variable \"");
						strcat(error,(yyvsp[0].strval));
						strcat(error, "\" is not declared.");
						yyerror(strdup(error));
						exit(0);
					}		
				}
#line 1960 "y.tab.c"
    break;

  case 76:
#line 404 "limbaj.y"
                             {	
								verify_expresie(tipuri_expresii,nr_expresii);
								if(is_ASTint((yyvsp[-1].ast)) == 0) {
									yyerror("Type unsupported for eval");
									exit(0);
								}
								int rez = EvalAST((yyvsp[-1].ast));
								printf("Eval result : %d\n",rez);
								freeAST((yyvsp[-1].ast));
								nr_expresii=0;
								memset(tipuri_expresii, 0, sizeof(tipuri_expresii));
							}
#line 1977 "y.tab.c"
    break;

  case 77:
#line 418 "limbaj.y"
                                        {
										strcpy(elemente_expresie[nr_elemente_expresie],"+");
										nr_elemente_expresie++;
										char k = '+';
										(yyval.ast) = buildAST(&k, (yyvsp[-2].ast), (yyvsp[0].ast), OP);
									}
#line 1988 "y.tab.c"
    break;

  case 78:
#line 424 "limbaj.y"
                                {
								strcpy(elemente_expresie[nr_elemente_expresie],"*");
								nr_elemente_expresie++;
								char k = '*';
								(yyval.ast) = buildAST(&k, (yyvsp[-2].ast), (yyvsp[0].ast), OP);
							}
#line 1999 "y.tab.c"
    break;

  case 79:
#line 430 "limbaj.y"
                                {
								strcpy(elemente_expresie[nr_elemente_expresie],"-");
								nr_elemente_expresie++;
								char k = '-';
								(yyval.ast) = buildAST(&k, (yyvsp[-2].ast), (yyvsp[0].ast), OP);
							}
#line 2010 "y.tab.c"
    break;

  case 80:
#line 436 "limbaj.y"
                                {
								strcpy(elemente_expresie[nr_elemente_expresie],"/");
								nr_elemente_expresie++;
								char k = '/';
								(yyval.ast) = buildAST(&k, (yyvsp[-2].ast), (yyvsp[0].ast), OP);
							}
#line 2021 "y.tab.c"
    break;

  case 81:
#line 442 "limbaj.y"
                    {(yyval.ast) = (yyvsp[-1].ast);}
#line 2027 "y.tab.c"
    break;

  case 82:
#line 443 "limbaj.y"
        {
			nume_typeof = (yyvsp[0].intval);
			typeOf = "int";
			is_int=1;
			tipuri_expresii[nr_expresii] = 1;
			nr_expresii++;
			int a = (yyvsp[0].intval);
			(yyval.ast) = buildAST(&a, 0, 0, INT);
		}
#line 2041 "y.tab.c"
    break;

  case 83:
#line 452 "limbaj.y"
                {
				nume_typeof = (yyvsp[0].strval);
				typeOf = "string";
				is_string=1;
				tipuri_expresii[nr_expresii] = 4;
				nr_expresii++;
				int a = (yyvsp[0].strval);
				(yyval.ast) = buildAST(&a, 0, 0, STR);
			}
#line 2055 "y.tab.c"
    break;

  case 84:
#line 461 "limbaj.y"
                {
				f = (yyvsp[0].floatval);
				typeOf = "float";
				is_float=1;
				tipuri_expresii[nr_expresii] = 2;
				nr_expresii++;
				int a = (yyvsp[0].floatval);
				(yyval.ast) = buildAST(&a, 0, 0, FLT);
			}
#line 2069 "y.tab.c"
    break;

  case 85:
#line 470 "limbaj.y"
        {
			nume_typeof = (yyvsp[0].charval);
			typeOf = "char";
			is_char=1;
			tipuri_expresii[nr_expresii] = 3;
			nr_expresii++;
				int a = (yyvsp[0].charval);
				(yyval.ast) = buildAST(&a, 0, 0, CHR);
 		}
#line 2083 "y.tab.c"
    break;

  case 86:
#line 479 "limbaj.y"
        {
			if((yyvsp[0].intval) == 1)
			{
				nume_typeof = "true";
			}
			else
			{
				nume_typeof = "false";
			}
			typeOf = "bool";
			tipuri_expresii[nr_expresii] = 5;
			nr_expresii++;
			int a = (yyvsp[0].intval);
			(yyval.ast) = buildAST(&a, 0, 0, BOL);
		}
#line 2103 "y.tab.c"
    break;

  case 87:
#line 494 "limbaj.y"
                        {
			if(exists_variable((yyvsp[-1].strval))>=0)
			{
				check_arrayList((yyvsp[-1].strval), (yyvsp[0].ls));
				nume_typeof = (yyvsp[-1].strval);
				if(get_typeof((yyvsp[-1].strval))==1)
				{
					typeOf = "int";
				}
				else if(get_typeof((yyvsp[-1].strval))==2)
				{
					typeOf = "float";
				}
				else if(get_typeof((yyvsp[-1].strval))==3)
				{
					typeOf = "char";
				}
				else if(get_typeof((yyvsp[-1].strval))==4)
				{
					typeOf = "string";
				}
				else if(get_typeof((yyvsp[-1].strval))==5)
				{
					typeOf = "bool";
				}
				else {
					typeOf = structNames[get_typeof((yyvsp[-1].strval))-6];
				}
				tipuri_expresii[nr_expresii] = get_typeof((yyvsp[-1].strval));
				strcpy(elemente_expresie[nr_elemente_expresie],(yyvsp[-1].strval));
				nr_expresii++;
				nr_elemente_expresie++;
				(yyval.ast) = buildAST((yyvsp[-1].strval), 0, 0, IDENTIFIER);
			}
			else
			{
				char* error[100];
				strcpy(error,"Variable \"");
				strcat(error,(yyvsp[-1].strval));
				strcat(error, "\" is not declared.");
				yyerror(strdup(error));
				exit(0);
			}
 		}
#line 2152 "y.tab.c"
    break;

  case 88:
#line 538 "limbaj.y"
                        {
			if(exists_variable((yyvsp[-3].strval))>=0)
			{
				check_arrayList((yyvsp[-3].strval), (yyvsp[-2].ls));
				nume_typeof = (yyvsp[-3].strval);
				if(get_typeof((yyvsp[-3].strval))==1)
				{
					typeOf = "int";
				}
				else if(get_typeof((yyvsp[-3].strval))==2)
				{
					typeOf = "float";
				}
				else if(get_typeof((yyvsp[-3].strval))==3)
				{
					typeOf = "char";
				}
				else if(get_typeof((yyvsp[-3].strval))==4)
				{
					typeOf = "string";
				}
				else if(get_typeof((yyvsp[-3].strval))==5)
				{
					typeOf = "bool";
				}
				else {
					typeOf = structNames[get_typeof((yyvsp[-3].strval))-6];
				}
				tipuri_expresii[nr_expresii] = get_typeof((yyvsp[-3].strval));
				strcpy(elemente_expresie[nr_elemente_expresie],(yyvsp[-3].strval));
				nr_expresii++;
				nr_elemente_expresie++;
				(yyval.ast) = buildAST((yyvsp[-3].strval), 0, 0, IDENTIFIER);
			}
			else
			{
				char* error[100];
				strcpy(error,"Variable \"");
				strcat(error,(yyvsp[-3].strval));
				strcat(error, "\" is not declared.");
				yyerror(strdup(error));
				exit(0);
			}
 		}
#line 2201 "y.tab.c"
    break;

  case 89:
#line 582 "limbaj.y"
                                {
								if(exists_function((yyvsp[-3].strval))>=0)
								{
									verify_parameters((yyvsp[-3].strval),parameters,nr_parametri);
									if(verify_no_parameters((yyvsp[-3].strval))==1)
									{
										char* error[100];
										strcpy(error,"Function \"");
										strcat(error,(yyvsp[-3].strval));
										strcat(error, "\" isn't supposed to have parameters.");
										yyerror(strdup(error));
										exit(0);
									}
									else
									{
										nume_typeof = (yyvsp[-3].strval);
										is_char = 0;is_string = 0;is_int = 0;is_float = 0;
										if(get_typeof((yyvsp[-3].strval))==1)
										{
											typeOf = "int";
										}
										else if(get_typeof((yyvsp[-3].strval))==2)
										{
											typeOf = "float";
										}
										else if(get_typeof((yyvsp[-3].strval))==3)
										{
											typeOf = "char";
										}
										else if(get_typeof((yyvsp[-3].strval))==4)
										{
											typeOf = "string";
										}
										else if(get_typeof((yyvsp[-3].strval))==5)
										{
											typeOf = "bool";
										}
										tipuri_expresii[nr_expresii] = get_typeof((yyvsp[-3].strval));
										strcpy(elemente_expresie[nr_elemente_expresie],(yyvsp[-3].strval));
										nr_expresii++;
										nr_elemente_expresie++;
									}
									nr_parametri=0;
									(yyval.ast) = buildAST((yyvsp[-3].strval), 0, 0, FNC);
								}
								else
								{
									char* error[100];
									strcpy(error,"Function \"");
									strcat(error,(yyvsp[-3].strval));
									strcat(error, "\" is not declared.");
									yyerror(strdup(error));
									exit(0);
								}
							}
#line 2261 "y.tab.c"
    break;

  case 90:
#line 637 "limbaj.y"
                {
				if(exists_function((yyvsp[-2].strval))>=0)
				{
					verify_parameters((yyvsp[-2].strval),parameters,nr_parametri);
					if(verify_no_parameters((yyvsp[-2].strval))==1)
					{
						nume_typeof = (yyvsp[-2].strval);
						if(get_typeof(nume_typeof)==1)
						{
							typeOf = "int";
						}
						else if(get_typeof(nume_typeof)==2)
						{
							typeOf = "float";
						}
						else if(get_typeof(nume_typeof)==3)
						{
							typeOf = "char";
						}
						else if(get_typeof(nume_typeof)==4)
						{
							typeOf = "string";
						}
						else if(get_typeof(nume_typeof)==5)
						{
							typeOf = "bool";
						}
						tipuri_expresii[nr_expresii] = get_typeof((yyvsp[-2].strval));
						strcpy(elemente_expresie[nr_elemente_expresie],(yyvsp[-2].strval));
						nr_expresii++;
						nr_elemente_expresie++;
						(yyval.ast) = buildAST((yyvsp[-2].strval),0,0,FNC);
					}
					else
					{
						char* error[100];
						strcpy(error,"Function \"");
						strcat(error,(yyvsp[-2].strval));
						strcat(error, "\" isn't supposed to have parameters.");
						yyerror(strdup(error));
						exit(0);
					}
					nr_parametri = 0;
				}
				else
				{
					char* error[100];
					strcpy(error,"Function \"");
					strcat(error,(yyvsp[-2].strval));
					strcat(error, "\" is not declared.");
					yyerror(strdup(error));
					exit(0);
				}
			}
#line 2320 "y.tab.c"
    break;


#line 2324 "y.tab.c"

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
#line 692 "limbaj.y"

void yyerror(char * s)
{
  	printf("ERROR: %s line:%d\n",s,yylineno);
}

int main(int argc, char** argv)
{
	yyin=fopen(argv[1],"r");
	yyparse();
}
