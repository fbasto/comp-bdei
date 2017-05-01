#include "header.h"

extern Table *symbol_table;

void print_tree(Node *node,int level,int anoted_tree,int anoted_authorization, Table *tbl){ //anoted_tree=0 normal || anoted_tree=1 anotada
	print_points(level);
	if(node != NULL){
		if (node->type == NODE_Id || node->type == NODE_Reallit || node->type == NODE_Declit || node->type == NODE_Strlit || node->type == NODE_Boolit){
			print_leaf(node,anoted_tree,anoted_authorization,tbl);
		}
		else{
			print_nodetype(node->type,anoted_tree);
		}
		Node *child = node->child;
		if(node->type!=NODE_Program && node->type!=NODE_FieldDecl && node->type!=NODE_VarDecl && node->type!=NODE_MethodDecl && node->type!=NODE_MethodHeader && node->type!=NODE_MethodParams && node->type!=NODE_ParamDecl && node->type!=NODE_MethodBody){
			anoted_authorization = 1;
		}
		else{
			anoted_authorization = 0;
		}
		if(node->type==NODE_MethodDecl){
			tbl = search_table(node->child->child->brother->value);
			printf("Switching to table %s\n",tbl->name);
		}
		if (child != NULL){
			print_tree(child,level+1,anoted_tree,anoted_authorization,tbl);
			while(child->brother != NULL){
				child = child->brother;
				print_tree(child,level+1,anoted_tree,anoted_authorization,tbl);
			}
		}
	}
}


void print_points(int n){
	while(n > 0){
		printf("..");
		n--;
	}
}

void print_leaf(Node *node,int anoted,int authorization,Table *tbl){
	//printf("TBL = %s\n",tbl->name);
	Symbol *saux;
	if(anoted==1 && authorization==1){
		if(node->type == NODE_Id){
			//if(tbl->name != NULL){
				//printf("CRRT TBL = %s\n",tbl->name);
			//}
			saux = search_symbol(tbl,node->value);
			if(saux == NULL){
				search_symbol(symbol_table,node->value);
			}
			printf("%s(%s) - %s\n",Node_names[node->type],node->value,saux->type);
		}
		else{
			printf("%s(%s) - %s\n",Node_names[node->type],node->value,Node_notes[node->type]);
		}
	}
	else{
		printf("%s(%s)\n",Node_names[node->type],node->value);
	}
}

void print_nodetype(Node_type type,int anoted){
	if(anoted==1 && Node_notes[type] != "NULL"){
		printf("%s - %s\n",Node_names[type],Node_notes[type]);
	}
	else{
		printf("%s\n",Node_names[type]);	
	}
}
