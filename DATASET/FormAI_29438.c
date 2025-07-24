//FormAI DATASET v1.0 Category: Arithmetic ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This program generates a random arithmetic expression and
 * evaluates the result with floating-point precision.
 */

int main() {
    srand(time(NULL));  // seed random number generator
    
    // randomly generate operands and operators
    float num1 = rand() % 100 + 1;
    float num2 = rand() % 100 + 1;
    char op1 = '+', op2 = '-', op3 = '*', op4 = '/';
    char rand_op1 = rand() % 4 == 0 ? op1 : rand() % 4 == 1 ? op2 : rand() % 4 == 2 ? op3 : op4;
    char rand_op2 = rand() % 4 == 0 ? op1 : rand() % 4 == 1 ? op2 : rand() % 4 == 2 ? op3 : op4;
    
    // perform arithmetic operations with precedence
    float result;
    if (rand_op1 == '*' || rand_op1 == '/') {
        result = rand_op1 == '*' ? num1 * num2 : num1 / num2;
        num1 = result;  // update num1 with result for next operation
        num2 = rand() % 100 + 1;  // generate new num2 for next operation
    }
    if (rand_op2 == '+' || rand_op2 == '-') {
        result = rand_op2 == '+' ? num1 + num2 : num1 - num2;
    } else {
        result = rand_op2 == '*' ? num1 * num2 : num1 / num2;
    }
    
    // print results
    printf("The arithmetic expression is: %.2f %c %.2f %c %.2f\n", num1, rand_op1, num2, rand_op2, result);
    printf("The result is: %.2f\n", result);
    
    return 0;
}