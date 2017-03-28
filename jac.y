%{
    #include <stdio.h>
	#include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"
	#include "header.h"
    int yylex(void);
    void yyerror (const char *s);

	extern int num_line;
	extern int num_col;
	extern char * yytext;
	Node * tree;
	Node *aux_node;
	Node *aux_node2;
	Node *aux_node3;
	int syntax_errors=0;
	int flag=1;
%}

%union{
	char * string;
	struct node * node;
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
%type <node> OptFormalParams
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

Program: CLASS ID OBRACE SubProgram CBRACE  {$$ = tree = create_node(NODE_Program);
	 aux_node = create_node(NODE_Id);
	 aux_node->value = $2;
	 
	 insert_brother(aux_node,$4);
	 insert_child($$,aux_node);  
	
}
	   ; 
   										
SubProgram: Empty {$$=NULL;}
		  | SubProgram FieldDecl {$$ = $2;}
		  | SubProgram MethodDecl {$$=NULL;}
		  | SubProgram SEMI {$$=NULL;}
		  ;
FieldDecl: PUBLIC STATIC Type ID SubFieldDecl SEMI {$$ =$5; 	
		insert_child($$,$3);
		aux_node =create_node(NODE_Id);
		aux_node->value=$4;
		insert_brother($3,aux_node);		 
		change_type($$,$5);
		/*if ($3->brother != NULL){
		}*/
}

	| error SEMI {syntax_errors++;$$=NULL;}
	;
SubFieldDecl: Empty {$$=create_node(NODE_FieldDecl);}
			| SubFieldDecl COMMA ID {$1 = create_node(NODE_FieldDecl);
				aux_node = create_node(NODE_Comp);
				insert_child($1,aux_node);
				aux_node3 = create_node(NODE_Id);
				aux_node3->value = $3;
				insert_brother(aux_node,aux_node3);
				insert_brother($$,$1);
}
			;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody {$$ = NULL;}

		  ;

MethodHeader: Type ID OCURV OptFormalParams CCURV {$$=NULL;}
            | VOID ID OCURV OptFormalParams CCURV {$$=NULL;}
	    ;


OptFormalParams: FormalParams {$$ = NULL;}
			   | Empty {$$=NULL;}
			   ;
MethodBody: OBRACE SubMethodBody CBRACE {$$=NULL;}
		  ;
SubMethodBody: Empty {$$=NULL;}
			 | SubMethodBody VarDecl {$$ = NULL;}
			 | SubMethodBody Statement {$$=NULL;}
			 ;


FormalParams: Type ID SubFormalParams {$$=NULL;}
    | STRING OSQUARE CSQUARE ID {$$=NULL;}
	;


SubFormalParams: Empty {$$=NULL;}
			   | SubFormalParams COMMA Type ID {$$=NULL;}
			   ;

VarDecl: Type ID SubVarDecl SEMI {$$=NULL;}
SubVarDecl: Empty {$$=NULL;}
		  | COMMA ID SubVarDecl {$$=NULL;}
	      ;

Type: BOOL {$$=NULL;}
	| INT {$$=create_node(NODE_Int);}
	| DOUBLE {$$=NULL;}
	;

Statement: OBRACE MultipleStatements CBRACE {$$=NULL;}
    | IF OCURV Expr CCURV Statement ELSE Statement {$$=NULL;}
    | IF OCURV Expr CCURV Statement %prec ELSE {$$=NULL;}
    | WHILE OCURV Expr CCURV Statement {$$=NULL;}
    | DO Statement WHILE OCURV Expr CCURV SEMI {$$=NULL;}
    | PRINT OCURV ExprStrlit CCURV SEMI {$$=NULL;}
    | OptAMIPA SEMI {$$=NULL;}
    | RETURN OptExpr SEMI {$$=NULL;}
    | error SEMI {syntax_errors++;$$=NULL;}
	;


MultipleStatements: Empty {$$=NULL;}
				  | Statement MultipleStatements {$$=NULL;}
				  ;


ExprStrlit: Expr {$$=NULL;}
		  | STRLIT {$$=NULL;}
		  ;

OptAMIPA: Assignment {$$=NULL;}
		| MethodInvocation {$$=NULL;}
		| ParseArgs {$$=NULL;}
		| Empty {$$=NULL;}
		;

OptExpr: Expr {$$=NULL;}
	   | Empty {$$=NULL;}
	   ;

Assignment: ID ASSIGN Expr {$$=NULL;}
	;

MethodInvocation: ID OCURV OptExprCommaExprs CCURV {$$=NULL;}
    | ID OCURV error CCURV {syntax_errors++;$$=NULL;}
	;

MultipleCommaExpr: Empty {$$=NULL;}
				 | MultipleCommaExpr COMMA Expr {$$=NULL;}
				 ;
OptExprCommaExprs: Expr MultipleCommaExpr {$$=NULL;}
				 | Empty {$$=NULL;}
				 ;

ParseArgs: PARSEINT OCURV ID OSQUARE Expr CSQUARE CCURV {$$=NULL;}
    | PARSEINT OCURV error CCURV {syntax_errors++;}
	;

OptDotLength: DOTLENGTH {$$=NULL;}
			| Empty {$$=NULL;}
			;	

Expr: Assignment {$$=NULL;}
	| Expre {$$ = NULL;}
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
    | Expre STAR Expre {$$=NULL;}
    | Expre MINUS Expre {$$=NULL;}
    | Expre PLUS Expre {$$=NULL;}
    | PLUS Expre {$$=NULL;}
    | MINUS Expre  {$$=NULL;}
    | NOT Expre {$$=NULL;}
    | ID OptDotLength {$$=NULL;} 
    | OCURV Expr CCURV {$$=NULL;}

    | OCURV error CCURV {syntax_errors++;$$=NULL;}
    | BOOLLIT {$$=NULL;}
	| DECLIT {$$=NULL;} 
	| REALLIT {$$=NULL;}
	;


Empty: {$$=NULL;} 
	 ; 

%%

void yyerror (const char *s){
	printf ("Line %d, col %d: %s: %s\n",num_line, (int)(num_col- strlen(yytext)), s, yytext);
}


