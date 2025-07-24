//FormAI DATASET v1.0 Category: Text processing ; Style: retro
#include <stdio.h>
#include <string.h>

int main()
{
  char string[100], reverse[100];
  int length, i, j = 0;

  printf("Enter a string to reverse: ");
  scanf("%s", string);

  length = strlen(string);

  for (i = length - 1; i >= 0; i--)
  {
    reverse[j++] = string[i];
  }

  reverse[j] = '\0';

  printf("Reverse of the string: %s\n", reverse);

  return 0;
}