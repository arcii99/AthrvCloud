//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: irregular
#include <stdio.h>

int main() 
{
  int input_number = 0;
  int is_prime = 1;

  printf("Please enter a number to check if it's prime: ");
  scanf("%d", &input_number);

  for (int i = 2; i < input_number; i++)
  {
    if (input_number % i == 0)
    {
      is_prime = 0;
      break;
    }
  }

  if (is_prime == 1)
  {
    printf("The number is a prime!");
  }
  else
  {
    printf("The number is not a prime!");
  }

  return 0;
}