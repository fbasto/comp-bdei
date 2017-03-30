%{
    #include <stdio.h>
	#include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"
	#include "header.h"
//	#include "ast.h"
    int yylex(void);
    void yyerror (const char *s);
	extern int num_line;
	extern int num_col;
	extern char *yytext;
	int syn_error = 0;
	Node *tree;
	Node *aux_node;
	Node *aux_node2;
	Node *aux_node3;
	int flag=1;
%}

%union{
	char * string;
	struct node *node;
}

%token BOOL
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
%token <string> BOOLLIT
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
%type <node> Expre


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

Program: CLASS ID OBRACE SubProgram CBRACE  {$$=tree=create_node(NODE_Program);

		aux_node = create_node(NODE_Id);
		aux_node->value = $2; 
		insert_child($$,aux_node);
		if($4 != NULL){
			insert_brother(aux_node,$4);
		}
}
	   ; 
   										
SubProgram: Empty {$$= NULL;}
		  |	FieldDecl  SubProgram {$$ = $1;
			if($$ != NULL){
				insert_brother($$,$2);
			}
}
		  | MethodDecl SubProgram {$$ = $1;}
		  | SEMI SubProgram {/*insert_child($$,$1)*/;}
		  ;
FieldDecl: PUBLIC STATIC Type ID SubFieldDecl SEMI {
		$$= create_node(NODE_FieldDecl); 
		insert_child($$,$3);
		aux_node2 = create_node(NODE_Id);
		aux_node2->value = $4;
		insert_brother($$->child,aux_node2);
		if($5 != NULL){
			insert_brother($$,$5);
		}
		change_type($$,$5);
}
	| error SEMI {$$=NULL;}
	;
SubFieldDecl:COMMA ID SubFieldDecl {
			//printf("TIPO: %s",$1->type);
			/*aux_node = create_node(NODE_Comp);
			insert_child($3,aux_node);
			aux_node2 = create_node(NODE_Id);
			aux_node2->value = $2;
			insert_brother($3->child,aux_node2);
			$$ = create_node(NODE_FieldDecl);
			insert_brother($$,$3);
			*/

			$$ = create_node(NODE_FieldDecl);
			aux_node = create_node(NODE_Comp);
			insert_child($$,aux_node);	
			aux_node2 = create_node(NODE_Id);
			aux_node2->value = $2;
			if($$  != NULL){
				insert_brother($$->child,aux_node2);
				insert_brother($$,$3);
			}
			

}
			| Empty {$$ = NULL/*create_node(NODE_FieldDecl)*/;}
			;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody {$$=create_node(NODE_MethodDecl);
		insert_child($$,$3);
		insert_brother($$->child,$4);
}
			;

MethodHeader: Type ID OCURV FormalParams CCURV {$$ = create_node(NODE_MethodHeader);
			insert_child($$,$1);
			aux_node = create_node(NODE_Id);
			aux_node->value = $2;
			insert_brother($$->child,aux_node);			
			aux_node3 = create_node(NODE_MethodParams);		
			insert_brother($$->child->brother,aux_node3);
			if($4->child != NULL){
				insert_child($$->child->brother->brother,$4);
			}

			
}
            | VOID ID OCURV FormalParams CCURV {$$ = create_node(NODE_MethodHeader);
			aux_node = create_node(NODE_Void);
			insert_child($$,aux_node);
			aux_node2 = create_node(NODE_Id);
			aux_node2->value = $2;
			insert_brother($$->child,aux_node2);
			aux_node3 = create_node(NODE_MethodParams);
			insert_brother($$->child->brother,aux_node3);
			if($4->child != NULL){
				insert_child($$->child->brother->brother,$4);
			}
}
	    ;

MethodBody: OBRACE SubMethodBody CBRACE {
			$$ = $2;}
	  ;

SubMethodBody: SubMethodBody VarDecl {
			if($$->child == NULL){
				insert_child($$,$2);
			}
			else{
				insert_brother($$->child,$2);
			}
}
			| SubMethodBody Statement {
			if($$->child == NULL){
				insert_child($$,$2);
			}
			else{
				insert_brother($$->child,$2);
			}
}
			| Empty {$$ = create_node(NODE_MethodBody);}
			;


