#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "printer.h"

extern table *symbol_table;

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