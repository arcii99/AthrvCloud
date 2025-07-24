//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: random
#include <stdio.h>
#include <string.h>

int main(void)
{
  char input[100];
  printf("Enter your input: ");
  fgets(input, 100, stdin); // Get input from the user
  
  // Loop through each character in the input and check if it needs to be sanitized
  for (int i = 0; i < strlen(input); i++)
  {
    switch (input[i])
    {
      case '<':
        printf("&lt;"); // Replace with HTML entity for '<'
        break;
      case '>':
        printf("&gt;"); // Replace with HTML entity for '>'
        break;
      case '&':
        printf("&amp;"); // Replace with HTML entity for '&'
        break;
      default:
        printf("%c", input[i]); // Print the character as-is
    }
  }
  
  return 0;
}