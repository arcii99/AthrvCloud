//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimalNumber){
    int quotient = decimalNumber / 16;
    int remainder = decimalNumber % 16;

    if(quotient != 0){
        decimalToHexadecimal(quotient);
    }

    if(remainder < 10) {
        printf("%d", remainder);
    } else {
        printf("%c", remainder-10+'A');
    }
}

// Main function starts here
int main() {
    int decimalNumber;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    printf("The hexadecimal representation of %d is: 0x", decimalNumber);
    decimalToHexadecimal(decimalNumber);
    printf("\n");

    return 0;
}