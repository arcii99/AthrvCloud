//FormAI DATASET v1.0 Category: Recursive ; Style: puzzling
#include<stdio.h>

int count = 0;

int recursive_puzzle(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }
    else if(n == 42)
    {
        printf("The Answer to the Ultimate Question of Life, the Universe, and Everything is 42.\n");
        return 42;
    }
    else if(n % 2 == 0)
    {
        count++;
        return recursive_puzzle(n/2);
    }
    else
    {
        count++;
        return recursive_puzzle(n*3+1);
    }
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int result = recursive_puzzle(n);

    printf("The result is: %d\n", result);
    printf("The program took %d steps to reach the result.\n", count);

    return 0;
}