//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: complete
#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    char hex[17], hexChar;
    int decimal = 0, i, j, digit;
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    j = strlen(hex);
    for(i = 0; hex[i] != '\0'; i++) {
        j--;
        hexChar = hex[i];
        if(hexChar >= '0' && hexChar <= '9') {
            digit = hexChar - '0';
        }
        else if(hexChar >= 'a' && hexChar <='f') {
            digit = hexChar - 'a' + 10;
        }
        else if(hexChar >= 'A' && hexChar <= 'F') {
            digit = hexChar - 'A' + 10;
        }
        decimal += digit*pow(16, j);
    }
    printf("Equivalent decimal number is: %d", decimal);
    return 0;
}