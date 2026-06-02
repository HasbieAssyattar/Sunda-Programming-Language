#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../lexer/lexer.h"

// Deklarasi prosedur 
void mainParser(char* line);                                            // untuk memproses string baris menjadi bahasa c (parsing)
void parserOperator(char *token, char* str);                            // untuk memparsing operator
void parserStrcmp(char* left, char* op, char* right, char* result);     // untuk memparsing operator (untuk string)
void parserAuraOperation(char pita[]);                                  // untuk parsing aura (increment/ decrement)
void parseAssignment(char* line);                                       // untuk memparsing assignment
void skibidi(char* line);                                               // untuk memparsing token tipe data int
void skibidiToilet(char* line);                                         // untuk memparsing token tipe data float
void sigma(char* line);                                                 // untuk memparsing token tipe data char
void sigmaBoy(char* line);                                              // untuk memparsing token tipe data string
void asupkeun(char* line);                                                 // untuk memparsing token fungsi scanf
void ngagorowok(char* line);                                             // untuk memparsing token fungsi printf
void muter(char* line);                                                 // untuk memparsing token keyword for
void keur(char* line);                                                  // untuk memparsing token keyword while
void mun(char* line);                                                   // untuk memparsing token keyword if
void munteu(char* line);                                                // untuk memparsing token keyword else if
void teu(char* line);                                                   // untuk memparsing token keyword else
