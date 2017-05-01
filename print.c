#include "header.h"


void print_tree(Node *node,int level,int anoted_tree,int anoted_authorization){ //anoted_tree=0 normal || anoted_tree=1 anotada
	print_points(level);
	if(node != NULL){
		if (node->type == NODE_Id || node->type == NODE_Reallit || node->type == NODE_Declit || node->type == NODE_Strlit || node->type == NODE_Boolit){
			print_leaf(node,anoted_tree,anoted_authorization);
		}
		else{
			print_nodetype(node->type,anoted_tree);
		}
		Node *child = node->child;
		if (child != NULL){
			if(node->type!=NODE_Program || node->type!=NODE_FieldDecl || node->type!=NODE_VarDecl || node->type!=NODE_MethodDecl || node->type!=NODE_MethodHeader || node->type!=NODE_MethodParams || node->type!=NODE_ParamDecl || node->type!=NODE_MethodBody){
				anoted_authorization = 1;
			}
			else{
				anoted_authorization = 0;
			}
			print_tree(child,level+1,anoted_tree,anoted_authorization);
			while(child->brother != NULL){
				child = child->brother;
				print_tree(child,level+1,anoted_tree,anoted_authorization);
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

void print_leaf(Node *node,int anoted,int authorization){
	if(anoted==1 && authorization==1){
		printf("%s(%s) - %s\n",Node_names[node->type],node->value,node->leaf_type);
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
