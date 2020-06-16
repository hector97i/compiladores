/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_TAREA5_TAB_H_INCLUDED
# define YY_YY_TAREA5_TAB_H_INCLUDED
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
    PROGRAM = 258,
    FUN = 259,
    COMA = 260,
    OPENKEY = 261,
    CLOSEKEY = 262,
    PUNTOCOMA = 263,
    VAR = 264,
    DOSPUNTOS = 265,
    OPENPAR = 266,
    CLOSEPAR = 267,
    TO = 268,
    STEP = 269,
    DO = 270,
    SET = 271,
    READ = 272,
    PRINT = 273,
    IF = 274,
    IFELSE = 275,
    WHILE = 276,
    FOR = 277,
    SUMA = 278,
    RESTA = 279,
    DIV = 280,
    MULTI = 281,
    MODULO = 282,
    EXPONEN = 283,
    MENORQUE = 284,
    MAYORQUE = 285,
    IGUAL = 286,
    MAYORIGUAL = 287,
    MENORIGUAL = 288,
    ID = 289,
    RETURN = 290,
    INT = 291,
    FLOAT = 292,
    NUMI = 293,
    NUMF = 294
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "tarea5.y" /* yacc.c:1909  */

  int entero;
  float real;
  char* palabra;
  struct num* esNumero;
  struct treeNode* arbol;

#line 102 "tarea5.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TAREA5_TAB_H_INCLUDED  */
