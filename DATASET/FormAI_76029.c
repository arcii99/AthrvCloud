//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Linus Torvalds
/* 
   Linux-style C code demonstrating bitwise operations.
   Author: Chatbot (inspired by Linus Torvalds)
*/

#include <stdio.h>

#define BIT_0 (1 << 0)
#define BIT_1 (1 << 1)
#define BIT_2 (1 << 2)
#define BIT_3 (1 << 3)
#define BIT_4 (1 << 4)
#define BIT_5 (1 << 5)
#define BIT_6 (1 << 6)
#define BIT_7 (1 << 7)

void print_binary(unsigned char val) {
    int i;
    for (i = 7; i >= 0; i--) {
        if (val & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
}

int main() {
    unsigned char b1 = BIT_0 | BIT_2 | BIT_6;     // 01000101
    unsigned char b2 = BIT_1 | BIT_4 | BIT_7;     // 10010010
    unsigned char b3;

    printf("b1:\t"); print_binary(b1); printf("\n");
    printf("b2:\t"); print_binary(b2); printf("\n");

    /* Bitwise AND */
    b3 = b1 & b2;                                 // 00000000
    printf("b1&b2:\t"); print_binary(b3); printf("\n");

    /* Bitwise OR */
    b3 = b1 | b2;                                 // 11010111
    printf("b1|b2:\t"); print_binary(b3); printf("\n");

    /* Bitwise XOR */
    b3 = b1 ^ b2;                                 // 11010111
    printf("b1^b2:\t"); print_binary(b3); printf("\n");

    /* Bitwise NOT */
    b3 = ~b1;                                     // 10111010
    printf("~b1:\t"); print_binary(b3); printf("\n");

    /* Bit shift */
    b3 = b1 << 2;                                 // 00010100
    printf("b1<<2:\t"); print_binary(b3); printf("\n");

    return 0;
}