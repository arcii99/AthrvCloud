//FormAI DATASET v1.0 Category: Syntax parsing ; Style: excited
#include<stdio.h>
int main()
{
  printf("Welcome to my C Syntax Parsing Example Program!\n");
  printf("Let's get started!\n\n");

  char code[] = "int main() {\n    printf(\"Hello World!\");\n    return 0;\n}\n";
  int length = strlen(code);
  int tabs = 0;

  printf("Code to be parsed:\n");
  for(int i = 0; i < length; i++)
  {
    if(code[i] == '{')
    {
      tabs++;
      printf("{\n");
      for(int j = 0; j < tabs; j++)
      {
        printf("\t");
      }
    }
    else if(code[i] == '}')
    {
      tabs--;
      printf("\n");
      for(int j = 0; j < tabs; j++)
      {
        printf("\t");
      }
      printf("}\n");
      for(int j = 0; j < tabs; j++)
      {
        printf("\t");
      }
    }
    else if(code[i] == '\n')
    {
      printf("\n");
      for(int j = 0; j < tabs; j++)
      {
        printf("\t");
      }
    }
    else
    {
      printf("%c", code[i]);
    }
  }

  printf("\n\nCongratulations! You have successfully parsed a C syntax!\n");

  return 0;
}