//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
  char input[100];
  int i;
  int j;
  int flag = 0;

  printf("Enter some text: ");
  fgets(input, 100, stdin);

  for (i = 0; i < strlen(input); i++)
  {
    if (input[i] == '<')
    {
      for (j = i+1; j < strlen(input); j++)
      {
        if (input[j] == '>')
        {
          i = j;
          flag = 1;
          break;
        }
      }

      if (flag == 0)
      {
        printf("Error: Invalid input\n");
        exit(0);
      }
      else
      {
        continue;
      }
    }
    else if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= '0' && input[i] <= '9') || input[i] == ' ')
    {
      continue;
    }
    else
    {
      printf("Error: Invalid input\n");
      exit(0);
    }
  }

  printf("Sanitized Input: %s\n", input);

  return 0;
}