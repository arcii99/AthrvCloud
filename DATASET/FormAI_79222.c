//FormAI DATASET v1.0 Category: Color Code Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert color code from hexadecimal to RGB
void hex_to_rgb(char hexcode[], int* r, int* g, int* b) {
    // Extracting Red, Green, and Blue values separately 
    sscanf(hexcode, "%02X%02X%02X", r, g, b);
}

// Function to convert color code from RGB to hexadecimal
void rgb_to_hex(int r, int g, int b, char hexcode[]) {
    // Creating a string of hexadecimal digits using sprintf() function 
    sprintf(hexcode, "#%02X%02X%02X", r, g, b);
}

int main() {
    int choice, r_val, g_val, b_val;
    char hex[8], hexcode[8];
    
    while(1) {
        // Menu-driven interface to choose the conversion type
        printf("\n\n------- Color Code Converter -------\n");
        printf("Choose the conversion type:\n");
        printf("1. Hexadecimal to RGB\n");
        printf("2. RGB to Hexadecimal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: // Conversion from hexadecimal to RGB
                printf("\nEnter the hexadecimal color code: ");
                scanf("%s", hex);
                hex_to_rgb(hex, &r_val, &g_val, &b_val);
                printf("\nRGB color code: %d, %d, %d", r_val, g_val, b_val);
                break;
                
            case 2: // Conversion from RGB to hexadecimal
                printf("\nEnter the RGB values (separated by comma): ");
                scanf("%d,%d,%d", &r_val, &g_val, &b_val);
                rgb_to_hex(r_val, g_val, b_val, hexcode);
                printf("\nHexadecimal color code: %s", hexcode);
                break;
                
            case 3: // Exit
                printf("\nExiting...");
                exit(0);
                break;
            
            default:
                printf("\nInvalid choice. Please try again.");
        }
    }
    return 0;
}