//FormAI DATASET v1.0 Category: Arithmetic ; Style: happy
#include <stdio.h>

int main()
{
    int num1, num2, sum, diff, prod, quot, rem;

    printf("I'm so excited to do some math! Let's get started! \n");
    printf("Please enter two whole numbers separated by a space: ");
    scanf("%d %d", &num1, &num2);

    sum = num1 + num2;
    diff = num1 - num2;
    prod = num1 * num2;

    printf("Oh boy, I can already see the results! The sum of %d and %d is %d!\n", num1, num2, sum);
    printf("The difference of %d and %d is %d. Woohoo! \n", num1, num2, diff);
    printf("And my favorite... the product of %d and %d is %d! Yay math!\n", num1, num2, prod);

    if(num2 != 0)
    {
        quot = num1 / num2;
        rem = num1 % num2;

        printf("Hey hey, let's not forget about division! %d divided by %d is %d, with a remainder of %d\n", num1, num2, quot, rem);
    }
    else
    {
        printf("Oh no! Division by zero is undefined :(\n");
    }
    
    printf("All done! Thanks for doing math with me, I had a blast!\n");

    return 0;
}