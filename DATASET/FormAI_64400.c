//FormAI DATASET v1.0 Category: Math exercise ; Style: enthusiastic
#include <stdio.h>

int main() {
    printf("Are you ready to exercise your brain with some math?!\n");

    int num1, num2, num3, sum, average, product, maximum, minimum;

    printf("Enter three integer numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    // finding the sum of the three numbers
    sum = num1 + num2 + num3;
    printf("\nThe sum of the three numbers is: %d\n", sum);

    // finding the average of the three numbers
    average = sum / 3;
    printf("The average of the three numbers is: %d\n", average);

    // finding the product of the three numbers
    product = num1 * num2 * num3;
    printf("The product of the three numbers is: %d\n", product);

    // finding the maximum number
    maximum = num1;
    if (num2 > maximum) {
        maximum = num2;
    }
    if (num3 > maximum) {
        maximum = num3;
    }
    printf("The maximum number is: %d\n", maximum);

    // finding the minimum number
    minimum = num1;
    if (num2 < minimum) {
        minimum = num2;
    }
    if (num3 < minimum) {
        minimum = num3;
    }
    printf("The minimum number is: %d\n", minimum);

    printf("\nCongratulations! You have completed the exercise!\n");

    return 0;
}