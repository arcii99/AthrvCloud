//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define ART_SIZE 10
#define PIXEL_SIZE 3
#define PIXELS_PER_ROW 3

// Define pixel art characters
const char PIXEL_CHARS[] = {
    '.', // empty pixel
    '+', // filled square pixel
    '*', // filled circle pixel
    '/', // diagonal pixel
    '-', // horizontal pixel
    '|', // vertical pixel
    '^', // upward pointing pixel
    'v', // downward pointing pixel
    '<', // left pointing pixel
    '>'  // right pointing pixel
};

// Function to generate random pixel art
void generate_pixel_art()
{
    int i, j, rand_pixel;
    
    // Set seed for random number generator
    srand(time(NULL));
    
    // Generate random pixel art
    for (i = 0; i < ART_SIZE; i++)
    {
        // Print row of pixels
        for (j = 0; j < ART_SIZE; j++)
        {
            // Generate random pixel character
            rand_pixel = rand() % sizeof(PIXEL_CHARS);
            
            // Print pixel character
            printf("%c", PIXEL_CHARS[rand_pixel]);
            
            // Add spacing between pixels in row
            if ((j + 1) % PIXELS_PER_ROW == 0)
            {
                printf(" ");
            }
            
            // Add spacing between rows of pixels
            if ((j + 1) % (ART_SIZE / PIXEL_SIZE) == 0)
            {
                printf("\n");
            }
        }
    }
}

int main()
{
    // Generate random pixel art
    generate_pixel_art();
    
    return 0;
}