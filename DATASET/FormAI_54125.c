//FormAI DATASET v1.0 Category: Bitwise operations ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    srand(time(NULL));
    unsigned char num1 = rand() % 256;
    unsigned char num2 = rand() % 256;

    printf("num1: %d\n", num1);
    printf("num2: %d\n\n", num2);

    // Bitwise AND
    unsigned char result_and = num1 & num2;
    printf("num1 & num2: %d\n", result_and);

    // Bitwise OR
    unsigned char result_or = num1 | num2;
    printf("num1 | num2: %d\n", result_or);

    // Bitwise XOR
    unsigned char result_xor = num1 ^ num2;
    printf("num1 ^ num2: %d\n", result_xor);

    // Bitwise NOT
    unsigned char result_not1 = ~num1;
    unsigned char result_not2 = ~num2;
    printf("~num1: %d\n", result_not1);
    printf("~num2: %d\n\n", result_not2);

    // Bitwise LEFT SHIFT
    unsigned char result_lshift = num1 << 1;
    printf("num1 << 1: %d\n", result_lshift);

    // Bitwise RIGHT SHIFT
    unsigned char result_rshift = num2 >> 1;
    printf("num2 >> 1: %d\n", result_rshift);

    // Bitwise COMPLEMENT
    unsigned char result_comp = ~(num1 | num2);
    printf("complement of (num1 | num2): %d\n", result_comp);

    return 0;
}