//FormAI DATASET v1.0 Category: Error handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to my error handling program! Let's make sure everything runs smoothly!\n");
    
    int num1, num2, result;
    
    printf("Enter the first number: ");
    if (scanf("%d",&num1) != 1) //Checking if user enters a number or not
    {
        printf("Oops! That wasn't a number. Please try again.\n");
        exit(EXIT_FAILURE); //Exiting the program with an error code
    }
    
    printf("Enter the second number: ");
    if (scanf("%d",&num2) != 1)
    {
        printf("Oops! That wasn't a number. Please try again.\n");
        exit(EXIT_FAILURE);
    }
    
    if(num2 == 0) //Checking if second number is zero for division operation
    {
        printf("Oops! Cannot divide by zero. Please try again.\n");
        exit(EXIT_FAILURE);
    }
    
    result = num1/num2; //Performing division operation
    
    printf("The result of division is: %d\n",result);
    
    printf("Yay! We made it through without any errors. Thank you for using my program!\n");
    
    return 0;
}