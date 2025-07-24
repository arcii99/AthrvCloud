//FormAI DATASET v1.0 Category: Color Code Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hexToDecimal(char hex[]) {
    int decimal = 0, power = 1;
    int len = strlen(hex);
    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - 48) * power;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 55) * power;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 87) * power;
        }
        power *= 16;
    }
    return decimal;
}

void decimalToRGB(int decimal, int* red, int* green, int* blue) {
    *red = (decimal >> 16) & 0xFF;
    *green = (decimal >> 8) & 0xFF;
    *blue = decimal & 0xFF;
}

void hexToRGB(char* hex, int* red, int* green, int* blue) {
    int decimal = hexToDecimal(hex);
    decimalToRGB(decimal, red, green, blue);
}

void displayRGB(int red, int green, int blue) {
    printf("Red: %d\n", red);
    printf("Green: %d\n", green);
    printf("Blue: %d\n", blue);
}

int main() {
    char hex[7];
    int red, green, blue;
    printf("Enter a 6 digit hexadecimal color code: ");
    scanf("%s", hex);
    hexToRGB(hex, &red, &green, &blue);
    printf("The RGB color for #%s is:\n", hex);
    displayRGB(red, green, blue);
    return 0;
}