//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: energetic
#include <stdio.h>

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimalNumber) {
    int quotient, remainder;
    int i = 1, j, temp;

    char hexadecimalNumber[100];

    quotient = decimalNumber;

    while(quotient != 0) {
        temp = quotient % 16;

        // To convert integer into character
        // for hexadecimals 0-9 are represented
        // as it is and A-F are represented as
        // 10-15 in ASCII values
        if(temp < 10) {
            temp += 48;
        }
        else {
            temp += 55;
        }

        hexadecimalNumber[i++] = temp;

        quotient /= 16;
    }

    // Printing hexadecimal number
    printf("Hexadecimal Equivalent: ");

    for(j = i - 1; j > 0; j--)
        printf("%c", hexadecimalNumber[j]);
}

int main() {
    int decimalNumber;

    printf("Enter a decimal number to convert to hexadecimal: ");
    scanf("%d", &decimalNumber);

    decimalToHexadecimal(decimalNumber);

    return 0;
}