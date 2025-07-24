//FormAI DATASET v1.0 Category: Color Code Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

int hexCharToInt(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    else if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    else {
        return -1;
    }
}

int main() {
    char hexColor[7];
    int red, green, blue;

    printf("Enter a 6-digit hexadecimal color code: ");
    scanf("%s", hexColor);

    // Convert hexadecimal color code to RGB
    red = hexCharToInt(hexColor[0]) * 16 + hexCharToInt(hexColor[1]);
    green = hexCharToInt(hexColor[2]) * 16 + hexCharToInt(hexColor[3]);
    blue = hexCharToInt(hexColor[4]) * 16 + hexCharToInt(hexColor[5]);

    // Print RGB values
    printf("Red: %d\n", red);
    printf("Green: %d\n", green);
    printf("Blue: %d\n", blue);

    return 0;
}