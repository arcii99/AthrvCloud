//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 120
#define HEIGHT 60

char ascii_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

int get_gray_value(unsigned char *image, int x, int y, int width) {
    return (int) image[x + y * width];
}

int get_ascii_index(int gray_value, int range) {
    int index = gray_value / (256 / range);
    return index;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Please specify an image file!\n");
        return 0;
    }

    FILE *f = fopen(argv[1], "rb");
    unsigned char image[WIDTH * HEIGHT];
    fread(image, sizeof(unsigned char), WIDTH * HEIGHT, f);
    fclose(f);

    printf("\033[2J");

    char ascii_art[HEIGHT][WIDTH + 1];
    int range = strlen(ascii_chars);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int gray_value = get_gray_value(image, x, y, WIDTH);
            int ascii_index = get_ascii_index(gray_value, range);
            ascii_art[y][x] = ascii_chars[ascii_index];
        }
        ascii_art[y][WIDTH] = '\0';
        printf("%s\n", ascii_art[y]);
    }

    return 0;
}