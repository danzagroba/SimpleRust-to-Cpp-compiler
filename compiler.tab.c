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

int yylex(void);
int yywrap(void);
void yyerror(const char* s);
    
SymbolTable st;
MainFunctionNode* ast_root = nullptr;


#line 88 "compiler.tab.c"

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
  YYSYMBOL_NOT = 18,                       /* NOT  */
  YYSYMBOL_AND = 19,                       /* AND  */
  YYSYMBOL_OR = 20,                        /* OR  */
  YYSYMBOL_TRUE = 21,                      /* TRUE  */
  YYSYMBOL_FALSE = 22,                     /* FALSE  */
  YYSYMBOL_ATRIB = 23,                     /* ATRIB  */
  YYSYMBOL_EQ = 24,                        /* EQ  */
  YYSYMBOL_NE = 25,                        /* NE  */
  YYSYMBOL_LT = 26,                        /* LT  */
  YYSYMBOL_LE = 27,                        /* LE  */
  YYSYMBOL_GT = 28,                        /* GT  */
  YYSYMBOL_GE = 29,                        /* GE  */
  YYSYMBOL_IF = 30,                        /* IF  */
  YYSYMBOL_ELSE = 31,                      /* ELSE  */
  YYSYMBOL_FOR = 32,                       /* FOR  */
  YYSYMBOL_IN = 33,                        /* IN  */
  YYSYMBOL_TO = 34,                        /* TO  */
  YYSYMBOL_WHILE = 35,                     /* WHILE  */
  YYSYMBOL_READ = 36,                      /* READ  */
  YYSYMBOL_WRITE = 37,                     /* WRITE  */
  YYSYMBOL_WRITELN = 38,                   /* WRITELN  */
  YYSYMBOL_EOL = 39,                       /* EOL  */
  YYSYMBOL_40_ = 40,                       /* '+'  */
  YYSYMBOL_41_ = 41,                       /* '-'  */
  YYSYMBOL_42_ = 42,                       /* '*'  */
  YYSYMBOL_43_ = 43,                       /* '/'  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_program = 45,                   /* program  */
  YYSYMBOL_commands = 46,                  /* commands  */
  YYSYMBOL_command = 47,                   /* command  */
  YYSYMBOL_TYPE = 48,                      /* TYPE  */
  YYSYMBOL_declaration = 49,               /* declaration  */
  YYSYMBOL_assign = 50,                    /* assign  */
  YYSYMBOL_if_else_command = 51,           /* if_else_command  */
  YYSYMBOL_for_command = 52,               /* for_command  */
  YYSYMBOL_expression = 53,                /* expression  */
  YYSYMBOL_arithmetic_expression = 54,     /* arithmetic_expression  */
  YYSYMBOL_logical_expression = 55,        /* logical_expression  */
  YYSYMBOL_term = 56,                      /* term  */
  YYSYMBOL_factor = 57                     /* factor  */
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
typedef yytype_int8 yy_state_t;

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
#define YYLAST   150

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  41
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  95

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
       2,     2,    42,    40,     2,    41,     2,    43,     2,     2,
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   134,   134,   144,   150,   157,   158,   159,   160,   164,
     165,   166,   171,   183,   197,   213,   228,   240,   259,   260,
     263,   268,   273,   280,   285,   290,   295,   300,   305,   310,
     315,   320,   325,   332,   333,   338,   345,   350,   355,   371,
     376,   381
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
  "COLON", "LEFT", "RIGHT", "LBRACE", "RBRACE", "NOT", "AND", "OR", "TRUE",
  "FALSE", "ATRIB", "EQ", "NE", "LT", "LE", "GT", "GE", "IF", "ELSE",
  "FOR", "IN", "TO", "WHILE", "READ", "WRITE", "WRITELN", "EOL", "'+'",
  "'-'", "'*'", "'/'", "$accept", "program", "commands", "command", "TYPE",
  "declaration", "assign", "if_else_command", "for_command", "expression",
  "arithmetic_expression", "logical_expression", "term", "factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-49)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -1,     2,    16,    -6,   -49,     5,     6,    12,    20,    34,
      46,    50,     4,   -49,   -49,   -49,   -49,   -49,    83,    62,
      83,    66,   -49,   -49,   -49,   -49,   -49,    83,    83,   -49,
     -49,    30,    11,   -49,    68,   -49,    61,   104,    60,    45,
      93,    72,   -49,    83,    83,    83,    83,    83,    83,    83,
      83,   -49,    85,    85,    85,    85,   119,    73,    85,   -49,
     -49,   121,   115,   109,   109,   -49,   -49,   -49,   -49,    83,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,    22,    12,    75,
      83,   -49,     7,    85,    57,    67,    32,   -49,    84,    12,
      12,     8,    36,   -49,   -49
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     3,     5,     6,     7,     8,     0,     0,
       0,     0,     2,     4,    38,    36,    37,     0,     0,    40,
      41,     0,    18,    19,    22,    33,     0,     0,    19,     0,
       0,    19,    25,     0,     0,     0,     0,     0,     0,     0,
       0,    14,     0,     0,     0,     0,     0,     0,     0,    39,
      32,    23,    24,    26,    27,    28,    29,    30,    31,     0,
      20,    21,    34,    35,     9,    10,    11,     0,     0,     0,
       0,    12,     0,     0,     0,    16,     0,    13,     0,     0,
       0,     0,     0,    17,    15
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -49,   -49,    13,   -12,   -49,   -49,   -49,   -49,   -49,   -17,
     -48,   -13,   -49,    10
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    12,    13,    77,    14,    15,    16,    17,    40,
      32,    33,    34,    35
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      23,    31,     1,    37,    70,    71,     3,    38,     5,     8,
      79,    42,     8,     8,    41,     9,     4,     8,     9,     9,
       6,    22,     7,     9,    85,    93,    61,    62,    63,    64,
      65,    66,    67,    68,    10,    86,    11,    10,    10,    11,
      11,     8,    10,    18,    11,    80,    19,     9,    89,    43,
      44,    52,    53,    94,    45,    46,    47,    48,    49,    50,
      20,    81,    21,    84,    72,    73,    10,    36,    11,    51,
      23,    39,    52,    53,    56,    57,    43,    44,    58,    23,
      23,    45,    46,    47,    48,    49,    50,    60,    24,    78,
      24,    82,    25,    26,    25,    26,    87,    27,    88,    69,
      90,    28,    91,    92,    29,    30,    29,    30,    59,    83,
      54,    55,    43,    44,     0,    52,    53,    45,    46,    47,
      48,    49,    50,    43,    44,    74,    75,    76,    45,    46,
      47,    48,    49,    50,    43,    47,    48,    49,    50,    45,
      46,    47,    48,    49,    50,    45,    46,    47,    48,    49,
      50
};

