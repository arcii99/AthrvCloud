//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Linus Torvalds
#include<stdio.h>

int isPrime(int num)
{
    int i;
    if (num <= 1) 
        return 0;
    for (i=2; i<num; i++)
    {
        if (num%i == 0) 
            return 0;
    }
    return 1;
}

int main()
{
    int i,j;
    printf("Generating prime numbers until 100...\n");
    for(i=2;i<=100;++i)
    {
        if(isPrime(i))
            printf("[%d] is prime\n",i);
    }
    printf("Done!\n");

    return 0;
}