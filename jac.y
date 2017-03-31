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
	int buildingTree=1;
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

Program: CLASS ID OBRACE SubProgram CBRACE  {
	if(buildingTree==1){
		$$=tree=create_node(NODE_Program);
		aux_node = create_node(NODE_Id);
		aux_node->value = $2; 
		insert_child($$,aux_node);
		if($4 != NULL){
			insert_brother(aux_node,$4);
		}
	}
}
	   ; 
   										
SubProgram: Empty {if(buildingTree==1){$$=NULL;}}
		  |	FieldDecl  SubProgram {if(buildingTree==1){
		  	$$ = $1;
			if($2 != NULL){
				insert_brother($$,$2);
			}
		}
}
		  | MethodDecl SubProgram {if(buildingTree==1){
		  	$$ = $1;
			if($2 != NULL){
				insert_brother($$,$2);
			}
}}
		  | SEMI SubProgram {if(buildingTree==1){$$=$2;}}
		  ;

FieldDecl: PUBLIC STATIC Type ID SubFieldDecl SEMI {if(buildingTree==1){
		$$= create_node(NODE_FieldDecl); 
		insert_child($$,$3);
		aux_node2 = create_node(NODE_Id);
		aux_node2->value = $4;
		insert_brother($$->child,aux_node2);
		if($5 != NULL){
			insert_brother($$,$5);
			change_type($$,$5);
		}
	}
}
	| error SEMI {if(buildingTree==1){buildingTree=0;syn_error=1;}}
	;
