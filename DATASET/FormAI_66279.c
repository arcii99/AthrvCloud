//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: calm
#include<stdio.h>
#include<string.h>

int main() {
  char str[100];
  int i, j, len, check = 0;

  printf("Palindrome Checker\nEnter a string to check if it is a palindrome: ");
  fgets(str, sizeof(str), stdin);
  len = strlen(str);

  i = 0;
  j = len - 1;

  while(j > i) {
    if(str[i++] != str[j--]) {
      check = 1;
      break;
    }
  }

  if(check == 0) {
    printf("%s is a Palindrome\n", str);
  } else {
    printf("%s is NOT a Palindrome\n", str);
  }

  return 0;
}