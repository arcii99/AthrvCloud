//FormAI DATASET v1.0 Category: Color Code Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert RGB values to HEX code
char* RGBtoHEX(int R, int G, int B) {
    // allocate memory to store HEX code
    char* HEX = (char*) malloc(sizeof(char)*7);
    
    // convert individual RGB values to HEX components
    sprintf(HEX, "#%02X%02X%02X", R, G, B);
    
    // return HEX code
    return HEX;
}

// function to convert HEX code to RGB values
int* HEXtoRGB(char* HEX) {
    // allocate memory to store RGB values
    int* RGB = (int*) malloc(sizeof(int)*3);
    
    // convert HEX code to individual RGB components
    sscanf(HEX, "#%02X%02X%02X", &RGB[0], &RGB[1], &RGB[2]);
    
    // return RGB values
    return RGB;
}

// main function to test color code converter
int main(int argc, char* argv[]) {
    // initial RGB values
    int R = 255, G = 128, B = 0;
    
    // convert RGB values to HEX code and print
    char* HEX = RGBtoHEX(R, G, B);
    printf("Initial color: RGB(%d, %d, %d) HEX(%s)\n", R, G, B, HEX);
    
    // convert HEX code to RGB values and print
    int* RGB = HEXtoRGB(HEX);
    printf("Converted color: RGB(%d, %d, %d) from HEX code (%s)\n", RGB[0], RGB[1], RGB[2], HEX);
    
    // free allocated memory
    free(HEX);
    free(RGB);
    
    return 0;
}