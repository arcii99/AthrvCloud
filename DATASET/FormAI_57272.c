//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: minimalist
#include <stdio.h>
#include <string.h>

int main() {
  char str[1000];
  int i, j, len;
  printf("Enter a string: ");
  scanf("%s", str);
  len = strlen(str);
  j = len - 1;
  for (i = 0; i < len; i++) {
    if (str[i] != str[j]) {
      printf("%s is not a palindrome\n", str);
      return 0;
    }
    j--;
  }
  printf("%s is a palindrome\n", str);
  return 0;
}