//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: protected
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int);

int main()
{
    int n, i = 2, count = 0;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("The first %d prime numbers are: \n", n);

    while (count < n)
    {
        if (isPrime(i))
        {
            printf("%d ", i);
            count++;
        }
        i++;
    }
    return 0;
}

bool isPrime(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}