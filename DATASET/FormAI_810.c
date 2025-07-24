//FormAI DATASET v1.0 Category: Color Code Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert RGB value to Hexadecimal string
char* rgb_to_hex(int r, int g, int b){
    char* hex = malloc(sizeof(char) * 7);
    sprintf(hex, "#%02X%02X%02X", r, g, b);
    return hex;
}

// Function to convert Hexadecimal string to RGB value
void hex_to_rgb(char* hex, int* r, int* g, int* b){
    *r = strtol(hex+1, NULL, 16) >> 16;
    *g = strtol(hex+1, NULL, 16) >> 8 & 0xFF;
    *b = strtol(hex+1, NULL, 16) & 0xFF;
}

// Main function to test the conversion functions
int main(){

    // Convert RGB to Hexadecimal
    int r = 87, g = 199, b = 255;
    char* hex = rgb_to_hex(r, g, b);
    printf("RGB(%d, %d, %d) is converted to Hexadecimal %s\n", r, g, b, hex);

    // Convert Hexadecimal to RGB
    char* hexVal = "#57C7FF";
    int red = 0, green = 0, blue = 0;
    hex_to_rgb(hexVal, &red, &green, &blue);
    printf("Hexadecimal %s is converted to RGB(%d, %d, %d)\n", hexVal, red, green, blue);

    return 0;
}