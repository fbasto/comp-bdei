%X COMMENT1
%X COMMENT2
%X STR
%{
	//podem faltar includes
	/*
		output=0 nao imprime
		output=1 imprime	
	*/
	int output = 0;
	int num_line = 1;
	int num_col = 1;
	int aux_line;
	int aux_col;
%}

ID 		([a-z]|[A-Z]|"_"|"$")+([a-z]|[A-Z]|"_"|"$"|[0-9])*
DECLIT		0|[1-9](\_+[0-9]|[0-9])*
ESCAPES		\\n|\\t|\\r|\\f|\\\"|\\\\
UNDEFESCAPES 	\\[^ntrf\"\\]

LINEB 	(\n)|(\r)|(\r\n)
STRLIT		"\""(([^"\\\n\r]|({ESCAPES}))*)"\""
REALLIT		(([0-9]+(([0-9]|_)*[0-9])*)\.((([0-9]+(([0-9]|_)*[0-9])*)(["e""E"][-+]?)([0-9]+(([0-9]|_)*[0-9])*))|([0-9]+(([0-9]|_)*[0-9])*)|(["e""E"][-+]?)([0-9]+(([0-9]|_)*[0-9])*))?)|((\.)([0-9]+(([0-9]|_)*[0-9])*)((["e""E"][-+]?)([0-9]+(([0-9]|_)*[0-9])*))?)|(([0-9]+(([0-9]|_)*[0-9])*)(["e""E"][-+]?([0-9]+(([0-9]|_)*[0-9])*)))

%%
"boolean"	{num_col=num_col+yyleng;if(output) printf("BOOL\n");}
"true"|"false"	{num_col=num_col+yyleng;if(output) printf("BOOLLIT(%s)\n",yytext);}
"class"		{num_col=num_col+yyleng;if(output) printf("CLASS\n");}
"do"		{num_col=num_col+yyleng;if(output) printf("DO\n");}
"double"	{num_col=num_col+yyleng;if(output) printf("DOUBLE\n");}
".length"	{num_col=num_col+yyleng;if(output) printf("DOTLENGTH\n");}
"else"		{num_col=num_col+yyleng;if(output) printf("ELSE\n");}
"if"		{num_col=num_col+yyleng;if(output) printf("IF\n");}
"int"		{num_col=num_col+yyleng;if(output) printf("INT\n");}
"Integer.parseInt"	{num_col=num_col+yyleng;if(output) printf("PARSEINT\n");}
"System.out.println"	{num_col=num_col+yyleng;if(output) printf("PRINT\n");}
"public"	{num_col=num_col+yyleng;if(output) printf("PUBLIC\n");}
"return"	{num_col=num_col+yyleng;if(output) printf("RETURN\n");}
"static"	{num_col=num_col+yyleng;if(output) printf("STATIC\n");}
"String"	{num_col=num_col+yyleng;if(output) printf("STRING\n");}
"void"		{num_col=num_col+yyleng;if(output) printf("VOID\n");}
"while"		{num_col=num_col+yyleng;if(output) printf("WHILE\n");}
"("		{num_col=num_col+yyleng;if(output) printf("OCURV\n");}
")"		{num_col=num_col+yyleng;if(output) printf("CCURV\n");}
"{"		{num_col=num_col+yyleng;if(output) printf("OBRACE\n");}
"}"		{num_col=num_col+yyleng;if(output) printf("CBRACE\n");}
"["		{num_col=num_col+yyleng;if(output) printf("OSQUARE\n");}
"]"		{num_col=num_col+yyleng;if(output) printf("CSQUARE\n");}
"&&"		{num_col=num_col+yyleng;if(output) printf("AND\n");}
"||"		{num_col=num_col+yyleng;if(output) printf("OR\n");}
"<"		{num_col=num_col+yyleng;if(output) printf("LT\n");}
">"		{num_col=num_col+yyleng;if(output) printf("GT\n");}	
"=="		{num_col=num_col+yyleng;if(output) printf("EQ\n");}
"!="		{num_col=num_col+yyleng;if(output) printf("NEQ\n");}
"<="		{num_col=num_col+yyleng;if(output) printf("LEQ\n");}
">="		{num_col=num_col+yyleng;if(output) printf("GEQ\n");}
"+"		{num_col=num_col+yyleng;if(output) printf("PLUS\n");}
"-"		{num_col=num_col+yyleng;if(output) printf("MINUS\n");}
"*"		{num_col=num_col+yyleng;if(output) printf("STAR\n");}
"/"		{num_col=num_col+yyleng;if(output) printf("DIV\n");}
"%"		{num_col=num_col+yyleng;if(output) printf("MOD\n");}
"!"		{num_col=num_col+yyleng;if(output) printf("NOT\n");}
"="		{num_col=num_col+yyleng;if(output) printf("ASSIGN\n");}
";"		{num_col=num_col+yyleng;if(output) printf("SEMI\n");}
","		{num_col=num_col+yyleng;if(output) printf("COMMA\n");}
"abstract"|"assert"|"byte"|"break"|"case"|"catch"|"char"|"const"|"continue"|"default"|"enum"|"extends"|"final"|"finally"|"float"|"for"|"goto"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"package"|"private"|"protected"|"short"|"strictfp"|"super"|"switch"|"synchronized"|"this"|"throws"|"throw"|"transient"|"try"|"volatile"|"++"|"--"|"null"|"Integer"|"System"		{num_col=num_col+yyleng;if(output) printf("RESERVED(%s)\n",yytext);}



{ID}	 	{num_col=num_col+yyleng;if(output)printf("ID(%s)\n",yytext);}
{STRLIT}	{num_col=num_col+yyleng;if(output)printf("STRLIT(%s)\n",yytext);}
{REALLIT}		{num_col=num_col+yyleng;if(output)printf("REALLIT(%s)\n",yytext);}
{DECLIT}		{num_col=num_col+yyleng;if(output)printf("DECLIT(%s)\n",yytext);}


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

