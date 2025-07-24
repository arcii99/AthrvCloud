//FormAI DATASET v1.0 Category: Bitwise operations ; Style: real-life
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Function to print binary representation of a number
void print_binary(uint8_t num) {
    for(int i=7; i>=0; i--){
        printf("%d", (num>>(i)) & 1);
    }
    printf(" ");
}

int main() {
    uint8_t a = 0b01101001; // 105
    uint8_t b = 0b01010110; // 86
    uint8_t c = 0b11111111; // 255

    // Printing the binary representation of the numbers
    printf("a = ");
    print_binary(a);
    printf("\n");

    printf("b = ");
    print_binary(b);
    printf("\n");

    printf("c = ");
    print_binary(c);
    printf("\n\n");

    // Performing bitwise AND operation
    uint8_t and_result = a & b;
    printf("a & b = ");
    print_binary(and_result);
    printf("\n");

    // Performing bitwise OR operation
    uint8_t or_result = a | b;
    printf("a | b = ");
    print_binary(or_result);
    printf("\n");

    // Performing bitwise XOR operation
    uint8_t xor_result = a ^ b;
    printf("a ^ b = ");
    print_binary(xor_result);
    printf("\n\n");

    // Performing bitwise NOT operation
    uint8_t not_result = ~a;
    printf("~a = ");
    print_binary(not_result);
    printf("\n");

    // Performing left shift operation
    uint8_t left_shift_result = b << 2;
    printf("b << 2 = ");
    print_binary(left_shift_result);
    printf("\n");

    // Performing right shift operation
    uint8_t right_shift_result = c >> 3;
    printf("c >> 3 = ");
    print_binary(right_shift_result);
    printf("\n");

    return 0;
}