//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: future-proof
#include <stdio.h>   // Standard Input Output Library
#include <stdbool.h> // Boolean Values Library
#include <stdlib.h>  // Standard Library for Memory Allocation
#include <time.h>    // Time Functions Library

#define WIDTH 50     // Width of Pixel Art Canvas
#define HEIGHT 50    // Height of Pixel Art Canvas
#define PIXEL_SIZE 5 // Size of Each Pixel in Pixels

bool canvas[WIDTH][HEIGHT]; // Boolean Array to Store Canvas

// Function to Clear the Canvas
void clearCanvas()
{
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            canvas[i][j] = false;
        }
    }
}

// Function to Draw Pixel
void drawPixel(int x, int y)
{
    for (int i = 0; i < PIXEL_SIZE; i++)
    {
        for (int j = 0; j < PIXEL_SIZE; j++)
        {
            canvas[x + i][y + j] = true;
        }
    }
}

// Function to Generate Random Pixel Art
void generatePixelArt(int numPixels)
{
    clearCanvas(); // Clear the Canvas

    // Generate Random Pixels
    for (int i = 0; i < numPixels; i++)
    {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        drawPixel(x, y);
    }

    // Print Pixel Art
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            if (canvas[i][j])
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL)); // Set Seed for Randomization

    generatePixelArt(1000); // Generate Pixel Art

    return 0;
}