//FormAI DATASET v1.0 Category: Binary Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BINARY_LENGTH 20

int binary_to_decimal(char *binary) {
    int len = strlen(binary);
    int decimal = 0;
    for (int i = 0; i < len; i++) {
        if (binary[i] == '1') {
            decimal += 1 << (len - i - 1);
        }
    }
    return decimal;
}

char *decimal_to_binary(int decimal) {
    char *binary = (char *) malloc(MAX_BINARY_LENGTH * sizeof(char));
    int index = 0;
    while (decimal > 0) {
        binary[index++] = (decimal % 2) + '0';
        decimal /= 2;
    }
    binary[index] = '\0';
    int len = strlen(binary);
    for (int i = 0; i < len / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[len - i - 1];
        binary[len - i - 1] = temp;
    }
    return binary;
}

int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    char *binary = decimal_to_binary(decimal);

    printf("Binary equivalent of %d is %s\n", decimal, binary);

    int converted_decimal = binary_to_decimal(binary);

    printf("Converted back, decimal equivalent of %s is %d\n", binary, converted_decimal);

    return 0;
}