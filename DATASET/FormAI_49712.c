//FormAI DATASET v1.0 Category: Text processing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 100 // Maximum number of characters

int main () {
  char input[MAX_CHARS]; // Create an array 'input' to store user input
  char output[MAX_CHARS]; // Create an array 'output' to store processed text

  printf("Enter some text to process: ");
  fgets(input, MAX_CHARS, stdin); // Get input from user and store it in 'input'

  // Convert all vowels to uppercase
  int i;
  for (i = 0; i < strlen(input); i++) {
    char ch = input[i];
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
      output[i] = toupper(ch);
    }
    else {
      output[i] = ch;
    }
  }

  // Display the processed text
  printf("Processed text: %s\n", output);

  return 0;
}