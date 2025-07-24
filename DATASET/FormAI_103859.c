//FormAI DATASET v1.0 Category: Syntax parsing ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Welcome to the wackiest C Syntax parsing program ever made!\n");
  printf("Are you ready? Let's get started!\n");

  char input[1000];
  printf("Enter a line of code to parse: ");
  fgets(input, 1000, stdin);

  int i, parentheses = 0, brackets = 0, curly_brackets = 0;
  for (i = 0; input[i] != '\n'; i++) {
    if (input[i] == '(') {
      parentheses++;
    } else if (input[i] == ')') {
      parentheses--;
      if (parentheses < 0) {
        printf("Oops, too many closing parentheses!\n");
        printf("Here's some more code to fix it:\n");
        printf("while (1) {\n");
        printf("}\n");
        exit(0);
      }
    } else if (input[i] == '[') {
      brackets++;
    } else if (input[i] == ']') {
      brackets--;
      if (brackets < 0) {
        printf("Oops, too many closing brackets!\n");
        printf("Here's some more code to fix it:\n");
        printf("int main() {\n");
        printf("while (1) {\n");
        printf("}\n");
        printf("}\n");
        exit(0);
      }
    } else if (input[i] == '{') {
      curly_brackets++;
    } else if (input[i] == '}') {
      curly_brackets--;
      if (curly_brackets < 0) {
        printf("Oops, too many closing curly brackets!\n");
        printf("Here's some more code to fix it:\n");
        printf("int main() {\n");
        printf("if (1) {\n");
        printf("}\n");
        printf("}\n");
        exit(0);
      }
    }
  }

  if (parentheses > 0) {
    printf("Oops, too many opening parentheses!\n");
    printf("Here's some more code to fix it:\n");
    printf("while (1) {\n");
    printf("}\n");
    exit(0);
  } else if (brackets > 0) {
    printf("Oops, too many opening brackets!\n");
    printf("Here's some more code to fix it:\n");
    printf("int main() {\n");
    printf("while (1) {\n");
    printf("}\n");
    printf("}\n");
    exit(0);
  } else if (curly_brackets > 0) {
    printf("Oops, too many opening curly brackets!\n");
    printf("Here's some more code to fix it:\n");
    printf("int main() {\n");
    printf("if (1) {\n");
    printf("}\n");
    printf("}\n");
    exit(0);
  } else {
    printf("Congratulations, your code is perfectly parsed!\n");
    printf("You must be a coding genius!\n");
    return 0;
  }
}