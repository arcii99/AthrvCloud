//FormAI DATASET v1.0 Category: Color Code Converter ; Style: accurate
#include <stdio.h>

// Function to convert RGB values to hex code
char* rgbToHex(int r, int g, int b){
    // Allocate memory for hex code
    char* hex = (char*) malloc(sizeof(char) * 7);
    // Convert RGB values to hex code
    sprintf(hex, "#%02x%02x%02x", r, g, b);
    // Return hex code
    return hex;
}

// Function to convert hex code to RGB values
void hexToRgb(char* hex, int* r, int* g, int* b){
    // Convert hex code to RGB values
    sscanf(hex, "#%02x%02x%02x", r, g, b);
}

int main(){
    int r = 255, g = 165, b = 0;
    // Convert RGB values to hex code and print
    char* hex = rgbToHex(r, g, b);
    printf("RGB values (%d,%d,%d) in HEX code: %s\n", r, g, b, hex);
    // Convert hex code to RGB values and print
    hexToRgb(hex, &r, &g, &b);
    printf("HEX code %s in RGB values: (%d,%d,%d)\n", hex, r, g, b);
    // Free memory allocated for hex code
    free(hex);
    return 0;
}