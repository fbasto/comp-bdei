%{
    #include <stdio.h>
	#include <stdlib.h>
    #include "string.h"
    #include "y.tab.h"
	#include "ast.h"
    int yylex(void);
	extern int num_line;
	extern int num_col;
	extern char * yytext;
	extern Node * tree;
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

%type <node> Program SubProgram FieldDecl SubFieldDecl MethodDecl MethodHeader OptFormalParams MethodBody SubMethodBody FormalParams SubFormalParams VarDecl SubVarDecl Type Statement MultipleStatements ExprStrlit OptAMIPA OptExpr Assignment MethodInvocation MultipleCommaExpr OptExprCommaExprs ParseArgs OptDotLength Expr Empty 




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

Program: CLASS ID OBRACE SubProgram CBRACE												
SubProgram: Empty | SubProgram FieldDecl | SubProgram MethodDecl | SubProgram SEMI

FieldDecl: PUBLIC STATIC Type ID SubFieldDecl SEMI
	| error SEMI
SubFieldDecl: Empty | SubFieldDecl COMMA ID

MethodDecl: PUBLIC STATIC MethodHeader MethodBody
MethodHeader: Type ID OCURV OptFormalParams CCURV
OptFormalParams: FormalParams | Empty

MethodBody: OBRACE SubMethodBody CBRACE
SubMethodBody: Empty | SubMethodBody VarDecl | SubMethodBody Statement


FormalParams: Type ID SubFormalParams
    | STRING OSQUARE CSQUARE ID
SubFormalParams: Empty | SubFormalParams COMMA Type ID

VarDecl: Type ID SubVarDecl SEMI
SubVarDecl: Empty | COMMA ID SubVarDecl

Type: BOOL | INT | DOUBLE

Statement: OBRACE MultipleStatements CBRACE
    | IF OCURV Expr CCURV Statement ELSE Statement
    | IF OCURV Expr CCURV Statement %prec ELSE
    | WHILE OCURV Expr CCURV Statement
    | DO Statement WHILE OCURV Expr CCURV SEMI
    | PRINT OCURV ExprStrlit CCURV SEMI
    | OptAMIPA SEMI
    | RETURN OptExpr SEMI
    | error SEMI
MultipleStatements: Empty | Statement MultipleStatements
ExprStrlit: Expr | STRLIT
OptAMIPA: Assignment | MethodInvocation | ParseArgs | Empty
OptExpr: Expr | Empty

Assignment: ID ASSIGN Expr

MethodInvocation: ID OCURV OptExprCommaExprs CCURV
    | ID OCURV error CCURV
MultipleCommaExpr: Empty | MultipleCommaExpr COMMA Expr
OptExprCommaExprs: Expr MultipleCommaExpr | Empty

ParseArgs: PARSEINT OCURV ID OSQUARE Expr CSQUARE CCURV
    | PARSEINT OCURV error CCURV

OptDotLength: DOTLENGTH | Empty

Expr: Assignment | MethodInvocation | ParseArgs
    | Expr AND Expr
    | Expr OR Expr
    | Expr EQ Expr
    | Expr GEQ Expr
    | Expr GT Expr
    | Expr LEQ Expr
    | Expr LT Expr
    | Expr NEQ Expr
    | PLUS Expr
    | MINUS Expr
    | NOT Expr
    | ID OptDotLength
    | OCURV Expr CCURV
    | OCURV error CCURV
    | BOOLLIT | DECLIT | REALLIT



Empty: ;

%%

void yyerror (const char *s){
	printf ("Line %d, col %d: %s: %s\n",num_line, (int)(num_col- strlen(yytext)+1), s, yytext);
}


