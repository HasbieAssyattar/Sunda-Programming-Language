#include "parser.h"

// prosedur untuk memproses token operator comparation, tapi untuk string
void parserStrcmp(char* left, char* op, char* right, char* result) {
    char cmp[16] = "";

    if (strcmp(op, "sarua") == 0) {
        strcpy(cmp, "==");
    } else if (strcmp(op, "teusarua") == 0) {
        strcpy(cmp, "!=");
    } else if (strcmp(op, "gede") == 0) {
        strcpy(cmp, ">");
    } else if (strcmp(op, "letik") == 0) {
        strcpy(cmp, "<");
    } else if (strcmp(op, "saruagede") == 0) {
        strcpy(cmp, ">=");
    } else if (strcmp(op, "sarualetik") == 0) {
        strcpy(cmp, "<=");
    } else {
        sprintf(result, "%s %s %s", left, op, right);
        return;
    }

    sprintf(result, "(strcmp(%s, %s) %s 0)", left, right, cmp);
}
