//FormAI DATASET v1.0 Category: Bitwise operations ; Style: authentic
#include <stdio.h>

/* This program demonstrates a unique use of Bitwise Operators. The following program will 
   ask the user for two integers, manipulate them with bitwise operators, 
   and output both the original and manipulated results to the console */

int main() {
    int num1, num2;

    printf("Enter your first integer: ");
    scanf("%d", &num1);

    printf("Enter your second integer: ");
    scanf("%d", &num2);

    printf("\n----- Original numbers -----\n");
    printf("Number 1: %d\n", num1);
    printf("Number 2: %d\n", num2);

    // Bitwise AND
    int res_and = num1 & num2;
    printf("\n----- Bitwise AND (&) -----\n");
    printf("%d & %d = %d\n", num1, num2, res_and);

    // Bitwise OR
    int res_or = num1 | num2;
    printf("\n----- Bitwise OR (|) -----\n");
    printf("%d | %d = %d\n", num1, num2, res_or);

    // Bitwise XOR
    int res_xor = num1 ^ num2;
    printf("\n----- Bitwise XOR (^) -----\n");
    printf("%d ^ %d = %d\n", num1, num2, res_xor);

    // Bitwise Left Shift
    int res_shift_left = num1 << 1;
    printf("\n----- Bitwise Left Shift (<<) -----\n");
    printf("%d << 1 = %d\n", num1, res_shift_left);

    // Bitwise Right Shift
    int res_shift_right = num2 >> 1;
    printf("\n----- Bitwise Right Shift (>>) -----\n");
    printf("%d >> 1 = %d\n", num2, res_shift_right);

    return 0;
}