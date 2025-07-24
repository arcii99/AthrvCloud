//FormAI DATASET v1.0 Category: Color Code Converter ; Style: configurable
#include <stdio.h>
#include <string.h>

// function prototypes
void convertToRGB(char*);
void convertToHex(char*);

int main() {
    // variables to store user input and conversion choice
    char input[10];
    int choice;
    
    // prompt user for input and conversion choice
    printf("Enter color code in RGB or hex format: ");
    scanf("%s", input);
    printf("Enter 1 to convert to hex, 2 to convert to RGB: ");
    scanf("%d", &choice);
    
    // perform selected conversion
    if (choice == 1) {
        convertToHex(input);
    } else if (choice == 2) {
        convertToRGB(input);
    } else {
        printf("Invalid choice. Please enter 1 or 2.");
    }
    
    return 0;
}

// function to convert RGB to hex
void convertToHex(char* color) {
    int r, g, b;
    char hex[10];
    sscanf(color, "%d,%d,%d", &r, &g, &b);
    sprintf(hex, "#%02X%02X%02X", r, g, b);
    printf("Hex code: %s", hex);
}

// function to convert hex to RGB
void convertToRGB(char* color) {
    int r, g, b;
    sscanf(color, "#%02X%02X%02X", &r, &g, &b);
    printf("RGB code: %d,%d,%d", r, g, b);
}