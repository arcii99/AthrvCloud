//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: energetic
#include <stdio.h>

int main() {
    int decimal, quotient, remainder;
    int i = 0, j;
    char hexadecimal[100];

    printf("Welcome to my Hexadecimal Converter Program!\n");
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    quotient = decimal;

    while (quotient != 0) {
        remainder = quotient % 16;

        if (remainder < 10) {
            hexadecimal[i++] = remainder + 48;
        }
        else {
            hexadecimal[i++] = remainder + 55;
        }

        quotient /= 16;
    }

    printf("\nHexadecimal representation of %d is: ", decimal);

    for (j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }

    printf("\nThank you for using my program!");

    return 0;
}