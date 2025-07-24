//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 50

void generatePixelArt(char pixelArt[][WIDTH], int width, int height);
void printPixelArt(char pixelArt[][WIDTH], int width, int height);
void savePixelArt(char pixelArt[][WIDTH], int width, int height);

int main() {
    char pixelArt[HEIGHT][WIDTH];
    
    srand(time(NULL)); // Seed for random number generator

    generatePixelArt(pixelArt, WIDTH, HEIGHT); // Generate pixel art
    printPixelArt(pixelArt, WIDTH, HEIGHT); // Print pixel art to console
    savePixelArt(pixelArt, WIDTH, HEIGHT); // Save pixel art to file 

    return 0;
}

/**
 * Generates a random pixel art using ASCII characters.
 * @param pixelArt 2D array to store the pixel art
 * @param width Width of the pixel art
 * @param height Height of the pixel art
 */
void generatePixelArt(char pixelArt[][WIDTH], int width, int height) {
    char characters[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'}; // Array of characters to use for pixel art

    // Populate pixelArt array with random characters
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixelArt[i][j] = characters[rand() % 10];
        }
    }
}

/**
 * Prints the pixel art to console.
 * @param pixelArt 2D array containing the pixel art
 * @param width Width of the pixel art
 * @param height Height of the pixel art
 */
void printPixelArt(char pixelArt[][WIDTH], int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", pixelArt[i][j]);
        }
        printf("\n");
    }
}

/**
 * Saves the pixel art to a file.
 * @param pixelArt 2D array containing the pixel art
 * @param width Width of the pixel art
 * @param height Height of the pixel art
 */
void savePixelArt(char pixelArt[][WIDTH], int width, int height) {
    FILE* file = fopen("pixel_art.txt", "w"); // Open file for writing

    if (file != NULL) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                fputc(pixelArt[i][j], file); // Write character to file
            }
            fputc('\n', file); // New line after every row
        }

        printf("Pixel art saved to file!");
        fclose(file); // Close file
    } else {
        printf("Error: Unable to open file for writing.");
    }
}