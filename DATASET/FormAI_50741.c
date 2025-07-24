//FormAI DATASET v1.0 Category: Bitwise operations ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

// Bitwise operations recursive function
int bitwiseRecursive(int a, int b, char op)
{
    if (op == '&')
    {
        if (a == 0 || b == 0)
            return 0;
        else if (a == 1 && b == 1)
            return 1;
        else
            return bitwiseRecursive(a >> 1, b >> 1, '&') << 1;
    }
    else if (op == '|')
    {
        if (a == 1 || b == 1)
            return 1;
        else if (a == 0 && b == 0)
            return 0;
        else
            return bitwiseRecursive(a >> 1, b >> 1, '|') << 1;
    }
    else if (op == '^')
    {
        if ((a == 1 && b == 0) || (a == 0 && b == 1))
            return 1;
        else if ((a == 1 && b == 1) || (a == 0 && b == 0))
            return 0;
        else
            return bitwiseRecursive(a >> 1, b >> 1, '^') << 1;
    }
    else
    {
        printf("Invalid operator!");
        exit(0);
    }
}

int main()
{
    int a, b;
    char op;

    // Prompt the user to enter inputs
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    printf("Enter the operator [& | ^]: ");
    scanf(" %c", &op);

    // Print the result of bitwise operations
    printf("\nBitwise operations on %d and %d using %c operator = %d", a, b, op, bitwiseRecursive(a, b, op));

    return 0;
}