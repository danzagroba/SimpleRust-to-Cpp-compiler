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
  YYSYMBOL_if_else_command = 54,           /* if_else_command  */
  YYSYMBOL_for_command = 55,               /* for_command  */
  YYSYMBOL_while_command = 56,             /* while_command  */
  YYSYMBOL_read_command = 57,              /* read_command  */
  YYSYMBOL_write_command = 58,             /* write_command  */
  YYSYMBOL_expression = 59,                /* expression  */
  YYSYMBOL_arithmetic_expression = 60,     /* arithmetic_expression  */
  YYSYMBOL_logical_expression = 61,        /* logical_expression  */
  YYSYMBOL_term = 62,                      /* term  */
  YYSYMBOL_factor = 63                     /* factor  */
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
#define YYLAST   287

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

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
       0,   139,   139,   149,   155,   162,   163,   164,   165,   166,
     167,   168,   169,   172,   173,   174,   179,   191,   205,   216,
     232,   248,   261,   279,   292,   301,   306,   312,   313,   316,
     321,   326,   333,   338,   343,   348,   353,   358,   363,   368,
     373,   378,   385,   386,   391,   398,   403,   408,   415,   420,
     425
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
  "assign", "if_else_command", "for_command", "while_command",
  "read_command", "write_command", "expression", "arithmetic_expression",
  "logical_expression", "term", "factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-59)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,     7,    17,    22,   -59,     6,    25,   111,    13,    36,
     175,    37,   175,    39,    42,    57,     5,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,   175,    67,   -59,   -59,
     -59,   175,   175,   -59,   -59,   239,   -28,    63,    24,   -59,
      68,    77,    78,   175,   175,   -59,   -59,   131,   -59,    81,
     181,    80,   -59,   175,   175,   175,   175,   175,   175,   175,
     175,   177,   177,   111,   177,   177,    61,   111,    83,   198,
     215,   -59,    44,   -59,   -59,   256,   250,    47,    47,   -59,
     -59,   -59,   -59,   175,   -59,   -59,    50,   -59,   -59,   177,
      75,    58,    60,    65,   -59,   -59,   -59,    19,   -17,    69,
      21,   -59,   -59,   -59,   -59,    87,   175,   -59,    92,   177,
     175,   147,   111,     4,   228,   -59,    86,   111,    88,   -59,
     100,   -59,   -59
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     3,     5,     6,
       7,     8,     9,    10,    11,    12,     0,     0,    47,    45,
      46,     0,     0,    49,    50,     0,    27,    28,    31,    42,
       0,    28,     0,     0,     0,     2,     4,     0,    28,     0,
       0,    28,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,     0,    48,    41,    32,    33,    35,    36,    37,
      38,    39,    40,     0,    29,    30,     0,    43,    44,     0,
       0,     0,     0,     0,    13,    14,    15,     0,     0,    21,
       0,    23,    24,    25,    26,     0,     0,    16,     0,     0,
       0,     0,     0,     0,     0,    17,     0,     0,     0,    20,
       0,    18,    22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -59,   -59,   -58,   -16,    30,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,   -25,   -49,    -8,   -59,     1
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    16,    17,    98,    18,    19,    20,    21,    22,
      23,    24,    25,    35,    36,    48,    38,    39
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      46,    47,    37,     1,    41,    86,    50,    52,   106,    90,
       8,     3,    84,    85,    61,    62,     9,     4,    69,    70,
     117,     6,    45,    51,   107,    94,    95,    96,    75,    76,
      77,    78,    79,    80,    81,    82,     5,    10,    26,    11,
     100,     7,    12,    13,    14,    15,    61,    62,    27,    40,
      94,    95,    96,    42,   116,     8,    43,   109,    50,   120,
     113,     9,    97,    61,    62,    87,    88,    99,    64,    65,
      46,    44,    49,    66,    46,    57,    58,    59,    60,    63,
       8,   111,    10,    68,    11,   114,     9,    12,    13,    14,
      15,     8,   101,    67,    72,    74,    89,     9,    91,   102,
      46,   103,   108,   119,    46,     8,   104,    10,   112,    11,
       0,     9,    12,    13,    14,    15,     8,   122,    10,     0,
      11,     0,     9,    12,    13,    14,    15,   105,   110,   121,
       0,     0,    10,     0,    11,     0,     0,    12,    13,    14,
      15,     0,     0,    10,     0,    11,     0,     0,    12,    13,
      14,    15,    53,    54,     0,     0,     0,    55,    56,    57,
      58,    59,    60,     0,     0,     0,     0,     0,    53,    54,
       0,     0,    71,    55,    56,    57,    58,    59,    60,     0,
      28,     0,    28,     0,    29,    30,    29,    30,   115,    31,
       0,    83,     0,     0,     0,    32,    73,     0,    33,    34,
      33,    34,    53,    54,     0,     0,     0,    55,    56,    57,
      58,    59,    60,    92,     0,     0,     0,     0,     0,    53,
      54,     0,     0,     0,    55,    56,    57,    58,    59,    60,
      93,     0,     0,     0,     0,     0,    53,    54,     0,     0,
       0,    55,    56,    57,    58,    59,    60,   118,     0,    53,
      54,     0,     0,     0,    55,    56,    57,    58,    59,    60,
      53,    54,     0,     0,     0,    55,    56,    57,    58,    59,
      60,    53,     0,     0,     0,     0,    55,    56,    57,    58,
      59,    60,    55,    56,    57,    58,    59,    60
};

