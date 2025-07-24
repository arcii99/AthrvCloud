//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: mind-bending
#include <stdio.h>
#include <string.h>

int main() {

  char word[50];
  int i, j, flag = 0;

  printf("Enter a word: ");
  scanf("%s", word);

  printf("The size of the word entered is: %d\n", strlen(word));
  
  // Check if word is a palindrome
  for(i = 0, j = strlen(word) - 1; i < strlen(word) / 2; i++, j--) {

    if(word[i] != word[j]) {
      flag = 1;
      break;
    }
  }

  if(flag == 0)
    printf("The word entered is a palindrome!\n");
  else
    printf("The word entered is not a palindrome.\n");

  return 0;
}