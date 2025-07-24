//FormAI DATASET v1.0 Category: Binary Converter ; Style: configurable
#include <stdio.h>
#include <limits.h>

// Function to convert decimal to binary
void decimalToBinary(int decimalNumber, char binaryNumber[], int size) {
    int i = 0;
    while (decimalNumber > 0 && i < size) {
        binaryNumber[i++] = decimalNumber % 2 + '0';
        decimalNumber /= 2;
    }
    while (i < size) {
        binaryNumber[i++] = '0';
    }
    binaryNumber[size] = '\0';
}

// Function to convert binary to decimal
int binaryToDecimal(char binaryNumber[], int size) {
    int decimalNumber = 0;
    int powerOfTwo = 1;
    for (int i = size - 1; i >= 0; i--) {
        decimalNumber += (binaryNumber[i] - '0') * powerOfTwo;
        powerOfTwo *= 2;
    }
    return decimalNumber;
}

int main() {
    int decimalNumber;
    char binaryNumber[CHAR_BIT * sizeof(int) + 1];
    int size = CHAR_BIT * sizeof(int);
    printf("Enter decimal number: ");
    scanf("%d", &decimalNumber);
    decimalToBinary(decimalNumber, binaryNumber, size);
    printf("Binary representation: %s\n", binaryNumber);
    printf("Enter binary number: ");
    scanf("%s", binaryNumber);
    printf("Decimal representation: %d\n", binaryToDecimal(binaryNumber, size));
    return 0;
}