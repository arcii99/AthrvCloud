//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

int main() {
    int imageWidth = 50;
    int imageHeight = 20;

    char pixels[imageHeight][imageWidth];

    // Set all the pixels to blank spaces
    for(int i=0; i<imageHeight; i++) {
        for(int j=0; j<imageWidth; j++) {
            pixels[i][j] = ' ';
        }
    }

    // Generate a heart shape
    for(float angle=0; angle<360; angle+=0.1) {
        float x = 16 * pow(sin(angle), 3);
        float y = 13 * cos(angle) - 5 * cos(2*angle) - 2 * cos(3*angle) - cos(4*angle);
        int i = (int)(y + 10);
        int j = (int)(x + 25);
        pixels[i][j] = '*';
    }

    // Print the pixel art
    for(int i=0; i<imageHeight; i++) {
        for(int j=0; j<imageWidth; j++) {
            putchar(pixels[i][j]);
        }
        putchar('\n');
    }

    return 0;
}