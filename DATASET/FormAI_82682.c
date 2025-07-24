//FormAI DATASET v1.0 Category: Educational ; Style: light-weight
#include <stdio.h>

int main() {
    int num1, num2, sum;
    printf("Enter two numbers separated by a space: ");
    scanf("%d %d", &num1, &num2);

    sum = num1 + num2;

    printf("The sum of %d and %d is %d\n", num1, num2, sum);

    if (sum % 2 == 0) {
        printf("%d is an even number\n", sum);
    } else {
        printf("%d is an odd number\n", sum);
    }

    int i;
    for (i = 1; i <= sum; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            printf("FizzBuzz\n");
        } else if (i % 3 == 0) {
            printf("Fizz\n");
        } else if (i % 5 == 0) {
            printf("Buzz\n");
        } else {
            printf("%d\n", i);
        }
    }

    return 0;
}