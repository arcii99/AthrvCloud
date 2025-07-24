//FormAI DATASET v1.0 Category: Binary Converter ; Style: introspective
#include <stdio.h>

// function to convert decimal to binary
void decimalToBinary(int num) {
    if (num > 1) {
        decimalToBinary(num / 2);
    }
    printf("%d", num % 2);
}

int main() {

    int decimal;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    printf("The binary equivalent of %d is: ", decimal);
    decimalToBinary(decimal);
    printf("\n");

    return 0;
}