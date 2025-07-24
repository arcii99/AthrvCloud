//FormAI DATASET v1.0 Category: Syntax parsing ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the mind-bending C syntax parsing program!\n");
  
  // Initialize counters and flags
  int num_open_brackets = 0;
  int num_close_brackets = 0;
  int num_semicolons = 0;
  int in_string_literal = 0;
  int in_char_literal = 0;
  int in_single_line_comment = 0;
  int in_multi_line_comment = 0;
  
  // Let's parse some code!
  char* code = "void func(int x) {\n"
               "  int y = x + 1;\n"
               "  if (y > 10) {\n"
               "    printf(\"y is greater than 10\\n\"); // print some info\n"
               "  }\n"
               "  else {\n"
               "    printf(\"y is less than or equal to 10\\n\"); /* print some more info */\n"
               "  }\n"
               "}\n";
  
  for (int i = 0; i < strlen(code); i++) {
    
    // Check if we're in a string literal
    if (code[i] == '"' && !in_char_literal && !in_single_line_comment && !in_multi_line_comment) {
      if (in_string_literal) {
        in_string_literal = 0;
      }
      else {
        in_string_literal = 1;
      }
    }
    
    // Check if we're in a character literal
    else if (code[i] == '\'' && !in_string_literal && !in_single_line_comment && !in_multi_line_comment) {
      if (in_char_literal) {
        in_char_literal = 0;
      }
      else {
        in_char_literal = 1;
      }
    }
    
    // Check if we're in a single-line comment
    else if (code[i] == '/' && !in_string_literal && !in_char_literal && !in_multi_line_comment) {
      if (code[i+1] == '/') {
        in_single_line_comment = 1;
      }
    }
    else if (in_single_line_comment && code[i] == '\n') {
      in_single_line_comment = 0;
    }
    
    // Check if we're in a multi-line comment
    else if (code[i] == '/' && !in_string_literal && !in_char_literal && !in_single_line_comment) {
      if (code[i+1] == '*') {
        in_multi_line_comment = 1;
      }
    }
    else if (in_multi_line_comment && code[i] == '*' && code[i+1] == '/') {
      in_multi_line_comment = 0;
    }
    
    // Count brackets and semicolons
    else if (!in_string_literal && !in_char_literal && !in_single_line_comment && !in_multi_line_comment) {
      if (code[i] == '{') {
        num_open_brackets++;
      }
      else if (code[i] == '}') {
        num_close_brackets++;
      }
      else if (code[i] == ';') {
        num_semicolons++;
      }
    }
  }
  
  // Output the results
  printf("Parsed code:\n%s", code);
  printf("Number of open brackets: %d\n", num_open_brackets);
  printf("Number of close brackets: %d\n", num_close_brackets);
  printf("Number of semicolons: %d\n", num_semicolons);
  
  return 0;
}