#include <stdlib.h>
#include <stdio.h>
#include <string.h>


static char *Node_names[] = {
	"Program",
	"FieldDecl",
	"VarDecl",
	"MethodDecl",
	"MethodHeader",
	"MethodParams",
	"ParamDecl",
	"MethodBody",
	"Block",
	"DoWhile",
	"If",
	"Print",
	"Return",
	"While",
	"Assign",
	"Call",
	"ParseArgs",
	"Or",
	"And",
	"Eq",
	"Neq",
	"Lt",
	"Gt",
	"Leq",
	"Geq",
	"Add",
	"Sub",
	"Mul",
	"Div",
	"Mod",
	"Not",
	"Minus",
	"Plus",
	"Length",
	"Bool",
	"BoolLit",
	"Double",
	"DecLit",
	"Id",
	"Int",
	"RealLit",
	"StrLit",
	"Void",
	"StringArray",
	"Comp",
	"Error"
};

typedef enum {
	NODE_Program,
	//Declaracao de variaveis
	NODE_FieldDecl,
	NODE_VarDecl,
	//Definicao de metodos
	NODE_MethodDecl,
	NODE_MethodHeader,
	NODE_MethodParams,
	NODE_ParamDecl,
	NODE_MethodBody,

	//Statements
	NODE_Block,
	NODE_DoWhile,
	NODE_If,
	NODE_Print,
	NODE_Return,
	NODE_While,
	//Tambem e um operador
	NODE_Assign,
	NODE_Call,
	//Operador tambem
	NODE_ParseArgs,

	//Operadores
	NODE_Or,
	NODE_And,
	NODE_Eq,
	NODE_Neq,
	NODE_Lt,
	NODE_Gt,
	NODE_Leq,
	NODE_Geq,
	NODE_Add,
	NODE_Sub,
	NODE_Mul,
	NODE_Div,
	NODE_Mod,
	NODE_Not,
	NODE_Minus,
	NODE_Plus,
	NODE_Length,

	//Terminais
	NODE_Bool,
	NODE_Boolit,
	NODE_Double,
	NODE_Declit,
	NODE_Id,
	NODE_Int,
	NODE_Reallit,
	NODE_Strlit,
	NODE_Void,
	NODE_StringArray,
	NODE_Comp,
	NODE_Error
}Node_type;



typedef struct node{
	Node_type type;
	struct node *father;
	struct node *brother;
	struct node *child;
	char *value;
}Node;

// Symbol table
typedef struct table{
	char *name;
	int type; // 0=class ou 1=method
	struct symbol *child;
	struct table *brother;
} Table;

typedef struct symbol{
	char *name;
	char *type;
	int param; // 0=false ou 1=true
	int varmethod; // 0=var ou 1=method
	struct table *table_pointer; // só usado se for um MethodDecl
	struct symbol *brother;
} Symbol;



//falta um array com o nome dos nos
void print_tree(Node *node,int level);
void print_points(int n);
void print_leaf(Node *node);
Node *create_node(Node_type type);
//Node *insert_leaf_node(Node_type type,char *value);
void insert_child(Node *father,Node *child);
void insert_brother(Node *brother,Node *self);
void change_type(Node *typo ,Node *nodes);


Table *insert_table(char *name, int type);
void insert_symbol(Table *tbl, Symbol *sbl);
Symbol *create_symbol(char *name, char *type, int param,int vm);
Symbol *search_symbol(Table *tbl, char* sbl_name);
Table *search_table(char* tbl_name);
void print_Table(Table *t);
void print_symbols(Symbol *s);
char * get_params(Table *t);


void create_symboltable(Node *node);
void analyze_node(Node* aux_node);
void add_program(Node* aux_node);
void add_methoddecl(Node* aux_node);
void add_vardecl(Table *method_tbl, Node* aux_node);
void add_fielddecl(Node* aux_node);
