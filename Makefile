flex limbaj.l
yacc -d limbaj.y
gcc code.c lex.yy.c y.tab.c -w -o proiect
./proiect ex.txt
