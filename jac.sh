flex jac.l
yacc -d -v jac.y
cc -o jac y.tab.c lex.yy.c
