//FormAI DATASET v1.0 Category: Text processing ; Style: systematic
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
  char sentence[1000];
  int wordCount = 0, charCount = 0, uppercaseCount = 0, lowercaseCount = 0, digitCount = 0, alphabeticalCount = 0;

  printf("Enter a sentence: ");
  fgets(sentence, sizeof(sentence), stdin);

  // count words and characters
  for (int i = 0; sentence[i] != '\0'; i++) {
    charCount++;
    if (isspace(sentence[i]) && !isspace(sentence[i+1])) {
      wordCount++;
    }
  }

  // count uppercase, lowercase, digit, and alphabetical characters
  for (int i = 0; sentence[i] != '\0'; i++) {
    if (isupper(sentence[i])) {
      uppercaseCount++;
      alphabeticalCount++;
    } else if (islower(sentence[i])) {
      lowercaseCount++;
      alphabeticalCount++;
    } else if (isdigit(sentence[i])) {
      digitCount++;
    }
  }

  // display results
  printf("\nWord count: %d\n", wordCount+1);
  printf("Character count: %d\n", charCount-1);
  printf("Uppercase character count: %d\n", uppercaseCount);
  printf("Lowercase character count: %d\n", lowercaseCount);
  printf("Digit count: %d\n", digitCount);
  printf("Alphabetical character count (excluding digits and spaces): %d\n", alphabeticalCount);

  return 0;
}