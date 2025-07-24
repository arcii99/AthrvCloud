//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Define the size of the ASCII art
#define WIDTH 80
#define HEIGHT 50

// Define the ASCII characters to use for the art
#define BLANK ' '
#define STAR '*'

// Define some colors for the art
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m"

// Define a function to clear the screen
void clearScreen()
{
    system("clear");
}

// Define a function to print the art to the screen
void printArt(char art[HEIGHT][WIDTH], int colors[HEIGHT][WIDTH])
{
    // Clear the screen
    clearScreen();

    // Print each character with its corresponding color
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (colors[y][x] == 1)
            {
                printf(COLOR_RED "%c" COLOR_RESET, art[y][x]);
            }
            else if (colors[y][x] == 2)
            {
                printf(COLOR_GREEN "%c" COLOR_RESET, art[y][x]);
            }
            else
            {
                printf("%c", art[y][x]);
            }
        }
        printf("\n");
    }
}

int main()
{
    // Define the ASCII art and colors
    char art[HEIGHT][WIDTH];
    int colors[HEIGHT][WIDTH];

    // Initialize the art and colors
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (x == y || x == WIDTH - y - 1)
            {
                art[y][x] = STAR;
                colors[y][x] = 1;
            }
            else if (x == WIDTH / 2 || y == HEIGHT / 2)
            {
                art[y][x] = STAR;
                colors[y][x] = 2;
            }
            else
            {
                art[y][x] = BLANK;
                colors[y][x] = 0;
            }
        }
    }

    // Print the art to the screen
    printArt(art, colors);

    return 0;
}