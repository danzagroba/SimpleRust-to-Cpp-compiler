/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "compiler.y"

#define ERROR_START "[ERROR] " <<  __LINE__  << ": "
#include <iostream>
using namespace std;
#include "AST.h"
#include "SymbolTable.h"
#include "SemanticVisitor.h"
#include "CodeVisitor.h"

int yylex(void);
int yywrap(void);
void yyerror(const char* s);
    
SymbolTable st;
MainFunctionNode* ast_root = nullptr;


#line 89 "compiler.tab.c"

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

#include "compiler.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_FUNCTION = 3,                   /* FUNCTION  */
  YYSYMBOL_MAIN = 4,                       /* MAIN  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_TINT = 6,                       /* TINT  */
  YYSYMBOL_TFLOAT = 7,                     /* TFLOAT  */
  YYSYMBOL_TBOOL = 8,                      /* TBOOL  */
  YYSYMBOL_INTEGER = 9,                    /* INTEGER  */
  YYSYMBOL_FLOATING = 10,                  /* FLOATING  */
  YYSYMBOL_LET = 11,                       /* LET  */
  YYSYMBOL_MUT = 12,                       /* MUT  */
  YYSYMBOL_COLON = 13,                     /* COLON  */
  YYSYMBOL_LEFT = 14,                      /* LEFT  */
  YYSYMBOL_RIGHT = 15,                     /* RIGHT  */
  YYSYMBOL_LBRACE = 16,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 17,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 18,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 19,                  /* RBRACKET  */
  YYSYMBOL_NOT = 20,                       /* NOT  */
  YYSYMBOL_AND = 21,                       /* AND  */
  YYSYMBOL_OR = 22,                        /* OR  */
  YYSYMBOL_TRUE = 23,                      /* TRUE  */
  YYSYMBOL_FALSE = 24,                     /* FALSE  */
  YYSYMBOL_ATRIB = 25,                     /* ATRIB  */
  YYSYMBOL_EQ = 26,                        /* EQ  */
  YYSYMBOL_NE = 27,                        /* NE  */
  YYSYMBOL_LT = 28,                        /* LT  */
  YYSYMBOL_LE = 29,                        /* LE  */
  YYSYMBOL_GT = 30,                        /* GT  */
  YYSYMBOL_GE = 31,                        /* GE  */
  YYSYMBOL_IF = 32,                        /* IF  */
  YYSYMBOL_ELSE = 33,                      /* ELSE  */
  YYSYMBOL_FOR = 34,                       /* FOR  */
  YYSYMBOL_IN = 35,                        /* IN  */
  YYSYMBOL_TO = 36,                        /* TO  */
  YYSYMBOL_WHILE = 37,                     /* WHILE  */
  YYSYMBOL_READ = 38,                      /* READ  */
  YYSYMBOL_WRITE = 39,                     /* WRITE  */
  YYSYMBOL_WRITELN = 40,                   /* WRITELN  */
  YYSYMBOL_EOL = 41,                       /* EOL  */
  YYSYMBOL_42_ = 42,                       /* '+'  */
  YYSYMBOL_43_ = 43,                       /* '-'  */
  YYSYMBOL_44_ = 44,                       /* '*'  */
  YYSYMBOL_45_ = 45,                       /* '/'  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_program = 47,                   /* program  */
  YYSYMBOL_commands = 48,                  /* commands  */
  YYSYMBOL_command = 49,                   /* command  */
  YYSYMBOL_TYPE = 50,                      /* TYPE  */
  YYSYMBOL_declaration = 51,               /* declaration  */
  YYSYMBOL_array_declaration = 52,         /* array_declaration  */
  YYSYMBOL_assign = 53,                    /* assign  */
  YYSYMBOL_array_assign = 54,              /* array_assign  */
  YYSYMBOL_if_else_command = 55,           /* if_else_command  */
  YYSYMBOL_for_command = 56,               /* for_command  */
  YYSYMBOL_while_command = 57,             /* while_command  */
  YYSYMBOL_read_command = 58,              /* read_command  */
  YYSYMBOL_write_command = 59,             /* write_command  */
  YYSYMBOL_expression = 60,                /* expression  */
  YYSYMBOL_arithmetic_expression = 61,     /* arithmetic_expression  */
  YYSYMBOL_logical_expression = 62,        /* logical_expression  */
  YYSYMBOL_term = 63,                      /* term  */
  YYSYMBOL_factor = 64                     /* factor  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   326

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  133

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    44,    42,     2,    43,     2,    45,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   140,   140,   150,   156,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   174,   175,   176,   181,   193,   207,
     219,   234,   249,   265,   278,   296,   309,   318,   323,   329,
     330,   333,   338,   343,   350,   355,   360,   365,   370,   375,
     380,   385,   390,   395,   402,   403,   408,   415,   420,   425,
     432,   439,   444,   449
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "FUNCTION", "MAIN",
  "ID", "TINT", "TFLOAT", "TBOOL", "INTEGER", "FLOATING", "LET", "MUT",
  "COLON", "LEFT", "RIGHT", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET",
  "NOT", "AND", "OR", "TRUE", "FALSE", "ATRIB", "EQ", "NE", "LT", "LE",
  "GT", "GE", "IF", "ELSE", "FOR", "IN", "TO", "WHILE", "READ", "WRITE",
  "WRITELN", "EOL", "'+'", "'-'", "'*'", "'/'", "$accept", "program",
  "commands", "command", "TYPE", "declaration", "array_declaration",
  "assign", "array_assign", "if_else_command", "for_command",
  "while_command", "read_command", "write_command", "expression",
  "arithmetic_expression", "logical_expression", "term", "factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-63)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,    17,    24,    28,   -63,    29,    31,   101,   -12,    41,
      47,    42,    47,    44,    45,    59,    11,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,    47,    47,    50,
      73,   -63,   -63,    47,    47,   -63,   -63,   278,   -28,    63,
     -27,   -63,    70,    76,    72,    47,    47,   -63,   -63,   241,
     -63,   130,    89,    47,   194,    90,   -63,    47,    47,    47,
      47,    47,    47,    47,    47,   190,   190,   101,   190,   190,
      69,   101,    93,   211,   228,    82,   -63,   147,   254,   -63,
     -63,   295,   289,    57,    57,   -63,   -63,   -63,   -63,    47,
     -63,   -63,    61,   -63,   -63,   190,    79,    81,    84,    87,
      47,   -63,   -63,   -63,    75,   -15,   -63,   103,    26,   -63,
     -63,   -63,   -63,   146,    96,    47,   -63,   104,   190,   -63,
      47,   162,   101,   -13,   267,   -63,    92,   101,   102,   -63,
     110,   -63,   -63
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     3,     5,     6,
       7,     8,     9,    10,    11,    12,    13,     0,     0,     0,
      49,    47,    48,     0,     0,    52,    53,     0,    29,    30,
      33,    44,     0,    30,     0,     0,     0,     2,     4,     0,
      30,     0,     0,     0,     0,    30,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,     0,     0,    51,
      43,    34,    35,    37,    38,    39,    40,    41,    42,     0,
      31,    32,     0,    45,    46,     0,     0,     0,     0,     0,
       0,    14,    15,    16,     0,     0,    50,    23,     0,    25,
      26,    27,    28,     0,     0,     0,    17,     0,     0,    21,
       0,     0,     0,     0,     0,    18,     0,     0,     0,    22,
       0,    19,    24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -63,   -63,   -62,   -16,    19,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -26,   -54,    13,   -63,   -29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    16,    17,   105,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    37,    38,    50,    40,    41
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      48,    49,    51,   127,     1,    92,    27,    54,    56,    96,
     115,    90,    91,    28,    65,    66,     8,    68,    69,    73,
      74,     3,     9,    39,     4,    43,   116,    78,    47,    65,
      66,    81,    82,    83,    84,    85,    86,    87,    88,    93,
      94,   108,     5,    10,     6,    11,    55,     7,    12,    13,
      14,    15,    30,    29,    42,    52,    31,    32,    44,    45,
     126,    33,   118,    54,   123,   130,     8,    34,    65,    66,
      35,    36,     9,    46,   113,    70,    48,    72,   107,    67,
      48,   101,   102,   103,     8,    61,    62,    63,    64,   121,
       9,    53,    71,    10,   124,    11,   109,     8,    12,    13,
      14,    15,    77,     9,    95,    80,     8,   100,    97,   129,
      48,    10,     9,    11,    48,     8,    12,    13,    14,    15,
     122,     9,   110,   114,    10,   111,    11,   132,   112,    12,
      13,    14,    15,    10,     0,    11,   117,   120,    12,    13,
      14,    15,    10,   131,    11,     0,     0,    12,    13,    14,
      15,    57,    58,   101,   102,   103,    59,    60,    61,    62,
      63,    64,     0,     0,     0,   104,     0,    57,    58,     0,
       0,    76,    59,    60,    61,    62,    63,    64,     0,     0,
       0,     0,     0,    57,    58,     0,     0,   119,    59,    60,
      61,    62,    63,    64,     0,    30,     0,     0,     0,    31,
      32,     0,     0,   125,    89,     0,     0,     0,     0,    79,
       0,     0,     0,    35,    36,    57,    58,     0,     0,     0,
      59,    60,    61,    62,    63,    64,    98,     0,     0,     0,
       0,     0,    57,    58,     0,     0,     0,    59,    60,    61,
      62,    63,    64,    99,     0,     0,     0,     0,     0,    57,
      58,     0,     0,     0,    59,    60,    61,    62,    63,    64,
      75,     0,    57,    58,     0,     0,     0,    59,    60,    61,
      62,    63,    64,   106,     0,    57,    58,     0,     0,     0,
      59,    60,    61,    62,    63,    64,   128,     0,    57,    58,
       0,     0,     0,    59,    60,    61,    62,    63,    64,    57,
      58,     0,     0,     0,    59,    60,    61,    62,    63,    64,
      57,     0,     0,     0,     0,    59,    60,    61,    62,    63,
      64,    59,    60,    61,    62,    63,    64
};

static const yytype_int16 yycheck[] =
{
      16,    27,    28,    16,     3,    67,    18,    33,    34,    71,
      25,    65,    66,    25,    42,    43,     5,    44,    45,    45,
      46,     4,    11,    10,     0,    12,    41,    53,    17,    42,
      43,    57,    58,    59,    60,    61,    62,    63,    64,    68,
      69,    95,    14,    32,    15,    34,    33,    16,    37,    38,
      39,    40,     5,    12,    12,     5,     9,    10,    14,    14,
     122,    14,    36,    89,   118,   127,     5,    20,    42,    43,
      23,    24,    11,    14,   100,     5,    92,     5,    17,    16,
      96,     6,     7,     8,     5,    28,    29,    30,    31,   115,
      11,    18,    16,    32,   120,    34,    17,     5,    37,    38,
      39,    40,    13,    11,    35,    15,     5,    25,    15,    17,
     126,    32,    11,    34,   130,     5,    37,    38,    39,    40,
      16,    11,    41,   104,    32,    41,    34,    17,    41,    37,
      38,    39,    40,    32,    -1,    34,    33,    41,    37,    38,
      39,    40,    32,    41,    34,    -1,    -1,    37,    38,    39,
      40,    21,    22,     6,     7,     8,    26,    27,    28,    29,
      30,    31,    -1,    -1,    -1,    18,    -1,    21,    22,    -1,
      -1,    41,    26,    27,    28,    29,    30,    31,    -1,    -1,
      -1,    -1,    -1,    21,    22,    -1,    -1,    41,    26,    27,
      28,    29,    30,    31,    -1,     5,    -1,    -1,    -1,     9,
      10,    -1,    -1,    41,    14,    -1,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    23,    24,    21,    22,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    31,    15,    -1,    -1,    -1,
      -1,    -1,    21,    22,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    15,    -1,    -1,    -1,    -1,    -1,    21,
      22,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      19,    -1,    21,    22,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    19,    -1,    21,    22,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    31,    19,    -1,    21,    22,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    21,
      22,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      21,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    26,    27,    28,    29,    30,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    47,     4,     0,    14,    15,    16,     5,    11,
      32,    34,    37,    38,    39,    40,    48,    49,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    18,    25,    12,
       5,     9,    10,    14,    20,    23,    24,    60,    61,    62,
      63,    64,    12,    62,    14,    14,    14,    17,    49,    60,
      62,    60,     5,    18,    60,    62,    60,    21,    22,    26,
      27,    28,    29,    30,    31,    42,    43,    16,    44,    45,
       5,    16,     5,    60,    60,    19,    41,    13,    60,    15,
      15,    60,    60,    60,    60,    60,    60,    60,    60,    14,
      61,    61,    48,    64,    64,    35,    48,    15,    15,    15,
      25,     6,     7,     8,    18,    50,    19,    17,    61,    17,
      41,    41,    41,    60,    50,    25,    41,    33,    36,    41,
      41,    60,    16,    61,    60,    41,    48,    16,    19,    17,
      48,    41,    17
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    50,    50,    50,    51,    51,    52,
      53,    54,    55,    55,    56,    57,    58,    59,    59,    60,
      60,    61,    61,    61,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    63,    63,    63,    64,    64,    64,
      64,    64,    64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     6,     8,    10,
       4,     7,     9,     5,    10,     5,     5,     5,     5,     1,
       1,     3,     3,     1,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     1,     1,
       4,     3,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* program: FUNCTION MAIN LEFT RIGHT LBRACE commands RBRACE  */
