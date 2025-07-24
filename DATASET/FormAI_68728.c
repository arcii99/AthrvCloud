//FormAI DATASET v1.0 Category: Recursive ; Style: detailed
#include <stdio.h>

// Recursive function to calculate the sum of natural numbers up to n
int sum_of_natural_numbers(int n)
{
    // Base case
    if (n == 1)
    {
        return 1;
    }
    // Recursive case
    else
    {
        return n + sum_of_natural_numbers(n - 1);
    }
}

int main()
{
    int n, sum;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Input validation
    while (n < 1)
    {
        printf("Invalid input. Please enter a positive integer: ");
        scanf("%d", &n);
    }

    sum = sum_of_natural_numbers(n);

    printf("The sum of natural numbers up to %d is %d", n, sum);

    return 0;
}