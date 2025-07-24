//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char hex[100], hexDigit;
    int decimal = 0, power = 0, i;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    for (i = strlen(hex) - 1; i >= 0; i--) {
        hexDigit = hex[i];

        if (hexDigit >= '0' && hexDigit <= '9')
            decimal += (hexDigit - '0') * pow(16, power);
        else if (hexDigit >= 'A' && hexDigit <= 'F')
            decimal += (hexDigit - 'A' + 10) * pow(16, power);
        else if (hexDigit >= 'a' && hexDigit <= 'f')
            decimal += (hexDigit - 'a' + 10) * pow(16, power);
        else {
            printf("\nInvalid hexadecimal digit %c \n", hexDigit);
            return 0;
        }

        power++;
    }

    printf("\n\nDecimal of '%s' is: %d\n\n", hex, decimal);

    return 0;
}