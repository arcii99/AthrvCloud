//FormAI DATASET v1.0 Category: Error handling ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  // Declare variable for user input
  int num;

  // Ask for user input
  printf("Hello! Please enter a number greater than 5: ");
  scanf("%d", &num);

  // Check if number is greater than 5
  if (num <= 5)
  {
    // Oops! The user did not follow the instructions...
    printf("Uh-oh! You did not follow instructions!\n");
    printf("You were supposed to enter a number greater than 5, but you entered %d!\n", num);

    // Handle the error
    printf("Here's what we can do to fix this error: \n");
    printf("Let's add 5 to your number to make it greater than 5!\n");

    // Fix the error
    num += 5;

    // Confirm that error is fixed
    printf("Your new number is %d! Yay!\n", num);
  }
  else
  {
    // User followed the instructions correctly
    printf("Great job! You entered a number greater than 5! Your number is %d.\n", num);

    // Celebrate the success!
    printf("Congratulations on following instructions correctly and avoiding error handling!\n");
    printf("Stay cool and continue to write bug-free code! :)\n");
  }

  return 0;
}