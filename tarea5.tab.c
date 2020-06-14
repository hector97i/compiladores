/* A Bison parser, made by GNU Bison 3.6.3.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.6.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 5 "tarea5.y"

#include <stdlib.h>
#include <string.h>
#include<stdio.h>
extern int yylex();
int yyerror(char const * s);
#include "arbol.h"
struct node *tableRoot;
struct node *localRoot;
struct node *paramRoot;
struct treeNode *treeRoot;
struct auxNode *treeAux;
struct funNode *funTableRoot;
int aux=0;
int flag=0;
extern int numlinea;

#line 89 "tarea5.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_TAREA5_TAB_H_INCLUDED
# define YY_YY_TAREA5_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PROGRAM = 258,                 /* PROGRAM  */
    FUN = 259,                     /* FUN  */
    COMA = 260,                    /* COMA  */
    OPENKEY = 261,                 /* OPENKEY  */
    CLOSEKEY = 262,                /* CLOSEKEY  */
    PUNTOCOMA = 263,               /* PUNTOCOMA  */
    VAR = 264,                     /* VAR  */
    DOSPUNTOS = 265,               /* DOSPUNTOS  */
    OPENPAR = 266,                 /* OPENPAR  */
    CLOSEPAR = 267,                /* CLOSEPAR  */
    TO = 268,                      /* TO  */
    STEP = 269,                    /* STEP  */
    DO = 270,                      /* DO  */
    RETURN = 271,                  /* RETURN  */
    SET = 272,                     /* SET  */
    READ = 273,                    /* READ  */
    PRINT = 274,                   /* PRINT  */
    IF = 275,                      /* IF  */
    IFELSE = 276,                  /* IFELSE  */
    WHILE = 277,                   /* WHILE  */
    FOR = 278,                     /* FOR  */
    SUMA = 279,                    /* SUMA  */
    RESTA = 280,                   /* RESTA  */
    DIV = 281,                     /* DIV  */
    MULTI = 282,                   /* MULTI  */
    MODULO = 283,                  /* MODULO  */
    EXPONEN = 284,                 /* EXPONEN  */
    MENORQUE = 285,                /* MENORQUE  */
    MAYORQUE = 286,                /* MAYORQUE  */
    IGUAL = 287,                   /* IGUAL  */
    MAYORIGUAL = 288,              /* MAYORIGUAL  */
    MENORIGUAL = 289,              /* MENORIGUAL  */
    ID = 290,                      /* ID  */
    INT = 291,                     /* INT  */
    FLOAT = 292,                   /* FLOAT  */
    NUMI = 293,                    /* NUMI  */
    NUMF = 294                     /* NUMF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "tarea5.y"

  int entero;
  float real;
  char* palabra;
  struct num* esNumero;
  struct treeNode* arbol;

#line 186 "tarea5.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TAREA5_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROGRAM = 3,                    /* PROGRAM  */
  YYSYMBOL_FUN = 4,                        /* FUN  */
  YYSYMBOL_COMA = 5,                       /* COMA  */
  YYSYMBOL_OPENKEY = 6,                    /* OPENKEY  */
  YYSYMBOL_CLOSEKEY = 7,                   /* CLOSEKEY  */
  YYSYMBOL_PUNTOCOMA = 8,                  /* PUNTOCOMA  */
  YYSYMBOL_VAR = 9,                        /* VAR  */
  YYSYMBOL_DOSPUNTOS = 10,                 /* DOSPUNTOS  */
  YYSYMBOL_OPENPAR = 11,                   /* OPENPAR  */
  YYSYMBOL_CLOSEPAR = 12,                  /* CLOSEPAR  */
  YYSYMBOL_TO = 13,                        /* TO  */
  YYSYMBOL_STEP = 14,                      /* STEP  */
  YYSYMBOL_DO = 15,                        /* DO  */
  YYSYMBOL_RETURN = 16,                    /* RETURN  */
  YYSYMBOL_SET = 17,                       /* SET  */
  YYSYMBOL_READ = 18,                      /* READ  */
  YYSYMBOL_PRINT = 19,                     /* PRINT  */
  YYSYMBOL_IF = 20,                        /* IF  */
  YYSYMBOL_IFELSE = 21,                    /* IFELSE  */
  YYSYMBOL_WHILE = 22,                     /* WHILE  */
  YYSYMBOL_FOR = 23,                       /* FOR  */
  YYSYMBOL_SUMA = 24,                      /* SUMA  */
  YYSYMBOL_RESTA = 25,                     /* RESTA  */
  YYSYMBOL_DIV = 26,                       /* DIV  */
  YYSYMBOL_MULTI = 27,                     /* MULTI  */
  YYSYMBOL_MODULO = 28,                    /* MODULO  */
  YYSYMBOL_EXPONEN = 29,                   /* EXPONEN  */
  YYSYMBOL_MENORQUE = 30,                  /* MENORQUE  */
  YYSYMBOL_MAYORQUE = 31,                  /* MAYORQUE  */
  YYSYMBOL_IGUAL = 32,                     /* IGUAL  */
  YYSYMBOL_MAYORIGUAL = 33,                /* MAYORIGUAL  */
  YYSYMBOL_MENORIGUAL = 34,                /* MENORIGUAL  */
  YYSYMBOL_ID = 35,                        /* ID  */
  YYSYMBOL_INT = 36,                       /* INT  */
  YYSYMBOL_FLOAT = 37,                     /* FLOAT  */
  YYSYMBOL_NUMI = 38,                      /* NUMI  */
  YYSYMBOL_NUMF = 39,                      /* NUMF  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_prog = 41,                      /* prog  */
  YYSYMBOL_opt_decls = 42,                 /* opt_decls  */
  YYSYMBOL_decls = 43,                     /* decls  */
  YYSYMBOL_dec = 44,                       /* dec  */
  YYSYMBOL_tipo = 45,                      /* tipo  */
  YYSYMBOL_opt_fun_decls = 46,             /* opt_fun_decls  */
  YYSYMBOL_fun_decls = 47,                 /* fun_decls  */
  YYSYMBOL_fun_dec = 48,                   /* fun_dec  */
  YYSYMBOL_oparams = 49,                   /* oparams  */
  YYSYMBOL_params = 50,                    /* params  */
  YYSYMBOL_param = 51,                     /* param  */
  YYSYMBOL_stmt = 52,                      /* stmt  */
  YYSYMBOL_assign_stmt = 53,               /* assign_stmt  */
  YYSYMBOL_if_stmt = 54,                   /* if_stmt  */
  YYSYMBOL_iter_stmt = 55,                 /* iter_stmt  */
  YYSYMBOL_cmp_stmt = 56,                  /* cmp_stmt  */
  YYSYMBOL_stmt_lst = 57,                  /* stmt_lst  */
  YYSYMBOL_expr = 58,                      /* expr  */
  YYSYMBOL_term = 59,                      /* term  */
  YYSYMBOL_factor = 60,                    /* factor  */
  YYSYMBOL_opt_exprs = 61,                 /* opt_exprs  */
  YYSYMBOL_expr_lst = 62,                  /* expr_lst  */
  YYSYMBOL_expresion = 63                  /* expresion  */
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   137

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  125

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
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    46,    46,    49,    50,    53,    54,    57,    66,    67,
      70,    71,    74,    75,    78,    83,    90,    91,    94,    95,
      98,   103,   105,   107,   109,   113,   116,   118,   120,   124,
     126,   130,   132,   135,   137,   142,   145,   150,   153,   156,
     159,   162,   165,   168,   169,   171,   172,   173,   177,   178,
     181,   182,   185,   188,   191,   194,   197
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
  "\"end of file\"", "error", "\"invalid token\"", "PROGRAM", "FUN",
  "COMA", "OPENKEY", "CLOSEKEY", "PUNTOCOMA", "VAR", "DOSPUNTOS",
  "OPENPAR", "CLOSEPAR", "TO", "STEP", "DO", "RETURN", "SET", "READ",
  "PRINT", "IF", "IFELSE", "WHILE", "FOR", "SUMA", "RESTA", "DIV", "MULTI",
  "MODULO", "EXPONEN", "MENORQUE", "MAYORQUE", "IGUAL", "MAYORIGUAL",
  "MENORIGUAL", "ID", "INT", "FLOAT", "NUMI", "NUMF", "$accept", "prog",
  "opt_decls", "decls", "dec", "tipo", "opt_fun_decls", "fun_decls",
  "fun_dec", "oparams", "params", "param", "stmt", "assign_stmt",
  "if_stmt", "iter_stmt", "cmp_stmt", "stmt_lst", "expr", "term", "factor",
  "opt_exprs", "expr_lst", "expresion", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
