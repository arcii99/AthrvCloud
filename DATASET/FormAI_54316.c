//FormAI DATASET v1.0 Category: Syntax parsing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char input[100]; // Initializing input array of size 100
  printf("Enter a C syntax statement: "); 
  scanf("%[^\n]s", input); // Reading input statement
  
  char *token;
  token = strtok(input, " "); // Separating each token by space
  
  while (token != NULL) { // Iterating through each token until there are none left
    if (strcmp(token, "for") == 0) { 
      printf("FOR loop syntax detected.\n"); // Checking for FOR loop syntax
    } else if (strcmp(token, "while") == 0) {
      printf("WHILE loop syntax detected.\n"); // Checking for WHILE loop syntax
    } else if (strcmp(token, "if") == 0 || strcmp(token, "else") == 0) {
      printf("Conditional statement syntax detected.\n"); // Checking for conditional statement syntax
    } else if (strcmp(token, "{") == 0 || strcmp(token, "}") == 0) {
      printf("Bracket syntax detected.\n"); // Checking for bracket syntax
    } else {
      printf("%s is not a recognized syntax.\n", token); // If token does not match recognized syntax
    }
    token = strtok(NULL, " "); // Get next token
  }
  
  return 0; // End program
}