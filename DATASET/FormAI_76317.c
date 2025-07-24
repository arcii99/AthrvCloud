//FormAI DATASET v1.0 Category: Color Code Converter ; Style: peaceful
#include<stdio.h>

// Function to convert RGB color code to HEX color code
void RGB_to_HEX(int r, int g, int b) {
    int hex_num;
    char hex_code[7];
    // Converting the color codes to hexadecimal using bitwise operators
    hex_num = (r << 16) + (g << 8) + b;
    // Converting the hex number to hex code
    sprintf(hex_code, "#%06X", hex_num);
    printf("The HEX color code is: %s\n", hex_code);
}

// Function to convert HEX color code to RGB color code
void HEX_to_RGB(char hex_val[]) {
    // Converting the hex code to RGB color codes
    unsigned int r, g, b;
    sscanf(hex_val, "#%02x%02x%02x", &r, &g, &b);
    printf("The RGB color code is: (%d,%d,%d)\n", r, g, b);
}

int main() {
    char input_code[10];
    int r, g, b;
    printf("Enter RGB or HEX color code: ");
    scanf("%s", &input_code);
    if (input_code[0] == '#') {
        // If input code is HEX then converting it to RGB
        HEX_to_RGB(input_code);
    } else {
        // If input code is RGB then converting it to HEX
        sscanf(input_code, "%d,%d,%d", &r, &g, &b);
        RGB_to_HEX(r, g, b);
    }
    return 0;
}