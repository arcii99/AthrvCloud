//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 32
#define HEIGHT 32

void clear_screen() {
    system("clear");
}

void draw_pixel(int color) {
    printf("\033[38;5;%dm\u2588\033[0m", color);
}

void draw_art(int **art) {
    clear_screen();
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            draw_pixel(art[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int **art = (int **)malloc(HEIGHT * sizeof(int *));
    for (int i=0; i<HEIGHT; i++) {
        art[i] = (int *)malloc(WIDTH * sizeof(int));
        for (int j=0; j<WIDTH; j++) {
            art[i][j] = rand() % 256;
        }
    }
    draw_art(art);

    for (int i=0; i<HEIGHT; i++) {
        free(art[i]);
    }
    free(art);

    return 0;
}