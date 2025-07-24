//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: irregular
#include<stdio.h>

// This is a simple program to find the factorial of a number

int main()
{
    int num, i, fact=1;
    
    // User enters a number
    printf("Enter the number: ");
    scanf("%d",&num);
    
    // If the number is negative, return an error
    if(num < 0)
    {
        printf("Error! Factorial of a negative number doesn't exist.");
        return 0;
    }
    
    // Calculate the factorial
    for(i=1;i<=num;i++)
    {
        fact *= i;
    }
    
    // Display the factorial
    printf("Factorial of %d is %d", num, fact);
    
    return 0;
}