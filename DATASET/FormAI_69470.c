//FormAI DATASET v1.0 Category: Syntax parsing ; Style: ephemeral
#include <stdio.h>

int main() {

  // Ephemeral C Syntax Parsing Example Program
  // ==========================================
  
  /*
  This program will parse a simple C code file and output the variables and functions declared in it.
  To keep with the ephemeral nature of this program, the code we will be parsing is the classic "Hello, World!"
  */

  char* code = "#include <stdio.h>\n\nint main() {\n\n    printf(\"Hello, World!\\n\");\n    return 0;\n}\n";

  // Parsing the code
  // ================

  /*
  First, we will count the number of variables and functions declared in the code.
  For this program, we will only consider variables declared at the start of the main function.
  */

  int variable_count = 0;
  int function_count = 1; // main() function is always present

  int i = 0;
  while (code[i]) {
    if (code[i] == '\n' && code[i+1] == '\n') { // We have reached the start of the main function
        break;
    }

    if (code[i] == '\n') {
      i++; // Skip empty lines
      continue;
    }

    if ((code[i] == 'c' && code[i+1] == 'h') || (code[i] == 's' && code[i+1] == 't')) { // We have encountered a include statement, skip this line
      while (code[i] != '\n') {
          i++;
      }
      continue;
    }

    if (code[i] == 'i' && code[i+1] == 'n' && code[i+2] == 't') { // We have found a variable declaration
        variable_count++;
    }
    i++;
  }

  printf("Variables declared: %d\n", variable_count);
  printf("Functions declared: %d\n", function_count);

  return 0;
}