#include "lib/logics/lexer/lexer.h"
#include "lib/logics/parser/parser.h"

// kalau kamu mau ngoding di cmd, uncomment kode di bawah, dan int main yang arg sampe read, jadiin komen atau hapus aja    
// int main(){
//     readFromStdin();

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <sundaLang-file>\n", argv[0]);
        return 1;
    }
    read(argv[1]);

    pisahbaris(tape);
    tape[0] = '\0';
    startLine();
    while (1) {
        // tokenisasi baris sebelum parsing
        tokenizeLine(argv[1], getLine(), curr_line + 1);

        // parsing line yang kita miliki dengan memanggil prosedur mainParser
        mainParser(getLine());

        // setelah parsing dilakukan, simpan hasil parsing an ke dalam string tape
        strcat(tape, getLine());
        strcat(tape, "\n");

        // jika sudah line terakhir, break
        if (isLastLine()) break;

        nextLine();
    }

    if(!error){ // jika tidak ditemukan error
        printf(GREEN "Interpretation successful!\n" RESET); // print success
        
        // Buat nama output berdasarkan nama file input
        char outputName[256];
        char cFile[256];
        strcpy(outputName, argv[1]);
        char *dot = strrchr(outputName, '.');
        if (dot != NULL) *dot = '\0'; // Hilangkan ekstensi .sundaLang
        
        sprintf(cFile, "%s.c", outputName);
        write(cFile); // Simpan hasil transpiling ke file .c
        
        char command[512];
        #ifdef _WIN32
            sprintf(command, "gcc %s -o %s && %s", cFile, outputName, outputName);
        #else
            sprintf(command, "gcc %s -o %s && ./%s", cFile, outputName, outputName);
        #endif
        
        system(command);
        
        // Hapus file C perantara agar folder tetap bersih, tapi simpan EXE-nya
        remove(cFile); 
    }else{ // jika ditemukan error
        printf(RED "Interpretation failed!\n" RESET); // print failed
    }
    
    return 0;
}
