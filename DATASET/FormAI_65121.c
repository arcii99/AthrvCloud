//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrome(char* str);

int main() {

  char input[100];
  printf("Enter a string: ");
  fgets(input, sizeof(input), stdin);
  
  // Removing newline character from the user input
  input[strcspn(input, "\n")] = 0;

  if(is_palindrome(input))
    printf("The string is a palindrome!\n");
  else
    printf("Not a palindrome!\n");

  return 0;
}

int is_palindrome(char* str) {
  
  int length = strlen(str);
  for(int i = 0, j = length-1; i < length/2; i++, j--) {
    if(*(str+i) != *(str+j))
      return 0;
  }
  return 1;
}