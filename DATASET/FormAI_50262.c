//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

int main() {
    srand(time(NULL));
    char pixel[HEIGHT][WIDTH];

    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            int random_num = rand() % 2;
            if(random_num == 0) {
                pixel[i][j] = '.';
            } else {
                pixel[i][j] = '#';
            }
        }
    }

    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            printf("%c ", pixel[i][j]);
        }
        printf("\n");
    }

    return 0;
}