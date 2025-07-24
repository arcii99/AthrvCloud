//FormAI DATASET v1.0 Category: Arithmetic ; Style: visionary
#include<stdio.h>
#include<stdlib.h>

int main()
{
  int a, b, c, x, y, z, result1, result2, finalResult;
  printf("Welcome to my visionary arithmetic program!\n");
  printf("Please enter your first number: ");
  scanf("%d", &a);
  printf("Please enter your second number: ");
  scanf("%d", &b);
  printf("Please enter your third number: ");
  scanf("%d", &c);

  x = a * b + 3; // Perform a multiplication and add 3
  y = x / c - 2; // Divide x by c and subtract 2
  z = y % 5; // Perform a remainder operation by dividing by 5

  result1 = (a + b) * c; // Perform an addition first, then multiplication
  result2 = a * b + b * c; // Perform multiplication first, then addition

  finalResult = z + result1 - result2; // Combine all above values

  printf("\nYour visionary arithmetic result is: %d\n", finalResult);
  printf("Thank you for using my program! Have a great day! :)");
  return 0;
}