//FormAI DATASET v1.0 Category: Syntax parsing ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  char syntax[50];
  int i, temp = 0, ifCounter = 0, braceOpen = 0, braceClose = 0;

  printf("Enter C syntax code:\n");
  scanf("%s", syntax);

  for(i=0;syntax[i]!='\0';i++)
  {
    if(syntax[i] == '{')
    {
      braceOpen++;
    }
    else if(syntax[i] == '}')
    {
      braceClose++;
    }
    else if(syntax[i] == 'i' && syntax[i+1] == 'f')
    {
      ifCounter++;
    }
    else if(syntax[i] == 'e' && syntax[i+1] == 'l' && syntax[i+2] == 's' && syntax[i+3] == 'e')
    {
      ifCounter--;
    }
  }

  if(ifCounter == 0 && braceOpen == braceClose)
  {
    printf("C syntax code compiled successfully!\n");
  }
  else
  {
    printf("C syntax code contains errors.\n");
  }

  return 0;
}