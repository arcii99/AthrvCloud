//FormAI DATASET v1.0 Category: Binary Converter ; Style: Alan Touring
#include <stdio.h>

void binaryConversion(int number) {
    int binary[32];
    int remainder, index = 0;
    while (number > 0) {
        remainder = number % 2;
        binary[index++] = remainder;
        number /= 2;
    }
    printf("Binary conversion: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}

int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    binaryConversion(decimal);
    return 0;
}