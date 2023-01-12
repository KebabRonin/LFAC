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
int is_parameter=0;
char parametri[100][100];

struct AstNode* buildAST(char* root, struct AstNode* left, struct AstNode* right, int type);
void freeAST(struct AstNode* self);
int EvalAST(struct AstNode* root);

void new_entry_sy(char* nume, int is_const, char* tip, char* valoare, struct list* matrix);
void new_entry_fn(char* nume, struct Tip_Date* ret, struct list* param);
void export_sy_table();
void export_fn_table();


#line 109 "y.tab.c"

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
#line 39 "limbaj.y"

int intval;
char* strval;
char charval;
float floatval;
struct Tip_Date* tipD;
struct list* ls;
struct simbol* symbol;
struct AstNode* ast;

#line 226 "y.tab.c"

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
#define YYLAST   240

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

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
       0,    63,    63,    66,    67,    67,    74,    75,    75,    78,
      79,    82,    83,    86,    91,    92,    95,    96,    96,   101,
     102,   105,   106,   113,   118,   106,   126,   129,   132,   135,
     138,   141,   183,   184,   196,   200,   204,   208,   214,   215,
     218,   219,   222,   231,   231,   233,   236,   237,   241,   242,
     243,   244,   248,   267,   288,   289,   289,   315,   341,   342,
     343,   346,   347,   348,   349,   352,   353,   356,   359,   362,
     365,   368,   371,   372,   373,   374,   382,   388,   396,   396,
     413,   419,   425,   431,   437,   438,   454,   470,   486,   502,
     524,   574,   618,   618,   674
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
  "param", "bloc", "$@7", "instr_bloc", "list", "assignment", "statement",
  "$@8", "control_statement", "if_statement", "else_statement",
  "while_statement", "do_while_statement", "for_statement",
  "boolean_expr_atomic", "boolean_expr", "lista_apel", "eval", "$@9",
  "expresie", "$@10", YY_NULLPTR
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

