//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

int is_prime(int num)
{
    int i;
    for(i=2;i<=num/2;i++)
    {
        if(num%i==0)
            return 0;
    }
    return 1;
}

int main()
{
    int i,n;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("Invalid input\n");
        return 0;
    }
    int *primes=(int*)malloc(sizeof(int)*n);     //Dynamic allocation of memory
    primes[0]=2;
    int count=1,num=3;
    while(count<n)
    {
        if(is_prime(num))
        {
            primes[count]=num;
            count++;
        }
        num+=2;
    }
    printf("Prime numbers are: ");
    for(i=0;i<n;i++)
        printf("%d ",primes[i]);
    free(primes);   //Freeing the allocated memory
    return 0;
}