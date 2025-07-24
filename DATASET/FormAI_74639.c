//FormAI DATASET v1.0 Category: Color Code Converter ; Style: futuristic
#include<stdio.h>

int main() {
    int hex[6], rgb[3];
    char color_code[7];

    printf("Enter a 6 digit color code in hexadecimal format (e.g. FFFFFF): ");
    scanf("%s", color_code);

    // Converting hexadecimal color code to RGB values
    for (int i = 0; i < 6; i += 2) {
        sscanf(&color_code[i], "%2x", &hex[i]);
        rgb[i/2] = hex[i];
    }

    // Printing input color code
    printf("\nInput Color Code (Hexadecimal): #%s\n", color_code);

    // Print converted RGB values
    printf("\nEquivalent RGB values: (%d, %d, %d)\n", rgb[0], rgb[1], rgb[2]);

    return 0;
}