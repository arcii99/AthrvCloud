//FormAI DATASET v1.0 Category: Color Code Converter ; Style: beginner-friendly
#include<stdio.h>

// function to convert hexadecimal code to RGB color
void convert_hex_to_rgb(char hex_color[], int *r, int *g, int *b) {
    // converting hex string to integer values
    sscanf(hex_color, "%02x%02x%02x", r, g, b);
}

// function to convert RGB color to hexadecimal code
void convert_rgb_to_hex(int r, int g, int b, char hex_color[]) {
    // converting integer values to hex string
    sprintf(hex_color, "#%02x%02x%02x", r, g, b);
}

int main() {

    char hex_color[] = "#FFA500"; // initial hexadecimal color code
    int r, g, b;

    // printing initial hexadecimal color code
    printf("Initial Hexadecimal Color Code: %s\n", hex_color);

    // converting hexadecimal code to RGB color
    convert_hex_to_rgb(hex_color, &r, &g, &b);

    // printing RGB color values
    printf("Red: %d\nGreen: %d\nBlue: %d\n", r, g, b);

    // modifying RGB color values
    r -= 20;
    g += 25;
    b += 10;

    // printing modified RGB color values
    printf("Modified RGB Values after applying filter:\n");
    printf("Red: %d\nGreen: %d\nBlue: %d\n", r, g, b);

    // converting modified RGB color back to hexadecimal code
    convert_rgb_to_hex(r, g, b, hex_color);

    // printing final hexadecimal color code
    printf("Final Hexadecimal Color Code: %s\n", hex_color);

    return 0;
}