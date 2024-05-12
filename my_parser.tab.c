/* A Bison parser, made by GNU Bison 3.7.4.  */

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
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "my_parser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <math.h>

    #include "TableSymbole.h"
    #include "quadruplet.h"
    #include "pile.h"

    SymbolTable *TS;
    qTable *TQ;
    qPile *P;

    qNoeud* quad;
    Symbol* node;

    int sauvLabel;

    int qC = 0;

    extern FILE *yyin;
    int yylex();
    void yyerror(const char *s);
    void yyerrorSemantic(char *s);

#line 98 "my_parser.tab.c"

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

#include "my_parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_COMMENT = 3,                    /* COMMENT  */
  YYSYMBOL_COMMENT_MULTILIGNE = 4,         /* COMMENT_MULTILIGNE  */
  YYSYMBOL_CARACTERE = 5,                  /* CARACTERE  */
  YYSYMBOL_CHAR = 6,                       /* CHAR  */
  YYSYMBOL_ENTIER = 7,                     /* ENTIER  */
  YYSYMBOL_FLOTTANT = 8,                   /* FLOTTANT  */
  YYSYMBOL_BOOLEAN_VRAI = 9,               /* BOOLEAN_VRAI  */
  YYSYMBOL_BOOLEAN_FAUX = 10,              /* BOOLEAN_FAUX  */
  YYSYMBOL_MAIN = 11,                      /* MAIN  */
  YYSYMBOL_PROCEDURE = 12,                 /* PROCEDURE  */
  YYSYMBOL_TYPE_CONS = 13,                 /* TYPE_CONS  */
  YYSYMBOL_TYPE_INT = 14,                  /* TYPE_INT  */
  YYSYMBOL_TYPE_FLT = 15,                  /* TYPE_FLT  */
  YYSYMBOL_TYPE_CAR = 16,                  /* TYPE_CAR  */
  YYSYMBOL_TYPE_STR = 17,                  /* TYPE_STR  */
  YYSYMBOL_TYPE_BLN = 18,                  /* TYPE_BLN  */
  YYSYMBOL_ID = 19,                        /* ID  */
  YYSYMBOL_RETURN = 20,                    /* RETURN  */
  YYSYMBOL_READ = 21,                      /* READ  */
  YYSYMBOL_WRITE = 22,                     /* WRITE  */
  YYSYMBOL_WHILE = 23,                     /* WHILE  */
  YYSYMBOL_FOR = 24,                       /* FOR  */
  YYSYMBOL_IF = 25,                        /* IF  */
  YYSYMBOL_ELSE = 26,                      /* ELSE  */
  YYSYMBOL_SWITCH = 27,                    /* SWITCH  */
  YYSYMBOL_CASE = 28,                      /* CASE  */
  YYSYMBOL_CASE_BREAK = 29,                /* CASE_BREAK  */
  YYSYMBOL_CASE_DEFAULT = 30,              /* CASE_DEFAULT  */
  YYSYMBOL_STRUCT = 31,                    /* STRUCT  */
  YYSYMBOL_FIN_INSTRUCTION = 32,           /* FIN_INSTRUCTION  */
  YYSYMBOL_INCREM = 33,                    /* INCREM  */
  YYSYMBOL_DECREM = 34,                    /* DECREM  */
  YYSYMBOL_PLUS = 35,                      /* PLUS  */
  YYSYMBOL_DIV = 36,                       /* DIV  */
  YYSYMBOL_MOINS = 37,                     /* MOINS  */
  YYSYMBOL_MUL = 38,                       /* MUL  */
  YYSYMBOL_MOD = 39,                       /* MOD  */
  YYSYMBOL_PUISS = 40,                     /* PUISS  */
  YYSYMBOL_PAR_OUV = 41,                   /* PAR_OUV  */
  YYSYMBOL_PAR_FERM = 42,                  /* PAR_FERM  */
  YYSYMBOL_INF_EGAL = 43,                  /* INF_EGAL  */
  YYSYMBOL_INF = 44,                       /* INF  */
  YYSYMBOL_SUPP = 45,                      /* SUPP  */
  YYSYMBOL_SUPP_EGAL = 46,                 /* SUPP_EGAL  */
  YYSYMBOL_EGALE = 47,                     /* EGALE  */
  YYSYMBOL_PASEGALE = 48,                  /* PASEGALE  */
  YYSYMBOL_NEGATION = 49,                  /* NEGATION  */
  YYSYMBOL_ET = 50,                        /* ET  */
  YYSYMBOL_OU = 51,                        /* OU  */
  YYSYMBOL_DEB_TABLEAU = 52,               /* DEB_TABLEAU  */
  YYSYMBOL_FIN_TABLEAU = 53,               /* FIN_TABLEAU  */
  YYSYMBOL_AFFECTATION = 54,               /* AFFECTATION  */
  YYSYMBOL_DEB_CORPS = 55,                 /* DEB_CORPS  */
  YYSYMBOL_FIN_CORPS = 56,                 /* FIN_CORPS  */
  YYSYMBOL_SEPARATEUR = 57,                /* SEPARATEUR  */
  YYSYMBOL_ACCES_STRUCT = 58,              /* ACCES_STRUCT  */
  YYSYMBOL_CASE_START = 59,                /* CASE_START  */
  YYSYMBOL_ADRESSE = 60,                   /* ADRESSE  */
  YYSYMBOL_IMPORT = 61,                    /* IMPORT  */
  YYSYMBOL_YYACCEPT = 62,                  /* $accept  */
  YYSYMBOL_Program = 63,                   /* Program  */
  YYSYMBOL_64_1 = 64,                      /* $@1  */
  YYSYMBOL_imports = 65,                   /* imports  */
  YYSYMBOL_import = 66,                    /* import  */
  YYSYMBOL_DeclarationFunctionMain = 67,   /* DeclarationFunctionMain  */
  YYSYMBOL_DeclarationFunctions = 68,      /* DeclarationFunctions  */
  YYSYMBOL_DeclarationFunction = 69,       /* DeclarationFunction  */
  YYSYMBOL_Entete = 70,                    /* Entete  */
  YYSYMBOL_Parameters = 71,                /* Parameters  */
  YYSYMBOL_Type = 72,                      /* Type  */
  YYSYMBOL_Tableau = 73,                   /* Tableau  */
  YYSYMBOL_Type_Struct = 74,               /* Type_Struct  */
  YYSYMBOL_declarations = 75,              /* declarations  */
  YYSYMBOL_statements = 76,                /* statements  */
  YYSYMBOL_signatureProcedure = 77,        /* signatureProcedure  */
  YYSYMBOL_statement = 78,                 /* statement  */
  YYSYMBOL_declaration = 79,               /* declaration  */
  YYSYMBOL_Parameter = 80,                 /* Parameter  */
  YYSYMBOL_assignment = 81,                /* assignment  */
  YYSYMBOL_82_2 = 82,                      /* $@2  */
  YYSYMBOL_signatureFonction = 83,         /* signatureFonction  */
  YYSYMBOL_ids = 84,                       /* ids  */
  YYSYMBOL_expression = 85,                /* expression  */
  YYSYMBOL_ifStatement = 86,               /* ifStatement  */
  YYSYMBOL_elseBlock = 87,                 /* elseBlock  */
  YYSYMBOL_whileStatement = 88,            /* whileStatement  */
  YYSYMBOL_while_part1 = 89,               /* while_part1  */
  YYSYMBOL_while_part2 = 90,               /* while_part2  */
  YYSYMBOL_while_part3 = 91,               /* while_part3  */
  YYSYMBOL_forStatement = 92,              /* forStatement  */
  YYSYMBOL_switchStatement = 93,           /* switchStatement  */
  YYSYMBOL_caseBlocks = 94,                /* caseBlocks  */
  YYSYMBOL_defaultBlock = 95,              /* defaultBlock  */
  YYSYMBOL_readStatement = 96,             /* readStatement  */
  YYSYMBOL_writeStatement = 97             /* writeStatement  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   776

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  207

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   316


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
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    87,    87,    87,   112,   114,   118,   121,   124,   126,
     130,   134,   135,   138,   140,   148,   149,   150,   151,   152,
     153,   157,   161,   164,   166,   170,   172,   176,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     233,   279,   283,   292,   293,   297,   297,   327,   350,   352,
     354,   360,   366,   372,   376,   382,   386,   392,   392,   394,
     405,   407,   472,   533,   595,   663,   729,   730,   759,   802,
     845,   850,   881,   912,   943,   975,  1030,  1085,  1135,  1191,
    1195,  1197,  1201,  1204,  1214,  1230,  1248,  1252,  1255,  1257,
    1260,  1262,  1266,  1270,  1271
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
  "\"end of file\"", "error", "\"invalid token\"", "COMMENT",
  "COMMENT_MULTILIGNE", "CARACTERE", "CHAR", "ENTIER", "FLOTTANT",
  "BOOLEAN_VRAI", "BOOLEAN_FAUX", "MAIN", "PROCEDURE", "TYPE_CONS",
  "TYPE_INT", "TYPE_FLT", "TYPE_CAR", "TYPE_STR", "TYPE_BLN", "ID",
  "RETURN", "READ", "WRITE", "WHILE", "FOR", "IF", "ELSE", "SWITCH",
  "CASE", "CASE_BREAK", "CASE_DEFAULT", "STRUCT", "FIN_INSTRUCTION",
  "INCREM", "DECREM", "PLUS", "DIV", "MOINS", "MUL", "MOD", "PUISS",
  "PAR_OUV", "PAR_FERM", "INF_EGAL", "INF", "SUPP", "SUPP_EGAL", "EGALE",
  "PASEGALE", "NEGATION", "ET", "OU", "DEB_TABLEAU", "FIN_TABLEAU",
  "AFFECTATION", "DEB_CORPS", "FIN_CORPS", "SEPARATEUR", "ACCES_STRUCT",
  "CASE_START", "ADRESSE", "IMPORT", "$accept", "Program", "$@1",
  "imports", "import", "DeclarationFunctionMain", "DeclarationFunctions",
  "DeclarationFunction", "Entete", "Parameters", "Type", "Tableau",
  "Type_Struct", "declarations", "statements", "signatureProcedure",
  "statement", "declaration", "Parameter", "assignment", "$@2",
  "signatureFonction", "ids", "expression", "ifStatement", "elseBlock",
  "whileStatement", "while_part1", "while_part2", "while_part3",
  "forStatement", "switchStatement", "caseBlocks", "defaultBlock",
  "readStatement", "writeStatement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
};
#endif

#define YYPACT_NINF (-135)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -135,    20,  -135,  -135,   -38,    29,  -135,     5,    -6,   -19,
     265,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,    -4,  -135,    21,    64,  -135,    -2,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,    71,    14,    15,    18,    19,
      23,    24,    47,   109,   109,  -135,    56,  -135,  -135,  -135,
    -135,  -135,   -22,  -135,  -135,   688,  -135,  -135,   109,  -135,
    -135,  -135,  -135,    -9,  -135,  -135,    69,   109,    65,   116,
     120,  -135,   109,   109,   109,    72,    80,   593,   191,    78,
    -135,   109,   101,   102,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   707,    94,
      82,  -135,   485,   -17,    86,   514,  -135,   107,   -29,   534,
     612,   631,  -135,  -135,  -135,  -135,  -135,   159,   707,  -135,
    -135,    54,  -135,    54,  -135,  -135,  -135,    61,    61,    61,
      61,    61,    61,   137,   726,   112,  -135,  -135,   113,  -135,
     146,  -135,  -135,   126,   156,   109,   109,   134,   135,    93,
      -8,   139,   161,  -135,   138,  -135,  -135,   172,  -135,   650,
     554,  -135,  -135,  -135,  -135,   171,  -135,  -135,  -135,   192,
    -135,   408,   162,   180,   109,   246,   -16,  -135,   109,   186,
    -135,   669,   194,   109,   163,   165,   574,  -135,   169,   170,
    -135,   486,  -135,  -135,   176,  -135,  -135,  -135,   466,  -135,
     300,   354,   437,  -135,  -135,   208,  -135
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     4,     1,     8,     0,     5,     0,     0,     0,
       0,     3,     9,     6,    25,    20,    15,    16,    19,    17,
      18,     0,    10,     0,     0,    13,     0,    31,    32,    54,
      53,    51,    52,    55,    56,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     0,    43,    44,    28,
      26,    29,     0,    30,    60,     0,    33,    34,     0,    35,
      36,    37,    38,     0,    13,    49,     0,     0,     0,     0,
       0,    83,     0,     0,     0,     0,    59,     0,    67,    42,
      41,     0,    68,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,     0,
       0,    14,     0,     0,     0,     0,    58,     0,     0,     0,
       0,     0,    23,    49,    68,    69,    70,     0,    45,    39,
      40,    61,    64,    62,    63,    65,    66,    72,    71,    73,
      74,    75,    76,    77,    78,     0,    82,    25,     0,    50,
      48,    57,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    25,     0,    25,    27,     0,    94,     0,
       0,    25,    88,    22,    24,     0,    48,    21,    46,     0,
      12,     0,     0,     0,     0,     0,    90,    85,     0,     0,
      93,     0,    80,     0,     0,     0,     0,    92,     0,     0,
      79,     0,    25,    87,     0,    25,    25,    25,    91,    11,
       0,     0,     0,    86,    81,     0,    89
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,   178,
     233,  -135,  -135,  -135,  -134,  -135,  -135,    95,   -45,  -135,
    -135,  -135,   132,   -43,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,  -135
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,     6,    11,     7,    12,    22,    63,
      46,    47,    48,   149,    24,    49,    50,    51,    52,    53,
     152,    54,   103,    55,    56,   190,    57,    58,    99,   136,
      59,    60,   176,   185,    61,    62
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      77,    78,   139,   154,    15,    16,    17,    18,    19,    20,
      80,   139,   183,   144,   184,    98,     9,    10,   101,   169,
       3,   171,    42,     5,   105,   140,    13,   175,   145,   109,
     110,   111,    81,   100,   166,     8,    14,    25,   118,    64,
      26,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    69,    70,   101,   198,    71,
      72,   200,   201,   202,    73,    74,    75,    27,    28,    29,
      30,    31,    32,    33,    34,    79,   104,    15,    16,    17,
      18,    19,    20,    35,   106,    36,    37,    38,    39,    40,
      85,    41,    87,    88,    89,    42,    84,    85,    86,    87,
      88,    89,   159,   160,   165,    43,    15,    16,    17,    18,
      19,    20,    65,    44,    29,    30,    31,    32,    33,    34,
      45,   113,   107,    66,    42,    67,   108,   112,    76,    68,
     117,   181,    66,   119,   120,   186,   135,   137,    68,   141,
     191,    27,    28,    29,    30,    31,    32,    33,    34,   163,
      43,    15,    16,    17,    18,    19,    20,    35,    44,    36,
      37,    38,    39,    40,   143,    41,   151,   153,   155,    42,
     114,   115,    84,    85,    86,    87,    88,    89,   156,    43,
      90,    91,    92,    93,    94,    95,   157,    44,   158,   161,
     162,   172,   167,   168,   170,    27,    28,    29,    30,    31,
      32,    33,    34,    80,   179,    15,    16,    17,    18,    19,
      20,    35,   180,    36,    37,    38,    39,    40,   187,    41,
     189,   193,   192,    42,   195,   196,    84,    85,    86,    87,
      88,    89,   199,    43,    90,    91,    92,    93,    94,    95,
     206,    44,   102,    23,   164,   150,     0,     0,   177,    27,
      28,    29,    30,    31,    32,    33,    34,     0,     0,    15,
      16,    17,    18,    19,    20,    35,     0,    36,    37,    38,
      39,    40,     0,    41,     0,     0,     0,    42,    15,    16,
      17,    18,    19,    20,    21,     0,     0,    43,     0,     0,
       0,     0,     0,     0,     0,    44,     0,     0,     0,     0,
       0,     0,   182,    27,    28,    29,    30,    31,    32,    33,
      34,     0,     0,    15,    16,    17,    18,    19,    20,    35,
       0,    36,    37,    38,    39,    40,     0,    41,     0,     0,
       0,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    43,     0,     0,     0,     0,     0,     0,     0,    44,
       0,     0,     0,     0,     0,     0,   203,    27,    28,    29,
      30,    31,    32,    33,    34,     0,     0,    15,    16,    17,
      18,    19,    20,    35,     0,    36,    37,    38,    39,    40,
       0,    41,     0,     0,     0,    42,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    43,     0,     0,     0,     0,
       0,     0,     0,    44,     0,     0,     0,     0,     0,     0,
     204,    27,    28,    29,    30,    31,    32,    33,    34,     0,
       0,    15,    16,    17,    18,    19,    20,    35,   178,    36,
      37,    38,    39,    40,     0,    41,     0,     0,     0,    42,
      27,    28,    29,    30,    31,    32,    33,    34,     0,    43,
      15,    16,    17,    18,    19,    20,    35,    44,    36,    37,
      38,    39,    40,     0,    41,     0,   205,     0,    42,    27,
      28,    29,    30,    31,    32,    33,    34,     0,    43,    15,
      16,    17,    18,    19,    20,    35,    44,    36,    37,    38,
      39,    40,     0,    41,     0,     0,     0,    42,    15,    16,
      17,    18,    19,    20,     0,     0,     0,    43,     0,     0,
       0,     0,     0,     0,     0,    44,    42,     0,     0,   114,
     115,    84,    85,    86,    87,    88,    89,   138,     0,    90,
      91,    92,    93,    94,    95,     0,    96,    97,     0,     0,
       0,     0,     0,     0,     0,   197,   142,   114,   115,    84,
      85,    86,    87,    88,    89,     0,     0,    90,    91,    92,
      93,    94,    95,     0,    96,    97,   146,   114,   115,    84,
      85,    86,    87,    88,    89,     0,     0,    90,    91,    92,
      93,    94,    95,     0,    96,    97,   174,   114,   115,    84,
      85,    86,    87,    88,    89,     0,     0,    90,    91,    92,
      93,    94,    95,     0,    96,    97,   194,   114,   115,    84,
      85,    86,    87,    88,    89,     0,     0,    90,    91,    92,
      93,    94,    95,     0,    96,    97,   114,   115,    84,    85,
      86,    87,    88,    89,     0,   116,    90,    91,    92,    93,
      94,    95,     0,    96,    97,   114,   115,    84,    85,    86,
      87,    88,    89,     0,   147,    90,    91,    92,    93,    94,
      95,     0,    96,    97,   114,   115,    84,    85,    86,    87,
      88,    89,     0,   148,    90,    91,    92,    93,    94,    95,
       0,    96,    97,   114,   115,    84,    85,    86,    87,    88,
      89,     0,   173,    90,    91,    92,    93,    94,    95,     0,
      96,    97,   114,   115,    84,    85,    86,    87,    88,    89,
       0,   188,    90,    91,    92,    93,    94,    95,     0,    96,
      97,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,    90,    91,    92,    93,    94,    95,     0,    96,    97,
     114,   115,    84,    85,    86,    87,    88,    89,     0,     0,
      90,    91,    92,    93,    94,    95,     0,    96,    97,   114,
     115,    84,    85,    86,    87,    88,    89,     0,     0,    90,
      91,    92,    93,    94,    95,     0,    96
};

static const yytype_int16 yycheck[] =
{
      43,    44,    19,   137,    13,    14,    15,    16,    17,    18,
      32,    19,    28,    42,    30,    58,    11,    12,    63,   153,
       0,   155,    31,    61,    67,    42,    32,   161,    57,    72,
      73,    74,    54,    42,    42,     6,    55,    41,    81,    41,
      19,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    41,    41,   102,   192,    41,
      41,   195,   196,   197,    41,    41,    19,     3,     4,     5,
       6,     7,     8,     9,    10,    19,     7,    13,    14,    15,
      16,    17,    18,    19,    19,    21,    22,    23,    24,    25,
      36,    27,    38,    39,    40,    31,    35,    36,    37,    38,
      39,    40,   145,   146,   149,    41,    13,    14,    15,    16,
      17,    18,    41,    49,     5,     6,     7,     8,     9,    10,
      56,    41,     6,    52,    31,    54,     6,    55,    19,    58,
      52,   174,    52,    32,    32,   178,    42,    55,    58,    53,
     183,     3,     4,     5,     6,     7,     8,     9,    10,    56,
      41,    13,    14,    15,    16,    17,    18,    19,    49,    21,
      22,    23,    24,    25,    57,    27,     7,    55,    55,    31,
      33,    34,    35,    36,    37,    38,    39,    40,    32,    41,
      43,    44,    45,    46,    47,    48,    60,    49,    32,    55,
      55,    19,    53,    32,    56,     3,     4,     5,     6,     7,
       8,     9,    10,    32,    42,    13,    14,    15,    16,    17,
      18,    19,    32,    21,    22,    23,    24,    25,    32,    27,
      26,    56,    59,    31,    55,    55,    35,    36,    37,    38,
      39,    40,    56,    41,    43,    44,    45,    46,    47,    48,
      32,    49,    64,    10,   149,   113,    -1,    -1,    56,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    13,
      14,    15,    16,    17,    18,    19,    -1,    21,    22,    23,
      24,    25,    -1,    27,    -1,    -1,    -1,    31,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    56,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,    13,    14,    15,    16,    17,    18,    19,
      -1,    21,    22,    23,    24,    25,    -1,    27,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    56,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    13,    14,    15,
      16,    17,    18,    19,    -1,    21,    22,    23,    24,    25,
      -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      56,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    27,    -1,    -1,    -1,    31,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    41,
      13,    14,    15,    16,    17,    18,    19,    49,    21,    22,
      23,    24,    25,    -1,    27,    -1,    29,    -1,    31,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    41,    13,
      14,    15,    16,    17,    18,    19,    49,    21,    22,    23,
      24,    25,    -1,    27,    -1,    -1,    -1,    31,    13,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    31,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    42,    -1,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    43,
      44,    45,    46,    47,    48,    -1,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    63,    64,     0,    65,    61,    66,    68,     6,    11,
      12,    67,    69,    32,    55,    13,    14,    15,    16,    17,
      18,    19,    70,    72,    76,    41,    19,     3,     4,     5,
       6,     7,     8,     9,    10,    19,    21,    22,    23,    24,
      25,    27,    31,    41,    49,    56,    72,    73,    74,    77,
      78,    79,    80,    81,    83,    85,    86,    88,    89,    92,
      93,    96,    97,    71,    41,    41,    52,    54,    58,    41,
      41,    41,    41,    41,    41,    19,    19,    85,    85,    19,
      32,    54,    33,    34,    35,    36,    37,    38,    39,    40,
      43,    44,    45,    46,    47,    48,    50,    51,    85,    90,
      42,    80,    71,    84,     7,    85,    19,     6,     6,    85,
      85,    85,    55,    41,    33,    34,    42,    52,    85,    32,
      32,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    42,    91,    55,    42,    19,
      42,    53,    32,    57,    42,    57,    32,    42,    42,    75,
      84,     7,    82,    55,    76,    55,    32,    60,    32,    85,
      85,    55,    55,    56,    79,    80,    42,    53,    32,    76,
      56,    76,    19,    42,    32,    76,    94,    56,    20,    42,
      32,    85,    56,    28,    30,    95,    85,    32,    42,    26,
      87,    85,    59,    56,    32,    55,    55,    59,    76,    56,
      76,    76,    76,    56,    56,    29,    32
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    64,    63,    65,    65,    66,    67,    68,    68,
      69,    70,    70,    71,    71,    72,    72,    72,    72,    72,
      72,    73,    74,    75,    75,    76,    76,    77,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    79,    80,    80,    80,    82,    81,    81,    83,    84,
      84,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    86,
      87,    87,    88,    89,    90,    91,    92,    93,    94,    94,
      95,    95,    96,    97,    97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     4,     0,     2,     3,     4,     0,     2,
       2,    11,     7,     0,     2,     1,     1,     1,     1,     1,
       1,     5,     5,     0,     2,     0,     2,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     2,     2,     1,     1,     0,     5,     4,     4,     0,
       2,     1,     1,     1,     1,     1,     1,     4,     3,     1,
       1,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     8,
       0,     4,     3,     2,     1,     4,    11,     8,     0,     7,
       0,     3,     8,     7,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  case 2: /* $@1: %empty  */
