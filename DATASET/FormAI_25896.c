//FormAI DATASET v1.0 Category: Arithmetic ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2;

    // Generate random numbers for num1 and num2 between 1 to 10
    srand(time(NULL));
    num1 = rand() % 10 + 1;
    num2 = rand() % 10 + 1;

    printf("Hey there! Let's do some arithmetic!\n");
    printf("I have two numbers for you: %d and %d\n", num1, num2);

    int sum = num1 + num2;
    int difference = num1 - num2;
    int product = num1 * num2;
    float quotient = (float) num1 / num2;
    int remainder = num1 % num2;

    printf("Here are the results:\n");
    printf("%d + %d = %d\n", num1, num2, sum);
    printf("%d - %d = %d\n", num1, num2, difference);
    printf("%d * %d = %d\n", num1, num2, product);
    printf("%d / %d = %.2f\n", num1, num2, quotient);
    printf("%d %% %d = %d\n", num1, num2, remainder);

    printf("I hope you had fun! Don't forget to try it again!\n");

    return 0;
}