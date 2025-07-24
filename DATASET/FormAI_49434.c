//FormAI DATASET v1.0 Category: Color Code Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert color codes from hex to RGB
void hex_to_rgb(char hex[], int *r, int *g, int *b) {
    sscanf(hex, "%02x%02x%02x", r, g, b);
}

// function to convert color codes from RGB to hex
void rgb_to_hex(int r, int g, int b, char hex[]) {
    sprintf(hex, "#%02x%02x%02x", r, g, b);
}

int main() {
    char hex[7], choice;
    int r, g, b;
    
    printf("Enter a color code in hexadecimal format (Example: #FFFFFF): ");
    scanf("%s", hex);
    
    // ask user for conversion choice
    printf("Enter the conversion you want to perform:\n");
    printf("1. Hex to RGB conversion\n2. RGB to Hex conversion\n");
    scanf(" %c", &choice);
    
    switch (choice) {
        case '1':
            hex_to_rgb(hex, &r, &g, &b);
            printf("RGB values: %d, %d, %d\n", r, g, b);
            break;
        case '2':
            sscanf(hex+1, "%2x%2x%2x", &r, &g, &b);
            printf("Hex code: %s\n", hex);
            printf("RGB values: %d, %d, %d\n", r, g, b);
            break;
        default:
            printf("Invalid choice.\n");
            exit(1);
    }
    
    return 0;
}