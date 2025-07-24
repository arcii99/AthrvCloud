//FormAI DATASET v1.0 Category: Bitwise operations ; Style: light-weight
#include <stdio.h>
#include <stdint.h>

// define a function to display binary digits of a number
void displayBinary(uint8_t num) {
    for(int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

int main() {
    // declare two 8-bit integers a and b
    uint8_t a = 0b10101010;
    uint8_t b = 0b01010101;
    
    // perform bitwise AND operation
    uint8_t result_and = a & b;
    printf("Bitwise AND: a & b = ");
    displayBinary(result_and);
    printf("\n");
    
    // perform bitwise OR operation
    uint8_t result_or = a | b;
    printf("Bitwise OR: a | b = ");
    displayBinary(result_or);
    printf("\n");
    
    // perform bitwise XOR operation
    uint8_t result_xor = a ^ b;
    printf("Bitwise XOR: a ^ b = ");
    displayBinary(result_xor);
    printf("\n");
    
    // perform bitwise NOT operation
    uint8_t result_not = ~a;
    printf("Bitwise NOT: ~a = ");
    displayBinary(result_not);
    printf("\n");
    
    // perform left shift operation
    uint8_t result_left_shift = a << 2;
    printf("Left Shift: a << 2 = ");
    displayBinary(result_left_shift);
    printf("\n");
    
    // perform right shift operation
    uint8_t result_right_shift = a >> 3;
    printf("Right Shift: a >> 3 = ");
    displayBinary(result_right_shift);
    printf("\n");
    
    return 0;
}