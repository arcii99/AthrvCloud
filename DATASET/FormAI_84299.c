//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: imaginative
/* 
Welcome to my Hexadecimal Converter! In this program you can convert any decimal number to its hexadecimal equivalent.
Simply enter a decimal number and watch as it magically converts to its hexadecimal counterpart.
*/

#include <stdio.h>

int main() {

    int decimal, remainder, quotient, i = 1;
    char hexadecimal[100];

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    quotient = decimal;

    while (quotient != 0) {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimal[i++] = 48 + remainder;
        else
            hexadecimal[i++] = 55 + remainder;
        quotient = quotient / 16;
    }

    printf("Hexadecimal equivalent of %d is : ", decimal);

    for (int j = i; j >= 1; j--) {
        printf("%c", hexadecimal[j]);
    }

    printf("\n");

    return 0;
}