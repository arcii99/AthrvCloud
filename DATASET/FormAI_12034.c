//FormAI DATASET v1.0 Category: Syntax parsing ; Style: authentic
#include <stdio.h>

int main()
{
  char input[50];
  
  printf("Enter a C syntax statement: ");
  fgets(input, 50, stdin);
  
  // Parsing the statement
  
  int i, flag = 0;
  
  for(i = 0; input[i] != '\0'; i++)
  {
    if(input[i] == '(')
    {
      flag++;
    }
    else if(input[i] == ')')
    {
      flag--;
    }
    else if(input[i] == '{')
    {
      flag++;
    }
    else if(input[i] == '}')
    {
      flag--;
    }
    else if(input[i] == ';')
    {
      break;
    }
  }
  
  // Checking for errors
  
  if(flag == 0)
  {
    printf("The syntax is correct.\n");
  }
  else if(flag > 0)
  {
    printf("Error: missing symbol.\n");
  }
  else if(flag < 0)
  {
    printf("Error: too many symbols.\n");
  }
  
  return 0;
}