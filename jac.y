%{
    #include <stdio.h>
    int yylex(void);
    void yyerror (const char *s);
	int flag=1;
%}

%token NUMBER
%token NEWLINE
%token END //opçao 2

%left '+' '-'
%left '*' '/'

%right '('
%left ')'


%%

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
