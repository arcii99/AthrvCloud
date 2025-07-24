//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: light-weight
#include <stdio.h>

int check_prime(int n);

int main()
{
    int num, i, prime = 1;
    printf("Enter an integer number: ");
    scanf("%d", &num);
    printf("The prime numbers between 1 and %d are: \n", num);

    for(i=2; i<=num; i++)
    {
        prime = check_prime(i);
        if(prime == 1)
        {
            printf("%d \n", i);
        }
    }
    return 0;
}

int check_prime(int n)
{
    int j, is_prime = 1;
    for(j=2; j<=n/2; j++)
    {
        if(n % j == 0)
        {
            is_prime = 0;
            break;
        }
    }
    return is_prime;
}