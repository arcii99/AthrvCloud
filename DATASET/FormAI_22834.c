//FormAI DATASET v1.0 Category: Arithmetic ; Style: expert-level
#include <stdio.h>

int main() {
    // Declare variables for input
    int a, b;

    // Declare variables for calculations
    int sum, difference, product;
    float quotient;

    // Get inputs from user
    printf("Enter value of a: ");
    scanf("%d", &a);
    printf("Enter value of b: ");
    scanf("%d", &b);

    // Perform arithmetic operations
    sum = a + b;
    difference = a - b;
    product = a * b;
    quotient = (float)a / (float)b;

    // Display the result
    printf("Sum of %d and %d is %d\n", a, b, sum);
    printf("Difference between %d and %d is %d\n", a, b, difference);
    printf("Product of %d and %d is %d\n", a, b, product);
    printf("Quotient of %d and %d is %.2f\n", a, b, quotient);

    // Perform additional operations
    int remainder = a % b;
    printf("Remainder of %d divided by %d is %d\n", a, b, remainder);

    // Use ternary operator to check if a is even or odd
    printf("%d is %s\n", a, (a % 2 == 0) ? "even" : "odd");

    return 0;
}