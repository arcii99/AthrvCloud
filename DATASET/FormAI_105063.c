//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: surprised
#include <stdio.h>

int main() {
    printf("Welcome to the Hexadecimal Converter!\n");
    printf("Enter a decimal number: ");

    int decimal;
    scanf("%d", &decimal);

    printf("\nDecimal %d in hexadecimal is: ", decimal);

    int remainder, quotient, i = 1, j;
    char hexadecimal[100];

    quotient = decimal;

    while (quotient != 0) {
        remainder = quotient % 16;
        if (remainder < 10) {
            hexadecimal[i++] = 48 + remainder;
        }
        else {
            hexadecimal[i++] = 55 + remainder;
        }
        quotient /= 16;
    }

    for (j = i - 1; j > 0; j--) {
        printf("%c", hexadecimal[j]);
    }
    printf("\n");

    printf("Thank you for using our converter! Don't forget to come back!\n");
    return 0;
}