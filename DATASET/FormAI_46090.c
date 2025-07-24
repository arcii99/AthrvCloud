//FormAI DATASET v1.0 Category: Arithmetic ; Style: visionary
#include <stdio.h>

int main() {
    int num1 = 10;
    int num2 = 20;
    
    /* Add two numbers */
    int sum = num1 + num2;
    
    /* Subtract two numbers */
    int diff = num1 - num2;
    
    /* Multiply two numbers */
    int product = num1 * num2;
    
    /* Divide two numbers */
    int quotient = num1 / num2;
    
    /* Modulus of two numbers */
    int remainder = num1 % num2;
    
    /* Negation of a number */
    int neg_num = -num1;
    
    /* Square of a number */
    int square = num1 * num1;
    
    /* Cube of a number */
    int cube = num1 * num1 * num1;
    
    /* Absolute value of a number */
    int abs_num = abs(neg_num);
    
    printf("The sum of %d and %d is %d.\n", num1, num2, sum);
    printf("The difference between %d and %d is %d.\n", num1, num2, diff);
    printf("The product of %d and %d is %d.\n", num1, num2, product);
    printf("The quotient of %d and %d is %d.\n", num1, num2, quotient);
    printf("The remainder of %d divided by %d is %d.\n", num1, num2, remainder);
    printf("The negation of %d is %d.\n", num1, neg_num);
    printf("The square of %d is %d.\n", num1, square);
    printf("The cube of %d is %d.\n", num1, cube);
    printf("The absolute value of %d is %d.\n", neg_num, abs_num);

    return 0;
}