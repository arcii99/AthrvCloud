//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mind-bending
#include <stdio.h>

#define MIND_BENDING(X) ((X << 3) ^ ~(X | 3)) & 0xFF

int main() {

    int num = 69;
    printf("Original Number: %d\n", num);

    int mind_bending_num = MIND_BENDING(num);
    printf("Mind-bending Number: %d\n", mind_bending_num);

    // Let's do some bitwise operations on the mind-bending number
    int left_shifted_num = mind_bending_num << 2;
    printf("Left Shifted Number: %d\n", left_shifted_num);

    int right_shifted_num = mind_bending_num >> 2;
    printf("Right Shifted Number: %d\n", right_shifted_num);

    int flipped_bits_num = ~mind_bending_num;
    printf("Flipped Bits Number: %d\n", flipped_bits_num);

    int anded_num = mind_bending_num & 0b110011;
    printf("Anded Number: %d\n", anded_num);

    int ored_num = mind_bending_num | 0b001100;
    printf("Ored Number: %d\n", ored_num);

    int xored_num = mind_bending_num ^ 0b101010;
    printf("Xored Number: %d\n", xored_num);

    return 0;
}