lex jac.l
yacc -d -v jac.y
cc ast.c print.c -g -o jac y.tab.c lex.yy.c -ll -ly

