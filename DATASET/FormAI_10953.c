//FormAI DATASET v1.0 Category: Binary Converter ; Style: lively
#include <stdio.h>

int main() {
    int decimal_num, binary_num = 0, remainder, base = 1;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);

    while (decimal_num > 0) {
        remainder = decimal_num % 2;
        binary_num = binary_num + remainder * base;
        decimal_num = decimal_num / 2;
        base = base * 10;
    }

    printf("Binary number: %d\n", binary_num);

    return 0;
}