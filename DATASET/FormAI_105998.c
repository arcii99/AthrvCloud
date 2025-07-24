//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: shocked
#include <stdio.h>

int main() {
    int width = 10;
    int height = 10;

    char pixels[height][width];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (x < 5) {
                pixels[y][x] = '#';
            } else {
                pixels[y][x] = '.';
            }
        }
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", pixels[y][x]);
        }
        printf("\n");
    }

    return 0;
}