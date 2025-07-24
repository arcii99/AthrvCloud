//FormAI DATASET v1.0 Category: Color Code Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Function to convert RGB value to hex code
char* rgb_to_hex(int red, int green, int blue) {
    char* hex_code = (char*) malloc(7 * sizeof(char));   // Allocate memory for hex code
    // Format hex code string
    sprintf(hex_code, "#%02X%02X%02X", red, green, blue);
    return hex_code;
}

// Function to convert hex code to RGB value
void hex_to_rgb(char hex_code[], int* red, int* green, int* blue) {
    sscanf(&hex_code[1], "%02x%02x%02x", red, green, blue);
}

int main() {
    int red = 255;
    int green = 165;
    int blue = 0;

    char* hex_code = rgb_to_hex(red, green, blue);
    printf("RGB value: (%d, %d, %d)\n", red, green, blue);
    printf("Hex code: %s\n", hex_code);

    free(hex_code);   // Free allocated memory

    char hex_input[7] = "#FFA500";
    hex_to_rgb(hex_input, &red, &green, &blue);
    printf("Hex code: %s\n", hex_input);
    printf("RGB value: (%d, %d, %d)\n", red, green, blue);

    return 0;   // Return success
}