SubFieldDecl:COMMA ID SubFieldDecl {if(buildingTree==1){
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
			

}
			| Empty {if(buildingTree==1){$$ = NULL/*create_node(NODE_FieldDecl)*/;}}
			;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody {if(buildingTree==1){$$=create_node(NODE_MethodDecl);
		insert_child($$,$3);
		insert_brother($$->child,$4);
	}
}
			;

MethodHeader: Type ID OCURV FormalParams CCURV {if(buildingTree==1){$$ = create_node(NODE_MethodHeader);
			insert_child($$,$1);
			aux_node = create_node(NODE_Id);
			aux_node->value = $2;
			insert_brother($$->child,aux_node);			
			aux_node3 = create_node(NODE_MethodParams);		
			insert_brother($$->child->brother,aux_node3);
			if($4 != NULL){
				insert_child($$->child->brother->brother,$4);
			}
		}

			
}
            | VOID ID OCURV FormalParams CCURV {if(buildingTree==1){$$ = create_node(NODE_MethodHeader);
			aux_node = create_node(NODE_Void);
			insert_child($$,aux_node);
			aux_node2 = create_node(NODE_Id);
			aux_node2->value = $2;
			insert_brother($$->child,aux_node2);
			aux_node3 = create_node(NODE_MethodParams);
			insert_brother($$->child->brother,aux_node3);
			if($4 != NULL){
				insert_child($$->child->brother->brother,$4);
			}
		}
}
	    ;

MethodBody: OBRACE SubMethodBody CBRACE {if(buildingTree==1){
			$$ = $2;}
		}
	  ;

SubMethodBody: SubMethodBody VarDecl {if(buildingTree==1){
			if($$->child == NULL){
				insert_child($$,$2);
			}
			else{
				insert_brother($$->child,$2);
			}
		}
}
			| SubMethodBody Statement {if(buildingTree==1){
			if($2 != NULL){
				if($$->child == NULL){
					insert_child($$,$2);
				}
				else{
					insert_brother($$->child,$2);
				}
			}
		}
}
			| Empty {if(buildingTree==1){$$ = create_node(NODE_MethodBody);}}
			;


FormalParams:  Type ID SubFormalParams {if(buildingTree==1){
			//$$ = create_node(NODE_ParamDecl);
			$$ = create_node(NODE_ParamDecl);
			insert_child($$,$1);
			aux_node = create_node(NODE_Id);
			aux_node->value = $2;
			insert_brother($$->child,aux_node);
			if ($3 != NULL){
				insert_brother($$,$3);
				// insert_child($$,$1);
				// aux_node = create_node(NODE_Id);
				// aux_node->value = $2;
				// insert_brother($$->child,aux_node);
			//insert_brother($$,$3);
			}
		}

}
    | STRING OSQUARE CSQUARE ID {if(buildingTree==1){
    			$$ = create_node(NODE_ParamDecl);
				aux_node = create_node(NODE_StringArray);
				insert_child($$,aux_node);
				aux_node2 = create_node(NODE_Id);
				aux_node2->value = $4;
				insert_brother($$->child,aux_node2);
			}
				
}
	|Empty {if(buildingTree==1){$$ = NULL/*create_node(NODE_ParamDecl)*/;}}
	;
	


SubFormalParams:   COMMA Type ID SubFormalParams{if(buildingTree==1){
			$$ = create_node(NODE_ParamDecl);
			insert_child($$,$2);
			aux_node = create_node(NODE_Id);
			aux_node->value = $3;
			insert_brother($$->child,aux_node);
			if($4 != NULL){
				insert_brother($$,$4);
			}
			 //   	if($1 != NULL){
				// 	$1 = create_node(NODE_ParamDecl);
				// 	insert_child($1,$3);
				// 	aux_node = create_node(NODE_Id);
				// 	aux_node->value = $4;
				// 	insert_brother($1->child,aux_node);
			 //   		insert_brother($$,$1);
				// }
			}
}

				|Empty {if(buildingTree==1){$$ = NULL/*create_node(NODE_ParamDecl)*/;}}
			   
			   ;

VarDecl: Type ID SubVarDecl SEMI {if(buildingTree==1){
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
			}
};

SubVarDecl: COMMA ID SubVarDecl {if(buildingTree==1){
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
}
			| Empty {if(buildingTree==1){
				$$ = create_node(NODE_VarDecl);
			}
			};

Type: BOOL {if(buildingTree==1){$$=create_node(NODE_Bool);}}
	| INT  {if(buildingTree==1){$$=create_node(NODE_Int);}}
	| DOUBLE {if(buildingTree==1){$$=create_node(NODE_Double);}}
	;

Statement: OBRACE MultipleStatements CBRACE {if(buildingTree==1){
		$$ = $2;
		if($2 != NULL){
			if($2->brother != NULL){
				$$ = create_node(NODE_Block);
				insert_child($$,$2);
			}
		}
	}
}
    | IF OCURV Expr CCURV Statement ELSE Statement {if(buildingTree==1){
    	$$=create_node(NODE_If);
		insert_child($$,$3);
    	if($5==NULL){
    		insert_brother($3,create_node(NODE_Block));
    	}
    	else{
    		insert_brother($3,$5);
    	}
    	if($7==NULL){
    		insert_brother($3,create_node(NODE_Block));
    	}
    	if($7!=NULL){
    		if($7->brother != NULL){
    			aux_node = create_node(NODE_Block);
    			insert_brother($3,aux_node);
    			insert_child(aux_node,$7);
    		}
    		else{
	    		insert_brother($3,$7);			
    		}
    	}
    }
}
    | IF OCURV Expr CCURV Statement %prec ELSE {if(buildingTree==1){
    	$$=create_node(NODE_If);
    	if($5==NULL){
    		insert_child($$,$3);
    		insert_brother($3,create_node(NODE_Block));
    	}
    	if($5!=NULL){
    		insert_child($$,$3);
    		insert_brother($3,$5);
    	}
    	insert_brother($3,create_node(NODE_Block));
    }

}
    | WHILE OCURV Expr CCURV Statement {if(buildingTree==1){
    	$$=create_node(NODE_While);
    	if($5==NULL){
    		insert_child($$,$3);
    		insert_brother($3,create_node(NODE_Block));
    	}
    	if($5!=NULL){
    		insert_child($$,$3);
    		insert_brother($3,$5);
    	}
    }
}
    | DO Statement WHILE OCURV Expr CCURV SEMI {if(buildingTree==1){
    	$$=create_node(NODE_DoWhile);
    	if($2==NULL){
    		insert_child($$,create_node(NODE_Block));
    		insert_brother($$->child,$5);
    	}
    	if($2!=NULL){
    		insert_child($$,$2);
    		insert_brother($2,$5);
    	}
    }
}
    | PRINT OCURV ExprStrlit CCURV SEMI {if(buildingTree==1){
		$$=create_node(NODE_Print);
		insert_child($$,$3);
	}
}
    | OptAMIPA SEMI {if(buildingTree==1){//$$=$1;
    	$$=$1;}}
    | RETURN OptExpr SEMI {if(buildingTree==1){//$$=$2;
    	$$=create_node(NODE_Return);
    	if($2 != NULL){
    		insert_child($$,$2);
    	}
    }}
    | error SEMI {if(buildingTree==1){//$$=NULL;
    	buildingTree=0;syn_error=1;$$=create_node(NODE_Error);}}
	;


MultipleStatements: Empty {if(buildingTree==1){$$=NULL;}}
				  | Statement MultipleStatements {if(buildingTree==1){
				  	if($1 == NULL){
				  		$$=$2;
				  	}
				  	if($1 != NULL){
				  		$$=$1;
				  		insert_brother($$,$2);
				  	}
}}
				  ;


ExprStrlit: Expr {if(buildingTree==1){$$=$1;}}
		  | STRLIT {if(buildingTree==1){
		  	$$=create_node(NODE_Strlit);
		  	$$->value = $1;}}
		  ;

OptAMIPA: Assignment {if(buildingTree==1){$$=$1;}}
		| MethodInvocation {if(buildingTree==1){$$=$1;}}
		| ParseArgs {if(buildingTree==1){$$=$1;}}
		| Empty {if(buildingTree==1){$$=NULL;}}
		;

OptExpr: Expr {if(buildingTree==1){$$=$1;}}
	   | Empty {if(buildingTree==1){$$=NULL;}}
	   ;

Assignment: ID ASSIGN Expr {if(buildingTree==1){
		$$ = create_node(NODE_Assign);
		aux_node = create_node(NODE_Id);
		aux_node->value = $1;
		insert_child($$,aux_node);
		insert_brother($$->child,$3);
	}
	}
	;

MethodInvocation: ID OCURV OptExprCommaExprs CCURV {if(buildingTree==1){
			$$ = create_node(NODE_Call);
			aux_node = create_node(NODE_Id);
			aux_node->value = $1;
			insert_child($$,aux_node);
			if($3 != NULL){
				if($$->child != NULL){
					insert_brother($$->child,$3);
				}
			}

}}
    | ID OCURV error CCURV {if(buildingTree==1){buildingTree=0;syn_error=1;$$=create_node(NODE_Error);}}
	;

MultipleCommaExpr: Empty {if(buildingTree==1){$$=NULL;}}
				| COMMA Expr MultipleCommaExpr {if(buildingTree==1){
					if($3 != NULL){
						$$ = $2;
						insert_brother($$,$3);
					}
					if($3 == NULL){
						$$ = $2;
					}
					// $$ = $3;
					// if($1 != NULL){
					// 	insert_brother($$,$1);
}};

OptExprCommaExprs: Expr MultipleCommaExpr {if(buildingTree==1){
					$$=$1;
					if($2 != NULL){
				 		insert_brother($$,$2);
					}
}}
				| Empty {if(buildingTree==1){
					$$ = NULL;
}}
				 ;

ParseArgs: PARSEINT OCURV ID OSQUARE Expr CSQUARE CCURV {if(buildingTree==1){ //Integer.parseInt(ID[Expr])
			$$ = create_node(NODE_ParseArgs);
			aux_node2 = create_node(NODE_Id);
			aux_node2->value = $3;
			insert_child($$,aux_node2);
			insert_brother($$->child,$5);
		}
}
    | PARSEINT OCURV error CCURV {if(buildingTree==1){buildingTree=0;syn_error=1;$$=create_node(NODE_Error);}}
	;

OptDotLength: DOTLENGTH {if(buildingTree==1){
			$$ = create_node(NODE_Length);
		}}
			| Empty {if(buildingTree==1){$$=NULL;}}
			;	

Expr: Assignment {if(buildingTree==1){$$=$1;}}
	| Expre {if(buildingTree==1){$$=$1;}}
	;

Expre: MethodInvocation {if(buildingTree==1){$$=$1;}}
	| ParseArgs {if(buildingTree==1){$$=$1;}}
    | Expre AND Expre {if(buildingTree==1){//$$=NULL;
    	$$ = create_node(NODE_And);
    	insert_child($$,$1);
    	insert_brother($$->child,$3);
    }
}
    | Expre OR Expre {if(buildingTree==1){//$$=NULL;
    	$$ = create_node(NODE_Or);
    	insert_child($$,$1);
    	insert_brother($$->child,$3);
    }
}
    | Expre EQ Expre {if(buildingTree==1){//$$=NULL;
    	$$ = create_node(NODE_Eq);
    	insert_child($$,$1);
    	insert_brother($$->child,$3);
    }
}
    | Expre GEQ Expre {if(buildingTree==1){//$$=NULL;
    	$$ = create_node(NODE_Geq);
    	insert_child($$,$1);
    	insert_brother($$->child,$3);
    }
}
    | Expre GT Expre {if(buildingTree==1){//$$=NULL;
    	$$ = create_node(NODE_Gt);
    	insert_child($$,$1);
    	insert_brother($$->child,$3);
    }
}
    | Expre LEQ Expre {if(buildingTree==1){//$$=NULL;
    	$$ = create_node(NODE_Leq);
    	insert_child($$,$1);
    	insert_brother($$->child,$3);
    }
}
    | Expre LT Expre {if(buildingTree==1){//$$=NULL;
    	$$ = create_node(NODE_Lt);
    	insert_child($$,$1);
    	insert_brother($$->child,$3);
    }
}
    | Expre NEQ Expre {if(buildingTree==1){//$$=NULL;
    	$$ = create_node(NODE_Neq);
    	insert_child($$,$1);
    	insert_brother($$->child,$3);
    }
}
    | Expre MINUS Expre {if(buildingTree==1){//$$=NULL;
    	$$ = create_node(NODE_Sub);
    	insert_child($$,$1);
    	insert_brother($$->child,$3);
    }
}
    | Expre PLUS Expre {if(buildingTree==1){//$$=NULL;
    	$$ = create_node(NODE_Add);
    	insert_child($$,$1);
    	insert_brother($$->child,$3);
    }
}
    | Expre STAR Expre {if(buildingTree==1){//$$=NULL;
    	$$ = create_node(NODE_Mul);
    	insert_child($$,$1);
    	insert_brother($$->child,$3);
    }
}
    | Expre DIV Expre {if(buildingTree==1){//$$=NULL;
    	$$ = create_node(NODE_Div);
    	insert_child($$,$1);
    	insert_brother($$->child,$3);
    }
}
    | Expre MOD Expre {if(buildingTree==1){//$$=NULL;
    	$$ = create_node(NODE_Mod);
    	insert_child($$,$1);
    	insert_brother($$->child,$3);
    }
}
    | PLUS Expre %prec NOT{if(buildingTree==1){
    	$$ = create_node(NODE_Plus);
    	insert_child($$,$2);
    }
}
    | MINUS Expre %prec NOT {if(buildingTree==1){
    	$$ = create_node(NODE_Minus);
    	insert_child($$,$2);
    }
}
    | NOT Expre %prec NOT{if(buildingTree==1){
    	$$ = create_node(NODE_Not);
    	insert_child($$,$2);
    }
}
    | ID OptDotLength {if(buildingTree==1){
    	if($2==NULL){
    		$$ = create_node(NODE_Id);
    		$$->value = $1;
    	}
    	if($2 != NULL){
    		$$ = $2;
    		aux_node = create_node(NODE_Id);
    		aux_node->value = $1;
    		insert_child($$,aux_node);
    	}
    }
} 
    | OCURV Expr CCURV {if(buildingTree==1){$$=$2;}}
    | OCURV error CCURV {if(buildingTree==1){buildingTree=0;syn_error=1;$$=create_node(NODE_Error);}}
    | BOOLLIT {if(buildingTree==1){//$$=NULL;
		$$ = create_node(NODE_Boolit);
		$$->value = $1;
	}
}
	| DECLIT {if(buildingTree==1){
		$$ = create_node(NODE_Declit);
		$$->value = $1;
	}
} 
	| REALLIT {if(buildingTree==1){//$$=NULL;
		$$ = create_node(NODE_Reallit);
		$$->value = $1;
	}
};


Empty: {if(buildingTree==1){;}}
	 ; 

%%

void yyerror (const char *s){
	syn_error++;
	printf ("Line %d, col %d: %s: %s\n",num_line, (int)(num_col- strlen(yytext)), s, yytext);
}


