//FormAI DATASET v1.0 Category: Binary Converter ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <math.h>

/*
    This program converts binary numbers to decimal values.
*/

int main(void) {
    char binaryString[100];
    int decimalValue = 0;
    int exponent = 0;
    int length;
    int i;

    printf("Enter binary number: ");
    scanf("%s", binaryString);

    length = strlen(binaryString);

    for (i = length - 1; i >= 0; i--) {
        if (binaryString[i] == '1') {
            decimalValue += pow(2, exponent);
        }
        exponent++;
    }

    printf("Decimal value is: %d\n", decimalValue);

    return 0;
}