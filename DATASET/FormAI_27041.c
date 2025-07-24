//FormAI DATASET v1.0 Category: Arithmetic ; Style: peaceful
/* 
A Calm Arithmetic Calculation Program
By: [Your Name]

This program takes two user-input float values and performs basic arithmetic operations on them. The answers are displayed on the screen in a peaceful tone.

*/

#include <stdio.h>

int main() {

    float num1, num2, sum, difference, product, quotient;

    printf("Please enter the first number: ");
    scanf("%f", &num1);

    printf("Please enter the second number: ");
    scanf("%f", &num2);

    // Addition
    sum = num1 + num2;
    printf("The sum of %.2f and %.2f is %.2f. This is a harmonious result.\n", num1, num2, sum);

    // Subtraction
    difference = num1 - num2;
    printf("The difference between %.2f and %.2f is %.2f. This is a peaceful result.\n", num1, num2, difference);

    // Multiplication
    product = num1 * num2;
    printf("The product of %.2f and %.2f is %.2f. This is a tranquil result.\n", num1, num2, product);

    // Division
    if(num2 != 0) {
        quotient = num1 / num2;
        printf("The quotient of %.2f and %.2f is %.2f. This is a serene result.\n", num1, num2, quotient);
    } 
    else {
        printf("Error: You cannot divide by 0. This is not a peaceful action.\n");
    }

    return 0;
}