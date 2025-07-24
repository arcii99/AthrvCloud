//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

/* This program converts RGB values to their nearest color code. */
int main(void) {

    // Define and initialize the RGB values
    unsigned char red = 0;
    unsigned char green = 255;
    unsigned char blue = 0;
    
    // Define variables to store the closest color code and its distance
    unsigned short closestCode = 0;
    float closestDistance = 442.8; // This is the maximum possible distance in RGB space
    
    // Define the color codes and their RGB values
    unsigned short colorCodes[8] = {30, 31, 32, 33, 34, 35, 36, 37};
    unsigned char colorValues[8][3] = {
        {0, 0, 0},
        {128, 0, 0},
        {0, 128, 0},
        {128, 128, 0},
        {0, 0, 128},
        {128, 0, 128},
        {0, 128, 128},
        {192, 192, 192}
    };
    
    // Loop through all color codes and find the closest one
    for (int i = 0; i < 8; i++) {
        // Calculate the distance between the RGB values and the color code
        float distance = sqrt(pow(red - colorValues[i][0], 2) +
                              pow(green - colorValues[i][1], 2) +
                              pow(blue - colorValues[i][2], 2));
        // Check if the distance is closer than the previous closest distance
        if (distance < closestDistance) {
            closestDistance = distance;
            closestCode = colorCodes[i];
        }
    }
    
    // Print the closest color code
    printf("\033[%hhu;1m", closestCode);
    printf("Hello, world!\n");
    printf("\033[0m"); // Reset the color code
    
    return 0;
}