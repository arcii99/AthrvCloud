//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int MAX_SIZE = 100;

int main()
{
  char str[MAX_SIZE], rev[MAX_SIZE];
  int i, j, len;

  printf("Enter a string: ");
  fgets(str, MAX_SIZE, stdin);

  // Remove non-alphanumeric characters and convert to lowercase
  for(i = 0, j = 0; i < strlen(str); i++)
  {
    if(isalnum(str[i]))
    {
      rev[j++] = tolower(str[i]);
    }
  }
  rev[j] = '\0';

  len = strlen(rev);
  for(i = 0, j = len-1; i < len/2; i++, j--)
  {
    char temp = rev[i];
    rev[i] = rev[j];
    rev[j] = temp;
  }

  // Compare the reversed string with the original string
  if(strcmp(rev, str) == 0)
  {
    printf("The string is a palindrome.\n");
  }
  else
  {
    printf("The string is not a palindrome.\n");
  }

  return 0;
}