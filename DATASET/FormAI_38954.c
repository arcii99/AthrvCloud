//FormAI DATASET v1.0 Category: Arithmetic ; Style: cheerful
#include <stdio.h>

int main()
{
    int num1, num2, sum, diff, prod, absolute_difference;     // declaring integer variables

    printf("Hello! I'm a cheerful arithmetic program.\n");
    printf("Let's do some fun maths together!\n\n");

    printf("Please enter two numbers:\n");
    scanf("%d%d", &num1, &num2);        // Taking input from user

    sum = num1 + num2;
    diff = num1 - num2;
    prod = num1 * num2;

    if (num1 >= num2)
    {
        absolute_difference = num1 - num2;
    }
    else
    {
        absolute_difference = num2 - num1;
    }

    printf("\nWoo-hoo! Here are the results:\n");

    printf("\n%d + %d = %d", num1, num2, sum);      // Addition
    printf("\n%d - %d = %d", num1, num2, diff);     // Subtraction
    printf("\n%d * %d = %d", num1, num2, prod);     // Multiplication

    printf("\nAnd, the absolute difference between the two numbers is %d!\n", absolute_difference);     // Absolute difference

    printf("\nThanks for playing with me! Have a great day ahead!!\n\n");

    return 0;
}