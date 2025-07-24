//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: ultraprecise
#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(char* word) {
  int length = strlen(word);
  int i;
  for (i = 0; i < length/2; i++) {
    if (word[i] != word[length-i-1])
      return false;
  }
  return true;
}

int main() {
  
  char word[100];
  printf("Enter a word: ");
  scanf("%s", word);
  
  if (isPalindrome(word)) {
    printf("%s is a palindrome.\n", word);
  } else {
    printf("%s is not a palindrome.\n", word);
  }
  
  return 0;
}