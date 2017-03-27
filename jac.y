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
	Node * tree = NULL;
	Node *aux_node = NULL;
	int syntax_errors=0;
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

Program: CLASS ID OBRACE SubProgram CBRACE  {$$ = insert_node(NODE_Program);
	  aux_node = insert_leaf_node(NODE_Id,$2);
	  insert_child($$,aux_node);
	  insert_child($$,$4); 
}
	   ; 
   										
SubProgram: Empty {;}
		  | SubProgram FieldDecl {$$ = $2;}
		  | SubProgram MethodDecl {$$ = $2;}
		  | SubProgram SEMI {;}
		  ;
FieldDecl: PUBLIC STATIC Type ID SubFieldDecl SEMI {$$ = insert_node(NODE_FieldDecl);
	insert_child($$,$3);		 
	insert_brother($$,insert_leaf_node(NODE_Id,$4));

}
	| error SEMI {syntax_errors++;}
	;
SubFieldDecl: Empty {;}
			| SubFieldDecl COMMA ID {$1 = insert_node(NODE_FieldDecl);
			insert_child($1,$$->child);
}
			;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody {;}
		  ;

MethodHeader: Type ID OCURV OptFormalParams CCURV {;}
            | VOID ID OCURV OptFormalParams CCURV {;}
	    ;


OptFormalParams: FormalParams {;}
			   | Empty {;}
			   ;
MethodBody: OBRACE SubMethodBody CBRACE {;}
		  ;
SubMethodBody: Empty {;}
			 | SubMethodBody VarDecl {;}
			 | SubMethodBody Statement {;}
			 ;


FormalParams: Type ID SubFormalParams {;}
    | STRING OSQUARE CSQUARE ID {;}
	;


SubFormalParams: Empty {;}
			   | SubFormalParams COMMA Type ID {;}
			   ;

VarDecl: Type ID SubVarDecl SEMI {;}
SubVarDecl: Empty {;}
		  | COMMA ID SubVarDecl {;}
	      ;

Type: BOOL {;}
	| INT {;}
	| DOUBLE {;}
	;

Statement: OBRACE MultipleStatements CBRACE {;}
    | IF OCURV Expr CCURV Statement ELSE Statement {;}
    | IF OCURV Expr CCURV Statement %prec ELSE {;}
    | WHILE OCURV Expr CCURV Statement {;}
    | DO Statement WHILE OCURV Expr CCURV SEMI {;}
    | PRINT OCURV ExprStrlit CCURV SEMI {;}
    | OptAMIPA SEMI {;}
    | RETURN OptExpr SEMI {;}
    | error SEMI {syntax_errors++;}
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
    | ID OCURV error CCURV {syntax_errors++;}
	;

MultipleCommaExpr: Empty {;}
				 | MultipleCommaExpr COMMA Expr {;}
				 ;
OptExprCommaExprs: Expr MultipleCommaExpr {;}
				 | Empty {;}
				 ;

ParseArgs: PARSEINT OCURV ID OSQUARE Expr CSQUARE CCURV {;}
    | PARSEINT OCURV error CCURV {syntax_errors++;}
	;

OptDotLength: DOTLENGTH {;}
			| Empty {;}
			;	

Expr: Assignment {;}
	| MethodInvocation {;}
	| ParseArgs {;}
    | Expr AND Expr {;}
    | Expr OR Expr {;}
    | Expr EQ Expr {;}
    | Expr GEQ Expr {;}
    | Expr GT Expr {;}
    | Expr LEQ Expr {;}
    | Expr LT Expr {;}
    | Expr NEQ Expr {;}
    | PLUS Expr {;}
    | MINUS Expr {;}
    | NOT Expr {;}
    | ID OptDotLength {;} 
    | OCURV Expr CCURV {;}
    | OCURV error CCURV {syntax_errors++;}
    | BOOLLIT {;}
	| DECLIT {;} 
	| REALLIT {;}
	;


Empty: {;} 
	 ; 

%%

void yyerror (const char *s){
	syntax_errors++;
	printf ("Line %d, col %d: %s: %s\n",num_line, (int)(num_col- strlen(yytext)), s, yytext);
}


