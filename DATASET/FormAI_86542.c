//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: cheerful
#include <stdio.h>

#define WIDTH 80    // number of columns in output
#define HEIGHT 60   // number of rows in output
#define MAX_INTENSITY 255   // maximum possible pixel intensity value

void convertToASCII(unsigned char *image) {
    char ascii[HEIGHT][WIDTH];
    int index = 0;

    // loop through each pixel in the image
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {

            // calculate the pixel intensity and normalize it to a value between 0 and 1
            double intensity = (double)*(image + index)/MAX_INTENSITY;

            // use a lookup table to map the intensity to an ASCII character
            const char *character = " .:-=+*#%@";
            int charIndex = (int)(intensity * (sizeof(character) - 1));

            // store the character in the output array
            ascii[row][col] = character[charIndex];

            // move on to the next pixel
            index++;
        }
    }

    // print the ASCII art to the console
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            printf("%c", ascii[row][col]);
        }
        printf("\n");
    }
}

int main() {
    unsigned char image[WIDTH * HEIGHT];

    // initialize the image with random pixel intensities
    for (int i = 0; i < WIDTH*HEIGHT; i++) {
        image[i] = rand() % MAX_INTENSITY;
    }

    convertToASCII(image);

    return 0;
}