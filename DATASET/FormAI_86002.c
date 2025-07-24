//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: decentralized
#include<stdio.h> 

int main() 
{ 
  char c[100];
  int i, j;
  printf("Enter the string: \n");
  fgets(c, sizeof(c), stdin); // read input from user
  printf("\nC Cat Language Translation: \n");
  
  i = 0;
  while(c[i] != '\0')
  {
    if(c[i] == ' ')
    {
      printf("meow ");
      j = i+1;
      while(c[j] == ' ') j++;
      i = j;
    }
    else if(c[i] == '\n')
    {
      printf("\n");
      i++;
    }
    else if(c[i] == '.')
    {
      printf("purr ");
      i++;
    }
    else if(c[i] == ',')
    {
      printf("hiss ");
      i++;
    }
    else if(c[i] == ';')
    {
      printf("paw_swing ");
      i++;
    }
    else
    {
      printf("meow");
      i++;
    }
  }

  return 0;
}