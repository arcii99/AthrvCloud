//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main() {
    long decimalNum, quotient, remainder;
    int i, j;
    char hexadecimalNum[100];

    printf("Enter a decimal number: ");
    scanf("%ld", &decimalNum);

    quotient = decimalNum;

    while (quotient != 0) {
        remainder = quotient % 16;
        if (remainder < 10) {
            hexadecimalNum[i++] = remainder + 48;
        } else {
            hexadecimalNum[i++] = remainder + 55;
        }
        quotient /= 16;
    }

    j = i - 1;

    printf("The hexadecimal number for %ld is: ", decimalNum);

    for (i = j; i >= 0; i--) {
        printf("%c", hexadecimalNum[i]);
    }

    return 0;
}