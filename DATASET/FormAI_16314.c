//FormAI DATASET v1.0 Category: Recursive ; Style: funny
#include <stdio.h>

int recursiveFunction(int n)
{
    if (n == 0)
    {
        printf("Oh no! You've reached the end of recursion!\n");
        return 0;
    }
    else if (n % 2 == 0)
    {
        printf("%d is an even number, how boring. Let's keep recursing.\n", n);
        return recursiveFunction(n / 2);
    }
    else
    {
        printf("%d is an odd number, how exciting!\n", n);
        return recursiveFunction(n - 1);
    }
}

int main()
{
    printf("Welcome to the Recursive Funhouse!\n");
    printf("Please enter a positive integer to start the fun: ");
    int n;
    scanf("%d", &n);
    printf("Starting the fun with %d...\n", n);
    recursiveFunction(n);
    printf("Hope you had fun! Bye bye!\n");
    return 0;
}