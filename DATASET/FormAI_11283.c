//FormAI DATASET v1.0 Category: Text processing ; Style: grateful
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];

  printf("Enter a sentence: ");
  fgets(input, 100, stdin); // get input from user

  char grateful[100] = "I am grateful for ";

  // string manipulation
  char *token = strtok(input, " ");
  while (token != NULL) {
    strcat(grateful, token); // concatenate token to grateful string
    strcat(grateful, ", "); // add ", " separator
    token = strtok(NULL, " "); // get next token
  }

  printf("%s\n", grateful);

  return 0;
}