static const yytype_int8 yycheck[] =
{
      16,    26,    10,     3,    12,    63,    31,    32,    25,    67,
       5,     4,    61,    62,    42,    43,    11,     0,    43,    44,
      16,    15,    17,    31,    41,     6,     7,     8,    53,    54,
      55,    56,    57,    58,    59,    60,    14,    32,    25,    34,
      89,    16,    37,    38,    39,    40,    42,    43,    12,    12,
       6,     7,     8,    14,   112,     5,    14,    36,    83,   117,
     109,    11,    18,    42,    43,    64,    65,    17,    44,    45,
      86,    14,     5,     5,    90,    28,    29,    30,    31,    16,
       5,   106,    32,     5,    34,   110,    11,    37,    38,    39,
      40,     5,    17,    16,    13,    15,    35,    11,    15,    41,
     116,    41,    33,    17,   120,     5,    41,    32,    16,    34,
      -1,    11,    37,    38,    39,    40,     5,    17,    32,    -1,
      34,    -1,    11,    37,    38,    39,    40,    97,    41,    41,
      -1,    -1,    32,    -1,    34,    -1,    -1,    37,    38,    39,
      40,    -1,    -1,    32,    -1,    34,    -1,    -1,    37,    38,
      39,    40,    21,    22,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    21,    22,
      -1,    -1,    41,    26,    27,    28,    29,    30,    31,    -1,
       5,    -1,     5,    -1,     9,    10,     9,    10,    41,    14,
      -1,    14,    -1,    -1,    -1,    20,    15,    -1,    23,    24,
      23,    24,    21,    22,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    15,    -1,    -1,    -1,    -1,    -1,    21,
      22,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      15,    -1,    -1,    -1,    -1,    -1,    21,    22,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    19,    -1,    21,
      22,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      21,    22,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    21,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    26,    27,    28,    29,    30,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    47,     4,     0,    14,    15,    16,     5,    11,
      32,    34,    37,    38,    39,    40,    48,    49,    51,    52,
      53,    54,    55,    56,    57,    58,    25,    12,     5,     9,
      10,    14,    20,    23,    24,    59,    60,    61,    62,    63,
      12,    61,    14,    14,    14,    17,    49,    59,    61,     5,
      59,    61,    59,    21,    22,    26,    27,    28,    29,    30,
      31,    42,    43,    16,    44,    45,     5,    16,     5,    59,
      59,    41,    13,    15,    15,    59,    59,    59,    59,    59,
      59,    59,    59,    14,    60,    60,    48,    63,    63,    35,
      48,    15,    15,    15,     6,     7,     8,    18,    50,    17,
      60,    17,    41,    41,    41,    50,    25,    41,    33,    36,
      41,    59,    16,    60,    59,    41,    48,    16,    19,    17,
      48,    41,    17
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    49,    49,    50,    50,    50,    51,    51,    52,    53,
      54,    54,    55,    56,    57,    58,    58,    59,    59,    60,
      60,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    62,    63,    63,    63,    63,    63,
      63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     6,     8,    10,     4,
       9,     5,    10,     5,     5,     5,     5,     1,     1,     3,
       3,     1,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     1,     1,     3,     1,
       1
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
#line 139 "compiler.y"
                                                         { 
        ast_root = new MainFunctionNode();
        cout<< "Program Started." << endl;
        std::vector<CommandNode*>* cmds_list = (yyvsp[-1].command_list_ptr);
        for (CommandNode* cmd : *cmds_list) {
            ast_root->addCommand(cmd);
        }
        delete cmds_list;
    }
#line 1254 "compiler.tab.c"
    break;

  case 3: /* commands: command  */
#line 150 "compiler.y"
    {
        (yyval.command_list_ptr) = new std::vector<CommandNode*>();
        (yyval.command_list_ptr)->push_back((yyvsp[0].command_node_ptr));
        //cout << "[INFO] " << "\t Command added to command list." << endl;
    }
#line 1264 "compiler.tab.c"
    break;

  case 4: /* commands: commands command  */
#line 156 "compiler.y"
    {
        (yyval.command_list_ptr) = (yyvsp[-1].command_list_ptr);
        (yyval.command_list_ptr)->push_back((yyvsp[0].command_node_ptr));
        //cout << "[INFO] " << "\t Command added to command list." << endl;
    }
#line 1274 "compiler.tab.c"
    break;

  case 5: /* command: declaration  */
#line 162 "compiler.y"
                     { (yyval.command_node_ptr) = (yyvsp[0].var_decl_node_ptr); }
#line 1280 "compiler.tab.c"
    break;

  case 6: /* command: array_declaration  */
#line 163 "compiler.y"
                        { (yyval.command_node_ptr) = (yyvsp[0].array_decl_node_ptr); }
#line 1286 "compiler.tab.c"
    break;

  case 7: /* command: assign  */
#line 164 "compiler.y"
             { (yyval.command_node_ptr) = (yyvsp[0].Variable_assign_node_ptr); }
#line 1292 "compiler.tab.c"
    break;

  case 8: /* command: if_else_command  */
#line 165 "compiler.y"
                      { (yyval.command_node_ptr) = (yyvsp[0].if_else_node_ptr); }
#line 1298 "compiler.tab.c"
    break;

  case 9: /* command: for_command  */
#line 166 "compiler.y"
                  { (yyval.command_node_ptr) = (yyvsp[0].for_node_ptr); }
#line 1304 "compiler.tab.c"
    break;

  case 10: /* command: while_command  */
#line 167 "compiler.y"
                    { (yyval.command_node_ptr) = (yyvsp[0].while_node_ptr); }
#line 1310 "compiler.tab.c"
    break;

  case 11: /* command: read_command  */
#line 168 "compiler.y"
                   { (yyval.command_node_ptr) = (yyvsp[0].input_node_ptr); }
#line 1316 "compiler.tab.c"
    break;

  case 12: /* command: write_command  */
#line 169 "compiler.y"
                    { (yyval.command_node_ptr) = (yyvsp[0].output_node_ptr); }
#line 1322 "compiler.tab.c"
    break;

  case 13: /* TYPE: TINT  */
#line 172 "compiler.y"
           { (yyval.type_node_ptr) = new IntegerTypeNode(); }
#line 1328 "compiler.tab.c"
    break;

  case 14: /* TYPE: TFLOAT  */
#line 173 "compiler.y"
             { (yyval.type_node_ptr) = new FloatTypeNode(); }
#line 1334 "compiler.tab.c"
    break;

  case 15: /* TYPE: TBOOL  */
#line 174 "compiler.y"
            { (yyval.type_node_ptr) = new BooleanTypeNode; }
#line 1340 "compiler.tab.c"
    break;

  case 16: /* declaration: LET MUT ID COLON TYPE EOL  */
#line 180 "compiler.y"
    {   
        IdentifierNode* id_node_ptr = new IdentifierNode(*(yyvsp[-3].str));

        TypeNode* type_node_ptr = (yyvsp[-1].type_node_ptr);

        (yyval.var_decl_node_ptr) = new VariableDeclarationNode(type_node_ptr, id_node_ptr, nullptr);
        st.variables.insert({id_node_ptr->getIdentifier(), type_node_ptr});

        //cout << "[INFO] " << "\t Variable/Constant " << *$3 << " added to AST." << endl;
        delete (yyvsp[-3].str);
    }
#line 1356 "compiler.tab.c"
    break;

  case 17: /* declaration: LET MUT ID COLON TYPE ATRIB expression EOL  */
#line 192 "compiler.y"
    {   
        IdentifierNode* id_node_ptr = new IdentifierNode(*(yyvsp[-5].str));

        TypeNode* type_node_ptr = (yyvsp[-3].type_node_ptr);
    
        (yyval.var_decl_node_ptr) = new VariableDeclarationNode(type_node_ptr, id_node_ptr, (yyvsp[-1].expr_node_ptr));
        st.variables.insert({id_node_ptr->getIdentifier(), type_node_ptr});

        //cout << "[INFO] " << "\t Variable " << *$3 << " added to AST." << endl;
        delete (yyvsp[-5].str);
    }
#line 1372 "compiler.tab.c"
    break;

  case 18: /* array_declaration: LET MUT ID COLON LBRACKET TYPE EOL expression RBRACKET EOL  */
#line 206 "compiler.y"
{
    IdentifierNode* id_node_ptr = new IdentifierNode(*(yyvsp[-7].str));
    TypeNode* type_node_ptr = (yyvsp[-4].type_node_ptr);

    (yyval.array_decl_node_ptr) = new ArrayDeclarationNode(type_node_ptr, id_node_ptr, (yyvsp[-2].expr_node_ptr));
    st.vectors.insert({id_node_ptr->getIdentifier(), type_node_ptr});

    delete (yyvsp[-7].str);
}
#line 1386 "compiler.tab.c"
    break;

  case 19: /* assign: ID ATRIB expression EOL  */
#line 217 "compiler.y"
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
#line 1404 "compiler.tab.c"
    break;

  case 20: /* if_else_command: IF logical_expression LBRACE commands RBRACE ELSE LBRACE commands RBRACE  */
#line 232 "compiler.y"
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
#line 1425 "compiler.tab.c"
    break;

  case 21: /* if_else_command: IF logical_expression LBRACE commands RBRACE  */
#line 248 "compiler.y"
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
#line 1441 "compiler.tab.c"
    break;

  case 22: /* for_command: FOR MUT ID IN arithmetic_expression TO arithmetic_expression LBRACE commands RBRACE  */
#line 261 "compiler.y"
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
#line 1463 "compiler.tab.c"
    break;

  case 23: /* while_command: WHILE logical_expression LBRACE commands RBRACE  */
#line 280 "compiler.y"
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
#line 1479 "compiler.tab.c"
    break;

  case 24: /* read_command: READ LEFT ID RIGHT EOL  */
#line 293 "compiler.y"
    {
        IdentifierNode* id_node_ptr = new IdentifierNode(*((yyvsp[-2].str)));
        (yyval.input_node_ptr) = new InputNode(id_node_ptr);
        //cout << "[INFO] " << "\t Input command AST node created." << endl;
        delete (yyvsp[-2].str);
    }
#line 1490 "compiler.tab.c"
    break;

  case 25: /* write_command: WRITE LEFT expression RIGHT EOL  */
#line 302 "compiler.y"
    {
        (yyval.output_node_ptr) = new OutputNode((yyvsp[-2].expr_node_ptr),false);
        //cout << "[INFO] " << "\t Output command AST node created." << endl;
    }
#line 1499 "compiler.tab.c"
    break;

  case 26: /* write_command: WRITELN LEFT expression RIGHT EOL  */
#line 307 "compiler.y"
    {
        (yyval.output_node_ptr) = new OutputNode((yyvsp[-2].expr_node_ptr), true);
        //cout << "[INFO] " << "\t Output command AST node created." << endl;
    }
#line 1508 "compiler.tab.c"
    break;

  case 27: /* expression: arithmetic_expression  */
#line 312 "compiler.y"
                                  { (yyval.expr_node_ptr) = (yyvsp[0].arith_expr_node_ptr); }
#line 1514 "compiler.tab.c"
    break;

  case 28: /* expression: logical_expression  */
#line 313 "compiler.y"
                         { (yyval.expr_node_ptr) = (yyvsp[0].logical_expr_node_ptr); }
#line 1520 "compiler.tab.c"
    break;

  case 29: /* arithmetic_expression: arithmetic_expression '+' arithmetic_expression  */
#line 317 "compiler.y"
    { 
        (yyval.arith_expr_node_ptr) = new AdditionOperatorNode((yyvsp[-2].arith_expr_node_ptr), (yyvsp[0].arith_expr_node_ptr)); 
        //cout << "[INFO] " << "\t Addition operation added to AST." << endl;
    }
#line 1529 "compiler.tab.c"
    break;

  case 30: /* arithmetic_expression: arithmetic_expression '-' arithmetic_expression  */
#line 322 "compiler.y"
    { 
        (yyval.arith_expr_node_ptr) = new SubtractionOperatorNode((yyvsp[-2].arith_expr_node_ptr), (yyvsp[0].arith_expr_node_ptr)); 
        //cout << "[INFO] " << "\t Subtraction operation added to AST." << endl;
    }
#line 1538 "compiler.tab.c"
    break;

  case 31: /* arithmetic_expression: term  */
#line 327 "compiler.y"
    { 
        (yyval.arith_expr_node_ptr) = static_cast<ArithmeticExpressionNode*>((yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Term added to arithmetic expression." << endl;
    }
#line 1547 "compiler.tab.c"
    break;

  case 32: /* logical_expression: expression AND expression  */
#line 334 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new LogicalAndOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr));
        //cout << "[INFO] " << "\t Logical AND operation added to AST." << endl;
    }
#line 1556 "compiler.tab.c"
    break;

  case 33: /* logical_expression: expression OR expression  */
#line 339 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new LogicalOrOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr));
        //cout << "[INFO] " << "\t Logical OR operation added to AST." << endl;
    }
#line 1565 "compiler.tab.c"
    break;

  case 34: /* logical_expression: NOT expression  */
#line 344 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new NotOperatorNode((yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Logical NOT operation added to AST." << endl;
    }
