//FormAI DATASET v1.0 Category: Educational ; Style: Linus Torvalds
/*
* This program generates the nth Fibonacci number recursively
* in C. It is written in the style of Linus Torvalds.
* By [Your Name]
*/

#include <stdio.h>

/**
* fibonacci - calculates the nth Fibonacci number recursively.
* @n: the index of the desired Fibonacci number.
* Return: the nth Fibonacci number.
*/
unsigned int fibonacci(unsigned int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    unsigned int n = 0;

    printf("Enter an index to print the nth Fibonacci number: ");
    scanf("%u", &n);

    printf("The %u%s Fibonacci number is: %u\n", n, n % 10 == 1 && n % 100 != 11 ? "st" :
                n % 10 == 2 && n % 100 != 12 ? "nd" :
                n % 10 == 3 && n % 100 != 13 ? "rd" : "th", fibonacci(n));

    return 0;
}