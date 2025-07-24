//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Ken Thompson
#include <stdio.h>

int main() {
    int hex_num, dec_num = 0, base = 1, rem;

    printf("Enter a hexadecimal number: ");
    scanf("%x", &hex_num);

    while (hex_num > 0) {
        rem = hex_num % 10;
        dec_num += rem * base;
        base *= 16;
        hex_num /= 10;
    }

    printf("Decimal equivalent is: %d", dec_num);

    return 0;
}