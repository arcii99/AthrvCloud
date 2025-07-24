//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: interoperable
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void draw_pixel(int x, int y, char pixel) {
    printf("\033[%d;%dH%c", y, x, pixel);
    fflush(stdout);
}

int main() {
    srand(time(NULL));

    int max_x = 50;
    int max_y = 20;
    char pixels[] = {'.', ':', '-', '=', '+', '*', '#', '%', '@'};
    int num_pixels = sizeof(pixels)/sizeof(*pixels);

    for(int y = 1; y <= max_y; y++) {
        for(int x = 1; x <= max_x; x++) {
            draw_pixel(x, y, pixels[rand()%num_pixels]);
        }
    }
    printf("\n");

    return 0;
}