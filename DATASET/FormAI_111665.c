//FormAI DATASET v1.0 Category: Binary Converter ; Style: complete
#include <stdio.h>

void decimalToBinary(int decimal);

int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    decimalToBinary(decimal);
    return 0;
}

void decimalToBinary(int decimal) {
    int binary[32];     // array to store binary digits
    int i = 0;
    while (decimal > 0) {
        binary[i] = decimal % 2;    // getting binary digit
        decimal /= 2;               // updating decimal
        i++;
    }
    printf("Binary equivalent: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);    // printing binary digits in reverse order
    }
}