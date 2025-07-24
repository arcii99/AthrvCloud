//FormAI DATASET v1.0 Category: Binary Converter ; Style: relaxed
#include <stdio.h>

void printBinary(int decimal) {
    int binaryArr[32];
    int i = 0;

    while (decimal > 0) {
        binaryArr[i] = decimal % 2;
        decimal /= 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryArr[j]);
    }
}

int main() {
    int decimal;

    printf("Enter a decimal number to convert to binary: ");
    scanf("%d", &decimal);

    printf("The binary representation of %d is: ", decimal);
    printBinary(decimal);

    return 0;
}