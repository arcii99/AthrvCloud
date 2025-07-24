//FormAI DATASET v1.0 Category: Arithmetic ; Style: recursive
#include <stdio.h>

// Recursive function to add two numbers
int add(int x, int y)
{
    // Base case: if y is 0, return x
    if (y == 0) {
        return x;
    }

    // Recursive case: add 1 to x and subtract 1 from y
    return add(x + 1, y - 1);
}

// Recursive function to subtract two numbers
int subtract(int x, int y)
{
    // Base case: if y is 0, return x
    if (y == 0) {
        return x;
    }

    // Recursive case: subtract 1 from x and y
    return subtract(x - 1, y - 1);
}

// Recursive function to multiply two numbers
int multiply(int x, int y)
{
    // Base case: if y is 1, return x
    if (y == 1) {
        return x;
    }

    // Recursive case: add x to itself y times
    return add(x, multiply(x, y - 1));
}

// Recursive function to divide two numbers
int divide(int x, int y)
{
    // Base case: if x is less than y, return 0
    if (x < y) {
        return 0;
    }

    // Recursive case: subtract y from x and add 1 to the quotient
    return add(1, divide(subtract(x, y), y));
}

int main()
{
    int num1 = 10, num2 = 5;

    printf("Adding %d and %d: %d\n", num1, num2, add(num1, num2));

    printf("Subtracting %d from %d: %d\n", num2, num1, subtract(num1, num2));

    printf("Multiplying %d and %d: %d\n", num1, num2, multiply(num1, num2));

    printf("Dividing %d by %d: %d\n", num1, num2, divide(num1, num2));

    return 0;
}