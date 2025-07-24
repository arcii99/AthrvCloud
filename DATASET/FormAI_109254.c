//FormAI DATASET v1.0 Category: Bitwise operations ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

void *bitwise_operation(void *args)
{
    int num = *(int *)args;
    printf("Thread ID: %ld\n", pthread_self());
    printf("Input Number: %d\n", num);

    unsigned int mask = 0xAAAAAAAA; // Binary pattern: 1010..1010
    int even_bits = num & mask; 
    mask = 0x55555555; // Binary pattern: 0101..0101
    int odd_bits = num & mask;           
    even_bits >>= 1;  // Right shift even bits
    odd_bits <<= 1;   // Left shift odd bits
    int result = even_bits | odd_bits;

    printf("Result: %d\n\n", result);

    pthread_exit(NULL);
}

int main()
{
    int numbers[] = { 10, 20, 30, 40, 50 };
    pthread_t threads[5];
    int rc;

    for (int i = 0; i < 5; i++) {
        rc = pthread_create(&threads[i], NULL, bitwise_operation, &numbers[i]);
        if (rc) {
            printf("Error creating thread %d\n", i);
            return 1;
        }
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}