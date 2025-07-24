//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int isPalindrome(char *word) {
  int isPalindrome = 1; 
  // Assume word is a palindrome
  unsigned long length = strlen(word);
  // Get word length
  
  for (int i=0; i<length/2; i++) {
    if (word[i] != word[length-i-1]) {
      isPalindrome = 0; // It's not a palindrome
      break;
    }
  }
 
  return isPalindrome; // Return true or false 
}

int main() {
  char word[50]; // Word storage area
  printf("Enter word to check if it's a palindrome: ");
  scanf("%s", word);
  // Get word input from user
 
  if (isPalindrome(word))
    printf("%s is a palindrome", word);
  else
    printf("%s is not a palindrome", word);
 
  return 0;
}