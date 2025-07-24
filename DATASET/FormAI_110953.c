//FormAI DATASET v1.0 Category: Bitwise operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Let's get bitwise, baby!\n");

    int x = 10; // Binary value of 10 is 1010
    int y = 12; // Binary value of 12 is 1100

    printf("The value of x is: %d\n", x);
    printf("The value of y is: %d\n", y);

    int bitwiseAnd = x & y; // Binary value of 8 is 1000
    printf("The result of x & y is: %d\n", bitwiseAnd);

    int bitwiseOr = x | y; // Binary value of 14 is 1110
    printf("The result of x | y is: %d\n", bitwiseOr);

    int bitwiseXor = x ^ y; // Binary value of 6 is 0110
    printf("The result of x ^ y is: %d\n", bitwiseXor);

    int bitwiseNot = ~x; // Binary value of -11 is 11110101
    printf("The result of ~x is: %d\n", bitwiseNot);

    int leftShifted = x << 2; // Binary value of 40 is 101000
    printf("The result of x << 2 is: %d\n", leftShifted);

    int rightShifted = y >> 2; // Binary value of 3 is 0011
    printf("The result of y >> 2 is: %d\n", rightShifted);

    printf("Now let's have some fun, let me show you some tricks!\n");

    int numberOfBitsToShift = 3;

    int shiftedBits = x << numberOfBitsToShift; // Binary value of 80 is 1010000
    printf("The value of x shifted by %d bits is %d\n", numberOfBitsToShift, shiftedBits);

    int maskedValue = x & ~(1 << numberOfBitsToShift - 1); // Binary value of 2 is 10
    printf("The value of x with the %dth bit cleared is %d\n", numberOfBitsToShift, maskedValue);

    int toggledValue = y ^ (1 << numberOfBitsToShift - 1); // Binary value of 4 is 100
    printf("The value of y with the %dth bit toggled is %d\n", numberOfBitsToShift, toggledValue);

    printf("Thanks for playing, bye bye!\n");

    return 0;
}