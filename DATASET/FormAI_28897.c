//FormAI DATASET v1.0 Category: Bitwise operations ; Style: grateful
#include <stdio.h>

int main() {
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    // Bitwise AND with 10
    printf("Bitwise AND with 10: %d\n", num & 10);

    // Bitwise OR with 5
    printf("Bitwise OR with 5: %d\n", num | 5);

    // Bitwise XOR with 3
    printf("Bitwise XOR with 3: %d\n", num ^ 3);

    // Left shift by 2 bits
    printf("Left shift by 2 bits: %d\n", num << 2);

    // Right shift by 3 bits
    printf("Right shift by 3 bits: %d\n", num >> 3);

    return 0;
}