//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// function prototype
void convertColor(char colorCode[]);

int main() {
    char colorCode[7]; // to store the hex color code
    printf("Enter hex color code (must be 6 digits): ");
    fgets(colorCode, 8, stdin); // get the user input
    convertColor(colorCode); // call the convertColor function
    return 0;
}

void convertColor(char colorCode[]) {
    int r, g, b; // to store the red, green and blue values
    char rStr[3], gStr[3], bStr[3]; // to store the converted values in string format
    // convert the first two digits to red value
    r = (int)strtol(colorCode, NULL, 16);
    sprintf(rStr, "%d", r); // convert red value to string

    // convert the third and fourth digits to green value
    g = (int)strtol(colorCode + 2, NULL, 16);
    sprintf(gStr, "%d", g); // convert green value to string

    // convert the fifth and sixth digits to blue value
    b = (int)strtol(colorCode + 4, NULL, 16);
    sprintf(bStr, "%d", b); // convert blue value to string
    
    // print the RGB values
    printf("RGB Color Values: (%s,%s,%s)\n", rStr, gStr, bStr);
}