//FormAI DATASET v1.0 Category: Educational ; Style: inquisitive
#include <stdio.h>

// Function to check if a number is even or odd
void checkEvenOdd(int num){
    if(num % 2 == 0){
        printf("%d is even.\n", num);
    } else {
        printf("%d is odd.\n", num);
    }
}

int main(){
    // Declaring variables
    int num1, num2, sum, difference, product, quotient, remainder;

    // Taking input from user
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Performing arithmetic operations
    sum = num1 + num2;
    difference = num1 - num2;
    product = num1 * num2;
    quotient = num1 / num2;
    remainder = num1 % num2;

    // Printing the results
    printf("\nSum: %d\n", sum);
    printf("Difference: %d\n", difference);
    printf("Product: %d\n", product);
    printf("Quotient: %d\n", quotient);
    printf("Remainder: %d\n\n", remainder);

    // Checking if the first number is even or odd
    printf("Is the first number even or odd?\n");
    checkEvenOdd(num1);

    // Checking if the second number is even or odd
    printf("Is the second number even or odd?\n");
    checkEvenOdd(num2);

    return 0;
}