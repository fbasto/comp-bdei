#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

extern Table *symbol_table;

Table *insert_table(char *name, int type){
	Table *table_aux = (Table*) malloc(sizeof(Table));
	table_aux->name = name;
	table_aux->type = type;
	table_aux->brother = NULL;
	table_aux->child = NULL;
	table_aux->method_params = (char*)malloc(sizeof(""));
	strcpy(table_aux->method_params,"");
	Table *i;
	if(symbol_table == NULL){
		symbol_table = table_aux;
	}
	else{
		i = symbol_table;
		while(i->brother != NULL){
			i=i->brother;
		}
		i->brother = table_aux;
	}
	return table_aux;
}

void insert_symbol(Table *tbl, Symbol *sbl){
	Symbol *i=NULL;
	if(tbl != NULL){
		if(tbl->child == NULL){
			tbl->child = sbl;
		}
		else{
			i = tbl->child;
			while(i->brother != NULL){
				i=i->brother;
			}
			i->brother = sbl;
		}
	}
}

Symbol *create_symbol(char *name, char *type, int param, int vm){
	Symbol *symbol = (Symbol*) malloc(sizeof(Symbol));
	symbol->name = name;
	symbol->type = type;
	symbol->param = param;
	symbol->brother = NULL;
	symbol->varmethod = vm;
	symbol->table_pointer = NULL;
	symbol->declared = 0;
	return symbol;
}

Symbol *search_symbol(Table *tbl, char* sbl_name){
	Symbol *sbl_aux = tbl->child;
	while(sbl_aux != NULL){
		if(strcmp(sbl_aux->name,sbl_name)==0){
			return sbl_aux;
		}
		sbl_aux = sbl_aux->brother;
	}
	if(sbl_aux == NULL){
		return NULL;
	}
	return NULL;
}

Table *search_table(char* tbl_name){
	Table *tbl_aux = symbol_table;
	while(tbl_aux != NULL){
		if(strcmp(tbl_aux->name,tbl_name)==0){
			return tbl_aux;
		}
		tbl_aux = tbl_aux->brother;
	}
	if(tbl_aux == NULL){
		return NULL;
	}
	return NULL;
}

void print_Table(Table *t){
	Table * aux;
	aux = t;
	//printf("Table name: %s\n", aux->name);
	//printf("Antes de imprimir tabela\n");
	while(aux != NULL){
		if (aux->type == 0){
			printf("===== Class %s Symbol Table =====\n", aux->name);	
			print_symbols(aux->child);
		}
		else{
			char *params = get_params(aux);
			//char *params = (char*)malloc(sizeof(get_params(aux)));
			//strcpy(params,get_params(aux));
			printf("===== Method %s(%s) Symbol Table =====\n",aux->name,params);
			print_symbols(aux->child);
		}
		aux = aux->brother;
		if (aux != NULL){
			printf("\n");
		}
	} 

}

char *get_params(Table *t){
	Symbol* son = t->child;
	char *retstring = (char*)malloc(sizeof(""));
	strcpy(retstring,"");
	while(son != NULL){
		//printf("Checking if [ %s - %s ] is a param\n",son->name,son->type);
		if(son->param == 1){
			//printf("param confirmed: adding\n");
			if(strcmp(retstring,"")==0){
				//retstring = (char*)malloc(sizeof(son->type));
				retstring = strdup(son->type);
			}
			else{
				//char *temp = (char*)malloc(sizeof(retstring));
				//strcpy(temp,retstring);
				retstring = (char*)realloc(retstring,sizeof(char)*(strlen(retstring)+strlen(son->type)+1));
				strcat(retstring,",");
				strcat(retstring,son->type);			
			}
		}
		son=son->brother;
	}
	//printf("retstr=%s\n",retstring);
	//printf("Params colecionados\n");
	return retstring;

}

void print_symbols(Symbol *s){
	Symbol *aux = s;
	char* method_params;
//	printf("IMprimir params: %s\n",aux->type);
	while(aux != NULL){
		if (aux->param == 1)
			printf("%s\t\t%s\tparam\n", aux->name, aux->type);
		else{
			if(aux->varmethod == 1 && aux->table_pointer != NULL){
				//method_params = (char*) malloc(sizeof(get_params(aux->table_pointer)));
				method_params = get_params(aux->table_pointer);
				printf("%s\t(%s)\t%s\n",aux->name,method_params,aux->type);
			}
			else{
				printf("%s\t\t%s\n",aux->name,aux->type);
			}
		}

//falta o caso para ter mais que um argumento de um funcao
		aux= aux->brother;
	}
}

