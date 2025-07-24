//FormAI DATASET v1.0 Category: String manipulation ; Style: expert-level
/**
* Program: String Manipulation
* Author: Expert Chatbot
* Purpose: This program demonstrates various string manipulation functions.
*/

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100 // Maximum string size

int main()
{
  char str[MAX_SIZE], choice;
  int i, j, len;

  printf("Enter a string: ");
  fgets(str, MAX_SIZE, stdin);
  len = strlen(str)-1; // Removing '\n' from the end of string due to fgets

  do
  {
    printf("\nChoose a manipulation option:\n");
    printf("1. Reverse the string\n");
    printf("2. Convert the string to uppercase\n");
    printf("3. Convert the string to lowercase\n");
    printf("4. Count the number of words in the string\n");
    printf("5. Exit the program\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    switch(choice)
    {
      case '1': // Reverse the string
        for(i=0, j=len-1; i<j; i++, j--)
        {
          char temp = str[i];
          str[i] = str[j];
          str[j] = temp;
        }
        printf("Reversed string: %s\n", str);
        break;

      case '2': // Convert the string to uppercase
        for(i=0; i<len; i++)
        {
          if(str[i] >= 'a' && str[i] <= 'z')
          {
            str[i] = str[i] -32;
          }
        }
        printf("Uppercase string: %s\n", str);
        break;

      case '3': // Convert the string to lowercase
        for(i=0; i<len; i++)
        {
          if(str[i] >= 'A' && str[i] <= 'Z')
          {
            str[i] = str[i] +32;
          }
        }
        printf("Lowercase string: %s\n", str);
        break;

      case '4': // Count the number of words in the string
        int count = 0;
        for(i=0; i<len; i++)
        {
          if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
          {
            count++;
          }
        }
        printf("Number of words in the string: %d\n", count+1);
        break;

      case '5': // Exit the program
        printf("Exiting the program...\n");
        break;

      default:
        printf("Invalid choice! Please select a valid option.\n");
        break;
    }
  } while(choice != '5');

  return 0;
}