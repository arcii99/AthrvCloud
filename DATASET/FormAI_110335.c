//FormAI DATASET v1.0 Category: Recursive ; Style: Alan Touring
#include <stdio.h>

// Define recursive function to calculate factorial of a number
int factorial(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n-1);
    }
}

int main()
{
    int num;

    // Take input from user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Call the recursive function to calculate factorial
    int result = factorial(num);

    // Display the result
    printf("Factorial of %d is %d\n", num, result);

    return 0;
}