//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40 // Width of character grid
#define HEIGHT 20 // Height of character grid

// Character grid
char grid[HEIGHT][WIDTH];

// Set character at specified coordinates
void set_char(int x, int y, char c) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return; // Skip if out of bounds
    }
    grid[y][x] = c;
}

// Generate a random character
char get_random_char() {
    return (char) (rand() % 256);
}

// Fill character grid with random characters
void fill_with_random_chars() {
    srand(time(NULL));
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            set_char(x, y, get_random_char());
        }
    }
}

// Print character grid
void print_grid() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c ", grid[y][x]);
        }
        printf("\n");
    }
}

int main() {
    // Fill character grid with random characters
    fill_with_random_chars();

    // Print pixel art
    print_grid();

    return 0;
}