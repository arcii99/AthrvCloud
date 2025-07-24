//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define N 16
#define HEX_BASE 16
#define DEC_BASE 10
#define BUFFER_SIZE 1024

typedef struct {
    uint8_t *data;
    size_t len;
} ByteArray;

typedef struct {
    uint8_t *data;
    size_t len;
    bool done;
} ThreadData;

void *convert_thread(void *arg);

int main(int argc, char **argv) {
    // Allocate buffer for input data
    uint8_t *buffer = malloc(BUFFER_SIZE);
    if (!buffer) {
        fprintf(stderr, "Error: Failed to allocate memory for buffer\n");
        return EXIT_FAILURE;
    }

    // Read input data from stdin
    printf("Enter hexadecimal data to be converted: ");
    if (!fgets(buffer, BUFFER_SIZE, stdin)) {
        fprintf(stderr, "Error: Failed to read input data\n");
        free(buffer);
        return EXIT_FAILURE;
    }

    // Remove newline from input data
    size_t len = strlen(buffer);
    if (len == 0 || buffer[len-1] != '\n') {
        fprintf(stderr, "Error: Invalid input data\n");
        free(buffer);
        return EXIT_FAILURE;
    }
    buffer[len-1] = '\0';

    // Calculate number of threads required
    size_t num_threads = len / N;
    if (len % N != 0) num_threads++;

    // Allocate memory for thread data
    ThreadData *thread_data = malloc(num_threads * sizeof(ThreadData));
    if (!thread_data) {
        fprintf(stderr, "Error: Failed to allocate memory for thread data\n");
        free(buffer);
        return EXIT_FAILURE;
    }

    // Initialize thread data
    size_t i, j;
    for (i = 0, j = 0; i < num_threads; i++, j += N) {
        thread_data[i].data = buffer + j;
        if (len - j >= N) {
            thread_data[i].len = N;
        } else {
            thread_data[i].len = len - j;
        }
        thread_data[i].done = false;
    }

    // Create threads
    pthread_t *threads = malloc(num_threads * sizeof(pthread_t));
    if (!threads) {
        fprintf(stderr, "Error: Failed to allocate memory for threads\n");
        free(thread_data);
        free(buffer);
        return EXIT_FAILURE;
    }
    for (i = 0; i < num_threads; i++) {
        if (pthread_create(&threads[i], NULL, convert_thread, (void *) &thread_data[i])) {
            fprintf(stderr, "Error: Failed to create thread %zu\n", i);
            for (j = 0; j < i; j++) {
                pthread_cancel(threads[j]);
            }
            for (j = 0; j < num_threads; j++) {
                pthread_join(threads[j], NULL);
            }
            free(threads);
            free(thread_data);
            free(buffer);
            return EXIT_FAILURE;
        }
    }

    // Wait for threads to complete
    bool all_done = false;
    while (!all_done) {
        all_done = true;
        for (i = 0; i < num_threads; i++) {
            if (!thread_data[i].done) {
                all_done = false;
                break;
            }
        }
        usleep(1000); // 1 ms
    }

    // Print output
    printf("Converted data: ");
    for (i = 0; i < num_threads; i++) {
        fwrite(thread_data[i].data, sizeof(uint8_t), thread_data[i].len, stdout);
    }
    printf("\n");

    // Cleanup
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    free(threads);
    free(thread_data);
    free(buffer);

    return EXIT_SUCCESS;
}

void *convert_thread(void *arg) {
    ThreadData *data = (ThreadData *) arg;
    size_t i;
    for (i = 0; i < data->len; i++) {
        uint8_t c = data->data[i];
        if (c >= '0' && c <= '9') {
            data->data[i] = c - '0';
        } else if (c >= 'a' && c <= 'f') {
            data->data[i] = c - 'a' + 10;
        } else if (c >= 'A' && c <= 'F') {
            data->data[i] = c - 'A' + 10;
        } else {
            fprintf(stderr, "Error: Invalid input data\n");
            pthread_exit(NULL);
        }
    }
    data->done = true;
    pthread_exit(NULL);
}