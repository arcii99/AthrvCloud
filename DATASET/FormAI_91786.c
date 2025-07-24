//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Donald Knuth
#include <stdio.h>

// Define the RGB struct to handle red, green, and blue values
typedef struct {
    unsigned char r; // Red value
    unsigned char g; // Green value
    unsigned char b; // Blue value
} RGB;

// Define the HEX struct to handle hexadecimal color codes
typedef struct {
    char hex[7]; // String of 6 hexadecimal digits (e.g. "#000000" for black)
} HEX;

// Function to convert RGB to HEX
HEX rgb_to_hex(RGB rgb) {
    char hex_string[7]; // Array to hold converted hexadecimal code
    sprintf(hex_string, "#%02X%02X%02X", rgb.r, rgb.g, rgb.b);
    HEX hex;
    for(int i = 0; i < 7; i++) {
        hex.hex[i] = hex_string[i];
    }
    return hex;
}

// Function to convert HEX to RGB
RGB hex_to_rgb(HEX hex) {
    // Convert hexadecimal code to individual red, green, and blue values
    unsigned int r, g, b;
    sscanf(hex.hex, "#%02x%02x%02x", &r, &g, &b);
    // Create RGB struct with converted values
    RGB rgb;
    rgb.r = r;
    rgb.g = g;
    rgb.b = b;
    return rgb;
}

int main() {
    RGB rgb = {255, 255, 255}; // Initialize RGB values as white (255, 255, 255)
    HEX hex = rgb_to_hex(rgb); // Convert RGB to hexadecimal and store in HEX struct
    printf("RGB (%d, %d, %d) converted to HEX is %s\n", rgb.r, rgb.g, rgb.b, hex.hex);
    HEX hex_input = {"#000000"}; // Initialize HEX string as black
    RGB rgb_output = hex_to_rgb(hex_input); // Convert HEX to RGB and store in RGB struct
    printf("HEX %s converted to RGB is (%d, %d, %d)\n", hex_input.hex, rgb_output.r, rgb_output.g, rgb_output.b);
    return 0;
}