#line 1574 "compiler.tab.c"
    break;

  case 35: /* logical_expression: expression EQ expression  */
#line 349 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new EqualityOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Equality operation added to AST." << endl;
    }
#line 1583 "compiler.tab.c"
    break;

  case 36: /* logical_expression: expression NE expression  */
#line 354 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new InequalityOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Inequality operation added to AST." << endl;
    }
#line 1592 "compiler.tab.c"
    break;

  case 37: /* logical_expression: expression LT expression  */
#line 359 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new LessThanOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Less than operation added to AST." << endl;
    }
#line 1601 "compiler.tab.c"
    break;

  case 38: /* logical_expression: expression LE expression  */
#line 364 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new LessThanOrEqualOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Less than or equal operation added to AST." << endl;
    }
#line 1610 "compiler.tab.c"
    break;

  case 39: /* logical_expression: expression GT expression  */
#line 369 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new GreaterThanOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Greater than operation added to AST." << endl;
    }
#line 1619 "compiler.tab.c"
    break;

  case 40: /* logical_expression: expression GE expression  */
#line 374 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = new GreaterThanOrEqualOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Greater than or equal operation added to AST." << endl;
    }
#line 1628 "compiler.tab.c"
    break;

  case 41: /* logical_expression: LEFT logical_expression RIGHT  */
