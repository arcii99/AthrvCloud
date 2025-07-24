//FormAI DATASET v1.0 Category: Binary Converter ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int binaryToDecimal(char *binary) {
    if (strlen(binary) == 1) {
        return *binary - '0';
    } else {
        return ((binary[strlen(binary)-1] - '0') +
               2 * binaryToDecimal(strncpy(binary, binary, strlen(binary)-1)));
    }
}

void decimalToBinary(int decimal) {
    if (decimal < 2) {
        printf("%d", decimal);
        return;
    } else {
        decimalToBinary(decimal / 2);
        printf("%d", decimal % 2);
    }
}

int main() {
    char binary[100];
    int decimal;

    printf("Welcome to the Mind-Bending Binary Converter!\n\n");

    printf("Enter a binary number: ");
    scanf("%s", binary);

    decimal = binaryToDecimal(binary);

    printf("\nDecimal equivalent: %d", decimal);

    printf("\nEnter a decimal number: ");
    scanf("%d", &decimal);

    printf("\nBinary equivalent: ");
    decimalToBinary(decimal);

    printf("\n\nThank you for using the Mind-Bending Binary Converter!\n");

    return 0;
}