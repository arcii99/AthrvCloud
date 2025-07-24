//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_LEN 100

int is_palindrome(char *str)
{
  int length = strlen(str);
  char *front = str;
  char *back = str+length-1;

  while(front < back)
  {
    if(tolower(*front) != tolower(*back))
      return 0;
    ++front;
    --back;
  }

  return 1;
}

int main()
{
  char input[MAX_LEN];
  printf("Enter a string: ");
  fgets(input, MAX_LEN, stdin);

  if(is_palindrome(input))
    printf("The string is a palindrome.\n");
  else
    printf("The string is not a palindrome.\n");

  return 0;
}