//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: standalone
#include <stdio.h>
#include <string.h>

int isPalindrome(char str[]) {
  int len = strlen(str);
  for (int i = 0; i < len / 2; i++) {
    if (str[i] != str[(len-1)-i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  char str[100];
  printf("Enter a string: ");
  scanf("%s", str);
  if (isPalindrome(str)) {
    printf("%s is a palindrome\n", str);
  } else {
    printf("%s is not a palindrome\n", str);
  }
  return 0;
}