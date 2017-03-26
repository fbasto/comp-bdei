#include "struct.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




Node *insert_node(Node_type type);
Node *insert_leaf_node(Node_type type,char* value);
void insert_child(Node* father,Node* child);
void insert_brother(Node *brother,Node *self)
