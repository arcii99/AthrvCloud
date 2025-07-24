//FormAI DATASET v1.0 Category: Binary Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define BITS_IN_BYTE 8

void binaryConverter(unsigned char number) {
    int bit;
    for(bit = BITS_IN_BYTE - 1; bit >= 0; bit--) {
        printf("%d", (number & (1 << bit)) ? 1 : 0);
    }
}

int main() {
    int decimalNumber = 0;
    printf("Enter a decimal number (0-255): ");
    scanf("%d", &decimalNumber);

    if((decimalNumber < 0) || (decimalNumber > 255)) {
        printf("Invalid decimal number!\n");
        exit(1);
    }

    printf("The binary representation of %d is: ", decimalNumber);
    binaryConverter((unsigned char) decimalNumber);
    printf("\n");

    return 0;
}