#line 140 "compiler.y"
                                                         { 
        ast_root = new MainFunctionNode();
        cout<< "Program Started." << endl;
        std::vector<CommandNode*>* cmds_list = (yyvsp[-1].command_list_ptr);
        for (CommandNode* cmd : *cmds_list) {
            ast_root->addCommand(cmd);
        }
        delete cmds_list;
    }
#line 1266 "compiler.tab.c"
    break;

  case 3: /* commands: command  */
#line 151 "compiler.y"
    {
        (yyval.command_list_ptr) = new std::vector<CommandNode*>();
        (yyval.command_list_ptr)->push_back((yyvsp[0].command_node_ptr));
        //cout << "[INFO] " << "\t Command added to command list." << endl;
    }
#line 1276 "compiler.tab.c"
    break;

  case 4: /* commands: commands command  */
#line 157 "compiler.y"
    {
        (yyval.command_list_ptr) = (yyvsp[-1].command_list_ptr);
        (yyval.command_list_ptr)->push_back((yyvsp[0].command_node_ptr));
        //cout << "[INFO] " << "\t Command added to command list." << endl;
    }
#line 1286 "compiler.tab.c"
    break;

  case 5: /* command: declaration  */
#line 163 "compiler.y"
                     { (yyval.command_node_ptr) = (yyvsp[0].var_decl_node_ptr); }
