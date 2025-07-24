//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: happy
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

// Colors
#define COLOR_BLACK 0
#define COLOR_RED 1
#define COLOR_GREEN 2
#define COLOR_YELLOW 3
#define COLOR_BLUE 4
#define COLOR_MAGENTA 5
#define COLOR_CYAN 6
#define COLOR_WHITE 7

// Define the byte size of a pixel
#define PIXEL_SIZE 2 // using 2 bytes per pixel (char and attribute)

// Define the attributes for each pixel (char and attribute)
typedef struct 
{
    char chr;
    char attribute;
} Pixel;

// Define the screen buffer to hold all the pixels
Pixel screen_buffer[SCREEN_WIDTH * SCREEN_HEIGHT];

// Generate a random character
char generate_random_char() {
    return (char)(32 + rand() % 95);
}

// Generate a random attribute (color)
char generate_random_attribute() {
    return (char)(COLOR_BLACK + rand() % 8);
}

// Generate a new pixel with random character and attribute
Pixel generate_random_pixel() {
    Pixel new_pixel;
    new_pixel.chr = generate_random_char();
    new_pixel.attribute = generate_random_attribute();
    return new_pixel;
}

// Draw the screen buffer to the console
void draw_screen_buffer() {
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        printf("%c%c", screen_buffer[i].chr, screen_buffer[i].attribute);
    }
}

int main() {
    // Initialize the random seed
    srand(time(NULL));

    // Fill the screen buffer with random pixels
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        screen_buffer[i] = generate_random_pixel();
    }

    // Draw the initial screen
    draw_screen_buffer();

    // Wait for user input (press any key to exit)
    getchar();

    // Exit the program
    return 0;
}