//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: imaginative
#include <stdio.h>
#include <string.h>

// Define the alphabet of the C Alien Language
char c_alphabet[] = "abcdefghijklmnopqrstuvwxy!@#$%^&*()-_=+[]{}|;:',.<>?/z ";

// Function to translate a given string into the C Alien Language
void translate_to_c_alien(char *text) {
  int i, j, index;
  char c;

  printf("Translation: ");

  // Loop through each character of the given string
  for (i = 0; i < strlen(text); i++) {
    c = tolower(text[i]); // Convert to lowercase to match the C Alien alphabet
    index = -1;

    // Find the index of the character in the C Alien alphabet
    for (j = 0; j < strlen(c_alphabet); j++) {
      if (c == c_alphabet[j]) {
        index = j;
        break;
      }
    }

    // If the character is not found in the alphabet, print an error message
    if (index == -1) {
      printf("Error: '%c' is not a valid character in the C Alien Language.\n", text[i]);
      return;
    }

    // Otherwise, print the translated character
    printf("%d ", index);
  }

  printf("\n"); // Print a newline character at the end of the translation
}

// Example usage of the C Alien Language Translator
int main() {
  char text[100];

  printf("Enter a string to translate into the C Alien Language:\n");
  fgets(text, 100, stdin); // Read input from the user

  // Remove the newline character from the input string
  text[strcspn(text, "\n")] = 0;

  translate_to_c_alien(text); // Translate the string to the C Alien Language

  return 0;
}