static const yytype_int8 yycheck[] =
{
      12,    18,     3,    20,    52,    53,     4,    20,    14,     5,
      58,    28,     5,     5,    27,    11,     0,     5,    11,    11,
      15,    17,    16,    11,    17,    17,    43,    44,    45,    46,
      47,    48,    49,    50,    30,    83,    32,    30,    30,    32,
      32,     5,    30,    23,    32,    23,    12,    11,    16,    19,
      20,    40,    41,    17,    24,    25,    26,    27,    28,    29,
      14,    39,    12,    80,    54,    55,    30,     5,    32,    39,
      82,     5,    40,    41,    13,    15,    19,    20,    33,    91,
      92,    24,    25,    26,    27,    28,    29,    15,     5,    16,
       5,    78,     9,    10,     9,    10,    39,    14,    31,    14,
      16,    18,    89,    90,    21,    22,    21,    22,    15,    34,
      42,    43,    19,    20,    -1,    40,    41,    24,    25,    26,
      27,    28,    29,    19,    20,     6,     7,     8,    24,    25,
      26,    27,    28,    29,    19,    26,    27,    28,    29,    24,
      25,    26,    27,    28,    29,    24,    25,    26,    27,    28,
      29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    45,     4,     0,    14,    15,    16,     5,    11,
      30,    32,    46,    47,    49,    50,    51,    52,    23,    12,
      14,    12,    17,    47,     5,     9,    10,    14,    18,    21,
      22,    53,    54,    55,    56,    57,     5,    53,    55,     5,
      53,    55,    53,    19,    20,    24,    25,    26,    27,    28,
      29,    39,    40,    41,    42,    43,    13,    15,    33,    15,
      15,    53,    53,    53,    53,    53,    53,    53,    53,    14,
      54,    54,    57,    57,     6,     7,     8,    48,    16,    54,
      23,    39,    46,    34,    53,    17,    54,    39,    31,    16,
      16,    46,    46,    17,    17
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    47,    48,
      48,    48,    49,    49,    50,    51,    51,    52,    53,    53,
      54,    54,    54,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    56,    56,    56,    57,    57,    57,    57,
      57,    57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     6,     8,     4,    11,     7,    10,     1,     1,
       3,     3,     1,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     1,     1,     3,
       1,     1
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
#line 134 "compiler.y"
                                                         { 
        ast_root = new MainFunctionNode();
        cout<< "Program Started." << endl;
        std::vector<CommandNode*>* cmds_list = (yyvsp[-1].command_list_ptr);
        for (CommandNode* cmd : *cmds_list) {
            ast_root->addCommand(cmd);
        }
        delete cmds_list;
    }
#line 1207 "compiler.tab.c"
    break;

  case 3: /* commands: command  */
#line 145 "compiler.y"
    {
        (yyval.command_list_ptr) = new std::vector<CommandNode*>();
        (yyval.command_list_ptr)->push_back((yyvsp[0].command_node_ptr));
        cout << "[INFO] " << "\t Command added to command list." << endl;
    }
#line 1217 "compiler.tab.c"
    break;

  case 4: /* commands: commands command  */
#line 151 "compiler.y"
    {
        (yyval.command_list_ptr) = (yyvsp[-1].command_list_ptr);
        (yyval.command_list_ptr)->push_back((yyvsp[0].command_node_ptr));
        cout << "[INFO] " << "\t Command added to command list." << endl;
    }
#line 1227 "compiler.tab.c"
    break;

  case 5: /* command: declaration  */
#line 157 "compiler.y"
                     { (yyval.command_node_ptr) = (yyvsp[0].var_decl_node_ptr); }
#line 1233 "compiler.tab.c"
    break;

  case 6: /* command: assign  */
#line 158 "compiler.y"
             { (yyval.command_node_ptr) = (yyvsp[0].Variable_assign_node_ptr); }
#line 1239 "compiler.tab.c"
    break;

  case 7: /* command: if_else_command  */
#line 159 "compiler.y"
                      { (yyval.command_node_ptr) = (yyvsp[0].if_else_node_ptr); }
#line 1245 "compiler.tab.c"
    break;

  case 8: /* command: for_command  */
#line 160 "compiler.y"
                  { (yyval.command_node_ptr) = (yyvsp[0].for_node_ptr);}
#line 1251 "compiler.tab.c"
    break;

  case 9: /* TYPE: TINT  */
#line 164 "compiler.y"
           { (yyval.type_node_ptr) = new IntegerTypeNode(); }
#line 1257 "compiler.tab.c"
    break;

  case 10: /* TYPE: TFLOAT  */
#line 165 "compiler.y"
             { (yyval.type_node_ptr) = new FloatTypeNode(); }
#line 1263 "compiler.tab.c"
    break;

  case 11: /* TYPE: TBOOL  */
#line 166 "compiler.y"
            { (yyval.type_node_ptr) = new BooleanTypeNode; }
#line 1269 "compiler.tab.c"
    break;

  case 12: /* declaration: LET MUT ID COLON TYPE EOL  */
#line 172 "compiler.y"
    {   
        IdentifierNode* id_node_ptr = new IdentifierNode(*(yyvsp[-3].str));

        TypeNode* type_node_ptr = (yyvsp[-1].type_node_ptr);

        (yyval.var_decl_node_ptr) = new VariableDeclarationNode(type_node_ptr, id_node_ptr, nullptr);
        st.variables.insert({id_node_ptr->getIdentifier(), type_node_ptr});

        cout << "[INFO] " << "\t Variable/Constant " << *(yyvsp[-3].str) << " added to AST." << endl;
        delete (yyvsp[-3].str);
    }
#line 1285 "compiler.tab.c"
    break;

  case 13: /* declaration: LET MUT ID COLON TYPE ATRIB expression EOL  */
#line 184 "compiler.y"
    {   
        IdentifierNode* id_node_ptr = new IdentifierNode(*(yyvsp[-5].str));

        TypeNode* type_node_ptr = (yyvsp[-3].type_node_ptr);
    
        (yyval.var_decl_node_ptr) = new VariableDeclarationNode(type_node_ptr, id_node_ptr, (yyvsp[-1].expr_node_ptr));
        st.variables.insert({id_node_ptr->getIdentifier(), type_node_ptr});

        cout << "[INFO] " << "\t Variable " << *(yyvsp[-5].str) << " added to AST." << endl;
        delete (yyvsp[-5].str);
    }
#line 1301 "compiler.tab.c"
    break;

  case 14: /* assign: ID ATRIB expression EOL  */
#line 198 "compiler.y"
{
    IdentifierNode* id_node_ptr = new IdentifierNode(*(yyvsp[-3].str));
    if(st.variables.find(id_node_ptr->getIdentifier()) != st.variables.end()) {
        (yyval.Variable_assign_node_ptr) = new VariableAssignmentNode(id_node_ptr, (yyvsp[-1].expr_node_ptr));
        cout << "[INFO] " << "\t Variable assignment for " << *(yyvsp[-3].str) << " added to AST." << endl;
    } 
    else {
        yyerror("Identifier not declared.");
        delete id_node_ptr;
        (yyval.Variable_assign_node_ptr) = nullptr;
    }
    delete (yyvsp[-3].str);
}
#line 1319 "compiler.tab.c"
    break;

  case 15: /* if_else_command: IF LEFT logical_expression RIGHT LBRACE commands RBRACE ELSE LBRACE commands RBRACE  */
#line 213 "compiler.y"
                                                                                                     {
        IfElseNode* if_else = new IfElseNode((yyvsp[-8].logical_expr_node_ptr), true);
        
        std::vector<CommandNode*>* cmds_list = (yyvsp[-5].command_list_ptr);
        for (CommandNode* cmd : *cmds_list) {
            if_else->addIfCommand(cmd);
        }
        delete cmds_list;
        cmds_list = (yyvsp[-1].command_list_ptr);
        for (CommandNode* cmd : *cmds_list) {
            if_else->addIfCommand(cmd);
        }
        delete cmds_list;
        (yyval.if_else_node_ptr) = if_else;
    }
#line 1339 "compiler.tab.c"
    break;

  case 16: /* if_else_command: IF LEFT logical_expression RIGHT LBRACE commands RBRACE  */
#line 228 "compiler.y"
                                                             {
        IfElseNode* if_else = new IfElseNode((yyvsp[-4].logical_expr_node_ptr), false);
        
        std::vector<CommandNode*>* cmds_list = (yyvsp[-1].command_list_ptr);
        for (CommandNode* cmd : *cmds_list) {
            if_else->addIfCommand(cmd);
        }
        delete cmds_list;
        (yyval.if_else_node_ptr) = if_else;
    }
#line 1354 "compiler.tab.c"
    break;

  case 17: /* for_command: FOR MUT ID IN arithmetic_expression TO arithmetic_expression LBRACE commands RBRACE  */
#line 241 "compiler.y"
    {
        IdentifierNode* iterator_id_node = new IdentifierNode(*((yyvsp[-7].str)));

        ForNode* for_node = new ForNode(iterator_id_node, (yyvsp[-5].arith_expr_node_ptr), (yyvsp[-3].arith_expr_node_ptr));

        std::vector<CommandNode*>* cmds_list = (yyvsp[-1].command_list_ptr);
        for (CommandNode* cmd : *cmds_list) {
            for_node->addCommand(cmd);
        }
        delete cmds_list;

        (yyval.for_node_ptr) = for_node;

        cout << "[INFO] For loop command AST node created." << endl;

        delete (yyvsp[-7].str);
    }
#line 1376 "compiler.tab.c"
    break;

  case 18: /* expression: arithmetic_expression  */
#line 259 "compiler.y"
                                  { (yyval.expr_node_ptr) = (yyvsp[0].arith_expr_node_ptr); }
#line 1382 "compiler.tab.c"
    break;

  case 19: /* expression: logical_expression  */
#line 260 "compiler.y"
                         { (yyval.expr_node_ptr) = (yyvsp[0].logical_expr_node_ptr); }
#line 1388 "compiler.tab.c"
    break;

  case 20: /* arithmetic_expression: arithmetic_expression '+' arithmetic_expression  */
#line 264 "compiler.y"
    { 
        (yyval.arith_expr_node_ptr) = new AdditionOperatorNode((yyvsp[-2].arith_expr_node_ptr), (yyvsp[0].arith_expr_node_ptr)); 
        cout << "[INFO] " << "\t Addition operation added to AST." << endl;
    }
#line 1397 "compiler.tab.c"
    break;

  case 21: /* arithmetic_expression: arithmetic_expression '-' arithmetic_expression  */
#line 269 "compiler.y"
    { 
        (yyval.arith_expr_node_ptr) = new SubtractionOperatorNode((yyvsp[-2].arith_expr_node_ptr), (yyvsp[0].arith_expr_node_ptr)); 
        cout << "[INFO] " << "\t Subtraction operation added to AST." << endl;
    }
#line 1406 "compiler.tab.c"
    break;

  case 22: /* arithmetic_expression: term  */
#line 274 "compiler.y"
    { 
        (yyval.arith_expr_node_ptr) = static_cast<ArithmeticExpressionNode*>((yyvsp[0].expr_node_ptr)); 
        cout << "[INFO] " << "\t Term added to arithmetic expression." << endl;
    }
#line 1415 "compiler.tab.c"
    break;

  case 23: /* logical_expression: expression AND expression  */
#line 281 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new LogicalAndOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr));
        cout << "[INFO] " << "\t Logical AND operation added to AST." << endl;
    }
