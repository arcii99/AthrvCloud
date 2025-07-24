//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: curious
#include <stdio.h>

int main() {
  printf("Welcome to the C Alien Language Translator!\n");
  
  char input[1000];
  printf("Please enter a phrase in the C Alien Language:\n");
  fgets(input, 1000, stdin);

  printf("Translation: ");
  for (int i = 0; input[i] != '\0'; i++) {
    if (input[i] == 'c') {
      printf("kl");
    } else if (input[i] == 'C') {
      printf("KL");
    } else if (input[i] == ' ') {
      printf(" ");
    } else {
      printf("%c", input[i]);
    }
  }

  printf("\nThank you for using the C Alien Language Translator! We hope to see you again soon.\n");

  return 0;
}