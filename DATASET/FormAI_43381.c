//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: authentic
#include <stdio.h>

int isPrime(int num);

int main()
{
  int i, n;
  printf("Enter the number of prime numbers to generate: ");
  scanf("%d", &n);

  printf("The first %d prime numbers are: ", n);

  for(i = 1; i <= n; i++)
  {
      if(isPrime(i))
      {
        printf("%d ", i);
      }
  }

  return 0;
}

int isPrime(int num)
{
    int i;
    if(num < 2)
    {
        return 0;
    }

    for(i = 2; i <= num/2; i++)
    {
        if(num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}