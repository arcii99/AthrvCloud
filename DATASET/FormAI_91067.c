//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: realistic
#include <stdio.h>

int check_prime_number(int);

int main()
{
    int number, i, prime_counter=0;
    printf("Enter a number: ");
    scanf("%d", &number);

    printf("The prime numbers between 1 to %d are:\n", number);
    for(i=2; i<=number; i++)
    {
        if(check_prime_number(i))
        {
            printf("%d ", i);
            prime_counter++;
        }
    }
    printf("\nTotal prime numbers found: %d", prime_counter);
    return 0;
}

int check_prime_number(int n)
{
    int i;
    if(n <= 1)
    {
        return 0;
    }

    for(i=2; i<=n/2; i++)
    {
        if(n%i == 0)
        {
            return 0;
        }
    }

    return 1;
}