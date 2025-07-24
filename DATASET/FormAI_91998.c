//FormAI DATASET v1.0 Category: Color Code Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert hexadecimal to integer
int hexToInt(char c) {
    if (c >= '0' && c <= '9') {
        return (int)c - '0';
    } else if (c >= 'A' && c <= 'F') {
        return (int)c - 'A' + 10;
    } else if (c >= 'a' && c <= 'f') {
        return (int)c - 'a' + 10;
    } else {
        return -1;
    }
}

int main() {
    char hex[8]; // input hexadecimal color code
    int r, g, b; // red, green, and blue values

    printf("Enter a hexadecimal color code (e.g. #FFAABB): ");
    scanf("%s", hex);

    // check if the input is valid
    if (strlen(hex) != 7 || hex[0] != '#') {
        printf("Invalid input.\n");
        return 1;
    }

    // convert the hexadecimal code to RGB
    r = (hexToInt(hex[1]) * 16) + hexToInt(hex[2]);
    g = (hexToInt(hex[3]) * 16) + hexToInt(hex[4]);
    b = (hexToInt(hex[5]) * 16) + hexToInt(hex[6]);

    // display the RGB values
    printf("RGB Value: (%d, %d, %d)\n", r, g, b);

    return 0;
}