#line 1292 "compiler.tab.c"
    break;

  case 6: /* command: array_declaration  */
#line 164 "compiler.y"
                        { (yyval.command_node_ptr) = (yyvsp[0].array_decl_node_ptr); }
#line 1298 "compiler.tab.c"
    break;

  case 7: /* command: assign  */
#line 165 "compiler.y"
             { (yyval.command_node_ptr) = (yyvsp[0].Variable_assign_node_ptr); }
#line 1304 "compiler.tab.c"
    break;

  case 8: /* command: array_assign  */
#line 166 "compiler.y"
                   { (yyval.command_node_ptr) = (yyvsp[0].array_assign_node_ptr); }
#line 1310 "compiler.tab.c"
    break;

  case 9: /* command: if_else_command  */
#line 167 "compiler.y"
                      { (yyval.command_node_ptr) = (yyvsp[0].if_else_node_ptr); }
#line 1316 "compiler.tab.c"
    break;

  case 10: /* command: for_command  */
#line 168 "compiler.y"
                  { (yyval.command_node_ptr) = (yyvsp[0].for_node_ptr); }
#line 1322 "compiler.tab.c"
    break;

  case 11: /* command: while_command  */
#line 169 "compiler.y"
                    { (yyval.command_node_ptr) = (yyvsp[0].while_node_ptr); }
