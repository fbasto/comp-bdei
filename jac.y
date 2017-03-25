%{
    #include <stdio.h>
    #include "string.h"
    #include "y.tab.h"
    int yylex(void);
	extern int num_line;
	extern int num_col;
	extern char * yytext;
    void yyerror (const char *s);
	int flag=1;
%}

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
%token RESERVED
%token NEWLINE
%token STRLIT
%token DECLIT
%token REALLIT
%token ID


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



%%

Program: CLASS ID OBRACE SubProgram CBRACE
SubProgram: SubProgram FieldDecl | SubProgram MethodDecl | SubProgram SEMI | %empty

FieldDecl: PUBLIC STATIC Type ID SubFieldDecl SEMI
SubFieldDecl: SubFieldDecl COMMA ID | %empty

MethodDecl: PUBLIC STATIC MethodHeader MethodBody
MethodHeader: Type ID OCURV OptFormalParams CCURV
OptFormalParams: FormalParams | %empty

MethodBody: OBRACE SubMethodBody CBRACE
SubMethodBody: SubMethodBody VarDecl | SubMethodBody Statement | %empty


FormalParams: Type ID SubFormalParams
    | STRING OSQUARE CSQUARE ID
SubFormalParams: SubFormalParams COMMA Type ID | %empty

VarDecl: Type ID SubVarDecl SEMI
SubVarDecl: COMMA ID SubVarDecl | %empty

Type: BOOL | INT | DOUBLE

Statement: OBRACE MultipleStatements CBRACE
    | IF OCURV Expr CCURV Statement OptElseStatement
    | WHILE OCURV Expr CCURV Statement
    | DO Statement WHILE OCURV Expr CCURV SEMI
    | PRINT OCURV ExprStrlit CCURV SEMI
    | OptAMIPA SEMI
    | RETURN OptExpr SEMI
MultipleStatements: Statement MultipleStatements | %empty
OptElseStatement: ELSE Statement | %empty
ExprStrlit: Expr | STRLIT
OptAMIPA: Assignment | MethodInvocation | ParseArgs | %empty
OptExpr: Expr | %empty

Assignment: ID ASSIGN Expr

MethodInvocation: ID OCURV OptExprCommaExprs CCURV
MultipleCommaExpr: MultipleCommaExpr COMMA Expr | %empty
OptExprCommaExprs: MultipleCommaExpr Expr | %empty

ParseArgs: PARSEINT OCURV ID OSQUARE Expr CSQUARE CCURV

OptDotLength: DOTLENGTH | %empty

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
    | BOOLLIT | DECLIT | REALLIT



%%

void yyerror (const char *s){
	printf ("Line %d, col %d: %s: %s\n",num_line, (int)(num_col- strlen(yytext)+1), s, yytext);
}
