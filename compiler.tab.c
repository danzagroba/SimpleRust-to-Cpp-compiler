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
ProgramNode* ast_root = nullptr;


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
  YYSYMBOL_RETURN = 5,                     /* RETURN  */
  YYSYMBOL_ID = 6,                         /* ID  */
  YYSYMBOL_TINT = 7,                       /* TINT  */
  YYSYMBOL_TFLOAT = 8,                     /* TFLOAT  */
  YYSYMBOL_TBOOL = 9,                      /* TBOOL  */
  YYSYMBOL_INTEGER = 10,                   /* INTEGER  */
  YYSYMBOL_FLOATING = 11,                  /* FLOATING  */
  YYSYMBOL_LET = 12,                       /* LET  */
  YYSYMBOL_MUT = 13,                       /* MUT  */
  YYSYMBOL_COLON = 14,                     /* COLON  */
  YYSYMBOL_COMMA = 15,                     /* COMMA  */
  YYSYMBOL_ARROW = 16,                     /* ARROW  */
  YYSYMBOL_LEFT = 17,                      /* LEFT  */
  YYSYMBOL_RIGHT = 18,                     /* RIGHT  */
  YYSYMBOL_LBRACE = 19,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 20,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 21,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 22,                  /* RBRACKET  */
  YYSYMBOL_NOT = 23,                       /* NOT  */
  YYSYMBOL_AND = 24,                       /* AND  */
  YYSYMBOL_OR = 25,                        /* OR  */
  YYSYMBOL_TRUE = 26,                      /* TRUE  */
  YYSYMBOL_FALSE = 27,                     /* FALSE  */
  YYSYMBOL_ATRIB = 28,                     /* ATRIB  */
  YYSYMBOL_EQ = 29,                        /* EQ  */
  YYSYMBOL_NE = 30,                        /* NE  */
  YYSYMBOL_LT = 31,                        /* LT  */
  YYSYMBOL_LE = 32,                        /* LE  */
  YYSYMBOL_GT = 33,                        /* GT  */
  YYSYMBOL_GE = 34,                        /* GE  */
  YYSYMBOL_IF = 35,                        /* IF  */
  YYSYMBOL_ELSE = 36,                      /* ELSE  */
  YYSYMBOL_FOR = 37,                       /* FOR  */
  YYSYMBOL_IN = 38,                        /* IN  */
  YYSYMBOL_TO = 39,                        /* TO  */
  YYSYMBOL_WHILE = 40,                     /* WHILE  */
  YYSYMBOL_READ = 41,                      /* READ  */
  YYSYMBOL_WRITE = 42,                     /* WRITE  */
  YYSYMBOL_WRITELN = 43,                   /* WRITELN  */
  YYSYMBOL_EOL = 44,                       /* EOL  */
  YYSYMBOL_45_ = 45,                       /* '+'  */
  YYSYMBOL_46_ = 46,                       /* '-'  */
  YYSYMBOL_47_ = 47,                       /* '*'  */
  YYSYMBOL_48_ = 48,                       /* '/'  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_program = 50,                   /* program  */
  YYSYMBOL_fns = 51,                       /* fns  */
  YYSYMBOL_fn = 52,                        /* fn  */
  YYSYMBOL_parameters = 53,                /* parameters  */
  YYSYMBOL_parameter = 54,                 /* parameter  */
  YYSYMBOL_commands = 55,                  /* commands  */
  YYSYMBOL_command = 56,                   /* command  */
  YYSYMBOL_TYPE = 57,                      /* TYPE  */
  YYSYMBOL_declaration = 58,               /* declaration  */
  YYSYMBOL_array_declaration = 59,         /* array_declaration  */
  YYSYMBOL_assign = 60,                    /* assign  */
  YYSYMBOL_array_assign = 61,              /* array_assign  */
  YYSYMBOL_if_else_command = 62,           /* if_else_command  */
  YYSYMBOL_for_command = 63,               /* for_command  */
  YYSYMBOL_while_command = 64,             /* while_command  */
  YYSYMBOL_read_command = 65,              /* read_command  */
  YYSYMBOL_write_command = 66,             /* write_command  */
  YYSYMBOL_return_command = 67,            /* return_command  */
  YYSYMBOL_expression = 68,                /* expression  */
  YYSYMBOL_arithmetic_expression = 69,     /* arithmetic_expression  */
  YYSYMBOL_logical_expression = 70,        /* logical_expression  */
  YYSYMBOL_term = 71,                      /* term  */
  YYSYMBOL_factor = 72                     /* factor  */
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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   392

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
       2,     2,    47,    45,     2,    46,     2,    48,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   151,   151,   164,   170,   178,   202,   221,   227,   235,
     246,   252,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   271,   272,   273,   278,   290,   304,   316,   331,
     346,   362,   375,   393,   406,   415,   420,   427,   433,   434,
     437,   442,   447,   454,   459,   464,   469,   474,   479,   484,
     489,   494,   499,   506,   507,   512,   519,   524,   529,   536,
     543,   548,   553
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
  "RETURN", "ID", "TINT", "TFLOAT", "TBOOL", "INTEGER", "FLOATING", "LET",
  "MUT", "COLON", "COMMA", "ARROW", "LEFT", "RIGHT", "LBRACE", "RBRACE",
  "LBRACKET", "RBRACKET", "NOT", "AND", "OR", "TRUE", "FALSE", "ATRIB",
  "EQ", "NE", "LT", "LE", "GT", "GE", "IF", "ELSE", "FOR", "IN", "TO",
  "WHILE", "READ", "WRITE", "WRITELN", "EOL", "'+'", "'-'", "'*'", "'/'",
  "$accept", "program", "fns", "fn", "parameters", "parameter", "commands",
  "command", "TYPE", "declaration", "array_declaration", "assign",
  "array_assign", "if_else_command", "for_command", "while_command",
  "read_command", "write_command", "return_command", "expression",
  "arithmetic_expression", "logical_expression", "term", "factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-93)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      17,    31,    44,    66,   -93,    53,   -93,    41,   -93,    25,
      55,    72,    65,    -4,   -93,    70,    77,    76,    81,    74,
      79,    76,   -93,   -93,   -93,    87,   -93,    76,   165,   -93,
     165,    93,    69,    -6,   100,    69,   101,    69,   104,   106,
     109,    11,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,    62,   165,   107,   -93,   -93,    69,    69,
     -93,   -93,   192,    12,   -93,   -19,   -93,    69,    69,   125,
     341,   110,   127,   115,   133,    69,    69,   -93,   -93,   -93,
      95,    69,   257,   131,   -93,    69,    69,    69,    69,    69,
      69,    69,    69,   -93,   203,   203,   203,   203,   304,   208,
     137,   165,   103,   165,   142,   274,   291,   -93,   317,   -93,
     -93,   358,   352,   123,   123,   -93,   -93,   -93,   -93,    69,
     -93,   -93,   -93,   -93,   135,   -93,    18,   105,   203,   138,
     120,   121,   122,   -93,    69,    76,   -23,   136,   -27,   -93,
     -93,   -93,   -93,   224,   130,    69,   -93,   150,   203,   -93,
      69,   240,   165,   -11,   330,   -93,   147,   165,   139,   -93,
     156,   -93,   -93
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     4,     0,     1,     0,     3,     0,
       0,     0,     0,     0,     7,     0,     0,     0,     0,     0,
       0,     0,    22,    23,    24,     0,     8,     0,     0,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,     0,    58,    56,    57,     0,     0,
      61,    62,     0,    38,    39,    42,    53,     0,     0,     0,
       0,    39,     0,    39,     0,     0,     0,     2,    11,     6,
       0,     0,     0,    39,    45,     0,     0,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     0,    60,
      52,    43,    44,    46,    47,    48,    49,    50,    51,     0,
      40,    41,    54,    55,     0,    28,     0,     0,     0,     0,
       0,     0,     0,    59,     0,     0,     0,    31,     0,    33,
      34,    35,    36,     0,     0,     0,    25,     0,     0,    29,
       0,     0,     0,     0,     0,    26,     0,     0,     0,    30,
       0,    27,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -93,   -93,   -93,   182,   -93,   168,   -30,   -40,   -17,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -26,
     -92,   -28,   -93,   -20
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,    13,    14,    41,    42,    25,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    70,
      63,    64,    65,    66
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      53,    78,   120,   121,    29,   145,    62,    71,   157,    73,
      31,    18,   148,    78,    19,    67,    32,    33,    94,    95,
       1,   146,    68,    34,    80,    22,    23,    24,    96,    97,
      83,    77,    82,    84,    94,    95,   138,     5,    11,   135,
      78,    98,    99,    12,     6,    10,    35,     5,    36,   105,
     106,    37,    38,    39,    40,   108,   153,    94,    95,   111,
     112,   113,   114,   115,   116,   117,   118,    32,    33,     7,
       9,   127,    15,   129,    34,    55,   122,   123,    16,    56,
      57,    17,    79,    22,    23,    24,    58,    78,    20,    78,
      27,    21,    59,    82,    11,    60,    61,    35,    28,    36,
      32,    33,    37,    38,    39,    40,    30,    34,   143,   136,
      32,    33,    54,    69,    72,   107,    78,    34,   144,   151,
      78,    74,   156,    75,   154,   137,    76,   160,    81,   101,
      35,   100,    36,   102,   103,    37,    38,    39,    40,   104,
      35,   128,    36,    32,    33,    37,    38,    39,    40,   110,
      34,   126,    32,    33,    89,    90,    91,    92,   139,    34,
     130,    32,    33,   134,   140,   141,   142,   159,    34,   152,
      32,    33,   147,    35,   150,    36,   162,    34,    37,    38,
      39,    40,    35,   161,    36,     8,    26,    37,    38,    39,
      40,    35,     0,    36,     0,     0,    37,    38,    39,    40,
      35,     0,    36,     0,     0,    37,    38,    39,    40,    55,
       0,     0,     0,    56,    57,     0,    85,    86,     0,     0,
     119,    87,    88,    89,    90,    91,    92,     0,     0,    60,
      61,     0,    85,    86,     0,     0,    93,    87,    88,    89,
      90,    91,    92,     0,     0,     0,     0,     0,    85,    86,
       0,     0,   125,    87,    88,    89,    90,    91,    92,     0,
       0,     0,     0,     0,    85,    86,     0,     0,   149,    87,
      88,    89,    90,    91,    92,   109,     0,     0,     0,     0,
       0,    85,    86,     0,   155,     0,    87,    88,    89,    90,
      91,    92,   131,     0,     0,     0,     0,     0,    85,    86,
       0,     0,     0,    87,    88,    89,    90,    91,    92,   132,
       0,     0,     0,     0,     0,    85,    86,     0,     0,     0,
      87,    88,    89,    90,    91,    92,   124,     0,    85,    86,
       0,     0,     0,    87,    88,    89,    90,    91,    92,   133,
       0,    85,    86,     0,     0,     0,    87,    88,    89,    90,
      91,    92,   158,     0,    85,    86,     0,     0,     0,    87,
      88,    89,    90,    91,    92,    85,    86,     0,     0,     0,
      87,    88,    89,    90,    91,    92,    85,     0,     0,     0,
       0,    87,    88,    89,    90,    91,    92,    87,    88,    89,
      90,    91,    92
};

