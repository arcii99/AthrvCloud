//FormAI DATASET v1.0 Category: Binary Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void convertDecimalToBinary(int decimalNumber);

int main() {
    int decimalNumber;
    
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);
    
    convertDecimalToBinary(decimalNumber);

    return 0;
}

void convertDecimalToBinary(int decimalNumber) {
    int binaryNumber = 0, remainder, i = 0;

    while(decimalNumber != 0) {
        remainder = decimalNumber % 2;
        decimalNumber /= 2;
        binaryNumber += remainder * pow(10, i);
        i++;
    }

    printf("Binary equivalent is: %d", binaryNumber);
}