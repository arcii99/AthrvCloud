//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 30

char asciiArt[HEIGHT][WIDTH];

int main() {
    // Set random seed
    srand(time(NULL));
    
    // Initialize ASCII art with blank spaces
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            asciiArt[i][j] = ' ';
        }
    }

    // Iterate over each pixel and set it to a random value
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            int randomValue = rand()%2;
            if(randomValue == 1) {
                asciiArt[i][j] = '#';
            }
        }
    }

    // Print out the ASCII art
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            printf("%c", asciiArt[i][j]);
        }
        printf("\n");
    }

    return 0;
}