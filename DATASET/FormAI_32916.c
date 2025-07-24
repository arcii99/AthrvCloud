//FormAI DATASET v1.0 Category: Image Editor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 400
#define HEIGHT 400
#define MAX_COLOR 255

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

Pixel image[WIDTH][HEIGHT];

void create_image() {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            image[i][j].red = rand() % MAX_COLOR;
            image[i][j].green = rand() % MAX_COLOR;
            image[i][j].blue = rand() % MAX_COLOR;
        }
    }
}

void apply_filter() {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            int r = image[i][j].red;
            int g = image[i][j].green;
            int b = image[i][j].blue;

            image[i][j].red = (r + g + b) / 3;
            image[i][j].green = 0;
            image[i][j].blue = 255 - r;
        }
    }
}

void save_image() {
    FILE *fp;
    char filename[] = "cyberpunk_image.ppm";

    fp = fopen(filename, "w");

    fprintf(fp, "P3\n%d %d\n%d\n", WIDTH, HEIGHT, MAX_COLOR);

    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            fprintf(fp, "%d %d %d ", image[i][j].red, image[i][j].green, image[i][j].blue);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main() {
    create_image();
    apply_filter();
    save_image();

    printf("Cyberpunk Image has been created!\n");

    return 0;
}