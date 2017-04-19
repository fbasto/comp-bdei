#include "header.h"



void print_tree(Node *node,int level){
	print_points(level);
	if(node != NULL){
		if (node->type == NODE_Id || node->type == NODE_Reallit || node->type == NODE_Declit || node->type == NODE_Strlit || node->type == NODE_Boolit){
			print_leaf(node);
		}
		else{
			printf("%s\n",Node_names[node->type]);	
		}

		Node *child = node->child;
		if (child != NULL){
			print_tree(child,level+1);
			while(child->brother != NULL){
				child = child->brother;
				print_tree(child,level +1);
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

void print_leaf(Node *node){
	printf("%s(%s)\n", Node_names[node->type],node->value);
}
