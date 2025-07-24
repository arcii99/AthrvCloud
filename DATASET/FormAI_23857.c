//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN 500

void sanitizeInput(char* input);
/* Function to sanitize the user input */

int main()
{
  char input[MAX_LEN];
  printf("Enter some text to sanitize:\n");
  fgets(input, MAX_LEN, stdin);
  /* Reading input from user */

  sanitizeInput(input);

  printf("The sanitized input is:\n%s", input);

  return 0;
}

void sanitizeInput(char* input)
{
  int i = 0, j = 0;

  while (input[i] != '\0')
  {
    if (isalnum(input[i]) || isspace(input[i]))
    {
      input[j] = input[i]; // Keep only alphanumeric and whitespace characters
      j++;
    }
    i++;
  }

  input[j] = '\0'; // Terminate the sanitized string
}