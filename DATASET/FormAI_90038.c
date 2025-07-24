//FormAI DATASET v1.0 Category: Arithmetic ; Style: genious
#include <stdio.h>

// define a struct to hold the result of arithmetic operations
typedef struct {
    int sum;
    int difference;
    int product;
    double quotient;
} ArithmeticResult;

// function to perform arithmetic operations on two numbers
ArithmeticResult calculate(int a, int b) {
    ArithmeticResult result;
    result.sum = a + b;
    result.difference = a - b;
    result.product = a * b;
    result.quotient = (double)a / (double)b;
    return result;
}

int main() {
    int firstNum, secondNum;
    printf("Welcome to the Genius Arithmetic Program!\n");
    printf("Please enter two numbers: ");
    scanf("%d %d", &firstNum, &secondNum);

    // call the calculate function and store the result in a variable
    ArithmeticResult result = calculate(firstNum, secondNum);

    printf("\nCalculating...\n\n");
    printf("The sum of %d and %d is: %d\n", firstNum, secondNum, result.sum);
    printf("The difference between %d and %d is: %d\n", firstNum, secondNum, result.difference);
    printf("The product of %d and %d is: %d\n", firstNum, secondNum, result.product);
    printf("The quotient of %d and %d is: %.2lf\n", firstNum, secondNum, result.quotient);

    printf("\nThank you for using the Genius Arithmetic Program!\n");
    return 0;
}