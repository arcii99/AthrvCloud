//FormAI DATASET v1.0 Category: Recursive ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int recursive_puzzle(int x)
{
    if (x == 0)
    {
        return 1;
    }
    else if (x == 1)
    {
        return 2;
    }
    else if (x == 2)
    {
        return 4;
    }
    else if (x % 10 == 0)
    {
        return recursive_puzzle(x / 10);
    }
    else if (x % 2 == 0)
    {
        return 2 * recursive_puzzle(x - 1);
    }
    else
    {
        return recursive_puzzle(x - 1) + recursive_puzzle(x - 2) + recursive_puzzle(x - 3);
    }
}

int main()
{
    int input;
    printf("Welcome to the Recursive Puzzle!\n");
    printf("Please enter a positive integer: ");
    scanf("%d", &input);
    if (input < 0)
    {
        printf("Invalid input.\n");
        return 0;
    }
    printf("The result is: %d\n", recursive_puzzle(input));
    return 0;
}