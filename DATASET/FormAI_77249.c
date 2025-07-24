//FormAI DATASET v1.0 Category: Binary Converter ; Style: systematic
#include <stdio.h>

int main() {
    int decimal = 0, binary = 0;
    int base = 1, remainder;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // Convert decimal to binary
    while (decimal > 0) {
        remainder = decimal % 2;
        binary += remainder * base;
        decimal /= 2;
        base *= 10;
    }

    printf("Binary representation: %d\n", binary);

    return 0;
}