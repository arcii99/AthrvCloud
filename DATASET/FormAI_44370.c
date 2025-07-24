//FormAI DATASET v1.0 Category: Arithmetic ; Style: single-threaded
#include <stdio.h>

int main() {
    int num1, num2, result;
    
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    result = num1 + num2;
    printf("Addition: %d\n", result);
    
    result = num1 - num2;
    printf("Subtraction: %d\n", result);
    
    result = num1 * num2;
    printf("Multiplication: %d\n", result);
    
    if(num2 != 0) {
        result = num1 / num2;
        printf("Division: %d\n", result);
    } else {
        printf("Division by zero is not possible\n");
    }
    
    result = num1 % num2;
    printf("Modulus: %d\n", result);
    
    result = num1 << 2;
    printf("Left shift 2 bits: %d\n", result);
    
    result = num1 >> 1;
    printf("Right shift 1 bit: %d\n", result);
    
    result = ~num1;
    printf("One's complement of first number: %d\n", result);
    
    return 0;
}