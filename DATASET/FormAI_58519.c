//FormAI DATASET v1.0 Category: Text processing ; Style: calm
#include<stdio.h>
#include<string.h>

int main() {

  char input[1000];
  printf("Enter a message: ");
  fgets(input, 1000, stdin);

  // Remove trailing newline character
  if (input[strlen(input) - 1] == '\n') {
    input[strlen(input) - 1] = '\0';
  }

  int count_spaces = 0, count_characters = 0, count_digits = 0, count_vowels = 0;

  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == ' ') {
      count_spaces++;
      continue;
    }
    if (isalpha(input[i])) {
      count_characters++;
      if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' || input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U') {
        count_vowels++;
      }
    }
    if (isdigit(input[i])) {
      count_digits++;
    }
  }

  printf("\nStatistics for the input message:\n");
  printf("Number of spaces: %d\n", count_spaces);
  printf("Number of characters: %d\n", count_characters);
  printf("Number of digits: %d\n", count_digits);
  printf("Number of vowels: %d\n", count_vowels);

  return 0;
}