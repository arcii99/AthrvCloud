//FormAI DATASET v1.0 Category: Text processing ; Style: automated
#include <stdio.h>
#include <string.h>

int main() {
  char input[1000];
  printf("Enter a string: ");
  fgets(input, 1000, stdin);

  int length = strlen(input);
  int vowels = 0, consonants = 0, digits = 0, spaces = 0;

  for (int i = 0; i < length; i++) {
    char ch = input[i];
    if (isalpha(ch)) {
      ch = tolower(ch);
      if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        vowels++;
      } else {
        consonants++;
      }
    } else if (isdigit(ch)) {
      digits++;
    } else if (isspace(ch)) {
      spaces++;
    }
  }

  printf("\nAnalysis of the input string:\n");
  printf("Total characters: %d\n", length - 1);
  printf("Vowels: %d\n", vowels);
  printf("Consonants: %d\n", consonants);
  printf("Digits: %d\n", digits);
  printf("Spaces: %d\n", spaces);

  return 0;
}