//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Define the size of the canvas
    int width = 10;
    int height = 10;
    
    // Define the color palette
    char colors[] = {' ', '.', 'o', '*', 'O', '@', '#', '%', '&', '$'};
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate the pixel art
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            // Generate a random color from the color palette
            char color = colors[rand() % (sizeof(colors)/sizeof(colors[0]))];
            
            // Print the pixel in the chosen color
            printf("%c ", color);
        }
        printf("\n");
    }
    
    return 0;
}