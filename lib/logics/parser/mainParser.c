#include "parser.h"
#include "../lexer/lexer.h"

// prosedur untuk melakukan parsing tiap barisnya
void mainParser(char* line){
    start(line);
    if (line[0] == '\0' || strcmp(getcw(), "") == 0) return;
    if(strcmp(getcw(), "nomer") == 0) nomer(line);
    else if(strcmp(getcw(), "koma") == 0) koma(line);
    else if (strcmp(getcw(), "legeg") == 0) legeg(line);
    else if (strcmp(getcw(), "legegpican") == 0) legegpican(line);
    else if (strcmp(getcw(), "asupkeun") == 0) asupkeun(line);
    else if(strcmp(getcw(), "ngagorowok") == 0) ngagorowok(line);
    else if(strcmp(getcw(), "muter") == 0) muter(line);
    else if(strcmp(getcw(), "Keur") == 0) keur(line);
    else if(strcmp(getcw(), "mun") == 0) mun(line);
    else if(strcmp(getcw(), "munte") == 0) munteu(line);
    else if(strcmp(getcw(), "nte") == 0) teu(line);
    else if (strstr(line, "sok") != NULL) strcpy(line, "continue;");
    else if(strcmp(getcw(), "}") == 0) strcpy(line, "}");
    else if (strstr(line, "nyaeta") != NULL) parseAssignment(line);
    else if(strcmp(getcw(), "nuhun") == 0) line[0] = '\0';
    else sprintf(line, "// KASALAHAN: kecap konci teu dikenal %s", getcw());
}
