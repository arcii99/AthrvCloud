//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Donald Knuth
/*
 * This program generates 8-bit pixel art of various objects and patterns using ANSI escape codes.
 *
 * Author: Donald Knuth
 * Date: October 10, 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define ANSI escape codes for different colors
#define COLOR_RESET "\x1B[0m"
#define COLOR_BLACK "\x1B[30m"
#define COLOR_RED "\x1B[31m"
#define COLOR_GREEN "\x1B[32m"
#define COLOR_YELLOW "\x1B[33m"
#define COLOR_BLUE "\x1B[34m"
#define COLOR_MAGENTA "\x1B[35m"
#define COLOR_CYAN "\x1B[36m"
#define COLOR_WHITE "\x1B[37m"

// Define array of pixels
#define WIDTH 8
#define HEIGHT 8
unsigned char pixels[WIDTH][HEIGHT];

// Function to generate random pixel art
void generate_pixel_art() {
    srand(time(NULL)); // Seed the random number generator
    int i, j, k;
    for (k = 0; k < 3; k++) {
        // Generate random color for each object
        int color = rand() % 8;
        switch (color) {
            case 0:
                printf(COLOR_BLACK);
                break;
            case 1:
                printf(COLOR_RED);
                break;
            case 2:
                printf(COLOR_GREEN);
                break;
            case 3:
                printf(COLOR_YELLOW);
                break;
            case 4:
                printf(COLOR_BLUE);
                break;
            case 5:
                printf(COLOR_MAGENTA);
                break;
            case 6:
                printf(COLOR_CYAN);
                break;
            case 7:
                printf(COLOR_WHITE);
                break;
        }
        int x = rand() % (WIDTH - 2) + 1; // Random x coordinate
        int y = rand() % (HEIGHT - 2) + 1; // Random y coordinate
        int w = rand() % (WIDTH - x); // Random width
        int h = rand() % (HEIGHT - y); // Random height
        // Draw rectangle
        for (i = x; i < x + w; i++) {
            for (j = y; j < y + h; j++) {
                pixels[i][j] = 1;
                printf("# ");
            }
            printf("\n");
        }
    }
    // Draw pattern
    printf(COLOR_YELLOW);
    for (i = 0; i < WIDTH; i += 2) {
        for (j = 0; j < HEIGHT; j += 2) {
            if (pixels[i][j] == 0) {
                printf("+");
            } else {
                printf("#");
            }
            if (pixels[i][j+1] == 0) {
                printf("+");
            } else {
                printf("#");
            }
        }
        printf("\n");
        for (j = 0; j < HEIGHT; j += 2) {
            if (pixels[i+1][j] == 0) {
                printf("+");
            } else {
                printf("#");
            }
            if (pixels[i+1][j+1] == 0) {
                printf("+");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
    printf(COLOR_RESET);
}

int main() {
    generate_pixel_art(); // Generate and print pixel art
    return 0;
}