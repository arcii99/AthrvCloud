//FormAI DATASET v1.0 Category: Bitwise operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>

#define NUM_THREADS 2
#define BITS_PER_BYTE 8

// Bitwise operation flag for threads
#define AND_FLAG 1
#define OR_FLAG 2
#define XOR_FLAG 3

// Thread arguments struct type
typedef struct {
    uint8_t* data;      // pointer to data
    uint8_t* result;    // pointer to result
    size_t size;        // size of data and result
    uint8_t flag;       // bitwise operation flag
} thread_args_t;

// Thread function to perform bitwise operation in given range
void* bitwise_thread(void* args) {
    thread_args_t* t_args = (thread_args_t*) args;
    uint8_t* data = t_args->data;
    uint8_t* result = t_args->result;
    size_t size = t_args->size;
    uint8_t flag = t_args->flag;

    for (size_t i = 0; i < size; i++) {
        switch (flag) {
            case AND_FLAG:
                result[i] &= data[i];
                break;
            case OR_FLAG:
                result[i] |= data[i];
                break;
            case XOR_FLAG:
                result[i] ^= data[i];
                break;
        }
    }

    pthread_exit(NULL);
}

int main() {
    // Input data
    uint8_t data[] = { 0x53, 0x74, 0x72, 0x65, 0x61, 0x6d, 0x20, 0x44, 0x61, 0x74, 0x61, 0x20, 0x42, 0x69, 0x74, 0x20, 0x4f, 0x70, 0x73 };
    size_t data_size = sizeof(data) / sizeof(data[0]);

    // Result buffer
    uint8_t result[data_size];
    memset(result, 0xff, data_size);

    // Thread arguments
    thread_args_t thread_args[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i].data = data;
        thread_args[i].result = result;
        thread_args[i].size = data_size / NUM_THREADS;
        thread_args[i].flag = i + 1;
    }
    // Last thread may handle extra bytes if necessary
    size_t size_remaining = data_size % NUM_THREADS;
    if (size_remaining > 0) {
        thread_args[NUM_THREADS - 1].size += size_remaining;
    }

    // Thread handles
    pthread_t threads[NUM_THREADS];

    // Start threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, bitwise_thread, (void*) &thread_args[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print input and output in binary format
    printf("Input:\t");
    for (size_t i = 0; i < data_size; i++) {
        for (int j = BITS_PER_BYTE - 1; j >= 0; j--) {
            printf("%d", (data[i] >> j) & 1);
        }
        printf(" ");
    }
    printf("\n");

    printf("Result:\t");
    for (size_t i = 0; i < data_size; i++) {
        for (int j = BITS_PER_BYTE - 1; j >= 0; j--) {
            printf("%d", (result[i] >> j) & 1);
        }
        printf(" ");
    }
    printf("\n");

    return 0;
}