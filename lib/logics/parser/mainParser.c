#include "parser.h"
#include "../lexer/lexer.h"

// prosedur untuk melakukan parsing tiap barisnya
void mainParser(char* line){
    start(line);
    if (line[0] == '\0' || strcmp(getcw(), "") == 0) return;
    if(strcmp(getcw(), "skibidi") == 0) skibidi(line);
    else if(strcmp(getcw(), "skibidiToilet") == 0) skibidiToilet(line);
    else if (strcmp(getcw(), "sigma") == 0) sigma(line);
    else if (strcmp(getcw(), "sigmaBoy") == 0) sigmaBoy(line);
    else if (strcmp(getcw(), "asupkeun") == 0) asupkeun(line);
    else if(strcmp(getcw(), "ngagorowok") == 0) ngagorowok(line);
    else if(strcmp(getcw(), "muter") == 0) muter(line);
    else if(strcmp(getcw(), "keur") == 0) keur(line);
    else if(strcmp(getcw(), "mun") == 0) mun(line);
    else if(strcmp(getcw(), "munteu") == 0) munteu(line);
    else if(strcmp(getcw(), "teu") == 0) teu(line);
    else if (strstr(line, "bruh") != NULL) strcpy(line, "break;");
    else if (strstr(line, "sok") != NULL) strcpy(line, "continue;");
    else if(strcmp(getcw(), "}") == 0) strcpy(line, "}");
    else if (strstr(line, "nyaeta") != NULL) parseAssignment(line);
    else if (strstr(line, "aura") != NULL) parserAuraOperation(line);
    else if(strcmp(getcw(), "nuhun") == 0) line[0] = '\0';
    else sprintf(line, "// ERROR: keyword tidak dikenali");
}
