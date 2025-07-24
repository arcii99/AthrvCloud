//FormAI DATASET v1.0 Category: Binary Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main() {
    int decimal_num, binary_num = {0}, count = 0, remainder;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);

    while (decimal_num > 0) {
        remainder = decimal_num % 2;
        decimal_num /= 2;
        binary_num += remainder * pow(10, count);
        count++;
    }

    printf("Binary equivalent is: %d", binary_num);
    return 0;
}