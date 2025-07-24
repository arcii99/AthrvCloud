//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char name[20];

  printf("Please enter your name: ");
  fgets(name, 20, stdin);

  // Remove newline character from user input
  int len = strlen(name);
  if (name[len-1] == '\n') {
    name[len-1] = '\0';
  }

  // Check if user input contains unwanted characters
  char* unwanted_chars = "!@#$%^&*()_+{}|:\"<>?,./;'[]\\=-";
  int i, j;
  for (i=0; i<strlen(name); i++) {
    for (j=0; j<strlen(unwanted_chars); j++) {
      if (name[i] == unwanted_chars[j]) {
        printf("Invalid character detected in name. Please try again.\n");
        exit(EXIT_FAILURE);
      }
    }
  }

  printf("Welcome, %s!\n", name);

  return 0;
}