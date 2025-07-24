//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int isPalindrome(char *string);

int main() {
  char string[50];
  printf("Enter your string: ");
  fgets(string, 50, stdin);

  if(isPalindrome(string)) {
    printf("This is a palindrome.");
  } else {
    printf("This is not a palindrome.");
  }

  return 0;
}

int isPalindrome(char *string) {
  int length = strlen(string);
  char reversed[length];
  int i;

  for (i = 0; i < length; i++) {
    reversed[i] = string[length - i - 2];
  }

  reversed[i-1] = '\0';

  if(strcmp(string,reversed) == 0) {
    return 1;
  } else {
    return 0;
  }
}