#line 1328 "compiler.tab.c"
    break;

  case 12: /* command: read_command  */
#line 170 "compiler.y"
                   { (yyval.command_node_ptr) = (yyvsp[0].input_node_ptr); }
#line 1334 "compiler.tab.c"
    break;

  case 13: /* command: write_command  */
#line 171 "compiler.y"
                    { (yyval.command_node_ptr) = (yyvsp[0].output_node_ptr); }
#line 1340 "compiler.tab.c"
    break;

  case 14: /* TYPE: TINT  */
#line 174 "compiler.y"
           { (yyval.type_node_ptr) = new IntegerTypeNode(); }
#line 1346 "compiler.tab.c"
    break;

  case 15: /* TYPE: TFLOAT  */
#line 175 "compiler.y"
             { (yyval.type_node_ptr) = new FloatTypeNode(); }
#line 1352 "compiler.tab.c"
    break;

  case 16: /* TYPE: TBOOL  */
#line 176 "compiler.y"
            { (yyval.type_node_ptr) = new BooleanTypeNode; }
#line 1358 "compiler.tab.c"
    break;

  case 17: /* declaration: LET MUT ID COLON TYPE EOL  */
#line 182 "compiler.y"
    {   
        IdentifierNode* id_node_ptr = new IdentifierNode(*(yyvsp[-3].str));

        TypeNode* type_node_ptr = (yyvsp[-1].type_node_ptr);

        (yyval.var_decl_node_ptr) = new VariableDeclarationNode(type_node_ptr, id_node_ptr, nullptr);
        st.variables.insert({id_node_ptr->getIdentifier(), type_node_ptr});

        //cout << "[INFO] " << "\t Variable/Constant " << *$3 << " added to AST." << endl;
        delete (yyvsp[-3].str);
    }
