//FormAI DATASET v1.0 Category: Scientific ; Style: beginner-friendly
#include <stdio.h>

// Function to calculate the factorial of a number using recursion
int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}

int main()
{
    int num;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &num);

    // Calling the fact() function to calculate the factorial of the entered number
    int res = fact(num);

    printf("The factorial of %d is %d.", num, res);
    return 0;
}