BINARY=sun
SOURCES=sundaLang-interpreter.c lib/logics/lexer/*.c lib/logics/parser/*.c

all:
	@if not exist bin mkdir bin
	gcc $(SOURCES) -o $(BINARY)
install:
	cp $(BINARY) /usr/local/bin/
