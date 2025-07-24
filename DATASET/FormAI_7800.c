//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Alan Touring
// Alan Turing style program to sanitize user input in C
// Written by Chatbot

#include<stdio.h>
#include<string.h>
#include<ctype.h>

// Function to sanitize user input string
void sanitizeInput(char *input)
{
  int i, j = 0;
  char temp[100];

  // Loop through input string
  for(i=0; input[i]!='\0'; i++)
  {
    // Remove non-alphanumeric characters
    if(isalnum(input[i]))
    {
      // Convert uppercase to lowercase
      if(input[i]>='A' && input[i]<='Z')
        temp[j++] = input[i] + 32;
      else
        temp[j++] = input[i];
    }
  }
  temp[j] = '\0';

  // Copy sanitized input back to original input string
  strncpy(input, temp, strlen(temp)+1);
}

// Main function
int main()
{
  char input[100];

  // User input
  printf("Enter a string: ");
  fgets(input, 100, stdin);

  // Sanitize user input
  sanitizeInput(input);

  // Display sanitized input
  printf("Sanitized input: %s\n", input);

  return 0;
}