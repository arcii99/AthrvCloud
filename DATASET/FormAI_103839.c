//FormAI DATASET v1.0 Category: Scientific ; Style: excited
#include <stdio.h>

int main() {
    int num1, num2, sum;

    printf("Welcome to the Adder Program!\n\n");

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    sum = num1 + num2;

    printf("\n*** Calculating the sum ***\n\n");
    printf("The sum of %d and %d is %d!\n", num1, num2, sum);

    if (sum > 100) {
        printf("\nWOW! That's a BIG number!!\n");
    } else if (sum > 50) {
        printf("\nGreat! That's a decent number!\n");
    } else if (sum > 25) {
        printf("\nNot bad, but you can do better!\n");
    } else {
        printf("\nHmm...maybe try picking bigger numbers?\n");
    }

    printf("\nThanks for using the Adder Program! :D\n");

    return 0;
}