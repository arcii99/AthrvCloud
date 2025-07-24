//FormAI DATASET v1.0 Category: Bitwise operations ; Style: statistical
#include <stdio.h>

int main() {
    printf("Welcome to the Bitwise Operations Program!\n");
    printf("This program takes two numbers and performs bitwise operations on them.\n\n");
    
    int num1, num2;
    printf("Please enter the first number: ");
    scanf("%d", &num1);
    printf("Please enter the second number: ");
    scanf("%d", &num2);
    
    int andResult = num1 & num2;
    printf("\nBitwise AND Operation:\n");
    printf("%d & %d = %d\n\n", num1, num2, andResult);
    
    int orResult = num1 | num2;
    printf("Bitwise OR Operation:\n");
    printf("%d | %d = %d\n\n", num1, num2, orResult);
    
    int xorResult = num1 ^ num2;
    printf("Bitwise XOR Operation:\n");
    printf("%d ^ %d = %d\n\n", num1, num2, xorResult);
    
    int leftShiftResult = num1 << 2;
    printf("Bitwise Left Shift Operation:\n");
    printf("%d << 2 = %d\n\n", num1, leftShiftResult);
    
    int rightShiftResult = num2 >> 3;
    printf("Bitwise Right Shift Operation:\n");
    printf("%d >> 3 = %d\n\n", num2, rightShiftResult);
    
    int onesComplementResult1 = ~num1;
    printf("Ones Complement Operation on First Number:\n");
    printf("~%d = %d\n\n", num1, onesComplementResult1);
    
    int onesComplementResult2 = ~num2;
    printf("Ones Complement Operation on Second Number:\n");
    printf("~%d = %d\n\n", num2, onesComplementResult2);
    
    printf("Thanks for using the Bitwise Operations Program! Goodbye!\n");
    
    return 0;
}