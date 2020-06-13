/* Este archivo contiene un reconocedor de expresiones aritméticas junto
   con algunas reglas semánticas que calculan los valores de las
   expresiones que se reconocen. Las expresiones son muy sencillas y
   consisten únicamente de sumas, restas, multiplicaciones y divisiones de
   números enteros. 

   Autor: Alberto Oliart Ros */
  
%{
#include <stdlib.h>
#include <string.h>
#include<stdio.h>
extern int yylex();
int yyerror(char const * s);
#include "arbol.h"
struct node *tableRoot;
struct treeNode *treeRoot;
struct auxNode *treeAux;
int aux=0;
extern int numlinea;
%}

/* Los elementos terminales de la gramática. La declaración de abajo se
   convierte en definición de constantes en el archivo calculadora.tab.h
   que hay que incluir en el archivo de flex. */

%union
{
  int entero;
  float real;
  char* palabra;
  struct num* esNumero;
  struct treeNode* arbol;
}

%token PROGRAM OPENKEY CLOSEKEY PUNTOCOMA VAR DOSPUNTOS OPENPAR CLOSEPAR TO STEP DO
%token <palabra> SET READ PRINT IF IFELSE WHILE FOR SUMA RESTA DIV MULTI MODULO EXPONEN MENORQUE MAYORQUE IGUAL MAYORIGUAL MENORIGUAL ID
%token <entero> INT 
%token <entero> FLOAT
%token <entero> NUMI
%token <real> NUMF

%type <entero> tipo
%type <arbol> expr term factor expresion stmt assign_stmt if_stmt iter_stmt cmp_stmt stmt_lst

%start prog

%%

prog : PROGRAM ID OPENKEY opt_decls CLOSEKEY stmt {treeRoot=$6;}
;

opt_decls : decls                                 {}
          | %empty                                {}
;

decls : dec PUNTOCOMA opt_decls                   {}
      | dec                                       {}
;

dec   : VAR ID DOSPUNTOS tipo                     {if(!insertInTable(&tableRoot,$2,$4,0,0))
                                                    error(5,$2);
                                                  }
;

tipo  : INT {$$=$1;}
      | FLOAT {$$=$1;}
;

stmt  : assign_stmt {$$=$1;
                    }
      | if_stmt     {$$=$1;
                    }
      | iter_stmt   {$$=$1;
                    }
      | cmp_stmt    {$$=$1;
                    }
;

assign_stmt : SET ID expr PUNTOCOMA {fun_Valid_SET($2,$3,tableRoot);
                                     $$=newTreeNode($1, $2, 0, 0, 0, $3, NULL, NULL, NULL);
                                    }
            | READ ID PUNTOCOMA     {$$=newTreeNode($1, $2, 0, 0, 0, NULL, NULL, NULL, NULL);
                                    }
            | PRINT expr PUNTOCOMA  {$$=newTreeNode($1, NULL, 0, 0, 0, $2, NULL, NULL, NULL);
                                    }
;

if_stmt : IF OPENPAR expresion CLOSEPAR stmt {$$=newTreeNode($1, NULL, 0, 0, 0, $3, $5, NULL, NULL);//crear nodo if: type "if" branch1: expresion ($3) branch2: stmt ($5)
                                             }
        | IFELSE OPENPAR expresion CLOSEPAR stmt stmt {$$=newTreeNode($1, NULL, 0, 0, 0, $3, $5, $6, NULL);//crear nodo ifelse: type "ifelse" branch3: expresion ($3) branch2: stmt ($5) branch3: stmt ($6)
                                                      }
;

iter_stmt : WHILE OPENPAR expresion CLOSEPAR stmt {$$=newTreeNode($1, NULL, 0, 0, 0, $3, $5, NULL, NULL);//crear nodo while: type "while" branch1: expresion ($3) branch2: stmt ($5)
                                                  } 
          | FOR SET ID expr TO expr STEP expr DO stmt {$$=newTreeNode($1, $3, 0, 0, 0, $4, $6, $8, $10);//crear nodo if: type "for" branch1: ID ($3) branch2: expr ($4) branch3: expr ($6) branch4: expr ($8) branch5: stmt ($10)
                                                      }
;
cmp_stmt  : OPENKEY CLOSEKEY {$$=NULL;
                             }
          | OPENKEY stmt_lst CLOSEKEY {$$=treeAux->name;
                                       datbAux(&treeAux);
                                      }
;

stmt_lst  : stmt          {$$=$1;
                           iatbAux(&treeAux,$1);
                          }
          | stmt_lst stmt {($1->next)=$2;
                           $$=$2;
                          }
;

expr : expr SUMA term  {aux=fun_Valid_Dos($1,$3);
                        $$=newTreeNode($2, NULL, aux, 0, 0, $1, $3, NULL, NULL);
                       }
     | expr RESTA term {aux=fun_Valid_Dos($1,$3);
                        $$=newTreeNode($2, NULL, aux, 0, 0, $1, $3, NULL, NULL);
                       }
     | term            {$$=$1;}
;

term : term MULTI factor {aux=fun_Valid_Dos($1,$3);
                          $$=newTreeNode($2, NULL, aux, 0, 0, $1, $3, NULL, NULL);
                         }
     | term DIV factor   {aux=fun_Valid_Dos($1,$3);
                          $$=newTreeNode($2, NULL, aux, 0, 0, $1, $3, NULL, NULL);
                         }
     | factor            {$$=$1;}
;

factor : OPENPAR expr CLOSEPAR {$$=$2;}
       | ID                    {aux=fun_ID($1,tableRoot);
                                $$=newTreeNode(strdup("id"), $1, aux, 0, 0, NULL, NULL, NULL, NULL);}
       | NUMI                  {$$=newTreeNode(strdup("int"), NULL, 1, $1, 0, NULL, NULL, NULL, NULL);} 
       | NUMF                  {$$=newTreeNode(strdup("float"), NULL, 2, 0, $1, NULL, NULL, NULL, NULL);} 
;

expresion : expr MENORQUE expr    {fun_Valid_Dos($1,$3);
                                   $$=newTreeNode($2, NULL, 0, 0, 0, $1, $3, NULL, NULL);
                                  }
          | expr MAYORQUE expr    {fun_Valid_Dos($1,$3);
                                   $$=newTreeNode($2, NULL, 0, 0, 0, $1, $3, NULL, NULL);
                                  }
          | expr IGUAL expr       {fun_Valid_Dos($1,$3);
                                   $$=newTreeNode($2, NULL, 0, 0, 0, $1, $3, NULL, NULL);
                                  }
          | expr MENORIGUAL expr  {fun_Valid_Dos($1,$3);
                                   $$=newTreeNode($2, NULL, 0, 0, 0, $1, $3, NULL, NULL);
                                  }
          | expr MAYORIGUAL expr  {fun_Valid_Dos($1,$3);
                                   $$=newTreeNode($2, NULL, 0, 0, 0, $1, $3, NULL, NULL);
                                  }
;

%%

int yyerror(char const * s) {
  fprintf(stderr, "%s en linea %d\n", s, numlinea);
}

void main(int argc, char * argv[]){
  extern FILE * yyin;
  yyin = fopen (argv[1], "r");
  yyparse();
  printTree(treeRoot);
  runTree(treeRoot, tableRoot);
}

