//FormAI DATASET v1.0 Category: Bitwise operations ; Style: light-weight
#include <stdio.h>

int main()
{
    int x = 0b1010;     // binary representation of 10
    int y = 0b1100;     // binary representation of 12

    // bitwise AND: sets each bit to 1 if both bits are 1
    int and_res = x & y;
    printf("Bitwise AND of %d and %d is %d in decimal\n", x, y, and_res);

    // bitwise OR: sets each bit to 1 if any of the bits is 1
    int or_res = x | y;
    printf("Bitwise OR of %d and %d is %d in decimal\n", x, y, or_res);

    // bitwise XOR: sets each bit to 1 if only one of the bits is 1
    int xor_res = x ^ y;
    printf("Bitwise XOR of %d and %d is %d in decimal\n", x, y, xor_res);

    // bitwise NOT: flips the bits
    int not_res_x = ~x;
    printf("Bitwise NOT of %d is %d in decimal\n", x, not_res_x);

    int not_res_y = ~y;
    printf("Bitwise NOT of %d is %d in decimal\n", y, not_res_y);

    // left shift: shifts the bits to the left by a specified amount
    int left_shift_res = x << 2;
    printf("Left shift of %d by 2 is %d in decimal\n", x, left_shift_res);

    // right shift: shifts the bits to the right by a specified amount
    int right_shift_res = y >> 2;
    printf("Right shift of %d by 2 is %d in decimal\n", y, right_shift_res);

    // complement the binary data using bitwise XOR
    int complement_x = x ^ 0xFFFF;
    printf("Complement of %d is %d in decimal\n", x, complement_x);

    return 0;
}