#line 1374 "compiler.tab.c"
    break;

  case 18: /* declaration: LET MUT ID COLON TYPE ATRIB expression EOL  */
#line 194 "compiler.y"
    {   
        IdentifierNode* id_node_ptr = new IdentifierNode(*(yyvsp[-5].str));

        TypeNode* type_node_ptr = (yyvsp[-3].type_node_ptr);
    
        (yyval.var_decl_node_ptr) = new VariableDeclarationNode(type_node_ptr, id_node_ptr, (yyvsp[-1].expr_node_ptr));
        st.variables.insert({id_node_ptr->getIdentifier(), type_node_ptr});

        //cout << "[INFO] " << "\t Variable " << *$3 << " added to AST." << endl;
        delete (yyvsp[-5].str);
    }
#line 1390 "compiler.tab.c"
    break;

  case 19: /* array_declaration: LET MUT ID COLON LBRACKET TYPE EOL expression RBRACKET EOL  */
#line 208 "compiler.y"
{
    IdentifierNode* id_node_ptr = new IdentifierNode(*(yyvsp[-7].str));
    TypeNode* type_node_ptr = (yyvsp[-4].type_node_ptr);

    (yyval.array_decl_node_ptr) = new ArrayDeclarationNode(type_node_ptr, id_node_ptr, (yyvsp[-2].expr_node_ptr));
    st.vectors.insert({id_node_ptr->getIdentifier(), type_node_ptr});

    //cout << "[INFO] " << "\t Array " << *$3 << " added to AST." << endl;
    delete (yyvsp[-7].str);
}
#line 1405 "compiler.tab.c"
    break;

  case 20: /* assign: ID ATRIB expression EOL  */
#line 220 "compiler.y"
{
    IdentifierNode* id_node_ptr = new IdentifierNode(*(yyvsp[-3].str));
    if(st.variables.find(id_node_ptr->getIdentifier()) != st.variables.end()) {
        (yyval.Variable_assign_node_ptr) = new VariableAssignmentNode(id_node_ptr, (yyvsp[-1].expr_node_ptr));
        //cout << "[INFO] " << "\t Variable assignment for " << *$1 << " added to AST." << endl;
    } 
    else {
        yyerror("Identifier not declared.");
        delete id_node_ptr;
        (yyval.Variable_assign_node_ptr) = nullptr;
    }
    delete (yyvsp[-3].str);
}
#line 1423 "compiler.tab.c"
    break;

  case 21: /* array_assign: ID LBRACKET expression RBRACKET ATRIB expression EOL  */
