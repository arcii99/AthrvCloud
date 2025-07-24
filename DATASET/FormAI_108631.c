//FormAI DATASET v1.0 Category: Educational ; Style: careful
#include <stdio.h>

// This program calculates the average of 5 numbers

int main() {

    int n1, n2, n3, n4, n5;
    float sum, average;

    printf("Enter the first number: ");
    scanf("%d", &n1);

    printf("Enter the second number: ");
    scanf("%d", &n2);

    printf("Enter the third number: ");
    scanf("%d", &n3);

    printf("Enter the fourth number: ");
    scanf("%d", &n4);

    printf("Enter the fifth number: ");
    scanf("%d", &n5);

    // calculating the sum
    sum = n1 + n2 + n3 + n4 + n5;

    // calculating the average
    average = sum / 5.0;

    // displaying the result
    printf("The average of %d, %d, %d, %d and %d is: %.2f", n1, n2, n3, n4, n5, average);

    return 0;
}