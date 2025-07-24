//FormAI DATASET v1.0 Category: Color Code Converter ; Style: immersive
#include <stdio.h>

void cCodeToRGBA(int hexcode) {
    int red = (hexcode >> 16) & 0xFF;
    int green = (hexcode >> 8) & 0xFF;
    int blue = hexcode & 0xFF;
    printf("Red: %d, Green: %d, Blue: %d\n", red, green, blue);
}

void RGBAtoCCode(int red, int green, int blue) {
    int hexcode = ((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff);
    printf("C Color Code: #%06X\n", hexcode);
}

int main() {
    int choice;
    int hexcode;
    int red, green, blue;
    printf("Welcome to the C Color Code Converter! \nEnter 1 to convert C color code to RGB values \nEnter 2 to convert RGB values to C color code\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Please enter C color code (without '#'): ");
            scanf("%06X", &hexcode);
            cCodeToRGBA(hexcode);
            break;
        case 2:
            printf("Please enter red, green, and blue values (0-255)\n");
            printf("Red: ");
            scanf("%d", &red);
            printf("Green: ");
            scanf("%d", &green);
            printf("Blue: ");
            scanf("%d", &blue);
            RGBAtoCCode(red, green, blue);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
    return 0;
}