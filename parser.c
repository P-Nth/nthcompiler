#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

InstructionNode parse_instruction(Token instruction_token, Token destination_token, Token source1_token, Token source2_token) {
    InstructionNode node;

    node.instruction.type = instruction_token.type;
    node.instruction.lexeme = strdup(instruction_token.lexeme);

    node.destination.type = destination_token.type;
    node.destination.lexeme = strdup(destination_token.lexeme);

    if (source1_token.type == TOKEN_IMMEDIATE) {
        node.source1.type = source1_token.type;
        node.source1.lexeme = strdup(source1_token.lexeme);
        node.source1.value = atoi(&source1_token.lexeme[1]);  // Convert immediate value to integer
    } else {
        node.source1.type = source1_token.type;
        node.source1.lexeme = strdup(source1_token.lexeme);
        node.source1.value = 0;  // Set value to 0 for non-immediate operands
    }

    if (source2_token.type == TOKEN_IMMEDIATE) {
        node.source2.type = source2_token.type;
        node.source2.lexeme = strdup(source2_token.lexeme);
        node.source2.value = atoi(&source2_token.lexeme[1]);  // Convert immediate value to integer
    } else {
        node.source2.type = source2_token.type;
        node.source2.lexeme = strdup(source2_token.lexeme);
        node.source2.value = 0;  // Set value to 0 for non-immediate operands
    }

    return node;
}

void free_instruction_node(InstructionNode* node) {
    free(node->instruction.lexeme);
    free(node->destination.lexeme);
    free(node->source1.lexeme);
    free(node->source2.lexeme);
}

