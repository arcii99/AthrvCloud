//FormAI DATASET v1.0 Category: Color Code Converter ; Style: visionary
#include <stdio.h>

// function to convert RGB to HEX
void RGBtoHEX(int red, int green, int blue) {
    char hex[7]; // initialize a char array to hold HEX code

    // convert red, green and blue to HEX and store in hex array
    sprintf(hex, "#%02X%02X%02X", red, green, blue);

    printf("RGB color: (%d, %d, %d)\n", red, green, blue);
    printf("Equivalent HEX color code: %s\n", hex);
}

// function to convert HEX to RGB
void HEXtoRGB(char hex[]) {
    int red, green, blue;
    
    // convert hex string to integers for red, green and blue
    sscanf(hex, "#%02X%02X%02X", &red, &green, &blue);

    printf("HEX color code: %s\n", hex);
    printf("Equivalent RGB color: (%d, %d, %d)\n", red, green, blue);
}

int main() {
    int red, green, blue;
    char hex[7];

    // get user input for color
    printf("Enter RGB color code (e.g. 255 255 255): ");
    scanf("%d %d %d", &red, &green, &blue);

    RGBtoHEX(red, green, blue); // convert RGB to HEX

    // get user input for color
    printf("\nEnter HEX color code (e.g. #FFFFFF): ");
    scanf("%s", hex);

    HEXtoRGB(hex); // convert HEX to RGB

    return 0; // exit program
}