#line 87 "my_parser.y"
    {
        // initialisation des table des symboles et table des quadruplets 
        // et la pile de manipulation des quadruplets
        TS = createSymbolTable() ;  
        TQ = initialiserTQ() ;
        P = initialiserP();

    }
#line 1446 "my_parser.tab.c"
    break;

  case 3: /* Program: $@1 imports DeclarationFunctions DeclarationFunctionMain  */
#line 96 "my_parser.y"
                                                         {
        qC++;
        quad = creer_Q("fin", "", "", "", qC); // creer le quadruplet pour la fin 
        inserer_TQ(TQ, quad); 
        
        
        afficher(TS); // afficher TS pour confirmé 
        afficherTQ(TQ);  // afficher TQ pour confirmé 

        afficherTQDansFichier(TQ, "output.txt");

        printf("\nProgramme accepte.");
        }
#line 1464 "my_parser.tab.c"
    break;

  case 15: /* Type: TYPE_INT  */
#line 148 "my_parser.y"
             {(yyval.type) = 1;}
#line 1470 "my_parser.tab.c"
    break;

  case 16: /* Type: TYPE_FLT  */
#line 149 "my_parser.y"
               {(yyval.type) = 2;}
#line 1476 "my_parser.tab.c"
    break;

  case 17: /* Type: TYPE_STR  */
