//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: random
#include <stdio.h>
#include <ctype.h>

int main() {
  char str[50];
  int i, j, flag = 1;
  
  printf("Enter a string: ");
  fgets(str, sizeof(str), stdin);

  for (i = 0, j = strlen(str) - 2; i < j; i++, j--) {
    while (!isalnum(str[i]) && i < j) i++;
    while (!isalnum(str[j]) && i < j) j--;
    if (tolower(str[i]) != tolower(str[j])) {
      flag = 0;
      break;
    }
  }

  if (flag) printf("The string is a palindrome.\n");
  else printf("The string is not a palindrome.\n");

  return 0;
}