#line 1424 "compiler.tab.c"
    break;

  case 24: /* logical_expression: expression OR expression  */
#line 286 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new LogicalOrOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr));
        cout << "[INFO] " << "\t Logical OR operation added to AST." << endl;
    }
#line 1433 "compiler.tab.c"
    break;

  case 25: /* logical_expression: NOT expression  */
#line 291 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new NotOperatorNode((yyvsp[0].expr_node_ptr)); 
        cout << "[INFO] " << "\t Logical NOT operation added to AST." << endl;
    }
#line 1442 "compiler.tab.c"
    break;

  case 26: /* logical_expression: expression EQ expression  */
#line 296 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new EqualityOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        cout << "[INFO] " << "\t Equality operation added to AST." << endl;
    }
#line 1451 "compiler.tab.c"
    break;

  case 27: /* logical_expression: expression NE expression  */
#line 301 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new InequalityOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        cout << "[INFO] " << "\t Inequality operation added to AST." << endl;
    }
#line 1460 "compiler.tab.c"
    break;

  case 28: /* logical_expression: expression LT expression  */
#line 306 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new LessThanOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        cout << "[INFO] " << "\t Less than operation added to AST." << endl;
    }
#line 1469 "compiler.tab.c"
    break;

  case 29: /* logical_expression: expression LE expression  */
