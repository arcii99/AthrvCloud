//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Alan Touring
#include <stdio.h>

void drawPixel(int x, int y) {
    printf("*");
}

void drawSpace() {
    printf(" ");
}

int main() {
    int pixels[5][5] = {{1, 0, 0, 0, 1},
                        {0, 1, 0, 1, 0},
                        {0, 0, 1, 0, 0},
                        {0, 1, 0, 1, 0},
                        {1, 0, 0, 0, 1}};

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (pixels[i][j] == 1) {
                drawPixel(i, j);
            } else {
                drawSpace();
            }
        }
        printf("\n");
    }

    return 0;
}