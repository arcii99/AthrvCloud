//FormAI DATASET v1.0 Category: Arithmetic ; Style: systematic
#include <stdio.h>

int main() {
    int a = 10;
    int b = 5;
    int c = 20;
    int result1, result2, result3, result4;
    
    // Add two integers together
    result1 = a + b;
    printf("Addition result: %d\n", result1);
    
    // Subtract two integers
    result2 = a - b;
    printf("Subtraction result: %d\n", result2);
    
    // Multiply two integers
    result3 = a * b;
    printf("Multiplication result: %d\n", result3);
    
    // Divide two integers and calculate the remainder
    result4 = c / a;
    printf("Division result: %d\n", result4);
    printf("Remainder result: %d\n", (c % a));
    
    // Increment and decrement operators
    printf("a before increment: %d\n", a);
    printf("a after increment: %d\n", ++a);
    printf("a after decrement: %d\n", --a);
    
    // Comparison operators
    printf("Is a greater than b? %d\n", (a > b));
    printf("Is a less than or equal to c? %d\n", (a <= c));
    printf("Are a and b equal? %d\n", (a == b));
    
    // Logical operators
    printf("Is a greater than b AND a less than c? %d\n", (a > b && a < c));
    printf("Is a greater than b OR a less than c? %d\n", (a > b || a < c));
    printf("Is NOT(a greater than b)? %d\n", !(a > b));
    
    // Bitwise operators
    printf("AND result: %d\n", (a & b));
    printf("OR result: %d\n", (a | b));
    printf("XOR result: %d\n", (a ^ b));
    printf("Left shift result: %d\n", (a << 2));
    printf("Right shift result: %d\n", (a >> 2));
    
    return 0;
}