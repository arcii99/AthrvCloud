//FormAI DATASET v1.0 Category: Bitwise operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int a = 8;  // decimal equivalent of 1000 in binary
int b = 5;  // decimal equivalent of 0101 in binary

void *shift_left(void *tid) {  // Thread function to perform the left shift operation
    printf("Thread %ld: Performing the left shift operation\n", (long) tid);
    printf("Before left shift: a = %d (binary: %d), b = %d (binary: %d)\n", a, a, b, b);
    a = a << 3;  // Shift a to the left by 3 bits (equal to multiplication by 8)
    b = b << 2;  // Shift b to the left by 2 bits (equal to multiplication by 4)
    printf("After left shift: a = %d (binary: %d), b = %d (binary: %d)\n", a, a, b, b);
    pthread_exit(NULL);
}

void *bitwise_and(void *tid) {  // Thread function to perform the bitwise AND operation
    printf("Thread %ld: Performing the bitwise AND operation\n", (long) tid);
    printf("Before bitwise AND: a = %d (binary: %d), b = %d (binary: %d)\n", a, a, b, b);
    int result = a & b;  // Perform bitwise AND on a and b
    printf("Result of bitwise AND: %d (binary: %d)\n", result, result);
    pthread_exit(NULL);
}

void *bitwise_or(void *tid) {  // Thread function to perform the bitwise OR operation
    printf("Thread %ld: Performing the bitwise OR operation\n", (long) tid);
    printf("Before bitwise OR: a = %d (binary: %d), b = %d (binary: %d)\n", a, a, b, b);
    int result = a | b;  // Perform bitwise OR on a and b
    printf("Result of bitwise OR: %d (binary: %d)\n", result, result);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];  // Create 3 threads
    int rc;

    // Create thread 1 to perform the left shift operation
    rc = pthread_create(&threads[0], NULL, shift_left, (void *) 0);
    if (rc) {
        printf("ERROR: Return code from pthread_create() for thread 1 is %d\n", rc);
        exit(-1);
    }

    // Create thread 2 to perform the bitwise AND operation
    rc = pthread_create(&threads[1], NULL, bitwise_and, (void *) 1);
    if (rc) {
        printf("ERROR: Return code from pthread_create() for thread 2 is %d\n", rc);
        exit(-1);
    }

    // Create thread 3 to perform the bitwise OR operation
    rc = pthread_create(&threads[2], NULL, bitwise_or, (void *) 2);
    if (rc) {
        printf("ERROR: Return code from pthread_create() for thread 3 is %d\n", rc);
        exit(-1);
    }

    // Wait for all threads to complete
    for (int i = 0; i < 3; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("ERROR: Return code from pthread_join() for thread %d is %d\n", i+1, rc);
            exit(-1);
        }
    }

    printf("All threads have completed execution.\n");
    return 0;
}