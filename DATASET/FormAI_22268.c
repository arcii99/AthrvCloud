//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePixelArt(int pixelSize, int artWidth, int artHeight) {
    srand(time(NULL)); // Seed the randomizer with current time
    
    // Loop through each pixel in the art
    for (int y = 0; y < artHeight; y++) {
        for (int x = 0; x < artWidth; x++) {
            
            // Generate a random RGB value for the pixel
            int red = rand() % 256;
            int green = rand() % 256;
            int blue = rand() % 256;
            
            // Calculate the pixel's position in the console
            int pixelX = x * (pixelSize + 1);
            int pixelY = y * (pixelSize + 1);
            
            // Fill in the pixel with the random color
            for (int i = 0; i < pixelSize; i++) {
                for (int j = 0; j < pixelSize; j++) {
                    printf("\033[%d;%dH\033[48;2;%d;%d;%dm ", pixelY + i + 1, pixelX + j + 1, red, green, blue);
                }
            }
        }
    }
    
    // Reset console formatting to default
    printf("\033[0m");
}

int main() {
    int pixelSize = 6;
    int artWidth = 10;
    int artHeight = 10;
    
    // Clear console
    printf("\033[2J");
    
    generatePixelArt(pixelSize, artWidth, artHeight);
    
    return 0;
}