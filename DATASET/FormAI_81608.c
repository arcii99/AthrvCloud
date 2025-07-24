//FormAI DATASET v1.0 Category: Binary Converter ; Style: happy
#include <stdio.h>

int main() {
    int decimalNumber, remainder, quotient, i = 1, j;
    char hexadecimalNumber[100];
    char binaryNumber[100];
 
    printf("\nEnter a decimal number: ");
    scanf("%d", &decimalNumber);
 
    quotient = decimalNumber;
 
    while (quotient != 0) {
        binaryNumber[i++] = quotient % 2 + '0';
        quotient = quotient / 2;
    }
 
    printf("\nBinary number of %d is: ", decimalNumber);
    for (j = i - 1; j > 0; j--)
        printf("%c", binaryNumber[j]);
 
    i = 0;
    quotient = decimalNumber;
 
    while (quotient != 0) {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimalNumber[i++] = remainder + 48;
        else
            hexadecimalNumber[i++] = remainder + 55;
        quotient = quotient / 16;
    }
 
    printf("\nHexadecimal number is: ");
    for (j = i - 1; j >= 0; j--)
        printf("%c", hexadecimalNumber[j]);
 
    printf("\n");
    return 0;
}