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
	NODE_RealLit,
	NODE_StrLit,
	NODE_Void


}Node_type;



typedef struct node{
	Node_type type;
	struct node_ele *father;
	struct node_ele *brother;
	struct node_ele *child;
	char *value;
}Node;
