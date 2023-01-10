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

void new_entry_sy(char* nume, int is_const, char* tip, char* valoare, struct list* matrix);
void new_entry_fn(char* nume, struct Tip_Date* ret, struct list* param);
void export_sy_table();
void export_fn_table();


#line 101 "y.tab.c"

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
#line 31 "limbaj.y"

int intval;
char* strval;
char charval;
float floatval;
struct Tip_Date* tipD;
struct list* ls;
struct simbol* symbol;

#line 217 "y.tab.c"

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
#define YYLAST   226

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

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
      33,    34,    30,    28,    39,    29,     2,    31,     2,     2,
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
       0,    53,    53,    56,    57,    60,    61,    61,    64,    65,
      68,    69,    72,    77,    78,    81,    82,    85,    88,    91,
      94,    97,   100,   149,   150,   162,   166,   170,   174,   180,
     181,   184,   185,   188,   197,   198,   201,   202,   206,   207,
     208,   209,   213,   229,   230,   256,   283,   284,   285,   288,
     289,   290,   291,   294,   295,   298,   301,   304,   307,   310,
     313,   314,   315,   316,   324,   325,   328,   347,   350,   354,
     358,   362,   366,   367,   374,   381,   388,   395,   408,   447,
     501
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
  "'('", "')'", "'{'", "'}'", "'['", "']'", "','", "$accept", "progr",
  "declaratii_globale", "declaratii_globale_atomic", "$@1",
  "declaratii_fnc", "declaratii_fnc_atomic", "declaratii_structuri",
  "declaratii_structuri_atomic", "tip_date", "typeof", "lista_array",
  "lista_id", "lista_param", "lista_param_non_void", "param", "bloc",
  "instr_bloc", "list", "assignment", "statement", "control_statement",
  "if_statement", "else_statement", "while_statement",
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
      42,    47,    59,    40,    41,   123,   125,    91,    93,    44
};
# endif

