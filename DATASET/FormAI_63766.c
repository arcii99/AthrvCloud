//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: random
#include <stdio.h>

int main() {
    int decimal_num, quotient, remainder, i, j;
    int hexadecimal_num[100];

    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);

    quotient = decimal_num;

    // convert decimal to hexadecimal
    for (i = 0; quotient != 0; i++) {
        remainder = quotient % 16;
        if (remainder < 10) {
            hexadecimal_num[i] = 48 + remainder;
        } else {
            hexadecimal_num[i] = 55 + remainder;
        }
        quotient = quotient / 16;
    }

    // print the result
    printf("Hexadecimal number: ");
    for (j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal_num[j]);
    }
    printf("\n");

    return 0;
}