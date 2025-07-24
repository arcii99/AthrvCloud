//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: curious
#include <stdio.h>

int isPrime(int num)
{
    int i;
    for(i = 2; i <= num/2; ++i)
    {
        if(num%i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n, i;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);
    int count = 0;
    int num = 2;
    printf("The first %d prime numbers are:\n", n);
    while(count < n)
    {
        if(isPrime(num) == 1)
        {
            printf("%d\n", num);
            count++;
        }
        num++;
    }
    return 0;
}