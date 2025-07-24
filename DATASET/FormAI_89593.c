//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Alan Touring
// Unique C Color Code Converter Example Program
// Written in Alan Turing Style by [Your Name]


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 7

// Function to convert hexadecimal to decimal
int hexToDec(char* hex) {
    return (int)strtol(hex, NULL, 16);
}

// Function to convert decimal to hexadecimal
char* decToHex(int dec) {
    char* hex = (char*)malloc(sizeof(char) * MAX_LENGTH);
    sprintf(hex, "#%02X%02X%02X", (dec >> 16) & 0xff, (dec >> 8) & 0xff, dec & 0xff);
    return hex;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a color code in either hexadecimal or decimal format:\n");
    scanf("%s", input);

    int dec;
    char* hex;

    // Check if input is a hexadecimal color code
    if (input[0] == '#') {
        dec = hexToDec(input + 1);
        printf("Decimal Color Code: %d\n", dec);
    }
    // Check if input is a decimal color code
    else if (atoi(input) >= 0 && atoi(input) <= 16777215) {
        dec = atoi(input);
        printf("Hexadecimal Color Code: %s\n", decToHex(dec));
    }
    else {
        printf("Invalid input. Please enter a valid color code.\n");
    }

    return 0;
}