//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 25

int main() {
    srand(time(NULL));
    char pixelArt[HEIGHT][WIDTH];

    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            int randomNum = rand() % 10;
            if(randomNum == 0) {
                pixelArt[i][j] = ' ';
            }
            else if(randomNum < 5) {
                pixelArt[i][j] = '.';
            }
            else {
                pixelArt[i][j] = '#';
            }
            printf("%c", pixelArt[i][j]);
        }
        printf("\n");
    }
    return 0;
}