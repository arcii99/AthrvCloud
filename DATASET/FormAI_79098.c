//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    char pixels[10][10];    // 10x10 pixel canvas

    // Generate random pixels
    for(int y = 0; y < 10; y++) {
        for(int x = 0; x < 10; x++) {
            int pixel = rand() % 2;
            if(pixel == 0) {
                pixels[y][x] = '.';
            } else {
                pixels[y][x] = 'X';
            }
        }
    }

    // Print the pixels
    for(int y = 0; y < 10; y++) {
        for(int x = 0; x < 10; x++) {
            printf("%c", pixels[y][x]);
        }
        printf("\n");
    }

    return 0;
}