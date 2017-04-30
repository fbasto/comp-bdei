#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

static char *semantic_errors[] = {"Cannot find symbol %s>",
"Incompatible type %s in <token> statement",
"Number %s out of bounds",
"Operator %s cannot be applied to type <type>",
"Operator %s cannot be applied to types <type>, <type>",
"Reference to method %s is ambiguous",
"Symbol %s already defined"};

extern Table *symbol_table;
Table *aux_table = NULL;
Table *class_table;

void create_symboltable(Node *node){
	Node *aux = node;
	//char *aux_type= Node_names[aux->child->type];
	//char* aux_name = aux->child->value;
	//printf("Name: %s\nType: %s\n",aux_name,aux_type);
	//printf("AUX: %s\n",Node_names[aux->type]);
	if(strcmp("Program",Node_names[aux->type])==0){
		add_program(aux);
	}
	
	
	aux = aux->child;
	//printf("AUX: %s\n", Node_names[aux->type]);
	while(aux != NULL){
		analyze_node(aux);
		aux = aux->brother;
	}
	
	print_Table(symbol_table);
}

void analyze_node(Node* aux_node){
	char *aux_name = Node_names[aux_node->type];
	if(strcmp("FieldDecl",aux_name)==0){
		add_fielddecl(aux_node);
	}
	if(strcmp("MethodDecl",aux_name)==0){
		add_methoddecl(aux_node);
	}
}

void add_program(Node* aux_node){ // class gcd2{
	//char* node_type = Node_names[aux_node->child->];
	char* node_name = aux_node->child->value;
	//Node* aux = aux_node->child;
	Table* class_tbl;
	//printf("Nome para a tabela: %s\n",node_name);
	class_tbl = insert_table(node_name,0);
	class_table = class_tbl;
	//printf("DPS DE INSERIR TABLE\n");

	
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
	char *node_type = Node_names[aux_node->child->type];
	char *node_name = aux_node->child->brother->value;
	if (strcmp("StringArray",node_type)==0){
		node_type="String[]";
	}
	if (strcmp("Int",node_type)==0){
		node_type="int";
	}
	if (strcmp("Double",node_type)==0){
		node_type="double";
	}
	if (strcmp("Void",node_type)==0){
		node_type="void";
	}
	if (strcmp("Bool",node_type)==0){
		node_type="boolean";
	}
	new_symbol = create_symbol(node_name,node_type,0,0);
	insert_symbol(class_table,new_symbol);
}

void add_vardecl(Table* tbl, Node* aux_node){ // int a, b;
	char* node_name = aux_node->child->brother->value; // se houver problemas verificar este print
	char* node_type = Node_names[aux_node->child->type];
//	printf("VarDecl node_name = %s | node_type = %s\n",node_name,node_type);
	if (strcmp("StringArray",node_type)==0){
		node_type="String[]";
	}
	if (strcmp("Int",node_type)==0){
		node_type="int";
	}
	if (strcmp("Double",node_type)==0){
		node_type="double";
	}
	if (strcmp("Void",node_type)==0){
		node_type="void";
	}
	if (strcmp("Bool",node_type)==0){
		node_type="boolean";
	}
	Symbol *new_symbol = create_symbol(node_name,node_type,0,0);
	if(tbl != NULL){
		if(search_symbol(tbl,node_name)==NULL){
			insert_symbol(tbl,new_symbol);
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

	char *node_type = Node_names[aux_node->child->child->type];
	char *node_name = aux_node->child->child->brother->value;
	Table *method_tbl = insert_table(node_name,1);
	Node* insideparam;
	char *paramtype;
	Symbol *new_symbol;

	//printf(">>>>>>>>Method Decl Name: %s\n",node_name);
	if (strcmp("StringArray",node_type)==0){
		node_type="String[]";
	}
	if (strcmp("Int",node_type)==0){
		node_type="int";
	}
	if (strcmp("Double",node_type)==0){
		node_type="double";
	}
	if (strcmp("Void",node_type)==0){
		node_type="void";
	}
	if (strcmp("Bool",node_type)==0){
		node_type="boolean";
	}
	new_symbol = create_symbol("return",node_type,0,1);
	insert_symbol(method_tbl,new_symbol);
		
	//criar simbolo para adicionar a tabela da classe
	
	new_symbol = create_symbol(node_name,node_type,0,1);
	new_symbol->table_pointer = method_tbl;
	insert_symbol(class_table,new_symbol);

	//TODO: ver todos os ParamDecl e criar simbolos para por na tabela, isto ainda nao esta a funcionar bem
	
	Node* paramdecl;
	paramdecl = aux_node->child->child->brother->brother->child;
	//printf(">>> Paramdecl: %s\n",Node_names[paramdecl->type]);
	while(paramdecl != NULL){ // if ParamDecl != null
		insideparam = paramdecl->child;
		while(insideparam->brother != NULL){
			paramtype = Node_names[insideparam->type];
			if (strcmp("StringArray",paramtype)==0){
				paramtype ="String[]";
			}
			if (strcmp("Int",paramtype)==0){
				paramtype ="int";
			}
			if (strcmp("Double",paramtype)==0){
				paramtype ="double";
			}
			if (strcmp("Void",paramtype)==0){
				paramtype ="void";
			}
			if (strcmp("Bool",paramtype)==0){
				paramtype="boolean";
			}

			//printf("<<>><<>> TIPO: %s\n",insideparam->brother->value);
			new_symbol = create_symbol(insideparam->brother->value,paramtype,1,0);
			//printf("METHOD TABLE : %s\n", method_tbl->name);
			insert_symbol(method_tbl,new_symbol);
			//insert_symbol(class_table,new_symbol);
			insideparam= insideparam->brother;	
		}
		paramdecl=paramdecl->brother;

	}
	
	Node* mbchild; // Ponteiro do MethodBody's Child
	mbchild = aux_node->child->brother->child;
	while(mbchild != NULL){
		//printf("Comparing node type %s with VarDecl\n",Node_names[mbchild->type]);
		if(strcmp(Node_names[mbchild->type],"VarDecl")==0){
			add_vardecl(method_tbl,mbchild);
		}
		mbchild = mbchild->brother;
	}

}
