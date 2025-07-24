//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
  char string[MAX_LENGTH];
  int i, j, flag = 0;
  
  printf("Enter a string: ");
  fgets(string, MAX_LENGTH, stdin);
  
  // Remove newline character from string
  for (i = 0; i < strlen(string); i++) {
    if (string[i] == '\n') {
      string[i] = '\0';
      break;
    }
  }
  
  // Convert string to lowercase
  for (i = 0; i < strlen(string); i++) {
    string[i] = tolower(string[i]);
  }
  
  j = strlen(string) - 1;
  
  for (i = 0; i < strlen(string); i++) {
    if (string[i] != string[j]) {
      flag = 1;
      break;
    }
    j--;
  }
  
  if (flag) {
    printf("\"%s\" is not a palindrome.\n", string);
  } else {
    printf("\"%s\" is a palindrome.\n", string);
  }
  
  return 0;
}