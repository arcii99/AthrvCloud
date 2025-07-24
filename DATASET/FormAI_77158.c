//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: excited
#include <stdio.h>

int main() {
    printf("Welcome to the exciting Hexadecimal Converter!\n");
    printf("Enter a decimal number to be converted: ");

    int decimal;
    scanf("%d", &decimal);

    printf("The hex equivalent of %d is: ", decimal);
    char hex[100]; // create an array to store the intermediate values
    int index = 0; // initialize the index to zero

    while(decimal > 0) { // while the decimal number is positive
        int remainder = decimal % 16; // get the remainder after dividing by 16
        if(remainder < 10) {
            hex[index] = remainder + '0'; // convert the digit to a character from '0' to '9'
        } else {
            hex[index] = remainder + 55; // convert the digit to a character from 'A' to 'F'
        }
        index++; // increment the index
        decimal /= 16; // divide the decimal by 16
    }

    // Reverse the array
    for(int i=0; i<index/2; i++) {
        char temp = hex[i];
        hex[i] = hex[index-i-1];
        hex[index-i-1] = temp;
    }

    // Print the final hex value
    for(int i=0; i<index; i++) {
        printf("%c", hex[i]);
    }

    printf("\nThanks for using the Hexadecimal Converter!\n");
    return 0;
}