#line 150 "my_parser.y"
               {(yyval.type) = 4;}
#line 1482 "my_parser.tab.c"
    break;

  case 18: /* Type: TYPE_BLN  */
#line 151 "my_parser.y"
               {(yyval.type) = 5;}
#line 1488 "my_parser.tab.c"
    break;

  case 19: /* Type: TYPE_CAR  */
#line 152 "my_parser.y"
               {(yyval.type) = 3;}
#line 1494 "my_parser.tab.c"
    break;

  case 20: /* Type: TYPE_CONS  */
#line 153 "my_parser.y"
                {(yyval.type) = 0;}
#line 1500 "my_parser.tab.c"
    break;

  case 39: /* statement: expression INCREM FIN_INSTRUCTION  */
#line 190 "my_parser.y"
                                         {
        printf("test x++;\n");
        if( isIntOrfloat((yyvsp[-2].structure).type)){
             char bff[255]; 
            if(isInt((yyvsp[-2].structure).type)){
                int result = atoi((yyvsp[-2].structure).valeur) + 1 ;
                (yyval.structure).type = 1 ; 

                sprintf(bff, "%d", result);
                strcpy((yyval.structure).valeur,bff);
            }
            else {
                float result = atof((yyvsp[-2].structure).valeur) + 1 ;
                (yyval.structure).type = 2 ; 

                sprintf(bff, "%f", result);
                strcpy((yyval.structure).valeur,bff); 
            }

             qC++ ; //// increment qC

            if ((yyvsp[-2].structure).nom != NULL){ // 1 is id 
                node = symbolSearchNom(TS, (yyvsp[-2].structure).nom);
                if(node==NULL){
                    yyerrorSemantic("\nid non declare");
                }
                else { // 1 declared 
                    SetValueSymbol(node,bff); 
                   quad = creer_Q("++", (yyvsp[-2].structure).nom , "" , bff , qC);
                }
            } 
            else { // 1 is number 
                    quad = creer_Q("++", (yyvsp[-2].structure).valeur , "", bff , qC);
            } 

             // inserer quad 
            inserer_TQ(TQ,quad);


        }
    

    }
