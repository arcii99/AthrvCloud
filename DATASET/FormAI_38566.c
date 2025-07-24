//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Claude Shannon
#include<stdio.h>
#include<string.h>

// function to convert a single hexadecimal character to decimal
int hexToDecimal(char hex) {
    if(isdigit(hex)) {
        return hex - '0';
    } else {
        return toupper(hex) - 'A' + 10;
    }
}

// function to convert a hexadecimal color code to an RGB value
void hexToRgb(char *hexCode, int *R, int *G, int *B) {
    // remove # symbol if present
    if(hexCode[0] == '#') {
        hexCode += 1;
    }
    int len = strlen(hexCode);
    // check if code is valid length (6 digits)
    if(len != 6 || strspn(hexCode, "0123456789ABCDEFabcdef") != len) {
        printf("Invalid hexadecimal color code\n");
        return;
    }
    // convert to RGB values
    *R = hexToDecimal(hexCode[0]) * 16 + hexToDecimal(hexCode[1]);
    *G = hexToDecimal(hexCode[2]) * 16 + hexToDecimal(hexCode[3]);
    *B = hexToDecimal(hexCode[4]) * 16 + hexToDecimal(hexCode[5]);
}

// function to convert an RGB value to a hexadecimal color code
void rgbToHex(int R, int G, int B, char *hexCode) {
    sprintf(hexCode, "#%02X%02X%02X", R, G, B);
}

int main() {
    // example usage
    char hexCode[7] = "#FFA500";
    int R, G, B;
    hexToRgb(hexCode, &R, &G, &B);
    printf("The RGB values are: %d, %d, %d\n", R, G, B);

    int red = 255, green = 0, blue = 255;
    char hex[7];
    rgbToHex(red, green, blue, hex);
    printf("The hexadecimal color code is: %s\n", hex);

    return 0;
}