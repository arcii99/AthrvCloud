//FormAI DATASET v1.0 Category: Color Code Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rgbToHex(int red, int green, int blue) {
    char hexValue[7];
    sprintf(hexValue, "#%02X%02X%02X", red, green, blue);
    printf("RGB color (%d, %d, %d) converted to HEX color %s", red, green, blue, hexValue);
}

void hexToRgb(char* hexValue) {
    int red, green, blue;
    sscanf(hexValue, "#%02X%02X%02X", &red, &green, &blue);
    printf("HEX color %s converted to RGB color (%d, %d, %d)", hexValue, red, green, blue);
}

int main() {
    char userInput[10];
    printf("Please enter a color in RGB or HEX format: ");
    scanf("%s", userInput);

    if (userInput[0] == '#') {
        hexToRgb(userInput);
    }
    else {
        char* element;
        element = strtok(userInput, ",");
        int red = atoi(element);
        element = strtok(NULL, ",");
        int green = atoi(element);
        element = strtok(NULL, ",");
        int blue = atoi(element);
        rgbToHex(red, green, blue);
    }

    return 0;
}