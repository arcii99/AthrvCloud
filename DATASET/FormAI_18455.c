//FormAI DATASET v1.0 Category: Color Code Converter ; Style: shape shifting
#include <stdio.h>

void hexToRgb(char hex[], int *red, int *green, int *blue) {
    // Convert hex string to RGB values
    sscanf(hex, "%02x%02x%02x", red, green, blue);
}

void rgbToHex(int red, int green, int blue, char hex[]) {
    // Convert RGB values to hex string
    sprintf(hex, "#%02x%02x%02x", red, green, blue); 
}

int main() {
    char input[10];
    int red, green, blue;

    printf("Enter the color code (hex or RGB): ");
    scanf("%s", input);

    // If input is in hex format
    if (input[0] == '#' && strlen(input) == 7) {
        hexToRgb(input+1, &red, &green, &blue);
        printf("RGB Value: (%d,%d,%d)\n", red, green, blue);
    }

    // If input is in RGB format
    else if (input[0] == '(' && input[strlen(input)-1] == ')') {
        sscanf(input+1, "%d,%d,%d", &red, &green, &blue);
        char hex[7];
        rgbToHex(red, green, blue, hex);
        printf("Hex Value: %s\n", hex);
    }

    // Invalid input
    else {
        printf("Invalid input format.\n");
    }

    return 0;
}