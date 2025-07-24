//FormAI DATASET v1.0 Category: Color Code Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// function to convert RGB color code to hexadecimal color code
char* RGBtoHex(int red, int green, int blue) {
    char* hexCode = (char*) malloc(sizeof(char) * 7); // allocate memory for hex code (6 digits + '\0')
    sprintf(hexCode, "#%02X%02X%02X", red, green, blue); // format code using sprintf
    return hexCode; // return the hex code
}

// function to convert hexadecimal color code to RGB color code
void HextoRGB(char* hexCode, int* red, int* green, int* blue) {
    sscanf(hexCode, "#%02X%02X%02X", red, green, blue); // scan the hex code and store the values in red, green and blue pointers
}

// main function to test the code
int main() {
    int red, green, blue;
    char hexCode[7];
    
    // convert RGB color code to hexadecimal color code
    red = 255;
    green = 165;
    blue = 0;
    char* hexCode1 = RGBtoHex(red, green, blue);
    printf("RGB color code (%d,%d,%d) in hexadecimal format is %s.\n", red, green, blue, hexCode1);
    free(hexCode1); // free the memory
    
    // convert hexadecimal color code to RGB color code
    strcpy(hexCode, "#800080"); // set the hex code
    HextoRGB(hexCode, &red, &green, &blue);
    printf("Hexadecimal color code %s in RGB format is (%d,%d,%d).\n", hexCode, red, green, blue);
    
    return 0;
}