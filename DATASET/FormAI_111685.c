//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  char output[100];
  printf("Welcome to the C Cat Language Translator!\n");
  printf("Please enter your sentence in C Cat Language:\n");
  fgets(input, 100, stdin);
  
  int length = strlen(input);
  
  /* Translate C Cat Language into English */
  for (int i = 0; i < length; i++) {
    switch (input[i]) {
      case 'M': // meow -> I
        strcat(output, "I");
        break;
      case 'P': // purr -> like
        strcat(output, "like");
        break;
      case 'F': // fish -> food
        strcat(output, "food");
        break;
      case 'W': // with -> and
        strcat(output, "and");
        break;
      case 'T': // toy -> play
        strcat(output, "play");
        break;
      case '\n': // remove newline character
        strcat(output, " ");
        break;
      default:
        strcat(output, " ");
        break;
    }
  }
  
  printf("\nTranslation: %s", output);
  printf("\nThank you for using the C Cat Language Translator!");
  
  return 0;
}