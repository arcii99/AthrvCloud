//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: funny
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 100

// This palindrome checker is the best in the world!
// It can even detect if your name is a palindrome!

bool isPalindrome(char str[]) {
  int len = strlen(str);
  for (int i=0; i<len/2; i++) {
    if (str[i] != str[len-i-1]) {
      return false;
    }
  }
  return true;
}

int main() {
  char input[MAX_LENGTH];
  printf("Welcome to the Palindrome Checker 3000!\n");
  printf("Enter a word or phrase and I'll tell you if it's a palindrome:\n");
  scanf("%[^\n]", input);
  printf("Processing...");
  for (int i=0; i<3; i++) {
    printf(".");
    sleep(1);
  }
  printf("\n");
  if (isPalindrome(input)) {
    printf("Congratulations, '%s' is a palindrome!\n", input);
  } else {
    printf("Sorry buddy, '%s' is not a palindrome.\n", input);
  }
  printf("But wait, let me check something...\n");
  for (int i=0; i<3; i++) {
    printf(".");
    sleep(1);
  }
  printf("\n");
  if (isPalindrome("neveroddoreven")) {
    printf("OMG, your name is a palindrome too? That's so cool!\n");
  } else {
    printf("Well, looks like your name is not a palindrome. Don't worry, not everyone can be as cool as 'neveroddoreven'.\n");
  }
  return 0;
}