static const yytype_int16 yycheck[] =
{
      30,    41,    94,    95,    21,    28,    32,    35,    19,    37,
      27,    15,    39,    53,    18,    21,     5,     6,    45,    46,
       3,    44,    28,    12,    54,     7,     8,     9,    47,    48,
      58,    20,    58,    59,    45,    46,   128,     6,    13,    21,
      80,    67,    68,    18,     0,     4,    35,     6,    37,    75,
      76,    40,    41,    42,    43,    81,   148,    45,    46,    85,
      86,    87,    88,    89,    90,    91,    92,     5,     6,     3,
      17,   101,    17,   103,    12,     6,    96,    97,     6,    10,
      11,    16,    20,     7,     8,     9,    17,   127,    18,   129,
      16,    14,    23,   119,    13,    26,    27,    35,    19,    37,
       5,     6,    40,    41,    42,    43,    19,    12,   134,   126,
       5,     6,    19,    13,    13,    20,   156,    12,   135,   145,
     160,    17,   152,    17,   150,    20,    17,   157,    21,    19,
      35,     6,    37,     6,    19,    40,    41,    42,    43,     6,
      35,    38,    37,     5,     6,    40,    41,    42,    43,    18,
      12,    14,     5,     6,    31,    32,    33,    34,    20,    12,
      18,     5,     6,    28,    44,    44,    44,    20,    12,    19,
       5,     6,    36,    35,    44,    37,    20,    12,    40,    41,
      42,    43,    35,    44,    37,     3,    18,    40,    41,    42,
      43,    35,    -1,    37,    -1,    -1,    40,    41,    42,    43,
      35,    -1,    37,    -1,    -1,    40,    41,    42,    43,     6,
      -1,    -1,    -1,    10,    11,    -1,    24,    25,    -1,    -1,
      17,    29,    30,    31,    32,    33,    34,    -1,    -1,    26,
      27,    -1,    24,    25,    -1,    -1,    44,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    24,    25,
      -1,    -1,    44,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    44,    29,
      30,    31,    32,    33,    34,    18,    -1,    -1,    -1,    -1,
      -1,    24,    25,    -1,    44,    -1,    29,    30,    31,    32,
      33,    34,    18,    -1,    -1,    -1,    -1,    -1,    24,    25,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    34,    18,
      -1,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    34,    22,    -1,    24,    25,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    34,    22,
      -1,    24,    25,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    34,    22,    -1,    24,    25,    -1,    -1,    -1,    29,
      30,    31,    32,    33,    34,    24,    25,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    34,    24,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    29,    30,    31,
      32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    50,    51,    52,     6,     0,     3,    52,    17,
       4,    13,    18,    53,    54,    17,     6,    16,    15,    18,
      18,    14,     7,     8,     9,    57,    54,    16,    19,    57,
      19,    57,     5,     6,    12,    35,    37,    40,    41,    42,
      43,    55,    56,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    55,    19,     6,    10,    11,    17,    23,
      26,    27,    68,    69,    70,    71,    72,    21,    28,    13,
      68,    70,    13,    70,    17,    17,    17,    20,    56,    20,
      55,    21,    68,    70,    68,    24,    25,    29,    30,    31,
      32,    33,    34,    44,    45,    46,    47,    48,    68,    68,
       6,    19,     6,    19,     6,    68,    68,    20,    68,    18,
      18,    68,    68,    68,    68,    68,    68,    68,    68,    17,
      69,    69,    72,    72,    22,    44,    14,    55,    38,    55,
      18,    18,    18,    22,    28,    21,    57,    20,    69,    20,
      44,    44,    44,    68,    57,    28,    44,    36,    39,    44,
      44,    68,    19,    69,    68,    44,    55,    19,    22,    20,
      55,    44,    20
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    53,    53,    54,
      55,    55,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    57,    57,    57,    58,    58,    59,    60,    61,
      62,    62,    63,    64,    65,    66,    66,    67,    68,    68,
      69,    69,    69,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    71,    71,    71,    72,    72,    72,    72,
      72,    72,    72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     8,     2,     1,    10,     9,     1,     3,     4,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     6,     8,    10,     4,     7,
       9,     5,    10,     5,     5,     5,     5,     3,     1,     1,
       3,     3,     1,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     1,     1,     4,
       3,     1,     1
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
  case 2: /* program: fns FUNCTION MAIN LEFT RIGHT LBRACE commands RBRACE  */
#line 151 "compiler.y"
                                                             { 
        cout<< "Program Started." << endl;
        ast_root = new ProgramNode();
        MainFunctionNode* main_func_node_ptr = new MainFunctionNode();
        std::vector<CommandNode*>* cmds_list = (yyvsp[-1].command_list_ptr);
        for (CommandNode* cmd : *cmds_list) {
            main_func_node_ptr->addCommand(cmd);
        }
        ast_root->mainFunction = main_func_node_ptr;
        ast_root->functions = (yyvsp[-7].function_list_ptr);
        delete cmds_list;
    }
#line 1306 "compiler.tab.c"
    break;

  case 3: /* fns: fns fn  */
#line 165 "compiler.y"
    {
        (yyval.function_list_ptr) = (yyvsp[-1].function_list_ptr);
        (yyval.function_list_ptr)->push_back((yyvsp[0].function_node_ptr));
        //cout << "[INFO] " << "\t Function added to function list." << endl;
    }
#line 1316 "compiler.tab.c"
    break;

  case 4: /* fns: fn  */
#line 171 "compiler.y"
    {
        (yyval.function_list_ptr) = new std::vector<FunctionNode*>();
        (yyval.function_list_ptr)->push_back((yyvsp[0].function_node_ptr));
        //cout << "[INFO] " << "\t Function added to function list." << endl;
    }
#line 1326 "compiler.tab.c"
    break;

  case 5: /* fn: FUNCTION ID LEFT parameters RIGHT ARROW TYPE LBRACE commands RBRACE  */
#line 178 "compiler.y"
                                                                        { 
        IdentifierNode* id_node_ptr = new IdentifierNode(*(yyvsp[-8].str));
        TypeNode* return_type_node_ptr = (yyvsp[-3].type_node_ptr);

        FunctionNode* function_node_ptr = new FunctionNode(id_node_ptr, return_type_node_ptr);

        std::vector<ParameterNode*>* prmt_list = (yyvsp[-6].parameter_list_ptr);
        for (ParameterNode* prmt : *prmt_list) {
            function_node_ptr->addParameter(prmt);
            st.variables.insert({prmt->identifier->getIdentifier(), prmt->getType()});
        }
        delete prmt_list;
        
        std::vector<CommandNode*>* cmds_list = (yyvsp[-1].command_list_ptr);
        for (CommandNode* cmd : *cmds_list) {
            function_node_ptr->addCommand(cmd);
        }
        delete cmds_list;

        (yyval.function_node_ptr) = function_node_ptr;
        st.functions.insert({id_node_ptr->getIdentifier(), return_type_node_ptr});
        //cout << "[INFO] " << "\t Function " << *$2 << " added to AST." << endl;
        delete (yyvsp[-8].str);
    }
#line 1355 "compiler.tab.c"
    break;

  case 6: /* fn: FUNCTION ID LEFT RIGHT ARROW TYPE LBRACE commands RBRACE  */
#line 202 "compiler.y"
                                                               { 
        IdentifierNode* id_node_ptr = new IdentifierNode(*(yyvsp[-7].str));
        TypeNode* return_type_node_ptr = (yyvsp[-3].type_node_ptr);

        FunctionNode* function_node_ptr = new FunctionNode(id_node_ptr, return_type_node_ptr);

        std::vector<CommandNode*>* cmds_list = (yyvsp[-1].command_list_ptr);
        for (CommandNode* cmd : *cmds_list) {
            function_node_ptr->addCommand(cmd);
        }
        delete cmds_list;

        (yyval.function_node_ptr) = function_node_ptr;
        st.functions.insert({id_node_ptr->getIdentifier(), return_type_node_ptr});
        //cout << "[INFO] " << "\t Function " << *$2 << " added to AST." << endl;
        delete (yyvsp[-7].str);
    }
#line 1377 "compiler.tab.c"
    break;

  case 7: /* parameters: parameter  */
#line 222 "compiler.y"
    {
        (yyval.parameter_list_ptr) = new std::vector<ParameterNode*>();
        (yyval.parameter_list_ptr)->push_back((yyvsp[0].parameter_node_ptr));
        //cout << "[INFO] " << "\t Parameter added to parameter list." << endl;    
    }
#line 1387 "compiler.tab.c"
    break;

  case 8: /* parameters: parameters COMMA parameter  */
#line 228 "compiler.y"
    {
        (yyval.parameter_list_ptr) = (yyvsp[-2].parameter_list_ptr);
        (yyval.parameter_list_ptr)->push_back((yyvsp[0].parameter_node_ptr));
        //cout << "[INFO] " << "\t Parameter added to parameter list." << endl;    
    }
#line 1397 "compiler.tab.c"
    break;

  case 9: /* parameter: MUT ID COLON TYPE  */
#line 236 "compiler.y"
    {
        IdentifierNode* id_node_ptr = new IdentifierNode(*(yyvsp[-2].str));
        TypeNode* type_node_ptr = (yyvsp[0].type_node_ptr);

        (yyval.parameter_node_ptr) = new ParameterNode(id_node_ptr, type_node_ptr);
        //cout << "[INFO] " << "\t Parameter " << *$2 << " added to AST." << endl;
        delete (yyvsp[-2].str);
    }
#line 1410 "compiler.tab.c"
    break;

  case 10: /* commands: command  */
#line 247 "compiler.y"
    {
        (yyval.command_list_ptr) = new std::vector<CommandNode*>();
        (yyval.command_list_ptr)->push_back((yyvsp[0].command_node_ptr));
        //cout << "[INFO] " << "\t Command added to command list." << endl;
    }
#line 1420 "compiler.tab.c"
    break;

  case 11: /* commands: commands command  */
#line 253 "compiler.y"
    {
        (yyval.command_list_ptr) = (yyvsp[-1].command_list_ptr);
        (yyval.command_list_ptr)->push_back((yyvsp[0].command_node_ptr));
        //cout << "[INFO] " << "\t Command added to command list." << endl;
    }
#line 1430 "compiler.tab.c"
    break;

  case 12: /* command: declaration  */
#line 259 "compiler.y"
                     { (yyval.command_node_ptr) = (yyvsp[0].var_decl_node_ptr); }
#line 1436 "compiler.tab.c"
    break;

  case 13: /* command: array_declaration  */
#line 260 "compiler.y"
                        { (yyval.command_node_ptr) = (yyvsp[0].array_decl_node_ptr); }
#line 1442 "compiler.tab.c"
    break;

  case 14: /* command: assign  */
#line 261 "compiler.y"
             { (yyval.command_node_ptr) = (yyvsp[0].Variable_assign_node_ptr); }
#line 1448 "compiler.tab.c"
    break;

  case 15: /* command: array_assign  */
#line 262 "compiler.y"
                   { (yyval.command_node_ptr) = (yyvsp[0].array_assign_node_ptr); }
#line 1454 "compiler.tab.c"
    break;

  case 16: /* command: if_else_command  */
#line 263 "compiler.y"
                      { (yyval.command_node_ptr) = (yyvsp[0].if_else_node_ptr); }
#line 1460 "compiler.tab.c"
    break;

  case 17: /* command: for_command  */
#line 264 "compiler.y"
                  { (yyval.command_node_ptr) = (yyvsp[0].for_node_ptr); }
#line 1466 "compiler.tab.c"
    break;

  case 18: /* command: while_command  */
#line 265 "compiler.y"
                    { (yyval.command_node_ptr) = (yyvsp[0].while_node_ptr); }
#line 1472 "compiler.tab.c"
    break;

  case 19: /* command: read_command  */
#line 266 "compiler.y"
                   { (yyval.command_node_ptr) = (yyvsp[0].input_node_ptr); }
#line 1478 "compiler.tab.c"
    break;

  case 20: /* command: write_command  */
#line 267 "compiler.y"
                    { (yyval.command_node_ptr) = (yyvsp[0].output_node_ptr); }
#line 1484 "compiler.tab.c"
    break;

  case 21: /* command: return_command  */
#line 268 "compiler.y"
                     { (yyval.command_node_ptr) = (yyvsp[0].return_node_ptr); }
#line 1490 "compiler.tab.c"
    break;

  case 22: /* TYPE: TINT  */
#line 271 "compiler.y"
           { (yyval.type_node_ptr) = new IntegerTypeNode(); }
#line 1496 "compiler.tab.c"
    break;

  case 23: /* TYPE: TFLOAT  */
#line 272 "compiler.y"
             { (yyval.type_node_ptr) = new FloatTypeNode(); }
#line 1502 "compiler.tab.c"
    break;

  case 24: /* TYPE: TBOOL  */
#line 273 "compiler.y"
            { (yyval.type_node_ptr) = new BooleanTypeNode; }
#line 1508 "compiler.tab.c"
    break;

  case 25: /* declaration: LET MUT ID COLON TYPE EOL  */
#line 279 "compiler.y"
    {   
        IdentifierNode* id_node_ptr = new IdentifierNode(*(yyvsp[-3].str));

        TypeNode* type_node_ptr = (yyvsp[-1].type_node_ptr);

        (yyval.var_decl_node_ptr) = new VariableDeclarationNode(type_node_ptr, id_node_ptr, nullptr);
        st.variables.insert({id_node_ptr->getIdentifier(), type_node_ptr});

        //cout << "[INFO] " << "\t Variable/Constant " << *$3 << " added to AST." << endl;
        delete (yyvsp[-3].str);
    }
#line 1524 "compiler.tab.c"
    break;

  case 26: /* declaration: LET MUT ID COLON TYPE ATRIB expression EOL  */
#line 291 "compiler.y"
    {   
        IdentifierNode* id_node_ptr = new IdentifierNode(*(yyvsp[-5].str));

        TypeNode* type_node_ptr = (yyvsp[-3].type_node_ptr);
    
        (yyval.var_decl_node_ptr) = new VariableDeclarationNode(type_node_ptr, id_node_ptr, (yyvsp[-1].expr_node_ptr));
        st.variables.insert({id_node_ptr->getIdentifier(), type_node_ptr});

        //cout << "[INFO] " << "\t Variable " << *$3 << " added to AST." << endl;
        delete (yyvsp[-5].str);
    }
#line 1540 "compiler.tab.c"
    break;

  case 27: /* array_declaration: LET MUT ID COLON LBRACKET TYPE EOL expression RBRACKET EOL  */
#line 305 "compiler.y"
{
    IdentifierNode* id_node_ptr = new IdentifierNode(*(yyvsp[-7].str));
    TypeNode* type_node_ptr = (yyvsp[-4].type_node_ptr);

    (yyval.array_decl_node_ptr) = new ArrayDeclarationNode(type_node_ptr, id_node_ptr, (yyvsp[-2].expr_node_ptr));
    st.vectors.insert({id_node_ptr->getIdentifier(), type_node_ptr});

    //cout << "[INFO] " << "\t Array " << *$3 << " added to AST." << endl;
    delete (yyvsp[-7].str);
}
#line 1555 "compiler.tab.c"
    break;

  case 28: /* assign: ID ATRIB expression EOL  */
#line 317 "compiler.y"
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
#line 1573 "compiler.tab.c"
    break;

  case 29: /* array_assign: ID LBRACKET expression RBRACKET ATRIB expression EOL  */
#line 332 "compiler.y"
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
#line 1591 "compiler.tab.c"
    break;

  case 30: /* if_else_command: IF logical_expression LBRACE commands RBRACE ELSE LBRACE commands RBRACE  */
#line 346 "compiler.y"
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
#line 1612 "compiler.tab.c"
    break;

  case 31: /* if_else_command: IF logical_expression LBRACE commands RBRACE  */
#line 362 "compiler.y"
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
#line 1628 "compiler.tab.c"
    break;

  case 32: /* for_command: FOR MUT ID IN arithmetic_expression TO arithmetic_expression LBRACE commands RBRACE  */
#line 375 "compiler.y"
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
#line 1650 "compiler.tab.c"
    break;

  case 33: /* while_command: WHILE logical_expression LBRACE commands RBRACE  */
#line 394 "compiler.y"
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
#line 1666 "compiler.tab.c"
    break;

  case 34: /* read_command: READ LEFT ID RIGHT EOL  */
#line 407 "compiler.y"
    {
        IdentifierNode* id_node_ptr = new IdentifierNode(*((yyvsp[-2].str)));
        (yyval.input_node_ptr) = new InputNode(id_node_ptr);
        //cout << "[INFO] " << "\t Input command AST node created." << endl;
        delete (yyvsp[-2].str);
    }
#line 1677 "compiler.tab.c"
    break;

  case 35: /* write_command: WRITE LEFT expression RIGHT EOL  */
#line 416 "compiler.y"
    {
        (yyval.output_node_ptr) = new OutputNode((yyvsp[-2].expr_node_ptr),false);
        //cout << "[INFO] " << "\t Output command AST node created." << endl;
    }
#line 1686 "compiler.tab.c"
    break;

  case 36: /* write_command: WRITELN LEFT expression RIGHT EOL  */
#line 421 "compiler.y"
    {
        (yyval.output_node_ptr) = new OutputNode((yyvsp[-2].expr_node_ptr), true);
        //cout << "[INFO] " << "\t Output command AST node created." << endl;
    }
#line 1695 "compiler.tab.c"
    break;

  case 37: /* return_command: RETURN expression EOL  */
#line 428 "compiler.y"
    {
        (yyval.return_node_ptr) = new ReturnNode((yyvsp[-1].expr_node_ptr));
        //cout << "[INFO] " << "\t Return command AST node created." << endl;
    }
#line 1704 "compiler.tab.c"
    break;

  case 38: /* expression: arithmetic_expression  */
#line 433 "compiler.y"
                                  { (yyval.expr_node_ptr) = (yyvsp[0].arith_expr_node_ptr); }
#line 1710 "compiler.tab.c"
    break;

  case 39: /* expression: logical_expression  */
#line 434 "compiler.y"
                         { (yyval.expr_node_ptr) = (yyvsp[0].logical_expr_node_ptr); }
#line 1716 "compiler.tab.c"
    break;

  case 40: /* arithmetic_expression: arithmetic_expression '+' arithmetic_expression  */
#line 438 "compiler.y"
    { 
        (yyval.arith_expr_node_ptr) = new AdditionOperatorNode((yyvsp[-2].arith_expr_node_ptr), (yyvsp[0].arith_expr_node_ptr)); 
        //cout << "[INFO] " << "\t Addition operation added to AST." << endl;
    }
#line 1725 "compiler.tab.c"
    break;

  case 41: /* arithmetic_expression: arithmetic_expression '-' arithmetic_expression  */
#line 443 "compiler.y"
    { 
        (yyval.arith_expr_node_ptr) = new SubtractionOperatorNode((yyvsp[-2].arith_expr_node_ptr), (yyvsp[0].arith_expr_node_ptr)); 
        //cout << "[INFO] " << "\t Subtraction operation added to AST." << endl;
    }
#line 1734 "compiler.tab.c"
    break;

  case 42: /* arithmetic_expression: term  */
#line 448 "compiler.y"
    { 
        (yyval.arith_expr_node_ptr) = static_cast<ArithmeticExpressionNode*>((yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Term added to arithmetic expression." << endl;
    }
#line 1743 "compiler.tab.c"
    break;

  case 43: /* logical_expression: expression AND expression  */
#line 455 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new LogicalAndOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr));
        //cout << "[INFO] " << "\t Logical AND operation added to AST." << endl;
    }
#line 1752 "compiler.tab.c"
    break;

  case 44: /* logical_expression: expression OR expression  */
#line 460 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new LogicalOrOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr));
        //cout << "[INFO] " << "\t Logical OR operation added to AST." << endl;
    }
#line 1761 "compiler.tab.c"
    break;

  case 45: /* logical_expression: NOT expression  */
#line 465 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new NotOperatorNode((yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Logical NOT operation added to AST." << endl;
    }
