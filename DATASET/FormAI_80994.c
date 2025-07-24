//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Linus Torvalds
#include <stdio.h>

int is_prime(int num)
{
    int i;
    if (num < 2)
        return 0;
    for (i = 2; i < num; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int count = 0, num = 2, check;
    printf("Prime numbers between 1 and 1000 are:\n");
    while (num <= 1000)
    {
        check = is_prime(num);
        if (check == 1)
        {
            count++;
            printf("%d ", num);
        }
        num++;
    }
    printf("\nTotal number of prime numbers between 1 and 1000: %d\n", count);
    return 0;
}