//FormAI DATASET v1.0 Category: Color Code Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert RGB values to hex code
char* RGBtoHEX(int r, int g, int b){
    char* hex = (char*)malloc(sizeof(char) * 7);
    // Use sprintf to convert RGB values to hexadecimal
    sprintf(hex, "#%02x%02x%02x", r, g, b);
    return hex;
}

// Function to convert hex code to RGB values
void HEXtoRGB(char* hex, int* r, int* g, int* b){
    // Check if hex is a valid code
    if (strlen(hex) != 7){
        printf("Invalid color code.\n");
        return;
    }
    // Use sscanf to convert hex code to RGB values
    sscanf(hex, "#%2x%2x%2x", r, g, b);
}

int main(){
    // Variables to store RGB values and hex code
    int r = 0, g = 0, b = 0;
    char hex[7];
    printf("Enter RGB values (0-255) separated by space: ");
    scanf("%d %d %d", &r, &g, &b);
    // Call RGBtoHEX function and print the hex code
    printf("Hex code: %s\n", RGBtoHEX(r, g, b));
    printf("Enter hex code (including # symbol): ");
    scanf("%s", hex);
    // Call HEXtoRGB function and print the RGB values
    HEXtoRGB(hex, &r, &g, &b);
    printf("RGB values: %d %d %d\n", r, g, b);
    return 0;
}