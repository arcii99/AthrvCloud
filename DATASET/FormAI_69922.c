//FormAI DATASET v1.0 Category: Bitwise operations ; Style: happy
#include <stdio.h>

void happyBitwiseOp(int num1, int num2) {
    int bitwiseAnd = num1 & num2;
    int bitwiseOr = num1 | num2;
    int bitwiseXor = num1 ^ num2;
    int bitwiseRightShift = num1 >> 1;
    int bitwiseLeftShift = num1 << 1;
    int bitwiseComplement = ~num1;
    
    printf("I am so happy to showcase the power of Bitwise Operations!\n\n");
    
    printf("Let's start with two happy numbers: %d and %d\n\n", num1, num2);
    
    printf("Here's the result of a happy Bitwise AND operation: %d & %d = %d\n", num1, num2, bitwiseAnd);
    printf("This means only the happy bits that are set in both numbers are kept: %d & %d = %d\n\n", num1, num2, bitwiseAnd);
    
    printf("Now, let's try a happy Bitwise OR operation: %d | %d = %d\n", num1, num2, bitwiseOr);
    printf("This means all the happy bits that are set in either number are kept: %d | %d = %d\n\n", num1, num2, bitwiseOr);
    
    printf("Let's move on to a happy Bitwise XOR operation: %d ^ %d = %d\n", num1, num2, bitwiseXor);
    printf("This means only the happy bits that are set in one number or the other are kept, but not both: %d ^ %d = %d\n\n", num1, num2, bitwiseXor);
    
    printf("Now, let's try a happy Bitwise Right Shift operation: %d >> %d = %d\n", num1, 1, bitwiseRightShift);
    printf("This means we shift all the happy bits in %d to the right by %d positions: %d >> %d = %d\n\n", num1, 1, num1, 1, bitwiseRightShift);
    
    printf("Let's move on to a happy Bitwise Left Shift operation: %d << %d = %d\n", num1, 1, bitwiseLeftShift);
    printf("This means we shift all the happy bits in %d to the left by %d positions: %d << %d = %d\n\n", num1, 1, num1, 1, bitwiseLeftShift);
    
    printf("Finally, let's try a happy Bitwise Complement operation: ~%d = %d\n", num1, bitwiseComplement);
    printf("This means we flip all the happy bits in %d that are currently set to 1 to become 0, and vice versa: ~%d = %d\n\n", num1, num1, bitwiseComplement);
    
    printf("Now, wasn't that a bunch of happy bitwise operations? I hope you learned something new today!\n");
}

int main() {
    int num1 = 42;
    int num2 = 99;
    
    happyBitwiseOp(num1, num2);
    
    return 0;
}