#define YYPACT_NINF (-115)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-49)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -14,  -115,    25,     9,   107,  -115,  -115,    11,  -115,    66,
      60,    64,  -115,  -115,   107,  -115,    45,  -115,  -115,    95,
      70,   106,   120,   118,   149,  -115,  -115,    92,  -115,  -115,
    -115,  -115,  -115,    70,   125,    90,    16,   103,   141,     3,
    -115,   116,   127,   115,   128,   129,  -115,   165,  -115,   139,
     142,  -115,  -115,  -115,  -115,  -115,     6,   171,    70,    70,
      70,    70,  -115,   169,   173,  -115,   177,   107,   151,    70,
       7,   131,   131,   174,   159,  -115,  -115,   181,    70,  -115,
     155,   142,  -115,  -115,  -115,   -19,  -115,  -115,    63,    63,
    -115,  -115,   157,    70,    90,   190,   162,   164,  -115,  -115,
     185,  -115,    18,   131,  -115,    -3,    76,    78,    10,   184,
     199,   179,   178,  -115,  -115,   207,    90,   185,   213,    90,
      39,   107,    55,  -115,    80,   117,   131,   131,   115,    70,
     115,  -115,   131,   131,  -115,  -115,  -115,    70,  -115,  -115,
     174,  -115,  -115,  -115,   197,  -115,   201,   185,  -115,   136,
       0,   185,    72,   115,  -115,   189,   181,  -115,  -115,  -115,
     188,   115,  -115
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     5,     0,     8,     4,     1,    10,    13,    17,     0,
       0,     0,     6,    21,     9,    15,     0,    19,    18,     0,
       0,     0,     0,    14,     0,     2,    20,    78,    73,    74,
      75,    76,    77,     0,     0,    23,     0,     0,     0,     0,
      35,     0,     0,     0,     0,     0,    47,     0,    43,     0,
      39,    49,    50,    51,    52,    46,     0,     0,     0,     0,
       0,     0,    22,     0,    25,     7,     0,    29,     0,     0,
       0,     0,     0,     0,     0,    36,    48,     0,     0,    34,
       0,    40,    38,    66,    80,     0,    64,    72,    68,    70,
      69,    71,     0,     0,    23,     0,     0,    30,    31,     5,
      42,    45,     0,     0,    63,     0,     0,     0,     0,     0,
       0,     0,     0,    41,    79,     0,    23,    26,    27,    23,
       0,     0,     0,    44,     0,     0,     0,     0,     0,     0,
       0,    37,     0,     0,    67,    65,    24,     0,    33,    11,
       0,    32,    16,    60,    61,    62,    54,    59,    56,     0,
       0,    28,     0,     0,    53,     0,     0,    12,    55,    57,
       0,     0,    58
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,  -115,  -115,   124,  -115,  -115,  -115,  -115,  -115,   -11,
      -2,   -65,  -115,  -115,  -115,   104,  -115,  -114,   -68,   -70,
     -24,   -23,  -115,  -115,  -115,  -115,  -115,  -115,   -66,   154,
     111,  -115,   -16
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    21,     7,    14,    16,    23,    12,
      46,    64,    36,    96,    97,    98,    25,    74,    47,    48,
      75,    76,    51,   154,    52,    53,    54,   104,   105,    85,
      86,    55,   106
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    50,    13,    22,    34,   108,   107,   111,    69,    83,
      83,     1,    13,    39,   146,   114,   148,    57,   126,   127,
     115,   126,   127,    80,    81,     5,    41,    42,    43,   118,
      44,   128,   156,    11,    45,     6,    70,   124,    15,   158,
      84,   101,    88,    89,    90,    91,   131,   162,    65,    49,
      50,   136,   123,   100,   138,    66,    95,   115,    24,     8,
     144,   145,   112,     9,    18,    13,   149,   150,    19,    17,
      10,   139,   152,    27,   140,    39,    28,   117,    11,    29,
      30,    31,    32,   129,    80,    81,   160,   125,    41,    42,
      43,   142,    44,    60,    61,    11,    45,    20,    26,   126,
     127,   126,   127,    33,    58,    59,    60,    61,   157,    35,
      95,     8,   130,   147,   143,     9,    49,    50,    39,    13,
      13,   151,    10,    37,   129,    56,    38,    63,    80,    81,
      11,    41,    42,    43,    27,    44,    67,    28,    11,    45,
      29,    30,    31,    32,    68,    58,    59,    60,    61,    71,
      73,    87,    39,    58,    59,    60,    61,   126,   127,    62,
      72,    77,    78,    40,   103,    41,    42,    43,    39,    44,
     155,    82,    11,    45,   -48,    92,   109,    39,    93,    79,
      94,    41,    42,    43,   110,    44,    99,   113,    11,    45,
      41,    42,    43,   119,    44,   116,   120,    11,    45,    58,
      59,    60,    61,   121,    69,    87,    58,    59,    60,    61,
      83,   133,   134,    58,    59,    60,    61,   132,   137,   127,
     153,   159,   161,   122,   102,   141,   135
};

