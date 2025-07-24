//FormAI DATASET v1.0 Category: Color Code Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hexToDecimal(char hexVal[]) { // Function to convert hexadecimal to decimal
    int len = strlen(hexVal);  
    int base = 1;
    int decVal = 0;

    for (int i=len-1; i>=0; i--) {
        if (hexVal[i]>='0' && hexVal[i]<='9') {
            decVal += (hexVal[i] - 48)*base;
            base = base * 16;
        }
        else if (hexVal[i]>='A' && hexVal[i]<='F') {
            decVal += (hexVal[i] - 55)*base;
            base = base*16;
        }
    }
    return decVal;
}

void decimalToRgb(int decimalVal, int *r, int *g, int *b) { // Function to convert decimal to RGB values
    *r = (decimalVal >> 16) & 0xFF;
    *g = (decimalVal >> 8) & 0xFF;
    *b = decimalVal & 0xFF;
}

int main() {
    char colorCode[8];
    printf("Enter the color code in hex format: ");
    scanf("%s", colorCode);

    // Converting the hex color code to decimal
    int decimalVal = hexToDecimal(colorCode);

    // Converting the decimal color code to RGB values
    int r, g, b;
    decimalToRgb(decimalVal, &r, &g, &b);

    // Displaying the RGB values
    printf("RGB values for color code #%s is %d, %d, %d\n", colorCode, r, g, b);

    return 0;
}