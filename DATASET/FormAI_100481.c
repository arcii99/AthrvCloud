//FormAI DATASET v1.0 Category: Arithmetic ; Style: mathematical
#include <stdio.h>

/* This arithmetic example program will calculate the sum of all the odd or even numbers between two integers */
/* The program will ask the user to input two numbers */
/* If the first number is even, it will calculate the sum of all even numbers in the range between the two numbers */
/* If the first number is odd, it will calculate the sum of all odd numbers in the range between the two numbers */

int main() 
{
  int first_num, second_num, sum = 0;
  
  printf("Enter the first number: ");
  scanf("%d", &first_num);
  printf("Enter the second number: ");
  scanf("%d", &second_num);
  
  if (first_num % 2 == 0) // If first_num is even
  {
    for (int i = first_num; i <= second_num; i += 2) // Loop through even numbers in range
    {
      sum += i;
    }
    printf("The sum of all even numbers between %d and %d is %d", first_num, second_num, sum);
  }
  else // If first_num is odd
  {
    for (int i = first_num; i <= second_num; i += 2) // Loop through odd numbers in range
    {
      sum += i;
    }
    printf("The sum of all odd numbers between %d and %d is %d", first_num, second_num, sum);
  }
  return 0;
}