static const yytype_uint8 yycheck[] =
{
      24,    24,     4,    14,    20,    73,    72,    77,     5,     3,
       3,    25,    14,     3,   128,    34,   130,    33,    21,    22,
      39,    21,    22,    47,    47,     0,    16,    17,    18,    94,
      20,    34,    32,    23,    24,    26,    33,   103,    27,   153,
      34,    34,    58,    59,    60,    61,    36,   161,    32,    73,
      73,   116,    34,    69,   119,    39,    67,    39,    13,     4,
     126,   127,    78,     8,     4,    67,   132,   133,     8,     3,
      15,    32,   140,     3,    35,     3,     6,    93,    23,     9,
      10,    11,    12,     7,   108,   108,   156,   103,    16,    17,
      18,    36,    20,    30,    31,    23,    24,    33,     3,    21,
      22,    21,    22,    33,    28,    29,    30,    31,    36,     3,
     121,     4,    34,   129,    34,     8,   140,   140,     3,   121,
     122,   137,    15,     3,     7,    33,     8,    37,   152,   152,
      23,    16,    17,    18,     3,    20,    33,     6,    23,    24,
       9,    10,    11,    12,     3,    28,    29,    30,    31,    33,
      35,    34,     3,    28,    29,    30,    31,    21,    22,    34,
      33,    33,    33,    14,    33,    16,    17,    18,     3,    20,
      34,    32,    23,    24,    32,     6,    17,     3,     5,    14,
       3,    16,    17,    18,     3,    20,    35,    32,    23,    24,
      16,    17,    18,     3,    20,    38,    34,    23,    24,    28,
      29,    30,    31,    39,     5,    34,    28,    29,    30,    31,
       3,    32,    34,    28,    29,    30,    31,    33,     5,    22,
      19,    32,    34,    99,    70,   121,   115
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    25,    41,    42,    43,     0,    26,    45,     4,     8,
      15,    23,    49,    50,    46,    27,    47,     3,     4,     8,
      33,    44,    49,    48,    13,    56,     3,     3,     6,     9,
      10,    11,    12,    33,    72,     3,    52,     3,     8,     3,
      14,    16,    17,    18,    20,    24,    50,    58,    59,    60,
      61,    62,    64,    65,    66,    71,    33,    72,    28,    29,
      30,    31,    34,    37,    51,    32,    39,    33,     3,     5,
      33,    33,    33,    35,    57,    60,    61,    33,    33,    14,
      60,    61,    32,     3,    34,    69,    70,    34,    72,    72,
      72,    72,     6,     5,     3,    49,    53,    54,    55,    35,
      72,    34,    69,    33,    67,    68,    72,    68,    58,    17,
       3,    59,    72,    32,    34,    39,    38,    72,    51,     3,
      34,    39,    43,    34,    68,    72,    21,    22,    34,     7,
      34,    36,    33,    32,    34,    70,    51,     5,    51,    32,
      35,    55,    36,    34,    68,    68,    57,    72,    57,    68,
      68,    72,    58,    19,    63,    34,    32,    36,    57,    32,
      59,    34,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    44,    43,    45,    45,
      46,    46,    46,    47,    47,    48,    48,    49,    49,    49,
      49,    49,    50,    51,    51,    52,    52,    52,    52,    53,
      53,    54,    54,    55,    56,    56,    57,    57,    58,    58,
      58,    58,    59,    60,    60,    60,    60,    60,    60,    61,
      61,    61,    61,    62,    62,    63,    64,    65,    66,    67,
      68,    68,    68,    68,    69,    69,    70,    71,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     0,     2,     0,     0,     5,     0,     2,
       0,     7,     9,     0,     2,     0,     6,     1,     2,     2,
       3,     1,     4,     0,     4,     2,     4,     4,     6,     0,
       1,     1,     3,     3,     3,     2,     1,     3,     2,     1,
       2,     3,     3,     1,     4,     3,     1,     1,     1,     1,
       1,     1,     1,     6,     5,     2,     5,     7,     9,     3,
       3,     3,     3,     1,     1,     3,     1,     4,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     4,
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
#line 53 "limbaj.y"
                                                                   {printf("program corect sintactic\n");}
#line 1518 "y.tab.c"
    break;

  case 4:
#line 57 "limbaj.y"
                                                                       {export_sy_table();}
#line 1524 "y.tab.c"
    break;

  case 6:
#line 61 "limbaj.y"
                                                                        {now_declaring = (yyvsp[0].tipD);}
#line 1530 "y.tab.c"
    break;

  case 9:
#line 65 "limbaj.y"
                                                          {export_fn_table();}
#line 1536 "y.tab.c"
    break;

  case 11:
#line 69 "limbaj.y"
                                                                                       {
																				new_entry_fn((yyvsp[-4].strval), (yyvsp[-5].tipD), (yyvsp[-2].ls));
																			}
#line 1544 "y.tab.c"
    break;

  case 12:
#line 72 "limbaj.y"
                                                                                                {
																						new_entry_fn((yyvsp[-6].strval), (yyvsp[-7].tipD), (yyvsp[-4].ls));
																					}
#line 1552 "y.tab.c"
    break;

  case 17:
#line 85 "limbaj.y"
               {(yyval.tipD) = malloc(sizeof(struct Tip_Date)); (yyval.tipD)->tip = strdup((yyvsp[0].strval)); (yyval.tipD)->is_const = 0; 
				(yyval.tipD)->size = malloc(sizeof(struct list)); (yyval.tipD)->size->nr_dimensiuni=0;
				}
#line 1560 "y.tab.c"
    break;

  case 18:
#line 88 "limbaj.y"
                             {(yyval.tipD) = malloc(sizeof(struct Tip_Date)); (yyval.tipD)->tip = strdup((yyvsp[0].strval)); (yyval.tipD)->is_const = 1;
				(yyval.tipD)->size = malloc(sizeof(struct list)); (yyval.tipD)->size->nr_dimensiuni=0;
				}
#line 1568 "y.tab.c"
    break;

  case 19:
#line 91 "limbaj.y"
                            {(yyval.tipD) = malloc(sizeof(struct Tip_Date)); (yyval.tipD)->tip = strdup((yyvsp[0].strval)); (yyval.tipD)->is_const = 0;
				(yyval.tipD)->size = malloc(sizeof(struct list)); (yyval.tipD)->size->nr_dimensiuni=0;
				}
#line 1576 "y.tab.c"
    break;

  case 20:
#line 94 "limbaj.y"
                                  {(yyval.tipD) = malloc(sizeof(struct Tip_Date)); (yyval.tipD)->tip = strdup((yyvsp[0].strval)); (yyval.tipD)->is_const = 1;
				(yyval.tipD)->size = malloc(sizeof(struct list)); (yyval.tipD)->size->nr_dimensiuni=0;
				}
#line 1584 "y.tab.c"
    break;

  case 21:
#line 97 "limbaj.y"
                          {(yyval.tipD) = NULL;}
#line 1590 "y.tab.c"
    break;

  case 22:
#line 100 "limbaj.y"
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
										printf("TypeOf(expression) : %s\n",typeOf);
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
#line 1642 "y.tab.c"
    break;

  case 23:
#line 149 "limbaj.y"
                          {(yyval.ls) = malloc(sizeof(struct list)); (yyval.ls)->nr_dimensiuni=0;}
#line 1648 "y.tab.c"
    break;

  case 24:
#line 150 "limbaj.y"
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
#line 1663 "y.tab.c"
    break;

  case 25:
#line 162 "limbaj.y"
                          {
				// printf("list_id :%s %d %s howmany:%d\n", now_declaring->tip, now_declaring->is_const, $1, $2->nr_dimensiuni);
				new_entry_sy((yyvsp[-1].strval), now_declaring->is_const, now_declaring->tip, 0, (yyvsp[0].ls));
			}
#line 1672 "y.tab.c"
    break;

  case 26:
#line 166 "limbaj.y"
                                                  {
				// printf("list_id :%s %d %s howmany:%d\n", now_declaring->tip, now_declaring->is_const, $1, $2->nr_dimensiuni);
				new_entry_sy((yyvsp[-3].strval), now_declaring->is_const, now_declaring->tip, /*$4*/0, (yyvsp[-2].ls));
			}
#line 1681 "y.tab.c"
    break;

  case 27:
#line 170 "limbaj.y"
                                               {
			// printf("list_id :%s %d %s howmany:%d\n", now_declaring->tip, now_declaring->is_const, $3, $4->nr_dimensiuni);
			new_entry_sy((yyvsp[-1].strval), now_declaring->is_const, now_declaring->tip, 0, (yyvsp[0].ls));
			}
#line 1690 "y.tab.c"
    break;

  case 28:
#line 174 "limbaj.y"
                                                               {
				// printf("list_id :%s %d %s howmany:%d\n", now_declaring->tip, now_declaring->is_const, $3, $4->nr_dimensiuni);
				new_entry_sy((yyvsp[-3].strval), now_declaring->is_const, now_declaring->tip, /*$6*/0, (yyvsp[-2].ls));
			}
#line 1699 "y.tab.c"
    break;

  case 29:
#line 180 "limbaj.y"
                          {(yyval.ls) = malloc(sizeof(struct list)); (yyval.ls)->nr_dimensiuni = 0;}
#line 1705 "y.tab.c"
    break;

  case 31:
#line 184 "limbaj.y"
                             {(yyval.ls) = malloc(sizeof(struct list)); (yyval.ls)->dimensiune[0] = (yyvsp[0].symbol); (yyval.ls)->nr_dimensiuni = 1;}
#line 1711 "y.tab.c"
    break;

  case 32:
#line 185 "limbaj.y"
                                              {(yyval.ls) = (yyvsp[-2].ls); (yyval.ls)->dimensiune[(yyval.ls)->nr_dimensiuni++] = (yyvsp[0].symbol);}
#line 1717 "y.tab.c"
    break;

  case 33:
#line 188 "limbaj.y"
                                {
									(yyval.symbol) = malloc(sizeof(struct simbol)); 
									free((yyvsp[-2].tipD)->size);
									(yyvsp[-2].tipD)->size = (yyvsp[0].ls);
									(yyval.symbol)->tip = (yyvsp[-2].tipD);
									(yyval.symbol)->nume = strdup((yyvsp[-1].strval)); 
									(yyval.symbol)->valoare = 0;
								}
#line 1730 "y.tab.c"
    break;

  case 42:
#line 213 "limbaj.y"
                                {
									if(exists_variable((yyvsp[-2].strval))!=1)
									{
										char* error[100];
										strcpy(error,"Variable \"");
										strcat(error,(yyvsp[-2].strval));
										strcat(error, "\" is not declared.");
										yyerror(strdup(error));
										exit(0);
									}
									verify_assignement((yyvsp[-2].strval),tipuri_expresii,nr_expresii);
									nr_expresii=0;
									memset(tipuri_expresii, 0, sizeof(tipuri_expresii));
								}
#line 1749 "y.tab.c"
    break;

  case 44:
#line 230 "limbaj.y"
                                        {
										if(exists_function((yyvsp[-3].strval))==1)
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
#line 1780 "y.tab.c"
    break;

  case 45:
#line 256 "limbaj.y"
                                {
							if(exists_function((yyvsp[-2].strval))==1)
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
#line 1812 "y.tab.c"
    break;

  case 59:
#line 310 "limbaj.y"
                                               {}
#line 1818 "y.tab.c"
    break;

  case 63:
#line 316 "limbaj.y"
                                                {
										verify_expresie(tipuri_expresii,nr_expresii);
										nr_expresii=0;
										memset(tipuri_expresii, 0, sizeof(tipuri_expresii));
			 						}
#line 1828 "y.tab.c"
    break;

  case 64:
#line 324 "limbaj.y"
                        {}
#line 1834 "y.tab.c"
    break;

  case 65:
#line 325 "limbaj.y"
                                         {}
#line 1840 "y.tab.c"
    break;

  case 66:
#line 328 "limbaj.y"
                {
					if(exists_variable((yyvsp[0].strval))==1)
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
#line 1861 "y.tab.c"
    break;

  case 68:
#line 350 "limbaj.y"
                                        {
										strcpy(elemente_expresie[nr_elemente_expresie],"+");
										nr_elemente_expresie++;
									}
#line 1870 "y.tab.c"
    break;

  case 69:
#line 354 "limbaj.y"
                                {
								strcpy(elemente_expresie[nr_elemente_expresie],"*");
								nr_elemente_expresie++;
							}
#line 1879 "y.tab.c"
    break;

  case 70:
#line 358 "limbaj.y"
                                {
								strcpy(elemente_expresie[nr_elemente_expresie],"-");
								nr_elemente_expresie++;
							}
#line 1888 "y.tab.c"
    break;

  case 71:
#line 362 "limbaj.y"
                                {
								strcpy(elemente_expresie[nr_elemente_expresie],"/");
								nr_elemente_expresie++;
							}
#line 1897 "y.tab.c"
    break;

  case 72:
#line 366 "limbaj.y"
                    {}
#line 1903 "y.tab.c"
    break;

  case 73:
#line 367 "limbaj.y"
        {	
 			nume_typeof = (yyvsp[0].intval);
			typeOf = "int";
			is_int=1;
			tipuri_expresii[nr_expresii] = 1;
			nr_expresii++;
		}
#line 1915 "y.tab.c"
    break;

  case 74:
#line 374 "limbaj.y"
                {
				nume_typeof = (yyvsp[0].strval);
				typeOf = "string";
				is_string=1;
				tipuri_expresii[nr_expresii] = 4;
				nr_expresii++;
			}
#line 1927 "y.tab.c"
    break;

  case 75:
#line 381 "limbaj.y"
                {
				f = (yyvsp[0].floatval);
				typeOf = "float";
				is_float=1;
				tipuri_expresii[nr_expresii] = 2;
				nr_expresii++;
			}
#line 1939 "y.tab.c"
    break;

  case 76:
#line 388 "limbaj.y"
        {
			nume_typeof = (yyvsp[0].charval);
			typeOf = "char";
			is_char=1;
			tipuri_expresii[nr_expresii] = 3;
			nr_expresii++;
 		}
#line 1951 "y.tab.c"
    break;

  case 77:
#line 395 "limbaj.y"
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
		}
#line 1969 "y.tab.c"
    break;

  case 78:
#line 408 "limbaj.y"
        {
			if(exists_variable((yyvsp[0].strval))==1)
			{
				nume_typeof = (yyvsp[0].strval);
				if(get_typeof((yyvsp[0].strval))==1)
				{
					typeOf = "int";
				}
				else if(get_typeof((yyvsp[0].strval))==2)
				{
					typeOf = "float";
				}
				else if(get_typeof((yyvsp[0].strval))==3)
				{
					typeOf = "char";
				}
				else if(get_typeof((yyvsp[0].strval))==4)
				{
					typeOf = "string";
				}
				else if(get_typeof((yyvsp[0].strval))==5)
				{
					typeOf = "bool";
				}
				tipuri_expresii[nr_expresii] = get_typeof((yyvsp[0].strval));
				strcpy(elemente_expresie[nr_elemente_expresie],(yyvsp[0].strval));
				nr_expresii++;
				nr_elemente_expresie++;
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
#line 2013 "y.tab.c"
    break;

  case 79:
#line 447 "limbaj.y"
                                {
								if(exists_function((yyvsp[-3].strval))==1)
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
#line 2072 "y.tab.c"
    break;

  case 80:
#line 501 "limbaj.y"
                {
				if(exists_function((yyvsp[-2].strval))==1)
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
#line 2130 "y.tab.c"
    break;


#line 2134 "y.tab.c"

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
#line 555 "limbaj.y"

void yyerror(char * s)
{
  	printf("ERROR: %s line:%d\n",s,yylineno);
}

int main(int argc, char** argv)
{
	yyin=fopen(argv[1],"r");
	yyparse();
}
