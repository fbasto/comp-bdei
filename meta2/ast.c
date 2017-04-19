#include "header.h"


Node *create_node(Node_type type){
	//printf("create node: %s\n",Node_names[type]);
	Node * node = (Node *)malloc(sizeof(Node));
	if (node != NULL){
		node->type = type;
		node->child = NULL;
		node->brother= NULL;
		node->value = NULL;
	}
	return node;
}

/*Node *insert_leaf_node(Node_type type,char *value){
	printf("insert leaf node :%s\n",value);
	Node* node = insert_node(type);
	node->value = value;
	return node;

}*/
void insert_child(Node *father,Node *newchild){
	//printf("CHILD INICIO\n");
	Node * temp = father->child;
	if(newchild == NULL){
		printf("newchild nulo\n");
	}
	if(father == NULL){
		printf("father nulo\n");
	}
	if(temp == NULL){
		newchild->father = father;
		father->child = newchild;
	}
	else {
		/*child->brother = father->child;
		child->father = father;
		father->child = child;*/
	}
	//printf("CHILD FIM\n");

}

void insert_brother(Node *brother,Node *self){
	Node *aux = brother;

	//printf("BROTHER\n");
	if(aux != NULL && self != NULL){
		while(aux->brother != NULL){
			aux = aux->brother;
		}

			aux->brother = self;
		
			self->father = aux->father;
		

	}
	//printf("BROTHER FIM\n");
}


void change_type(Node *typo ,Node *nodes){
	// printf("UMA VEZ\n");
	
	while (nodes->brother != NULL){
		nodes->child->type = typo->child->type;
		nodes = nodes->brother;
	}
		nodes->child->type = typo->child->type;

}
