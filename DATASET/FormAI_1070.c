//FormAI DATASET v1.0 Category: Binary Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>

/*
 * This program is a binary converter. 
 * It takes a decimal number and converts it to binary. But wait, there's more! 
 * It also tells you whether or not the resulting binary number is even or odd.
 * 
 * How use funny terms to make it more engaging and fun!
 * Author: Your Friendly Chatbot :)
 */

int main(void) {
    int decimal_number, quotient, remainder, i, count = 0;
    int binary_number[100];

    printf("Welcome to the Binary Converter 3000! \n");
    printf("Enter a decimal number you want to convert: ");
    scanf("%d", &decimal_number);

    quotient = decimal_number;

    while (quotient != 0) {
        remainder = quotient % 2;
        quotient /= 2;
        binary_number[count] = remainder;
        count++;
    }

    printf("\nThe binary equivalent of %d is: ", decimal_number);

    for (i = count - 1; i >= 0; i--) {
        printf("%d", binary_number[i]);
    }

    if (binary_number[0] == 1) {
        printf("\nWow, this is an odd number! \n");
    } else {
        printf("\nWhoa, this is an even number! \n");
    }

    printf("\nThanks for using the Binary Converter 3000! Goodbye! \n");

    return 0;
}