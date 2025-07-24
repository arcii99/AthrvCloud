//FormAI DATASET v1.0 Category: Educational ; Style: mathematical
#include <stdio.h>

// Function to calculate the factorial of a number
int factorial(int num)
{
    int fact = 1;

    while(num > 1)
    {
        fact *= num;
        num--;
    }

    return fact;
}

// Main function
int main()
{
    // Prompt user to enter a number
    printf("Enter a number: ");

    // Get input from user
    int num;
    scanf("%d", &num);

    // Calculate and print the factorial of the number
    int fact = factorial(num);
    printf("The factorial of %d is %d\n", num, fact);

    return 0;
}