//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: high level of detail
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int number);

int main()
{
    int limit, count = 0, num = 2;
    printf("Enter the number of prime numbers you want: ");
    scanf("%d", &limit);
    printf("The first %d prime numbers are:\n", limit);
    while (count < limit)
    {
        if (isPrime(num))
        {
            printf("%d ", num);
            count++;
        }
        num++;
    }
    return 0;
}

bool isPrime(int number)
{
    int i;
    if (number < 2)
    {
        return false;
    }
    for (i = 2; i*i <= number; i++)
    {
        if (number%i == 0)
        {
            return false;
        }
    }
    return true;
}