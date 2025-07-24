//FormAI DATASET v1.0 Category: Binary Converter ; Style: intelligent
#include <stdio.h>
#include <math.h>

/* This program converts binary number to decimal number */

int main() {
    long long binaryNumber;
    int decimalNumber = 0, i = 0, remainder;
    printf("Enter a binary number: ");
    scanf("%lld", &binaryNumber);

    while(binaryNumber != 0) {
        remainder = binaryNumber % 10;
        binaryNumber /= 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
    }

    printf("The decimal equivalent of %lld is %d", binaryNumber, decimalNumber);
    return 0;
}