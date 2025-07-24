//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

void print_hexadecimal(int decimal_number) {
    int remainder, quotient;
    char hexadecimal_array[100];
    quotient = decimal_number;
    int i = 0;
    while (quotient != 0) {
        remainder = quotient % 16;
        if (remainder < 10) {
            hexadecimal_array[i++] = 48 + remainder;
        } else {
            hexadecimal_array[i++] = 55 + remainder;
        }
        quotient = quotient / 16; 
    }
    printf("\n Hexadecimal Conversion: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal_array[j]);
    }
}

int main() {
    int decimal_number;
    printf("\n Enter Decimal Number to Convert to Hexadecimal: ");
    scanf("%d", &decimal_number);
    if (decimal_number < 0) {
        printf("\n Negative Decimal Numbers Cannot be Converted to Hexadecimal.");
        exit(0);
    }
    print_hexadecimal(decimal_number);
    printf("\n");
    return 0;
}