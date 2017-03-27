lex jac.l
yacc -d -v jac.y
cc ast.c -o jac y.tab.c lex.yy.c 
