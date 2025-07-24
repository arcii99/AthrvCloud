//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: puzzling
#include <stdio.h>
#include <string.h>

int main()
{
  char input[50];
  int i, j;

  printf("Enter a string: ");
  scanf("%s", input);

  // Run the input through the sanitizer
  for(i = 0, j = 0; input[i] != '\0'; i++)
  {
    // Check if the current character is alphanumeric
    if(isalnum(input[i]))
    {
      // If it is, add it to the sanitized input
      input[j++] = input[i];
    }
  }

  // Terminate the sanitized input string
  input[j] = '\0';

  printf("Sanitized string: %s\n", input);

  return 0;
}