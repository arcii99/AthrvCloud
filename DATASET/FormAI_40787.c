//FormAI DATASET v1.0 Category: Text processing ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[100];
  printf("Please enter a sentence: ");
  fgets(input, 100, stdin);

  for(int i = 0; i < strlen(input); i++) {
    if (input[i] == 'e') {
      printf("%c", 'i');
    } else if (input[i] == 'a') {
      printf("%c", 'u');
    } else if (input[i] == 'o') {
      printf("%c", 'e');
    } else if (input[i] == 'i') {
      printf("%c", 'o');
    } else if (input[i] == 'u') {
      printf("%c", 'a');
    } else {
      printf("%c", input[i]);
    }
  }
  printf("\n");

  return 0;
}