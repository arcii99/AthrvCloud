//FormAI DATASET v1.0 Category: Color Code Converter ; Style: expert-level
#include <stdio.h>
#include <string.h>

// Function prototypes
void hexToRgb(char *hex, int *r, int *g, int *b);
void rgbToHex(int r, int g, int b, char *hex);
void rgbToCmyk(int r, int g, int b, double *c, double *m, double *y, double *k);

int main() {
    char colorCode[8];
    int r, g, b;
    double c, m, y, k;
    
    printf("Enter a color code (hex or RGB): ");
    scanf("%s", colorCode);
    
    // Check if input is hex code
    if (colorCode[0] == '#') {
        hexToRgb(colorCode + 1, &r, &g, &b);
    }
    // Check if input is RGB code
    else if (colorCode[0] == '(') {
        sscanf(colorCode, "(%d,%d,%d)", &r, &g, &b);
    }
    else {
        printf("Invalid input.\n");
        return 1; // Exit program with error code
    }
    
    // Print RGB values and convert to hex and CMYK
    printf("RGB: %d,%d,%d\n", r, g, b);
    
    char hexCode[8];
    rgbToHex(r, g, b, hexCode);
    printf("Hex: #%s\n", hexCode);
    
    rgbToCmyk(r, g, b, &c, &m, &y, &k);
    printf("CMYK: %.2f,%.2f,%.2f,%.2f\n", c, m, y, k);
    
    return 0; // Exit program with success code
}

// Converts a hex code to RGB values
void hexToRgb(char *hex, int *r, int *g, int *b) {
    sscanf(hex, "%02x%02x%02x", r, g, b);
}

// Converts RGB values to a hex code
void rgbToHex(int r, int g, int b, char *hex) {
    sprintf(hex, "%02X%02X%02X", r, g, b);
}

// Converts RGB values to CMYK values
void rgbToCmyk(int r, int g, int b, double *c, double *m, double *y, double *k) {
    double dr = r / 255.0;
    double dg = g / 255.0;
    double db = b / 255.0;
    
    *k = 1 - fmax(fmax(dr, dg), db);
    *c = (*k == 1) ? 0 : (1 - dr - *k) / (1 - *k);
    *m = (*k == 1) ? 0 : (1 - dg - *k) / (1 - *k);
    *y = (*k == 1) ? 0 : (1 - db - *k) / (1 - *k);
}