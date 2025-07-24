//FormAI DATASET v1.0 Category: Educational ; Style: multivariable
#include<stdio.h>

// function to calculate sum of 3 numbers
int sum(int a, int b, int c) {
    return a + b + c;
}

// function to calculate average of 3 numbers
float average(int a, int b, int c) {
    int sum_of_numbers = sum(a, b, c);
    return (float) sum_of_numbers / 3.0;
}

// function to calculate product of 3 numbers
int product(int a, int b, int c) {
    return a * b * c;
}

int main() {
    int num1, num2, num3;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    printf("Sum of %d, %d and %d is: %d\n", num1, num2, num3, sum(num1, num2, num3));
    printf("Average of %d, %d and %d is: %.2f\n", num1, num2, num3, average(num1, num2, num3));
    printf("Product of %d, %d and %d is: %d\n", num1, num2, num3, product(num1, num2, num3));

    return 0;
}