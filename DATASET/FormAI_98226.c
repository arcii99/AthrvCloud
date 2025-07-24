//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

  char input[100];
  printf("Welcome to the User Input Sanitizer Program!\n");
  printf("Please enter a string: ");
  fgets(input, 100, stdin); //gets the user input

  // Removing leading and trailing white spaces
  int i = 0;
  int j = strlen(input) - 1;
  while (isspace(input[i])) {
    i++;
  }
  while (isspace(input[j])) {
    j--;
  }
  input[j + 1] = '\0';
  strcpy(input, &input[i]);

  // Changing all characters to lowercase
  for (int k = 0; k < strlen(input); k++) {
    input[k] = tolower(input[k]);
  }

  // Replacing all non-alphanumeric characters with underscores
  for (int l = 0; l < strlen(input); l++) {
    if (!isalnum(input[l])) {
      input[l] = '_';
    }
  }

  printf("The sanitized input is: %s", input); //printing the sanitized input

  return 0;
}