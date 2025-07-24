//FormAI DATASET v1.0 Category: Arithmetic ; Style: sophisticated
#include <stdio.h>

int main() {
    int num1, num2, sum, subtract, multiply; //declare variables
    float divide; 

    printf("Please enter the first integer: "); //get input from user
    scanf("%d", &num1);

    printf("Please enter the second integer: ");
    scanf("%d", &num2);

    sum = num1 + num2; //perform arithmetic operations
    subtract = num1 - num2;
    multiply = num1 * num2;
    divide = (float)num1 / num2;

    printf("\nSUM of %d and %d is: %d\n", num1, num2, sum); //display results
    printf("DIFFERENCE between %d and %d is: %d\n", num1, num2, subtract);
    printf("PRODUCT of %d and %d is: %d\n", num1, num2, multiply);
    printf("QUOTIENT of %d and %d is: %.2f\n", num1, num2, divide);

    return 0; // exit program
}