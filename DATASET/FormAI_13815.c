//FormAI DATASET v1.0 Category: Binary Converter ; Style: portable
#include <stdio.h>

void binary(int decimal_num) {
    int remainder;
    int binary_num = 0;
    int base = 1;

    while (decimal_num > 0) {
        remainder = decimal_num % 2;
        binary_num += remainder * base;
        decimal_num /= 2;
        base *= 10;
    }

    printf("Binary Number: %d\n", binary_num);
}

int main() {
    int decimal_num;

    printf("Enter a Decimal Number: ");
    scanf("%d", &decimal_num);

    binary(decimal_num);

    return 0;
}