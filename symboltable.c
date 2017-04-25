#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "printer.h"

extern table *symbol_table;

Table *insert_table(char *name, int type){
	Table *table_aux = (Table*) malloc(sizeof(Table));
	table_aux->name = name;
	table_aux->type = type;
	table_aux->brother = NULL;
	table_aux->child = NULL;

	if(symbol_table == NULL){
		symbol_table = table_aux;
	}
	else{
		i = symbol_table;
		while(i->brother != NULL){
			i=symbol_table->brother;
		}
		i->brother = table;
	}
	return table_aux;
}




void insert_symbol(Table *tbl, Symbol *sbl){
	if(tbl->child == NULL){
		tbl->child = sbl;
	}
	else{
		i = tbl->child;
		while(i->brother != NULL){
			i=tbl->brother;
		}
		i->brother = sbl;
	}
}

Symbol *create_symbol(char *name, char *type, int param){
	Symbol *symbol = (Symbol*) malloc(sizeof(Symbol));
	symbol->name = name;
	symbol->type = type;
	symbol->param = param;
	symbol->brother = NULL;
	return symbol;
}

Symbol *search_symbol(Table *tbl, char* sbl_name){
	sbl_aux = tbl->child;
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
	tbl_aux = symbol_table;
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

void print_Table(Table t){
	Symbol * sym = NULL;
	if (t->type == 0){
		printf("===== Class %s Symbol Table =====", t->name);	
	}
	else{
		printf("=== Method");
		print_params(t->child);
		printf(" Symbol Table =====")
	} 

}


void print_params(Symbol *s){
	Symbol *aux = s
	printf("( ")
	while(aux->brother != NULL){
		if (aux->brother != NULL){
			if (aux->param == 1)
				printf("%s, ", aux->type);
		}
		else if(aux->brother == NULL){
			if (aux->param == 1)
				printf("%s", aux->type);
		}
		aux= aux->brother;
	}
	printf(")");
}
