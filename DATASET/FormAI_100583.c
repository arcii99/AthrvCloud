//FormAI DATASET v1.0 Category: Binary Converter ; Style: introspective
#include <stdio.h>

int main() {
    int decimal, tempDecimal, binary = 0, base = 1, remainder;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    tempDecimal = decimal;
    while(tempDecimal > 0) {
        remainder = tempDecimal % 2;
        binary = binary + remainder * base;
        base *= 10;
        tempDecimal /= 2;
    }
    printf("Decimal number %d in binary is: %d\n", decimal, binary);
    return 0;
}