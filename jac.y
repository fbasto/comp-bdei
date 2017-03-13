%{
    #include <stdio.h>
    int yylex(void);
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

%left '+' '-'
%left '*' '/'

%right '('
%left ')'



%%

Program: CLASS ID OBRACE SubProgram CBRACE
SubProgram: (FieldDecl | MethodDecl | SEMI) SubProgram | %empty

FieldDecl: PUBLIC STATIC Type ID SubFieldDecl SEMI
SubFieldDecl: COMMA ID SubFieldDecl | %empty

MethodDecl: PUBLIC STATIC MethodHeader MethodBody

MethodBody: OBRACE SubMethodBody CBRACE
SubMethodBody: ( VarDecl | Statement ) SubMethodBody | %empty


FormalParams: Type ID SubFormalParams
    | STRING OSQUARE CSQUARE ID
SubFormalParams: COMMA Type ID SubFormalParams | %empty

VarDecl: Type ID SubVarDecl SEMI
SubVarDecl: COMMA ID SubVarDecl | %empty

Type: BOOL | INT | DOUBLE

Statement: OBRACE MultipleStatements CBRACE
    | IF OCURV Expr CCURV Statement OptElseStatement
    | WHILE OCURV Expr CCURV Statement
    | DO Statement WHILE OCURV Expr CCURV SEMI
    | PRINT OCURV ( Expr | STRLIT ) CCURV SEMI
    | OptAMIPA SEMI
    | RETURN OptExpr SEMI
MultipleStatements: Statement MultipleStatements | %empty
OptElseStatement: ELSE Statement | %empty
OptAMIPA: ( Assignment | MethodInvocation | ParseArgs ) | %empty
OptExpr: Expr | %empty

Assignment: ID ASSIGN Expr

MethodInvocation: ID OCURV OptExprCommaExprs CCURV
MultipleCommaExpr: (COMMA Expr)MultipleCommaExpr | %empty
OptExprCommaExprs: Expr MultipleCommaExpr | %empty

ParseArgs: PARSEINT OCURV ID OSQUARE Expr CSQUARE CCURV

Expr: Assignment | MethodInvocation | ParseArgs
    | Expr ( AND | OR ) Expr
    | Expr ( EQ | GEQ | GT | LEQ | LT | NEQ ) Expr
    | ( PLUS | MINUS | NOT ) Expr
    | ID [ DOTLENGTH ]
    | OCURV Expr CCURV
    | BOOLLIT | DECLIT | REALLIT


calc: calc expression NEWLINE                        {printf("%d\n", $2);}
	| {;}
	;

expression: expression '+' expression   {$$=$1+$3;}
    |   expression '-' expression       {$$=$1-$3;}
    |   expression '-''-' expression      {$$=$1+$4;}
    |   '-' expression			{$$=-$2;}
    |   expression '*' expression       {$$=$1*$3;}
    |   expression '/' expression       {if($3==0){yyerror("Divide by zero");return 1;}$$=$1/$3;}
    |   '(' expression ')'		{$$=$2;}
    |   NUMBER                          {$$=$1;}
    ;

%%

int main() {
	yyparse();
	return 0;
}
