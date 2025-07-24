//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hexToInt(char hex_char);

int main() {
    char hex[1000];
    int decimal = 0;
    int i, j, power = 0;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    // Convert each hex digit to decimal and add to decimal value
    for (i = strlen(hex) - 1; i >= 0; i--) {
        int decimal_digit = hexToInt(hex[i]);
        decimal += decimal_digit * (1 << power);
        power += 4;
    }

    printf("Decimal value: %d\n", decimal);

    return 0;
}

// Returns the integer value of a hexadecimal character
int hexToInt(char hex_char) {
    if (hex_char >= '0' && hex_char <= '9') {
        return hex_char - '0';
    } else if (hex_char >= 'A' && hex_char <= 'F') {
        return hex_char - 'A' + 10;
    } else if (hex_char >= 'a' && hex_char <= 'f') {
        return hex_char - 'a' + 10;
    } else {
        printf("Invalid hexadecimal input!\n");
        exit(1);
    }
}