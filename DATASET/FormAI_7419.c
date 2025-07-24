//FormAI DATASET v1.0 Category: Binary Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 // Maximum size of the binary string

int toDecimal(char binary[]) {
    int decimal = 0;
    int length = strlen(binary);
    int power = 1;
    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += power;
        }
        power *= 2;
    }
    return decimal;
}

void decimalToBinary(int decimal) {
    int binary[MAX_SIZE];
    int i = 0;
    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

int main() {
    char binaryString[MAX_SIZE];
    printf("Enter a binary number: ");
    scanf("%s", binaryString);
    int decimal = toDecimal(binaryString);
    printf("Decimal representation: %d\n", decimal);
    printf("Binary representation: ");
    decimalToBinary(decimal);
    printf("\n");
    return 0;
}