//archivo dedicado a la estructura del arbol
//tipos: while, for, if, ifelse, set, read, print, for, +,-,*,/,<,>,=,<=,>=, id, int, float
#include <stdlib.h>
#include <string.h>
#include<stdio.h>

struct treeNode{

	struct treeNode *next;
	struct treeNode *branch1;
	struct treeNode *branch2;
	struct treeNode *branch3;
	struct treeNode *branch4;
	char * type;
	char * charVal;
	int tipo;
	int natVal;
	float realVal;

};

struct funNode{

	struct funNode *next;
	struct treeNode *decTree;
	struct node *paramTree;
	struct node *varTree;
	char * id;
	int tipo;
	int natVal;
	float realVal;

};

struct node{
	int tipo;
	char name[20];
	int valInt;
	float valFloat;
	struct node *next;	
};

/////////////////////////////////////////////////////////////////////
//
struct auxNode{
	struct treeNode *name;
	struct auxNode *next;	
};

void iatbAux(struct auxNode **pth, struct treeNode *actualNode){//Insert at the beginning
	struct auxNode *tmp;
	tmp = (struct auxNode *)malloc(sizeof(struct auxNode));
	tmp ->name = actualNode;
	tmp ->next	= *pth;
	*pth = tmp;
}

void datbAux(struct auxNode **pth){//Delete at the beginning
	struct auxNode *tmp;
	tmp = *pth;
	*pth= tmp -> next;
	memset(tmp,0,sizeof(struct auxNode));
	free(tmp);
}



////////////////////////////////////////////////////////////////////



struct node* search(struct node *head, char* ref);
void runTree(struct treeNode *head, struct node *tableRoot);

/*
struct auxnode{



};


void insTreeNode(struct treeNode * prev, char * typeN, int natV, int realV){

	struct treeNode * tmp = malloc(sizeof(struct treeNode));
	prev->next = tmp;				//Apuntar el anterior nodo al nuevo nodo.

	//Inicializar datos del nodo nuevo.

	tmp->next = NULL;				//Apuntar nuevo nodo e hijos a NULL.
	//if(char*)

}
*/

struct treeNode* newTreeNode(char* typeV, char* charV, int tipoV, int natV, float realV, struct treeNode* b1, struct treeNode* b2, struct treeNode* b3, struct treeNode* b4){

	struct treeNode *tmp ;
	tmp= (struct treeNode *)malloc(sizeof(struct treeNode));
	tmp->next=NULL;
	tmp->charVal=charV;
	tmp->type=typeV;
	tmp->tipo=tipoV;
	tmp->natVal=natV;
	tmp->realVal=realV;
	tmp->branch1=b1;
	tmp->branch2=b2;
	tmp->branch3=b3;
	tmp->branch4=b4;
	return tmp;
}

void printTree(struct treeNode *head){//Simple print method for the list
	while(head){
		printf("%s\n",head->type);
		head=head->next;
	}
}

///////////////////////////////////////////////////////////////////////
//funciones que originalmentente estaban en funciones tabla, pero debido a la integración de treeNode es más factible moverlas acá
//son funciones dedicadas a validacion de tipos y errores de validacion
void error(int a, char*ref){
	switch(a){
		case 1:
		printf("error: tipos en expresion no compatibles\n");
		break;
		case 2:
		printf("la variable %s no ha sido declarada\n", ref);
		break;
		case 3:
		printf("tipos no compatibles: %s difiere de expresion en set", ref);
		break;
		case 4:
		printf("la variable %s no ha sido declarada\n", ref);
		break;
		case 5:
		printf("%s declarada por segunda vez\n", ref);
		break;
		case 6:
		printf("%s definida por segunda vez\n", ref);
		case 7:
		printf("Función '%s'()  no declarada\n", ref);
		case 8:
		printf("Los parámetros de '%s'() no coinciden con la declaración\n", ref);
		break;
	}
	exit(1);
}

void fun_Valid_SET(char *ID,struct treeNode *expr, struct node *tableRoot){
	struct node *copiaID;
	copiaID=search(tableRoot,ID);
	if(copiaID!=NULL){
		if(copiaID->tipo != expr->tipo){
			error(3, ID);
		}
	}else{
		error(4, ID);
	}
}

