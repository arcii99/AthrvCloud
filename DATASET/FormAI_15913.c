//FormAI DATASET v1.0 Category: Color Code Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// I am a Color Code Converter Program

// Function to convert RGB color code to HEX color code
char* rgb_to_hex(int r, int g, int b) {
    char* hex_code = (char*) malloc(sizeof(char) * 7); // allocate memory for hex code

    // convert RGB values to HEX format and store in hex_code
    sprintf(hex_code, "#%02X%02X%02X", r, g, b);

    return hex_code;
}

// Function to convert HEX color code to RGB color code
void hex_to_rgb(char* hex_code, int* r, int* g, int* b) {
    // skip the # character in hex code
    hex_code += 1;

    // extract R, G, B values from hex code and store in r, g, b respectively
    sscanf(hex_code, "%2x%2x%2x", r, g, b);
}

int main() {
    printf("Welcome to the Color Code Converter!\n\n");

    // RGB to HEX example
    int r = 255, g = 165, b = 0;
    char* hex_code = rgb_to_hex(r, g, b);
    printf("RGB Color Code: (%d, %d, %d)\n", r, g, b);
    printf("HEX Color Code: %s\n\n", hex_code);
    free(hex_code);

    // HEX to RGB example
    char hex[] = "#00FF7F";
    int rr, gg, bb;
    hex_to_rgb(hex, &rr, &gg, &bb);
    printf("HEX Color Code: %s\n", hex);
    printf("RGB Color Code: (%d, %d, %d)\n\n", rr, gg, bb);

    printf("Thank you for using the Color Code Converter!");

    return 0;
}