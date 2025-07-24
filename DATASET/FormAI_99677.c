//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 15
#define HEIGHT 15
#define PIXEL_WIDTH 5
#define PIXEL_HEIGHT 5
#define MAX_COLOR 8

void print_pixel(char c, int times) {
    for (int i = 0; i < times; i++) {
        printf("%c", c);
    }
}

int main() {
    char canvas[HEIGHT][WIDTH];
    srand((unsigned) time(NULL));
    // Generate canvas
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            canvas[i][j] = (char) ('0' + rand() % (MAX_COLOR + 1));
        }
    }
    // Print canvas
    for (int i = 0; i < HEIGHT * PIXEL_HEIGHT; i++) {
        for (int j = 0; j < WIDTH * PIXEL_WIDTH; j++) {
            char color = canvas[i / PIXEL_HEIGHT][j / PIXEL_WIDTH];
            switch (color) {
                case '0':
                    printf("\033[40m  \033[0m");
                    break;
                case '1':
                    printf("\033[41m  \033[0m");
                    break;
                case '2':
                    printf("\033[42m  \033[0m");
                    break;
                case '3':
                    printf("\033[43m  \033[0m");
                    break;
                case '4':
                    printf("\033[44m  \033[0m");
                    break;
                case '5':
                    printf("\033[45m  \033[0m");
                    break;
                case '6':
                    printf("\033[46m  \033[0m");
                    break;
                case '7':
                    printf("\033[47m  \033[0m");
                    break;
            }
        }
        printf("\n");
    }
    return 0;
}