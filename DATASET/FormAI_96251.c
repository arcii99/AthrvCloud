//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// function prototype
void convertToHexadecimal(unsigned int decimal);

int main() {
    char userInput[10];
    unsigned int decimal;

    printf("Enter a decimal value: ");
    fgets(userInput, 10, stdin);

    if (isdigit(userInput[0])) {
        decimal = strtoul(userInput, NULL, 10);
        // call function to convert decimal to hexadecimal
        convertToHexadecimal(decimal);
    } else {
        printf("Invalid input. Please enter a valid decimal value.\n");
    }

    return 0;
}

// function to convert decimal value to hexadecimal
void convertToHexadecimal(unsigned int decimal) {
    char hexadecimal[10];
    int i = 0;

    while (decimal != 0) {
        int remainder = decimal % 16;
        
        if (remainder < 10) {
            hexadecimal[i] = remainder + '0';
        } else {
            hexadecimal[i] = remainder + 55; 
        }

        i++;
        decimal /= 16;
    }

    // print the hexadecimal value in reverse order
    printf("Hexadecimal value: 0x");
    for (int j = i-1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }
    printf("\n");
}