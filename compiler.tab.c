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
  YYSYMBOL_while_command = 53,             /* while_command  */
  YYSYMBOL_expression = 54,                /* expression  */
  YYSYMBOL_arithmetic_expression = 55,     /* arithmetic_expression  */
  YYSYMBOL_logical_expression = 56,        /* logical_expression  */
  YYSYMBOL_term = 57,                      /* term  */
  YYSYMBOL_factor = 58                     /* factor  */
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
#define YYLAST   188

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  43
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  99

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
       0,   135,   135,   145,   151,   158,   159,   160,   161,   162,
     166,   167,   168,   173,   185,   199,   215,   230,   242,   261,
     271,   272,   275,   280,   285,   292,   297,   302,   307,   312,
     317,   322,   327,   332,   337,   344,   345,   350,   357,   362,
     367,   383,   388,   393
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
  "declaration", "assign", "if_else_command", "for_command",
  "while_command", "expression", "arithmetic_expression",
  "logical_expression", "term", "factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-51)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,     1,    15,     3,   -51,    18,    22,    48,    17,    42,
     127,    45,   127,     7,   -51,   -51,   -51,   -51,   -51,   -51,
     127,    46,   -51,   -51,   -51,   127,   127,   -51,   -51,   142,
     -27,    47,   -22,   -51,    53,    59,   -51,   -51,    85,   -51,
      66,   131,    74,   -51,   127,   127,   127,   127,   127,   127,
     127,   127,    86,    86,    48,    86,    86,    60,    48,   -51,
      91,   -51,   -51,   159,   153,    89,    89,   -51,   -51,   -51,
     -51,   127,   -51,   -51,    38,   -51,   -51,    86,    39,   -51,
     -51,   -51,   -20,    61,   -18,   -51,   127,   -51,    70,    86,
     101,    48,    -5,   -51,    55,    48,   -51,    71,   -51
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     3,     5,     6,     7,     8,     9,
       0,     0,    40,    38,    39,     0,     0,    42,    43,     0,
      20,    21,    24,    35,     0,    21,     2,     4,     0,    21,
       0,     0,    21,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,    41,    34,    25,    26,    28,    29,    30,    31,    32,
      33,     0,    22,    23,     0,    36,    37,     0,     0,    10,
      11,    12,     0,    17,     0,    19,     0,    13,     0,     0,
       0,     0,     0,    14,     0,     0,    16,     0,    18
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,   -50,   -13,   -51,   -51,   -51,   -51,   -51,   -51,
     -19,   -43,    52,   -51,    -8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    13,    14,    82,    15,    16,    17,    18,    19,
      29,    30,    39,    32,    33
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      37,    38,     1,    86,    74,     3,    41,    43,    78,    72,
      73,    95,     8,    52,    53,     4,    89,     5,     9,    87,
      55,    56,    52,    53,    36,    63,    64,    65,    66,    67,
      68,    69,    70,     6,    84,    52,    53,    10,     7,    11,
      20,    94,    12,     8,     8,    97,    92,    75,    76,     9,
       9,    40,    41,     8,    21,    83,    85,    34,    57,     9,
       8,    37,    31,    54,    35,    37,     9,    90,    10,    10,
      11,    11,    96,    12,    12,    58,     8,    42,    10,    60,
      11,    37,     9,    12,    37,    10,    91,    11,    98,    62,
      12,    22,    88,    77,     0,    23,    24,    79,    80,    81,
      71,    10,     0,    11,    44,    45,    12,    27,    28,    46,
      47,    48,    49,    50,    51,    48,    49,    50,    51,     0,
      44,    45,     0,     0,    59,    46,    47,    48,    49,    50,
      51,     0,    22,     0,     0,     0,    23,    24,     0,     0,
      93,    25,     0,     0,     0,    26,    61,     0,    27,    28,
      44,    45,     0,     0,     0,    46,    47,    48,    49,    50,
      51,    44,    45,     0,     0,     0,    46,    47,    48,    49,
      50,    51,    44,     0,     0,     0,     0,    46,    47,    48,
      49,    50,    51,    46,    47,    48,    49,    50,    51
};