#line 379 "compiler.y"
    { 
        (yyval.logical_expr_node_ptr) = (yyvsp[-1].logical_expr_node_ptr); 
        //cout << "[INFO] " << "\t Parentheses added to logical expression." << endl;
    }
#line 1637 "compiler.tab.c"
    break;

  case 43: /* term: term '*' factor  */
#line 387 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new MultiplicationOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Multiplication operation added to AST." << endl;
    }
#line 1646 "compiler.tab.c"
    break;

  case 44: /* term: term '/' factor  */
#line 392 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new DivisionOperatorNode((yyvsp[-2].expr_node_ptr), (yyvsp[0].expr_node_ptr)); 
        //cout << "[INFO] " << "\t Division operation added to AST." << endl;
    }
#line 1655 "compiler.tab.c"
    break;

  case 45: /* factor: INTEGER  */
#line 399 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new IntegerLiteralNode((yyvsp[0].ival)); 
        //cout << "[INFO] " << "\t Integer literal " << $1 << " added to AST." << endl;
    }
#line 1664 "compiler.tab.c"
    break;

  case 46: /* factor: FLOATING  */
#line 404 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new FloatLiteralNode((yyvsp[0].fval)); 
        //cout << "[INFO] " << "\t Float literal " << $1 << " added to AST." << endl;
    }
