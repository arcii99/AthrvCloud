//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define colors for pixel art
#define BLACK 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define WHITE 7

// define pixel art size
#define WIDTH 10
#define HEIGHT 10

// define random color generator function
int get_random_color() {
    return rand() % 8; // generates a random number between 0 and 7, inclusive
}

int main() {
    // seed the pseudo-random number generator
    srand(time(NULL));
    
    int pixel_art[WIDTH][HEIGHT]; // create a 2D array to represent the pixel art
    
    // populate the array with random colors
    for(int i=0; i<WIDTH; i++) {
        for(int j=0; j<HEIGHT; j++) {
            pixel_art[i][j] = get_random_color();
        }
    }
    
    // print the pixel art to the console
    for(int i=0; i<WIDTH; i++) {
        for(int j=0; j<HEIGHT; j++) {
            switch(pixel_art[i][j]) {
                case BLACK:
                    printf("\u2588\u2588"); // print two full block Unicode characters for BLACK color
                    break;
                case RED:
                    printf("\033[1;31m\u2588\u2588\033[0m"); // print two full block Unicode characters for RED color with red text color
                    break;
                case GREEN:
                    printf("\033[1;32m\u2588\u2588\033[0m"); // print two full block Unicode characters for GREEN color with green text color
                    break;
                case YELLOW:
                    printf("\033[1;33m\u2588\u2588\033[0m"); // print two full block Unicode characters for YELLOW color with yellow text color
                    break;
                case BLUE:
                    printf("\033[1;34m\u2588\u2588\033[0m"); // print two full block Unicode characters for BLUE color with blue text color
                    break;
                case MAGENTA:
                    printf("\033[1;35m\u2588\u2588\033[0m"); // print two full block Unicode characters for MAGENTA color with magenta text color
                    break;
                case CYAN:
                    printf("\033[1;36m\u2588\u2588\033[0m"); // print two full block Unicode characters for CYAN color with cyan text color
                    break;
                case WHITE:
                    printf("\033[1;37m\u2588\u2588\033[0m"); // print two full block Unicode characters for WHITE color with white text color
                    break;
            }
        }
        printf("\n"); // move cursor to next line for new row
    }
    
    return 0;
}