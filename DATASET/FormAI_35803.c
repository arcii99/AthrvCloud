//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const int width = 40;
    const int height = 20;
    
    srand(time(NULL)); // seed the random number generator
    
    char canvas[height][width];
    
    // fill the canvas with random ASCII characters
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int random_num = rand() % 95 + 32; // get a random number between 32 and 126 (inclusive)
            canvas[i][j] = (char) random_num; // convert the random number to its corresponding ASCII character
        }
    }
    
    // print the canvas
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}