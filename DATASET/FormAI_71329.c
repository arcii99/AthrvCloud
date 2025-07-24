//FormAI DATASET v1.0 Category: Scientific ; Style: lively
#include <stdio.h>

int main()
{
    int num1 = 10;
    int num2 = 20;

    printf("Welcome to our exciting math program!\n");
    printf("In this program, we will perform some simple arithmetic calculations.\n");

    printf("The sum of %d and %d is %d.\n", num1, num2, num1 + num2);
    printf("The difference between %d and %d is %d.\n", num2, num1, num2 - num1);
    printf("The product of %d and %d is %d.\n", num1, num2, num1 * num2);

    if(num2 > num1)
    {
        printf("%d is greater than %d.\n", num2, num1);
    }
    else
    {
        printf("%d is greater than %d.\n", num1, num2);
    }

    printf("Thanks for using our math program! Come again soon!\n");
    
    return 0;
}