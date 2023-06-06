#include <stdio.h>
#include "codegen.h"

void generate_code(InstructionNode* instructions, int num_instructions) {
    printf("Generated Code:\n");

    for (int i = 0; i < num_instructions; i++) {
        InstructionNode instruction = instructions[i];

        printf("%s %s, %s, %s\n", instruction.instruction.lexeme, instruction.destination.lexeme,
               instruction.source1.lexeme, instruction.source2.lexeme);
    }
}
