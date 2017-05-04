#include "header.h"

extern Table *symbol_table;

void print_tree(Node *node,int level,int anoted_tree,int anoted_authorization, Table *tbl){ //anoted_tree=0 normal || anoted_tree=1 anotada
	Symbol *sauxiliar;
	print_points(level);
	if(node != NULL){
		if(node->type==NODE_VarDecl || node->type==NODE_ParamDecl){
			sauxiliar = search_symbol(tbl,node->child->brother->value);
			sauxiliar->declared = 1;
		}
		if (node->type == NODE_Id || node->type == NODE_Reallit || node->type == NODE_Declit || node->type == NODE_Strlit || node->type == NODE_Boolit){
			print_leaf(node,anoted_tree,anoted_authorization,tbl);
		}
		else{
			print_nodetype(node,anoted_tree,tbl);
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
			//printf("Switching to table %s\n",tbl->name);
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
			saux = get_symbolID(tbl, node);
			if(saux == NULL){
				printf("Erro ID nao declarado\n");
			}
			else if(saux != NULL){
				printf("%s(%s) - %s\n",Node_names[node->type],node->value,saux->type);
			}
		}
		else{
			printf("%s(%s) - %s\n",Node_names[node->type],node->value,Node_notes[node->type]);
		}
	}
	else{
		printf("%s(%s)\n",Node_names[node->type],node->value);
	}
}

void print_nodetype(Node *node, int anoted, Table *tbl){
	Symbol *saux = NULL;
	Symbol *saux2 = NULL;
	Table *taux = NULL;
	char caux[500] = "";
	char type1[500] = "";
	char type2[500] = "";
	if(anoted==1 && Node_notes[node->type] != "NULL" && Node_notes[node->type] != "DYN"){
		printf("%s - %s\n",Node_names[node->type],Node_notes[node->type]);
	}
	else if(anoted==1 && Node_notes[node->type] == "DYN"){
		if(node->type == NODE_Assign){
			saux = get_symbolID(tbl,node->child);
			if(saux == NULL){
				printf("Erro ID nao declarado\n");
			}
			else if(saux != NULL){
				printf("%s - %s\n",Node_names[node->type],saux->type);
			}
		}
		if(node->type == NODE_Add || node->type == NODE_Sub || node->type == NODE_Mul || node->type == NODE_Div){
			//printf("Op. Aritmetica - type of 1st: %s\n",Node_names[node->child->type]);
			if(strcmp(Node_names[node->child->type],"Id")== 0){
				saux = get_symbolID(tbl,node->child);
				strcpy(type1,saux->type);
				//printf("type1=%s\n",type1);
			}
			else{
				strcpy(type1,Node_names[node->child->type]);
			}
			if(strcmp(Node_names[node->child->brother->type],"Id")== 0){
				saux2 = get_symbolID(tbl,node->child->brother);
				strcpy(type2,saux2->type);
			}
			else{
				strcpy(type2,Node_names[node->child->brother->type]);
			}
			if(strcmp("double",type1)==0){
				strcpy(caux,"double");
				/*if(strcmp("double",type2)==0){
					strcpy(caux,"double");
				}
				else if(strcmp("int",type2)==0){
					strcpy(caux,"double");
				}*/
			}
			else if(strcmp("int",type1)==0){
				if(strcmp("int",type2)==0){
					strcpy(caux,"int");
				}
				else if(strcmp("double",type2)==0){
					strcpy(caux,"double");
				}
			}
			if(caux != NULL){
				printf("%s - %s\n",Node_names[node->type],caux);
			}			
		}
	}
	else{
		printf("%s\n",Node_names[node->type]);
	}
}

Symbol* get_symbolID(Table *tbl, Node *node){
	Symbol *saux;
	saux = search_symbol(tbl,node->value);
	if(saux == NULL || saux->declared == 0){
		saux = search_symbol(symbol_table,node->value);
	}
	return saux;
}


