//FormAI DATASET v1.0 Category: Color Code Converter ; Style: enthusiastic
// Are you tired of manually converting hexadecimal color codes to RGB values? 
// Well, look no further because this C Color Code Converter is here to save the day!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define our color struct for storing RGB values
typedef struct {
    int r;
    int g;
    int b;
} color;

// define function to convert hexadecimal code to RGB values
color hexToRGB(char hex[7]) {
    color rgb;
    // convert each hex value to an integer with base 16
    rgb.r = strtol(&hex[1], NULL, 16);
    rgb.g = strtol(&hex[3], NULL, 16);
    rgb.b = strtol(&hex[5], NULL, 16);
    return rgb;
}

int main() {
    char hex[7];
    color rgb;
    printf("Welcome to C Color Code Converter!\n");
    printf("Please enter a hexadecimal color code (in the format #RRGGBB): ");
    scanf("%s", hex);
    // check if user inputted a valid hexadecimal code
    if (hex[0] == '#' && strlen(hex) == 7) {
        rgb = hexToRGB(hex);
        // print out the RGB values
        printf("The RGB values for %s are: (%d, %d, %d)\n", hex, rgb.r, rgb.g, rgb.b);
    } else {
        printf("Invalid hexadecimal color code.\n");
    }
    return 0;
}