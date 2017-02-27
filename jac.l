%X COMMENT1
%X COMMENT2
%{
	//podem faltar includes
	/*
		output=0 nao imprime
		output=1 imprime	
	*/
	#define YY_USER_ACTION num_col += yyleng;
	int output = 0;
	int num_line = 0;
	int num_col = 1;
	int comm_line;
	int comm_col;
%}
ID 		([a-z]|[A-Z]|"_"|"$")+([a-z]|[A-Z]|"_"|"$"|[0-9])*
DECLIT		0|[1-9](\_+[0-9]|[0-9])*
ESCAPES		\\n|\\t|\\r|\\f|\\\"|\\\\
UNDEFESCAPES 	"\\b"|"\\'"

STRLIT		"\""(([^"\\\n]|({ESCAPES}))*)"\""
UNTSTRLIT	\"([^\"\n]|{ESCAPES})*
REALLIT		(((([0-9]_+[0-9]|[0-9])+((\.)([0-9]_+[0-9]|[0-9])*))|((\.)([0-9]_+[0-9]|[0-9])+))(["e"|"E"]([-+]?([0-9]_+[0-9]|[0-9])*))?)|(([0-9]_+[0-9]|[0-9])*(["e"|"E"]([-+]?([0-9]_+[0-9]|[0-9])*)))

%option yylineno
%%
"boolean"	{if(output) printf("BOOL\n");}
"true"|"false"	{if(output) printf("BOOLLIT(%s)\n",yytext);}
"class"		{if(output) printf("CLASS\n");}
"do"		{if(output) printf("DO\n");}
"double"	{if(output) printf("DOUBLE\n");}
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
"abstract"|"assert"|"byte"|"break"|"case"|"catch"|"char"|"const"|"continue"|"default"|"enum"|"extends"|"final"|"finally"|"float"|"for"|"goto"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"package"|"private"|"protected"|"short"|"strictfp"|"super"|"switch"|"synchronized"|"this"|"throws"|"throw"|"transient"|"try"|"volatile"|"++"|"--"|"null"|"Integer"|"System"		{if(output) printf("RESERVED(%s)\n",yytext);}



{ID}	 	{if(output)printf("ID(%s)\n",yytext);}
{STRLIT}	{if(output)printf("STRLIT(%s)\n",yytext);}
{UNDEFESCAPES}	{printf("Line %d, col %d: invalid escape sequence (%s)\n",yylineno,(int)(num_col-yyleng),yytext);}
{UNTSTRLIT}	{if(output)printf("Line %d, col %d: unterminated string literal\n",yylineno,(int)(num_col-yyleng));}
{REALLIT}		{if(output)printf("REALLIT(%s)\n",yytext);}
{DECLIT}		{if(output)printf("DECLIT(%s)\n",yytext);}
{ESCAPES}	{;}

"//"	{BEGIN COMMENT2;}
<COMMENT2>"\n"	{BEGIN 0;num_col=1;num_line++;}
<COMMENT2>"\r"	{BEGIN 0;num_col=1;num_line++;}
<COMMENT2>"\r\n" {BEGIN 0;num_col=1;num_line++;}
<COMMENT2>.		{num_col=num_col+yyleng;}

"/*"	{BEGIN COMMENT1; comm_line = yylineno; comm_col = (int)(num_col-yyleng);}
<COMMENT1>"*/"			{BEGIN 0;}
<COMMENT1>"\n"			{num_col=1;num_line++;}
<COMMENT1>"\r"			{num_col=1;num_line++;}
<COMMENT1>"\r\n"		{num_col=1;num_line++;}
<COMMENT1><<EOF>>		{printf("Line %d, col %d: unterminated comment\n",comm_line,comm_col);yyterminate();}
<COMMENT1>.				{num_col=num_col+yyleng;}

"\n"		{num_col=1;num_line++;}
"\t"		{num_col=num_col+yyleng;}
"\r"		{num_col=1;num_line++;}
"\r\n"		{num_col=1;num_line++;}
"\f"		{num_col=num_col+yyleng;}
" "	    	{num_col=num_col+yyleng;}
.		{num_col=num_col+yyleng;printf("Line %d, col %d: illegal character (%s)\n",yylineno,(int)(num_col-yyleng),yytext);}


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