#line 235 "compiler.y"
{
    IdentifierNode* id_node_ptr = new IdentifierNode(*(yyvsp[-6].str));
    if(st.vectors.find(id_node_ptr->getIdentifier()) != st.vectors.end()) {
        (yyval.array_assign_node_ptr) = new ArrayAssignmentNode(id_node_ptr, (yyvsp[-4].expr_node_ptr), (yyvsp[-1].expr_node_ptr));
        //cout << "[INFO] " << "\t Array assignment for " << *$1 << " added to AST." << endl;
    } 
    else {
        yyerror("Array identifier not declared.");
        delete id_node_ptr;
        (yyval.array_assign_node_ptr) = nullptr;
    }
    delete (yyvsp[-6].str);
}
#line 1441 "compiler.tab.c"
    break;

  case 22: /* if_else_command: IF logical_expression LBRACE commands RBRACE ELSE LBRACE commands RBRACE  */
#line 249 "compiler.y"
                                                                                          {
        IfElseNode* if_else = new IfElseNode((yyvsp[-7].logical_expr_node_ptr), true);
        
        std::vector<CommandNode*>* cmds_list = (yyvsp[-5].command_list_ptr);
        for (CommandNode* cmd : *cmds_list) {
            if_else->addIfCommand(cmd);
        }
        delete cmds_list;
        cmds_list = (yyvsp[-1].command_list_ptr);
        for (CommandNode* cmd : *cmds_list) {
            if_else->addElseCommand(cmd);
        }
        delete cmds_list;
        (yyval.if_else_node_ptr) = if_else;
        //cout << "[INFO] " << "\t If-Else command AST node created." << endl;
    }
#line 1462 "compiler.tab.c"
    break;

  case 23: /* if_else_command: IF logical_expression LBRACE commands RBRACE  */
#line 265 "compiler.y"
                                                  {
        IfElseNode* if_else = new IfElseNode((yyvsp[-3].logical_expr_node_ptr), false);
        
        std::vector<CommandNode*>* cmds_list = (yyvsp[-1].command_list_ptr);
        for (CommandNode* cmd : *cmds_list) {
            if_else->addIfCommand(cmd);
        }
        delete cmds_list;
        (yyval.if_else_node_ptr) = if_else;
        //cout << "[INFO] " << "\t If command AST node created." << endl;
    }
#line 1478 "compiler.tab.c"
    break;

  case 24: /* for_command: FOR MUT ID IN arithmetic_expression TO arithmetic_expression LBRACE commands RBRACE  */
#line 278 "compiler.y"
                                                                                                 {
        IdentifierNode* iterator_id_node = new IdentifierNode(*((yyvsp[-7].str)));

        ForNode* for_node = new ForNode(iterator_id_node, (yyvsp[-5].arith_expr_node_ptr), (yyvsp[-3].arith_expr_node_ptr));

        std::vector<CommandNode*>* cmds_list = (yyvsp[-1].command_list_ptr);
        for (CommandNode* cmd : *cmds_list) {
            for_node->addCommand(cmd);
        }
        delete cmds_list;

        (yyval.for_node_ptr) = for_node;

         //cout << "[INFO] " << "\t For loop command AST node created." << endl;

        delete (yyvsp[-7].str);
    }
#line 1500 "compiler.tab.c"
    break;

  case 25: /* while_command: WHILE logical_expression LBRACE commands RBRACE  */
#line 297 "compiler.y"
{
    WhileNode* while_node = new WhileNode((yyvsp[-3].logical_expr_node_ptr));
    std::vector<CommandNode*>* cmds_list = (yyvsp[-1].command_list_ptr);
    for (CommandNode* cmd : *cmds_list) {
        while_node->addCommand(cmd);
    }
    delete cmds_list;

    (yyval.while_node_ptr) = while_node;
    //cout << "[INFO] " << "\t While loop command AST node created." << endl;
}
#line 1516 "compiler.tab.c"
    break;

  case 26: /* read_command: READ LEFT ID RIGHT EOL  */
#line 310 "compiler.y"
    {
        IdentifierNode* id_node_ptr = new IdentifierNode(*((yyvsp[-2].str)));
        (yyval.input_node_ptr) = new InputNode(id_node_ptr);
        //cout << "[INFO] " << "\t Input command AST node created." << endl;
        delete (yyvsp[-2].str);
    }
