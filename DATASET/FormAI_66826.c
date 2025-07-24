//FormAI DATASET v1.0 Category: Binary Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int decimal);

int main() {
    int decimal;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    decimalToBinary(decimal);

    return 0;
}

void decimalToBinary(int decimal) {
    int binary[32] = {0};
    int index = 0;

    while(decimal > 0) {
        binary[index] = decimal % 2;
        decimal /= 2;
        index++;
    }

    printf("Binary number: ");

    for(int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}