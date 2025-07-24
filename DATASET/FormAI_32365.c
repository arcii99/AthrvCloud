//FormAI DATASET v1.0 Category: Educational ; Style: satisfied
#include <stdio.h>

/*
This program checks if a number is prime or not.
A prime number is a whole number greater than 1 that can't be divided by any number except 1 and itself.
*/

int main()
{
    int num, i, flag = 0; // flag = 0 means number is prime and flag = 1 means it's not prime

    printf("Please enter a number: ");
    scanf("%d", &num);

    if (num == 0 || num == 1)
    {
        printf("%d is not a prime number.\n", num);
        return 0;
    }

    for (i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        printf("%d is a prime number.\n", num);
    else
        printf("%d is not a prime number.\n", num);

    return 0;
}