#line 311 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new LessThanOrEqualOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        cout << "[INFO] " << "\t Less than or equal operation added to AST." << endl;
    }
#line 1478 "compiler.tab.c"
    break;

  case 30: /* logical_expression: expression GT expression  */
#line 316 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new GreaterThanOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        cout << "[INFO] " << "\t Greater than operation added to AST." << endl;
    }
#line 1487 "compiler.tab.c"
    break;

  case 31: /* logical_expression: expression GE expression  */
#line 321 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new GreaterThanOrEqualOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        cout << "[INFO] " << "\t Greater than or equal operation added to AST." << endl;
    }
#line 1496 "compiler.tab.c"
    break;

  case 32: /* logical_expression: LEFT logical_expression RIGHT  */
#line 326 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = (yyvsp[-1].logical_expr_node_ptr); 
        cout << "[INFO] " << "\t Parentheses added to logical expression." << endl;
    }
#line 1505 "compiler.tab.c"
    break;

  case 34: /* term: term '*' factor  */
#line 334 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new MultiplicationOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        cout << "[INFO] " << "\t Multiplication operation added to AST." << endl;
    }
#line 1514 "compiler.tab.c"
    break;

  case 35: /* term: term '/' factor  */
#line 339 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new DivisionOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        cout << "[INFO] " << "\t Division operation added to AST." << endl;
    }
