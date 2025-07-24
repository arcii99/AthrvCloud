//FormAI DATASET v1.0 Category: Bitwise operations ; Style: complex
#include <stdio.h>

/* Function to print binary */
void binary(unsigned int x) {
    if (x > 1) {
        binary(x/2);
    }
    printf("%d", x%2);  
}

int main() {
    unsigned int num1 = 23; 
    unsigned int num2 = 13; 

    unsigned int bitwiseOR = num1 | num2; /* OR operation */
    printf("Bitwise OR result: %d (", bitwiseOR);
    binary(bitwiseOR);
    printf(")\n");

    unsigned int bitwiseAND = num1 & num2; /* AND operation */
    printf("Bitwise AND result: %d (", bitwiseAND);
    binary(bitwiseAND);
    printf(")\n");

    unsigned int bitwiseXOR = num1 ^ num2; /* XOR operation */
    printf("Bitwise XOR result: %d (", bitwiseXOR);
    binary(bitwiseXOR);
    printf(")\n");

    unsigned int bitwiseNOT = ~num1; /* NOT operation */
    printf("Bitwise NOT num1 result: %d (", bitwiseNOT);
    binary(bitwiseNOT);
    printf(")\n");

    unsigned int shiftLeft = num1 << 2; /* Left shift operation */
    printf("Bitwise Left Shift result: %d (", shiftLeft);
    binary(shiftLeft);
    printf(")\n");

    unsigned int shiftRight = num2 >> 1; /* Right shift operation */
    printf("Bitwise Right Shift result: %d (", shiftRight);
    binary(shiftRight);
    printf(")\n");

    return 0;
}