#line 1770 "compiler.tab.c"
    break;

  case 46: /* logical_expression: expression EQ expression  */
#line 470 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new EqualityOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Equality operation added to AST." << endl;
    }
#line 1779 "compiler.tab.c"
    break;

  case 47: /* logical_expression: expression NE expression  */
#line 475 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new InequalityOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Inequality operation added to AST." << endl;
    }
#line 1788 "compiler.tab.c"
    break;

  case 48: /* logical_expression: expression LT expression  */
#line 480 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new LessThanOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Less than operation added to AST." << endl;
    }
#line 1797 "compiler.tab.c"
    break;

  case 49: /* logical_expression: expression LE expression  */
#line 485 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new LessThanOrEqualOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Less than or equal operation added to AST." << endl;
    }
#line 1806 "compiler.tab.c"
    break;

  case 50: /* logical_expression: expression GT expression  */
#line 490 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new GreaterThanOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Greater than operation added to AST." << endl;
    }
#line 1815 "compiler.tab.c"
    break;

  case 51: /* logical_expression: expression GE expression  */
#line 495 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new GreaterThanOrEqualOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Greater than or equal operation added to AST." << endl;
    }
#line 1824 "compiler.tab.c"
    break;

  case 52: /* logical_expression: LEFT logical_expression RIGHT  */
