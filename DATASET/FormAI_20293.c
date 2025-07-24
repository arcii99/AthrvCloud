//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const int WIDTH = 32;
    const int HEIGHT = 32;
    const int PIXEL_SIZE = 4;

    char pixels[WIDTH * HEIGHT * PIXEL_SIZE];
    int x, y, i;

    for(y = 0; y < HEIGHT; y++) {
        for(x = 0; x < WIDTH; x++) {
            i = (y * WIDTH + x) * PIXEL_SIZE;

            pixels[i] = 255; // Sets red channel to max value
            pixels[i + 1] = x % 256; // Sets green channel based on x position
            pixels[i + 2] = y % 256; // Sets blue channel based on y position
            pixels[i + 3] = 255; // Sets alpha channel to max value
        }
    }

    FILE *fp = fopen("pixel_art.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(pixels, sizeof(char), WIDTH * HEIGHT * PIXEL_SIZE, fp);
    fclose(fp);

    printf("Pixel art generated at \"pixel_art.ppm\".\n");

    return 0;
}