#line 1523 "compiler.tab.c"
    break;

  case 36: /* factor: INTEGER  */
#line 346 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new IntegerLiteralNode((yyvsp[0].ival)); 
        cout << "[INFO] " << "\t Integer literal " << (yyvsp[0].ival) << " added to AST." << endl;
    }
#line 1532 "compiler.tab.c"
    break;

  case 37: /* factor: FLOATING  */
#line 351 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new FloatLiteralNode((yyvsp[0].fval)); 
        cout << "[INFO] " << "\t Float literal " << (yyvsp[0].fval) << " added to AST." << endl;
    }
#line 1541 "compiler.tab.c"
    break;

  case 38: /* factor: ID  */
#line 356 "compiler.y"
    { 
        IdentifierNode* id_node_ptr = new IdentifierNode(*(yyvsp[0].str));
        if(st.variables.find(id_node_ptr->getIdentifier()) != st.variables.end() 
        //Constants are not supported in this grammar anymore
        //|| st.constants.find(id_node_ptr->getIdentifier()) != st.constants.end()
        ) {
            (yyval.expr_node_ptr) = id_node_ptr; 
            cout << "[INFO] " << "\t Identifier " << *(yyvsp[0].str) << " added to AST." << endl;
        } else {
            yyerror("Identifier not declared.");
            delete id_node_ptr;
            (yyval.expr_node_ptr) = nullptr;
        }
        delete (yyvsp[0].str);
    }
