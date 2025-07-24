//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants 
#define WIDTH 10
#define HEIGHT 10
#define COLORS 5

// Function to generate random pixel colors
int generatePixelColor() {
    return rand() % COLORS;
}

// Function to generate pixel art 
void generatePixelArt(int pixelArt[WIDTH][HEIGHT]) {
    srand(time(NULL));  // Initialize random seed
    
    // Loop through each pixel in the pixel art 
    for(int i = 0; i < WIDTH; i++) {
        for(int j = 0; j < HEIGHT; j++) {
            pixelArt[i][j] = generatePixelColor();  // Generate random color for the pixel
        }
    }
}

// Function to print pixel values as characters 
void printPixelArt(int pixelArt[WIDTH][HEIGHT]) {
    for(int i = 0; i < WIDTH; i++) {
        for(int j = 0; j < HEIGHT; j++) {
            printf("%c ", pixelArt[i][j] + 'A'); // Convert pixel value to character and print
        }
        printf("\n");  // Move to next row
    }
}

int main() {
    int pixelArt[WIDTH][HEIGHT];
    
    generatePixelArt(pixelArt); // Generate pixel art 
    
    printf("Generated pixel art:\n");
    printPixelArt(pixelArt);    // Print pixel art 
    
    return 0;
}