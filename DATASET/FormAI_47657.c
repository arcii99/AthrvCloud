//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main() {
  char word[50];
  int i, j, len, flag=0;
  
  printf("Welcome to the Palindrome Checker!\n\n");
  printf("Please enter a word: ");
  scanf("%s", word);
  
  len = strlen(word);
  
  for (i = 0, j = len - 1; i < len / 2; i++, j--) {
    if (word[i] != word[j]) {
      flag = 1;
      break;
    }
  }
  
  if (flag == 0) {
    printf("\n\nWoohoo! The word \"%s\" is a Palindrome!", word);
  }
  else {
    printf("\n\nOh no! The word \"%s\" is not a Palindrome.", word);
  }
  
  return 0;
}