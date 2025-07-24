//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: automated
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char str_hex[50];
    int decimal = 0, base = 1, i, len;
    printf("Enter a hexadecimal number: ");
    scanf("%s", str_hex);
    len = strlen(str_hex);
    for (i=len-1; i>=0; i--) {
        if (str_hex[i]>='0' && str_hex[i]<='9') {
            decimal += (str_hex[i] - 48)*base;
            base *= 16;
        } else if (str_hex[i]>='A' && str_hex[i]<='F') {
            decimal += (str_hex[i] - 55)*base;
            base *= 16;
        } else if (str_hex[i]>='a' && str_hex[i]<='f') {
            decimal += (str_hex[i] - 87)*base;
            base *= 16;
        } else {
            printf("\nInvalid hexadecimal number");
            return 0;
        }
    }
    printf("\nDecimal number is: %d", decimal);
    return 0;
}