#endif

#define YYPACT_NINF (-41)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       5,    21,    34,    52,   -41,    62,    37,    69,   -41,    70,
      71,    47,    91,    69,   -41,    62,   -32,    92,    95,   -41,
     -41,   -41,   -41,   -41,    93,    29,   -10,    72,    74,   -10,
      94,    97,   108,    89,   -41,   -41,   -41,   -41,   -41,    85,
     109,   -41,   117,   -41,   -41,    73,   -10,   112,   -41,   -41,
      -1,   -11,   -41,   -10,   116,     2,   -10,   -10,   -10,    90,
     118,   119,    93,   -41,   -41,    -6,   -10,   -41,   -10,   -10,
     -10,   -10,     6,   -41,   -41,    35,   114,   115,   120,   -10,
     -32,   -32,   -41,   -41,    14,   121,   -10,   -11,   -11,   -41,
     -41,   -41,   -10,   -10,   -10,   -10,   -10,    95,    95,    95,
       8,   -41,     3,   -41,    14,    14,    14,    14,    14,    14,
     -41,    95,   -41,   -10,    62,   -41,   -41,    39,   123,   -10,
      95,   -12,   -41,    95,   -41
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,    11,     3,     6,
       0,     0,     0,    10,    13,     4,     0,     0,     0,    12,
       5,     8,     9,     7,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,    21,    22,    23,    24,     0,
       0,    16,    19,    33,    35,     0,     0,    44,    45,    46,
       0,    39,    42,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,    36,     0,    49,    28,     0,     0,
       0,     0,     0,    26,    27,     0,     0,     0,     0,     0,
       0,     0,    18,    43,    51,     0,    48,    37,    38,    41,
      40,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,     0,    47,    50,    52,    53,    54,    56,    55,
      29,     0,    31,     0,     4,    15,    30,     0,     0,     0,
       0,     0,    14,     0,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -41,   -41,   -15,   -41,   -41,   -40,   -41,   -41,   122,   -41,
      75,   -41,   -23,   -41,   -41,   -41,   -41,   -41,    -9,   -26,
     -16,   -41,   -41,     4
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,     8,     9,    23,    12,    13,    14,    40,
      41,    42,    34,    35,    36,    37,    38,    45,    75,    51,
      52,    85,    86,    76
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      20,    46,    44,   123,    21,    22,    83,    67,     1,   114,
      74,   115,    68,    69,    91,    70,    71,    50,    68,    69,
      55,   113,    64,    68,    69,    47,    68,    69,    48,    49,
      68,    69,    68,    69,     4,    25,    43,    65,    68,    69,
     101,   102,    87,    88,    72,    26,    27,    28,    29,    30,
      31,    32,    33,   119,    89,    90,     3,    84,     5,    68,
      69,    77,    78,    68,    69,    92,    93,    94,    95,    96,
     100,     6,    10,    11,   110,   111,   112,   104,    15,    25,
      63,    16,    17,   105,   106,   107,   108,   109,   116,    26,
      27,    28,    29,    30,    31,    32,    33,   122,    18,   118,
     124,    25,    39,    24,   117,    56,    59,    53,    57,    54,
     121,    26,    27,    28,    29,    30,    31,    32,    33,    58,
      60,    61,    62,    66,    73,    79,    97,    98,    80,    81,
     120,     0,    99,   103,     0,    19,     0,    82
};

