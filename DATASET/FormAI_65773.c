//FormAI DATASET v1.0 Category: Bitwise operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* bitwise operations function */
void *bitwise_operation(void *arg) {
    unsigned int value = *((unsigned int *)arg);
    unsigned int result;

    /* perform AND operation with a random number */
    result = value & (rand() % 65535);
    printf("And operation: %u & %u = %u\n", value, rand() % 65535, result);

    /* perform OR operation with a random number */
    result = value | (rand() % 65535);
    printf("Or operation: %u | %u = %u\n", value, rand() % 65535, result);

    /* perform XOR operation with a random number */
    result = value ^ (rand() % 65535);
    printf("Xor operation: %u ^ %u = %u\n", value, rand() % 65535, result);

    /* perform left shift by 1 operation */
    result = value << 1;
    printf("Left shift by 1: %u << 1 = %u\n", value, result);

    /* perform right shift by 1 operation */
    result = value >> 1;
    printf("Right shift by 1: %u >> 1 = %u\n", value, result);

    pthread_exit(NULL);
}

int main() {
    int n_threads = 5;
    pthread_t threads[n_threads];
    unsigned int values[n_threads];

    /* initialize random number generator */
    srand(time(NULL));

    /* create threads */
    for(int i=0; i<n_threads; i++) {
        values[i] = rand() % 65535;
        pthread_create(&threads[i], NULL, bitwise_operation, (void *)&values[i]);
    }

    /* wait for threads to finish */
    for(int i=0; i<n_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}