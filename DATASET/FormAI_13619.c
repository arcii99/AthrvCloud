//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 30 // Width of the pixel art
#define HEIGHT 30 // Height of the pixel art

void generatePixelArt(char canvas[][WIDTH]);
void printPixelArt(char canvas[][WIDTH]);

int main(void) {
    char pixelArt[HEIGHT][WIDTH];
    generatePixelArt(pixelArt);
    printPixelArt(pixelArt);
    return 0;
}

void generatePixelArt(char canvas[][WIDTH]) {
    // Set all pixels to white initially
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            canvas[i][j] = 'O'; // 'O' represents a white pixel
        }
    }

    // Add a black border around the canvas
    for (int i = 0; i < HEIGHT; i++) {
        canvas[i][0] = '*'; // '*' represents a black pixel
        canvas[i][WIDTH-1] = '*';
    }
    for (int j = 0; j < WIDTH; j++) {
        canvas[0][j] = '*';
        canvas[HEIGHT-1][j] = '*';
    }

    // Add some random black pixels within the canvas
    for (int k = 0; k < 200; k++) {
        int i = rand() % (HEIGHT-2) + 1; // Exclude the border pixels
        int j = rand() % (WIDTH-2) + 1;
        canvas[i][j] = '*';
    }
}

void printPixelArt(char canvas[][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
}