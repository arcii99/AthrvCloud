//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {
  char word[1000], reversed[1000];

  printf("Enter a word to check if it is a palindrome: ");
  scanf("%s", word);

  int i, j;
  j = 0;
  // reversing the input string
  for (i = strlen(word) - 1; i >= 0; i--) {
    reversed[j] = word[i];
    j++;
  }
  reversed[j] = '\0'; // adding null terminating character

  // Checking if the input string is the same as the reversed string
  if (strcmp(word, reversed) == 0) {
    printf("Woah! '%s' is a palindrome!🤯\n", word);
  } else {
    printf("Oops! '%s' is not a palindrome.😔\n", word);
  }

  return 0;
}