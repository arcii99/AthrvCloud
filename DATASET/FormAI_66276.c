//FormAI DATASET v1.0 Category: Binary Converter ; Style: futuristic
#include <stdio.h>
#include <math.h>

int main() {
    long long binaryNumber, decimalNumber = 0;
    int i = 0, remainder;
    printf("Enter the binary number: ");
    scanf("%lld", &binaryNumber);
    while (binaryNumber != 0) {
        remainder = binaryNumber % 10;
        binaryNumber /= 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
    }
    printf("Decimal Equivalent: %lld\n", decimalNumber);
    return 0;
}