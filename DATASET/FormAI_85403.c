//FormAI DATASET v1.0 Category: Color Code Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int red, blue, green;    // Declare variables for storing RGB values
    float cyan, magenta, yellow, black;    // Declare variables for storing CMYK values

    // Take user input for RGB values
    printf("Enter the RED value (0-255): ");
    scanf("%d", &red);
    printf("Enter the GREEN value (0-255): ");
    scanf("%d", &green);
    printf("Enter the BLUE value (0-255): ");
    scanf("%d", &blue);

    // Convert RGB to CMYK
    float r = red / 255.0;
    float g = green / 255.0;
    float b = blue / 255.0;

    // Find the maximum value between R, G and B to calculate K value
    float max = r > g ? r : g;
    max = max > b ? max : b;

    cyan = (max - r) / max;
    magenta = (max - g) / max;
    yellow = (max - b) / max;
    black = 1 - max;

    printf("\nCMYK values: C=%.2f M=%.2f Y=%.2f K=%.2f", cyan, magenta, yellow, black);

    return 0;
}