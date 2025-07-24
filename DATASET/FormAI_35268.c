//FormAI DATASET v1.0 Category: Binary Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void binaryConversion(int number, int *binaryArray, int *index) {
    if (number > 1) {
        binaryConversion(number/2, binaryArray, index);
    }
    binaryArray[(*index)++] = number % 2;
}

int main() {
    int number, binary[32], index = 0;
    printf("Enter a decimal number: ");
    scanf("%d", &number);

    binaryConversion(number, binary, &index);

    printf("The binary representation of %d is: ", number);
    for(int i = 0; i < index; i++) {
        printf("%d", binary[i]);
    }

    return 0;
}