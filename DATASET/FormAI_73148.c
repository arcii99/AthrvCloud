//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

int main()
{
  printf("Welcome to the Palindrome Checker Program!\n");
  printf("Enter a word or phrase to check if it is a palindrome:\n");

  char input[100];
  fgets(input, 100, stdin);

  // Remove any spaces or new line characters from the input string
  for (int i = 0; i < strlen(input); i++)
  {
    if (input[i] == ' ' || input[i] == '\n')
    {
      for (int j = i; j < strlen(input); j++)
      {
        input[j] = input[j + 1];
      }
      i--;
    }
  }

  // Compare the first and last letters, then the second and second to last, and so on
  int palindrome = 1;
  for (int i = 0; i < strlen(input) / 2; i++)
  {
    if (input[i] != input[strlen(input) - 1 - i])
    {
      palindrome = 0;
      break;
    }
  }

  if (palindrome)
  {
    printf("Congratulations! \"%s\" is a palindrome!\n", input);
  }
  else
  {
    printf("Sorry, \"%s\" is not a palindrome.\n", input);
  }

  printf("Thank you for using the Palindrome Checker Program in the post-apocalyptic world. Stay safe out there!\n");

  return 0;
}