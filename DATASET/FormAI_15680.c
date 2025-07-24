//FormAI DATASET v1.0 Category: Arithmetic ; Style: introspective
#include <stdio.h>

/* This program performs arithmetic operations on two numbers entered by the user. 
   It also displays the maximum and minimum of the two numbers. */

int main() {

    // Declarations
    int a, b, sum, difference, product, quotient, remainder, max, min; 
    
    // Accepting input from user
    printf("Please enter two integers: ");
    scanf("%d%d", &a, &b); 
    
    // Performing arithmetic operations
    sum = a + b;
    difference = a - b;
    product = a * b;
    quotient = a / b;
    remainder = a % b;
    
    // Displaying the results
    printf("The sum of %d and %d is %d\n", a, b, sum);
    printf("The difference between %d and %d is %d\n", a, b, difference);
    printf("The product of %d and %d is %d\n", a, b, product);
    printf("The quotient of %d divided by %d is %d with remainder %d\n", a, b, quotient, remainder);
    
    // Finding the maximum and minimum of the two numbers
    max = (a > b) ? a : b;
    min = (a < b) ? a : b;
    
    printf("The maximum of %d and %d is %d\n", a, b, max);
    printf("The minimum of %d and %d is %d\n", a, b, min);
    
    return 0;
}