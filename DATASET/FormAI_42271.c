//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: genious
#include <stdio.h>
#include <string.h>

void convertToHex(char input);

int main() {
    char input;
    printf("Welcome to the Hexadecimal Converter! Enter an ASCII character: ");
    scanf("%c", &input);
    printf("The hexadecimal representation of '%c' is: ", input);
    convertToHex(input);
    return 0;
}

void convertToHex(char input) {
    char hex[3];
    int ascii = input;
    sprintf(hex, "%02X", ascii);
    printf("%s\n", hex);
}