FormalParams:  Type ID SubFormalParams {
			//$$ = create_node(NODE_ParamDecl);

			$$ = $3;
			if ($3 != NULL){	
				insert_child($$,$1);
				aux_node = create_node(NODE_Id);
				aux_node->value = $2;
				insert_brother($$->child,aux_node);
			//insert_brother($$,$3);
			}

}
    | STRING OSQUARE CSQUARE ID {$$ = create_node(NODE_ParamDecl);
				aux_node = create_node(NODE_StringArray);
				insert_child($$,aux_node);
				aux_node2 = create_node(NODE_Id);
				aux_node2->value = $4;
				insert_brother($$->child,aux_node2);
				
}
	|Empty {$$ = NULL/*create_node(NODE_ParamDecl)*/;}
	;
	


SubFormalParams:  SubFormalParams COMMA Type ID {
			   	if($1 != NULL){
					$1 = create_node(NODE_ParamDecl);
					insert_child($1,$3);
					aux_node = create_node(NODE_Id);
					aux_node->value = $4;
					insert_brother($1->child,aux_node);
			   		insert_brother($$,$1);
				}
}

				|Empty {$$ = NULL/*create_node(NODE_ParamDecl)*/;}
			   
			   ;

VarDecl: Type ID SubVarDecl SEMI {
				// $$ = $3;
				// insert_brother($3->child,$1);
				// aux_node = create_node(NODE_Id);
				// aux_node->value = $2;
				// insert_brother($$->child,aux_node);
				$$ = create_node(NODE_VarDecl);
				insert_child($$,$1);
				aux_node = create_node(NODE_Id);
				aux_node->value = $2;
				insert_brother($$->child,aux_node);
				if($3->child != NULL){
					insert_brother($$,$3);
					change_type($$,$3);
				}
};

SubVarDecl: COMMA ID SubVarDecl {
				$$ = create_node(NODE_VarDecl);
				aux_node2 = create_node(NODE_Comp);
				insert_child($$,aux_node2);
				aux_node = create_node(NODE_Id);
				aux_node->value = $2;
				insert_brother($$->child,aux_node);
				if($3->child != NULL){
					insert_brother($$,$3);
				}
}
			| Empty {
				$$ = create_node(NODE_VarDecl);
			};

Type: BOOL {$$=create_node(NODE_Bool);}
	| INT  {$$=create_node(NODE_Int);}
	| DOUBLE {$$=create_node(NODE_Double);}
	;

Statement: OBRACE MultipleStatements CBRACE {
		$$ = $2;
}
    | IF OCURV Expr CCURV Statement ELSE Statement {
    	$$=create_node(NODE_If);
    	insert_child($$,$3);
    	insert_brother($3,$5);
    	insert_brother($3,$7);
}
    | IF OCURV Expr CCURV Statement %prec ELSE {
    	$$=create_node(NODE_If);
    	insert_child($$,$3);
    	insert_brother($3,$5);

}
    | WHILE OCURV Expr CCURV Statement {
    	$$=create_node(NODE_While);
    	insert_child($$,$3);
    	insert_brother($3,$5);
}
    | DO Statement WHILE OCURV Expr CCURV SEMI {
    	$$=create_node(NODE_DoWhile);
    	insert_child($$,$2);
    	insert_brother($2,$5);
}
    | PRINT OCURV ExprStrlit CCURV SEMI {
		$$=create_node(NODE_Print);
		insert_child($$,$3);
}
    | OptAMIPA SEMI {//$$=$1;
    	$$=$1;}
    | RETURN OptExpr SEMI {//$$=$2;
    	$$=$2;}
    | error SEMI {//$$=NULL;
    	$$=NULL;}
	;


MultipleStatements: Empty {$$=NULL;}
				  | Statement MultipleStatements {$$=NULL;}
				  ;


ExprStrlit: Expr {$$=$1;}
		  | STRLIT {
		  	$$=create_node(NODE_Strlit);
		  	$$->value = $1;}
		  ;

OptAMIPA: Assignment {$$=$1;}
		| MethodInvocation {$$=$1;}
		| ParseArgs {$$=$1;}
		| Empty {$$=NULL;}
		;

OptExpr: Expr {$$=$1;}
	   | Empty {$$=NULL;}
	   ;

Assignment: ID ASSIGN Expr {
		$$ = create_node(NODE_Assign);
		aux_node = create_node(NODE_Id);
		aux_node->value = $1;
		insert_child($$,aux_node);
		insert_brother($$->child,$3);
	}
	;

