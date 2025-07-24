//FormAI DATASET v1.0 Category: Binary Converter ; Style: careful
#include <stdio.h>

int main() {
    int decimal_num, binary_num = 0, base = 1, rem;

    /* Input decimal number from user */
    printf("Enter a decimal integer: ");
    scanf("%d", &decimal_num);

    /* convert decimal to binary */
    while (decimal_num > 0) {
        rem = decimal_num % 2;
        binary_num += rem * base;
        decimal_num /= 2;
        base *= 10;
    } 

    printf("The binary representation of %d is %d\n", decimal_num, binary_num);
    return 0;
}