#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "printer.h"

static const char *semantic_errors[] = {"Cannot find symbol %s>",
"Incompatible type %s in <token> statement",
"Number %s out of bounds",
"Operator %s cannot be applied to type <type>",
"Operator %s cannot be applied to types <type>, <type>",
"Reference to method %s is ambiguous",
"Symbol %s already defined"};

extern Table *symbol_table;
Table aux_table = NULL;

void create_symboltable(Node *node){
	Node* aux = node->child;
	while(aux != NULL){
		analyze_node(aux);
		aux = aux->brother;
	}
}

void analyze_node(Node* aux_node){
	aux_name = Node_name[aux_node->type];
	if(strcmp("Program",aux_name)==0){
		add_program(aux_node);
	}
	if(strcmp("FieldDecl",aux_name)==0){
		add_fielddecl(aux_node);
	}
	if(strcmp("VarDecl",aux_name)==0){
		add_vardecl(aux_node);
	}
	if(strcmp("MethodDecl",aux_name)==0){
		add_methoddecl(aux_node);
	}
}

void add_program(Node* aux_node){ // class gcd2{

}

void add_fielddecl(Node* aux_node){ // class gcd2{ public static int gcd; -- gcd 
	
}

void add_vardecl(Node* aux_node){ // int a, b;
	char* node_name = tree->name; // se houver problemas verificar este print
	printf("VarDecl node name = %s\n",node_name);
	char* node_type = tree->type;
	Symbol *new_symbol = create_symbol(node_name,node_type,0);
	if(aux_table != NULL){
		if(search_symbol(aux_table,node_name)==NULL){
			insert_symbol(aux_table,new_symbol);
		}
		else{
			printf(semantic_errors[6], node_name);
		}
	}
}

void add_methoddecl(Node* aux_node){ // public static int gcd(int a, int b) 
	
}
