//FormAI DATASET v1.0 Category: Binary Converter ; Style: medieval
#include <stdio.h>

void decimalToBinary(unsigned int decimalNumber) {
    int binaryNumber[32];
    int i = 0;
    while (decimalNumber > 0) {
        binaryNumber[i] = decimalNumber % 2;
        decimalNumber /= 2;
        i++;
    }
    printf("The binary representation is: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNumber[j]);
    }
    printf("\n");
}

int main() {
    unsigned int number;
    printf("Enter a decimal number: ");
    scanf("%u", &number);
    decimalToBinary(number);
    return 0;
}