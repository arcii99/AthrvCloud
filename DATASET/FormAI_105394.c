//FormAI DATASET v1.0 Category: Color Code Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Function to convert RGB color code to hexadecimal
char* convertRgbToHex(int r, int g, int b) {
    char* hexColor = (char*) malloc(sizeof(char) * 7);
    sprintf(hexColor, "#%02x%02x%02x", r, g, b);
    return hexColor;
}

// Function to convert hexadecimal color code to RGB
void convertHexToRgb(char* hexColor, int* r, int* g, int* b) {
    sscanf(hexColor, "#%02x%02x%02x", r, g, b);
}

int main() {
    int option;
    printf("Color Code Converter\n");
    printf("1. Convert RGB to Hex\n");
    printf("2. Convert Hex to RGB\n");
    printf("Enter your option: ");
    scanf("%d", &option);

    if (option == 1) {
        int r, g, b;
        printf("Enter RGB color code (separated by spaces): ");
        scanf("%d %d %d", &r, &g, &b);
        char* hexColor = convertRgbToHex(r, g, b);
        printf("Hexadecimal color code: %s\n", hexColor);
        free(hexColor);
    }
    else if (option == 2) {
        char hexColor[7];
        printf("Enter hexadecimal color code: ");
        scanf("%s", hexColor);
        int r, g, b;
        convertHexToRgb(hexColor, &r, &g, &b);
        printf("RGB color code: %d %d %d\n", r, g, b);
    }
    else {
        printf("Invalid option selected.\n");
    }

    return 0;
}