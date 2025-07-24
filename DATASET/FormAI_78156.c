//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: calm
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  int i, length;
  int flag = 0;

  printf("Enter a string:\n");
  scanf("%s", input); // Take user input

  length = strlen(input); // Determine length of string

  for (i = 0; i < length; i++) {
    if (input[i] != input[length - 1 - i]) { // Compare characters of input string
      flag = 1;
      break;
    }
  }

  if (flag) {
    printf("%s is not a palindrome.\n", input);
  } else {
    printf("%s is a palindrome.\n", input);
  }

  return 0;
}