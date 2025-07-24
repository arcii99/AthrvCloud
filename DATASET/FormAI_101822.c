//FormAI DATASET v1.0 Category: Fractal Generation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

#define MAX_ITERATIONS 1000
#define IMAGE_WIDTH 640
#define IMAGE_HEIGHT 480

struct thread_data {
    int thread_id;
    int num_threads;
    unsigned char *image;
};

void* compute_fractal(void* arg) {
    struct thread_data* data = (struct thread_data *) arg;
    int start_row = (IMAGE_HEIGHT / data->num_threads) * data->thread_id;
    int end_row = start_row + (IMAGE_HEIGHT / data->num_threads);
    int offset = start_row * IMAGE_WIDTH;
    for (int y = start_row; y < end_row; y++) {
        for (int x = 0; x < IMAGE_WIDTH; x++) {
            double cre = (x - IMAGE_WIDTH / 2.0) * 4.0 / IMAGE_WIDTH;
            double cim = (y - IMAGE_HEIGHT / 2.0) * 4.0 / IMAGE_WIDTH;
            double zre = cre, zim = cim;
            int iter;
            for (iter = 0; iter < MAX_ITERATIONS; iter++) {
                double tmp = zre * zre - zim * zim + cre;
                zim = 2.0 * zre * zim + cim;
                zre = tmp;
                if (zre * zre + zim * zim > 4) {
                    break;
                }
            }
            data->image[offset + x] = (unsigned char)(iter % 256);
        }
        offset += IMAGE_WIDTH;
    }
    pthread_exit(NULL);
}

int main() {
    unsigned char *image = malloc(IMAGE_WIDTH * IMAGE_HEIGHT * sizeof(unsigned char));
    if (image == NULL) {
        printf("Out of memory.");
        return -1;
    }

    pthread_t threads[4];
    struct thread_data td[4];

    for (int i = 0; i < 4; i++) {
        td[i].thread_id = i;
        td[i].num_threads = 4;
        td[i].image = image;
        pthread_create(&threads[i], NULL, compute_fractal, (void *) &td[i]);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    FILE *fp = fopen("fractal.pgm", "wb");
    if (fp == NULL) {
        printf("Error creating fractal file.\n");
        return -1;
    }
    fprintf(fp, "P5\n%d %d\n255\n", IMAGE_WIDTH, IMAGE_HEIGHT);
    fwrite(image, IMAGE_WIDTH * IMAGE_HEIGHT, 1, fp);
    fclose(fp);

    free(image);
    return 0;
}