#include "parser.h"

// prosedur untuk memproses token operator
void parserOperator(char *token, char* str){
    if(strcmp(token, "jeung") == 0){
        strcpy(str, " && ");
    }else if(strcmp(token, "atawa") == 0){
        strcpy(str, " || ");
    }else if(strcmp(token, "gede") == 0){
        strcpy(str, " > ");
    }else if(strcmp(token, "letik") == 0){
        strcpy(str, " < ");
    }else if(strcmp(token, "saruagede") == 0){
        strcpy(str, " >= ");
    }else if(strcmp(token, "sarualetik") == 0){
        strcpy(str, " <= ");
    }else if(strcmp(token, "sarua") == 0){
        strcpy(str, " == ");
    }else if(strcmp(token, "teusarua") == 0){
        strcpy(str, " != ");
    }else{
        strcpy(str, token);
    }
}