#line 1561 "compiler.tab.c"
    break;

  case 39: /* factor: LEFT expression RIGHT  */
#line 372 "compiler.y"
    { 
        (yyval.expr_node_ptr) = (yyvsp[-1].expr_node_ptr); 
        cout << "[INFO] " << "\t Parentheses added to arithmetic expression." << endl;
    }
#line 1570 "compiler.tab.c"
    break;

  case 40: /* factor: TRUE  */
#line 377 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new BooleanLiteralNode(true); 
        cout << "[INFO] " << "\t Boolean literal TRUE added to AST." << endl;
    }
#line 1579 "compiler.tab.c"
    break;

  case 41: /* factor: FALSE  */
#line 382 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new BooleanLiteralNode(false); 
        cout << "[INFO] " << "\t Boolean literal FALSE added to AST." << endl;
    }
#line 1588 "compiler.tab.c"
    break;


#line 1592 "compiler.tab.c"

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

#line 388 "compiler.y"




int main() { 

    int parse_result = yyparse();
    if (parse_result == 0) 
    {
        cout << "Parsing successful!" << endl;
        SemanticVisitor sm(st);
        ast_root->accept(sm);
        if(ast_root)
        {
            delete ast_root;
            ast_root = nullptr;
        } 
    } 
    else 
    {
        cout << "Parsing failed." << endl;
    }
    return parse_result;
}
