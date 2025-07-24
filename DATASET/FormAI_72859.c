//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {
  char str[100];
  printf("Enter a string: ");
  scanf("%s", str);
  int len = strlen(str);
  int flag = 1;
  for (int i = 0; i < len/2; i++) {
    if (str[i] != str[len-i-1]) {
      flag = 0;
      break;
    }
  }
  if (flag) {
    printf("OMG! The string is a PALINDROME!!!\n");
  } else {
    printf("WAIT! The string is NOT a palindrome.\n");
  }
  return 0;
}