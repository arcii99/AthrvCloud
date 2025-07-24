//FormAI DATASET v1.0 Category: String manipulation ; Style: accurate
#include <stdio.h>
#include <string.h>

int main() {
  char inputString[100];
  char reversedString[100];
  int length, i, j, flag = 1;

  printf("Enter a word or a sentence: ");
  scanf("%[^\n]", inputString);

  length = strlen(inputString);

  for (i = 0, j = length - 1; i < length; i++, j--) {
    reversedString[i] = inputString[j];
  }
  reversedString[i] = '\0';

  printf("\nReversed string: %s\n", reversedString);

  // Check if input string is a palindrome
  for (i = 0; i < length; i++) {
    if (inputString[i] != reversedString[i]) {
      flag = 0;
      break;
    }
  }

  if (flag) {
    printf("\nInput string is a palindrome.\n");
  } else {
    printf("\nInput string is not a palindrome.\n");
  }

  // Print every other character
  printf("\nEvery other character in the input string: ");
  for (i = 0; i < length; i += 2) {
    printf("%c", inputString[i]);
  }

  // Convert input string to uppercase
  printf("\n\nInput string in uppercase: ");
  for (i = 0; i < length; i++) {
    printf("%c", toupper(inputString[i]));
  }

  return 0;
}