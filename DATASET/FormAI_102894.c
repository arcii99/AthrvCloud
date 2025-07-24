//FormAI DATASET v1.0 Category: Bitwise operations ; Style: statistical
#include <stdio.h>

// This program demonstrates the use of bitwise operations in statistics

int main() {

    int a = 8;
    int b = 10;

    printf("The original values of a and b are %d and %d respectively.\n\n", a, b);

    // bitwise AND operation to find the minimum value of a and b
    int min = (a & b);

    printf("The minimum value of a and b using bitwise AND is %d.\n\n", min);

    // bitwise OR operation to find the maximum value of a and b
    int max = (a | b);

    printf("The maximum value of a and b using bitwise OR is %d.\n\n", max);

    // bitwise XOR operation to count the number of different bits in a and b
    int xor = (a ^ b);

    int count = 0;

    // count the number of set bits in xor using bitwise AND and right shift operations
    while (xor != 0) {
        if (xor & 1) {
            count++;
        }
        xor >>= 1;
    }

    printf("The number of different bits between a and b using bitwise XOR is %d.\n\n", count);

    return 0;
}