static const yytype_int8 yycheck[] =
{
      13,    20,     3,    23,    54,     4,    25,    26,    58,    52,
      53,    16,     5,    40,    41,     0,    34,    14,    11,    39,
      42,    43,    40,    41,    17,    44,    45,    46,    47,    48,
      49,    50,    51,    15,    77,    40,    41,    30,    16,    32,
      23,    91,    35,     5,     5,    95,    89,    55,    56,    11,
      11,     5,    71,     5,    12,    17,    17,    12,     5,    11,
       5,    74,    10,    16,    12,    78,    11,    86,    30,    30,
      32,    32,    17,    35,    35,    16,     5,    25,    30,    13,
      32,    94,    11,    35,    97,    30,    16,    32,    17,    15,
      35,     5,    31,    33,    -1,     9,    10,     6,     7,     8,
      14,    30,    -1,    32,    19,    20,    35,    21,    22,    24,
      25,    26,    27,    28,    29,    26,    27,    28,    29,    -1,
      19,    20,    -1,    -1,    39,    24,    25,    26,    27,    28,
      29,    -1,     5,    -1,    -1,    -1,     9,    10,    -1,    -1,
      39,    14,    -1,    -1,    -1,    18,    15,    -1,    21,    22,
      19,    20,    -1,    -1,    -1,    24,    25,    26,    27,    28,
      29,    19,    20,    -1,    -1,    -1,    24,    25,    26,    27,
      28,    29,    19,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    28,    29,    24,    25,    26,    27,    28,    29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    45,     4,     0,    14,    15,    16,     5,    11,
      30,    32,    35,    46,    47,    49,    50,    51,    52,    53,
      23,    12,     5,     9,    10,    14,    18,    21,    22,    54,
      55,    56,    57,    58,    12,    56,    17,    47,    54,    56,
       5,    54,    56,    54,    19,    20,    24,    25,    26,    27,
      28,    29,    40,    41,    16,    42,    43,     5,    16,    39,
      13,    15,    15,    54,    54,    54,    54,    54,    54,    54,
      54,    14,    55,    55,    46,    58,    58,    33,    46,     6,
       7,     8,    48,    17,    55,    17,    23,    39,    31,    34,
      54,    16,    55,    39,    46,    16,    17,    46,    17
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    47,    47,
      48,    48,    48,    49,    49,    50,    51,    51,    52,    53,
      54,    54,    55,    55,    55,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    57,    57,    57,    58,    58,
      58,    58,    58,    58
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     6,     8,     4,     9,     5,    10,     5,
       1,     1,     3,     3,     1,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     1,
       1,     3,     1,     1
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
#line 135 "compiler.y"
                                                         { 
        ast_root = new MainFunctionNode();
        cout<< "Program Started." << endl;
        std::vector<CommandNode*>* cmds_list = (yyvsp[-1].command_list_ptr);
        for (CommandNode* cmd : *cmds_list) {
            ast_root->addCommand(cmd);
        }
        delete cmds_list;
    }
#line 1215 "compiler.tab.c"
    break;

  case 3: /* commands: command  */
#line 146 "compiler.y"
    {
        (yyval.command_list_ptr) = new std::vector<CommandNode*>();
        (yyval.command_list_ptr)->push_back((yyvsp[0].command_node_ptr));
        cout << "[INFO] " << "\t Command added to command list." << endl;
    }
#line 1225 "compiler.tab.c"
    break;

  case 4: /* commands: commands command  */
#line 152 "compiler.y"
    {
        (yyval.command_list_ptr) = (yyvsp[-1].command_list_ptr);
        (yyval.command_list_ptr)->push_back((yyvsp[0].command_node_ptr));
        cout << "[INFO] " << "\t Command added to command list." << endl;
    }
#line 1235 "compiler.tab.c"
    break;

  case 5: /* command: declaration  */
#line 158 "compiler.y"
                     { (yyval.command_node_ptr) = (yyvsp[0].var_decl_node_ptr); }
#line 1241 "compiler.tab.c"
    break;

  case 6: /* command: assign  */
#line 159 "compiler.y"
             { (yyval.command_node_ptr) = (yyvsp[0].Variable_assign_node_ptr); }
#line 1247 "compiler.tab.c"
    break;

  case 7: /* command: if_else_command  */
#line 160 "compiler.y"
                      { (yyval.command_node_ptr) = (yyvsp[0].if_else_node_ptr); }
#line 1253 "compiler.tab.c"
    break;

  case 8: /* command: for_command  */
#line 161 "compiler.y"
                  { (yyval.command_node_ptr) = (yyvsp[0].for_node_ptr); }
#line 1259 "compiler.tab.c"
    break;

  case 9: /* command: while_command  */
#line 162 "compiler.y"
                    { (yyval.command_node_ptr) = (yyvsp[0].while_node_ptr); }
#line 1265 "compiler.tab.c"
    break;

  case 10: /* TYPE: TINT  */
#line 166 "compiler.y"
           { (yyval.type_node_ptr) = new IntegerTypeNode(); }
#line 1271 "compiler.tab.c"
    break;

  case 11: /* TYPE: TFLOAT  */
#line 167 "compiler.y"
             { (yyval.type_node_ptr) = new FloatTypeNode(); }
#line 1277 "compiler.tab.c"
    break;

  case 12: /* TYPE: TBOOL  */
#line 168 "compiler.y"
            { (yyval.type_node_ptr) = new BooleanTypeNode; }
#line 1283 "compiler.tab.c"
    break;

  case 13: /* declaration: LET MUT ID COLON TYPE EOL  */
#line 174 "compiler.y"
    {   
        IdentifierNode* id_node_ptr = new IdentifierNode(*(yyvsp[-3].str));

        TypeNode* type_node_ptr = (yyvsp[-1].type_node_ptr);

        (yyval.var_decl_node_ptr) = new VariableDeclarationNode(type_node_ptr, id_node_ptr, nullptr);
        st.variables.insert({id_node_ptr->getIdentifier(), type_node_ptr});

        cout << "[INFO] " << "\t Variable/Constant " << *(yyvsp[-3].str) << " added to AST." << endl;
        delete (yyvsp[-3].str);
    }
#line 1299 "compiler.tab.c"
    break;

  case 14: /* declaration: LET MUT ID COLON TYPE ATRIB expression EOL  */
#line 186 "compiler.y"
    {   
        IdentifierNode* id_node_ptr = new IdentifierNode(*(yyvsp[-5].str));

        TypeNode* type_node_ptr = (yyvsp[-3].type_node_ptr);
    
        (yyval.var_decl_node_ptr) = new VariableDeclarationNode(type_node_ptr, id_node_ptr, (yyvsp[-1].expr_node_ptr));
        st.variables.insert({id_node_ptr->getIdentifier(), type_node_ptr});

        cout << "[INFO] " << "\t Variable " << *(yyvsp[-5].str) << " added to AST." << endl;
        delete (yyvsp[-5].str);
    }
#line 1315 "compiler.tab.c"
    break;

  case 15: /* assign: ID ATRIB expression EOL  */
#line 200 "compiler.y"
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
#line 1333 "compiler.tab.c"
    break;

  case 16: /* if_else_command: IF logical_expression LBRACE commands RBRACE ELSE LBRACE commands RBRACE  */
#line 215 "compiler.y"
                                                                                          {
        IfElseNode* if_else = new IfElseNode((yyvsp[-7].logical_expr_node_ptr), true);
        
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
#line 1353 "compiler.tab.c"
    break;

  case 17: /* if_else_command: IF logical_expression LBRACE commands RBRACE  */
#line 230 "compiler.y"
                                                  {
        IfElseNode* if_else = new IfElseNode((yyvsp[-3].logical_expr_node_ptr), false);
        
        std::vector<CommandNode*>* cmds_list = (yyvsp[-1].command_list_ptr);
        for (CommandNode* cmd : *cmds_list) {
            if_else->addIfCommand(cmd);
        }
        delete cmds_list;
        (yyval.if_else_node_ptr) = if_else;
    }
#line 1368 "compiler.tab.c"
    break;

  case 18: /* for_command: FOR MUT ID IN arithmetic_expression TO arithmetic_expression LBRACE commands RBRACE  */
#line 243 "compiler.y"
    {
        IdentifierNode* iterator_id_node = new IdentifierNode(*((yyvsp[-7].str)));

        ForNode* for_node = new ForNode(iterator_id_node, (yyvsp[-5].arith_expr_node_ptr), (yyvsp[-3].arith_expr_node_ptr));

        std::vector<CommandNode*>* cmds_list = (yyvsp[-1].command_list_ptr);
        for (CommandNode* cmd : *cmds_list) {
            for_node->addCommand(cmd);
        }
        delete cmds_list;

        (yyval.for_node_ptr) = for_node;

         cout << "[INFO] " << "\t For loop command AST node created." << endl;

        delete (yyvsp[-7].str);
    }
#line 1390 "compiler.tab.c"
    break;

  case 19: /* while_command: WHILE logical_expression LBRACE commands RBRACE  */
#line 262 "compiler.y"
{
    WhileNode* while_node = new WhileNode((yyvsp[-3].logical_expr_node_ptr));
    std::vector<CommandNode*>* cmds_list = (yyvsp[-1].command_list_ptr);
    for (CommandNode* cmd : *cmds_list) {
        while_node->addCommand(cmd);
    }
    delete cmds_list;
    cout << "[INFO] " << "\t While loop command AST node created." << endl;
}
#line 1404 "compiler.tab.c"
    break;

  case 20: /* expression: arithmetic_expression  */
#line 271 "compiler.y"
                                  { (yyval.expr_node_ptr) = (yyvsp[0].arith_expr_node_ptr); }
#line 1410 "compiler.tab.c"
    break;

  case 21: /* expression: logical_expression  */
#line 272 "compiler.y"
                         { (yyval.expr_node_ptr) = (yyvsp[0].logical_expr_node_ptr); }
#line 1416 "compiler.tab.c"
    break;

  case 22: /* arithmetic_expression: arithmetic_expression '+' arithmetic_expression  */
#line 276 "compiler.y"
    { 
        (yyval.arith_expr_node_ptr) = new AdditionOperatorNode((yyvsp[-2].arith_expr_node_ptr), (yyvsp[0].arith_expr_node_ptr)); 
        cout << "[INFO] " << "\t Addition operation added to AST." << endl;
    }
#line 1425 "compiler.tab.c"
    break;

  case 23: /* arithmetic_expression: arithmetic_expression '-' arithmetic_expression  */
#line 281 "compiler.y"
    { 
        (yyval.arith_expr_node_ptr) = new SubtractionOperatorNode((yyvsp[-2].arith_expr_node_ptr), (yyvsp[0].arith_expr_node_ptr)); 
        cout << "[INFO] " << "\t Subtraction operation added to AST." << endl;
    }
#line 1434 "compiler.tab.c"
    break;

  case 24: /* arithmetic_expression: term  */
#line 286 "compiler.y"
    { 
        (yyval.arith_expr_node_ptr) = static_cast<ArithmeticExpressionNode*>((yyvsp[0].expr_node_ptr)); 
        cout << "[INFO] " << "\t Term added to arithmetic expression." << endl;
    }
#line 1443 "compiler.tab.c"
    break;

  case 25: /* logical_expression: expression AND expression  */
#line 293 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new LogicalAndOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr));
        cout << "[INFO] " << "\t Logical AND operation added to AST." << endl;
    }
#line 1452 "compiler.tab.c"
    break;

  case 26: /* logical_expression: expression OR expression  */
#line 298 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new LogicalOrOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr));
        cout << "[INFO] " << "\t Logical OR operation added to AST." << endl;
    }