#line 1527 "compiler.tab.c"
    break;

  case 27: /* write_command: WRITE LEFT expression RIGHT EOL  */
#line 319 "compiler.y"
    {
        (yyval.output_node_ptr) = new OutputNode((yyvsp[-2].expr_node_ptr),false);
        //cout << "[INFO] " << "\t Output command AST node created." << endl;
    }
#line 1536 "compiler.tab.c"
    break;

  case 28: /* write_command: WRITELN LEFT expression RIGHT EOL  */
#line 324 "compiler.y"
    {
        (yyval.output_node_ptr) = new OutputNode((yyvsp[-2].expr_node_ptr), true);
        //cout << "[INFO] " << "\t Output command AST node created." << endl;
    }
#line 1545 "compiler.tab.c"
    break;

  case 29: /* expression: arithmetic_expression  */
#line 329 "compiler.y"
                                  { (yyval.expr_node_ptr) = (yyvsp[0].arith_expr_node_ptr); }
#line 1551 "compiler.tab.c"
    break;

  case 30: /* expression: logical_expression  */
#line 330 "compiler.y"
                         { (yyval.expr_node_ptr) = (yyvsp[0].logical_expr_node_ptr); }
#line 1557 "compiler.tab.c"
    break;

  case 31: /* arithmetic_expression: arithmetic_expression '+' arithmetic_expression  */
#line 334 "compiler.y"
    { 
        (yyval.arith_expr_node_ptr) = new AdditionOperatorNode((yyvsp[-2].arith_expr_node_ptr), (yyvsp[0].arith_expr_node_ptr)); 
        //cout << "[INFO] " << "\t Addition operation added to AST." << endl;
    }
#line 1566 "compiler.tab.c"
    break;

  case 32: /* arithmetic_expression: arithmetic_expression '-' arithmetic_expression  */
#line 339 "compiler.y"
    { 
        (yyval.arith_expr_node_ptr) = new SubtractionOperatorNode((yyvsp[-2].arith_expr_node_ptr), (yyvsp[0].arith_expr_node_ptr)); 
        //cout << "[INFO] " << "\t Subtraction operation added to AST." << endl;
    }
#line 1575 "compiler.tab.c"
    break;

  case 33: /* arithmetic_expression: term  */
#line 344 "compiler.y"
    { 
        (yyval.arith_expr_node_ptr) = static_cast<ArithmeticExpressionNode*>((yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Term added to arithmetic expression." << endl;
    }
#line 1584 "compiler.tab.c"
    break;

  case 34: /* logical_expression: expression AND expression  */
#line 351 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new LogicalAndOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr));
        //cout << "[INFO] " << "\t Logical AND operation added to AST." << endl;
    }
#line 1593 "compiler.tab.c"
    break;

  case 35: /* logical_expression: expression OR expression  */
#line 356 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new LogicalOrOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr));
        //cout << "[INFO] " << "\t Logical OR operation added to AST." << endl;
    }
#line 1602 "compiler.tab.c"
    break;

  case 36: /* logical_expression: NOT expression  */
#line 361 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new NotOperatorNode((yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Logical NOT operation added to AST." << endl;
    }
#line 1611 "compiler.tab.c"
    break;

  case 37: /* logical_expression: expression EQ expression  */
#line 366 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new EqualityOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Equality operation added to AST." << endl;
    }
#line 1620 "compiler.tab.c"
    break;

  case 38: /* logical_expression: expression NE expression  */
#line 371 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new InequalityOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Inequality operation added to AST." << endl;
    }
#line 1629 "compiler.tab.c"
    break;

  case 39: /* logical_expression: expression LT expression  */
#line 376 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new LessThanOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Less than operation added to AST." << endl;
    }
#line 1638 "compiler.tab.c"
    break;

  case 40: /* logical_expression: expression LE expression  */
#line 381 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new LessThanOrEqualOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Less than or equal operation added to AST." << endl;
    }
#line 1647 "compiler.tab.c"
    break;

  case 41: /* logical_expression: expression GT expression  */
#line 386 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new GreaterThanOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Greater than operation added to AST." << endl;
    }
