//FormAI DATASET v1.0 Category: Arithmetic ; Style: enthusiastic
#include <stdio.h>

int main() {
    printf("Let's do some exciting arithmetic!\n");
    printf("Please enter two numbers:\n");

    int num1, num2;
    scanf("%d %d", &num1, &num2);

    int sum = num1 + num2;
    printf("%d + %d = %d\n", num1, num2, sum);

    int diff = num1 - num2;
    printf("%d - %d = %d\n", num1, num2, diff);

    int product = num1 * num2;
    printf("%d * %d = %d\n", num1, num2, product);

    if (num2 == 0) {
        printf("Cannot divide by 0.\n");
    }
    else {
        float quotient = (float) num1 / num2;
        printf("%d / %d = %.2f\n", num1, num2, quotient);
    }

    printf("Now let's find the squares of both numbers!\n");

    int square1 = num1 * num1;
    int square2 = num2 * num2;
    printf("%d squared is %d and %d squared is %d.\n", num1, square1, num2, square2);

    printf("Thanks for doing some fun math with me! Goodbye!\n");

    return 0;
}