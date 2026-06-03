#include "parser.h"
#include "../lexer/lexer.h"

void generateIR(char* line) {
    start(line);
    if (line[0] == '\0' || strcmp(getcw(), "") == 0) return;

    char first_word[100];
    strcpy(first_word, getcw());

    char ir_output[1000] = "";
    char lhs[100] = "";
    char rhs[500] = "";

    // Handle Variable Declaration: nomer x nyaeta 5
    if (strcmp(first_word, "nomer") == 0 || 
        strcmp(first_word, "koma") == 0 || 
        strcmp(first_word, "legeg") == 0 || 
        strcmp(first_word, "legegpican") == 0) {
        
        inc(line); // skip type
        strcpy(lhs, getcw());
        addVariable(lhs, first_word);

        inc(line); // check if nyaeta
        if (strcmp(getcw(), "nyaeta") == 0) {
            inc(line);
            // Simple expression parsing for IR
            // For now, handle: val, var, or var op val
            char op1[100];
            strcpy(op1, getcw());
            
            sprintf(ir_output, "LOAD %s\n", op1);
            
            if (!eop(line)) {
                inc(line);
                while (!eop(line)) {
                    char op[10];
                    char op2[100];
                    strcpy(op, getcw());
                    inc(line);
                    strcpy(op2, getcw());

                    if (strcmp(op, "+") == 0) strcat(ir_output, "ADD ");
                    else if (strcmp(op, "-") == 0) strcat(ir_output, "SUB ");
                    else if (strcmp(op, "*") == 0) strcat(ir_output, "MUL ");
                    else if (strcmp(op, "/") == 0) strcat(ir_output, "DIV ");
                    else if (strcmp(op, "%") == 0) strcat(ir_output, "MOD ");
                    
                    strcat(ir_output, op2);
                    strcat(ir_output, "\n");
                    
                    if (eop(line)) break;
                    inc(line);
                }
            }
            strcat(ir_output, "STORE ");
            strcat(ir_output, lhs);
        } else {
            // Just declaration, no IR needed usually, or just reserve space
            sprintf(ir_output, "// DECLARE %s", lhs);
        }
    }
    // Handle Assignment: x nyaeta 10
    else if (strstr(line, "nyaeta") != NULL) {
        strcpy(lhs, first_word);
        inc(line); // skip to nyaeta
        inc(line); // skip nyaeta to rhs
        
        char op1[100];
        strcpy(op1, getcw());
        sprintf(ir_output, "LOAD %s\n", op1);

        while (!eop(line)) {
            inc(line);
            char op[10];
            char op2[100];
            strcpy(op, getcw());
            inc(line);
            strcpy(op2, getcw());

            if (strcmp(op, "+") == 0) strcat(ir_output, "ADD ");
            else if (strcmp(op, "-") == 0) strcat(ir_output, "SUB ");
            else if (strcmp(op, "*") == 0) strcat(ir_output, "MUL ");
            else if (strcmp(op, "/") == 0) strcat(ir_output, "DIV ");
            else if (strcmp(op, "%") == 0) strcat(ir_output, "MOD ");
            
            strcat(ir_output, op2);
            strcat(ir_output, "\n");
        }
        strcat(ir_output, "STORE ");
        strcat(ir_output, lhs);
    }
    // Handle Output: ngagorowok(x)
    else if (strncmp(first_word, "ngagorowok", 10) == 0) {
        if (first_word[10] == '(') {
            // Case ngagorowok(y)
            char *start_ptr = strchr(first_word, '(');
            char *end_ptr = strchr(first_word, ')');
            if (start_ptr && end_ptr) {
                *end_ptr = '\0';
                sprintf(ir_output, "WRITE %s", start_ptr + 1);
            } else if (start_ptr) {
                // maybe arg is in next word
                inc(line);
                sprintf(ir_output, "WRITE %s", getcw());
            }
        } else {
            inc(line); // skip (
            inc(line); // get var/val
            sprintf(ir_output, "WRITE %s", getcw());
        }
    }
    // Handle Input: asupkeun(x)
    else if (strncmp(first_word, "asupkeun", 8) == 0) {
        if (first_word[8] == '(') {
            char *start_ptr = strchr(first_word, '(');
            char *end_ptr = strchr(first_word, ')');
            if (start_ptr && end_ptr) {
                *end_ptr = '\0';
                sprintf(ir_output, "READ %s", start_ptr + 1);
            } else if (start_ptr) {
                inc(line);
                sprintf(ir_output, "READ %s", getcw());
            }
        } else {
            inc(line); // skip (
            inc(line); // get var
            sprintf(ir_output, "READ %s", getcw());
        }
    }
    else if (strcmp(first_word, "}") == 0) {
        strcpy(ir_output, "END_BLOCK");
    }
    else if (strcmp(first_word, "nuhun") == 0) {
        strcpy(ir_output, "HALT");
    }
    else {
        sprintf(ir_output, "// %s (unsupported in IR)", first_word);
    }

    strcpy(line, ir_output);
}