#line 1673 "compiler.tab.c"
    break;

  case 47: /* factor: ID  */
#line 409 "compiler.y"
    { 
        IdentifierNode* id_node_ptr = new IdentifierNode(*(yyvsp[0].str));
        (yyval.expr_node_ptr) = id_node_ptr; 
        //cout << "[INFO] " << "\t Identifier " << *$1 << " added to AST." << endl;
        delete (yyvsp[0].str);
    }
#line 1684 "compiler.tab.c"
    break;

  case 48: /* factor: LEFT expression RIGHT  */
#line 416 "compiler.y"
    { 
        (yyval.expr_node_ptr) = (yyvsp[-1].expr_node_ptr); 
        //cout << "[INFO] " << "\t Parentheses added to arithmetic expression." << endl;
    }
#line 1693 "compiler.tab.c"
    break;

  case 49: /* factor: TRUE  */
#line 421 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new BooleanLiteralNode(true); 
        //cout << "[INFO] " << "\t Boolean literal TRUE added to AST." << endl;
    }
#line 1702 "compiler.tab.c"
    break;

  case 50: /* factor: FALSE  */
#line 426 "compiler.y"
    { 
        (yyval.expr_node_ptr) = new BooleanLiteralNode(false); 
        //cout << "[INFO] " << "\t Boolean literal FALSE added to AST." << endl;
    }
#line 1711 "compiler.tab.c"
    break;


#line 1715 "compiler.tab.c"

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

#line 432 "compiler.y"




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
