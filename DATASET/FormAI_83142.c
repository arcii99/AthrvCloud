//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: happy
#include <stdio.h>

int main() {
    int decimal, quotient, remainder, i = 1, j;
    char hexadecimal[100];

    printf("Let's convert a decimal number to hexadecimal! Enter a positive integer: ");
    scanf("%d", &decimal);

    quotient = decimal;

    while (quotient != 0) {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimal[i++] = 48 + remainder;
        else
            hexadecimal[i++] = 55 + remainder;
        quotient /= 16;
    }

    printf("\nEquivalent hexadecimal value of %d is: ", decimal);
    for (j = i - 1; j > 0; j--)
        printf("%c", hexadecimal[j]);

    return 0;
}