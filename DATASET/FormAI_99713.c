//FormAI DATASET v1.0 Category: Arithmetic ; Style: surprised
#include <stdio.h>

int main()
{
    printf("SURPRISE! Let's do some arithmetic!\n");

    int num1, num2;
    printf("Please enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int sum = num1 + num2;
    printf("\nWow! The sum of %d and %d is %d\n", num1, num2, sum);

    int difference = num1 - num2;
    printf("Shocking! The difference of %d and %d is %d\n", num1, num2, difference);

    int product = num1 * num2;
    printf("Unbelievable! The product of %d and %d is %d\n", num1, num2, product);

    if (num2 == 0)
    {
        printf("Oh no! The second number is equal to 0. We can't perform division!\n");
    }
    else
    {
        float quotient = (float) num1 / num2;
        printf("OMG! The quotient of %d and %d is %.2f\n", num1, num2, quotient);
    }

    int mod = num1 % num2;
    printf("WOWZER! The modulus of %d and %d is %d\n", num1, num2, mod);

    printf("\nThat was some wild math! I hope you enjoyed it!\n");

    return 0;
}