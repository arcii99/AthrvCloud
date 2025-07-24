//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: unmistakable
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main()
{
  char string[MAX_LENGTH];
  int length, i, end, middle;

  printf("Enter a string:");
  fgets(string, MAX_LENGTH, stdin);

  length = strlen(string) - 1; // subtracting 1 because fgets reads the newline character as well

  end = length - 1;
  middle = length / 2; // if length is odd, middle will be a whole number; if length is even, middle will be the lower of the two midpoints

  for (i = 0; i < middle; i++)
  {
    if (string[i] != string[end])
    {
      printf("%s is not a palindrome.\n", string);
      return 0;
    }
    end--;
  }
  
  printf("%s is a palindrome.\n", string);

  return 0;
}