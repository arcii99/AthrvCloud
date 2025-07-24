//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2
#define POINTS 1000000

double counter = 0.0;

struct thread_data {
    int thread_id;
    int start;
    int end;
};

void *thread_func(void *arg) {
    struct thread_data *data = (struct thread_data*) arg;
    int i;
    double x, y;

    for (i = data->start; i < data->end; i++) {
        x = (double) rand() / RAND_MAX;
        y = (double) rand() / RAND_MAX;

        if ((x * x + y * y) <= 1.0) {
            counter++;
        }
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    struct thread_data thread_data_arr[NUM_THREADS];
    int i, rc;
    void *status;

    srand(time(NULL));

    for (i = 0; i < NUM_THREADS; i++) {
        thread_data_arr[i].thread_id = i;
        thread_data_arr[i].start = i * POINTS / NUM_THREADS;
        thread_data_arr[i].end = (i + 1) * POINTS / NUM_THREADS;

        rc = pthread_create(&threads[i], NULL, thread_func, (void*) &thread_data_arr[i]);

        if (rc) {
            printf("Error creating thread %d\n", i);
            exit(-1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], &status);

        if (rc) {
            printf("Error joining thread %d\n", i);
            exit(-1);
        }
    }

    double pi = 4.0 * counter / POINTS;

    printf("The value of pi is: %f\n", pi);

    pthread_exit(NULL);
}