#include "header.h"

extern Table *symbol_table;

void print_tree(Node *node,int level,int anoted_tree,int anoted_authorization, Table *tbl){ //anoted_tree=0 normal || anoted_tree=1 anotada
	Symbol *sauxiliar;
	print_points(level);
	if(node != NULL){
		if(node->type==NODE_VarDecl || node->type==NODE_ParamDecl){
			sauxiliar = search_symbol(tbl,node->child->brother->value);
			if(sauxiliar == NULL){
				sauxiliar = search_symbol(symbol_table, node->child->brother->value);
			}
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
	Table *taux;
	if(anoted==1 && authorization==1){
		taux = symbol_table;
		if(node->type == NODE_Id){
			if (node->varmethod == 0){
				saux = get_symbolID(tbl, node);
				if(saux == NULL){
					printf("Erro ID nao declarado\n");
				}
				else if(saux != NULL){
					printf("%s(%s) - %s\n",Node_names[node->type],node->value,saux->type);
				}
			}
			else{
				while(taux != NULL){
					//printf("taux->method_params=%s | cmp=%s\n",get_params(taux),node->method_params);
					if((strcmp(taux->name,node->value)== 0 && strcmp(get_params(taux),node->method_params)==0)){
						break;
					}
					taux = taux->brother;
					if(taux == NULL){
						printf("Tabela null a procurar por parametros de metodo\n");
					}
				}
				if (taux != NULL){
					printf("%s(%s) - (%s)\n",Node_names[node->type],node->value,node->method_params);
				}
			}
		}
		else{
			printf("%s(%s) - %s\n",Node_names[node->type],node->value,Node_notes[node->type]);
		}
	}
	else{
		//printf("HEY\n");
		printf("%s(%s)\n",Node_names[node->type],node->value);
	}
}

void print_nodetype(Node *node, int anoted, Table *tbl){
	Symbol *saux = NULL;
	Symbol *saux3 = NULL;
	Symbol *saux2 = NULL;
	Node *node_aux=NULL;
	Table *taux = NULL;
	char *caux = (char*)malloc(sizeof(""));
	strcpy(caux,"");
	char *caux2 = (char*)malloc(sizeof(""));
	strcpy(caux2,"");
	char *type1;
	char *type2;
	if(anoted==1 && strcmp(Node_notes[node->type],"NULL") != 0 && strcmp(Node_notes[node->type],"DYN") != 0){
		printf("%s - %s\n",Node_names[node->type],Node_notes[node->type]);
	}
	else if(anoted==1 && strcmp(Node_notes[node->type],"DYN")==0){
		if(node->type == NODE_Assign){
			saux = get_symbolID(tbl,node->child);
			if(saux == NULL){
				printf("Erro ID nao declarado\n");
			}
			else if(saux != NULL){
				printf("%s - %s\n",Node_names[node->type],saux->type);
			}
		}
		if (node->type == NODE_Call){
			saux = get_symbolID(tbl,node->child);
			node->child->varmethod = 1;
			node_aux = node->child->brother;
			//printf("b4while\n");
			while(node_aux != NULL){
				saux3 = get_symbolID(tbl,node_aux);
				//printf("NODE NAME: %s\nNODE TYPE: %s\n",node_aux->value,Node_names[node_aux->type]);
				if(strcmp(caux2,"")==0){
					//printf("v1 caux2=%s\n",caux2);
					caux2 = (char*)malloc(sizeof(saux3->type));
					strcpy(caux2,saux3->type);
					//printf("v1 caux2 v2=%s\n",caux2);
				}
				else{
					//printf("v2 caux2=%s\n",caux2);
					char *temp = (char*)malloc(sizeof(caux2));
					strcpy(temp,caux2);
					caux2 = (char*)malloc(sizeof(caux2)+sizeof(",")+sizeof(saux3->type));
					caux2 = strcat(temp,",");
					strcat(caux2,saux3->type);
					//printf("v2 caux2 v2=%s\n",caux2);			
				}
				node_aux = node_aux->brother;
			}
			//printf("afterwhile\n");
			node->child->method_params = (char*)malloc(sizeof(caux2));
			strcpy(node->child->method_params,caux2);
			//printf("METHODPARAMS: %s\n",caux2);			taux=symbol_table;
			taux=symbol_table;
			while(taux != NULL){
				//printf("taux->method_params=%s | cmp=%s\n",get_params(taux),node->child->method_params);
				if((strcmp(taux->name,node->child->value)== 0 && strcmp(get_params(taux),node->child->method_params)==0)){
					break;
				}
				taux = taux->brother;
				if(taux == NULL){
					printf("Tabela null a procurar por parametros de metodo\n");
				}
			}
			if(strcmp(taux->child->name,"return")==0){
				printf("%s - %s\n",Node_names[node->type],taux->child->type);
			}				
			else{
				printf("%s - undef\n",Node_names[node->type]);
			}
			//printf("%s - porfazer\n",Node_names[node->type]);
			
				
		}

		if(node->type == NODE_Add || node->type == NODE_Sub || node->type == NODE_Mul || node->type == NODE_Div){
			//printf("Op. Aritmetica - type of 1st: %s\n",Node_names[node->child->type]);
			if(strcmp(Node_names[node->child->type],"Id")== 0){
				saux = get_symbolID(tbl,node->child);
				type1 = (char*)malloc(sizeof(saux->type));
				strcpy(type1,saux->type);
				//printf("type1=%s\n",type1);
			}
			else{
				type1 = (char*)malloc(sizeof(Node_names[node->child->type]));
				strcpy(type1,Node_names[node->child->type]);
			}
			if(strcmp(Node_names[node->child->brother->type],"Id")== 0){
				saux2 = get_symbolID(tbl,node->child->brother);
				type2 = (char*)malloc(sizeof(saux2->type));
				strcpy(type2,saux2->type);
			}
			else{
				type2 = (char*)malloc(sizeof(Node_names[node->child->brother->type]));
				strcpy(type2,Node_names[node->child->brother->type]);
			}
			if(strcmp("double",type1)==0){
				caux = (char*)malloc(sizeof("double"));
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
					caux = (char*)malloc(sizeof("int"));
					strcpy(caux,"int");
				}
				else if(strcmp("double",type2)==0){
					caux = (char*)malloc(sizeof("double"));
					strcpy(caux,"double");
				}
			}
			//if(caux != NULL){
				printf("%s - %s\n",Node_names[node->type],caux);
			//}			
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


