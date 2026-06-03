#include "parser.h"
#include "../lexer/lexer.h"

// prosedur untuk memparsing tipe data char
void legeg(char* line){
    start(line);
    inc(line);
    char var_name[100];
    strcpy(var_name, getcw());
    char* tipe = "char";
    addVariable(var_name, tipe);

    inc(line);
    if (strcmp(getcw(), "nyaeta") == 0) {
        inc(line);
        char* value = getcw();
        if (value[0] == '\'' && value[strlen(value) - 1] == '\'') {
            sprintf(line, "char %s = %s;", var_name, value);
        } else {
            sprintf(line, "char %s = '%s';", var_name, value);
        }
    } else {
        sprintf(line, "char %s;", var_name);
    }
}