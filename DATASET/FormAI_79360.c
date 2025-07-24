//FormAI DATASET v1.0 Category: Binary Converter ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main() {
    // Initialize variables
    int decimalNumber, quotient, remainder;
    int binaryNumber[100], i = 1, j;
    printf("\nEnter any decimal number: ");
    scanf("%d", &decimalNumber);

    // Conversion process
    quotient = decimalNumber;
    while (quotient != 0) {
        binaryNumber[i++] = quotient % 2;
        quotient = quotient / 2;
    }

    // Output Binary Number
    printf("\nEquivalent binary value of decimal number %d: ", decimalNumber);
    for (j = i - 1; j > 0; j--) {
        printf("%d", binaryNumber[j]);
    }

    return 0;
}