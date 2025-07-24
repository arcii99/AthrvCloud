//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: surrealist
#include <stdio.h>
#include <string.h>

int main() {
  char input[100], original[100], reverse[100];
  printf("Enter a string: ");
  scanf("%s", input);

  printf("\n\nRunning a test to determine if %s is a palindrome...\n\n", input);

  // copy the input into original for comparison
  strcpy(original, input);

  // reverse the input and store it in reverse
  int i, j;
  for (i = 0, j = strlen(input) - 1; i < strlen(input); i++, j--) {
    reverse[i] = input[j];
  }
  reverse[i] = '\0';

  printf("Original string: %s\n", original);
  printf("Reversed string: %s\n", reverse);

  // check if the original and reversed strings are equal
  if (strcmp(original, reverse) == 0) {
    printf("\n%s is a palindrome! 🎉 🎉 🎉\n", input);
  } else {
    printf("\n%s is NOT a palindrome! 😢 😢 😢\n", input);
  }

  return 0;
}