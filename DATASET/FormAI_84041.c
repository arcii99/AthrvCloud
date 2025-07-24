//FormAI DATASET v1.0 Category: Binary Converter ; Style: creative
#include <stdio.h>
#include <math.h>

int main() {
    int decimal, binary = 0, count = 0, remainder;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // Converting decimal to binary
    while (decimal > 0) {
        remainder = decimal % 2;
        binary += remainder * pow(10, count);
        decimal /= 2;
        count++;
    }

    // Reversing the binary value
    int temp = binary, reversedBinary = 0, digit;
    while (temp > 0) {
        digit = temp % 10;
        reversedBinary = reversedBinary * 10 + digit;
        temp /= 10;
    }

    printf("Decimal: %d\n Binary: %d", decimal, reversedBinary);
    return 0;
}