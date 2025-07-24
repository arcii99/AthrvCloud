//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: irregular
// C Pixel Art Generator
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random colors
void generateColor(char colorHex[]) {
    // Array of possible color range
    char colors[] = "1234567890ABCDEF";
    // Generate random color code
    for (int i = 0; i < 6; i++) {
        int index = rand() % 16;
        colorHex[i] = colors[index];
    }
    colorHex[6] = '\0';
}

int main() {
    // Set seed for randomization
    srand(time(0));
    // Create 20 x 20 pixel art grid using ASCII characters
    char grid[20][20] = {
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', '*', '*', '*', '*', ' ', ' ', ' ', ' ', '*', '*', '*', '*', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', '*', ' ', '*'},
        {'*', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', '*', '*'},
        {'*', ' ', ' ', '*', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', '*', '*', '*', '*', ' ', ' ', '*', '*'},
        {'*', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', '*', '*', '*', '*', ' ', ' ', ' ', ' ', '*', '*', '*', '*', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
    };

    // Declare variables for generating color
    char color1[7], color2[7];

    // Generate two random colors to use for irregular style
    generateColor(color1);
    generateColor(color2);

    // Loop through grid and print pixels in irregular style
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            // Skip pixels in rows 5 to 14 (inclusive) and columns 5 to 14 (inclusive)
            if ((i >= 5 && i <= 14) && (j >= 5 && j <= 14)) {
                continue;
            }
            // Color code the pixels in diagonal shape using color1
            else if (i == j || i == (20 - j - 1)) {
                printf("\033[0;38;2;%d;%d;%dm", color1[0], color1[1], color1[2]);
                printf("%c ", grid[i][j]);
                printf("\033[0m");
            }
            // Color code the pixels in a checkerboard pattern using color2
            else if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
                printf("\033[0;38;2;%d;%d;%dm", color2[0], color2[1], color2[2]);
                printf("%c ", grid[i][j]);
                printf("\033[0m");
            }
            // Color code all other pixels in white
            else {
                printf("\033[0;38;2;255;255;255m");
                printf("%c ", grid[i][j]);
                printf("\033[0m");
            }
        }
        printf("\n");
    }

    return 0;
}