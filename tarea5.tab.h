/* A Bison parser, made by GNU Bison 3.6.3.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
#line 25 "tarea5.y"

  int entero;
  float real;
  char* palabra;
  struct num* esNumero;
  struct treeNode* arbol;

#line 111 "tarea5.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TAREA5_TAB_H_INCLUDED  */