int fun_Valid_Dos(struct treeNode* izquierdo,struct treeNode *derecho){
	if(izquierdo->tipo!=derecho->tipo){
		char* basura=NULL;
		error(1,basura);
	}
	return (izquierdo->tipo);
}

int fun_ID(char *ref, struct node *tableRoot){
	struct node *copiaID;
	copiaID=search(tableRoot,ref);
	if(copiaID!=NULL)
		return (copiaID->tipo);
	else
		error(2,ref);
	return 0;
}

//funciones de interpretación de arbol
/////////////////////////////////////////////////////////////////////////

int compareToTree(char*a,char*b){//It returns 1 if strings are equal
	while(*a!='\0' || *b!='\0'){
		if(*a == *b){
			a++;
			b++;
		}else{
			return 0;
		}
	}

	if(*a=='\0' && *b=='\0'){
		return 1;
	}else{
		return 0;
	}
}

int compare(char*type){//It returns 1 if strings are equal
	if (compareToTree(type,"set"))
		return 1;
	else if(compareToTree(type,"read"))
		return 2;
	else if(compareToTree(type,"print"))
		return 3;
	else if(compareToTree(type,"if"))
		return 4;
	else if(compareToTree(type,"ifelse"))
		return 5;
	else if(compareToTree(type,"while"))
		return 6;
	else if(compareToTree(type,"for"))
		return 7;
	else if(compareToTree(type,"+"))
		return 8;
	else if(compareToTree(type,"-"))
		return 9;
	else if(compareToTree(type,"*"))
		return 10;
	else if(compareToTree(type,"/"))
		return 11;
	else if(compareToTree(type,"<"))
		return 12;
	else if(compareToTree(type,">"))
		return 13;
	else if(compareToTree(type,"="))
		return 14;
	else if(compareToTree(type,"<="))
		return 15;
	else if(compareToTree(type,">="))
		return 16;
	else if(compareToTree(type,"id")){
		return 17;
	}
	return 18;//int o float
}

void exprFun(struct treeNode *head, struct node *tableRoot){
	if(head!=NULL){
		struct node *ID;
		exprFun(head->branch1, tableRoot);
		exprFun(head->branch2, tableRoot);
		switch(compare(head->type)){
			case 8://add
			head->natVal=head->branch1->natVal+head->branch2->natVal;
			head->realVal=head->branch1->realVal+head->branch2->realVal;
			head->tipo=head->branch1->tipo;
			break;
			
			case 9://substract
			head->natVal=head->branch1->natVal-head->branch2->natVal;
			head->realVal=head->branch1->realVal-head->branch2->realVal;
			head->tipo=head->branch1->tipo;
			break;
			
			case 10://multiplication
			head->natVal=head->branch1->natVal*head->branch2->natVal;
			head->realVal=head->branch1->realVal*head->branch2->realVal;
			head->tipo=head->branch1->tipo;
			break;
			
			case 11://division
			head->natVal=head->branch1->natVal/head->branch2->natVal;
			head->realVal=head->branch1->realVal/head->branch2->realVal;
			head->tipo=head->branch1->tipo;
			break;
			
			case 17://id
			ID=search(tableRoot, head->charVal);
			head->natVal=ID->valInt;
			head->realVal=ID->valFloat;
			head->tipo=ID->tipo;
			break;

			case 18:
			//caso de numero, no hace nada porque ya está listo para evaluarse
			break;

			default:
			printf("%s\n", "que paso papi");
			break;
		}
	}
}

void setFunction(struct treeNode *head, struct node *tableRoot){//Jala chido
	struct node *ID;
	ID=search(tableRoot, head->charVal);
	exprFun(head->branch1,tableRoot);
	ID->valInt=head->branch1->natVal;
	ID->valFloat=head->branch1->realVal;
}

void readFunction(struct treeNode *head, struct node *tableRoot){
	struct node *ID;
	ID=search(tableRoot, head->charVal);
	if(ID->tipo==1)
		scanf("%d",&(ID->valInt));
	else
		scanf("%f",&(ID->valFloat));
}

void printFunction(struct treeNode *head, struct node *tableRoot){
	exprFun(head->branch1,tableRoot);
	if(head->branch1->tipo==1)
		printf("%d\n", head->branch1->natVal);
	else
		printf("%f\n", head->branch1->realVal);
}

