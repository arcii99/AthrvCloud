//FormAI DATASET v1.0 Category: Text processing ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare and initialize variables
  char input[100];
  int vowels = 0;
  int consonants = 0;

  // Get user input
  printf("Enter a string: ");
  fgets(input, 100, stdin);

  // Loop through each character in the input string
  for (int i = 0; i < strlen(input); i++) {
    // Check if the character is a letter
    if (isalpha(input[i])) {
      // Check if the letter is a vowel
      if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' || input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U') {
        vowels++;
      } else {
        consonants++;
      }
    }
  }

  // Print the results
  printf("Number of vowels in the string: %d\n", vowels);
  printf("Number of consonants in the string: %d\n", consonants);

  return 0;
}