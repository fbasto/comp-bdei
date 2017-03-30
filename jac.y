%{
    #include <stdio.h>
	#include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"
	#include "header.h"
//	#include "ast.h"
    int yylex(void);
    void yyerror (const char *s);
	extern int num_line;
	extern int num_col;
	extern char *yytext;
	int syn_error = 0;
	Node *tree;
	Node *aux_node;
	Node *aux_node2;
	Node *aux_node3;
	int flag=1;
%}

%union{
	char * string;
	struct node *node;
}

%token BOOL
%token BOOLLIT
%token CLASS
%token DO
%token DOTLENGTH
%token DOUBLE
%token ELSE
%token IF
%token INT
%token PARSEINT
%token PRINT
%token PUBLIC
%token RETURN 
%token STATIC
%token STRING
%token VOID 
%token WHILE
%token OCURV
%token CCURV
%token OBRACE
%token CBRACE
%token OSQUARE
%token CSQUARE
%token AND
%token OR
%token LT 
%token GT
%token EQ
%token NEQ
%token LEQ
%token GEQ
%token PLUS
%token MINUS
%token STAR
%token DIV
%token MOD
%token NOT
%token ASSIGN
%token SEMI
%token COMMA
%token <string> RESERVED
%token NEWLINE
%token <string> STRLIT
%token <string> DECLIT
%token <string> REALLIT
%token <string> ID
%type <node> Empty

%type <node> Program
%type <node> SubProgram
%type <node> FieldDecl
%type <node> SubFieldDecl
%type <node> MethodDecl
%type <node> MethodHeader
%type <node> MethodBody
%type <node> SubMethodBody
%type <node> FormalParams
%type <node> SubFormalParams
%type <node> VarDecl
%type <node> SubVarDecl
%type <node> Type
%type <node> Statement
%type <node> MultipleStatements
%type <node> ExprStrlit
%type <node> OptAMIPA
%type <node> OptExpr
%type <node> Assignment
%type <node> MethodInvocation
%type <node> MultipleCommaExpr
%type <node> OptExprCommaExprs
%type <node> ParseArgs
%type <node> OptDotLength
%type <node> Expr
%type <node> Expre


%left COMMA
%right ASSIGN
%left OR
%left AND
%left EQ NEQ
%left GEQ LEQ GT LT
%left PLUS MINUS
%left STAR DIV MOD 

%right NOT
%left OCURV CCURV OBRACE CBRACE OSQUARE CSQUARE 

%right ELSE

%%

Program: CLASS ID OBRACE SubProgram CBRACE  {$$=tree=create_node(NODE_Program);

	   aux_node = create_node(NODE_Id);
	   aux_node->value = $2; 
	   insert_child($$,aux_node);
	   insert_brother(aux_node,$4);	   
//	   printf("GFEEFEF\n");
}
	   ; 
   										
SubProgram: Empty {$$= NULL;}
		  | SubProgram FieldDecl {$$ = $2;}
		  | SubProgram MethodDecl {$$ = $2;}
		  | SubProgram SEMI {$$ = NULL;}
		  ;
FieldDecl: PUBLIC STATIC Type ID SubFieldDecl SEMI {$$ = $5;
		printf("$$ nulo fielddecl\n");
		
		insert_child($$,create_node(NODE_FieldDecl));
		printf("$$ nulo fielddecl\n");
		aux_node = create_node(NODE_Id);
		aux_node->value = $4;
		insert_brother($$->child,aux_node);
		printf("FieldDecl b4 type\n");
		change_type($$,$5);
		printf("FieldDecl fim\n");
}
	| error SEMI {$$=NULL;}
	;
SubFieldDecl: SubFieldDecl COMMA ID {
			$1 = create_node(NODE_FieldDecl);
			aux_node = create_node(NODE_Comp);
			insert_child($1,aux_node);		
			aux_node2 = create_node(NODE_Id);
			aux_node2->value = $3;
			insert_brother($1->child,aux_node2);
			$$ = $1;
}
			

			| Empty {$$ = create_node(NODE_FieldDecl);}
			;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody {$$=create_node(NODE_MethodDecl);
		insert_child($$,$3);
		insert_brother($$->child,$4);
}
		  ;