void expresionFun(struct treeNode *head, struct node *tableRoot){
	exprFun(head->branch1,tableRoot);
	exprFun(head->branch2,tableRoot);
	if(head->branch1->tipo==head->branch2->tipo){
		head->tipo=head->branch1->tipo;
		switch(compare(head->type)){
			case 12://menor
			head->natVal=head->branch1->natVal<head->branch2->natVal;
			head->realVal=head->branch1->realVal<head->branch2->realVal;
			break;

			case 13://mayor
			head->natVal=head->branch1->natVal>head->branch2->natVal;
			head->realVal=head->branch1->realVal>head->branch2->realVal;
			break;

			case 14://igual
			head->natVal=head->branch1->natVal==head->branch2->natVal;
			head->realVal=head->branch1->realVal==head->branch2->realVal;
			break;

			case 15://menorigual
			head->natVal=head->branch1->natVal<=head->branch2->natVal;
			head->realVal=head->branch1->realVal<=head->branch2->realVal;
			break;

			case 16://mayorigual
			head->natVal=head->branch1->natVal>=head->branch2->natVal;
			head->realVal=head->branch1->realVal>=head->branch2->realVal;
			break;

			default:
			printf("%s\n", "que paso papi");
			break;
		}
	}else{
		char *basura;
		error(1,basura);
	}
}

void ifFunction(struct treeNode *head, struct node *tableRoot){
	expresionFun(head->branch1,tableRoot);
	if(head->branch1->tipo==1){
		if(head->branch1->natVal)
			runTree(head->branch2, tableRoot);
	}else{
		if(head->branch1->realVal)
			runTree(head->branch2, tableRoot);
	}
}

void ifelseFunction(struct treeNode *head, struct node *tableRoot){
	expresionFun(head->branch1,tableRoot);
	if(head->branch1->tipo==1){
		if(head->branch1->natVal)
			runTree(head->branch2, tableRoot);
		else
			runTree(head->branch3, tableRoot);
	}else{
		if(head->branch1->realVal)
			runTree(head->branch2, tableRoot);
		else
			runTree(head->branch3, tableRoot);
	}
}

void whileFunction(struct treeNode *head, struct node *tableRoot){
	expresionFun(head->branch1,tableRoot);
	if (head->branch1->tipo==1){
		while(head->branch1->natVal){
			runTree(head->branch2, tableRoot);
			expresionFun(head->branch1,tableRoot);
		}
		
	}else{
		while(head->branch1->realVal){
			runTree(head->branch2, tableRoot);
			expresionFun(head->branch1,tableRoot);
		}
	}
}

void forFunction(struct treeNode *head, struct node *tableRoot){
	struct node *ID;
	int topeInt=0, stepInt=0;
	float topeFloat=0, stepFloat=0;
	ID=search(tableRoot, head->charVal);

	exprFun(head->branch1,tableRoot);
	exprFun(head->branch2,tableRoot);
	exprFun(head->branch3,tableRoot);

	if(head->branch1->tipo==head->branch2->tipo==head->branch3->tipo){		
		ID->valInt=head->branch1->natVal;
		ID->valFloat=head->branch1->realVal;

		topeInt=head->branch2->natVal;
		topeFloat=head->branch2->realVal;
		
		stepInt=head->branch3->natVal;
		stepFloat=head->branch3->realVal;
		
		if (head->branch1->tipo==1){
			for(ID->valInt;ID->valInt<=topeInt;ID->valInt=ID->valInt+stepInt){
				runTree(head->branch4, tableRoot);
			}
		}else{
			for(ID->valFloat;ID->valFloat<=topeFloat;ID->valFloat=ID->valFloat+stepFloat){
				runTree(head->branch4, tableRoot);
			}
		}
	}else{
		char *basura;
		error(1,basura);
	}
}

void runTree(struct treeNode *head, struct node *tableRoot){
	while(head){
		switch(compare(head->type)){
			case 1://set
			setFunction(head, tableRoot);
			break;
			case 2://read
			readFunction(head, tableRoot);
			break;
			case 3://print
			printFunction(head, tableRoot);
			break;
			case 4://if
			ifFunction(head, tableRoot);
			break;
			case 5://ifelse
			ifelseFunction(head, tableRoot);
			break;
			case 6://while
			whileFunction(head, tableRoot);
			break;
			case 7://for
			forFunction(head, tableRoot);
			break;
			default:
			printf("%s\n", "que paso papi");
		}
		head=head->next;
	}
}

