//FormAI DATASET v1.0 Category: Syntax parsing ; Style: peaceful
#include <stdio.h>

int main()
{
    printf("Welcome to my C Syntax parsing program!\n");
    
    // First, let's declare some variables
    int num1, num2, result;
    
    // Now we'll prompt the user to input two values
    printf("Please enter two integers:\n");
    scanf("%d %d", &num1, &num2);
    
    // Now we'll parse the values to check if they are within range
    if (num1 > 0 && num1 <= 100 && num2 > 0 && num2 <= 100)
    {
        // If they are within range, we'll perform some basic arithmetic
        result = num1 + num2;
        printf("The sum of %d and %d is %d.\n", num1, num2, result);
    }
    else
    {
        // If they are not within range, we'll let the user know
        printf("The values you entered are not within the range of 1 - 100.\n");
    }
    
    // Finally, we'll end the program
    printf("Thank you for using my program. Goodbye!\n");
    
    return 0;
}