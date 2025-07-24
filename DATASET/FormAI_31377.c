//FormAI DATASET v1.0 Category: Binary Converter ; Style: all-encompassing
#include <stdio.h>

int main() {
    unsigned int decimal;
    int binary[32], i = 0;

    // get the decimal number from the user
    printf("Enter a decimal number: ");
    scanf("%u", &decimal);

    // convert decimal to binary
    while (decimal > 0) {
        binary[i++] = decimal % 2;
        decimal /= 2;
    }

    // print the binary number
    printf("Binary equivalent: ");
    for (int j = i-1; j >= 0; j--) {
        printf("%d", binary[j]);
    }

    return 0;
}