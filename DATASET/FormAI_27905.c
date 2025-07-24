//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Define variable size of image
    int size = 8;

    // Define color values for pixels
    int colors[] = {0, 1, 2, 3, 4, 5, 6, 7};

    // Set the seed for random number generation
    srand(time(NULL));

    // Iterate over each pixel in the image
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            
            // Generate a random color index
            int color_index = rand() % 8;

            // Set the current pixel to the randomly selected color
            int pixel_color = colors[color_index];

            // Print the pixel color value to the console
            printf("%d ", pixel_color);

        }
        printf("\n"); // Start new line after each row of pixels is printed
    }

    return 0;
}