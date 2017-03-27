#include "header.h"


Node *insert_node(Node_type type){
	Node * node = (Node *)malloc(sizeof(Node));
	if (node != NULL){
		node->type = type;
		node->child = NULL;
		node->brother= NULL;
	}
	return node;
}

Node *insert_leaf_node(Node_type type,char *value){

	Node* node = insert_node(type);
	node->value = value;
	return node;

}
void insert_child(Node *father,Node *child){
	
	Node * temp = father->child;
	if(temp ==NULL){
		child->father = father;
		father->child = child;
	}
	else {
		child->brother = father->child;
		child->father = father;
		father->child = child;
	}

}

void insert_brother(Node *brother,Node *self){
	Node *aux = brother;


	if(aux != NULL && self !=NULL){
		while(aux->brother != NULL){
			aux = aux->brother;
		}
		aux->brother = self;
		self->father = aux->father;
	}
}
