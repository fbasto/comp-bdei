#include <stdlib.h>
#include <stdio.h>
#include <printer.h>

extern table *symbol_table;

Table *insert_table(char* name, int type){
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

Symbol *create_symbol()