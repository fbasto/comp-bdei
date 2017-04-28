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
	//char* node_type = Node_names[aux_node->child->];
	char* node_name = aux_node;
	Node* aux = aux_node->child;
	Table* class_tbl = NULL;
	Node* aux2 = NULL;//ajuda para ir  buscar o tipo dos metodos e o id
	Symbol * new_symbol	= NULL;
	class_tbl = insert_table(node_name,0);

	
}

void add_fielddecl(Node* aux_node){ // class gcd2{ public static int gcd; -- gcd 
	// char* node_name = aux_node->name; // se houver problemas verificar este print
	// printf("FieldDecl node name = %s\n",node_name);

	// if(aux_table != NULL){
	// 	if(search_table(aux_table,node_name)==NULL){
	// 		aux_table = insert_table(aux_node->name,aux_node->type);
	// 	}
	// 	else{
	// 		printf(semantic_errors[6], node_name);
	// 	}
	// }

	Symbol *new_symbol;
	node_type = Node_names[aux_child->type];
	node_name = aux_child->brother->value;
	new_symbol = create_symbol(node_name,node_type,0);
	insert_symbol(aux_table,new_symbol);
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
	// char* node_name = aux->name; // se houver problemas verificar este print
	// printf("MethodDecl node name = %s\n",node_name);
	// char* node_type = tree->type;
	// if(aux_table != NULL){
	// 	if(search_symbol(aux_table,node_name)==NULL){
	// 		insert_symbol(aux_table,new_symbol);
	// 	}
	// 	else{
	// 		printf(semantic_errors[6], node_name);
	// 	}
	// }

	char* node_type = Node_names[aux_node->child->child];
	char* node_name = aux_node->child->child->brother->value;
	method_tbl = insert_table(node_name,1);

	Symbol *new_symbol = create_symbol("return",node_type,0);
	insert_symbol(method_tbl,new_symbol);

	paramdecl = aux_node->child->child->brother->brother->child;
	if(paramdecl != NULL){ // if ParamDecl != null
		Symbol *new_symbol = create_symbol(paramdecl->child->brother->value,paramdecl->child,1);
		insert_symbol(method_tbl,new_symbol);
		paramdecl=paramdecl->brother;
	}


}
