//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

// function prototypes
void drawPixel(char pixel[HEIGHT][WIDTH]);
void randomPixels(char pixel[HEIGHT][WIDTH]);
void clear(char pixel[HEIGHT][WIDTH]);

int main()
{
    // initialize the 2D-char array representing the pixel art
    char pixel[HEIGHT][WIDTH];
    clear(pixel);

    // loop to constantly generate new pixel art
    while (1) {
        // draw random pixels on the canvas
        randomPixels(pixel);

        // display the pixel art on the screen
        drawPixel(pixel);

        // add some delay before generating new pixel art
        usleep(30000);
    }

    return 0;
}

// function to draw the 2D-char array pixel art to the console
void drawPixel(char pixel[HEIGHT][WIDTH])
{
    system("clear"); // clear the console before redrawing pixel art
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", pixel[i][j]); // print each pixel
        }
        printf("\n"); // move to next row
    }
}

// function to fill randomly the 2D-char array with '*' or ' '
void randomPixels(char pixel[HEIGHT][WIDTH])
{
    srand(time(NULL));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int rnd = rand() % 2; // randomly choose between 0 and 1
            if (rnd == 1) {
                pixel[i][j] = '*'; // fill with asterisk if random number is 1
            } else {
                pixel[i][j] = ' '; // fill with space if random number is 0
            }
        }
    }
}

// function to set all elements of the 2D-char array to ' '
void clear(char pixel[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pixel[i][j] = ' ';
        }
    }
}