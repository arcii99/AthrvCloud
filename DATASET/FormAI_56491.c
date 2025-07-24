//FormAI DATASET v1.0 Category: Syntax parsing ; Style: brave
#include <stdio.h>

int main() {
  printf("Welcome to C Syntax Parsing Example Program!\n");
  char input[1000];
  printf("Enter the C code to parse:\n");
  fgets(input, 1000, stdin);
  int i = 0;
  int bracket_count = 0;
  char last_char = '\0';
  while (input[i] != '\0') {
    if (input[i] == '{') {
      bracket_count++;
      if (last_char != '\n') {
        printf("\n");
      }
      printf("{\n");
    } else if (input[i] == '}') {
      bracket_count--;
      if (last_char != '\n') {
        printf("\n");
      }
      printf("}\n");
    } else if (input[i] == ';') {
      if (last_char != '\n') {
        printf("\n");
      }
      printf(";\n");
    } else if ((input[i] == '\n' && (bracket_count > 0))) {
        for (int j = 0; j < bracket_count; j++) {
            printf("  ");
        }
        printf("\n");
    } else if ((input[i] == '\n' && (bracket_count == 0))) {
      printf("\n");
    } else {
      printf("%c", input[i]);
    }
    last_char = input[i];
    i++;
  }
  return 0;
}