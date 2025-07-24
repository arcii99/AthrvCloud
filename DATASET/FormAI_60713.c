//FormAI DATASET v1.0 Category: Bitwise operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>

#define NUM_THREADS 3
#define BITMASK 0xFF

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static volatile uint8_t result = 0x0;

void *bitset(void *arg) {
    uint8_t *input = (uint8_t *)arg;
    pthread_mutex_lock(&mutex);
    result = result | *input;
    pthread_mutex_unlock(&mutex);
    printf("Bitwise OR operation performed: %x\n", *input);
    pthread_exit(NULL);
}

void *bitreset(void *arg) {
    uint8_t *input = (uint8_t *)arg;
    pthread_mutex_lock(&mutex);
    result = result & ~(*input);
    pthread_mutex_unlock(&mutex);
    printf("Bitwise AND operation performed: %x\n", ~(*input));
    pthread_exit(NULL);
}

void *bitshift(void *arg) {
    uint8_t *input = (uint8_t *)arg;
    pthread_mutex_lock(&mutex);
    result = result << *input;
    pthread_mutex_unlock(&mutex);
    printf("Left bitshift operation performed: %x\n", *input);
    pthread_exit(NULL);
}

int main() {
    uint8_t inputs[NUM_THREADS] = {0x3, 0x7, 0x5};
    pthread_t threads[NUM_THREADS];
    int thread_status;

    for (int i = 0; i < NUM_THREADS; i++) {
        switch(i) {
            case 0:
                thread_status = pthread_create(&threads[i], NULL, bitset, (void *)(&inputs[i]));
                break;
            case 1:
                thread_status = pthread_create(&threads[i], NULL, bitreset, (void *)(&inputs[i]));
                break;
            case 2:
                thread_status = pthread_create(&threads[i], NULL, bitshift, (void *)(&inputs[i]));
                break;
            default:
                printf("Invalid thread index: %d\n", i);
                exit(1);
        }
        if (thread_status != 0) {
            printf("Failed to create thread %d. Exiting program.\n", i);
            exit(1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_status = pthread_join(threads[i], NULL);
        if (thread_status != 0) {
            printf("Failed to join thread %d. Exiting program.\n", i);
            exit(1);
        }
    }

    printf("Final result: %x\n", result);

    return 0;
}