//FormAI DATASET v1.0 Category: Color Code Converter ; Style: energetic
#include <stdio.h>

int main() {
    char hex[7]; // create a char array to store the hexadecimal code
    int r, g, b; // create variables for the red, green, and blue colors

    printf("Enter the hexadecimal color code: #"); 
    scanf("%s", hex); // prompt user to enter the hexadecimal code
    sscanf(hex, "%02x%02x%02x", &r, &g, &b); // convert the hexadecimal code to RGB values

    printf("The RGB values for %s are: %d, %d, %d\n", hex, r, g, b); // print the RGB values

    return 0; // end the program
}