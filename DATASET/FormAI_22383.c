//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: detailed
// C Palindrome Checker
#include <stdio.h>
#include <string.h>

int main()
{
  char str[100], rev_str[100];
  int i, j, len, flag;

  printf("Enter a string: ");
  scanf("%s", str);

  len = strlen(str);

  // Reverse the entered string
  j = 0;
  for (i = len - 1; i >= 0; i--)
  {
    rev_str[j++] = str[i];
  }
  rev_str[j] = '\0';

  // Check if the reversed string is same as the original string
  flag = strcmp(str, rev_str);
  
  if (flag == 0)
  {
    printf("\"%s\" is a palindrome.\n", str);
  }
  else
  {
    printf("\"%s\" is not a palindrome.\n", str);
  }

  return 0;
}