#line 1461 "compiler.tab.c"
    break;

  case 27: /* logical_expression: NOT expression  */
#line 303 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new NotOperatorNode((yyvsp[0].expr_node_ptr)); 
        cout << "[INFO] " << "\t Logical NOT operation added to AST." << endl;
    }
#line 1470 "compiler.tab.c"
    break;

  case 28: /* logical_expression: expression EQ expression  */
#line 308 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new EqualityOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        cout << "[INFO] " << "\t Equality operation added to AST." << endl;
    }
#line 1479 "compiler.tab.c"
    break;

  case 29: /* logical_expression: expression NE expression  */
#line 313 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new InequalityOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        cout << "[INFO] " << "\t Inequality operation added to AST." << endl;
    }
#line 1488 "compiler.tab.c"
    break;

  case 30: /* logical_expression: expression LT expression  */
#line 318 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new LessThanOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        cout << "[INFO] " << "\t Less than operation added to AST." << endl;
    }
#line 1497 "compiler.tab.c"
    break;

  case 31: /* logical_expression: expression LE expression  */
#line 323 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new LessThanOrEqualOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        cout << "[INFO] " << "\t Less than or equal operation added to AST." << endl;
    }
#line 1506 "compiler.tab.c"
    break;

  case 32: /* logical_expression: expression GT expression  */
