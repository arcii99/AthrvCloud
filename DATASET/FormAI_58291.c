//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <math.h>

int hexadecimalToDecimal(char hex[]) {
    int decimal = 0, length, base = 1;
    int i;
    length = strlen(hex);
    for(i = length--; i >= 0; i--) {
        if(hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - 48) * base;
        } else if(hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 55) * base;
        } else if(hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 87) * base;
        }
        base *= 16;
    }
    return decimal;
}

int main() {
    char hex[100];
    int decimal;
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    decimal = hexadecimalToDecimal(hex);
    printf("Decimal number of %s is %d", hex, decimal);
    return 0;
}