//FormAI DATASET v1.0 Category: String manipulation ; Style: surprised
#include <stdio.h>

int main() {
  char myString[100] = "Hello, World!";
  char myName[10] = "Bob";
  char newString[100];

  printf("Original string: %s\n", myString);

  for(int i = 0; i < strlen(myName); i++) {
    myString[i+7] = myName[i];
  }

  printf("Modified string: %s\n", myString);

  int len = strlen(myString);

  for(int i = 0; i < len; i++) {
    newString[i] = myString[len-i-1];
  }

  printf("Reversed string: %s\n", newString);

  int count = 0;

  for(int i = 0; i < len; i++) {
    if(myString[i] == 'o') {
      count++;
    }
  }

  printf("Number of 'o' characters: %d\n", count);

  if(strcmp(myString, newString) == 0) {
    printf("The string is a palindrome!");
  } else {
    printf("The string is not a palindrome.");
  }

  return 0;
}