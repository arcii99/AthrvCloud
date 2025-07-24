//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: inquisitive
#include <stdio.h>

int main() {
    int decimal_num, remainder, quotient, i=1, j, temp;
    char hex_num[100];

    // Get decimal number from user input
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);

    quotient = decimal_num;

    // Convert decimal to hexadecimal
    while (quotient != 0) {
        temp = quotient % 16;
        // To convert integer to character in hex
        if (temp < 10) {
            temp = temp + 48;
        } else {
            temp = temp + 55;
        }
        hex_num[i++] = temp;
        quotient = quotient / 16;
    }

    // Print out hexadecimal output
    printf("\nHexadecimal value of %d is: ", decimal_num);
    for (j = i - 1; j > 0; j--) {
        printf("%c", hex_num[j]);
    }

    return 0;
}