#include "lib/logics/lexer/lexer.h"
#include "lib/logics/parser/parser.h"

void printHeader() {
    printf("\n" GREEN "=== SUNDALANG TOKENIZER OUTPUT ===" RESET "\n");
    printf("+----------------------+----------------------+\n");
    printf("| %-20s | %-20s |\n", "LEXEME", "TOKEN TYPE");
    printf("+----------------------+----------------------+\n");
}

void printFooter() {
    printf("+----------------------+----------------------+\n\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <sundaLang-file>\n", argv[0]);
        return 1;
    }

    oneple_mode = 1; // Aktifkan mode oneple
    read(argv[1]);

    printHeader();

    pisahbaris(tape);
    tape[0] = '\0';
    startLine();
    while (1) {
        // tokenisasi baris
        tokenizeLine(argv[1], getLine(), curr_line + 1);

        // parsing line (tetap lakukan parsing agar bisa compile)
        mainParser(getLine());

        strcat(tape, getLine());
        strcat(tape, "\n");

        if (isLastLine()) break;
        nextLine();
    }

    printFooter();

    if(!error){
        printf(GREEN "Interpretation successful!" RESET " Compiling...\n");
        
        char outputName[256];
        char cFile[256];
        strcpy(outputName, argv[1]);
        char *dot = strrchr(outputName, '.');
        if (dot != NULL) *dot = '\0';
        
        sprintf(cFile, "%s.c", outputName);
        write(cFile);
        
        char command[512];
        #ifdef _WIN32
            sprintf(command, "gcc %s -o %s && %s", cFile, outputName, outputName);
        #else
            sprintf(command, "gcc %s -o %s && ./%s", cFile, outputName, outputName);
        #endif
        
        printf("\n" WHITE "--- Program Output ---" RESET "\n");
        system(command);
        printf("\n" WHITE "----------------------" RESET "\n");
        
        remove(cFile); 
    } else {
        printf(RED "Interpretation failed!\n" RESET);
    }
    
    return 0;
}
