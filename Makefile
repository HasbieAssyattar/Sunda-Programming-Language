BINARY=bin/sun
SOURCES=sundaLang-interpreter.c lib/logics/lexer/*.c lib/logics/parser/*.c

all:
	@if not exist bin mkdir bin
	gcc sundaLang-interpreter.c lib/logics/lexer/*.c lib/logics/parser/*.c -o bin/sun
oneple:
	@if not exist bin mkdir bin
	gcc sunda-oneple.c lib/logics/lexer/*.c lib/logics/parser/*.c -o bin/sun-oneple
ir:
	@if not exist bin mkdir bin
	gcc sunda-ir-interpreter.c lib/logics/lexer/*.c lib/logics/parser/*.c -o bin/sun-ir
install:
	cp bin/sun /usr/local/bin/