#line 1548 "my_parser.tab.c"
    break;

  case 40: /* statement: expression DECREM FIN_INSTRUCTION  */
#line 233 "my_parser.y"
                                         {
       
        if( isIntOrfloat((yyvsp[-2].structure).type)){
             char bff[255]; 
            if(isInt((yyvsp[-2].structure).type)){
                int result = atoi((yyvsp[-2].structure).valeur) - 1 ;
                (yyval.structure).type = 1 ; 

                sprintf(bff, "%d", result);
                strcpy((yyval.structure).valeur,bff);
            }
            else {
                float result = atof((yyvsp[-2].structure).valeur) - 1 ;
                (yyval.structure).type = 2 ; 

                sprintf(bff, "%f", result);
                strcpy((yyval.structure).valeur,bff); 
            }

             qC++ ; //// increment qC

            if ((yyvsp[-2].structure).nom != NULL){ // 1 is id 
                node = symbolSearchNom(TS, (yyvsp[-2].structure).nom);
                if(node==NULL){
                    yyerrorSemantic("\nid non declare");
                }
                else { // 1 declared 
                    SetValueSymbol(node,bff); 
                   quad = creer_Q("--", (yyvsp[-2].structure).nom , "" , bff , qC);
                }
            } 
            else { // 1 is number 
                    quad = creer_Q("--", (yyvsp[-2].structure).valeur , "", bff , qC);
            } 

             // inserer quad 
            inserer_TQ(TQ,quad);


        }
    

    }
#line 1596 "my_parser.tab.c"
    break;

  case 42: /* Parameter: Type ID  */
#line 283 "my_parser.y"
            {  
        node = createSymbol((yyvsp[0].str), (yyvsp[-1].type), NULL); // creer le Symbol de ID id et type Type 
        insertSymbol(TS, node); 
        char bff[255]; 
        strcpy(bff,(yyvsp[0].str));

        (yyval.structure).nom = strdup(bff); // passer à parameter le nom et le type 
        (yyval.structure).type = (yyvsp[-1].type);
    }
#line 1610 "my_parser.tab.c"
    break;

  case 45: /* $@2: %empty  */
#line 297 "my_parser.y"
                                     {
    
        if (node = symbolSearchNom(TS, (yyvsp[-2].structure).nom)){ 
           
            // test for constante first 
            if((yyvsp[-2].structure).type == 0){
                qC++;
                SetValueSymbol(node,(yyvsp[0].structure).valeur ); // màj valeur de node 
                quad = creer_Q(":=", (yyvsp[-2].structure).nom ," " , (yyvsp[0].structure).valeur, qC);
                inserer_TQ(TQ,quad);
            }
            // test if compatible types 
            else if((yyvsp[-2].structure).type == (yyvsp[0].structure).type){
                qC++;
                SetValueSymbol(node,(yyvsp[0].structure).valeur ); // màj valeur de node 
                quad = creer_Q(":=", (yyvsp[-2].structure).nom ," " , (yyvsp[0].structure).valeur, qC);
                inserer_TQ(TQ,quad);
            }
            else {
                yyerrorSemantic("\nType incompatible dans l'affectation. ");
               
            }
        }
        else{
            yyerrorSemantic("\nid non declare"); 
            //juste pour tester la partie de parameter 
            // on ne rentre jamais ici
        }

    }
#line 1645 "my_parser.tab.c"
    break;

  case 47: /* assignment: ID AFFECTATION expression FIN_INSTRUCTION  */
#line 327 "my_parser.y"
                                                {
        if (node = symbolSearchNom(TS, (yyvsp[-3].str))){ // is declared

            int type = node->type ;
        
            // test if compatible types 
            if(type == (yyvsp[-1].structure).type){
                qC++;
                SetValueSymbol(node,(yyvsp[-1].structure).valeur ); // màj valeur de node 
                quad = creer_Q(":=", (yyvsp[-3].str) ," " , (yyvsp[-1].structure).valeur, qC);
                inserer_TQ(TQ,quad);
            }
            else {
                 yyerrorSemantic("\nType incompatible dans l'affectation. ");
            }
        }else{
            yyerrorSemantic("\nid non declare");
        }

    }
#line 1670 "my_parser.tab.c"
    break;

  case 51: /* expression: ENTIER  */
#line 360 "my_parser.y"
           { 
        char bff[255]; 
        sprintf(bff, "%d", (yyvsp[0].intv)); 
        (yyval.structure).valeur = strdup(bff);
        (yyval.structure).type = 1;
    }
#line 1681 "my_parser.tab.c"
    break;

  case 52: /* expression: FLOTTANT  */
#line 366 "my_parser.y"
               {
        char bff[255]; 
        sprintf(bff, "%f", (yyvsp[0].flt)); 
        (yyval.structure).valeur = strdup(bff);
        (yyval.structure).type = 2;
    }
#line 1692 "my_parser.tab.c"
    break;

  case 53: /* expression: CHAR  */
#line 372 "my_parser.y"
           {
        (yyval.structure).valeur = strdup((yyvsp[0].str));
        (yyval.structure).type = 4;
    }
#line 1701 "my_parser.tab.c"
    break;

  case 54: /* expression: CARACTERE  */
#line 376 "my_parser.y"
                {
        char bff[255]; 
        sprintf(bff, "%c", (yyvsp[0].charv)); 
        (yyval.structure).valeur = strdup(bff);
        (yyval.structure).type = 3;
    }
#line 1712 "my_parser.tab.c"
    break;

  case 55: /* expression: BOOLEAN_VRAI  */
#line 382 "my_parser.y"
                   {
        (yyval.structure).valeur = strdup("vrai");
        (yyval.structure).type = 5;
    }
