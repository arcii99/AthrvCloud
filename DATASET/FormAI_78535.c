//FormAI DATASET v1.0 Category: Binary Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100 // Maximum binary length constant

int convertBinaryToDecimal(long); // Function prototype

int main() {
    long binaryNumber;
    int decimalNumber, i = 0, remainder;
    char binary[MAX_LENGTH];

    // Input binary number
    printf("Enter a binary number: ");
    scanf("%ld", &binaryNumber);

    // Convert binary to decimal using function
    decimalNumber = convertBinaryToDecimal(binaryNumber);
    printf("%ld in binary = %d in decimal\n", binaryNumber, decimalNumber);

    // Convert decimal to binary
    while (decimalNumber != 0) {
        binary[i++] = decimalNumber % 2 + '0';
        decimalNumber /= 2;
    }
    binary[i] = '\0'; // Set null terminator

    // Reverse binary array
    for (int j = 0, k = i - 1; j < k; j++, k--) {
        remainder = binary[j];
        binary[j] = binary[k];
        binary[k] = remainder;
    }

    printf("%d in decimal = %s in binary\n", decimalNumber, binary);
    return 0;
}

int convertBinaryToDecimal(long binaryNumber) {
    int decimalNumber = 0, i = 0, remainder;
    // Convert binary to decimal
    while (binaryNumber != 0) {
        remainder = binaryNumber % 10;
        binaryNumber /= 10;
        decimalNumber += remainder * pow(2, i);
        i++;
    }
    return decimalNumber;
}