MethodHeader: Type ID OCURV FormalParams CCURV {$$ = create_node(NODE_MethodHeader);
			insert_child($$,$1);
			aux_node = create_node(NODE_Id);
			aux_node->value = $2;
			insert_brother($$->child,aux_node);			
			aux_node3 = create_node(NODE_MethodParams);		
			insert_brother($$->child->brother,aux_node3);
			if($4->child != NULL){
				insert_child($$->child->brother->brother,$4);
			}

			
}
            | VOID ID OCURV FormalParams CCURV {$$ = create_node(NODE_MethodHeader);
			aux_node = create_node(NODE_Void);
			insert_child($$,aux_node);
			aux_node2 = create_node(NODE_Id);
			aux_node2->value = $2;
			insert_brother($$->child,aux_node2);
			aux_node3 = create_node(NODE_MethodParams);
			insert_brother($$->child->brother,aux_node3);
			if($4->child != NULL){
				insert_child($$->child->brother->brother,$4);
			}
}
	    ;

MethodBody: OBRACE SubMethodBody CBRACE {
			$$ = $2;}
	  ;

SubMethodBody: SubMethodBody VarDecl {
			if($$->child == NULL){
				insert_child($$,$2);
			}
			else{
				insert_brother($$->child,$2);
			}
}
			 | SubMethodBody Statement {$$=$2;}
			 | Empty {$$ = create_node(NODE_MethodBody);}
			 ;


FormalParams:  Type ID SubFormalParams {
			//$$ = create_node(NODE_ParamDecl);
			$$ = $3;	
			insert_child($$,$1);
			aux_node = create_node(NODE_Id);
			aux_node->value = $2;
			insert_brother($$->child,aux_node);
			//insert_brother($$,$3);


}
    | STRING OSQUARE CSQUARE ID {$$ = create_node(NODE_ParamDecl);
				aux_node = create_node(NODE_StringArray);
				insert_child($$,aux_node);
				aux_node2 = create_node(NODE_Id);
				aux_node2->value = $4;
				insert_brother($$->child,aux_node2);
				
}
	|Empty {$$ = create_node(NODE_ParamDecl);}
	;
	


SubFormalParams:  SubFormalParams COMMA Type ID {
				$1 = create_node(NODE_ParamDecl);
				insert_child($1,$3);
				aux_node = create_node(NODE_Id);
				aux_node->value = $4;
				insert_brother($1->child,aux_node);
			   	insert_brother($$,$1);
}
				|Empty {$$ = create_node(NODE_ParamDecl);}
			   
			   ;

VarDecl: Type ID SubVarDecl SEMI {
				// $$ = $3;
				// insert_brother($3->child,$1);
				// aux_node = create_node(NODE_Id);
				// aux_node->value = $2;
				// insert_brother($$->child,aux_node);
				$$ = create_node(NODE_VarDecl);
				insert_child($$,$1);
				aux_node = create_node(NODE_Id);
				aux_node->value = $2;
				insert_brother($$->child,aux_node);
				if($3->child != NULL){
					insert_brother($$,$3);
					change_type($$,$3);
				}
};

SubVarDecl: COMMA ID SubVarDecl {
				$$ = create_node(NODE_VarDecl);
				aux_node2 = create_node(NODE_Comp);
				insert_child($$,aux_node2);
				aux_node = create_node(NODE_Id);
				aux_node->value = $2;
				insert_brother($$->child,aux_node);
				if($3->child != NULL){
					insert_brother($$,$3);
				}
}
			| Empty {
				$$ = create_node(NODE_VarDecl);
			};

Type: BOOL {$$=create_node(NODE_Bool);}
	| INT  {$$=create_node(NODE_Int);}
	| DOUBLE {$$=create_node(NODE_Double);}
	;