#line 1721 "my_parser.tab.c"
    break;

  case 56: /* expression: BOOLEAN_FAUX  */
#line 386 "my_parser.y"
                   {
        (yyval.structure).valeur = strdup("faux");
        (yyval.structure).type = 5;
    }
#line 1730 "my_parser.tab.c"
    break;

  case 59: /* expression: ID  */
#line 394 "my_parser.y"
         {
        (yyval.structure).nom = strdup((yyvsp[0].str));
        
        if (node = symbolSearchNom(TS, (yyvsp[0].str))){ // rechercher id dans TS
            (yyval.structure).valeur = strdup(node->value);
            (yyval.structure).type = node->type ;
        }else{
            yyerrorSemantic("\nid non declare");
        }
    }
#line 1745 "my_parser.tab.c"
    break;

  case 61: /* expression: expression PLUS expression  */
#line 407 "my_parser.y"
                                  { 
        
        if( isIntOrfloat((yyvsp[-2].structure).type) & isIntOrfloat((yyvsp[0].structure).type))  // addition de 2 nombres int or float 
        {
            char bff[255]; 
            if (isInt((yyvsp[-2].structure).type) & isInt((yyvsp[0].structure).type)){ // si les 2 sont des entiers ==> result entier
                int result = atoi((yyvsp[-2].structure).valeur) + atoi((yyvsp[0].structure).valeur);
                (yyval.structure).type = 1 ; // int

                sprintf(bff, "%d", result);
                strcpy((yyval.structure).valeur,bff);
            }
            else { // sinon ==> result float
                float result = atof((yyvsp[-2].structure).valeur) + atof((yyvsp[0].structure).valeur);
                (yyval.structure).type = 2 ; // float

                sprintf(bff, "%f", result);
                strcpy((yyval.structure).valeur,bff);
            }


            qC++ ; //// increment qC

            if ((yyvsp[-2].structure).nom != NULL){ // 1 is id 
                node = symbolSearchNom(TS, (yyvsp[-2].structure).nom);
                if(node==NULL){
                    yyerrorSemantic("\nid non declare");
                }
                else { // 1 declared 
                    if ((yyvsp[0].structure).nom != NULL){ 
                        node = symbolSearchNom(TS, (yyvsp[0].structure).nom);
                        if(node==NULL){
                             yyerrorSemantic("\nid non declare");
                        }
                        else { // both declared 
                            quad = creer_Q("+", (yyvsp[-2].structure).nom , (yyvsp[0].structure).nom , bff , qC);
                        }
                    }
                    else { // 2 is number 
                        quad = creer_Q("+", (yyvsp[-2].structure).nom , (yyvsp[0].structure).valeur , bff , qC);
                    }
                }
            }
            else { // 1 is number 
                if ((yyvsp[0].structure).nom != NULL){  // is id
                    node = symbolSearchNom(TS, (yyvsp[0].structure).nom);
                    if(node==NULL){
                         yyerrorSemantic("\nid non declare");
                    }
                    else { // 2 is declared

                        quad = creer_Q("+", (yyvsp[-2].structure).valeur , (yyvsp[0].structure).nom , bff , qC);
                    }
                }
                else { // 2 is number 
                        quad = creer_Q("+", (yyvsp[-2].structure).valeur , (yyvsp[0].structure).valeur , bff , qC);
                }        
            }

            // inserer quad 
            inserer_TQ(TQ,quad);

          
        }
    }
#line 1815 "my_parser.tab.c"
    break;

  case 62: /* expression: expression MOINS expression  */
#line 472 "my_parser.y"
                                  {
        if( isIntOrfloat((yyvsp[-2].structure).type) & isIntOrfloat((yyvsp[0].structure).type))  // soustraction de 2 nombres int or float 
        {
            char bff[255]; 
            if (isInt((yyvsp[-2].structure).type) & isInt((yyvsp[0].structure).type)){ // si les 2 sont des entiers ==> result entier
                int result = atoi((yyvsp[-2].structure).valeur) - atoi((yyvsp[0].structure).valeur);
                (yyval.structure).type = 1 ; // float

                sprintf(bff, "%d", result);
                strcpy((yyval.structure).valeur,bff);
            }
            else { // sinon ==> result float
                float result = atof((yyvsp[-2].structure).valeur) - atof((yyvsp[0].structure).valeur);
                (yyval.structure).type = 2 ; // float

                sprintf(bff, "%f", result);
                strcpy((yyval.structure).valeur,bff);
            }

            qC++ ; //// increment qC

            if ((yyvsp[-2].structure).nom != NULL){ // 1 is id 
                node = symbolSearchNom(TS, (yyvsp[-2].structure).nom);
                if(node==NULL){
                    yyerrorSemantic("\nid non declare");
                }
                else { // 1 declared 
                    if ((yyvsp[0].structure).nom != NULL){ 
                        node = symbolSearchNom(TS, (yyvsp[0].structure).nom);
                        if(node==NULL){
                            yyerrorSemantic("\nid non declare");
                        }
                        else { // both declared 
                            quad = creer_Q("-", (yyvsp[-2].structure).nom , (yyvsp[0].structure).nom , bff , qC);
                        }
                    }
                    else { // 2 is number 
                        quad = creer_Q("-", (yyvsp[-2].structure).nom , (yyvsp[0].structure).valeur , bff , qC);
                    }
                }
            }
            else { // 1 is number 
                if ((yyvsp[0].structure).nom != NULL){  // is id
                    node = symbolSearchNom(TS, (yyvsp[0].structure).nom);
                    if(node==NULL){
                        yyerrorSemantic("\nid non declare");
                    }
                    else { // 2 is declared

                        quad = creer_Q("-", (yyvsp[-2].structure).valeur , (yyvsp[0].structure).nom , bff , qC);
                    }
                }
                else { // 2 is number 
                        quad = creer_Q("-", (yyvsp[-2].structure).valeur , (yyvsp[0].structure).valeur , bff , qC);
                }        
            }

            // inserer quad 
            inserer_TQ(TQ,quad);
        }
    }
#line 1881 "my_parser.tab.c"
    break;

  case 63: /* expression: expression MUL expression  */
#line 533 "my_parser.y"
                                {
        if( isIntOrfloat((yyvsp[-2].structure).type) & isIntOrfloat((yyvsp[0].structure).type))  // multiplication de 2 nombres int or float 
        {
            char bff[255]; 
            if (isInt((yyvsp[-2].structure).type) & isInt((yyvsp[0].structure).type)){ // si les 2 sont des entiers ==> result entier
                int result = atoi((yyvsp[-2].structure).valeur) * atoi((yyvsp[0].structure).valeur);
                (yyval.structure).type = 1 ; // float

                sprintf(bff, "%d", result);
                strcpy((yyval.structure).valeur,bff);
            }
            else { // sinon ==> result float
                float result = atof((yyvsp[-2].structure).valeur) * atof((yyvsp[0].structure).valeur);
                (yyval.structure).type = 2 ; // float

                sprintf(bff, "%f", result);
                strcpy((yyval.structure).valeur,bff);
            }

            qC++ ; //// increment qC

            if ((yyvsp[-2].structure).nom != NULL){ // 1 is id 
                node = symbolSearchNom(TS, (yyvsp[-2].structure).nom);
                if(node==NULL){
                    yyerrorSemantic("\nid non declare");
                }
                else { // 1 declared 
                    if ((yyvsp[0].structure).nom != NULL){ 
                        node = symbolSearchNom(TS, (yyvsp[0].structure).nom);
                        if(node==NULL){
                            yyerrorSemantic("\nid non declare");
                        }
                        else { // both declared 
                            quad = creer_Q("*", (yyvsp[-2].structure).nom , (yyvsp[0].structure).nom , bff , qC);
                        }
                    }
                    else { // 2 is number 
                        quad = creer_Q("*", (yyvsp[-2].structure).nom , (yyvsp[0].structure).valeur , bff , qC);
                    }
                }
            }
            else { // 1 is number 
                if ((yyvsp[0].structure).nom != NULL){  // is id
                    node = symbolSearchNom(TS, (yyvsp[0].structure).nom);
                    if(node==NULL){
                        yyerrorSemantic("\nid non declare");
                    }
                    else { // 2 is declared

                        quad = creer_Q("*", (yyvsp[-2].structure).valeur , (yyvsp[0].structure).nom , bff , qC);
                    }
                }
                else { // 2 is number 
                        quad = creer_Q("*", (yyvsp[-2].structure).valeur , (yyvsp[0].structure).valeur , bff , qC);
                }        
            }

            // inserer quad 
            inserer_TQ(TQ,quad);
        }

    }
