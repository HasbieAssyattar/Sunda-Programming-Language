#include "parser.h"

// prosedur untuk memparsing assignment
void parseAssignment(char* line){
    start(line);
    char lhs[100], rhs[256] = "";
    strcpy(lhs, getcw());  // ambil variabel kiri
    char* tipeLHS = getType(lhs);

    inc(line); // ke 'nyaeta'
    inc(line); // gabungkan semua token setelah 'nyaeta' sampai akhir baris
    while(1){
        if (strlen(rhs) > 0) strcat(rhs, " ");
        strcat(rhs, getcw());
        if (eop(line)) break;
        inc(line);
    }

    // validasi tipe data (Semantic Analysis)
    if (tipeLHS != NULL && strcmp(tipeLHS, "int") == 0) {
        // Jika RHS bukan angka dan bukan variabel yang terdaftar
        if (!isdigit(rhs[0]) && getType(rhs) == NULL && rhs[0] != '-') {
             printf(RED "HAYU MAEN! Aya kasalahan dina baris %d: " RESET 
                    "Variabel '%s' teh tipe 'nomer' (int), teu bisa diisi ku '%s'!\n", 
                    curr_line + 1, lhs, rhs);
             error = 1;
        }
    }

    sprintf(line, "%s = %s;", lhs, rhs);
}