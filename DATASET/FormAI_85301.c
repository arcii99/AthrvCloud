//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: invasive
#include <stdio.h>
#include <string.h>

int main() {
  char word[50];

  printf("Enter a word: ");
  scanf("%s", word);

  int isPalindrome = 1; // assumes word is a palindrome

  for (int i = 0, j = strlen(word) - 1; i < j; i++, j--) {
    if (word[i] != word[j]) {
      isPalindrome = 0;
      break;
    }
  }

  if (isPalindrome) {
    printf("%s is a palindrome!\n", word);
  } else {
    printf("%s is not a palindrome.\n", word);
  }

  return 0;
}