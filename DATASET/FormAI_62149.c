//FormAI DATASET v1.0 Category: Scientific ; Style: content
/* Program to Calculate Factorial of a Number */

#include <stdio.h>

int main()
{
    int number, factorial = 1;
    
    printf("Enter the Number: ");
    scanf("%d", &number);
    
    if(number < 0)
    {
        printf("Factorial of Negative Number doesn't Exist");
    }
    else
    {
        for(int i = 1; i <= number; i++)
        {
            factorial *= i;
        }
        
        printf("Factorial of %d = %d\n", number, factorial);
    }
    
    return 0;
}