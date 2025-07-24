//FormAI DATASET v1.0 Category: Binary Converter ; Style: genious
#include <stdio.h>
#include <string.h>

void decimalToBinary(int decimalNumber);

int main() {
    int decimalNumber;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    printf("Binary equivalent: ");
    decimalToBinary(decimalNumber);

    return 0;
}

void decimalToBinary(int decimalNumber) {
    int binaryArray[64];
    int index = 0;

    while (decimalNumber > 0) {
        binaryArray[index++] = decimalNumber % 2;
        decimalNumber /= 2;
    }
    
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binaryArray[i]);
    }
}