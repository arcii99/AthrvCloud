//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to clear console screen
void clear_screen() {
    system("@cls||clear");
}

// Function to generate a random number in a given range
int random_number(int min_num, int max_num) {
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num) {
        low_num = min_num;
        hi_num = max_num + 1;
    } else {
        low_num = max_num + 1;
        hi_num = min_num;
    }

    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

// Function to generate pixel art
void generate_art(int width, int height, int pixel_size) {
    clear_screen();

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = 0, g = 0, b = 0;

            // Generate random colors
            int color = random_number(1, 4);
            if (color == 1) {
                r = 255;
            } else if (color == 2) {
                g = 255;
            } else if (color == 3) {
                b = 255;
            }

            // Draw pixel
            for (int i = 0; i < pixel_size; i++) {
                for (int j = 0; j < pixel_size; j++) {
                    printf("\033[48;2;%d;%d;%dm ", r, g, b); // Set background color
                }
                printf("\n");
            }
        }
        usleep(1000); // Add delay for effect
    }
}

// Main function
int main() {
    int width = 32;
    int height = 16;
    int pixel_size = 4;

    generate_art(width, height, pixel_size);

    return 0;
}