#define YYPACT_NINF (-144)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-61)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -16,  -144,    12,   -11,  -144,  -144,  -144,    19,    80,    80,
    -144,    50,  -144,    46,    39,    63,  -144,  -144,    96,   104,
     106,  -144,  -144,  -144,   115,   164,   119,    92,   130,  -144,
     186,  -144,    36,  -144,  -144,  -144,  -144,  -144,   164,   112,
     107,   -12,    80,  -144,    82,   116,   118,   145,   122,  -144,
    -144,   176,  -144,   113,   125,  -144,  -144,  -144,  -144,  -144,
     124,   141,   126,   183,   164,   164,   164,   164,  -144,   159,
    -144,   168,   174,   148,   144,  -144,   153,   157,     5,   175,
     175,   186,   178,  -144,  -144,   195,   172,  -144,   169,   125,
    -144,  -144,   164,   177,   204,  -144,   105,   105,  -144,  -144,
     164,   107,   107,   181,    80,  -144,  -144,   164,   164,   219,
     175,  -144,     1,    26,    30,    14,   196,   107,   191,   164,
    -144,   -13,   197,   107,  -144,   197,   225,  -144,   114,  -144,
      64,    77,   197,   226,    40,    79,   175,   175,   145,   164,
     145,  -144,   175,   175,   190,  -144,   164,  -144,   164,  -144,
     136,  -144,  -144,  -144,   164,  -144,   210,  -144,   214,   197,
    -144,    44,    69,  -144,   197,   197,  -144,   119,   119,   197,
     145,  -144,   202,   195,  -144,   198,    65,  -144,  -144,   201,
     206,  -144,   145,  -144,  -144
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     4,     0,     9,     6,     1,    11,    14,     5,    10,
      21,     0,    26,     0,     0,     0,     7,    30,     0,    15,
      43,     2,    28,    27,     0,     0,     0,     0,     0,    45,
       0,    29,    32,    85,    86,    87,    88,    89,     0,     0,
      32,     0,    38,    22,    32,     0,     0,     0,     0,    78,
      59,     0,    54,     0,    49,    61,    62,    63,    64,    58,
      92,     0,    90,     0,     0,     0,     0,     0,    31,    34,
       8,     0,     0,     0,    39,    40,     0,    55,     0,     0,
       0,     0,     0,    46,    60,     0,     0,    44,     0,    50,
      48,    94,     0,     0,     0,    84,    80,    82,    81,    83,
       0,    32,    32,     0,     0,    16,    57,     0,     0,     0,
       0,    75,     0,     0,     0,     0,     0,    32,     0,     0,
      51,     0,    76,    32,    91,    35,    36,    42,     0,    41,
       0,     0,    52,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,     0,     0,    93,     0,    33,     0,    13,
       0,    23,    17,    56,     0,    72,    73,    74,    66,    71,
      68,     0,     0,    79,    77,    37,    12,    20,     0,    53,
       0,    65,     0,     0,    24,    19,     0,    67,    69,     0,
       0,    18,     0,    25,    70
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,    -4,    -6,   -21,  -143,
    -144,  -144,   132,  -144,  -144,  -122,   -75,   -84,   -23,  -144,
     -22,  -144,  -144,  -144,  -144,  -144,  -144,   -66,   133,  -144,
    -144,   -25,  -144
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     8,    26,     7,     9,    11,   130,
     168,   174,    19,    76,   167,   180,    72,    50,    78,    41,
      73,    74,    75,    21,    30,    82,    51,    52,    83,   107,
      84,    55,   171,    56,    57,    58,   111,   112,   121,    59,
      86,   113,    92
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,   118,    17,    17,    16,    18,   115,    53,    54,     1,
     108,    62,     5,    63,   114,     6,   158,    44,   160,    69,
      70,   145,   136,   137,   175,   176,   146,    71,    88,    89,
      45,    46,    47,   139,    48,   138,    17,    15,    49,    96,
      97,    98,    99,    23,   134,   109,    10,    24,   177,    22,
     141,   136,   137,   150,    64,    65,    66,    67,    53,    54,
     184,   136,   137,    20,   140,   136,   137,   122,    12,    60,
     156,   157,    13,    61,   155,   125,   161,   162,   172,    14,
     126,   127,   122,   132,    12,   135,   139,    15,    13,   179,
     136,   137,    88,    89,   144,    14,    25,   181,    17,    27,
     151,   173,   147,    15,    71,    53,    54,    64,    65,    66,
      67,   153,    28,    95,   159,    77,   146,    44,    31,    61,
      29,   164,    40,   165,    17,    42,   152,    88,    89,   169,
      45,    46,    47,    43,    48,    66,    67,    15,    49,    44,
      64,    65,    66,    67,    61,    90,    68,    93,    44,    79,
     149,    80,    45,    46,    47,    85,    48,   -60,    91,    15,
      49,    45,    46,    47,   100,    48,    94,    32,    15,    49,
      33,   101,   166,    34,    35,    36,    37,   102,    32,    44,
      81,    33,   103,   104,    34,    35,    36,    37,   105,    44,
      87,   106,    45,    46,    47,   116,    48,    38,   117,    15,
      49,   120,    45,    46,    47,   119,    48,   124,   110,    15,
      49,    64,    65,    66,    67,   123,   128,    95,    64,    65,
      66,    67,   133,   143,   163,    64,    65,    66,    67,   142,
     148,   154,   137,   170,   178,   182,   129,    71,   183,     0,
     131
};

