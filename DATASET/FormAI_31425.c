//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: funny
#include <stdio.h>
#include <string.h>

int main() 
{
  char userInput[50];

  printf("Please enter your name: ");
  fgets(userInput, 50, stdin);

  // Let's sanitize the user input to remove any unwanted characters

  for (int i = 0; i < strlen(userInput); i++) 
  {
    if (userInput[i] == '!' || userInput[i] == '@' || 
        userInput[i] == '#' || userInput[i] == '$' || 
        userInput[i] == '%' || userInput[i] == '^' || 
        userInput[i] == '&' || userInput[i] == '*' || 
        userInput[i] == '(' || userInput[i] == ')' || 
        userInput[i] == '-' || userInput[i] == '_' || 
        userInput[i] == '+' || userInput[i] == '=' || 
        userInput[i] == '[' || userInput[i] == ']' || 
        userInput[i] == '{' || userInput[i] == '}' || 
        userInput[i] == ';' || userInput[i] == ':' || 
        userInput[i] == '"' || userInput[i] == '\'' || 
        userInput[i] == ',' || userInput[i] == '.' || 
        userInput[i] == '/' || userInput[i] == '?' || 
        userInput[i] == '<' || userInput[i] == '>' || 
        userInput[i] == '`' || userInput[i] == '~') 
    {
      // replace invalid characters with spaces
      userInput[i] = ' ';
    }
  }

  printf("Hello, %s! Welcome to our program. Your input has been sanitized.\n", userInput);

  return 0;
}