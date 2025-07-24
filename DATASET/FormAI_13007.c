//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: complete
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char word[50];
  printf("Enter a word: ");
  scanf("%s", word);
  
  int len = strlen(word);
  int i, j;

  // Convert to lowercase
  for(i = 0; i < len; i++) {
    word[i] = tolower(word[i]);
  }

  // Remove non-letter characters
  for(i = 0, j = 0; i < len; i++) {
    if(isalpha(word[i])) {
      word[j++] = word[i];
    }
  }
  word[j] = '\0';

  // Check if word is a palindrome
  int isPalindrome = 1;
  for(i = 0, j = strlen(word) - 1; i < j; i++, j--) {
    if(word[i] != word[j]) {
      isPalindrome = 0;
    }
  }

  if(isPalindrome) {
    printf("%s is a palindrome!", word);
  } else {
    printf("%s is not a palindrome.", word);
  }
  
  return 0;
}