//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
  srand (time (NULL)); //initialize random seed

  int num;
  printf ("Enter a positive integer between 1 and 10: ");
  scanf ("%d", &num);

  if (num <= 0 || num >= 11) //check input validity
    {
      printf ("Invalid input. Please enter a number between 1 and 10.\n");
      return 1;
    }

  int num1 = rand () % 10 + 1;
  int num2 = rand () % 10 + 1;
  int num3 = rand () % 10 + 1;

  printf ("Your lucky numbers are: %d, %d, %d\n", num1, num2, num3);

  int sum = num1 + num2 + num3;
  int product = num1 * num2 * num3;

  if (sum == num)
    {
      printf ("Your lucky number matches your input. Today is your lucky day!\n");
    }
  else if (product == num)
    {
      printf ("Your lucky number matches your input. Today is your lucky day!\n");
    }
  else
    {
      printf ("Today is not your lucky day. Better luck next time!\n");
    }

  return 0;
}