//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Sherlock Holmes
#include<stdio.h>

int main()
{
  char alienLanguage[100];
  
  printf("Enter the alien language: ");
  scanf("%s", alienLanguage);
  
  int i;
  for(i=0; i<100; i++)
  {
    if(alienLanguage[i] == '\0')
      break;
    else if(alienLanguage[i] == 'a')
      printf("z");
    else if(alienLanguage[i] == 'b')
      printf("y");
    else if(alienLanguage[i] == 'c')
      printf("x");
    else if(alienLanguage[i] == 'd')
      printf("w");
    else if(alienLanguage[i] == 'e')
      printf("v");
    else if(alienLanguage[i] == 'f')
      printf("u");
    else if(alienLanguage[i] == 'g')
      printf("t");
    else if(alienLanguage[i] == 'h')
      printf("s");
    else if(alienLanguage[i] == 'i')
      printf("r");
    else if(alienLanguage[i] == 'j')
      printf("q");
    else if(alienLanguage[i] == 'k')
      printf("p");
    else if(alienLanguage[i] == 'l')
      printf("o");
    else if(alienLanguage[i] == 'm')
      printf("n");
    else if(alienLanguage[i] == 'n')
      printf("m");
    else if(alienLanguage[i] == 'o')
      printf("l");
    else if(alienLanguage[i] == 'p')
      printf("k");
    else if(alienLanguage[i] == 'q')
      printf("j");
    else if(alienLanguage[i] == 'r')
      printf("i");
    else if(alienLanguage[i] == 's')
      printf("h");
    else if(alienLanguage[i] == 't')
      printf("g");
    else if(alienLanguage[i] == 'u')
      printf("f");
    else if(alienLanguage[i] == 'v')
      printf("e");
    else if(alienLanguage[i] == 'w')
      printf("d");
    else if(alienLanguage[i] == 'x')
      printf("c");
    else if(alienLanguage[i] == 'y')
      printf("b");
    else if(alienLanguage[i] == 'z')
      printf("a");
    else
      printf("%c", alienLanguage[i]);
  }
  
  return 0;
}