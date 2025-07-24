//FormAI DATASET v1.0 Category: Arithmetic ; Style: Dennis Ritchie
#include <stdio.h>

int main(void) {
    int num_one, num_two, sum, difference, product, quotient, remainder;

    printf("Enter two integers separated by a space: ");
    scanf("%d %d", &num_one, &num_two);

    sum = num_one + num_two;
    difference = num_one - num_two;
    product = num_one * num_two;
    quotient = num_one / num_two;
    remainder = num_one % num_two;

    printf("\nSum: %d\n", sum);
    printf("Difference: %d\n", difference);
    printf("Product: %d\n", product);
    printf("Quotient: %d\n", quotient);
    printf("Remainder: %d\n", remainder);

    if (num_one > num_two) {
        printf("%d is the largest number.\n", num_one);
    } else {
        printf("%d is the largest number.\n", num_two);
    }

    if (num_one % 2 == 0) {
        printf("%d is an even number.\n", num_one);
    } else {
        printf("%d is an odd number.\n", num_one);
    }

    if (num_two > 0) {
        printf("%d is a positive number.\n", num_two);
    } else if (num_two < 0) {
        printf("%d is a negative number.\n", num_two);
    } else {
        printf("%d is neither positive nor negative.\n", num_two);
    }

    return 0;
}