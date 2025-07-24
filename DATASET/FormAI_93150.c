//FormAI DATASET v1.0 Category: Arithmetic ; Style: cheerful
#include <stdio.h>

int main() {
    int num1, num2;
    printf("Hey there! Let's do some math! Enter a number: ");
    scanf("%d", &num1);
    printf("Great choice! Now enter another number: ");
    scanf("%d", &num2);

    int sum = num1 + num2;
    printf("\nAwesome! Here's the sum: %d\n", sum);

    int difference = num1 - num2;
    printf("That was amazing! Here's the difference: %d\n", difference);

    int product = num1 * num2;
    printf("Wohoo! Here's the product: %d\n", product);

    printf("Let's see if we can divide the numbers!...\n");

    if (num2 == 0) {
        printf("Oops! Cannot divide by zero... Try again.\n");
    } else {
        float quotient = (float) num1 / num2;
        printf("Congratulations! Here's the quotient: %.2f\n", quotient);
    }

    int remainder = num1 % num2;
    printf("Finally, here's the remainder: %d\n", remainder);

    printf("\nThanks for using this program! Have a great day!\n");

    return 0;
}