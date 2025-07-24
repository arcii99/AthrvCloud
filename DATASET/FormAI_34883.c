//FormAI DATASET v1.0 Category: Bitwise operations ; Style: brave
/* A brave example of C bitwise operations */
#include <stdio.h>

void print_binary(unsigned int num) {
    int binary[32];
    int index = 0;
    while (num > 0) {
        binary[index] = num % 2;
        num >>= 1;
        index++;
    }
    index--;
    while (index >= 0) {
        printf("%d", binary[index]);
        index--;
    }
}

int main() {
    unsigned int num1 = 5; // 101
    unsigned int num2 = 10; // 1010

    printf("num1: ");
    print_binary(num1);
    printf("\nnum2: ");
    print_binary(num2);

    // bitwise AND
    unsigned int result_and = num1 & num2; // 0010
    printf("\nnum1 & num2: ");
    print_binary(result_and);

    // bitwise OR
    unsigned int result_or = num1 | num2; // 1011
    printf("\nnum1 | num2: ");
    print_binary(result_or);

    // bitwise XOR
    unsigned int result_xor = num1 ^ num2; // 1001
    printf("\nnum1 ^ num2: ");
    print_binary(result_xor);

    // bitwise NOT
    printf("\n~num1: ");
    print_binary(~num1); // 11111111111111111111111111111010, due to two's complement

    // left shift
    printf("\nnum1 << 2: ");
    print_binary(num1 << 2); // 10100

    // right shift
    printf("\nnum2 >> 2: ");
    print_binary(num2 >> 2); // 10

    return 0;
}