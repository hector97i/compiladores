//Autores: Carlos Ignacio Villalobos Sánchez A01731558
//
//

%{
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
struct funNode * funSearchTmp;
extern int numlinea;
%}

%union
{
  int entero;
  float real;
  char* palabra;
  struct num* esNumero;
  struct treeNode* arbol;
}

%token PROGRAM FUN COMA OPENKEY CLOSEKEY PUNTOCOMA VAR DOSPUNTOS OPENPAR CLOSEPAR TO STEP DO RETURN
%token <palabra> SET READ PRINT IF IFELSE WHILE FOR SUMA RESTA DIV MULTI MODULO EXPONEN MENORQUE MAYORQUE IGUAL MAYORIGUAL MENORIGUAL ID
%token <entero> INT 
%token <entero> FLOAT
%token <entero> NUMI
%token <real> NUMF

%type <entero> tipo
%type <arbol> expr term factor expresion stmt assign_stmt if_stmt iter_stmt cmp_stmt stmt_lst opt_exprs expr_lst

%start prog

%%

prog : PROGRAM ID OPENKEY opt_decls opt_fun_decls CLOSEKEY stmt {treeRoot=$7;}
;

opt_decls : decls                                 {flag=1;}
          | %empty                                {}
;

decls : dec PUNTOCOMA decls                   {}
      | dec                                       {}
;

dec   : VAR ID DOSPUNTOS tipo                     { if(!flag){
                                                     if(!insertInTable(&tableRoot,$2,$4,0,0))
                                                      error(5,$2);
                                                    }
                                                    if(!insertInTable(&localRoot,$2,$4,0,0))
                                                      error(5,$2);
                                                  }
;

tipo  : INT {$$=$1;}
      | FLOAT {$$=$1;}
;

opt_fun_decls : fun_decls                        
              | %empty
;

fun_decls : fun_decls fun_dec
          | fun_dec
;

fun_dec : FUN ID OPENPAR oparams CLOSEPAR DOSPUNTOS tipo OPENKEY opt_decls CLOSEKEY stmt {if(!insertInFunTable(&funTableRoot,$2,localRoot,paramRoot,$11,$7))
                                                                                            error(6,$2);
                                                                                          localRoot=NULL;
                                                                                          paramRoot=NULL;
                                                                                         }
        | FUN ID OPENPAR oparams CLOSEPAR DOSPUNTOS tipo PUNTOCOMA                       {if(!insertInFunTable(&funTableRoot,$2,NULL,paramRoot,NULL,$7))
                                                                                            error(6,$2);
                                                                                          localRoot=NULL;
                                                                                          paramRoot=NULL;
                                                                                         }
;

oparams : params              
        | %empty
;

params : param COMA params 
       | param              
;

param : VAR ID DOSPUNTOS tipo {if(!insertInTable(&paramRoot,$2,$4,0,0))
                                error(5,$2);
                              }
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
            | RETURN expr PUNTOCOMA  {//ver que onda
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
       | ID OPENPAR opt_exprs CLOSEPAR {funSearchTmp = searchFun(funTableRoot, $1); //Buscar si la funcion ya está en la tabla
                                        if(funSearchTmp == NULL){   //Si no está, error.
                                          error(7, $1);
                                        }else{    //Si está, checar que los tipos de parámetro coincidan.
                                          $$=newTreeNode($1, NULL, 2, 0, 0, $3, NULL, NULL, NULL);//Si los tipos coinciden, se agrega 
                                          if(funcParamCheck(funTableRoot, funSearchTmp) == 0){
                                          }else{                                                      //al arbol un nodo de funcion apuntando a sus parametros
                                            error(8, $1);         //Si los tipos entre la llamada y la declaracion no coinciden, error.
                                          }
                                            
                                        }
                                       }
;

opt_exprs : expr_lst  
          | %empty    
;

expr_lst : expr_lst expr    
         | expr             
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
  return 1;
}

void main(int argc, char * argv[]){
  extern FILE * yyin;
  yyin = fopen (argv[1], "r");
  yyparse();
  //runTree(treeRoot, tableRoot);
}

