#include <stdio.h>
#include "lexer.h"
#include "parser.h"
#include "semantics.h"
#include "codegen.h"
#include "outputgen.h"

void print_instruction(InstructionNode node) {
    printf("Instruction: %s\n", node.instruction.lexeme);
    printf("Destination: %s\n", node.destination.lexeme);
    printf("Source 1: %s\n", node.source1.lexeme);
    printf("Source 2: %s\n", node.source2.lexeme);
    printf("-------------------\n");
}

int main() {
    const char* filename = "test.nth";
    const char* output_filename = "output.txt";
    lexer_init(filename);

    Token instruction_token, destination_token, source1_token, source2_token;
    InstructionNode instructions[MAX_INSTRUCTIONS];
    int num_instructions = 0;

    do {
        instruction_token = lexer_get_next_token();
        destination_token = lexer_get_next_token();
        source1_token = lexer_get_next_token();
        source2_token = lexer_get_next_token();

        if (instruction_token.type != TOKEN_EOF) {
            InstructionNode node = parse_instruction(instruction_token, destination_token, source1_token, source2_token);
            instructions[num_instructions++] = node;
            print_instruction(node);
        }
    } while (instruction_token.type != TOKEN_EOF);

    lexer_cleanup();

    perform_semantic_analysis(instructions, num_instructions);

    generate_code(instructions, num_instructions);

    generate_output(instructions, num_instructions, output_filename);

    // Cleanup
    for (int i = 0; i < num_instructions; i++) {
        free_instruction_node(&instructions[i]);
    }

    return 0;
}
