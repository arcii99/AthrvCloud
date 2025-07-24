//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {

  char str[100];
  int i,j,len;

  printf("Enter a word to check if it is a palindrome: ");
  scanf("%s", str);

  len = strlen(str);

  for(i=0,j=len-1; i<=len/2; i++,j--) {
    if(tolower(str[i]) != tolower(str[j])) {
      printf("The given word is not a palindrome.\n");
      return 0;
    }
  }

  printf("The given word is a palindrome.\n");

  return 0;
}