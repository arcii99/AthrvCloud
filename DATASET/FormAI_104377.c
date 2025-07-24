//FormAI DATASET v1.0 Category: Syntax parsing ; Style: energetic
#include<stdio.h>
#include<stdlib.h>

// This is a program that parses through C syntax to identify variables and their data types.

int main()
{
  // printing program instructions
  printf("Please enter a C syntax statement:\n");
  
  // initializing variables for input and parsing
  char input[100];
  int i, j, flag=0, len=0;
  
  // reading input statement
  fgets(input, sizeof(input), stdin);

  // parsing through statement
  for(i=0; input[i]!='\0'; i++)
  {
    // checking for data type
    if((input[i]=='i')&&(input[i+1]=='n')&&(input[i+2]=='t')&&(input[i+3]==' '))
    {
      // printing data type
      printf("Data type: Integer\n");
      
      // finding variable name
      for(j=i+4; input[j]!=';'; j++)
      {
        // printing variable name
        if((input[j]>='a'&&input[j]<='z')||(input[j]>='A'&&input[j]<='Z'))
        {
          flag=1;
          printf("Variable name: ");
        }
        if(input[j]=='=')
        {
          printf("Value assignment: ");
        }
        if(flag)
        {
          printf("%c", input[j]);
          len++;
        }
      }
      
      // printing variable length
      printf("\nVariable length: %d bytes\n", sizeof(int)*len);
    }
    else if((input[i]=='c')&&(input[i+1]=='h')&&(input[i+2]=='a')&&(input[i+3]=='r')&&(input[i+4]==' '))
    {
      // printing data type
      printf("Data type: Character\n");
      
      // finding variable name
      for(j=i+5; input[j]!=';'; j++)
      {
        // printing variable name
        if((input[j]>='a'&&input[j]<='z')||(input[j]>='A'&&input[j]<='Z'))
        {
          flag=1;
          printf("Variable name: ");
        }
        if(input[j]=='=')
        {
          printf("Value assignment: ");
        }
        if(flag)
        {
          printf("%c", input[j]);
          len++;
        }
      }
      
      // printing variable length
      printf("\nVariable length: %d bytes\n", sizeof(char)*len);
    }
    else if((input[i]=='f')&&(input[i+1]=='l')&&(input[i+2]=='o')&&(input[i+3]=='a')&&(input[i+4]=='t')&&(input[i+5]==' '))
    {
      // printing data type
      printf("Data type: Float\n");
      
      // finding variable name
      for(j=i+6; input[j]!=';'; j++)
      {
        // printing variable name
        if((input[j]>='a'&&input[j]<='z')||(input[j]>='A'&&input[j]<='Z'))
        {
          flag=1;
          printf("Variable name: ");
        }
        if(input[j]=='=')
        {
          printf("Value assignment: ");
        }
        if(flag)
        {
          printf("%c", input[j]);
          len++;
        }
      }
      
      // printing variable length
      printf("\nVariable length: %d bytes\n", sizeof(float)*len);
    }
    else if((input[i]=='d')&&(input[i+1]=='o')&&(input[i+2]=='u')&&(input[i+3]=='b')&&(input[i+4]=='l')&&(input[i+5]=='e')&&(input[i+6]==' '))
    {
      // printing data type
      printf("Data type: Double\n");
      
      // finding variable name
      for(j=i+7; input[j]!=';'; j++)
      {
        // printing variable name
        if((input[j]>='a'&&input[j]<='z')||(input[j]>='A'&&input[j]<='Z'))
        {
          flag=1;
          printf("Variable name: ");
        }
        if(input[j]=='=')
        {
          printf("Value assignment: ");
        }
        if(flag)
        {
          printf("%c", input[j]);
          len++;
        }
      }
      
      // printing variable length
      printf("\nVariable length: %d bytes\n", sizeof(double)*len);
    }
  }
  
  // exiting program
  return 0;
}