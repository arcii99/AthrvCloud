//FormAI DATASET v1.0 Category: Error handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
  int num;
  char input[10];
  
  printf("Enter a positive number: ");
  fgets(input, 10, stdin);
  
  // Check for input errors
  if (sscanf(input, "%d", &num) != 1 || num < 0) {
    fprintf(stderr, "Error: Invalid input\n");
    exit(EXIT_FAILURE);
  }
  
  // Check for integer overflow
  if (errno == ERANGE) {
    fprintf(stderr, "Error: Integer overflow occurred\n");
    exit(EXIT_FAILURE);
  }
  
  // Do some calculation
  int result = num * 2;
  
  // Check for arithmetic errors
  if (result < num) {
    fprintf(stderr, "Error: Arithmetic overflow occurred\n");
    exit(EXIT_FAILURE);
  }
  
  printf("The result is: %d\n", result);
  
  return 0;
}