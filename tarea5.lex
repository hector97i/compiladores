/* Archivo con el reconocedor léxico */
%{
#include<stdlib.h>
#include<math.h>
  /* Se incluye el archivo generado por bison para tener las definiciones
     de los tokens */
#include "tarea5.tab.h"
int numlinea=0;
%}

LETRA [A-Za-z]
DIGITO [0-9]

%%

"program" {return PROGRAM; /* Simbolo de program */}
";"	  	  {return PUNTOCOMA; /* Simbolo de punto y coma */}
"fun" 	  {return FUN; /* Simbolo de funcion */}
","	  	  {return COMA; /* Simbolo de coma */}
"var"	  {return VAR; /* Simbolo de variable */}
":"		  {return DOSPUNTOS; /* Simbolo de dos puntos */}
"int"	  {yylval.entero=1; return INT; /* Simbolo de int */}
"float"	  {yylval.entero=2; return FLOAT; /* Simbolo de float */}
"read"	  {yylval.palabra = strdup(yytext); return READ; /* Simbolo de read */}
"print"	  {yylval.palabra = strdup(yytext); return PRINT; /* Simbolo de print */}
"ifelse"  {yylval.palabra = strdup(yytext); return IFELSE; /* Simbolo de ifelse */}
"if"	  {yylval.palabra = strdup(yytext); return IF; /* Simbolo de if */}
"while"	  {yylval.palabra = strdup(yytext); return WHILE; /* Simbolo de while */}
"for"	  {yylval.palabra = strdup(yytext); return FOR; /* Simbolo de for */}
"set"	  {yylval.palabra = strdup(yytext); return SET; /* Simbolo de set */}
"to"	  {return TO; /* Simbolo de to */}
"step"	  {return STEP; /* Simbolo de step */}
"do"	  {return DO; /* Simbolo de do */}
"return"  {yylval.palabra = strdup(yytext); return RETURN; /*Simbolo de return*/}

"("       {return OPENPAR; /* Simbolo de parentesis que abre */}
")"       {return CLOSEPAR; /* Simbolo de parentesis que cierra */}
"{"	  	  {return OPENKEY; /* Simbolo de llave que abre */}
"}"	  	  {return CLOSEKEY; /* Simbolo de llave que cierra */}
"<"       {yylval.palabra = strdup(yytext); return MENORQUE; /* Simbolo de menor-que */}
">"       {yylval.palabra = strdup(yytext); return MAYORQUE; /* Simbolo de mayor-que */}
"="       {yylval.palabra = strdup(yytext); return IGUAL; /* Simbolo de igual */}
"<="      {yylval.palabra = strdup(yytext); return MENORIGUAL; /* Simbolo de menor-igual */}
">="      {yylval.palabra = strdup(yytext); return MAYORIGUAL; /* Simbolo de mayor-igual */}
"+"       {yylval.palabra = strdup(yytext); return SUMA; /* Simbolo de suma */}
"-"       {yylval.palabra = strdup(yytext); return RESTA;/* Simbolo de resta */}
"*"       {yylval.palabra = strdup(yytext); return MULTI;/* Se encontrÃ³ un sÃ­mbolo de multiplicaciÃ³n */}
"/"       {yylval.palabra = strdup(yytext); return DIV;/* Se encontrÃ³ un sÃ­mbolo de divisiÃ³n */}
"%"       {yylval.palabra = strdup(yytext); return MODULO;/* Se encontrÃ³ un sÃ­mbolo de modulo */}
"^"       {yylval.palabra = strdup(yytext); return EXPONEN;/* Se encontrÃ³ un sÃ­mbolo de exponenciacion */}

{DIGITO}*"."{DIGITO}*|"-"{DIGITO}*"."{DIGITO}* {yylval.real = atof(yytext); return NUMF; /* Convierte el NUM a nÃºmero flotante */}

{DIGITO}*|"-"{DIGITO}* {yylval.entero = atoi(yytext); return NUMI; /* Convierte el NUM a nÃºmero entero*/}

("a"|"b"|"c"|"d"|"e"|"f"|"g"|"h"|"i"|"j"|"k"|"l"|"m"|"n"|"o"|"p"|"r"|"s"|"t"|"u"|"v"|"w"|"x"|"y"|"z"|"_")("a"|"b"|"c"|"d"|"e"|"f"|"g"|"h"|"i"|"j"|"k"|"l"|"m"|"n"|"o"|"p"|"r"|"s"|"t"|"u"|"v"|"w"|"x"|"y"|"z"|"_"|0|1|2|3|4|5|6|7|8|9)* {yylval.palabra = strdup(yytext); return ID; /* Simbolo de id */}

"\n" {numlinea++;}
%%