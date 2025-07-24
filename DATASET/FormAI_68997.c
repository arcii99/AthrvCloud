//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: scalable
#include <stdio.h>
#include <ctype.h>

int main() {
    char hex[100];
    int i = 0, decimal = 0, place = 1;
    printf("Enter a hexadecimal number: ");
    fgets(hex, 100, stdin);
    // Converting hexadecimal to decimal
    while (hex[i] != '\0' && hex[i] != '\n') {
        if (isdigit(hex[i])) {
            decimal += (hex[i] - '0') * place;
            place *= 16;
        } else if (isupper(hex[i])) {
            decimal += (hex[i] - 'A' + 10) * place;
            place *= 16;
        } else if (islower(hex[i])) {
            decimal += (hex[i] - 'a' + 10) * place;
            place *= 16;
        } 
        i++;
    }
    printf("Decimal equivalent: %d\n", decimal);
    // Converting decimal back to hexadecimal
    int quotient, remainder;
    char hexEquivalent[100];
    quotient = decimal;
    i = 0;
    while (quotient != 0) {
        remainder = quotient % 16;
        if (remainder < 10) {
            hexEquivalent[i++] = remainder + '0';
        } else {
            hexEquivalent[i++] = remainder - 10 + 'A';
        }
        quotient /= 16;
    }
    printf("Hexadecimal equivalent: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexEquivalent[j]);
    }
    printf("\n");
    return 0;
}