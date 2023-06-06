#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

#define MAX_INSTRUCTIONS 100

typedef struct {
    TokenType type;
    char* lexeme;
} Instruction;

typedef struct {
    TokenType type;
    char* lexeme;
} Register;

typedef struct {
    TokenType type;
    char* lexeme;
    int value;
} Operand;

typedef struct {
    Instruction instruction;
    Register destination;
    Operand source1;
    Operand source2;
} InstructionNode;

InstructionNode parse_instruction(Token instruction_token, Token destination_token, Token source1_token, Token source2_token);
void free_instruction_node(InstructionNode* node);

#endif
