//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: all-encompassing
#include<stdio.h>
#include<string.h>

int main()
{
  char input[100],output[100];
  printf("Enter the cat language: ");
  fgets(input,100,stdin);
  input[strcspn(input,"\n")]='\0';
  int i=0,j=0;
  while(input[i]!='\0')
  {
    switch(input[i])
    {
      case 'M':
      output[j]='0';
      j++;
      break;
      case 'E':
      output[j]='1';
      j++;
      break;
      case 'W':
      output[j]='2';
      j++;
      break;
      case 'O':
      output[j]='3';
      j++;
      break;
      case 'H':
      output[j]='4';
      j++;
      break;
      case 'R':
      output[j]='5';
      j++;
      break;
      case 'L':
      output[j]='6';
      j++;
      break;
      case 'D':
      output[j]='7';
      j++;
      break;
      case 'U':
      output[j]='8';
      j++;
      break;
      case 'C':
      output[j]='9';
      j++;
      break;
      case ' ':
      output[j]=input[i];
      j++;
      break;
      default:
      printf("\nInvalid Cat language!");
      return 0;
    }
    i++;
  }
  output[j]='\0';

  printf("\nTranslated Cat language: %s",output);
  return 0;
}