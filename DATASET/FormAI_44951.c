//FormAI DATASET v1.0 Category: Bitwise operations ; Style: happy
#include <stdio.h>

int main() {
    printf("Hello there! Let's do some bitwise operations today!\n");
    printf("I am feeling happy because this is such a fun topic!\n");

    // Let's start by declaring some variables for our bitwise operations
    unsigned int x = 18;   // equivalent to binary 10010
    unsigned int y = 25;   // equivalent to binary 11001
    unsigned int result;

    // AND (&) operation example
    result = x & y;     // bitwise AND of x and y
    printf("\nBitwise AND of %d and %d is %d\n", x, y, result);

    // OR (|) operation example
    result = x | y;     // bitwise OR of x and y
    printf("\nBitwise OR of %d and %d is %d\n", x, y, result);

    // XOR (^) operation example
    result = x ^ y;     // bitwise XOR of x and y
    printf("\nBitwise XOR of %d and %d is %d\n", x, y, result);

    // NOT (~) operation example
    result = ~x;        // bitwise NOT of x
    printf("\nBitwise NOT of %d is %d\n", x, result);

    // left shift (<<) operation example
    result = x << 2;    // left shift x by 2 positions
    printf("\nLeft shift of %d by 2 positions is %d\n", x, result);

    // right shift (>>) operation example
    result = y >> 2;    // right shift y by 2 positions
    printf("\nRight shift of %d by 2 positions is %d\n", y, result);

    printf("\nYay! We got it all done with the bitwise operations. Let's do more in the future!\n");

    return 0;
}