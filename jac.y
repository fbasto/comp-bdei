%{
    #include <stdio.h>
	#include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"
//	#include "ast.h"
    int yylex(void);
	extern int num_line;
	extern int num_col;
	extern char * yytext;
	//extern Node * tree;
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

Program: CLASS ID OBRACE SubProgram CBRACE  {;}
	   ; 
   										
SubProgram: Empty {;}
		  | SubProgram FieldDecl {;}
		  | SubProgram MethodDecl {;}
		  | SubProgram SEMI {;}
		  ;
FieldDecl: PUBLIC STATIC Type ID SubFieldDecl SEMI {;}
	| error SEMI {;}
	;
SubFieldDecl: Empty {;}
			| SubFieldDecl COMMA ID {;}
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
    | error SEMI {;}
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
    | ID OCURV error CCURV {;}
	;

MultipleCommaExpr: Empty {;}
				 | MultipleCommaExpr COMMA Expr {;}
				 ;
OptExprCommaExprs: Expr MultipleCommaExpr {;}
				 | Empty {;}
				 ;

ParseArgs: PARSEINT OCURV ID OSQUARE Expr CSQUARE CCURV {;}
    | PARSEINT OCURV error CCURV {;}
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
    | Expre STAR Expre {;}
    | Expre MINUS Expre {;}
    | Expre PLUS Expre {;}
    | PLUS Expre {;}
    | MINUS Expre  {;}
    | NOT Expre {;}
    | ID OptDotLength {;} 
    | OCURV Expr CCURV {;}
    | OCURV error CCURV {;}
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


