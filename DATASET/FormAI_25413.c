//FormAI DATASET v1.0 Category: Bitwise operations ; Style: expert-level
#include <stdio.h>

int main() {
    unsigned int x, y;
    int n;

    printf("Enter two integers in decimal form:");
    scanf("%d %d", &x, &y);

    printf("Enter an integer n:");
    scanf("%d", &n);

    printf("Performing bitwise operations on x and y...\n\n");

    // Bitwise AND
    printf("Bitwise AND of x and y: %u\n", x & y);

    // Bitwise OR
    printf("Bitwise OR of x and y: %u\n", x | y);

    // Bitwise XOR
    printf("Bitwise XOR of x and y: %u\n", x ^ y);

    // Left shift
    printf("Left shift of x by n bits: %u\n", x << n);

    // Right shift
    printf("Right shift of x by n bits: %u\n", x >> n);

    // Bitwise complement
    printf("Bitwise complement of x: %u\n", ~x);

    return 0;
}