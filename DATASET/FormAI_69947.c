//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hexToInt(char c) {
    int result;

    if (c >= '0' && c <= '9')
        result = c - '0';
    else if (c >= 'A' && c <= 'F')
        result = c - 'A' + 10;
    else if (c >= 'a' && c <= 'f')
        result = c - 'a' + 10;
    else
        result = -1; // Invalid character.

    return result;
}

int hexToDecimal(char* hex) {
    int result = 0;
    int length = strlen(hex);
    int i;

    for (i = 0; i < length; i++) {
        int digit = hexToInt(hex[i]);

        if (digit == -1) {
            printf("Invalid hexadecimal number\n");
            return -1;
        }

        result += digit * (1 << (4 * (length - i - 1)));
    }

    printf("Decimal value: %d\n", result);
    return result;
}

int main() {
   char hex[10];
   printf("Enter a hexadecimal number: ");
   scanf("%s", hex);
   hexToDecimal(hex);
   return 0;
}