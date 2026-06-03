#include "lib/logics/lexer/lexer.h"
#include "lib/logics/parser/parser.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <sundaLang-file>\n", argv[0]);
        return 1;
    }

    ir_mode = 1; // Enable IR mode
    read(argv[1]);

    printf("\n" GREEN "// Oneple (1-address code) output:" RESET "\n");

    pisahbaris(tape);
    tape[0] = '\0';
    startLine();
    while (1) {
        char line_buffer[5005];
        strcpy(line_buffer, getLine());

        // tokenisasi baris
        tokenizeLine(argv[1], line_buffer, curr_line + 1);

        // generate IR instead of parsing to C
        generateIR(line_buffer);

        printf("%s\n", line_buffer);

        if (isLastLine()) break;
        nextLine();
    }

    if(error){
        printf(RED "Error encountered during IR generation!\n" RESET);
    }
    
    return 0;
}
