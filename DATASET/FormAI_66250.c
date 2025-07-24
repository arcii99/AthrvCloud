//FormAI DATASET v1.0 Category: Text processing ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char string[100];  // variable to store text input
  int count = 0;     // variable to count number of occurences
  char search;       // variable to store character to be searched

  // Get text input from user
  printf("Enter a string: ");
  fgets(string, sizeof(string), stdin);

  // Get character to be searched from user
  printf("Enter a character to be searched: ");
  scanf("%c", &search);

  // Loop through string to find occurences of the character
  for(int i=0; i<strlen(string); i++) {
    if(string[i] == search) {
       count++;
    }
  }

  // Print output
  if(count == 0) {
     printf("The character '%c' was not found.\n", search);
  } 
  else {
     printf("The character '%c' was found %d times.\n", search, count);
  }

  return 0;
}