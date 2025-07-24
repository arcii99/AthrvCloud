//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: minimalist
#include <stdio.h>
#include <string.h>

void main() {
  char input[100];
  printf("Enter a string to check if it's a palindrome: ");
  scanf("%s", input);

  int length = strlen(input);
  int is_palindrome = 1;

  for (int i = 0; i < length / 2; i++) {
    if (input[i] != input[length - i - 1]) {
      is_palindrome = 0;
      break;
    }
  }

  if (is_palindrome) {
    printf("%s is a palindrome!\n", input);
  } else {
    printf("%s is not a palindrome.\n", input);
  }
}