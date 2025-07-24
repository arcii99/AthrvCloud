//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: lively
#include <stdio.h>
#include <string.h>

// Function to convert input message into C Alien language
void convertToCAlien(char input[]) {
  int i;

  // Loop through each character in input message
  for (i = 0; i < strlen(input); i++) {

    // Check if character is a letter
    if (input[i] >= 'a' && input[i] <= 'z') {
      // Add a '#' before the letter
      printf("#%c", input[i] - 32);
    }
    else if (input[i] == ' ') {
      // Print a '.' for spaces
      printf(".");
    }
    else if (input[i] == '!') {
      // Add a '!' at the end of the message
      printf("!");
    }
    else {
      // Print the character as is
      printf("%c", input[i]);
    }
  }
}

int main() {
  char input[100];

  // Prompt user to enter message to convert
  printf("Enter message to translate: ");
  scanf("%[^\n]", input);

  // Call function to convert to C Alien language
  convertToCAlien(input);

  return 0;
}