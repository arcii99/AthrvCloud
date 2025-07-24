//FormAI DATASET v1.0 Category: Recursive ; Style: relaxed
#include <stdio.h>

// Function to calculate factorial recursively
int calculateFactorialRecursive(int num)
{
    if(num == 0 || num == 1)
    {
        // Base case
        return 1;
    }
    else
    {
        // Recursive case
        return num * calculateFactorialRecursive(num-1);
    }
}

// Main function
int main()
{
    int num, factorial;
    printf("Enter a number: ");
    scanf("%d",&num);
    
    if(num < 0)
    {
        printf("Negative numbers do not have factorial.");
    }
    else
    {
        factorial = calculateFactorialRecursive(num);
        printf("Factorial of %d is %d",num, factorial);
    }
    
    return 0;
}