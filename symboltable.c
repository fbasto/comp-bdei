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
	Symbol *i;
	if(tbl != NULL)
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


Symbol *create_symbol(char *name, char *type, int param, int vm){
	Symbol *symbol = (Symbol*) malloc(sizeof(Symbol));
	symbol->name = name;
	symbol->type = type;
	symbol->param = param;
	symbol->brother = NULL;
	symbol->varmethod = vm;
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
}

void print_Table(Table *t){
	Symbol * sym = NULL;
	Table * aux;
	aux = t;
	printf("Tabele name: %s\n", aux->name);
	printf("antes de imprimir\n");
	while(aux != NULL){
		if (aux->type == 0){
			printf("===== Class %s Symbol Table =====\n", aux->name);	
			print_params(aux->child);
		}
		else{
			printf("=== Method %s",aux->name);
			printf("(");
			printf("%s",get_params(t));
			printf(")");
			printf(" Symbol Table =====\n");
			print_params(aux->child);
		}
		aux = aux->brother;
	}
	 

}

char * get_params(Table *t){
//TODO: criar uma funcao que devolva uma string com todos os tipos dos params de maneira a que de para por dentro dos () das tabelas dos metodos
	Symbol* son = t->child;
	char* retstring = "";
	while(son != NULL){
		if(son->param == 1){
			if(strcmp(retstring,"")==0){
				strcat(retstring,son->type);
			}
			else{
				strcat(retstring,",");
				strcat(retstring,son->type);			
			}
		}
		son=son->brother;
	}

}

void print_params(Symbol *s){
	Symbol *aux = s;
//	printf("IMprimir params: %s\n",aux->type);
	while(aux != NULL){
		if (aux->param == 1)
			printf("%s\t%s\tparams\n", aux->name, aux->type);
		else
			printf("%s\t%s\n", aux->name, aux->type);
//falta o caso para ter mais que um argumento de um funcao
		aux= aux->brother;
	}
}
