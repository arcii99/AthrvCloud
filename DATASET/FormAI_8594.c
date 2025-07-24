//FormAI DATASET v1.0 Category: File handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define DATA_LEN 100
#define THREAD_COUNT 5

struct thread_data {
    int start;
    int end;
};

void *file_write_thread(void *arg) {
    struct thread_data *data = (struct thread_data*) arg;

    FILE *fp;
    fp = fopen("data.txt", "a");

    for (int i = data->start; i < data->end; i++) {
        fprintf(fp, "%d\n", i);
    }

    fclose(fp);

    pthread_exit(NULL);
}

int main() {
    // generate data
    int data[DATA_LEN];

    for (int i = 0; i < DATA_LEN; i++) {
        data[i] = i;
    }

    // divide data among threads
    struct thread_data thread_args[THREAD_COUNT];
    int data_per_thread = DATA_LEN / THREAD_COUNT;

    for (int i = 0; i < THREAD_COUNT; i++) {
        thread_args[i].start = i * data_per_thread;
        thread_args[i].end = (i + 1) * data_per_thread;

        if (i == THREAD_COUNT - 1) {
            // last thread takes any remaining data
            thread_args[i].end = DATA_LEN;
        }
    }

    // create threads and run file write function
    pthread_t threads[THREAD_COUNT];

    for (int i = 0; i < THREAD_COUNT; i++) {
        int rc = pthread_create(&threads[i], NULL, file_write_thread, (void*) &thread_args[i]);

        if (rc) {
            printf("Error creating thread %d. Return code: %d\n", i, rc);
            exit(-1);
        }
    }

    // join threads
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("File write complete.");

    return 0;
}