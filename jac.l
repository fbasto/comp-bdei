%X COMMENT1
%X COMMENT2
%X STR
%{
	//podem faltar includes
	/*
		output=0 nao imprime
		output=1 imprime	
	*/
	#include "y.tab.h"
	#include "header.h"
	int yyparse();	
	extern Node *tree;
	extern int syn_error;
	//extern int syntax_errors;
	int output = 0;
	int num_line = 1;
	int num_col = 1;
	int aux_line;
	int aux_col;

	Table *symbol_table;
%}

ID 		([a-z]|[A-Z]|"_"|"$")+([a-z]|[A-Z]|"_"|"$"|[0-9])*
DECLIT		0|[1-9](\_+[0-9]|[0-9])*
ESCAPES		\\n|\\t|\\r|\\f|\\\"|\\\\
UNDEFESCAPES 	\\[^ntrf\"\\]

LINEB 	(\n)|(\r)|(\r\n)
STRLIT		"\""(([^"\\\n\r]|({ESCAPES}))*)"\""
REALLIT		(([0-9]+(([0-9]|_)*[0-9])*)\.((([0-9]+(([0-9]|_)*[0-9])*)(["e""E"][-+]?)([0-9]+(([0-9]|_)*[0-9])*))|([0-9]+(([0-9]|_)*[0-9])*)|(["e""E"][-+]?)([0-9]+(([0-9]|_)*[0-9])*))?)|((\.)([0-9]+(([0-9]|_)*[0-9])*)((["e""E"][-+]?)([0-9]+(([0-9]|_)*[0-9])*))?)|(([0-9]+(([0-9]|_)*[0-9])*)(["e""E"][-+]?([0-9]+(([0-9]|_)*[0-9])*)))

%%
"boolean"	{num_col=num_col+yyleng;if(output) printf("BOOL\n"); if(output==0){return BOOL;}}
"true"|"false"	{num_col=num_col+yyleng;if(output) printf("BOOLLIT(%s)\n",yytext);yylval.string = strdup(yytext); if(output==0){return BOOLLIT;}}
"class"		{num_col=num_col+yyleng;if(output) printf("CLASS\n"); if(output==0){return CLASS;}}
"do"		{num_col=num_col+yyleng;if(output) printf("DO\n"); if(output==0){return DO;}}
"double"	{num_col=num_col+yyleng;if(output) printf("DOUBLE\n"); if(output==0){return DOUBLE;}}
".length"	{num_col=num_col+yyleng;if(output) printf("DOTLENGTH\n"); if(output==0){return DOTLENGTH;}}
"else"		{num_col=num_col+yyleng;if(output) printf("ELSE\n"); if(output==0){return ELSE;}}
"if"		{num_col=num_col+yyleng;if(output) printf("IF\n"); if(output==0){return IF;}}
"int"		{num_col=num_col+yyleng;if(output) printf("INT\n"); if(output==0){return INT;}}
"Integer.parseInt"	{num_col=num_col+yyleng;if(output) printf("PARSEINT\n"); if(output==0){return PARSEINT;}}
"System.out.println"	{num_col=num_col+yyleng;if(output) printf("PRINT\n"); if(output==0){return PRINT;}}
"public"	{num_col=num_col+yyleng;if(output) printf("PUBLIC\n"); if(output==0){return PUBLIC;}}
"return"	{num_col=num_col+yyleng;if(output) printf("RETURN\n"); if(output==0){return RETURN;}}
"static"	{num_col=num_col+yyleng;if(output) printf("STATIC\n"); if(output==0){return STATIC;}}
"String"	{num_col=num_col+yyleng;if(output) printf("STRING\n"); if(output==0){return STRING;}}
"void"		{num_col=num_col+yyleng;if(output) printf("VOID\n"); if(output==0){return VOID;}}
"while"		{num_col=num_col+yyleng;if(output) printf("WHILE\n"); if(output==0){return WHILE;}}
"("		{num_col=num_col+yyleng;if(output) printf("OCURV\n"); if(output==0){return OCURV;}}
")"		{num_col=num_col+yyleng;if(output) printf("CCURV\n"); if(output==0){return CCURV;}}
"{"		{num_col=num_col+yyleng;if(output) printf("OBRACE\n"); if(output==0){return OBRACE;}}
"}"		{num_col=num_col+yyleng;if(output) printf("CBRACE\n"); if(output==0){return CBRACE;}}
"["		{num_col=num_col+yyleng;if(output) printf("OSQUARE\n"); if(output==0){return OSQUARE;}}
"]"		{num_col=num_col+yyleng;if(output) printf("CSQUARE\n"); if(output==0){return CSQUARE;}}
"&&"		{num_col=num_col+yyleng;if(output) printf("AND\n"); if(output==0){return AND;}}
"||"		{num_col=num_col+yyleng;if(output) printf("OR\n"); if(output==0){return OR;}}
"<"		{num_col=num_col+yyleng;if(output) printf("LT\n"); if(output==0){return LT;}}
">"		{num_col=num_col+yyleng;if(output) printf("GT\n"); if(output==0){return GT;}}	
"=="		{num_col=num_col+yyleng;if(output) printf("EQ\n"); if(output==0){return EQ;}}
"!="		{num_col=num_col+yyleng;if(output) printf("NEQ\n"); if(output==0){return NEQ;}}
"<="		{num_col=num_col+yyleng;if(output) printf("LEQ\n"); if(output==0){return LEQ;}}
">="		{num_col=num_col+yyleng;if(output) printf("GEQ\n"); if(output==0){return GEQ;}}
"+"		{num_col=num_col+yyleng;if(output) printf("PLUS\n"); if(output==0){return PLUS;}}
"-"		{num_col=num_col+yyleng;if(output) printf("MINUS\n"); if(output==0){return MINUS;}}
"*"		{num_col=num_col+yyleng;if(output) printf("STAR\n"); if(output==0){return STAR;}}
"/"		{num_col=num_col+yyleng;if(output) printf("DIV\n"); if(output==0){return DIV;}}
"%"		{num_col=num_col+yyleng;if(output) printf("MOD\n"); if(output==0){return MOD;}}
"!"		{num_col=num_col+yyleng;if(output) printf("NOT\n"); if(output==0){return NOT;}}
"="		{num_col=num_col+yyleng;if(output) printf("ASSIGN\n"); if(output==0){return ASSIGN;}}
";"		{num_col=num_col+yyleng;if(output) printf("SEMI\n"); if(output==0){return SEMI;}}
","		{num_col=num_col+yyleng;if(output) printf("COMMA\n"); if(output==0){return COMMA;}}
"abstract"|"assert"|"byte"|"break"|"case"|"catch"|"char"|"const"|"continue"|"default"|"enum"|"extends"|"final"|"finally"|"float"|"for"|"goto"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"package"|"private"|"protected"|"short"|"strictfp"|"super"|"switch"|"synchronized"|"this"|"throws"|"throw"|"transient"|"try"|"volatile"|"++"|"--"|"null"|"Integer"|"System"		{num_col=num_col+yyleng;if(output) printf("RESERVED(%s)\n",yytext); if(output==0){return RESERVED;}}



{ID}	 	{num_col=num_col+yyleng;if(output)printf("ID(%s)\n",yytext);yylval.string = strdup(yytext); if(output==0){return ID;}}
{STRLIT}	{num_col=num_col+yyleng;if(output)printf("STRLIT(%s)\n",yytext);yylval.string = strdup(yytext); if(output==0){return STRLIT;}}
{REALLIT}		{num_col=num_col+yyleng;if(output)printf("REALLIT(%s)\n",yytext);yylval.string = strdup(yytext); if(output==0){return REALLIT;}}
{DECLIT}		{num_col=num_col+yyleng;if(output)printf("DECLIT(%s)\n",yytext);yylval.string = strdup(yytext); if(output==0){return DECLIT;}}


"\""	{BEGIN STR;num_col=num_col+yyleng;aux_line = num_line; aux_col = (int)(num_col-yyleng);}
<STR>"\""	{BEGIN 0;num_col=num_col+yyleng;}
<STR>{ESCAPES}	{num_col=num_col+yyleng;}
<STR>\\{LINEB}	{BEGIN 0;num_col=num_col+yyleng;printf("Line %d, col %d: invalid escape sequence (\\)\n",num_line,(int)(num_col-yyleng));printf("Line %d, col %d: unterminated string literal\n",aux_line,aux_col);num_col=1;num_line++;}
<STR>{LINEB}			{ BEGIN 0;printf("Line %d, col %d: unterminated string literal\n", aux_line, aux_col) ; num_col=1; num_line++;}
<STR><<EOF>>	{num_col=num_col+yyleng;printf("Line %d, col %d: unterminated string literal\n",aux_line,aux_col);yyterminate();}
<STR>{UNDEFESCAPES}		{num_col=num_col+yyleng;printf("Line %d, col %d: invalid escape sequence (%s)\n",num_line,(int)(num_col-yyleng),yytext);}
<STR>.		{num_col=num_col+yyleng;}

"//"	{BEGIN COMMENT2;num_col=num_col+yyleng;}
<COMMENT2>"\n"	{BEGIN 0;num_col=1;num_line++;}
<COMMENT2>"\r"	{BEGIN 0;num_col=1;num_line++;}
<COMMENT2>"\r\n" {BEGIN 0;num_col=1;num_line++;}
<COMMENT2>.		{num_col=num_col+yyleng;}

"/*"	{BEGIN COMMENT1;num_col=num_col+yyleng;aux_line = num_line; aux_col = (int)(num_col-yyleng);}
<COMMENT1>"*/"			{num_col=num_col+yyleng;BEGIN 0;}
<COMMENT1>\n			{num_col=1;num_line++;}
<COMMENT1>\r			{num_col=1;num_line++;}
<COMMENT1>\r\n		{num_col=1;num_line++;}
<COMMENT1><<EOF>>		{printf("Line %d, col %d: unterminated comment\n",aux_line,aux_col);yyterminate();}
<COMMENT1>.				{num_col=num_col+yyleng;}

{LINEB}		{num_col=1;num_line++;}
"\t"		{num_col=num_col+yyleng;}
"\f"		{num_col=num_col+yyleng;}
" "	    	{num_col=num_col+1;}
.		{num_col=num_col+yyleng;printf("Line %d, col %d: illegal character (%s)\n",num_line,(int)(num_col-yyleng),yytext);}


%%
int main(int argc, char* argv[])
{
	if(argc>1)
	{
		{/*caso a flag seja -l ou -1 nao deve imprimir os tokens*/}
		if(strcmp(argv[1],"-l") == 0 || strcmp(argv[1],"-1") == 0){
			if(strcmp(argv[1],"-l") == 0){
				output = 1;
			}
			yylex();
		}
		else if(strcmp(argv[1],"-t") == 0){
			output = 0;
			yyparse();
			if(syn_error== 0){
				print_tree(tree,0);
			}
		}
		else if(strcmp(argv[1],"-s") == 0){
			output = 0;
			yyparse();
			
			if(syn_error== 0){
				create_symboltable(tree);
				printf("\n");
				print_tree(tree,0);
			}
		}
		else if(strcmp(argv[1],"-2") == 0){
			output = 0;
			yyparse();
		}
		
	}
	else if(argc==1){
		output = 0;
		yyparse();
		create_symboltable(tree);
	}
	return 0;
}

int yywrap()
{
	return 1;
}

