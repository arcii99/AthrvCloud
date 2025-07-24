//FormAI DATASET v1.0 Category: Text processing ; Style: active
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int main() {

  char input[MAX_STRING_LENGTH];
  char processed_string[MAX_STRING_LENGTH];

  printf("Please enter a string: ");
  fgets(input, MAX_STRING_LENGTH, stdin);

  int length = strlen(input);

  // remove white spaces
  int j = 0;
  for (int i = 0; i < length; i++) {
    if (input[i] != ' ' && input[i] != '\n') {
      processed_string[j] = input[i];
      j++;
    }
  }

  length = strlen(processed_string);

  // convert all characters to lower case
  for (int i = 0; i < length; i++) {
    if (processed_string[i] >= 'A' && processed_string[i] <= 'Z') {
      processed_string[i] += 32;
    }
  }

  // check if the string is a palindrome
  int is_palindrome = 1;
  for (int i = 0; i < length/2; i++) {
    if (processed_string[i] != processed_string[length-i-1]) {
      is_palindrome = 0;
      break;
    }
  }

  if (is_palindrome) {
    printf("The string entered is a palindrome.");
  } else {
    printf("The string entered is not a palindrome.");
  }

  return 0;
}