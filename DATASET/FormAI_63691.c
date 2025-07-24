//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: creative
#include <stdio.h>
#include <string.h>

int main() {
  // Define variables and arrays for translation
  char c_cat[6][10] = {"meow", "purr", "hiss", "scratch", "whiskers", "catnip"};
  char english[6][12] = {"Hello", "Goodbye", "Angry", "Attack", "Cute", "Fun"};

  // Display intro message and prompt user for input
  printf("Welcome to the C Cat Language Translator!\n");
  printf("Enter a sentence in C Cat language:\n");

  // Read user input and remove trailing newline character
  char input[100];
  fgets(input, 100, stdin);
  input[strcspn(input, "\n")] = 0;

  // Tokenize user input by space delimiter and translate each word
  printf("Translation: ");
  char *token = strtok(input, " ");
  while (token != NULL) {
    int i;
    int found = 0;
    
    // Search for C Cat word in array
    for (i = 0; i < 6; i++) {
      if (strcmp(token, c_cat[i]) == 0) {
        printf("%s ", english[i]);
        found = 1;
        break;
      }
    }

    // If word not found, print original word with '(?)'
    if (!found) {
      printf("%s(?) ", token);
    }

    token = strtok(NULL, " ");
  }

  printf("\n");

  return 0;
}