#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semantics.h"

void perform_semantic_analysis(InstructionNode* instructions, int num_instructions) {
    // Symbol Table to store the values of registers and labels
    Symbol symbol_table[8];
    int num_symbols = 0;

    for (int i = 0; i < num_instructions; i++) {
        // Process the destination register
        if (instructions[i].destination.type == TOKEN_REGISTER) {
            // Check if the register is already in the symbol table
            int register_index = -1;
            for (int j = 0; j < num_symbols; j++) {
                if (strcmp(symbol_table[j].lexeme, instructions[i].destination.lexeme) == 0) {
                    register_index = j;
                    break;
                }
            }

            // If register is not in the symbol table, add it with a value of 0
            if (register_index == -1) {
                symbol_table[num_symbols].lexeme = strdup(instructions[i].destination.lexeme);
                symbol_table[num_symbols].value = 0;
                num_symbols++;
            }
        }

        // Process the source operands
        if (instructions[i].source1.type == TOKEN_REGISTER) {
            // Check if the register is already in the symbol table
            int register_index = -1;
            for (int j = 0; j < num_symbols; j++) {
                if (strcmp(symbol_table[j].lexeme, instructions[i].source1.lexeme) == 0) {
                    register_index = j;
                    break;
                }
            }

            // If register is not in the symbol table, add it with a value of 0
            if (register_index == -1) {
                symbol_table[num_symbols].lexeme = strdup(instructions[i].source1.lexeme);
                symbol_table[num_symbols].value = 0;
                num_symbols++;
            }
        }

        if (instructions[i].source2.type == TOKEN_REGISTER) {
            // Check if the register is already in the symbol table
            int register_index = -1;
            for (int j = 0; j < num_symbols; j++) {
                if (strcmp(symbol_table[j].lexeme, instructions[i].source2.lexeme) == 0) {
                    register_index = j;
                    break;
                }
            }

            // If register is not in the symbol table, add it with a value of 0
            if (register_index == -1) {
                symbol_table[num_symbols].lexeme = strdup(instructions[i].source2.lexeme);
                symbol_table[num_symbols].value = 0;
                num_symbols++;
            }
        }
    }

    // Print the symbol table
    printf("Symbol Table:\n");
    print_symbol_table(symbol_table, num_symbols);
}

void print_symbol_table(Symbol* symbol_table, int num_symbols) {
    for (int i = 0; i < num_symbols; i++) {
        printf("%s: %d\n", symbol_table[i].lexeme, symbol_table[i].value);
    }
}

void free_symbol_table(Symbol* symbol_table, int num_symbols) {
    for (int i = 0; i < num_symbols; i++) {
        free(symbol_table[i].lexeme);
    }
}
