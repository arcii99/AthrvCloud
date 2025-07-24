//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Ada Lovelace
// PROGRAM NAME: BITWISE WONDER
// CREATED BY: (Your Name Here) in honor of Ada Lovelace
// DATE CREATED: (Date Here)
// DESCRIPTION: A program that demonstrates the power and versatility of C Bitwise Operations.

#include <stdio.h>

int main(){
    int num1, num2;
    
    printf("Welcome to Bitwise Wonder! This program showcases the beauty of C Bitwise Operations.\n");
    printf("Please enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("\n");
    
    // Bitwise AND Operation
    printf("Bitwise AND Operation:\n");
    printf("%d & %d = %d\n\n", num1, num2, num1 & num2);
    
    // Bitwise OR Operation
    printf("Bitwise OR Operation:\n");
    printf("%d | %d = %d\n\n", num1, num2, num1 | num2);
    
    // Bitwise XOR Operation
    printf("Bitwise XOR Operation:\n");
    printf("%d ^ %d = %d\n\n", num1, num2, num1 ^ num2);
    
    // Bitwise NOT Operation
    printf("Bitwise NOT Operation:\n");
    printf("~%d = %d\n", num1, ~num1);
    printf("~%d = %d\n\n", num2, ~num2);
    
    // Bitwise Left Shift and Right Shift Operations
    int shift = 2;
    printf("Bitwise Left Shift and Right Shift Operations (Shift value: %d)\n", shift);
    printf("%d << %d = %d\n", num1, shift, num1 << shift);
    printf("%d >> %d = %d\n\n", num2, shift, num2 >> shift);
    
    printf("Thank you for exploring the Bitwise Wonder program. Hope you enjoyed it!\n");
    
    return 0;
}