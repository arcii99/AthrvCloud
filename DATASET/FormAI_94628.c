//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: grateful
#include <stdio.h>
#include <string.h>

int main() {
  char word[100];
  int i, j, length, flag = 0;

  printf("Welcome to Palindrome Checker!\n");
  printf("Please enter a word: ");
  fgets(word, 100, stdin);   // takes input from user

  length = strlen(word) - 1;    // remove newline character

  for (i = 0; i < length; i++) {
    if (word[i] != word[length - 1 - i]) {   // check for palindrome
      flag = 1;
      break;
    }
  }

  if (flag) {
    printf("%s is not a palindrome.\n", word);
  }

  else {
    printf("%s is a palindrome.\n", word);
  }

  return 0;
}