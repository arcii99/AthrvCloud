//FormAI DATASET v1.0 Category: Recursive ; Style: real-life
#include<stdio.h>

// The factorial function takes an integer as input.
// It then recursively calculates the factorial.
int factorial(int num)
{
    if(num == 0 || num == 1)  // Base case
        return 1;
    
    else
        return num * factorial(num - 1);  // Recursive case
}

int main()
{
    int number;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &number);
    
    // Error handling
    if(number < 0) 
    {
        printf("Cannot find factorial of negative numbers\n");
        return 0;
    }
    
    int result = factorial(number);  // Call the factorial function
    
    printf("The factorial of %d is %d\n", number, result);
    
    return 0;  // exit the program
}