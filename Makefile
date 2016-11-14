complier:lex.yy.c yacc.tab.c ast.h
	gcc -o praser lex.yy.c yacc.tab.c ast.c semantic.c
	@echo Make Success!
lex.yy.c:lex.l 
	flex lex.l
yacc.tab.c:yacc.y 
	bison -d -v yacc.y
clean:
	del lex.yy.c yacc.tab.c yacc.tab.h