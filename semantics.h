#ifndef SEMANTICS_H
#define SEMANTICS_H

#include "parser.h"

typedef struct {
    char* lexeme;
    int value;
} Symbol;

void perform_semantic_analysis(InstructionNode* instructions, int num_instructions);
void print_symbol_table(Symbol* symbol_table, int num_symbols);
void free_symbol_table(Symbol* symbol_table, int num_symbols);

#endif
