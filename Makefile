BINARY=sun
SOURCES=sundaLang-interpreter.c lib/logics/lexer/*.c lib/logics/parser/*.c

all:
	@if not exist bin mkdir bin
	gcc sundaLang-interpreter.c lib/logics/lexer/*.c lib/logics/parser/*.c -o sun
oneple:
	gcc sunda-oneple.c lib/logics/lexer/*.c lib/logics/parser/*.c -o sun-oneple
ir:
	gcc sunda-ir-interpreter.c lib/logics/lexer/*.c lib/logics/parser/*.c -o sun-ir
install:
	cp sun /usr/local/bin/
