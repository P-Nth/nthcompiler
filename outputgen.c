#include <stdio.h>
#include "outputgen.h"

void generate_output(InstructionNode* instructions, int num_instructions, const char* output_filename) {
    FILE* output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        return;
    }

    fprintf(output_file, "Generated Output:\n\n");

    for (int i = 0; i < num_instructions; i++) {
        InstructionNode instruction = instructions[i];

        fprintf(output_file, "%s %s, %s, %s\n", instruction.instruction.lexeme, instruction.destination.lexeme,
                instruction.source1.lexeme, instruction.source2.lexeme);
    }

    fclose(output_file);
    printf("Output file generated: %s\n", output_filename);
}
