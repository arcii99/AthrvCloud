//FormAI DATASET v1.0 Category: Text processing ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[1000];
  int vowels = 0, consonants = 0, digits = 0, spaces = 0, i;

  printf("Welcome to the Vowel-Consonant-Digit-Spaces Counter! \n");
  printf("Please Enter the Text: ");
  
  // get the user's input
  fgets(input, sizeof(input), stdin);

  // loop through the input
  for (i = 0; input[i] != '\0'; ++i) {
    if (input[i] == ' ') {
      // if the current character is a space
      ++spaces;
    } else if (input[i] >= '0' && input[i] <= '9') {
      // if the current character is a digit
      ++digits;
    } else if (input[i] >= 'A' && input[i] <= 'Z') {
      // if the current character is an uppercase letter
      ++consonants;
      ++input[i]; // change the letter to its lowercase version
    } else if (input[i] >= 'a' && input[i] <= 'z') {
      // if the current character is a lowercase letter
      ++input[i]; // change the letter to its uppercase version
      if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || 
          input[i] == 'o' || input[i] == 'u') { 
        // if the current character is a vowel
        ++vowels; 
      } else { 
        // if the current character is a consonant
        ++consonants; 
      }
    }
  }

  // print the results
  printf("\nTotal Number of Vowels in Text: %d", vowels);
  printf("\nTotal Number of Consonants in Text: %d", consonants);
  printf("\nTotal Number of Digits in Text: %d", digits);
  printf("\nTotal Number of Spaces in Text: %d", spaces);

  return 0;
}