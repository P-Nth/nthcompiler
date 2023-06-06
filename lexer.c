#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"


// File pointer for the source code file
static FILE* source_file = NULL;

// Helper function to allocate memory for a new token
static Token create_token(TokenType type, const char* lexeme, int line) {
    Token token;
    token.type = type;
    token.lexeme = strdup(lexeme);
    token.line = line;
    return token;
}


// Function to initialize the lexer
void lexer_init(const char* filename) {
    source_file = fopen(filename, "r");
    if (source_file == NULL) {
        printf("Error opening source file.\n");
        exit(1);
    }
}

// Function to get the next token from the source code
Token lexer_get_next_token() {
    char buffer[256];  // Buffer to store the lexeme
    int line = 1;      // Current line number
    int ch = fgetc(source_file);
    
    // Skip whitespace characters
    while (ch == ' ' || ch == '\t') {
        ch = fgetc(source_file);
    }

    // Check for end of file
    if (ch == EOF) {
        return create_token(TOKEN_EOF, "", line);
    }

    // Check for newline
    if (ch == '\n') {
        return create_token(TOKEN_NEWLINE, "\\n", line++);
    }

    // Check for instructions, registers, operands, or arithmetic operations
    if (isalpha(ch)) {
        int i = 0;
        buffer[i++] = ch;

        while ((ch = fgetc(source_file)) != EOF && (isalnum(ch) || ch == '_')) {
            buffer[i++] = ch;
        }
        buffer[i] = '\0';

        // Determine the token type based on the lexeme
        if (strcmp(buffer, "add") == 0) {
            return create_token(TOKEN_INSTRUCTION, buffer, line);
        } else if (strcmp(buffer, "sub") == 0) {
            return create_token(TOKEN_INSTRUCTION, buffer, line);
        } else if (strcmp(buffer, "mul") == 0) {
            return create_token(TOKEN_INSTRUCTION, buffer, line);
        } else if (strcmp(buffer, "div") == 0) {
            return create_token(TOKEN_INSTRUCTION, buffer, line);
        } else if (strcmp(buffer, "eax") == 0) {
            return create_token(TOKEN_REGISTER, buffer, line);
        } else if (strcmp(buffer, "ebx") == 0) {
            return create_token(TOKEN_REGISTER, buffer, line);
        } else if (strcmp(buffer, "ecx") == 0) {
            return create_token(TOKEN_REGISTER, buffer, line);
        } else if (strcmp(buffer, "edx") == 0) {
            return create_token(TOKEN_REGISTER, buffer, line);
        } else {
            return create_token(TOKEN_OPERAND, buffer, line);
        }
    }

    // Check for immediate values
    if (ch == '#') {
        int i = 0;
        buffer[i++] = ch;

        while ((ch = fgetc(source_file)) != EOF && isdigit(ch)) {
            buffer[i++] = ch;
        }
        buffer[i] = '\0';

        return create_token(TOKEN_IMMEDIATE, buffer, line);
    }

    // Return an error token if an invalid character is encountered
    printf("Error: Invalid character '%c' at line %d\n", ch, line);
    exit(1);
}

// Function to clean up the resources used by the lexer
void lexer_cleanup() {
    if (source_file != NULL) {
        fclose(source_file);
    }
}
