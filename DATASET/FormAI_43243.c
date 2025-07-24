//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: puzzling
#include <stdio.h>
int main()
{
  printf("Welcome to the Prime Number Generator. Please enter an upper bound: ");
  int max;
  scanf("%d", &max);

  printf("\nGenerating prime numbers up to %d...\n\n", max);

  int prime[max], index = 0, test;
  prime[0] = 2;
  index++;

  for(int i = 3; i <= max; i += 2)
  {
    test = 1;

    for(int j = 0; j < index; j++)
    {
      if(i % prime[j] == 0)
      {
        test = 0;
        break;
      }
    }

    if(test == 1)
    {
      prime[index] = i;
      index++;
    }
  }

  printf("Prime numbers up to %d:\n", max);

  for(int i = 0; i < index; i++)
  {
    printf("%d ", prime[i]);
  }

  printf("\n\nThank you for using the Prime Number Generator!");

  return 0;
}