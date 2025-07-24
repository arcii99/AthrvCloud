//FormAI DATASET v1.0 Category: Fractal Generation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define WIDTH 100
#define HEIGHT 60
#define MAX_ITERATIONS 1000
#define WORKERS 4

typedef struct _worker_data {
    int id;
    int start;
    int end;
    double re_min;
    double re_max;
    double im_min;
    double im_max;
    int image[WIDTH][HEIGHT];
} worker_data;

void* worker_thread(void* arg) {
    worker_data* data = (worker_data*) arg;

    int i, j;
    double re_factor = (data->re_max - data->re_min) / WIDTH;
    double im_factor = (data->im_max - data->im_min) / HEIGHT;

    for (i = data->start; i < data->end; ++i) {
        double c_im = data->im_min + i * im_factor;

        for (j = 0; j < WIDTH; ++j) {
            double c_re = data->re_min + j * re_factor;
            double z_re = c_re;
            double z_im = c_im;
            int iteration;

            for (iteration = 0; iteration < MAX_ITERATIONS; ++iteration) {
                if (z_re * z_re + z_im * z_im > 4) {
                    break;
                }

                double new_re = z_re * z_re - z_im * z_im;
                double new_im = 2 * z_re * z_im;

                z_re = c_re + new_re;
                z_im = c_im + new_im;
            }

            data->image[j][i] = iteration;
        }
    }

    return NULL;
}

void generate_fractal(double re_min, double re_max, double im_min, double im_max, int image[WIDTH][HEIGHT]) {
    int i, j;
    pthread_t threads[WORKERS];
    worker_data worker_data_array[WORKERS];

    for (i = 0; i < WORKERS; ++i) {
        worker_data_array[i].id = i;
        worker_data_array[i].start = i * HEIGHT / WORKERS;
        worker_data_array[i].end = (i + 1) * HEIGHT / WORKERS;
        worker_data_array[i].re_min = re_min;
        worker_data_array[i].re_max = re_max;
        worker_data_array[i].im_min = im_min;
        worker_data_array[i].im_max = im_max;

        for (j = 0; j < WIDTH; ++j) {
            int k;

            for (k = worker_data_array[i].start; k < worker_data_array[i].end; ++k) {
                worker_data_array[i].image[j][k] = 0;
            }
        }

        pthread_create(&threads[i], NULL, worker_thread, &worker_data_array[i]);
    }

    for (i = 0; i < WORKERS; ++i) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < WORKERS; ++i) {
        for (j = 0; j < WIDTH; ++j) {
            int k;

            for (k = worker_data_array[i].start; k < worker_data_array[i].end; ++k) {
                image[j][k] = worker_data_array[i].image[j][k];
            }
        }
    }
}

int main() {
    int i, j;
    int image[WIDTH][HEIGHT];

    generate_fractal(-2.0, 1.0, -1.0, 1.0, image);

    for (i = 0; i < HEIGHT; ++i) {
        for (j = 0; j < WIDTH; ++j) {
            if (image[j][i] == MAX_ITERATIONS) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}