//FormAI DATASET v1.0 Category: Spell checking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  // Read the text from the user
  char input[1000];
  printf("Enter text: ");
  fgets(input, 1000, stdin);

  // Remove any newline characters from the input
  char *pos;
  if ((pos = strchr(input, '\n')) != NULL)
    *pos = '\0';

  // Convert all characters to lowercase
  for (int i = 0; i < strlen(input); i++)
  {
    input[i] = tolower(input[i]);
  }

  // Declare an array of known words
  char dictionary[10][20] = {"example", "spell", "checking", "program", "innovative", "style", "code", "snippet", "compile", "error"};

  // Split the input string into words
  char *token;
  token = strtok(input, " .,!?");
  while (token != NULL)
  {
    // Check if the word is in the dictionary
    int in_dict = 0;
    for (int i = 0; i < 10; i++)
    {
      if (strcmp(token, dictionary[i]) == 0)
      {
        in_dict = 1;
        break;
      }
    }

    // Print out the result
    if (in_dict == 1)
      printf("%s ", token);
    else
      printf("[%s] ", token);

    // Move to the next word
    token = strtok(NULL, " .,!?");
  }

  return 0;
}