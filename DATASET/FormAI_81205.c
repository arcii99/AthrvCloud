//FormAI DATASET v1.0 Category: Educational ; Style: protected
/*
  Title: Protected Style Example Program
  Description: This program demonstrates a unique example program in the protected style coding convention 
*/

#include <stdio.h>

#define SECRET_KEY 12345 // A secret key for the program

void authenticate()
{
  int key; // Declare a variable to hold the user's key input

  printf("Please enter the secret key: "); // Prompt the user to enter the key
  scanf("%d", &key); // Read in the user's input

  if (key != SECRET_KEY) // If the keys don't match
  {
    printf("Access denied.\n"); // Print an error message
    exit(0); // Exit the program
  }
}

int main()
{
  int num;

  printf("Welcome to the protected program!\n");
  authenticate(); // Call the authentication function

  printf("Please enter a number: ");
  scanf("%d", &num);

  if (num < 50)
  {
    printf("The number is less than 50.\n");
  }
  else
  {
    printf("The number is greater than or equal to 50.\n");
  }

  return 0; // Return 0 to indicate successful program execution
}