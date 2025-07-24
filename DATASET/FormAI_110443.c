//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

// Function to clear the console screen
void clearScreen() {
    system("cls||clear");
}

// Function to get a random color
char* getRandomColor() {
    char* colors[7] = {"\033[0;31m", "\033[0;32m", "\033[0;33m", "\033[0;34m", "\033[0;35m", "\033[0;36m", "\033[0;37m"};
    int index = rand() % 7;
    return colors[index];
}

// Function to print the pixel art
void printPixelArt(char pixelArt[ROWS][COLS][10]) {
    clearScreen();
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%s%s ", pixelArt[i][j], "\033[0m");
        }
        printf("\n");
    }
    // Wait for 1 second before clearing the screen
    // and printing the next frame
    usleep(1000000);
}

int main() {
    srand(time(0)); // Seed for the random number generator
    char pixelArt[ROWS][COLS][10] = {{" "}};
    // Generate the pixel art
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            char* color = getRandomColor();
            sprintf(pixelArt[i][j], "%s%d,%d", color, i, j);
        }
    }
    // Print the pixel art continuously
    while(1) {
        printPixelArt(pixelArt);
        // Change the colors randomly for each frame
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                char* color = getRandomColor();
                sprintf(pixelArt[i][j], "%s%d,%d", color, i, j);
            }
        }
    }
    return 0;
}