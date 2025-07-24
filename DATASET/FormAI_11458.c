//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: innovative
#include <stdio.h>

int main() {
    int pixels[6][10] = {
        {0, 1, 1, 0, 0, 0, 0, 1, 1, 0},
        {0, 1, 1, 1, 0, 0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 1, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
    };

    char pseudo_art[6][11];
    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 10; j++) {
            if (pixels[i][j] == 1)
                pseudo_art[i][j] = '|';
            else
                pseudo_art[i][j] = ' ';
        }
        pseudo_art[i][10] = '\0';
    }
    
    // Print the pixel art
    printf("Here's a cute cat in ASCII pixel art:\n\n");
    for (int i = 0; i < 6; i++) {
        printf("%s\n", pseudo_art[i]);
    }
    
    return 0;
}