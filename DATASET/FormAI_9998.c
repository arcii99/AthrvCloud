//FormAI DATASET v1.0 Category: Syntax parsing ; Style: minimalist
#include <stdio.h>
#include <string.h>

int main() {
  char input[1000];
  printf("Enter a line of C code:\n");
  fgets(input, 1000, stdin);
  char delimiters[] = " ,();\n\t";
  char* token = strtok(input, delimiters);
  
  printf("\nParsed tokens:\n");
  while (token != NULL) {
      printf("%s\n", token);
      token = strtok(NULL, delimiters);
  }
  
  return 0;
}