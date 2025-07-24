//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: grateful
#include<stdio.h>
#include<string.h>

void main()
{
  // Let's start by welcoming the user to our unique Palindrome Checker program.
  printf("\nWelcome to our Palindrome Checker program, where we check if a given string is Palindrome or not.\n");

  // Now, we will ask for user input.
  printf("\nEnter a string: ");

  // Moving on, we will store the input taken from the user in a character array.
  char str[50];
  scanf("%s", str);

  // Let's find the length of the string entered by the user.
  int length = strlen(str);

  // We will now create variables to keep track of our iterations.
  int i, j, flag=0;

  // Let's begin by iterating over the string.
  for(i=0, j=length-1; i<length/2; i++, j--)
  {
    // Let's check if the characters read while iterating are equal or not.
    if(str[i]!=str[j])
    {
      // If the characters are not equal, we will set the flag and break out of the loop.
      flag=1;
      break;
    }
  }

  // If our flag is set, that means the input string is not a palindrome.
  if(flag==1)
    printf("\nThe given string \"%s\" is not a Palindrome.\n", str);
  // If our flag is not set, that means the input string is a palindrome.
  else
    printf("\nThe given string \"%s\" is a Palindrome.\n", str);

  // Finally, let's bid goodbye to the user.
  printf("\nThank you for using our Palindrome Checker program. Have a nice day!\n");
}