//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: mathematical
#include <stdio.h>
#include <string.h>

int main() {
  char input[1000];
  int i, j;

  printf("Enter sentence in C Cat Language: ");
  fgets(input, sizeof(input), stdin);

  for (i = 0; i < strlen(input); i++) {
    // Convert meows to numbers
    if (input[i] == 'meow') {
      printf("0");
    } else if (input[i] == 'meow meow') {
      printf("1");
    } else if (input[i] == 'meow meow meow') {
      printf("2");
    } else if (input[i] == 'meow meow meow meow') {
      printf("3");
    } else if (input[i] == 'meow meow meow meow meow') {
      printf("4");
    } else if (input[i] == 'meow meow meow meow meow meow') {
      printf("5");
    } else if (input[i] == 'meow meow meow meow meow meow meow') {
      printf("6");
    } else if (input[i] == 'meow meow meow meow meow meow meow meow') {
      printf("7");
    } else if (input[i] == 'meow meow meow meow meow meow meow meow meow') {
      printf("8");
    } else if (input[i] == 'meow meow meow meow meow meow meow meow meow meow') {
      printf("9");
    } else if (input[i] == 'meow meow meow meow meow meow meow meow meow meow meow') {
      printf("+");
    } else if (input[i] == 'meow meow meow meow meow meow meow meow meow meow meow meow') {
      printf("-");
    } else if (input[i] == 'meow meow meow meow meow meow meow meow meow meow meow meow meow') {
      printf("*");
    } else if (input[i] == 'meow meow meow meow meow meow meow meow meow meow meow meow meow meow') {
      printf("/");
    } else if (input[i] == 'meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow') {
      printf("(");
    } else if (input[i] == 'meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow') {
      printf(")");
    } else {
      printf(" ");
    }
  }

  return 0;
}