#line 1948 "my_parser.tab.c"
    break;

  case 64: /* expression: expression DIV expression  */
#line 595 "my_parser.y"
                                {
        
        if( isIntOrfloat((yyvsp[-2].structure).type) & isIntOrfloat((yyvsp[0].structure).type))  // division de 2 nombres int or float 
        {
            if ( atoi((yyvsp[0].structure).valeur) == 0 || atof((yyvsp[0].structure).valeur) == 0 ){
                yyerrorSemantic("\nDivision par Zero");
            }
            else {
            char bff[255]; 
            if (isInt((yyvsp[-2].structure).type) & isInt((yyvsp[0].structure).type)){ // si les 2 sont des entiers ==> result entier
                int result = atoi((yyvsp[-2].structure).valeur) / atoi((yyvsp[0].structure).valeur);
                (yyval.structure).type = 1 ; // float

                sprintf(bff, "%d", result);
                strcpy((yyval.structure).valeur,bff);
            }
            else { // sinon ==> result float
                float result = atof((yyvsp[-2].structure).valeur) / atof((yyvsp[0].structure).valeur);
                (yyval.structure).type = 2 ; // float

                sprintf(bff, "%f", result);
                strcpy((yyval.structure).valeur,bff);
            }

            qC++ ; //// increment qC

            if ((yyvsp[-2].structure).nom != NULL){ // 1 is id 
                node = symbolSearchNom(TS, (yyvsp[-2].structure).nom);
                if(node==NULL){
                    yyerrorSemantic("\nid non declare");
                }
                else { // 1 declared 
                    if ((yyvsp[0].structure).nom != NULL){ 
                        node = symbolSearchNom(TS, (yyvsp[0].structure).nom);
                        if(node==NULL){
                            yyerrorSemantic("\nid non declare");
                        }
                        else { // both declared 
                            quad = creer_Q("/", (yyvsp[-2].structure).nom , (yyvsp[0].structure).nom , bff , qC);
                        }
                    }
                    else { // 2 is number 
                        quad = creer_Q("/", (yyvsp[-2].structure).nom , (yyvsp[0].structure).valeur , bff , qC);
                    }
                }
            }
            else { // 1 is number 
                if ((yyvsp[0].structure).nom != NULL){  // is id
                    node = symbolSearchNom(TS, (yyvsp[0].structure).nom);
                    if(node==NULL){
                        yyerrorSemantic("\nid non declare");
                    }
                    else { // 2 is declared

                        quad = creer_Q("/", (yyvsp[-2].structure).valeur , (yyvsp[0].structure).nom , bff , qC);
                    }
                }
                else { // 2 is number 
                        quad = creer_Q("/", (yyvsp[-2].structure).valeur , (yyvsp[0].structure).valeur , bff , qC);
                }        
            }

            // inserer quad 
            inserer_TQ(TQ,quad);
            }
        }

    }
#line 2021 "my_parser.tab.c"
    break;

  case 65: /* expression: expression MOD expression  */
#line 663 "my_parser.y"
                                {
        if( isIntOrfloat((yyvsp[-2].structure).type) & isIntOrfloat((yyvsp[0].structure).type))  // division de 2 nombres int or float 
        {
            if ( atoi((yyvsp[0].structure).valeur) == 0 || atof((yyvsp[0].structure).valeur) == 0 ){
                yyerrorSemantic("\nModulo Zero");
            }
            else {
            char bff[255]; 
            if (isInt((yyvsp[-2].structure).type) & isInt((yyvsp[0].structure).type)){ // si les 2 sont des entiers ==> result entier
                int result = atoi((yyvsp[-2].structure).valeur) % atoi((yyvsp[0].structure).valeur);
                (yyval.structure).type = 1 ; // float

                sprintf(bff, "%d", result);
                strcpy((yyval.structure).valeur,bff);
            }
            else { // sinon ==> result float
                double result = fmod(atof((yyvsp[-2].structure).valeur), atof((yyvsp[0].structure).valeur));
                (yyval.structure).type = 2 ; // float

                sprintf(bff, "%f", result);
                strcpy((yyval.structure).valeur,bff);
            }

            qC++ ; //// increment qC

            if ((yyvsp[-2].structure).nom != NULL){ // 1 is id 
                node = symbolSearchNom(TS, (yyvsp[-2].structure).nom);
                if(node==NULL){
                    yyerrorSemantic("\nid non declare");
                }
                else { // 1 declared 
                    if ((yyvsp[0].structure).nom != NULL){ 
                        node = symbolSearchNom(TS, (yyvsp[0].structure).nom);
                        if(node==NULL){
                            yyerrorSemantic("\nid non declare");
                        }
                        else { // both declared 
                            quad = creer_Q("%", (yyvsp[-2].structure).nom , (yyvsp[0].structure).nom , bff , qC);
                        }
                    }
                    else { // 2 is number 
                        quad = creer_Q("%", (yyvsp[-2].structure).nom , (yyvsp[0].structure).valeur , bff , qC);
                    }
                }
            }
            else { // 1 is number 
                if ((yyvsp[0].structure).nom != NULL){  // is id
                    node = symbolSearchNom(TS, (yyvsp[0].structure).nom);
                    if(node==NULL){
                        yyerrorSemantic("\nid non declare");
                    }
                    else { // 2 is declared

                        quad = creer_Q("%", (yyvsp[-2].structure).valeur , (yyvsp[0].structure).nom , bff , qC);
                    }
                }
                else { // 2 is number 
                        quad = creer_Q("%", (yyvsp[-2].structure).valeur , (yyvsp[0].structure).valeur , bff , qC);
                }        
            }

            // inserer quad 
            inserer_TQ(TQ,quad);
            }
        }
    }
#line 2092 "my_parser.tab.c"
    break;

  case 67: /* expression: NEGATION expression  */
#line 730 "my_parser.y"
                            {
        if ((yyvsp[0].structure).type == 5) {  // Check if the expression is of boolean type
            char op[255];
            if ((yyvsp[0].structure).nom != NULL) {
                strcpy(op, (yyvsp[0].structure).nom);
            } else {
                strcpy(op, (yyvsp[0].structure).valeur);
            }

            char result[255];
            if (strcmp((yyvsp[0].structure).valeur,"vrai") == 0) {
                strcpy(result, "faux");
            } else {
                strcpy(result, "vrai");
            }

            // Update semantic values
            (yyval.structure).type = 5;  // boolean type
            (yyval.structure).valeur = strdup(result);
            qC++;
            // Insert the quadruplet
            quad = creer_Q("!", op, "", (yyval.structure).valeur, qC);
            inserer_TQ(TQ, quad);
        } else {
            printf("Erreur Semantique : Type incompatible\n");
            yyerrorSemantic("Error: Logical negation applied to non-boolean type");
        }
    }
#line 2125 "my_parser.tab.c"
    break;

  case 68: /* expression: expression INCREM  */
#line 759 "my_parser.y"
                         {
       
        if( isIntOrfloat((yyvsp[-1].structure).type)){
             char bff[255]; 
            if(isInt((yyvsp[-1].structure).type)){
                int result = atoi((yyvsp[-1].structure).valeur) + 1 ;
                (yyval.structure).type = 1 ; 

                sprintf(bff, "%d", result);
                strcpy((yyval.structure).valeur,bff);
            }
            else {
                float result = atof((yyvsp[-1].structure).valeur) + 1 ;
                (yyval.structure).type = 2 ; 

                sprintf(bff, "%f", result);
                strcpy((yyval.structure).valeur,bff); 
            }

             qC++ ; //// increment qC

            if ((yyvsp[-1].structure).nom != NULL){ // 1 is id 
                node = symbolSearchNom(TS, (yyvsp[-1].structure).nom);
                if(node==NULL){
                    yyerrorSemantic("\nid non declare");
                }
                else { // 1 declared 
                    SetValueSymbol(node,bff); 
                   quad = creer_Q("++", (yyvsp[-1].structure).nom , "" , bff , qC);
                }
            } 
            else { // 1 is number 
                    quad = creer_Q("++", (yyvsp[-1].structure).valeur , "", bff , qC);
            } 

             // inserer quad 
            inserer_TQ(TQ,quad);


        }
    

    }