static const yytype_int16 yycheck[] =
{
      25,    85,     8,     9,     8,     9,    81,    30,    30,    25,
       5,    32,     0,    38,    80,    26,   138,     3,   140,    40,
      32,    34,    21,    22,   167,   168,    39,    39,    51,    51,
      16,    17,    18,     7,    20,    34,    42,    23,    24,    64,
      65,    66,    67,     4,   110,    40,    27,     8,   170,     3,
      36,    21,    22,   128,    28,    29,    30,    31,    81,    81,
     182,    21,    22,    13,    34,    21,    22,    92,     4,    33,
     136,   137,     8,    37,    34,   100,   142,   143,    34,    15,
     101,   102,   107,   108,     4,   110,     7,    23,     8,   173,
      21,    22,   115,   115,   119,    15,    33,    32,   104,     3,
      36,    32,   123,    23,    39,   128,   128,    28,    29,    30,
      31,    34,     8,    34,   139,    33,    39,     3,     3,    37,
      14,   146,     3,   148,   130,    33,   130,   150,   150,   154,
      16,    17,    18,     3,    20,    30,    31,    23,    24,     3,
      28,    29,    30,    31,    37,    32,    34,     6,     3,    33,
      36,    33,    16,    17,    18,    33,    20,    32,    34,    23,
      24,    16,    17,    18,     5,    20,    40,     3,    23,    24,
       6,     3,    36,     9,    10,    11,    12,     3,     3,     3,
      35,     6,    34,    39,     9,    10,    11,    12,    35,     3,
      14,    34,    16,    17,    18,    17,    20,    33,     3,    23,
      24,    32,    16,    17,    18,    33,    20,     3,    33,    23,
      24,    28,    29,    30,    31,    38,    35,    34,    28,    29,
      30,    31,     3,    32,    34,    28,    29,    30,    31,    33,
       5,     5,    22,    19,    32,    34,   104,    39,    32,    -1,
     107
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    25,    42,    43,    44,     0,    26,    47,    45,    48,
      27,    49,     4,     8,    15,    23,    57,    58,    57,    53,
      13,    64,     3,     4,     8,    33,    46,     3,     8,    14,
      65,     3,     3,     6,     9,    10,    11,    12,    33,    82,
       3,    60,    33,     3,     3,    16,    17,    18,    20,    24,
      58,    67,    68,    69,    71,    72,    74,    75,    76,    80,
      33,    37,    59,    82,    28,    29,    30,    31,    34,    59,
      32,    39,    57,    61,    62,    63,    54,    33,    59,    33,
      33,    35,    66,    69,    71,    33,    81,    14,    69,    71,
      32,    34,    83,     6,    40,    34,    82,    82,    82,    82,
       5,     3,     3,    34,    39,    35,    34,    70,     5,    40,
      33,    77,    78,    82,    78,    67,    17,     3,    68,    33,
      32,    79,    82,    38,     3,    82,    59,    59,    35,    63,
      50,    79,    82,     3,    78,    82,    21,    22,    34,     7,
      34,    36,    33,    32,    82,    34,    39,    59,     5,    36,
      67,    36,    57,    34,     5,    34,    78,    78,    66,    82,
      66,    78,    78,    34,    82,    82,    36,    55,    51,    82,
      19,    73,    34,    32,    52,    60,    60,    66,    32,    68,
      56,    32,    34,    32,    66
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    44,    43,    45,    46,    45,    47,
      47,    48,    48,    48,    49,    49,    50,    51,    50,    52,
      52,    53,    54,    55,    56,    53,    57,    57,    57,    57,
      57,    58,    59,    59,    60,    60,    60,    60,    61,    61,
      62,    62,    63,    65,    64,    64,    66,    66,    67,    67,
      67,    67,    68,    68,    69,    70,    69,    69,    69,    69,
      69,    71,    71,    71,    71,    72,    72,    73,    74,    75,
      76,    77,    78,    78,    78,    78,    79,    79,    81,    80,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    83,    82,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     0,     0,     3,     0,     0,     5,     0,
       2,     0,     9,     8,     0,     2,     0,     0,     5,     1,
       0,     0,     0,     0,     0,    11,     1,     2,     2,     3,
       1,     4,     0,     4,     2,     4,     4,     6,     0,     1,
       1,     3,     3,     0,     4,     2,     1,     3,     2,     1,
       2,     3,     4,     6,     1,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     6,     5,     2,     5,     7,
       9,     3,     3,     3,     3,     1,     1,     3,     0,     5,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       2,     4,     0,     5,     3
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
#line 63 "limbaj.y"
                                                                   {printf("\nCORRECT PROGRAM\n");}
#line 1545 "y.tab.c"
    break;

  case 4:
#line 67 "limbaj.y"
                                             { make_sym_table(0); }
#line 1551 "y.tab.c"
    break;

  case 5:
#line 67 "limbaj.y"
                                                                                                {	
																					export_sy_table();
																					nr_expresii=0;
																					memset(tipuri_expresii, 0, sizeof(tipuri_expresii));
																				}
#line 1561 "y.tab.c"
    break;

  case 7:
#line 75 "limbaj.y"
                                                                        {now_declaring = (yyvsp[0].tipD);}
#line 1567 "y.tab.c"
    break;

  case 10:
#line 79 "limbaj.y"
                                                          {export_fn_table();}
#line 1573 "y.tab.c"
    break;

  case 12:
#line 83 "limbaj.y"
                                                                                                {
																						new_entry_fn((yyvsp[-6].strval), (yyvsp[-7].tipD), (yyvsp[-4].ls));
																					}
#line 1581 "y.tab.c"
    break;

  case 13:
#line 86 "limbaj.y"
                                                                                          {
							new_entry_fn((yyvsp[-5].strval), (yyvsp[-6].tipD), (yyvsp[-3].ls));
						}
#line 1589 "y.tab.c"
    break;

  case 15:
#line 92 "limbaj.y"
                                                                   {export_sy_table();}
#line 1595 "y.tab.c"
    break;

  case 17:
#line 96 "limbaj.y"
                                                                {
					now_declaring = (yyvsp[0].tipD); 
					}
#line 1603 "y.tab.c"
    break;

  case 22:
#line 106 "limbaj.y"
                                                                                 {
					userdef_table.dimensiune[userdef_table.nr_dimensiuni] = (char*) (malloc(sizeof(struct UserDef))); 
					((struct UserDef*)(userdef_table.dimensiune[userdef_table.nr_dimensiuni]))->nume = strdup((yyvsp[0].strval));
					strcpy(structNames[userdef_table.nr_dimensiuni], (yyvsp[0].strval));
					((struct UserDef*)(userdef_table.dimensiune[userdef_table.nr_dimensiuni]))->date = malloc(sizeof(struct tabela_simboluri));
					make_sym_table((((struct UserDef*)(userdef_table.dimensiune[userdef_table.nr_dimensiuni]))->date));
					userdef_table.nr_dimensiuni++;
					}
#line 1616 "y.tab.c"
    break;

  case 23:
#line 113 "limbaj.y"
                                                                    {
						now_declaring = malloc(sizeof(struct Tip_Date));
						now_declaring->is_const = 0;
						now_declaring->tip = strdup((yyvsp[-4].strval));
						make_sym_table(0);
					}
#line 1627 "y.tab.c"
    break;

  case 24:
#line 118 "limbaj.y"
                                                       {
						now_declaring->is_const = 0;
						free(now_declaring->tip);
						free(now_declaring);
						now_declaring = 0;
					}
#line 1638 "y.tab.c"
    break;

  case 26:
#line 126 "limbaj.y"
               {(yyval.tipD) = malloc(sizeof(struct Tip_Date)); (yyval.tipD)->tip = strdup((yyvsp[0].strval)); (yyval.tipD)->is_const = 0; 
				(yyval.tipD)->size = malloc(sizeof(struct list)); (yyval.tipD)->size->nr_dimensiuni=0;
				}
#line 1646 "y.tab.c"
    break;

  case 27:
#line 129 "limbaj.y"
                             {(yyval.tipD) = malloc(sizeof(struct Tip_Date)); (yyval.tipD)->tip = strdup((yyvsp[0].strval)); (yyval.tipD)->is_const = 1;
				(yyval.tipD)->size = malloc(sizeof(struct list)); (yyval.tipD)->size->nr_dimensiuni=0;
				}
#line 1654 "y.tab.c"
    break;

  case 28:
#line 132 "limbaj.y"
                            {(yyval.tipD) = malloc(sizeof(struct Tip_Date)); (yyval.tipD)->tip = strdup((yyvsp[0].strval)); (yyval.tipD)->is_const = 0;
				(yyval.tipD)->size = malloc(sizeof(struct list)); (yyval.tipD)->size->nr_dimensiuni=0;
				}
#line 1662 "y.tab.c"
    break;

  case 29:
#line 135 "limbaj.y"
                                  {(yyval.tipD) = malloc(sizeof(struct Tip_Date)); (yyval.tipD)->tip = strdup((yyvsp[0].strval)); (yyval.tipD)->is_const = 1;
				(yyval.tipD)->size = malloc(sizeof(struct list)); (yyval.tipD)->size->nr_dimensiuni=0;
				}
#line 1670 "y.tab.c"
    break;

  case 30:
#line 138 "limbaj.y"
                          {(yyval.tipD) = NULL;}
#line 1676 "y.tab.c"
    break;

  case 31:
#line 141 "limbaj.y"
                                {
									verify_expresie(tipuri_expresii,nr_expresii);
									
									if(nr_elemente_expresie == 1)
									{
										if(is_char==1)
										{
											printf("TypeOf('%c') : %s\tLINE : %d\n",nume_typeof,typeOf,yylineno);
											is_char=0;
										}
										else if(is_string==1)
										{
											printf("TypeOf(\"%s\") : %s\tLINE : %d\n",nume_typeof,typeOf,yylineno);
											is_string=0;
										}
										else if(is_int==1)
										{
											printf("TypeOf(%d) : %s\tLINE : %d\n",nume_typeof,typeOf,yylineno);
											is_int=0;
										}
										else if(is_float==1)
										{
											printf("TypeOf(%f) : %s\tLINE : %d\n",f,typeOf,yylineno);
											is_float=0;
										}
										else
										{
											printf("TypeOf(%s) : %s\tLINE : %d\n",nume_typeof,typeOf,yylineno);
										}
									}
									else
									{
										printf("TypeOf() : %s\tLINE : %d\n",typeOf,yylineno);
									}
									
									nr_expresii=0;
									nr_elemente_expresie = 0;
									memset(tipuri_expresii, 0, sizeof(tipuri_expresii));
									memset(elemente_expresie, 0, sizeof(elemente_expresie));
	   							}
#line 1721 "y.tab.c"
    break;

  case 32:
#line 183 "limbaj.y"
                          {(yyval.ls) = malloc(sizeof(struct list)); (yyval.ls)->nr_dimensiuni=0;}
#line 1727 "y.tab.c"
    break;

  case 33:
#line 184 "limbaj.y"
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
#line 1742 "y.tab.c"
    break;

  case 34:
#line 196 "limbaj.y"
                          {
				// printf("list_id :%s %d %s howmany:%d\n", now_declaring->tip, now_declaring->is_const, $1, $2->nr_dimensiuni);
				new_entry_sy((yyvsp[-1].strval), now_declaring->is_const, now_declaring->tip, 0, (yyvsp[0].ls));
			}
#line 1751 "y.tab.c"
    break;

  case 35:
#line 200 "limbaj.y"
                                                  {
				// printf("list_id :%s %d %s howmany:%d\n", now_declaring->tip, now_declaring->is_const, $1, $2->nr_dimensiuni);
				new_entry_sy((yyvsp[-3].strval), now_declaring->is_const, now_declaring->tip, /*$4*/0, (yyvsp[-2].ls));
			}
#line 1760 "y.tab.c"
    break;

  case 36:
#line 204 "limbaj.y"
                                               {
			// printf("list_id :%s %d %s howmany:%d\n", now_declaring->tip, now_declaring->is_const, $3, $4->nr_dimensiuni);
			new_entry_sy((yyvsp[-1].strval), now_declaring->is_const, now_declaring->tip, 0, (yyvsp[0].ls));
			}
#line 1769 "y.tab.c"
    break;

  case 37:
#line 208 "limbaj.y"
                                                               {
				// printf("list_id :%s %d %s howmany:%d\n", now_declaring->tip, now_declaring->is_const, $3, $4->nr_dimensiuni);
				new_entry_sy((yyvsp[-3].strval), now_declaring->is_const, now_declaring->tip, /*$6*/0, (yyvsp[-2].ls));
			}
#line 1778 "y.tab.c"
    break;

  case 38:
#line 214 "limbaj.y"
                          {(yyval.ls) = malloc(sizeof(struct list)); (yyval.ls)->nr_dimensiuni = 0;}
#line 1784 "y.tab.c"
    break;

  case 40:
#line 218 "limbaj.y"
                             {(yyval.ls) = malloc(sizeof(struct list)); (yyval.ls)->dimensiune[0] = (yyvsp[0].symbol); (yyval.ls)->nr_dimensiuni = 1;}
#line 1790 "y.tab.c"
    break;

  case 41:
#line 219 "limbaj.y"
                                                           {(yyval.ls) = (yyvsp[-2].ls); (yyval.ls)->dimensiune[(yyval.ls)->nr_dimensiuni++] = (yyvsp[0].symbol);}
#line 1796 "y.tab.c"
    break;

  case 42:
#line 222 "limbaj.y"
                                {
									(yyval.symbol) = malloc(sizeof(struct simbol)); 
									free((yyvsp[-2].tipD)->size);
									(yyvsp[-2].tipD)->size = (yyvsp[0].ls);
									(yyval.symbol)->tip = (yyvsp[-2].tipD);
									(yyval.symbol)->nume = strdup((yyvsp[-1].strval)); 
									(yyval.symbol)->valoare = 0;
								}
#line 1809 "y.tab.c"
    break;

  case 43:
#line 231 "limbaj.y"
            {nr_expresii=0;
			memset(tipuri_expresii, 0, sizeof(tipuri_expresii));}
#line 1816 "y.tab.c"
    break;

  case 52:
#line 248 "limbaj.y"
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
#line 1840 "y.tab.c"
    break;

  case 53:
#line 267 "limbaj.y"
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
#line 1864 "y.tab.c"
    break;

  case 55:
#line 289 "limbaj.y"
                   {is_parameter=1;}
#line 1870 "y.tab.c"
    break;

  case 56:
#line 289 "limbaj.y"
                                                        {
										
										if(exists_function((yyvsp[-4].strval))>=0)
										{
											verify_parameters((yyvsp[-4].strval),parameters,nr_parametri);
											if(verify_no_parameters((yyvsp[-4].strval))==1)
											{
												char* error[100];
												strcpy(error,"Function \"");
												strcat(error,(yyvsp[-4].strval));
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
											strcat(error,(yyvsp[-4].strval));
											strcat(error, "\" is not declared.");
											yyerror(strdup(error));
											exit(0);
										}
									}
#line 1901 "y.tab.c"
    break;

  case 57:
#line 315 "limbaj.y"
                                {
							if(exists_function((yyvsp[-2].strval))>=0)
							{
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
#line 1932 "y.tab.c"
    break;

  case 71:
#line 368 "limbaj.y"
                                               {}
#line 1938 "y.tab.c"
    break;

  case 75:
#line 374 "limbaj.y"
                                                {
										verify_expresie(tipuri_expresii,nr_expresii);
										nr_expresii=0;
										memset(tipuri_expresii, 0, sizeof(tipuri_expresii));
			 						}
#line 1948 "y.tab.c"
    break;

  case 76:
#line 382 "limbaj.y"
                        {
							verify_expresie(tipuri_expresii,nr_expresii);
							is_parameter=1;
							nr_expresii=0;
							memset(tipuri_expresii, 0, sizeof(tipuri_expresii));
						}
#line 1959 "y.tab.c"
    break;

  case 77:
#line 388 "limbaj.y"
                                        {
											verify_expresie(tipuri_expresii,nr_expresii);
											is_parameter=1;
											nr_expresii=0;
											memset(tipuri_expresii, 0, sizeof(tipuri_expresii));
										}
#line 1970 "y.tab.c"
    break;

  case 78:
#line 396 "limbaj.y"
            {nr_expresii=0;
			 					memset(tipuri_expresii, 0, sizeof(tipuri_expresii));}
#line 1977 "y.tab.c"
    break;

  case 79:
#line 397 "limbaj.y"
                                                                                                                                      {	
								verify_expresie(tipuri_expresii,nr_expresii);
								if(is_ASTint((yyvsp[-1].ast)) == 0) {
									yyerror("Type unsupported for eval");
									exit(0);
								}
								
								int rez = EvalAST((yyvsp[-1].ast));
								printf("Eval Result : %d\tLINE: %d\n",rez,yylineno);
								freeAST((yyvsp[-1].ast));
								
								nr_expresii=0;
								memset(tipuri_expresii, 0, sizeof(tipuri_expresii));
							}
#line 1996 "y.tab.c"
    break;

  case 80:
#line 413 "limbaj.y"
                                        {
										strcpy(elemente_expresie[nr_elemente_expresie],"+");
										nr_elemente_expresie++;
										char k = '+';
										(yyval.ast) = buildAST(&k, (yyvsp[-2].ast), (yyvsp[0].ast), OP);
									}
#line 2007 "y.tab.c"
    break;

  case 81:
#line 419 "limbaj.y"
                                {
								strcpy(elemente_expresie[nr_elemente_expresie],"*");
								nr_elemente_expresie++;
								char k = '*';
								(yyval.ast) = buildAST(&k, (yyvsp[-2].ast), (yyvsp[0].ast), OP);
							}
#line 2018 "y.tab.c"
    break;

  case 82:
#line 425 "limbaj.y"
                                {
								strcpy(elemente_expresie[nr_elemente_expresie],"-");
								nr_elemente_expresie++;
								char k = '-';
								(yyval.ast) = buildAST(&k, (yyvsp[-2].ast), (yyvsp[0].ast), OP);
							}
#line 2029 "y.tab.c"
    break;

  case 83:
#line 431 "limbaj.y"
                                {
								strcpy(elemente_expresie[nr_elemente_expresie],"/");
								nr_elemente_expresie++;
								char k = '/';
								(yyval.ast) = buildAST(&k, (yyvsp[-2].ast), (yyvsp[0].ast), OP);
							}
#line 2040 "y.tab.c"
    break;

  case 84:
#line 437 "limbaj.y"
                    {(yyval.ast) = (yyvsp[-1].ast);}
#line 2046 "y.tab.c"
    break;

  case 85:
#line 438 "limbaj.y"
        {
			if(is_parameter==1)
			{
				//strcpy(parameters[nr_parametri],$1);
				sprintf(parameters[nr_parametri],"%d",(yyvsp[0].intval));
				nr_parametri++;
				is_parameter=0;
			}
			nume_typeof = (yyvsp[0].intval);
			typeOf = "int";
			is_int=1;
			tipuri_expresii[nr_expresii] = 1;
			nr_expresii++;
			int a = (yyvsp[0].intval);
			(yyval.ast) = buildAST(&a, 0, 0, INT);
		}
#line 2067 "y.tab.c"
    break;

  case 86:
#line 454 "limbaj.y"
                {
				if(is_parameter==1)
				{
					strcpy(parameters[nr_parametri],(yyvsp[0].strval));
					//sprintf(parameters[nr_parametri],"%d",$1);
					nr_parametri++;
					is_parameter=0;
				}
				nume_typeof = (yyvsp[0].strval);
				typeOf = "string";
				is_string=1;
				tipuri_expresii[nr_expresii] = 4;
				nr_expresii++;
				int a = (yyvsp[0].strval);
				(yyval.ast) = buildAST(&a, 0, 0, STR);
			}
#line 2088 "y.tab.c"
    break;

  case 87:
#line 470 "limbaj.y"
                {
				if(is_parameter==1)
				{
					//strcpy(parameters[nr_parametri],$1);
					sprintf(parameters[nr_parametri],"%f",(yyvsp[0].floatval));
					nr_parametri++;
					is_parameter=0;
				}
				f = (yyvsp[0].floatval);
				typeOf = "float";
				is_float=1;
				tipuri_expresii[nr_expresii] = 2;
				nr_expresii++;
				int a = (yyvsp[0].floatval);
				(yyval.ast) = buildAST(&a, 0, 0, FLT);
			}
#line 2109 "y.tab.c"
    break;

  case 88:
#line 486 "limbaj.y"
        {
			if(is_parameter==1)
			{
				//strcpy(parameters[nr_parametri],$1);
				sprintf(parameters[nr_parametri],"%c",(yyvsp[0].charval));
				nr_parametri++;
				is_parameter=0;
			}
			nume_typeof = (yyvsp[0].charval);
			typeOf = "char";
			is_char=1;
			tipuri_expresii[nr_expresii] = 3;
			nr_expresii++;
				int a = (yyvsp[0].charval);
				(yyval.ast) = buildAST(&a, 0, 0, CHR);
 		}
#line 2130 "y.tab.c"
    break;

  case 89:
#line 502 "limbaj.y"
        {
			if(is_parameter==1)
			{
				//strcpy(parameters[nr_parametri],$1);
				sprintf(parameters[nr_parametri],"%d",(yyvsp[0].intval));
				nr_parametri++;
				is_parameter=0;
			}
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
#line 2157 "y.tab.c"
    break;

  case 90:
#line 524 "limbaj.y"
                        {
						if(exists_variable((yyvsp[-1].strval))>=0)
						{
							if(is_parameter==1)
							{
								strcpy(parameters[nr_parametri],(yyvsp[-1].strval));
								nr_parametri++;
								is_parameter=0;
							}
							
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
#line 2212 "y.tab.c"
    break;

  case 91:
#line 574 "limbaj.y"
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
#line 2261 "y.tab.c"
    break;

  case 92:
#line 618 "limbaj.y"
          {is_parameter = 1;nr_parametri=0;}
#line 2267 "y.tab.c"
    break;

  case 93:
#line 618 "limbaj.y"
                                                                {
								
								if(exists_function((yyvsp[-4].strval))>=0)
								{
									verify_parameters((yyvsp[-4].strval),parameters,nr_parametri);
									if(verify_no_parameters((yyvsp[-4].strval))==1)
									{
										char* error[100];
										strcpy(error,"Function \"");
										strcat(error,(yyvsp[-4].strval));
										strcat(error, "\" isn't supposed to have parameters.");
										yyerror(strdup(error));
										exit(0);
									}
									else
									{
										nume_typeof = (yyvsp[-4].strval);
										is_char = 0;is_string = 0;is_int = 0;is_float = 0;
										if(get_typeof((yyvsp[-4].strval))==1)
										{
											typeOf = "int";
										}
										else if(get_typeof((yyvsp[-4].strval))==2)
										{
											typeOf = "float";
										}
										else if(get_typeof((yyvsp[-4].strval))==3)
										{
											typeOf = "char";
										}
										else if(get_typeof((yyvsp[-4].strval))==4)
										{
											typeOf = "string";
										}
										else if(get_typeof((yyvsp[-4].strval))==5)
										{
											typeOf = "bool";
										}
										tipuri_expresii[nr_expresii] = get_typeof((yyvsp[-4].strval));
										strcpy(elemente_expresie[nr_elemente_expresie],(yyvsp[-4].strval));
										nr_expresii++;
										nr_elemente_expresie++;
									}
									nr_parametri=0;
									(yyval.ast) = buildAST((yyvsp[-4].strval), 0, 0, FNC);
								}
								else
								{
									char* error[100];
									strcpy(error,"Function \"");
									strcat(error,(yyvsp[-4].strval));
									strcat(error, "\" is not declared.");
									yyerror(strdup(error));
									exit(0);
								}
							}
#line 2328 "y.tab.c"
    break;

  case 94:
#line 674 "limbaj.y"
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
#line 2387 "y.tab.c"
    break;


#line 2391 "y.tab.c"

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
#line 729 "limbaj.y"

void yyerror(char * s)
{
  	printf("ERROR: %s\tLINE:%d\n",s,yylineno);
}

int main(int argc, char** argv)
{
	yyin=fopen(argv[1],"r");
	yyparse();
}
