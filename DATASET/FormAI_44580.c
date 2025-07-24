//FormAI DATASET v1.0 Category: Syntax parsing ; Style: interoperable
#include <stdio.h>

int main() {
  char input[100];
  printf("Enter a C syntax statement:\n");
  fgets(input, 100, stdin); // get user input
  int i = 0;
  int braces = 0, parentheses = 0, brackets = 0;
  while (input[i] != '\0') { // traverse string
    if (input[i] == '{') { 
      braces++;
    }
    if (input[i] == '}') { 
      braces--;
    }
    if (input[i] == '(') { 
      parentheses++;
    }
    if (input[i] == ')') { 
      parentheses--;
    }
    if (input[i] == '[') { 
      brackets++;
    }
    if (input[i] == ']') { 
      brackets--;
    }
    if (braces < 0 || parentheses < 0 || brackets < 0) { // check for mismatched delimiters
      printf("Error: Mismatched delimiters!\n");
      return 0;
    }
    i++;
  }
  if (braces == 0 && parentheses == 0 && brackets == 0) { // check for balanced delimiters
    printf("Correct syntax!\n");
  } else {
    printf("Error: Unbalanced delimiters!\n");
  }
  return 0; 
}