#line 328 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new GreaterThanOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        cout << "[INFO] " << "\t Greater than operation added to AST." << endl;
    }
#line 1515 "compiler.tab.c"
    break;

  case 33: /* logical_expression: expression GE expression  */
#line 333 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new GreaterThanOrEqualOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        cout << "[INFO] " << "\t Greater than or equal operation added to AST." << endl;
    }
#line 1524 "compiler.tab.c"
    break;

  case 34: /* logical_expression: LEFT logical_expression RIGHT  */
#line 338 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = (yyvsp[-1].logical_expr_node_ptr); 
        cout << "[INFO] " << "\t Parentheses added to logical expression." << endl;
    }
#line 1533 "compiler.tab.c"
    break;

  case 36: /* term: term '*' factor  */
#line 346 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new MultiplicationOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        cout << "[INFO] " << "\t Multiplication operation added to AST." << endl;
    }
#line 1542 "compiler.tab.c"
    break;

  case 37: /* term: term '/' factor  */
#line 351 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new DivisionOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        cout << "[INFO] " << "\t Division operation added to AST." << endl;
    }
#line 1551 "compiler.tab.c"
    break;

  case 38: /* factor: INTEGER  */
#line 358 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new IntegerLiteralNode((yyvsp[0].ival)); 
        cout << "[INFO] " << "\t Integer literal " << (yyvsp[0].ival) << " added to AST." << endl;
    }
