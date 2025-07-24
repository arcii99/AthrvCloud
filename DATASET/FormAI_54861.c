//FormAI DATASET v1.0 Category: Syntax parsing ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  char input[100];
  printf("Enter C syntax: ");
  fgets(input, 100, stdin);

  // checking syntax for keywords
  char keywords[32][15] = {
    "auto", "break", "case", "char", "const", "continue", "default",
    "do", "double", "else", "enum", "extern", "float", "for",
    "goto", "if", "int", "long", "register", "return", "short",
    "signed", "sizeof", "static", "struct", "switch", "typedef",
    "union", "unsigned", "void", "volatile", "while"
  };
  
  const char delimiters[] = " ,;:{}()\n";
  char *word = strtok(input, delimiters);

  while(word != NULL)
  {
    int keyword_found = 0;
    
    for(int i=0; i<32; i++)
    {
      if(strcmp(keywords[i], word) == 0)
      {
        printf("%s is a keyword in C syntax.\n", word);
        keyword_found = 1;
        break;
      }
    }
    
    if(keyword_found == 0)
      printf("%s is not a keyword in C syntax.\n", word);
    
    word = strtok(NULL, delimiters);
  }

  return 0;
}