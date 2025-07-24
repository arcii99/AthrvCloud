//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: medieval
#include <stdio.h>

int main() {

    int decimalNum, remainder;

    // Ask the user to enter the decimal number
    printf("Good day sire! Please enter a decimal number to convert to hexadecimal: ");
    scanf("%d", &decimalNum);

    // Declare the hexadecimal array
    char hexadecimalNum[20];

    // Convert decimal to hexadecimal
    int i = 0;
    while (decimalNum != 0) {
        remainder = decimalNum % 16;
        if (remainder < 10) {
            hexadecimalNum[i] = remainder + 48;
            i++;
        }
        else {
            hexadecimalNum[i] = remainder + 55;
            i++;
        }
        decimalNum = decimalNum / 16;
    }

    // Print the hexadecimal number
    printf("The converted hexadecimal number is: 0x");
    for (int j = i - 1; j >= 0; j--)
        printf("%c", hexadecimalNum[j]);

    printf("\nThank you sire! Enjoy your new hexadecimal number.\n");
    
    return 0;
}