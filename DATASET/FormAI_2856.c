//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000 // maximum size of input string

// function to convert hexadecimal string to decimal integer
int hexToInt(char hexString[]) {
    int length = strlen(hexString);
    int decimal = 0;
    for (int i = 0; i < length; i++) {
        int digit = 0;
        if (isdigit(hexString[i])) {
            digit = hexString[i] - '0';
        } else if (isalpha(hexString[i])) {
            digit = toupper(hexString[i]) - 'A' + 10;
        } else {
            return -1; // invalid input
        }
        decimal += digit * pow(16, length - i - 1);
    }
    return decimal;
}

// function to convert decimal integer to hexadecimal string
void intToHex(int decimal, char hexString[]) {
    sprintf(hexString, "%X", decimal); // using sprintf to format integer as hexadecimal string
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a hexadecimal number: ");
    fgets(input, MAX_LENGTH, stdin); // reading input as string
    input[strcspn(input, "\n")] = '\0'; // removing newline character from input string
    int decimal = hexToInt(input);
    if (decimal == -1) {
        printf("Error: Invalid input\n");
        return 1; // exit program with error code
    }
    printf("Decimal: %d\n", decimal);
    char output[MAX_LENGTH];
    intToHex(decimal, output);
    printf("Hexadecimal: %s\n", output);
    return 0; // exit program with success code
}