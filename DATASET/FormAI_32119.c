//FormAI DATASET v1.0 Category: Funny ; Style: inquisitive
#include<stdio.h>

int main()
{
  int i,n,sum=0;

  printf("Enter a positive integer: ");
  scanf("%d",&n);

  printf("The first %d positive integers are: ",n);
  for(i=1;i<=n;i++)
  {
    printf("%d ",i);
    sum+=i;
  }

  printf("\nThe sum of first %d positive integers is %d\n",n,sum);

  /* Check if the sum is prime or not */
  for(i=2;i<sum;i++)
  {
    if(sum%i==0)
    {
      printf("%d is not a prime number.\n",sum);
      return 0;
    }
  }
  printf("%d is a prime number.\n",sum);

  return 0;
}