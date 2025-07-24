//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mathematical
#include <stdio.h>

int main() {
    int a = 10;
    int b = 5;
    int result;

    // bitwise AND
    result = a & b;
    printf("The result of bitwise AND is: %d\n", result);

    // bitwise OR
    result = a | b;
    printf("The result of bitwise OR is: %d\n", result);

    // bitwise XOR
    result = a ^ b;
    printf("The result of bitwise XOR is: %d\n", result);

    // bitwise NOT
    result = ~a;
    printf("The result of bitwise NOT is: %d\n", result);

    // left shift
    result = a << 1;
    printf("The result of left shift is: %d\n", result);

    // right shift
    result = a >> 1;
    printf("The result of right shift is: %d\n", result);

    return 0;
}