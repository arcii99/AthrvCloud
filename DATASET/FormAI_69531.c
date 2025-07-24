//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 60
#define HEIGHT 30
#define COLOR_MAX 7

int main() {
    int pixels[HEIGHT][WIDTH];

    srand(time(NULL));

    printf("Pixel Art:\n");

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            pixels[y][x] = rand() % COLOR_MAX;
        }
    }

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            switch (pixels[y][x]) {
                case 0: printf(" "); break;
                case 1: printf("."); break;
                case 2: printf(":"); break;
                case 3: printf("-"); break;
                case 4: printf("="); break;
                case 5: printf("+"); break;
                case 6: printf("#"); break;
                default: printf("?"); break;
            }
        }
        printf("\n");
    }

    return 0;
}