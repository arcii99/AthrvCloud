//FormAI DATASET v1.0 Category: Bitwise operations ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

// Function to perform bitwise AND operation
void* bitwise_AND(void* num_ptr) {
    int* num = (int*) num_ptr;
    *num &= 0xFF;
    printf("Bitwise AND Result: %d\n", *num);
    pthread_exit(NULL);
}

// Function to perform bitwise OR operation
void* bitwise_OR(void* num_ptr) {
    int* num = (int*) num_ptr;
    *num |= 0xFF00;
    printf("Bitwise OR Result: %d\n", *num);
    pthread_exit(NULL);
}

// Function to perform bitwise XOR operation
void* bitwise_XOR(void* num_ptr) {
    int* num = (int*) num_ptr;
    *num ^= 0xFFFF;
    printf("Bitwise XOR Result: %d\n", *num);
    pthread_exit(NULL);
}

int main() {
    int num = 0x1234;

    printf("Starting Multi-threaded Bitwise Operation Program...\n\n");

    pthread_t tid_AND, tid_OR, tid_XOR;

    // Create thread for AND operation
    if(pthread_create(&tid_AND, NULL, bitwise_AND, (void*) &num)) {
        printf("\nError creating AND thread");
        return 1;
    }

    // Create thread for OR operation
    if(pthread_create(&tid_OR, NULL, bitwise_OR, (void*) &num)) {
        printf("\nError creating OR thread");
        return 1;
    }

    // Create thread for XOR operation
    if(pthread_create(&tid_XOR, NULL, bitwise_XOR, (void*) &num)) {
        printf("\nError creating XOR thread");
        return 1;
    }

    // Wait for all threads to finish
    if(pthread_join(tid_AND, NULL)) {
        printf("\nError: Thread AND join failed");
        return 1;
    }
    if(pthread_join(tid_OR, NULL)) {
        printf("\nError: Thread OR join failed");
        return 1;
    }
    if(pthread_join(tid_XOR, NULL)) {
        printf("\nError: Thread XOR join failed");
        return 1;
    }

    printf("\nFinal Result: %d\n", num);

    return 0;
}