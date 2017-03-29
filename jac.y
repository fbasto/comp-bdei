%{
    #include <stdio.h>
	#include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"
	#include "header.h"
//	#include "ast.h"
    int yylex(void);
	extern int num_line;
	extern int num_col;
	extern char *yytext;
	Node *tree;
	Node *aux_node;
	Node *aux_node2;
	Node *aux_node3;
    void yyerror (const char *s);
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
}
	   ; 
   										
SubProgram: Empty {;}
		  | SubProgram FieldDecl {$$ = $2;}
		  | SubProgram MethodDecl {$$ = $2;}
		  | SubProgram SEMI {;}
		  ;
FieldDecl: PUBLIC STATIC Type ID SubFieldDecl SEMI {$$ = $5;
		if($3==NULL){
			printf("$$ nulo fielddecl\n");
		}
		insert_child($$,$3);
		//printf("$$ nulo fielddecl\n");
		aux_node = create_node(NODE_Id);
		aux_node->value = $4;
		insert_brother($5->child,aux_node);
		insert_brother($$,$5);
		//printf("FieldDecl b4 type\n");
		change_type($$,$5);
		//printf("FieldDecl fim\n");
}
	| error SEMI {$$=NULL;}
	;
SubFieldDecl:Empty {$$ = create_node(NODE_FieldDecl);}
			| SubFieldDecl COMMA ID {$1 = create_node(NODE_FieldDecl);
			aux_node = create_node(NODE_Comp);
			insert_child($1,aux_node);
			aux_node2 = create_node(NODE_Id);
			aux_node->value = $3;
			insert_brother($1->child,aux_node2);
			//printf("SubFieldDecl fim\n");
}
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
			insert_brother($$->child->brother,$4);
}
            | VOID ID OCURV FormalParams CCURV {$$ = create_node(NODE_MethodHeader);
			aux_node = create_node(NODE_Void);
			insert_child($$,aux_node);
			aux_node2 = create_node(NODE_Id);
			aux_node2->value = $2;
			insert_brother($$->child,aux_node2);
			insert_brother($$->child,$4);
}
	    ;

MethodBody: OBRACE SubMethodBody CBRACE {;}
		  ;
SubMethodBody: Empty {;}
			 | SubMethodBody VarDecl {;}
			 | SubMethodBody Statement {;}
			 ;


FormalParams: Empty {$$ = create_node(NODE_MethodParams);}
	| Type ID SubFormalParams {$$ = create_node(NODE_MethodParams);
			aux_node = create_node(NODE_ParamDecl);
			insert_child($3,aux_node);
			insert_child($3->child,$1);
			aux_node2 = create_node(NODE_Id);
			aux_node2->value;
			insert_brother($3->child->child,aux_node2);

}
    | STRING OSQUARE CSQUARE ID {$$ = create_node(NODE_MethodParams);
			aux_node = create_node(NODE_ParamDecl);
			insert_child($$,aux_node);			
			aux_node2 = create_node(NODE_StringArray);
			insert_child($$->child,aux_node);
			aux_node3 = create_node(NODE_Id);
			aux_node3->value = $4;
			insert_brother($$->child->child,aux_node2);
}
	;


SubFormalParams: Empty {$$ = create_node(NODE_ParamDecl);}
			   | SubFormalParams COMMA Type ID {$1 = create_node(NODE_ParamDecl);
				insert_child($1,$3);
				aux_node = create_node(NODE_Id);
				aux_node->value = $4;
				insert_child($1->child,aux_node);

}
			   ;

VarDecl: Type ID SubVarDecl SEMI {;}
SubVarDecl: Empty {;}
		  | COMMA ID SubVarDecl {;}
	      ;

Type: BOOL {$$=create_node(NODE_Bool);}
	| INT  {$$=create_node(NODE_Int);}
	| DOUBLE {$$=create_node(NODE_Double);}
	;

Statement: OBRACE MultipleStatements CBRACE {;}
    | IF OCURV Expr CCURV Statement ELSE Statement {;}
    | IF OCURV Expr CCURV Statement %prec ELSE {;}
    | WHILE OCURV Expr CCURV Statement {;}
    | DO Statement WHILE OCURV Expr CCURV SEMI {;}
    | PRINT OCURV ExprStrlit CCURV SEMI {;}
    | OptAMIPA SEMI {;}
    | RETURN OptExpr SEMI {;}
    | error SEMI {$$=NULL;}
	;


MultipleStatements: Empty {;}
				  | Statement MultipleStatements {;}
				  ;


ExprStrlit: Expr {;}
		  | STRLIT {;}
		  ;

OptAMIPA: Assignment {;}
		| MethodInvocation {;}
		| ParseArgs {;}
		| Empty {;}
		;

OptExpr: Expr {;}
	   | Empty {;}
	   ;

Assignment: ID ASSIGN Expr {;}
	;

MethodInvocation: ID OCURV OptExprCommaExprs CCURV {;}
    | ID OCURV error CCURV {$$=NULL;}
	;

MultipleCommaExpr: Empty {;}
				 | MultipleCommaExpr COMMA Expr {;}
				 ;
OptExprCommaExprs: Expr MultipleCommaExpr {;}
				 | Empty {;}
				 ;

ParseArgs: PARSEINT OCURV ID OSQUARE Expr CSQUARE CCURV {;}
    | PARSEINT OCURV error CCURV {$$=NULL;}
	;

OptDotLength: DOTLENGTH {;}
			| Empty {;}
			;	

Expr: Assignment {;}
	| Expre {;}
	;

Expre: MethodInvocation {;}
	| ParseArgs {;}
    | Expre AND Expre {;}
    | Expre OR Expre {;}
    | Expre EQ Expre {;}
    | Expre GEQ Expre {;}
    | Expre GT Expre {;}
    | Expre LEQ Expre {;}
    | Expre LT Expre {;}
    | Expre NEQ Expre {;}
    | Expre MINUS Expre {;}
    | Expre PLUS Expre {;}
    | Expre STAR Expre {;}
    | Expre DIV Expre {;}
    | Expre MOD Expre {;}
    | PLUS Expre {;}
    | MINUS Expre  {;}
    | NOT Expre {;}
    | ID OptDotLength {;} 
    | OCURV Expr CCURV {;}
    | OCURV error CCURV {$$=NULL;}
    | BOOLLIT {;}
	| DECLIT {;} 
	| REALLIT {;}
	;


Empty: {;} 
	 ; 

%%

void yyerror (const char *s){
	printf ("Line %d, col %d: %s: %s\n",num_line, (int)(num_col- strlen(yytext)), s, yytext);
}


