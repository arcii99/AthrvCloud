//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: minimalist
#include <stdio.h>
#include <string.h>

int main() {
  char str[100];
  int i, j, len, flag = 1;

  printf("Enter a string: ");
  scanf("%s", str);

  len = strlen(str);

  for(i = 0, j = len - 1; i < len/2; i++, j--) {
    if(str[i] != str[j]) {
      flag = 0;
      break;
    }
  }
  
  if(flag) {
    printf("%s is a palindrome", str);
  } else {
    printf("%s is not a palindrome", str);
  }

  return 0;
}