//FormAI DATASET v1.0 Category: Color Code Converter ; Style: multiplayer
#include <stdio.h>

// function to check if the input number is valid hexadecimal digit
int isHexDigit(char c) {
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))
        return 1;
    else
        return 0;
}

// function to convert a valid hexadecimal digit to its decimal equivalent
int hexToDec(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    else
        return c - 'a' + 10;
}

int main() {
    char hexCode[7];
    int red, green, blue;
    
    printf("Enter a valid hexadecimal color code (in the format RRGGBB): ");
    scanf("%6s", hexCode);

    // input validation
    for (int i = 0; i < 6; i++) {
        if (!isHexDigit(hexCode[i])) {
            printf("Invalid input. Please enter a valid hexadecimal color code (in the format RRGGBB).\n");
            return 1;
        }
    }

    // convert hexadecimal values to decimal values
    red = hexToDec(hexCode[0]) * 16 + hexToDec(hexCode[1]);
    green = hexToDec(hexCode[2]) * 16 + hexToDec(hexCode[3]);
    blue = hexToDec(hexCode[4]) * 16 + hexToDec(hexCode[5]);

    printf("The decimal equivalent of the color code #%s is (%d, %d, %d).\n", hexCode, red, green, blue);

    return 0;
}