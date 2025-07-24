//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Linus Torvalds
#include <stdio.h>

#define BIT(x) (1 << (x))

#define BITMASK(x) (((unsigned int) ~(~0U << x)))

/* Example function to implement the AND operation */
unsigned int bitwise_and(unsigned int a, unsigned int b) {
    return a & b;
}

/* Example function to implement the OR operation */
unsigned int bitwise_or(unsigned int a, unsigned int b) {
    return a | b;
}

/* Example function to implement the XOR operation */
unsigned int bitwise_xor(unsigned int a, unsigned int b) {
    return a ^ b;
}

/* Example function to implement the NOT operation */
unsigned int bitwise_not(unsigned int a) {
    return ~a;
}

/* Example function to implement the SHIFT LEFT operation */
unsigned int shift_left(unsigned int a, unsigned int shift) {
    return a << shift;
}

/* Example function to implement the SHIFT RIGHT operation */
unsigned int shift_right(unsigned int a, unsigned int shift) {
    return a >> shift;
}

/* Example function to implement the COMPLEMENT operation */
void complement(unsigned int* a) {
    *a = ~(*a);
}

unsigned int extract_bits(unsigned int num, unsigned int start_bit, unsigned int num_bits) {
    unsigned int mask = BITMASK(num_bits);
    return (num >> start_bit) & mask;
}

int main() {
    unsigned int a = 0x12;
    unsigned int b = 0x34;

    printf("a = 0x%08x\n", a);
    printf("b = 0x%08x\n", b);

    unsigned int and_result = bitwise_and(a, b);
    printf("a & b = 0x%08x\n", and_result);

    unsigned int or_result = bitwise_or(a, b);
    printf("a | b = 0x%08x\n", or_result);

    unsigned int xor_result = bitwise_xor(a, b);
    printf("a ^ b = 0x%08x\n", xor_result);

    unsigned int not_result = bitwise_not(a);
    printf("~a = 0x%08x\n", not_result);

    unsigned int shift_left_result = shift_left(a, 4);
    printf("a << 4 = 0x%08x\n", shift_left_result);

    unsigned int shift_right_result = shift_right(b, 3);
    printf("b >> 3 = 0x%08x\n", shift_right_result);

    printf("bits 3-6 of a = 0x%08x\n", extract_bits(a, 3, 4));

    complement(&a);
    printf("a after complement = 0x%08x\n", a);

    return 0;
}