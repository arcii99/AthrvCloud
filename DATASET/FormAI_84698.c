//FormAI DATASET v1.0 Category: Binary Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToBinary(int decimal);

int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    if (decimal < 0) {
        printf("Invalid Input! Decimal number must be positive.\n");
        exit(EXIT_FAILURE);
    }
    printf("The binary representation of %d is: ", decimal);
    convertToBinary(decimal);
    printf("\n");
    return 0;
}

void convertToBinary(int decimal) {
    int binary[32], index = 0;
    while(decimal > 0) {
        binary[index] = decimal % 2;
        decimal /= 2;
        index++;
    }
    for(int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}