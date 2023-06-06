# nthcompiler

This project is a mini compiler for assembly code files with the .nth extension. The compiler is implemented in C and aims to provide a seamless compilation process for basic arithmetic operations.

## Features

- **Lexer:** The lexer scans the assembly code file and breaks it into individual tokens such as instructions, registers, operands, newlines, and end-of-file markers.

- **Parser:** The parser analyzes the sequence of tokens and verifies if they conform to the expected grammar of the assembly code. It ensures the correct usage of instructions and operands and outputs any encountered errors during parsing.

- **Semantic Analysis:** The compiler performs semantic analysis to check for potential errors and inconsistencies in the assembly code. It verifies the correctness of instruction usage and checks for operand compatibility.

- **Code Generation:** The compiler generates target code based on the compiled instructions. It converts the assembly code into machine-readable instructions.

- **Output Generation:** The compiler generates an output file containing the compiled instructions, ready to be executed on a target machine.

## Usage

1. Write your assembly code in a file with the .nth extension.

2. Compile the compiler using the provided makefile or by running the necessary compilation commands.

3. Run the compiler executable, providing your assembly code file as input.

4. The compiler will tokenize, parse, perform semantic analysis, generate target code, and produce an output file with the compiled instructions.

5. Execute the output file on the target machine to perform the desired arithmetic operations.

## Usage 1

1. Write your assembly code in a file with the .nth extension.

2. Compile the compiler using the provided makefile or by running the necessary compilation commands.

3. To compile the file and generate the output in one step, run the following command:

Replace `"filename.nth"` with the name of your assembly code file.

4. Alternatively, you can run each step of the compiler construction process individually:
- Lexer: Tokenize the assembly code file.
  ```
  ./lexer "filename.nth"
  ```

- Parser: Parse the tokenized assembly code file.
  ```
  ./parser "filename.nth"
  ```

- Semantic Analysis: Perform semantic analysis on the parsed assembly code file.
  ```
  ./semantics "filename.nth"
  ```

- Code Generation: Generate target code from the semantically analyzed assembly code file.
  ```
  ./codegen "filename.nth"
  ```

Running each step individually can be helpful for understanding the inner workings of the compiler and debugging specific stages.

5. The compiler will produce an output file with the compiled instructions or display any encountered errors during the compilation process.

6. Execute the output file on the target machine to perform the desired arithmetic operations.

## Contributing

Contributions to this project are welcome! If you find any issues or have suggestions for improvements, please feel free to submit a pull request or open an issue.

## License

This project is licensed under the [MIT License](LICENSE).


