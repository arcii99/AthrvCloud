//FormAI DATASET v1.0 Category: Binary Converter ; Style: puzzling
#include <stdio.h>

int main() {
    int num, bin, base = 1, rem;
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    bin = 0;
    while (num > 0) {
        rem = num % 2;
        bin = bin + rem * base;
        num = num / 2;
        base = base * 10;
    }

    printf("The binary equivalent of %d is %d\n", num, bin);

    return 0;
}