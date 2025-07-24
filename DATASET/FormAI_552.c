//FormAI DATASET v1.0 Category: Bitwise operations ; Style: satisfied
#include <stdio.h>

int main()
{
    int a = 10; // 1010 in binary
    int b = 7; // 0111 in binary

    // Bitwise AND operation
    int andResult = a & b; // 0010 in binary
    printf("a & b = %d\n", andResult);

    // Bitwise OR operation
    int orResult = a | b; // 1111 in binary
    printf("a | b = %d\n", orResult);

    // Bitwise XOR operation
    int xorResult = a ^ b; // 1101 in binary
    printf("a ^ b = %d\n", xorResult);

    // Bitwise NOT operation
    int notResult = ~a; // 0101 in binary
    printf("~a = %d\n", notResult);

    // Bitwise left shift operation
    int leftResult = a << 2; // 101000 in binary
    printf("a << 2 = %d\n", leftResult);

    // Bitwise right shift operation
    int rightResult = a >> 2; // 0010 in binary
    printf("a >> 2 = %d\n", rightResult);

    return 0;
}