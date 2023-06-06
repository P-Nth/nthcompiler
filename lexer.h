#ifndef LEXER_H
#define LEXER_H

// Token types
typedef enum {
    TOKEN_INSTRUCTION,
    TOKEN_REGISTER,
    TOKEN_OPERAND,
    TOKEN_ADDITION,        // Addition operation
    TOKEN_SUBTRACTION,     // Subtraction operation
    TOKEN_MULTIPLICATION,  // Multiplication operation
    TOKEN_IMMEDIATE,
    TOKEN_DIVISION,        // Division operation
    TOKEN_NEWLINE,
    TOKEN_EOF
    // Add more token types as needed
} TokenType;

// Token structure
typedef struct {
    TokenType type;
    char* lexeme;
    int line;
} Token;

// Function declarations
void lexer_init(const char* filename);
Token lexer_get_next_token();
void lexer_cleanup();

#endif