#line 500 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = (yyvsp[-1].logical_expr_node_ptr); 
        //cout << "[INFO] " << "\t Parentheses added to logical expression." << endl;
    }
#line 1833 "compiler.tab.c"
    break;

  case 54: /* term: term '*' factor  */
#line 508 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new MultiplicationOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Multiplication operation added to AST." << endl;
    }
#line 1842 "compiler.tab.c"
    break;

  case 55: /* term: term '/' factor  */
#line 513 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new DivisionOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Division operation added to AST." << endl;
    }
#line 1851 "compiler.tab.c"
    break;

  case 56: /* factor: INTEGER  */
#line 520 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new IntegerLiteralNode((yyvsp[0].ival)); 
        //cout << "[INFO] " << "\t Integer literal " << $1 << " added to AST." << endl;
    }
#line 1860 "compiler.tab.c"
    break;

  case 57: /* factor: FLOATING  */
#line 525 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new FloatLiteralNode((yyvsp[0].fval)); 
        //cout << "[INFO] " << "\t Float literal " << $1 << " added to AST." << endl;
    }
#line 1869 "compiler.tab.c"
    break;

  case 58: /* factor: ID  */
#line 530 "compiler.y"
    { 
        IdentifierNode* id_node_ptr = new IdentifierNode(*(yyvsp[0].str));
        (yyval.expr_node_ptr) = id_node_ptr; 
        //cout << "[INFO] " << "\t Identifier " << *$1 << " added to AST." << endl;
        delete (yyvsp[0].str);
    }
