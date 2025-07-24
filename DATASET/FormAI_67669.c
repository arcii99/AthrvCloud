//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

bool isPrime(int n)
{
    if(n<=1)
        return false;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

void generatePrime(int n)
{
   int prime[n],count=0;
   for(int i=2;i<=n;i++)
   {
        if(isPrime(i))
        {
            prime[count++]=i;
        }
   }
   printf("The prime numbers between 2 and %d are:\n",n);
   for(int i=0;i<count;i++)
   {
       printf("%d ",prime[i]);
   }
}

int main()
{
    int n;
    printf("Enter the maximum limit to find prime numbers:");
    scanf("%d",&n);
    generatePrime(n);
    return 0;
}