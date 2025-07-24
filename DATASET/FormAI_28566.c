//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: calm
#include <stdio.h>

int main() {
    int decimal_num, remainder, quotient, i = 1, j;
    char hex_num[100];

    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);

    quotient = decimal_num;

    while (quotient != 0) {
        remainder = quotient % 16;
        if (remainder < 10) {
            hex_num[i++] = 48 + remainder;
        } else {
            hex_num[i++] = 55 + remainder;
        }
        quotient = quotient / 16;
    }

    printf("Hexadecimal number of %d is: ", decimal_num);

    for(j = i - 1; j > 0; j--) {
        printf("%c", hex_num[j]);
    }

    return 0;
}