#line 1880 "compiler.tab.c"
    break;

  case 59: /* factor: ID LBRACKET expression RBRACKET  */
#line 537 "compiler.y"
    { 
        IdentifierNode* id_node_ptr = new IdentifierNode(*(yyvsp[-3].str));
        (yyval.expr_node_ptr) = new ArrayAcessNode(id_node_ptr, (yyvsp[-1].expr_node_ptr));
        //cout << "[INFO] " << "\t Array access for " << *$1 << " added to AST." << endl;
        delete (yyvsp[-3].str);
    }
#line 1891 "compiler.tab.c"
    break;

  case 60: /* factor: LEFT expression RIGHT  */
#line 544 "compiler.y"
    { 
        (yyval.expr_node_ptr) = (yyvsp[-1].expr_node_ptr); 
        //cout << "[INFO] " << "\t Parentheses added to arithmetic expression." << endl;
    }
#line 1900 "compiler.tab.c"
    break;

  case 61: /* factor: TRUE  */
#line 549 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new BooleanLiteralNode(true); 
        //cout << "[INFO] " << "\t Boolean literal TRUE added to AST." << endl;
    }
#line 1909 "compiler.tab.c"
    break;

  case 62: /* factor: FALSE  */
#line 554 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new BooleanLiteralNode(false); 
        //cout << "[INFO] " << "\t Boolean literal FALSE added to AST." << endl;
    }
#line 1918 "compiler.tab.c"
    break;


#line 1922 "compiler.tab.c"

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

#line 560 "compiler.y"




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
        code.createFinalCode();
    }
    delete ast_root;
    ast_root = nullptr;
    return parse_result;
}
