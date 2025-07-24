//FormAI DATASET v1.0 Category: Binary Converter ; Style: realistic
#include <stdio.h>

int main() {
    int decimal, remainder, binary = 0, base = 1;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    while (decimal != 0) {
        remainder = decimal % 2;
        decimal /= 2;
        binary += remainder * base;
        base *= 10;
    }

    printf("The binary equivalent is %d\n", binary);

    return 0;
}