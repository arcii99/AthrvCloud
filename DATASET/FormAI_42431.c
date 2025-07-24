//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: realistic
#include <stdio.h>

int main() {
    char pixels[7][7] = {
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { ' ', '*', ' ', ' ', ' ', '*', ' ' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { ' ', '*', ' ', ' ', ' ', '*', ' ' },
        { ' ', ' ', ' ', '*', ' ', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ' }
    };

    // Print the pixel art
    for (int y = 0; y < 7; y++) {
        for (int x = 0; x < 7; x++) {
            printf("%c ", pixels[y][x]);
        }
        printf("\n");
    }

    return 0;
}