#line 1656 "compiler.tab.c"
    break;

  case 42: /* logical_expression: expression GE expression  */
#line 391 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new GreaterThanOrEqualOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Greater than or equal operation added to AST." << endl;
    }
#line 1665 "compiler.tab.c"
    break;

  case 43: /* logical_expression: LEFT logical_expression RIGHT  */
#line 396 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = (yyvsp[-1].logical_expr_node_ptr); 
        //cout << "[INFO] " << "\t Parentheses added to logical expression." << endl;
    }
#line 1674 "compiler.tab.c"
    break;

  case 45: /* term: term '*' factor  */
#line 404 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new MultiplicationOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Multiplication operation added to AST." << endl;
    }
#line 1683 "compiler.tab.c"
    break;

  case 46: /* term: term '/' factor  */
#line 409 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new DivisionOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Division operation added to AST." << endl;
    }
#line 1692 "compiler.tab.c"
    break;

  case 47: /* factor: INTEGER  */
#line 416 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new IntegerLiteralNode((yyvsp[0].ival)); 
        //cout << "[INFO] " << "\t Integer literal " << $1 << " added to AST." << endl;
    }
#line 1701 "compiler.tab.c"
    break;

  case 48: /* factor: FLOATING  */
#line 421 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new FloatLiteralNode((yyvsp[0].fval)); 
        //cout << "[INFO] " << "\t Float literal " << $1 << " added to AST." << endl;
    }
#line 1710 "compiler.tab.c"
    break;

  case 49: /* factor: ID  */
#line 426 "compiler.y"
    { 
        IdentifierNode* id_node_ptr = new IdentifierNode(*(yyvsp[0].str));
        (yyval.expr_node_ptr) = id_node_ptr; 
        //cout << "[INFO] " << "\t Identifier " << *$1 << " added to AST." << endl;
        delete (yyvsp[0].str);
    }
#line 1721 "compiler.tab.c"
    break;

  case 50: /* factor: ID LBRACKET expression RBRACKET  */
#line 433 "compiler.y"
    { 
        IdentifierNode* id_node_ptr = new IdentifierNode(*(yyvsp[-3].str));
        (yyval.expr_node_ptr) = new ArrayAcessNode(id_node_ptr, (yyvsp[-1].expr_node_ptr));
        //cout << "[INFO] " << "\t Array access for " << *$1 << " added to AST." << endl;
        delete (yyvsp[-3].str);
    }
#line 1732 "compiler.tab.c"
    break;

  case 51: /* factor: LEFT expression RIGHT  */
#line 440 "compiler.y"
    { 
        (yyval.expr_node_ptr) = (yyvsp[-1].expr_node_ptr); 
        //cout << "[INFO] " << "\t Parentheses added to arithmetic expression." << endl;
    }
#line 1741 "compiler.tab.c"
    break;

  case 52: /* factor: TRUE  */
#line 445 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new BooleanLiteralNode(true); 
        //cout << "[INFO] " << "\t Boolean literal TRUE added to AST." << endl;
    }
#line 1750 "compiler.tab.c"
    break;

  case 53: /* factor: FALSE  */
#line 450 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new BooleanLiteralNode(false); 
        //cout << "[INFO] " << "\t Boolean literal FALSE added to AST." << endl;
    }
#line 1759 "compiler.tab.c"
    break;


#line 1763 "compiler.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 456 "compiler.y"




int main() { 

    int parse_result = yyparse();
    int semantic_result = false;
    if (parse_result == 0) 
    {
        cout << "Parsing successful!" << endl;
        if(ast_root){
            SemanticVisitor semantic(st);
            ast_root->accept(semantic);
            if(semantic.hasError) {
                cout << "Semantic errors found." << endl;
            } else {
                cout << "Semantic analysis completed successfully." << endl;
            }
            semantic_result = semantic.hasError;
        }
    } 
    else 
    {
        cout << "Parsing failed." << endl;
    }

    if(parse_result == 0 && ast_root && semantic_result == 0)
    {
        CodeVisitor code(st);
        ast_root->accept(code);
    }
    delete ast_root;
    ast_root = nullptr;
    return parse_result;
}
