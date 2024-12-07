# Turing-complete programming language

## Project Overview

This project is a custom programming language interpreter written in C++. It supports basic arithmetic operations, conditional statements, loops, and variable manipulation. The interpreter converts high-level code into Reverse Polish Notation (RPN) and evaluates it, enabling the execution of simple scripts with variables, expressions, `print`, `println`, and `read` commands.

### Key Features

- **Arithmetic Operations**: Supports addition, subtraction, multiplication, division, modulo, and exponentiation.
- **Logical Operations**: Includes logical operators such as AND (`&&`), OR (`||`), and bitwise operations (`^`, `|`, `&`).
- **Comparison Operators**: Handles comparison operations (`>`, `<`, `>=`, `<=`, `==`, `!=`).
- **Conditional Statements**: Implements `if` statements for conditional execution.
- **Loops**: Supports `while` loops for repeated execution based on a condition.
- **Variable Handling**: Allows defining variables and using them in expressions.
- **Input/Output**: Supports reading from user input and printing output to the console.

## How It Works

### Parsing and Tokenization

The interpreter reads input as a string and splits it into tokens for further processing. It supports whitespace trimming and string parsing to manage the syntax effectively.

### Conversion to Reverse Polish Notation (RPN)

To evaluate mathematical expressions correctly, the interpreter converts infix notation (e.g., `3 + 5 * 2`) to postfix notation (e.g., `3 5 2 * +`) using the Shunting Yard algorithm.

### Expression Evaluation

The interpreter processes expressions in RPN using a stack to evaluate them based on operator precedence and associativity. This allows for evaluating complex expressions while handling errors like division by zero and power of zero.

### Execution Flow

The `main()` function reads from a file or uses embedded code for testing. It splits the code into lines, and each line is parsed and executed in sequence:
- **Read commands** store input values into variables.
- **Print and println** commands output values or strings to the console.
- **If statements** execute a block of code if the condition evaluates to true.
- **While loops** repeatedly execute a block of code as long as the condition is true.

## Code Structure

### Main Components

- **`trim()`**: Trims leading and trailing spaces from a string.
- **`split()`**: Splits a string into tokens based on a delimiter.
- **`isAllDigits()`**: Checks if a string contains only digits.
- **`isAllAlpha()`**: Checks if a string contains only alphabetic characters.
- **`isOperator()`**: Checks if a string is a valid operator.
- **`getPrecedence()`**: Returns the precedence of an operator.
- **`normalToRPN()`**: Converts an infix expression to RPN.
- **`evaluate()`**: Evaluates an expression in RPN and returns the result.
- **`executeInstruction()`**: Executes a single line of code.
- **`executeIfStatement()`**: Handles `if` statements.
- **`executeWhileLoop()`**: Handles `while` loops.
- **`handleInputLines()`**: Processes all lines from the input and executes them.

### Error Handling

The interpreter includes robust error handling for:
- **Syntax errors**: Invalid tokens or expressions.
- **Division by zero**: Checked before division operations.
- **Undefined variables**: Attempting to access variables not defined.
- **Infinite loops**: Limits the number of loop iterations to prevent non-termination.

### Supported Keyword
| <b><i>Keyword</b></i>       | <b><i>Description</b></i> |    <b><i>Syntax</b></i>                                                                     |
|-----------------|-------|-----------------------------------------------------------------------------------------------------------------------------------------|
| `read`  | Used to read user input and store it in a variable | `read <variableName>`                                                                                                                    |
| `print`  | Used to print the variables or a strings output without moving to a new line |`print <variableName>`<br>`print "Hello, World!"`                                                                         |                                                                                            
| `println`  |  Used to print the variables or a strings output with a newline at the end. |`println <variableName>`<br>`println "Hello, World!"`                                                                           |                                                                                               
| `if`  | Used for conditional execution based on whether a condition is true |  `if <condition>`<br>&nbsp;&nbsp;&nbsp;&nbsp;`<block of code>`<br>&nbsp;&nbsp;&nbsp;&nbsp;`<block of code>`<br>&nbsp;&nbsp;&nbsp;&nbsp;`<block of code>`                                                                              |                                                                                           
| `while`  | Used to create a loop that repeats a block of code while a given condition is true | `while <condition>`<br>&nbsp;&nbsp;&nbsp;&nbsp;`<block of code>`<br>&nbsp;&nbsp;&nbsp;&nbsp;`<block of code>`<br>&nbsp;&nbsp;&nbsp;&nbsp;`<block of code>`                                                                               |                                                                                                    |                                                                              |                     

### Supported operator types
| <b><i>Operation</b></i> | <b><i>Description</b></i> |
|----------------|-------|
| `+`   | Adds two numbers |
| `-`   | Subtracts the second number from the first |
| `*`   | Multiplies two numbers |
| `/`   | Divides the first number by the second. Results in an error if dividing by zero |
| `%`   | Returns the remainder of dividing the first number by the second |
| `**`   | Raises the first number to the power of the second number |
| `>`   | Checks if the first value is greater than the second |
| `<`   | Checks if the first value is less than the second |
| `>=`   | Checks if the first value is greater than or equal to the second |
| `<=`   | Checks if the first value is less than or equal to the second |
| `==`   | Checks if the first value is equal to the second |
| `!=`   | Checks if the first value is not equal to the second |
| `\|\|`   | Returns true if at least one of the conditions is true |
| `&&`   | Returns true if both conditions are true |
| `^`   | Performs a bitwise XOR operation on two numbers |
| `\|`   | Performs a bitwise OR operation on two numbers |
| `&`   | Performs a bitwise AND operation on two numbers |

## How to Use

### Direct Code Input

Modify the embedded `instructions` string in the `main()` function for quick testing.

### File Input

Run the program with a file containing the code as an argument:
```bash
./interpreter inputFile.txt
```
Ensure the file is formatted correctly, with lines of code and proper indentation for `if` and `while` blocks.

## Example Code

### Sample Code to Test the Interpreter:

```plaintext
read test
while test > 0
    read a
    read b
    b - a
    test = test - 1
```

### Input/Output:

The program reads values for `test`, `a`, and `b`, performs operations as specified, and prints the results.

## Installation and Running

### Clone the Repository and Navigate to the Project

```bash
git clone https://github.com/yourusername/your-repo.git
cd your-repo
```

### Compile the Code

```bash
g++ -o interpreter interpreter.cpp
```

### Run the Compiled Program

```bash
./interpreter inputFile.txt
```

## Running the Program

1. **Compile** the `interpreter.cpp` source file to create an executable:
   ```bash
   g++ -o interpreter interpreter.cpp
   ```

2. **Run** the compiled program with your input file:
   ```bash
   ./interpreter inputFile.txt
   ```
   This command processes `inputFile.txt` and provides the output based on the script's instructions.


## Future Enhancements

- Add support for recurssion.
- Add support for functions and subroutines.
- Implement more data types (e.g., floats, strings).
- Improve error handling and debugging features.
- Create a more sophisticated parser for complex syntax.

## Contributing

We welcome contributions from the community! If you’d like to contribute to this project, please follow these steps:

1. **Fork the repository** to create your own copy of the project.
2. **Clone your fork** to your local machine.
3. **Create a new branch** for your feature or bug fix.
4. **Make your changes** and test them thoroughly.
5. **Commit your changes** with descriptive commit messages.
6. **Push your branch** to your fork.
7. **Submit a pull request** to the main repository and describe your changes in detail.

We appreciate your help in making this project better. Your contributions help us add new features, improve performance, and fix any issues. Thank you for your support!
