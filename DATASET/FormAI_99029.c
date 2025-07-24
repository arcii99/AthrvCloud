//FormAI DATASET v1.0 Category: Fractal Generation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000

typedef struct {
    int x_start;
    int y_start;
    int x_end;
    int y_end;
} Params;

pthread_mutex_t mutex;

char color_gradient[MAX_ITERATIONS][3];

void init_color_gradient() {
    int i, j, value;
    srand(time(NULL));
    for (i = 0; i < MAX_ITERATIONS; i++) {
        for (j = 0; j < 3; j++) {
            value = rand() % 255;
            color_gradient[i][j] = value;
        }
    }
}

int mandelbrot_set(double x, double y) {
    int i;
    double z_real = 0;
    double z_imag = 0;
    double z_real_temp;

    for (i = 0; i < MAX_ITERATIONS; i++) {
        z_real_temp = z_real * z_real - z_imag * z_imag + x;
        z_imag = 2 * z_real * z_imag + y;
        z_real = z_real_temp;

        if (z_real * z_real + z_imag * z_imag > 4) {
            return i;
        }
    }

    return -1;
}

void *generate_fractal(void *arg) {
    Params *params = (Params *) arg;
    int x, y, i;

    for (x = params->x_start; x < params->x_end; x++) {
        for (y = params->y_start; y < params->y_end; y++) {
            int iterations = mandelbrot_set((double) x * 4 / WIDTH - 2, (double) y * 4 / HEIGHT - 2);

            if (iterations == -1) {
                pthread_mutex_lock(&mutex);
                printf(" ");
                pthread_mutex_unlock(&mutex);
            } else {
                pthread_mutex_lock(&mutex);
                printf("\033[48;2;%d;%d;%dm ", color_gradient[iterations][0], color_gradient[iterations][1], color_gradient[iterations][2]);
                pthread_mutex_unlock(&mutex);
            }
        }
    }
    return NULL;
}

int main() {
    pthread_t t1, t2, t3, t4;
    Params params1, params2, params3, params4;

    init_color_gradient();

    params1.x_start = 0;
    params1.y_start = 0;
    params1.x_end = WIDTH / 2;
    params1.y_end = HEIGHT / 2;

    params2.x_start = WIDTH / 2;
    params2.y_start = 0;
    params2.x_end = WIDTH;
    params2.y_end = HEIGHT / 2;

    params3.x_start = 0;
    params3.y_start = HEIGHT / 2;
    params3.x_end = WIDTH / 2;
    params3.y_end = HEIGHT;

    params4.x_start = WIDTH / 2;
    params4.y_start = HEIGHT / 2;
    params4.x_end = WIDTH;
    params4.y_end = HEIGHT;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&t1, NULL, generate_fractal, &params1);
    pthread_create(&t2, NULL, generate_fractal, &params2);
    pthread_create(&t3, NULL, generate_fractal, &params3);
    pthread_create(&t4, NULL, generate_fractal, &params4);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}