//FormAI DATASET v1.0 Category: Binary Converter ; Style: minimalist
#include <stdio.h>

int main() {
    unsigned int num, mask, i, num_bits;

    /* Input a number from user */
    printf("Enter any number: ");
    scanf("%u", &num);

    /* Find number of bits in the given number */
    num_bits = sizeof(num) * 8;

    /* Set the highest bit of mask to 1 */
    mask = (unsigned int) 1 << (num_bits - 1);

    /* Print binary representation of num */
    printf("Binary representation of %u is: ", num);

    for(i=1; i<=num_bits; i++) {
        putchar(num & mask ? '1' : '0');
        num <<= 1;
        if(i%8 == 0) {
            putchar(' ');
        }
    }

    return 0;
}