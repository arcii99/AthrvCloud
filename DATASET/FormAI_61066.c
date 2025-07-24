//FormAI DATASET v1.0 Category: Arithmetic ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int num1, num2, sum, difference, product, quotient;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    // Addition
    sum = num1 + num2;
    
    // Subtraction
    difference = num1 - num2;
    
    // Multiplication
    product = num1 * num2;
    
    // Division
    quotient = num1 / num2;
    
    printf("\nSUM: %d\nDIFFERENCE: %d\nPRODUCT: %d\nQUOTIENT: %d\n", sum, difference, product, quotient);

    return 0;
}