//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Declare variables for the size of the image
    int width, height;

    // Prompt the user to enter the width and height of the image
    printf("Enter the Width of the image: ");
    scanf("%d", &width);

    printf("Enter the Height of the image: ");
    scanf("%d", &height);

    srand(time(NULL)); // Seed the random function

    // Loop through the pixels and display a random color for each pixel
    for(int x = 0; x < width; x++) {
        for(int y = 0; y < height; y++) {
            
            // Generate a random integer between 0 and 255 for each color channel
            int red = rand() % 256;
            int green = rand() % 256;
            int blue = rand() % 256;

            // Display the RGB values of the pixel in the format (R, G, B)
            printf("(%d, %d, %d) ", red, green, blue);
        }
        printf("\n"); // End the row of pixels
    }
    
    return 0;
}