//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 40

// define colors
#define BLACK   "\x1b[40m"
#define WHITE   "\x1b[47m"
#define RED     "\x1b[41m"
#define GREEN   "\x1b[42m"
#define BLUE    "\x1b[44m"
#define YELLOW  "\x1b[43m"
#define MAGENTA "\x1b[45m"
#define CYAN    "\x1b[46m"

// define pixel character
#define PIXEL   "  "

// define pixel color codes
#define COLORS  {BLACK, WHITE, RED, GREEN, BLUE, YELLOW, MAGENTA, CYAN}
#define NUM_COLORS 8

// function to generate random color code
char* getRandomColor(char** colors) {
    int index = rand() % NUM_COLORS;
    return colors[index];
}

// main function
int main() {

    // initialize random seed
    srand(time(NULL));
    
    // initialize pixel colors
    char* colors[NUM_COLORS] = COLORS;
    
    // create array of pixels with random colors
    char* pixels[HEIGHT][WIDTH];
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            pixels[i][j] = getRandomColor(colors);
        }
    }
    
    // print array of pixels
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            printf("%s", pixels[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}