//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0)); // set seed for random number generator
    int canvas_width = 16, canvas_height = 16; // pixel canvas size
    int pixel_size = 5; // size of each pixel in output
    int pixel_canvas_width = canvas_width * pixel_size;
    int pixel_canvas_height = canvas_height * pixel_size;
    char canvas[canvas_width][canvas_height];
    int i, j, k, l;
    for (i = 0; i < canvas_width; i++) {
        for (j = 0; j < canvas_height; j++) {
            canvas[i][j] = ' ';
        }
    }
    for (k = 0; k < canvas_width/2; k++) {
        for (l = 0; l < canvas_height/2; l++) {
            int r = rand() % 2;
            if (r == 0) {
                canvas[k][l] = '0';
                canvas[canvas_width - k - 1][l] = '1';
                canvas[k][canvas_height - l - 1] = '1';
                canvas[canvas_width - k - 1][canvas_height - l - 1] = '0';
            } else {
                canvas[k][l] = '1';
                canvas[canvas_width - k - 1][l] = '0';
                canvas[k][canvas_height - l - 1] = '0';
                canvas[canvas_width - k - 1][canvas_height - l - 1] = '1';
            }
        }
    }
    printf("\n");
    for (i = 0; i < pixel_canvas_height; i++) {
        for (j = 0; j < pixel_canvas_width; j++) {
            printf("%c", canvas[j/pixel_size][i/pixel_size]);
        }
        printf("\n");
    }
    return 0;
}