//FormAI DATASET v1.0 Category: Color Code Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // Ask the user for input
    printf("Please enter the color you want to convert in hexadecimal format: ");

    // Create a variable to store the user input
    char hex[7];
    scanf("%6s", hex);

    // Check if the input is valid
    if (strlen(hex) != 6) {
        printf("Invalid input. Please enter a valid color code.\n");
        return 0;
    }

    // Convert the hexadecimal color code to RGB color code
    int r = (int)strtol(&hex[0], NULL, 16);
    int g = (int)strtol(&hex[2], NULL, 16);
    int b = (int)strtol(&hex[4], NULL, 16);

    // Print the RGB color code
    printf("The RGB color code for %s is (%d, %d, %d)\n", hex, r, g, b);

    return 0; 
}