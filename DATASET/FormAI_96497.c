//FormAI DATASET v1.0 Category: Bitwise operations ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

// global variables
int a = 12345;
int b = 67890;

// bitwise AND operation function
void *bitwise_and(void *arg) {
    int result = a & b;
    printf("Bitwise AND operation of %d and %d is %d\n", a, b, result);
    pthread_exit(NULL);
}

// bitwise OR operation function
void *bitwise_or(void *arg) {
    int result = a | b;
    printf("Bitwise OR operation of %d and %d is %d\n", a, b, result);
    pthread_exit(NULL);
}

// bitwise XOR operation function
void *bitwise_xor(void *arg) {
    int result = a ^ b;
    printf("Bitwise XOR operation of %d and %d is %d\n", a, b, result);
    pthread_exit(NULL);
}

int main() {
    // declaring threads
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;

    // creating threads
    pthread_create(&t1, NULL, &bitwise_and, NULL);
    pthread_create(&t2, NULL, &bitwise_or, NULL);
    pthread_create(&t3, NULL, &bitwise_xor, NULL);

    // waiting for the threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("Program finished.\n");

    return 0;
}