//FormAI DATASET v1.0 Category: Error handling ; Style: artistic
// A unique C Error handling example program in an artistic style

#include <stdlib.h> // Required for exit() function
#include <stdio.h> // Required for fprintf() and perror() functions

int main()
{
  int a = 10;
  int b = 0;

  if (b == 0) // Checking for division by zero
  {
    fprintf(stderr, "Error: Cannot divide by zero\n");
    exit(1); // Exiting program with error code 1
  }

  int c = a / b; // Performing division

  if (c == 0) // Checking if the result is zero
  {
    perror("Error"); // Displaying error message
    exit(EXIT_FAILURE); // Exiting program with failure status
  }

  printf("Result: %d\n", c); // Displaying result

  return 0; // Exiting program successfully
}