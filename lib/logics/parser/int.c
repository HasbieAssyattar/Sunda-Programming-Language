#include "parser.h"
#include "../lexer/lexer.h"

// prosedur untuk memproses token tipe data int
void nomer(char* line){
    start(line);
    inc(line);
    char var_name[100];
    strcpy(var_name, getcw());
    char* tipe = "int";
    addVariable(var_name, tipe);
    
    inc(line);
    if(strcmp(getcw(), "nyaeta") == 0){ // jika deklarasi mengandung inisialisasi
        inc(line);
        char rhs[256] = "";
        while(1){
            if (strlen(rhs) > 0) strcat(rhs, " ");
            strcat(rhs, getcw());
            if (eop(line)) break;
            inc(line);
        }
        
        // Semantic Analysis: Cek apakah RHS sesuai dengan tipe 'nomer' (int)
        if (!isdigit(rhs[0]) && getType(rhs) == NULL && rhs[0] != '-') {
             printf(RED "HAYU MAEN! Aya kasalahan dina baris %d: " RESET 
                    "Variabel '%s' teh tipe 'nomer' (int), teu bisa diisi ku '%s'!\n", 
                    curr_line + 1, var_name, rhs);
             error = 1;
        }

        sprintf(line, "int %s = %s;", var_name, rhs);
    }else{ // jika hanya deklarasi
        sprintf(line, "int %s;", var_name);
    }
}