/////////////////////////////////////////////////////////////////////////
//funciones de la tabla de variables

//Estrucutura para variables
//tipo = 1 cuando el valor es igual a un entero
//tipo = 2 cuando el valor es igual a un flotante

int compareTo(char*a,char*b){//It returns 1 if strings are equal
	while(*a!='\0' || *b!='\0'){
		if(*a == *b){
			a++;
			b++;
		}else{
			return 0;
		}
	}

	if(*a=='\0' && *b=='\0'){
		return 1;
	}else{
		return 0;
	}
}

void iatb(struct node **pth, int type, int vInt, float vFloat, char* ref){//Insert at the beginning
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	strcpy(tmp -> name,ref);
	tmp ->tipo=type;
	tmp ->valInt=vInt;
	tmp ->valFloat=vFloat;
	tmp ->next	= *pth;
	*pth = tmp;
}

struct node* search(struct node *head, char* ref){//search the memory address were the node is contained
	struct node *tmp;
	tmp = head;
	int flag = 0;
	if(tmp !=NULL){
		if (compareTo((tmp -> name),ref)){
			return tmp;
		}
		while (tmp->next != NULL){
			if (compareTo((tmp ->next-> name),ref)){
				return tmp->next;
			}
			tmp = tmp -> next;
		}
	}
	return NULL;
}

int insertInTable(struct node **head, char* ref, int type, int vInt, float vFloat){
	if(search(*head, ref)==NULL){
		iatb(head, type, vInt, vFloat, ref);
		return 1;
	}
	else{
		return 0;
	}
}

void print(struct node *head){//Simple print method for the list
	while(head){
		printf("%s",head->name);
		if(head->tipo==1)
			printf(" (int):=%d\n",head->valInt);
		if(head->tipo==2)
			printf(" (float):=%f\n",head->valFloat);
		head=head->next;
	}
}

/////////////////////////////////////////////////////////////////////////
//funciones de la tabla de funciones

//Estrucutura para variables
//tipo = 1 cuando el valor es igual a un entero
//tipo = 2 cuando el valor es igual a un flotante


void iatbFun(struct funNode **pth, struct treeNode *dec, struct node *var, struct node *param, int tipo, char* ref){//Insert at the beginning
	struct funNode *tmp;
	tmp = (struct funNode *)malloc(sizeof(struct funNode));
	strcpy(tmp -> id,ref);
	tmp ->tipo=tipo;
	tmp ->decTree=dec;
	tmp ->varTree=var;
	tmp ->paramTree=param;
	tmp ->next	= *pth;
	*pth = tmp;
}

struct funNode* searchFun(struct funNode *head, char* ref){//search the memory address were the node is contained
	struct funNode *tmp;
	tmp = head;
	int flag = 0;
	if(tmp !=NULL){
		if (compareTo((tmp -> id),ref)){
			return tmp;
		}
		while (tmp->next != NULL){
			if (compareTo((tmp ->next-> id),ref)){
				return tmp->next;
			}
			tmp = tmp -> next;
		}
	}
	return NULL;
}

int insertInFunTable(struct funNode **head, char* ref, struct node *var, struct node *param, struct treeNode *dec, int tipo){
	struct funNode *busqueda;
	busqueda = searchFun(*head, ref);
	if(busqueda==NULL){
		iatbFun(head, dec, var,param, tipo, ref);
		return 1;
	}
	else{
		if(busqueda->decTree == NULL){
			//función de error(6,$2); aquí se comparan los paramRoot
			busqueda->decTree=dec;
			busqueda->varTree=var;
			busqueda->paramTree=var;
			busqueda->tipo=tipo;
			return 1;
		}
		return 0;
	}
}

void printFun(struct funNode *head){//Simple print method for the list
	while(head){
		printf("%s",head->id);
	}
	head=head->next;
}


int funcParamCheck(struct funNode * root, struct funNode * call){

	struct node * tmp = root->paramTree;
	struct node * tmp2 = call->paramTree;

	while(tmp != NULL){
		
		if(strcmp(tmp->name, tmp2->name)){

			if(tmp->tipo == tmp2->tipo){

				tmp = tmp->next;
				tmp2 = tmp2->next;

			}else{
				return 1;
			}
		}else{

			return 1;
		}
	}	

	return 0;

}