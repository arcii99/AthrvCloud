//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 50

int main()
{
  char input[MAX_SIZE];
  printf("Enter a string up to 50 characters: ");
  fgets(input, MAX_SIZE, stdin);

  // Remove newline character from input
  int len = strlen(input);
  if (input[len - 1] == '\n')
    input[len - 1] = '\0';

  // Convert all characters to lowercase
  int i;
  for (i = 0; i < len; i++)
    input[i] = tolower(input[i]);

  // Check if the input is a palindrome
  int is_palindrome = 1; // Assume input is a palindrome
  int j = len - 1;
  for (i = 0; i < len / 2; i++) {
    if (input[i] != input[j]) {
      is_palindrome = 0;
      break;
    }
    j--;
  }

  // Display the result
  if (is_palindrome)
    printf("%s is a palindrome.\n", input);
  else
    printf("%s is not a palindrome.\n", input);

  return 0;
}