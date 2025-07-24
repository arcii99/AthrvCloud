//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: genious
#include <stdio.h>

// This program converts a decimal number to hexadecimal.

void convertToHexadecimal(int decimal);

int main() {
    int decimalNumber;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);
    printf("The hexadecimal representation of %d is: ", decimalNumber);
    convertToHexadecimal(decimalNumber);
    return 0;
}

void convertToHexadecimal(int decimal) {
    char hexadecimal[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int remainder = decimal % 16;
    if (decimal / 16 == 0) {
        printf("%c", hexadecimal[remainder]);
    } else {
        convertToHexadecimal(decimal / 16);
        printf("%c", hexadecimal[remainder]);
    }
}