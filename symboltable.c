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


void print_Table(Table t){
	Symbol * sym = NULL;
	if (t->type == 0){
		printf("===== Class %s Symbol Table", t->name);	
	}
	else{
		printf("=== Method");
		print_params(t->child);
		printf(" Symbol Table")
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
