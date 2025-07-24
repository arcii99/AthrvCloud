//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 50

// Color codes for pixels
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define RESET "\033[0m"

char pixels[HEIGHT][WIDTH]; // 2D array for storing pixel data

// Function for generating random pixel color
char* randomColor()
{
    int index = rand() % 7;
    switch (index)
    {
        case 0:
            return BLACK;
        case 1:
            return RED;
        case 2:
            return GREEN;
        case 3:
            return YELLOW;
        case 4:
            return BLUE;
        case 5:
            return MAGENTA;
        case 6:
            return CYAN;
        case 7:
            return WHITE;
    }
}

int main()
{
    srand(time(NULL)); // Seed for generating random numbers
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            pixels[i][j] = *randomColor(); // Initialize all pixels with random color
        }
    }

    // Print the generated pixel art
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            printf("%s\u2588%s", pixels[i][j], RESET);
        }
        printf("\n");
    }
    return 0;
}