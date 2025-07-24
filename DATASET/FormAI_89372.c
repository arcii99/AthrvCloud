//FormAI DATASET v1.0 Category: Syntax parsing ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>

int main()
{
  char input[100];                    //Declaring an input string of size 100
  printf("Enter a C syntax statement: ");
  fgets(input, sizeof(input), stdin);      //Taking the input from the user

  char delim[] = " ";                  //Defining the delimiter
  char *token = strtok(input, delim);      //Extracting the first token from the string

  while(token != NULL)
  {
    if(strcmp(token, "int") == 0)          //Checking if the token is 'int'
      printf("Data type: int\n");
    else if(strcmp(token, "float") == 0)      //Checking if the token is 'float'
      printf("Data type: float\n");
    else if(strcmp(token, "char") == 0)      //Checking if the token is 'char'
      printf("Data type: char\n");
    else if(strcmp(token, "for") == 0)      //Checking if the token is 'for'
      printf("Loop type: for\n");
    else if(strcmp(token, "while") == 0)      //Checking if the token is 'while'
      printf("Loop type: while\n");
    else if(strcmp(token, "if") == 0)        //Checking if the token is 'if'
      printf("Conditional statement: if\n");
    else if(strcmp(token, "else") == 0)      //Checking if the token is 'else'
      printf("Conditional statement: else\n");
    else
      printf("Unknown token\n");
      
    token = strtok(NULL, delim);          //Extracting the next token
  }
  
  return 0;
}