//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define WIDTH 100
#define HEIGHT 100

typedef struct {
    int r;
    int g;
    int b;
} Color;

typedef struct {
    Color pixels[WIDTH][HEIGHT];
    pthread_mutex_t lock;
    int row;
} Image;

void* generator(void* arg) {
    Image* img = (Image*) arg;
    while (1) {
        pthread_mutex_lock(&img->lock);
        int row = img->row;
        if (row >= HEIGHT) {
            pthread_mutex_unlock(&img->lock);
            return NULL;
        }
        printf("Generating row %d\n", row);
        for (int x = 0; x < WIDTH; x++) {
            img->pixels[x][row].r = rand() % 256;
            img->pixels[x][row].g = rand() % 256;
            img->pixels[x][row].b = rand() % 256;
        }
        img->row++;
        pthread_mutex_unlock(&img->lock);
    }
}

void output_image(Image* img) {
    FILE* fp = fopen("image.ppm", "w");
    fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            Color c = img->pixels[x][y];
            fprintf(fp, "%d %d %d ", c.r, c.g, c.b);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

int main() {
    pthread_t threads[4];
    pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
    Image img = {
        .lock = lock,
        .row = 0
    };
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, generator, (void*) &img);
    }
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }
    output_image(&img);
    return 0;
}