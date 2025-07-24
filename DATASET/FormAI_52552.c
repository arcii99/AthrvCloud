//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: surrealist
#include <stdio.h>
#include <string.h>

// Surrealist C Alien Language Translator
int main() {
  char input[100];
  printf("Welcome to the Surrealist C Alien Language Translator! Enter a phrase to translate:\n");
  fgets(input, 100, stdin);
  input[strcspn(input, "\n")] = 0; // Remove the trailing newline character
  
  // Start Translation
  
  printf("Translating...\n");
  for(int i = 0; i < strlen(input); i++) {
    switch(input[i]) {
      case 'A':
        printf("%%||%d[.-]%%", i+3); // The letter A looks like a fancy diamond in C Alien Language, so we use the modulo operator surrounded by some brackets and dots to create a decorative effect
        break;
      case 'B':
        printf("<0_______."); // The letter B is symbolized by an alien's head
        break;
      case 'C':
        printf("((%.5d))", i * 100); // The letter C is represented by a pair of brackets enclosing a five-digit random number generated from the index of the input character
        break;
      case 'D':
        printf("~~%c~~", (i % 2 == 0) ? '-' : '/'); // Letter D is represented by two squiggles and either a dash or a forward slash depending on if the character index is even or odd
        break;
      case 'E':
        printf("`%c'", (i % 2 == 0) ? '0' : '|'); // For the letter E, we use two backticks enclosing either the digit 0 or a vertical bar for even or odd index positions
        break;
      // Rest of the translation goes here
      default:
        printf("%c", input[i]); // If the character is not recognized in the C Alien Language, then we just print it as is
        break;
    }
  }
  printf("\nTranslation complete.");
  return 0;
}