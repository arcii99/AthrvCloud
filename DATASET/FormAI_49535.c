//FormAI DATASET v1.0 Category: Binary Converter ; Style: optimized
#include <stdio.h>

void printBinary(int num);

int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    printf("The binary equivalent is: ");
    printBinary(decimal);

    return 0;
}

void printBinary(int num) {
    int binary[32], index = 0;

    while (num > 0) {
        binary[index++] = num % 2;
        num = num / 2;
    }

    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}