#line 2173 "my_parser.tab.c"
    break;

  case 69: /* expression: expression DECREM  */
#line 802 "my_parser.y"
                        {
       
        if( isIntOrfloat((yyvsp[-1].structure).type)){
             char bff[255]; 
            if(isInt((yyvsp[-1].structure).type)){
                int result = atoi((yyvsp[-1].structure).valeur) - 1 ;
                (yyval.structure).type = 1 ; 

                sprintf(bff, "%d", result);
                strcpy((yyval.structure).valeur,bff);
            }
            else {
                float result = atof((yyvsp[-1].structure).valeur) - 1 ;
                (yyval.structure).type = 2 ; 

                sprintf(bff, "%f", result);
                strcpy((yyval.structure).valeur,bff); 
            }

             qC++ ; //// increment qC

            if ((yyvsp[-1].structure).nom != NULL){ // 1 is id 
                node = symbolSearchNom(TS, (yyvsp[-1].structure).nom);
                if(node==NULL){
                    yyerrorSemantic("\nid non declare");
                }
                else { // 1 declared 
                    SetValueSymbol(node,bff); 
                   quad = creer_Q("--", (yyvsp[-1].structure).nom , "" , bff , qC);
                }
            } 
            else { // 1 is number 
                    quad = creer_Q("--", (yyvsp[-1].structure).valeur , "", bff , qC);
            } 

             // inserer quad 
            inserer_TQ(TQ,quad);


        }
    

    }
#line 2221 "my_parser.tab.c"
    break;

  case 70: /* expression: PAR_OUV expression PAR_FERM  */
#line 846 "my_parser.y"
    {   (yyval.structure).nom = (yyvsp[-1].structure).nom;
        (yyval.structure).valeur = (yyvsp[-1].structure).valeur;
        (yyval.structure).type = (yyvsp[-1].structure).type;
    }
#line 2230 "my_parser.tab.c"
    break;

  case 71: /* expression: expression INF expression  */
#line 850 "my_parser.y"
                                {
            if(isIntOrfloat((yyvsp[-2].structure).type) && isIntOrfloat((yyvsp[0].structure).type)) {
                char op1[255];
                char op2[255];
                // si l'operand est un identifiant on le prend sinon on prend la valeur
                if((yyvsp[-2].structure).nom != NULL){strcpy(op1, (yyvsp[-2].structure).nom); } else {strcpy(op1, (yyvsp[-2].structure).valeur);}
                if((yyvsp[0].structure).nom != NULL){strcpy(op2, (yyvsp[0].structure).nom);} else {strcpy(op2, (yyvsp[0].structure).valeur);}

                float val1 = atof((yyvsp[-2].structure).valeur);
                float val2 = atof((yyvsp[0].structure).valeur);

                char result[255];
                if(val1 < val2) {
                    strcpy(result, "true");
                } else {
                    strcpy(result, "false");
                }

                (yyval.structure).type = 5;
               
                (yyval.structure).valeur = strdup(result);

                quad = creer_Q("<", op1, op2, (yyval.structure).valeur, qC++);
                inserer_TQ(TQ, quad);
               
                (yyval.structure).nom = NULL;
            }
            else{
                printf("Erreur Semantique : Type incompatible\n");
            }
    }
#line 2266 "my_parser.tab.c"
    break;

  case 72: /* expression: expression INF_EGAL expression  */
#line 881 "my_parser.y"
                                     {
            if(isIntOrfloat((yyvsp[-2].structure).type) && isIntOrfloat((yyvsp[0].structure).type)) {
                char op1[255];
                char op2[255];
                // si l'operand est un identifiant on le prend sinon on prend la valeur
                if((yyvsp[-2].structure).nom != NULL){strcpy(op1, (yyvsp[-2].structure).nom); } else {strcpy(op1, (yyvsp[-2].structure).valeur);}
                if((yyvsp[0].structure).nom != NULL){strcpy(op2, (yyvsp[0].structure).nom);} else {strcpy(op2, (yyvsp[0].structure).valeur);}

                float val1 = atof((yyvsp[-2].structure).valeur);
                float val2 = atof((yyvsp[0].structure).valeur);

                char result[255];
                if(val1 < val2) {
                    strcpy(result, "true");
                } else {
                    strcpy(result, "false");
                }

                (yyval.structure).type = 5;
               
                (yyval.structure).valeur = strdup(result);

                quad = creer_Q("<=", op1, op2, (yyval.structure).valeur, qC++);
                inserer_TQ(TQ, quad);
               
                (yyval.structure).nom = NULL;
            }
            else{
                printf("Erreur Semantique : Type incompatible\n");
            }
    }
#line 2302 "my_parser.tab.c"
    break;

  case 73: /* expression: expression SUPP expression  */
#line 912 "my_parser.y"
                                 {
            if(isIntOrfloat((yyvsp[-2].structure).type) && isIntOrfloat((yyvsp[0].structure).type)) {
                char op1[255];
                char op2[255];
                // si l'operand est un identifiant on le prend sinon on prend la valeur
                if((yyvsp[-2].structure).nom != NULL){strcpy(op1, (yyvsp[-2].structure).nom); } else {strcpy(op1, (yyvsp[-2].structure).valeur);}
                if((yyvsp[0].structure).nom != NULL){strcpy(op2, (yyvsp[0].structure).nom);} else {strcpy(op2, (yyvsp[0].structure).valeur);}

                float val1 = atof((yyvsp[-2].structure).valeur);
                float val2 = atof((yyvsp[0].structure).valeur);

                char result[255];
                if(val1 > val2) {
                    strcpy(result, "true");
                } else {
                    strcpy(result, "false");
                }

                (yyval.structure).type = 5;
               
                (yyval.structure).valeur = strdup(result);

                quad = creer_Q(">", op1, op2, (yyval.structure).valeur, qC++);
                inserer_TQ(TQ, quad);
               
                (yyval.structure).nom = NULL;
            }
            else{
                printf("Erreur Semantique : Type incompatible\n");
            }
    }
#line 2338 "my_parser.tab.c"
    break;

  case 74: /* expression: expression SUPP_EGAL expression  */
#line 943 "my_parser.y"
                                      {
            if(isIntOrfloat((yyvsp[-2].structure).type) && isIntOrfloat((yyvsp[0].structure).type)) {
                char op1[255];
                char op2[255];
                // si l'operand est un identifiant on le prend sinon on prend la valeur
                if((yyvsp[-2].structure).nom != NULL){strcpy(op1, (yyvsp[-2].structure).nom); } else {strcpy(op1, (yyvsp[-2].structure).valeur);}
                if((yyvsp[0].structure).nom != NULL){strcpy(op2, (yyvsp[0].structure).nom);} else {strcpy(op2, (yyvsp[0].structure).valeur);}

                float val1 = atof((yyvsp[-2].structure).valeur);
                float val2 = atof((yyvsp[0].structure).valeur);

                char result[255];
                if(val1 >= val2) {
                    strcpy(result, "true");
                } else {
                    strcpy(result, "false");
                }

                (yyval.structure).type = 5;
               
                (yyval.structure).valeur = strdup(result);

                quad = creer_Q(">=", op1, op2, (yyval.structure).valeur, qC++);
                inserer_TQ(TQ, quad);
               
                (yyval.structure).nom = NULL;
            }
            else{
                printf("Erreur Semantique : Type incompatible\n");
            }
    }
#line 2374 "my_parser.tab.c"
    break;

  case 75: /* expression: expression EGALE expression  */
#line 975 "my_parser.y"
                                  {
        if(isIntOrfloat((yyvsp[-2].structure).type) && isIntOrfloat((yyvsp[0].structure).type)){
            char op1[255];
            char op2[255]; 
            if((yyvsp[-2].structure).nom != NULL){ // id 
                node = symbolSearchNom(TS, (yyvsp[-2].structure).nom);
                if(node==NULL){
                    yyerrorSemantic("\nid non declare");
                }
                else {
                    strcpy(op1, (yyvsp[-2].structure).nom);
                }   
            }
            else {
                strcpy(op1, (yyvsp[-2].structure).valeur);
            }

            if((yyvsp[0].structure).nom != NULL){ // id 
                node = symbolSearchNom(TS, (yyvsp[0].structure).nom);
                if(node==NULL){
                    yyerrorSemantic("\nid non declare");
                }
                else {
                    strcpy(op2, (yyvsp[0].structure).nom);

                }   
            }
            else {
                strcpy(op2, (yyvsp[0].structure).valeur);

            }

            float val1 = atof((yyvsp[-2].structure).valeur);
            float val2 = atof((yyvsp[0].structure).valeur);

            char result[255];
            if(val1 == val2) {
                    strcpy(result, "true");
            }

       
 
            (yyval.structure).type = 5; // expression.type = bool
              
            (yyval.structure).valeur = strdup(result); // la valeur de la comparaison

            qC++;
            quad = creer_Q("==", op1, op2, (yyval.structure).valeur, qC);
            inserer_TQ(TQ, quad);
            
            (yyval.structure).nom = NULL;
            
        }

    }
