//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: shocked
#include <stdio.h>

int main() {
    printf("Welcome to the unique C Hexadecimal Converter!\n");
    printf("Enter a decimal number: ");
    int decimal;
    scanf("%d", &decimal);
    printf("Your decimal number is: %d\n", decimal);

    int quotient = decimal;
    int remainder;
    char hexadecimal[100];
    int index = 0;

    while (quotient != 0) {
        remainder = quotient % 16;
        if (remainder < 10) {
            hexadecimal[index] = remainder + 48;
            index++;
        } else {
            hexadecimal[index] = remainder + 55;
            index++;
        }
        quotient = (int)(quotient / 16.0);
    }

    printf("Your hexadecimal number is: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hexadecimal[i]);
    }
    printf("\n");

    return 0;
}