Statement: OBRACE MultipleStatements CBRACE {$$=NULL;}
    | IF OCURV Expr CCURV Statement ELSE Statement {$$=NULL;
    	// $$=create_node(Node_If);
    	// insert_child($$,$3);
    	// insert_brother($3,$5);
    	// insert_brother($3,$7);
}
    | IF OCURV Expr CCURV Statement %prec ELSE {$$=NULL;
    	// $$=create_node(Node_If);
    	// insert_child($$,$3);
    	// insert_brother($3,$5);
}
    | WHILE OCURV Expr CCURV Statement {$$=NULL;
    	// $$=create_node(Node_While);
    	// insert_child($$,$3);
    	// insert_brother($3,$5);
}
    | DO Statement WHILE OCURV Expr CCURV SEMI {$$=NULL;
    	// $$=create_node(Node_DoWhile);
    	// insert_child($$,$2);
    	// insert_brother($2,$5);
}
    | PRINT OCURV ExprStrlit CCURV SEMI {$$=NULL;
		// $$=create_node(Node_Print);
		// insert_child($$,$3);
}
    | OptAMIPA SEMI {//$$=$1;
    	$$=NULL;}
    | RETURN OptExpr SEMI {//$$=$2;
    	$$=NULL;}
    | error SEMI {//$$=NULL;
    	$$=NULL;}
	;


MultipleStatements: Empty {$$=NULL;}
				  | Statement MultipleStatements {$$=NULL;}
				  ;


ExprStrlit: Expr {$$=$1;}
		  | STRLIT {$$=create_node(NODE_StrLit);}
		  ;

OptAMIPA: Assignment {$$=create_node(NODE_Assign);}
		| MethodInvocation {$$=$1;}
		| ParseArgs {$$=$1;}
		| Empty {$$=NULL;}
		;

OptExpr: Expr {$$=$1;}
	   | Empty {$$=NULL;}
	   ;

Assignment: ID ASSIGN Expr {$$=NULL;}
	;

MethodInvocation: ID OCURV OptExprCommaExprs CCURV {$$=NULL;}
    | ID OCURV error CCURV {$$=NULL;}
	;

MultipleCommaExpr: Empty {$$=NULL;}
				 | MultipleCommaExpr COMMA Expr {$$=NULL;}
				 ;
OptExprCommaExprs: Expr MultipleCommaExpr {$$=NULL;}
				 | Empty {$$=NULL;}
				 ;

ParseArgs: PARSEINT OCURV ID OSQUARE Expr CSQUARE CCURV {$$=NULL;}
    | PARSEINT OCURV error CCURV {$$=NULL;syn_error=1;}
	;

OptDotLength: DOTLENGTH {$$=NULL;}
			| Empty {$$=NULL;}
			;	

Expr: Assignment {$$=NULL;}
	| Expre {$$=NULL;}
	;

Expre: MethodInvocation {$$=NULL;}
	| ParseArgs {$$=NULL;}
    | Expre AND Expre {$$=NULL;}
    | Expre OR Expre {$$=NULL;}
    | Expre EQ Expre {$$=NULL;}
    | Expre GEQ Expre {$$=NULL;}
    | Expre GT Expre {$$=NULL;}
    | Expre LEQ Expre {$$=NULL;}
    | Expre LT Expre {$$=NULL;}
    | Expre NEQ Expre {$$=NULL;}
    | Expre MINUS Expre {$$=NULL;}
    | Expre PLUS Expre {$$=NULL;}
    | Expre STAR Expre {$$=NULL;}
    | Expre DIV Expre {$$=NULL;}
    | Expre MOD Expre {$$=NULL;}
    | PLUS Expre {$$=NULL;}
    | MINUS Expre  {$$=NULL;}
    | NOT Expre {$$=NULL;}
    | ID OptDotLength {$$=NULL;} 
    | OCURV Expr CCURV {$$=NULL;}
    | OCURV error CCURV {$$=NULL;}
    | BOOLLIT {$$=NULL;}
	| DECLIT {$$=NULL;} 
	| REALLIT {$$=NULL;}

	;


Empty: {;} 
	 ; 

%%

void yyerror (const char *s){
	syn_error++;
	printf ("Line %d, col %d: %s: %s\n",num_line, (int)(num_col- strlen(yytext)), s, yytext);
}



