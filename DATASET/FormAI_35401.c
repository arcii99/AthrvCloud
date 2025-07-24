//FormAI DATASET v1.0 Category: Binary Converter ; Style: authentic
#include <stdio.h>

int main() {
    long int decimalNumber, quotient;
    int binaryNumber[100], i = 1, j;

    printf("Enter decimal number: ");
    scanf("%ld", &decimalNumber);

    quotient = decimalNumber;

    while (quotient != 0) {
        binaryNumber[i++] = quotient % 2;
        quotient = quotient / 2;
    }

    printf("Equivalent binary value of decimal number %ld: ", decimalNumber);

    for (j = i - 1; j > 0; j--)
        printf("%d", binaryNumber[j]);

    return 0;
}