#line 1560 "compiler.tab.c"
    break;

  case 39: /* factor: FLOATING  */
#line 363 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new FloatLiteralNode((yyvsp[0].fval)); 
        cout << "[INFO] " << "\t Float literal " << (yyvsp[0].fval) << " added to AST." << endl;
    }
#line 1569 "compiler.tab.c"
    break;

  case 40: /* factor: ID  */
#line 368 "compiler.y"
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
#line 1589 "compiler.tab.c"
    break;

  case 41: /* factor: LEFT expression RIGHT  */
#line 384 "compiler.y"
    { 
        (yyval.expr_node_ptr) = (yyvsp[-1].expr_node_ptr); 
        cout << "[INFO] " << "\t Parentheses added to arithmetic expression." << endl;
    }
#line 1598 "compiler.tab.c"
    break;

  case 42: /* factor: TRUE  */
#line 389 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new BooleanLiteralNode(true); 
        cout << "[INFO] " << "\t Boolean literal TRUE added to AST." << endl;
    }
#line 1607 "compiler.tab.c"
    break;

  case 43: /* factor: FALSE  */
#line 394 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new BooleanLiteralNode(false); 
        cout << "[INFO] " << "\t Boolean literal FALSE added to AST." << endl;
    }
#line 1616 "compiler.tab.c"
    break;


#line 1620 "compiler.tab.c"

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

#line 400 "compiler.y"




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