MethodInvocation: ID OCURV OptExprCommaExprs CCURV {$$=NULL;}
    | ID OCURV error CCURV {$$=NULL;}
	;

MultipleCommaExpr: Empty {$$=NULL;}
				 | MultipleCommaExpr COMMA Expr {$$=NULL;}
				 ;
OptExprCommaExprs: Expr MultipleCommaExpr {$$=NULL;}
				 | Empty {$$=NULL;}
				 ;

ParseArgs: PARSEINT OCURV ID OSQUARE Expr CSQUARE CCURV { //Integer.parseInt(ID[Expr])
			$$ = create_node(NODE_ParseArgs);
			aux_node2 = create_node(NODE_Id);
			aux_node2->value = $3;
			insert_child($$,aux_node2);
			insert_brother($$->child,$5);


}
    | PARSEINT OCURV error CCURV {$$=NULL;syn_error=1;}
	;

OptDotLength: DOTLENGTH {$$=NULL;}
			| Empty {$$=NULL;}
			;	

Expr: Assignment {$$=$1;}
	| Expre {$$=$1;}
	;

Expre: MethodInvocation {$$=NULL;}
	| ParseArgs {$$=$1;}
    | Expre AND Expre {//$$=NULL;
    	$$ = create_node(NODE_And);
    	insert_child($$,$1);
    	insert_brother($$->child,$3);
}
    | Expre OR Expre {//$$=NULL;
    	$$ = create_node(NODE_Or);
    	insert_child($$,$1);
    	insert_brother($$->child,$3);
}
    | Expre EQ Expre {//$$=NULL;
    	$$ = create_node(NODE_Eq);
    	insert_child($$,$1);
    	insert_brother($$->child,$3);
}
    | Expre GEQ Expre {//$$=NULL;
    	$$ = create_node(NODE_Geq);
    	insert_child($$,$1);
    	insert_brother($$->child,$3);
}
    | Expre GT Expre {//$$=NULL;
    	$$ = create_node(NODE_Gt);
    	insert_child($$,$1);
    	insert_brother($$->child,$3);
}
    | Expre LEQ Expre {//$$=NULL;
    	$$ = create_node(NODE_Leq);
    	insert_child($$,$1);
    	insert_brother($$->child,$3);
}
    | Expre LT Expre {//$$=NULL;
    	$$ = create_node(NODE_Lt);
    	insert_child($$,$1);
    	insert_brother($$->child,$3);
}
    | Expre NEQ Expre {//$$=NULL;
    	$$ = create_node(NODE_Neq);
    	insert_child($$,$1);
    	insert_brother($$->child,$3);
}
    | Expre MINUS Expre {//$$=NULL;
    	$$ = create_node(NODE_Minus);
    	insert_child($$,$1);
    	insert_brother($$->child,$3);
}
    | Expre PLUS Expre {//$$=NULL;
    	$$ = create_node(NODE_Plus);
    	insert_child($$,$1);
    	insert_brother($$->child,$3);
}
    | Expre STAR Expre {//$$=NULL;
    	$$ = create_node(NODE_Mul);
    	insert_child($$,$1);
    	insert_brother($$->child,$3);
}
    | Expre DIV Expre {//$$=NULL;
    	$$ = create_node(NODE_Div);
    	insert_child($$,$1);
    	insert_brother($$->child,$3);
}
    | Expre MOD Expre {//$$=NULL;
    	$$ = create_node(NODE_Mod);
    	insert_child($$,$1);
    	insert_brother($$->child,$3);
}
    | PLUS Expre %prec NOT{

;}
    | MINUS Expre %prec NOT {$$=NULL;}
    | NOT Expre %prec NOT{$$=NULL;}
    | ID OptDotLength {
    	$$ = create_node(NODE_Id);
    	$$->value = $1;
;} 
    | OCURV Expr CCURV {$$=$2;}
    | OCURV error CCURV {$$=NULL;}
    | BOOLLIT {//$$=NULL;
		$$ = create_node(NODE_Boolit);
		$$->value = $1;
}
	| DECLIT {
		$$ = create_node(NODE_Declit);
		$$->value = $1;
} 
	| REALLIT {//$$=NULL;
		$$ = create_node(NODE_Reallit);
		$$->value = $1;
};


Empty: {;} 
	 ; 

%%

void yyerror (const char *s){
	syn_error++;
	printf ("Line %d, col %d: %s: %s\n",num_line, (int)(num_col- strlen(yytext)), s, yytext);
}