static const yytype_int8 yycheck[] =
{
      15,    11,    25,    15,    36,    37,    12,     8,     3,     6,
       8,     8,    24,    25,     8,    26,    27,    26,    24,    25,
      29,    13,    45,    24,    25,    35,    24,    25,    38,    39,
      24,    25,    24,    25,     0,     6,     7,    46,    24,    25,
      80,    81,    68,    69,    53,    16,    17,    18,    19,    20,
      21,    22,    23,    14,    70,    71,    35,    66,     6,    24,
      25,    57,    58,    24,    25,    30,    31,    32,    33,    34,
      79,     9,    35,     4,    97,    98,    99,    86,     8,     6,
       7,    10,    35,    92,    93,    94,    95,    96,   111,    16,
      17,    18,    19,    20,    21,    22,    23,   120,     7,   114,
     123,     6,     9,    11,   113,    11,    17,    35,    11,    35,
     119,    16,    17,    18,    19,    20,    21,    22,    23,    11,
      35,    12,     5,    11,     8,    35,    12,    12,    10,    10,
       7,    -1,    12,    12,    -1,    13,    -1,    62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    41,    35,     0,     6,     9,    42,    43,    44,
      35,     4,    46,    47,    48,     8,    10,    35,     7,    48,
      42,    36,    37,    45,    11,     6,    16,    17,    18,    19,
      20,    21,    22,    23,    52,    53,    54,    55,    56,     9,
      49,    50,    51,     7,    52,    57,    11,    35,    38,    39,
      58,    59,    60,    35,    35,    58,    11,    11,    11,    17,
      35,    12,     5,     7,    52,    58,    11,     8,    24,    25,
      26,    27,    58,     8,     8,    58,    63,    63,    63,    35,
      10,    10,    50,    12,    58,    61,    62,    59,    59,    60,
      60,     8,    30,    31,    32,    33,    34,    12,    12,    12,
      58,    45,    45,    12,    58,    58,    58,    58,    58,    58,
      52,    52,    52,    13,     6,     8,    52,    58,    42,    14,
       7,    58,    52,    15,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    44,    45,    45,
      46,    46,    47,    47,    48,    48,    49,    49,    50,    50,
      51,    52,    52,    52,    52,    53,    53,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    57,    58,    58,    58,
      59,    59,    59,    60,    60,    60,    60,    60,    61,    61,
      62,    62,    63,    63,    63,    63,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     1,     0,     3,     1,     4,     1,     1,
       1,     0,     2,     1,    11,     8,     1,     0,     3,     1,
       4,     1,     1,     1,     1,     4,     3,     3,     3,     5,
       6,     5,    10,     2,     3,     1,     2,     3,     3,     1,
       3,     3,     1,     3,     1,     1,     1,     4,     1,     0,
       2,     1,     3,     3,     3,     3,     3
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

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yystacksize = YYINITDEPTH;
  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;


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
  case 2:
#line 46 "tarea5.y"
                                                                {treeRoot=(yyvsp[0].arbol);}
#line 1315 "tarea5.tab.c"
    break;

  case 3:
#line 49 "tarea5.y"
                                                  {flag=1;}
#line 1321 "tarea5.tab.c"
    break;

  case 4:
#line 50 "tarea5.y"
                                                  {}
#line 1327 "tarea5.tab.c"
    break;

  case 5:
#line 53 "tarea5.y"
                                                  {}
#line 1333 "tarea5.tab.c"
    break;

  case 6:
#line 54 "tarea5.y"
                                                  {}
#line 1339 "tarea5.tab.c"
    break;

  case 7:
#line 57 "tarea5.y"
                                                  { if(!flag){
                                                     if(!insertInTable(&tableRoot,(yyvsp[-2].palabra),(yyvsp[0].entero),0,0))
                                                      error(5,(yyvsp[-2].palabra));
                                                    }
                                                    if(!insertInTable(&localRoot,(yyvsp[-2].palabra),(yyvsp[0].entero),0,0))
                                                      error(5,(yyvsp[-2].palabra));
                                                  }
#line 1351 "tarea5.tab.c"
    break;

  case 8:
#line 66 "tarea5.y"
            {(yyval.entero)=(yyvsp[0].entero);}
#line 1357 "tarea5.tab.c"
    break;

  case 9:
#line 67 "tarea5.y"
              {(yyval.entero)=(yyvsp[0].entero);}
#line 1363 "tarea5.tab.c"
    break;

  case 14:
#line 78 "tarea5.y"
                                                                                         {if(!insertInFunTable(&funTableRoot,(yyvsp[-9].palabra),localRoot,paramRoot,(yyvsp[0].arbol),(yyvsp[-4].entero)))
                                                                                            error(6,(yyvsp[-9].palabra));
                                                                                          localRoot=NULL;
                                                                                          paramRoot=NULL;
                                                                                         }
#line 1373 "tarea5.tab.c"
    break;

  case 15:
#line 83 "tarea5.y"
                                                                                         {if(!insertInFunTable(&funTableRoot,(yyvsp[-6].palabra),NULL,paramRoot,NULL,(yyvsp[-1].entero)))
                                                                                            error(6,(yyvsp[-6].palabra));
                                                                                          localRoot=NULL;
                                                                                          paramRoot=NULL;
                                                                                         }
#line 1383 "tarea5.tab.c"
    break;

  case 20:
#line 98 "tarea5.y"
                              {if(!insertInTable(&paramRoot,(yyvsp[-2].palabra),(yyvsp[0].entero),0,0))
                                error(5,(yyvsp[-2].palabra));
                              }
#line 1391 "tarea5.tab.c"
    break;

  case 21:
#line 103 "tarea5.y"
                    {(yyval.arbol)=(yyvsp[0].arbol);
                    }
#line 1398 "tarea5.tab.c"
    break;

  case 22:
#line 105 "tarea5.y"
                    {(yyval.arbol)=(yyvsp[0].arbol);
                    }
#line 1405 "tarea5.tab.c"
    break;

  case 23:
#line 107 "tarea5.y"
                    {(yyval.arbol)=(yyvsp[0].arbol);
                    }
#line 1412 "tarea5.tab.c"
    break;

  case 24:
#line 109 "tarea5.y"
                    {(yyval.arbol)=(yyvsp[0].arbol);
                    }
#line 1419 "tarea5.tab.c"
    break;

  case 25:
#line 113 "tarea5.y"
                                    {fun_Valid_SET((yyvsp[-2].palabra),(yyvsp[-1].arbol),tableRoot);
                                     (yyval.arbol)=newTreeNode((yyvsp[-3].palabra), (yyvsp[-2].palabra), 0, 0, 0, (yyvsp[-1].arbol), NULL, NULL, NULL);
                                    }
#line 1427 "tarea5.tab.c"
    break;

  case 26:
#line 116 "tarea5.y"
                                    {(yyval.arbol)=newTreeNode((yyvsp[-2].palabra), (yyvsp[-1].palabra), 0, 0, 0, NULL, NULL, NULL, NULL);
                                    }
#line 1434 "tarea5.tab.c"
    break;

  case 27:
#line 118 "tarea5.y"
                                    {(yyval.arbol)=newTreeNode((yyvsp[-2].palabra), NULL, 0, 0, 0, (yyvsp[-1].arbol), NULL, NULL, NULL);
                                    }
#line 1441 "tarea5.tab.c"
    break;

  case 28:
#line 120 "tarea5.y"
                                     {//ver que onda
                                    }
#line 1448 "tarea5.tab.c"
    break;

  case 29:
#line 124 "tarea5.y"
                                             {(yyval.arbol)=newTreeNode((yyvsp[-4].palabra), NULL, 0, 0, 0, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL);//crear nodo if: type "if" branch1: expresion ($3) branch2: stmt ($5)
                                             }
#line 1455 "tarea5.tab.c"
    break;

  case 30:
#line 126 "tarea5.y"
                                                      {(yyval.arbol)=newTreeNode((yyvsp[-5].palabra), NULL, 0, 0, 0, (yyvsp[-3].arbol), (yyvsp[-1].arbol), (yyvsp[0].arbol), NULL);//crear nodo ifelse: type "ifelse" branch3: expresion ($3) branch2: stmt ($5) branch3: stmt ($6)
                                                      }
#line 1462 "tarea5.tab.c"
    break;

  case 31:
#line 130 "tarea5.y"
                                                  {(yyval.arbol)=newTreeNode((yyvsp[-4].palabra), NULL, 0, 0, 0, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL);//crear nodo while: type "while" branch1: expresion ($3) branch2: stmt ($5)
                                                  }
#line 1469 "tarea5.tab.c"
    break;

  case 32:
#line 132 "tarea5.y"
                                                      {(yyval.arbol)=newTreeNode((yyvsp[-9].palabra), (yyvsp[-7].palabra), 0, 0, 0, (yyvsp[-6].arbol), (yyvsp[-4].arbol), (yyvsp[-2].arbol), (yyvsp[0].arbol));//crear nodo if: type "for" branch1: ID ($3) branch2: expr ($4) branch3: expr ($6) branch4: expr ($8) branch5: stmt ($10)
                                                      }
#line 1476 "tarea5.tab.c"
    break;

  case 33:
#line 135 "tarea5.y"
                             {(yyval.arbol)=NULL;
                             }
#line 1483 "tarea5.tab.c"
    break;

  case 34:
#line 137 "tarea5.y"
                                      {(yyval.arbol)=treeAux->name;
                                       datbAux(&treeAux);
                                      }
#line 1491 "tarea5.tab.c"
    break;

  case 35:
#line 142 "tarea5.y"
                          {(yyval.arbol)=(yyvsp[0].arbol);
                           iatbAux(&treeAux,(yyvsp[0].arbol));
                          }
#line 1499 "tarea5.tab.c"
    break;

  case 36:
#line 145 "tarea5.y"
                          {((yyvsp[-1].arbol)->next)=(yyvsp[0].arbol);
                           (yyval.arbol)=(yyvsp[0].arbol);
                          }
#line 1507 "tarea5.tab.c"
    break;

  case 37:
#line 150 "tarea5.y"
                       {aux=fun_Valid_Dos((yyvsp[-2].arbol),(yyvsp[0].arbol));
                        (yyval.arbol)=newTreeNode((yyvsp[-1].palabra), NULL, aux, 0, 0, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL);
                       }
#line 1515 "tarea5.tab.c"
    break;

  case 38:
#line 153 "tarea5.y"
                       {aux=fun_Valid_Dos((yyvsp[-2].arbol),(yyvsp[0].arbol));
                        (yyval.arbol)=newTreeNode((yyvsp[-1].palabra), NULL, aux, 0, 0, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL);
                       }
#line 1523 "tarea5.tab.c"
    break;

  case 39:
#line 156 "tarea5.y"
                       {(yyval.arbol)=(yyvsp[0].arbol);}
#line 1529 "tarea5.tab.c"
    break;

  case 40:
#line 159 "tarea5.y"
                         {aux=fun_Valid_Dos((yyvsp[-2].arbol),(yyvsp[0].arbol));
                          (yyval.arbol)=newTreeNode((yyvsp[-1].palabra), NULL, aux, 0, 0, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL);
                         }
#line 1537 "tarea5.tab.c"
    break;

  case 41:
#line 162 "tarea5.y"
                         {aux=fun_Valid_Dos((yyvsp[-2].arbol),(yyvsp[0].arbol));
                          (yyval.arbol)=newTreeNode((yyvsp[-1].palabra), NULL, aux, 0, 0, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL);
                         }
#line 1545 "tarea5.tab.c"
    break;

  case 42:
#line 165 "tarea5.y"
                         {(yyval.arbol)=(yyvsp[0].arbol);}
#line 1551 "tarea5.tab.c"
    break;

  case 43:
#line 168 "tarea5.y"
                               {(yyval.arbol)=(yyvsp[-1].arbol);}
#line 1557 "tarea5.tab.c"
    break;

  case 44:
#line 169 "tarea5.y"
                               {aux=fun_ID((yyvsp[0].palabra),tableRoot);
                                (yyval.arbol)=newTreeNode(strdup("id"), (yyvsp[0].palabra), aux, 0, 0, NULL, NULL, NULL, NULL);}
#line 1564 "tarea5.tab.c"
    break;

  case 45:
#line 171 "tarea5.y"
                               {(yyval.arbol)=newTreeNode(strdup("int"), NULL, 1, (yyvsp[0].entero), 0, NULL, NULL, NULL, NULL);}
#line 1570 "tarea5.tab.c"
    break;

  case 46:
#line 172 "tarea5.y"
                               {(yyval.arbol)=newTreeNode(strdup("float"), NULL, 2, 0, (yyvsp[0].real), NULL, NULL, NULL, NULL);}
#line 1576 "tarea5.tab.c"
    break;

  case 47:
#line 173 "tarea5.y"
                                       {(yyval.arbol)=newTreeNode(strdup("fun"), NULL, 2, 0, 0, (yyvsp[-3].palabra), NULL, NULL, NULL);//se agrega al arbol un nodo qe representa a una funcion
                                       }
#line 1583 "tarea5.tab.c"
    break;

  case 52:
#line 185 "tarea5.y"
                                  {fun_Valid_Dos((yyvsp[-2].arbol),(yyvsp[0].arbol));
                                   (yyval.arbol)=newTreeNode((yyvsp[-1].palabra), NULL, 0, 0, 0, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL);
                                  }
#line 1591 "tarea5.tab.c"
    break;

  case 53:
#line 188 "tarea5.y"
                                  {fun_Valid_Dos((yyvsp[-2].arbol),(yyvsp[0].arbol));
                                   (yyval.arbol)=newTreeNode((yyvsp[-1].palabra), NULL, 0, 0, 0, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL);
                                  }
#line 1599 "tarea5.tab.c"
    break;

  case 54:
#line 191 "tarea5.y"
                                  {fun_Valid_Dos((yyvsp[-2].arbol),(yyvsp[0].arbol));
                                   (yyval.arbol)=newTreeNode((yyvsp[-1].palabra), NULL, 0, 0, 0, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL);
                                  }
#line 1607 "tarea5.tab.c"
    break;

  case 55:
#line 194 "tarea5.y"
                                  {fun_Valid_Dos((yyvsp[-2].arbol),(yyvsp[0].arbol));
                                   (yyval.arbol)=newTreeNode((yyvsp[-1].palabra), NULL, 0, 0, 0, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL);
                                  }
#line 1615 "tarea5.tab.c"
    break;

  case 56:
#line 197 "tarea5.y"
                                  {fun_Valid_Dos((yyvsp[-2].arbol),(yyvsp[0].arbol));
                                   (yyval.arbol)=newTreeNode((yyvsp[-1].palabra), NULL, 0, 0, 0, (yyvsp[-2].arbol), (yyvsp[0].arbol), NULL, NULL);
                                  }
#line 1623 "tarea5.tab.c"
    break;


#line 1627 "tarea5.tab.c"

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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 202 "tarea5.y"


int yyerror(char const * s) {
  fprintf(stderr, "%s en linea %d\n", s, numlinea);
}

void main(int argc, char * argv[]){
  extern FILE * yyin;
  yyin = fopen (argv[1], "r");
  yyparse();
  //runTree(treeRoot, tableRoot);
}