#line 2434 "my_parser.tab.c"
    break;

  case 76: /* expression: expression PASEGALE expression  */
#line 1030 "my_parser.y"
                                     {
        if(isIntOrfloat((yyvsp[-2].structure).type) && isIntOrfloat((yyvsp[0].structure).type)){
            char op1[255];
            char op2[255];
            if((yyvsp[-2].structure).nom != NULL){ // id 
                    Symbol* symbole = symbolSearchNom(TS, (yyvsp[-2].structure).nom);
                    if(symbole==NULL){
                        printf("\n id %s not declared before !\n",(yyvsp[-2].structure).nom); yyerrorSemantic("error sem");
                    }
                    else {
                        strcpy(op1, (yyvsp[-2].structure).nom);
                        printf("nom1 = %s",op1) ; 
                    }   
                }
                else {
                    strcpy(op1, (yyvsp[-2].structure).valeur);
                    printf("valeur1 = %s",op1) ; 
                }

                if((yyvsp[0].structure).nom != NULL){ // id 
                    Symbol* symbole = symbolSearchNom(TS, (yyvsp[0].structure).nom);
                    if(symbole==NULL){
                        printf("\n id %s not declared before !\n",(yyvsp[0].structure).nom); yyerrorSemantic("error sem");
                    }
                    else {
                        strcpy(op2, (yyvsp[0].structure).nom);
                    
                    printf("nom2 = %s",op2) ; 
                    }   
                }
                else {
                    strcpy(op2, (yyvsp[0].structure).valeur);
                    printf("valeur = %s",op2) ; 
                }


            float val1 = atof((yyvsp[-2].structure).valeur);
            float val2 = atof((yyvsp[0].structure).valeur);

            char result[255];
             if(val1 != val2) {
                    //expression is true
                    strcpy(result, "true");
            } 

            (yyval.structure).type = 5;
            (yyval.structure).valeur = strdup(result);


            quad = creer_Q("!=", op1, op2, (yyval.structure).valeur, qC++);
            inserer_TQ(TQ, quad);
            
            (yyval.structure).nom = NULL;
        }
    }
#line 2494 "my_parser.tab.c"
    break;

  case 77: /* expression: expression ET expression  */
#line 1085 "my_parser.y"
                               {
    if ((yyvsp[-2].structure).type == 5 && (yyvsp[0].structure).type == 5) {
        char op1[255];
        char op2[255];
        
        // Gérer le premier opérande
        if ((yyvsp[-2].structure).nom != NULL) {
            Symbol* symbole = symbolSearchNom(TS, (yyvsp[-2].structure).nom);
            if (symbole == NULL) {
                printf("\n id %s not declared before !\n", (yyvsp[-2].structure).nom); 
                yyerrorSemantic("error sem");
            } else {
                strcpy(op1, (yyvsp[-2].structure).nom);
            }
        } else {
            strcpy(op1, (yyvsp[-2].structure).valeur);
        }

        // Gérer le deuxième opérande
        if ((yyvsp[0].structure).nom != NULL) {
            Symbol* symbole = symbolSearchNom(TS, (yyvsp[0].structure).nom);
            if (symbole == NULL) {
                printf("\n id %s not declared before !\n", (yyvsp[0].structure).nom);
                yyerrorSemantic("error sem");
            } else {
                strcpy(op2, (yyvsp[0].structure).nom);
            }
        } else {
            strcpy(op2, (yyvsp[0].structure).valeur);
        }

        char result[255];
        if (strcmp((yyvsp[-2].structure).valeur, "faux") == 0 || strcmp((yyvsp[0].structure).valeur, "faux") == 0) {
            strcpy(result, "faux");
        } else {
            strcpy(result, "vrai");
        }

        (yyval.structure).type = 5;
        (yyval.structure).valeur = strdup(result);

        quad = creer_Q("&&", op1, op2, (yyval.structure).valeur, qC++);
        inserer_TQ(TQ, quad);

        (yyval.structure).nom = NULL;
    } else {
        printf("Erreur Semantique : Type incompatible\n");
        yyerrorSemantic("Error: Logical AND applied to non-boolean type");
    }
}
#line 2549 "my_parser.tab.c"
    break;

  case 78: /* expression: expression OU expression  */
#line 1135 "my_parser.y"
                               {
    if ((yyvsp[-2].structure).type == 5 && (yyvsp[0].structure).type == 5) {
        char op1[255];
        char op2[255];
        
        // Gérer le premier opérande
        if ((yyvsp[-2].structure).nom != NULL) {
            Symbol* symbole = symbolSearchNom(TS, (yyvsp[-2].structure).nom);
            if (symbole == NULL) {
                printf("\n id %s not declared before !\n", (yyvsp[-2].structure).nom); 
                yyerrorSemantic("error sem");
            } else {
                strcpy(op1, (yyvsp[-2].structure).nom);
            }
        } else {
            strcpy(op1, (yyvsp[-2].structure).valeur);
        }

        // Gérer le deuxième opérande
        if ((yyvsp[0].structure).nom != NULL) {
            Symbol* symbole = symbolSearchNom(TS, (yyvsp[0].structure).nom);
            if (symbole == NULL) {
                printf("\n id %s not declared before !\n", (yyvsp[0].structure).nom);
                yyerrorSemantic("error sem");
            } else {
                strcpy(op2, (yyvsp[0].structure).nom);
            }
        } else {
            strcpy(op2, (yyvsp[0].structure).valeur);
        }

        char result[255];
        if (strcmp((yyvsp[-2].structure).valeur, "vrai") == 0 || strcmp((yyvsp[0].structure).valeur, "vrai") == 0) {
            strcpy(result, "vrai");
        } else {
            strcpy(result, "faux");
        }

        (yyval.structure).type = 5;
        (yyval.structure).valeur = strdup(result);
         qC++;
        quad = creer_Q("|", op1, op2, (yyval.structure).valeur, qC);
        inserer_TQ(TQ, quad);

    } else {
        printf("Erreur Semantique : Type incompatible\n");
    
    }
}
#line 2603 "my_parser.tab.c"
    break;

  case 83: /* while_part1: WHILE PAR_OUV  */
#line 1205 "my_parser.y"
         {
            // debut while 
            // Sauvegarde de l'@ deb, avant la condition
            sauvLabel = qC+1 ; 
         }
#line 2613 "my_parser.tab.c"
    break;

  case 84: /* while_part2: expression  */
#line 1215 "my_parser.y"
         {
            if((yyvsp[0].structure).type != 5) {
                yyerrorSemantic("\nCondition dans while de type non boolean");
            }

            // Apres l'evaluation de la cond, on fait un branchement si cond == faux vers fin 
            qC++ ; 
            quad = creer_Q("BZ", "finWhile", " ",(yyvsp[0].structure).valeur, qC);
            inserer_TQ(TQ, quad);
            push(P, quad);

         }
#line 2630 "my_parser.tab.c"
    break;

  case 85: /* while_part3: PAR_FERM DEB_CORPS statements FIN_CORPS  */
#line 1231 "my_parser.y"
         {
            // R3 

            qC++ ;  
            quad = pop(P);
            updateLabel(quad, qC+1); // MAJ l'@ defin "finWhile"

            // branchement vers l'@ du debut
            char etiq[255];
            itoa(sauvLabel, etiq, 10);
            quad = creer_Q("BR", etiq, "" , "", qC);
            inserer_TQ(TQ, quad);
    
        }
#line 2649 "my_parser.tab.c"
    break;


#line 2653 "my_parser.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1274 "my_parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
    exit(EXIT_FAILURE);
}

void yyerrorSemantic(char *s){
    printf("\nErreur semantique : %s",s);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    yyin = fopen("final_test.txt", "r");
    yyparse();
    fclose(yyin);
    return 0;
}
