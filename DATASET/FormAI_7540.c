//FormAI DATASET v1.0 Category: Binary Converter ; Style: peaceful
#include <stdio.h>

// This is a peaceful C Program that helps us convert decimal to binary. 

int main() {

    int decimalNumber, binaryNumber = 0, i = 1;

    printf("Please enter a decimal number: ");
    scanf("%d", &decimalNumber);

    while (decimalNumber != 0) {

        binaryNumber += (decimalNumber % 2) * i;
        decimalNumber /= 2;
        i *= 10;

    }

    printf("The binary equivalent is %d.\n", binaryNumber);

    return 0;

}