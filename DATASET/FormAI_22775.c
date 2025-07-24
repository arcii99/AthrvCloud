//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define CHAR_WIDTH 10
#define CHAR_HEIGHT 20
#define CANVAS_WIDTH 50
#define CANVAS_HEIGHT 30

char chars[11][20] = {
    " ######## ",
    "##      ##",
    "##      ##",
    "##      ##",
    " ######## ",
    "##      ##",
    "##      ##",
    "##      ##",
    " ######## ",
    "          ",

    " ######## ",
    "##      ##",
    "##      ##",
    " ######## ",
    "##      ##",
    "##      ##",
    "##      ##",
    " ######## ",
    "          ",
    
    " ######## ",
    "##      ##",
    "##        ",
    "##        ",
    "##        ",
    "##        ",
    "##      ##",
    " ######## ",
    "          ",
    
    " ######## ",
    "##      ##",
    "##      ##",
    "##      ##",
    " ######## ",
    "          ",
    "          ",
    " ######## ",
    "          ",
    
    " ######## ",
    "##        ",
    "##        ",
    " ######## ",
    "          ",
    "          ",
    "          ",
    " ######## ",
    "          ",
    
    "          ",
    "          ",
    "          ",
    "          ",
    "          ",
    "          ",
    "          ",
    " ######## ",
    "          ",
    
    "          ",
    "          ",
    "          ",
    "          ",
    "          ",
    "          ",
    "          ",
    "  ######  ",
    "          ",
    
    "          ",
    "          ",
    "          ",
    " ######## ",
    "          ",
    "          ",
    "          ",
    "          ",
    "          ",
    
    "          ",
    "        ##",
    "        ##",
    " ######## ",
    "        ##",
    "        ##",
    "        ##",
    " ######## ",
    "          ",
    
    " ######## ",
    "##      ##",
    "##      ##",
    " ######## ",
    "##      ##",
    "##      ##",
    "##      ##",
    " ######## ",
    "          ",
};

int main() {
    char canvas[CANVAS_HEIGHT][CANVAS_WIDTH];
    
    // Initialize canvas to be empty
    for (int i = 0; i < CANVAS_HEIGHT; i++) {
        for (int j = 0; j < CANVAS_WIDTH; j++) {
            canvas[i][j] = ' ';
        }
    }
    
    // Randomly place pixels
    for (int i = 0; i < 75; i++) {
        int x = rand() % CANVAS_WIDTH;
        int y = rand() % CANVAS_HEIGHT;
        char pixel = '#';
        canvas[y][x] = pixel;
    }
    
    // Convert pixel canvas to character art
    for (int i = 0; i < CANVAS_HEIGHT; i += CHAR_HEIGHT) {
        for (int j = 0; j < CANVAS_WIDTH; j += CHAR_WIDTH) {
            int charIndex = rand() % 10;
            for (int k = 0; k < CHAR_HEIGHT; k++) {
                for (int l = 0; l < CHAR_WIDTH; l++) {
                    char pixel = canvas[i + k][j + l];
                    if (pixel == '#') {
                        printf("%c", chars[charIndex][k*CHAR_WIDTH + l]);
                    } else {
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }
        printf("\n\n");
    }
    
    return 0;
}