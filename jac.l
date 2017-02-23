%X COMMENT
%X ERROR
%{
	//podem faltar includes
	/*
		output=0 nao imprime
		output=1 imprime	
	*/
	int output = 0;
%}
ID 		([a-z]|[A-Z]|\_|\$)+([a-z]|[A-Z]|\_|\$|[0-9])*
DECLIT		0|[1-9](\_+[0-9]|[0-9])*
STRLIT		\"([^\n\\]*)\"
REALLIT		((([0-9]_+[0-9]|[0-9])+((\.)?([0-9]_+[0-9]|[0-9])*))|((\.)([0-9]_+[0-9]|[0-9])+))([e|E]([-+]?([0-9]_+[0-9]|[0-9])*))?
UNDEFESCAPES 	\"\\b\"|\"\\'\"|\"\\"\"

%%
"boolean"	{if(output) printf("BOOL\n");}
"true"|"false"	{if(output) printf("BOOLLIT\n");}
"class"		{if(output) printf("CLASS\n");}
"do"		{if(output) printf("DO\n");}
".length"	{if(output) printf("DOTLENGTH\n");}
"else"		{if(output) printf("ELSE\n");}
"if"		{if(output) printf("IF\n");}
"int"		{if(output) printf("INT\n");}
"Integer.parseInt"	{if(output) printf("PARSEINT\n");}
"System.out.println"	{if(output) printf("PRINT\n");}
"public"	{if(output) printf("PUBLIC\n");}
"return"	{if(output) printf("RETURN\n");}
"static"	{if(output) printf("STATIC\n");}
"String"	{if(output) printf("STRING\n");}
"void"		{if(output) printf("VOID\n");}
"while"		{if(output) printf("WHILE\n");}
"("		{if(output) printf("OCURV\n");}
")"		{if(output) printf("CCURV\n");}
"{"		{if(output) printf("OBRACE\n");}
"}"		{if(output) printf("CBRACE\n");}
"["		{if(output) printf("OSQUARE\n");}
"]"		{if(output) printf("CSQUARE\n");}
"&&"		{if(output) printf("AND\n");}
"||"		{if(output) printf("OR\n");}
"<"		{if(output) printf("LT\n");}
">"		{if(output) printf("GT\n");}	
"=="		{if(output) printf("EQ\n");}
"!="		{if(output) printf("NEQ\n");}
"<="		{if(output) printf("LEQ\n");}
">="		{if(output) printf("GEQ\n");}
"+"		{if(output) printf("PLUS\n");}
"-"		{if(output) printf("MINUS\n");}
"*"		{if(output) printf("STAR\n");}
"/"		{if(output) printf("DIV\n");}
"%"		{if(output) printf("MOD\n");}
"!"		{if(output) printf("NOT\n");}
"="		{if(output) printf("ASSIGN\n");}
";"		{if(output) printf("SEMI\n");}
","		{if(output) printf("COMMA\n");}
"abstract"|"assert"|"byte"|"case"|"catch"|"char"|"const"|"continue"|"default"|"double"|"enum"|"extends"|"final"|"finally"|"float"|"for"|"goto"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"package"|"private"|"protected"|"short"|"strictfp"|"super"|"switch"|"synchronized"|"this"|"throws"|"throw"|"transient"|"try"|"volatile"|"++"|"--"|"null"|"Integer"|"System"		{if(output) printf("RESERVED\n");}

"\n"		{;}
"\t"		{;}
"\r"		{;}
"\f"		{;}
" "		    {;}

{ID} 	{if(output)printf("ID(%s)\n",yytext);}

{DECLIT}	{if(output)printf("DECLIT(%s)\n",yytext);}
.		{printf("Line <num linha>, col <num coluna>: illegal character (<s>)\n");}



"/*"	{BEGIN COMMENT;}
%%
int main(int argc, char* argv[])
{
	if(argc>1)
	{
		{/*caso a flag seja -l ou -1 nao deve imprimir os tokens*/}
		if(strcmp(argv[1],"-l") == 0 || strcmp(argv[1],"-1") == 0)
		{
			output = 1 ;
		}

	}
	yylex();
	return 0;
}

int yywrap()
{
	return 1;
}
