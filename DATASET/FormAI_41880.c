//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Set seed for random number generation
    srand(time(NULL));
    
    // Define pixel character array
    char pixels[8][8];
    
    // Fill array with random pixel characters
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int pixelInt = rand() % 2;
            if (pixelInt == 0) {
                pixels[i][j] = '#';
            } else {
                pixels[i][j] = '.';
            }
        }
    }
    
    // Print out pixel art
    printf("Here's your unique pixel art:\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", pixels[i][j]);
        }
        printf("\n");
    }
    
    // Generate puzzle question based on pixel art
    int numColoredPixels = 0;
    int numBlankPixels = 0;
    int numRowMatches = 0;
    int numColMatches = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (pixels[i][j] == '#') {
                numColoredPixels++;
                if (j == 0 || pixels[i][j-1] == '.') {
                    numRowMatches++;
                }
                if (i == 0 || pixels[i-1][j] == '.') {
                    numColMatches++;
                }
            } else {
                numBlankPixels++;
            }
        }
    }
    
    // Print out puzzle question
    printf("\nWhat is the number of colored pixels in the pixel art?\n");
    printf("There are %d colored pixels and %d blank pixels.\n", numColoredPixels, numBlankPixels);
    printf("The number of rows that have a colored pixel in the leftmost position is %d.\n", numRowMatches);
    printf("The number of columns that have a colored pixel in the topmost position is %d.\n", numColMatches);
    
    return 0;
}