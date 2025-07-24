//FormAI DATASET v1.0 Category: Color Code Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define RGB_MIN_VAL 0
#define RGB_MAX_VAL 255

typedef struct {
    int red;
    int green;
    int blue;
} RGB;

int hexToDecimal(char hexValue);
int isValidHexCode(char* hexCode);
int hexToInt(char* hexString);
int intToHex(int intVal);
RGB hexToRgb(char* hexCode);
char* rgbToHex(int r, int g, int b);

int hexToDecimal(char hexValue) {
    if (hexValue >= '0' && hexValue <= '9') {
        return hexValue - '0';
    }
    else if (hexValue >= 'a' && hexValue <= 'f') {
        return hexValue - 'a' + 10;
    }
    else if (hexValue >= 'A' && hexValue <= 'F') {
        return hexValue - 'A' + 10;
    }
    else {
        return -1;
    }
}

int isValidHexCode(char* hexCode) {
    int len = strlen(hexCode);
    if (len != 6) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isxdigit(hexCode[i])) {
            return 0;
        }
    }
    return 1;
}

int hexToInt(char* hexString) {
    int decValue = 0;
    for (int i = 0; i < strlen(hexString); i++) {
        decValue += hexToDecimal(hexString[i]) * (1 << ((strlen(hexString) - i - 1) * 4));
    }
    return decValue;
}

int intToHex(int intVal) {
    return intVal >= 0 && intVal <= 9 ? intVal + '0' : intVal - 10 + 'a';
}

RGB hexToRgb(char* hexCode) {
    if (!isValidHexCode(hexCode)) {
        printf("%s is not a valid hexadecimal color code.", hexCode);
        RGB rgb = { 0, 0, 0 };
        return rgb;
    }
    int hexDec = hexToInt(hexCode);
    RGB rgb = {
        (hexDec >> 16) & 0xFF,
        (hexDec >> 8) & 0xFF,
        hexDec & 0xFF
    };
    return rgb;
}

char* rgbToHex(int r, int g, int b) {
    r = r < RGB_MIN_VAL ? RGB_MIN_VAL : (r > RGB_MAX_VAL ? RGB_MAX_VAL : r);
    g = g < RGB_MIN_VAL ? RGB_MIN_VAL : (g > RGB_MAX_VAL ? RGB_MAX_VAL : g);
    b = b < RGB_MIN_VAL ? RGB_MIN_VAL : (b > RGB_MAX_VAL ? RGB_MAX_VAL : b);
    char* hexCode = (char*)calloc(7, sizeof(char));
    sprintf(hexCode, "#%02x%02x%02x", r, g, b);
    return hexCode;
}

int main() {
    // RGB to Hexadecimal Conversion
    int r = 255, g = 255, b = 0;
    char* hexCode = rgbToHex(r, g, b);
    printf("RGB: (%d, %d, %d)\nHex Code: %s\n", r, g, b, hexCode);

    // Hexadecimal to RGB Conversion
    char* hex = "#00ff00";
    RGB rgb = hexToRgb(hex);
    printf("Hex Code: %s\nRGB: (%d, %d, %d)\n", hex, rgb.red, rgb.green, rgb.blue);

    free(hexCode);
    return 0;
}