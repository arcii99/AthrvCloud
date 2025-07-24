//FormAI DATASET v1.0 Category: Bitwise operations ; Style: statistical
#include <stdio.h>

// Function to count the number of set bits in binary representation of a number
int countSetBits(unsigned int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

void bitwiseOperations(int a, int b) {
    printf("The bitwise AND of %d and %d is %d\n", a, b, a & b);
    printf("The bitwise OR of %d and %d is %d\n", a, b, a | b);
    printf("The bitwise XOR of %d and %d is %d\n", a, b, a ^ b);
    printf("The bitwise NOT of %d is %d\n", a, ~a);
    printf("The bitwise left shift of %d by 2 bits is %d\n", a, a << 2);
    printf("The bitwise right shift of %d by 2 bits is %d\n", a, a >> 2);
    printf("The number of set bits in binary representation of %d is %d", a, countSetBits(a));
}

int main() {
    int a = 10;
    int b = 5;
    bitwiseOperations(a, b);
    return 0;
}