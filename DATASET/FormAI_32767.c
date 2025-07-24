//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: enthusiastic
#include <stdio.h>

int main(void) {
  printf("\n");
  printf("Welcome to the C Cat Language Translator!\n");
  printf("Meow meow meow meow!\n\n");

  // Initializing the input and output strings

  char input_string[1000], output_string[1000];

  printf("Please enter a sentence in C Cat Language: \n");
  fgets(input_string, 1000, stdin);

  // Converting C Cat Language to English

  int i, j;

  for (i = 0, j = 0; input_string[i] != '\0'; i++) {
    switch (input_string[i]) {
      case 'M': // Meow
        output_string[j++] = 'M';
        output_string[j++] = 'e';
        output_string[j++] = 'o';
        output_string[j++] = 'w';
        break;

      case 'P': // Purr
        output_string[j++] = 'P';
        output_string[j++] = 'u';
        output_string[j++] = 'r';
        output_string[j++] = 'r';
        break;

      case 'H': // Hiss
        output_string[j++] = 'H';
        output_string[j++] = 'i';
        output_string[j++] = 's';
        output_string[j++] = 's';
        break;

      case 'C': // Clean
        output_string[j++] = 'C';
        output_string[j++] = 'l';
        output_string[j++] = 'e';
        output_string[j++] = 'a';
        output_string[j++] = 'n';
        break;

      case 'E': // Eat
        output_string[j++] = 'E';
        output_string[j++] = 'a';
        output_string[j++] = 't';
        break;

      case 'W': // Walk
        output_string[j++] = 'W';
        output_string[j++] = 'a';
        output_string[j++] = 'l';
        output_string[j++] = 'k';
        break;

      case 'S': // Sleep
        output_string[j++] = 'S';
        output_string[j++] = 'l';
        output_string[j++] = 'e';
        output_string[j++] = 'e';
        output_string[j++] = 'p';
        break;

      default: // Any other character
        output_string[j++] = input_string[i];
        break;
    }
  }

  output_string[j] = '\0'; // Adding null character to output string

  // Displaying the translated string

  printf("\nThe translated sentence in English is: \n");
  printf("%s\n", output_string);

  printf("\nThank you for using the C Cat Language Translator! Meow meow meow meow!\n");
  
  return 0;
}