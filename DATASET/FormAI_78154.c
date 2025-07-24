//FormAI DATASET v1.0 Category: Text processing ; Style: satisfied
#include <stdio.h>
#include <string.h>

int main() {

  char input[1000];
  printf("Enter a string: ");
  fgets(input, 1000, stdin);

  int count = 0;
  int vowels = 0;

  for(int i = 0; i < strlen(input); i++) {
    if(input[i] == ' ' || input[i] == '\n') {
      count++;
    }
    if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') {
      vowels++;
    }
  }

  printf("The string has %d words and %d vowels.\n", count+1, vowels);

  char reverse[strlen(input)];
  for(int i = strlen(input)-1; i >= 0; i--) {
    reverse[strlen(input)-i-1] = input[i];
  }
  printf("The string in reverse is %s\n", reverse);

  char noVowels[strlen(input)];
  int j = 0;
  for(int i = 0; i < strlen(input); i++) {
    if(input[i] != 'a' && input[i] != 'e' && input[i] != 'i' && input[i] != 'o' && input[i] != 'u') {
      noVowels[j] = input[i];
      j++;
    }
  }
  noVowels[j] = '\0';
  printf("The string without vowels is %s\n", noVowels);

  return 0;
}