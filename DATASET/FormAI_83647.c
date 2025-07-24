//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: thoughtful
#include <stdio.h>

void convertToHex(int decimal) {
    int remainder[100], quotient = decimal, i = 0;
    char hex[100];
    while (quotient != 0) { // divide the decimal number by 16 continuously until the quotient is 0
        remainder[i] = quotient % 16; // store the remainder in an array
        quotient = quotient / 16; // update the quotient
        i++;
    }
    printf("Hexadecimal equivalent of %d is: ", decimal);
    for (int j = i - 1; j >= 0; j--) {
        if (remainder[j] <= 9) { // if remainder is less than 9, store the remainder value in the hex array
            hex[i - 1 -j] = remainder[j] + '0';
        } else { // otherwise, store the hex value in the hex array
            hex[i - 1 -j] = remainder[j] + 55;
            // add 55 to the remainder to get the corresponding ASCII value of the hexadecimal digit
        }
    }
    printf("%s\n", hex); // print the hexadecimal number
}

int main() {
    int decimal;
    printf("Enter a decimal number to convert to hexadecimal: ");
    scanf("%d", &decimal);

    convertToHex(decimal);

    return 0;
}