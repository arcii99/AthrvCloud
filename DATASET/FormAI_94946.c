//FormAI DATASET v1.0 Category: Fractal Generation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 8
#define MAX_ITERATIONS 10000
#define WIDTH 60
#define HEIGHT 60

char pixels[HEIGHT][WIDTH];

typedef struct {
    double x0;
    double y0;
    double x1;
    double y1;
} rectangle;

rectangle work[MAX_THREADS];
pthread_mutex_t mutex;
int next_thread = 0;

void compute(double x, double y, int *iterations) {
    double xt, yt, x_new;
    int i;

    *iterations = 0;
    xt = x;
    yt = y;

    for (i = 0; i < MAX_ITERATIONS; i++) {
        x_new = xt * xt - yt * yt + x;
        yt = 2 * xt * yt + y;
        xt = x_new;
        (*iterations)++;
        if (xt * xt + yt * yt > 4)
            break;
    }
}

void draw_rectangle(rectangle rect) {
    int x, y, iterations;

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            compute(rect.x0 + (double) x / WIDTH * (rect.x1 - rect.x0),
                    rect.y0 + (double) y / HEIGHT * (rect.y1 - rect.y0),
                    &iterations);

            if (iterations == MAX_ITERATIONS)
                pixels[y][x] = '*';
            else if (iterations > MAX_ITERATIONS / 2)
                pixels[y][x] = '+';
            else if (iterations > MAX_ITERATIONS / 5)
                pixels[y][x] = '.';
            else
                pixels[y][x] = ' ';
        }
    }
}

void *worker(void *args) {
    rectangle *work_item;
    pthread_t id = pthread_self();

    while (1) {
        pthread_mutex_lock(&mutex);
        if (next_thread == MAX_THREADS) {
            pthread_mutex_unlock(&mutex);
            break;
        }
        work_item = &work[next_thread++];
        printf("Thread %ld is working on rectangle (%f,%f) to (%f,%f)\n",
               id, work_item->x0, work_item->y0, work_item->x1, work_item->y1);
        pthread_mutex_unlock(&mutex);

        draw_rectangle(*work_item);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    int i;

    for (i = 0; i < MAX_THREADS; i++) {
        work[i].x0 = (double) (i % 3) / 3 - 0.5;
        work[i].y0 = (double) (i / 3) / 3 - 0.5;
        work[i].x1 = work[i].x0 + 0.333;
        work[i].y1 = work[i].y0 + 0.333;
    }

    pthread_mutex_init(&mutex, NULL);

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, worker, NULL);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    for (i = 0; i < HEIGHT; i++) {
        puts(pixels[i]);
    }

    return EXIT_SUCCESS;
}