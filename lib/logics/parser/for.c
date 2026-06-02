#include "parser.h"
#include "../lexer/lexer.h"

// prosedur untuk memparsing token keyword for
// Pola: muter [var] ti [awal] nepi [akhir] :
void muter(char* line){
    char output[256] = "";
    char varName[64];
    char startVal[64];
    char endVal[64];

    start(line);
    inc(line); // skip "muter"
    
    strcpy(varName, getcw()); // ambil nama variabel
    inc(line);
    
    if(strcmp(getcw(), "ti") == 0){
        inc(line);
        strcpy(startVal, getcw()); // ambil nilai awal
    } else {
        printf("Error: 'muter' kedah nganggo 'ti' saatos nami variabel!\n");
        return;
    }
    
    inc(line);
    if(strcmp(getcw(), "nepi") == 0){
        inc(line);
        strcpy(endVal, getcw()); // ambil nilai akhir
        // Cek apakah diakhiri dengan :
        if (endVal[strlen(endVal)-1] == ':') {
            endVal[strlen(endVal)-1] = '\0';
        }
    } else {
        printf("Error: 'muter' kedah nganggo 'nepi' kanggo wates akhir!\n");
        return;
    }

    sprintf(output, "for(int %s = %s; %s < %s; %s++){", varName, startVal, varName, endVal, varName);
    strcpy(line, output);
}