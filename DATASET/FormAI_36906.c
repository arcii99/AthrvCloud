//FormAI DATASET v1.0 Category: Arithmetic ; Style: invasive
#include<stdio.h>

int main()
{
    int num_1, num_2, sum, diff, prod;     // Declaration of variables

    printf("Enter the first number: ");    // Request user input
    scanf("%d", &num_1);

    printf("Enter the second number: ");
    scanf("%d", &num_2);

    sum = num_1 + num_2;                   // Addition operation
    printf("The sum of %d and %d is %d\n", num_1, num_2, sum);

    diff = num_1 - num_2;                  // Subtraction operation
    printf("The difference between %d and %d is %d\n", num_1, num_2, diff);

    prod = num_1 * num_2;                  // Multiplication operation
    printf("The product of %d and %d is %d\n", num_1, num_2, prod);

    if(num_2 != 0)                         // Checking for division by zero
    {
        printf("The result of %d divided by %d is %d\n", num_1, num_2, num_1/num_2);
    }
    else
    {
        printf("Cannot divide by zero, Enter a valid number\n");
    }

    return 0;                              // End of program
}