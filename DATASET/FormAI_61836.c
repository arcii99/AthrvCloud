//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drawPixel(char pixel) {
    if(pixel == '1') {
        printf("\u2588");
    } else {
        printf(" ");
    }
}

int main() {
    // Set seed for random number generator
    srand(time(NULL));

    // Define color array
    char colors[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    // Define color variables
    char color1;
    char color2;
    char color3;

    // Define pixel values
    char pixel1;
    char pixel2;
    char pixel3;

    // Loop through 10 rows of pixels
    for(int i = 0; i < 10; i++) {
        // Loop through 30 columns of pixels
        for(int j = 0; j < 30; j++) {
            // Select random colors for each pixel
            color1 = colors[rand() % 10];
            color2 = colors[rand() % 10];
            color3 = colors[rand() % 10];

            // Set pixel value based on color
            if(color1 == '1' || color2 == '1' || color3 == '1') {
                pixel1 = '1';
            } else {
                pixel1 = '0';
            }

            if(color1 == '2' || color2 == '2' || color3 == '2') {
                pixel2 = '1';
            } else {
                pixel2 = '0';
            }

            if(color1 == '3' || color2 == '3' || color3 == '3') {
                pixel3 = '1';
            } else {
                pixel3 = '0';
            }

            // Draw the pixels
            drawPixel(pixel1);
            drawPixel(pixel2);
            drawPixel(pixel3);
        }
        // Start a new line for the next row of pixels
        printf("\n");
    }

    return 0;
}