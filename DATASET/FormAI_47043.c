//FormAI DATASET v1.0 Category: Database querying ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

typedef struct {
    int age;
    char name[20];
    float balance;
} Account;

Account accounts[5] = {
    {24, "Alice", 100.00},
    {31, "Bob", 250.00},
    {42, "Charlie", 75.50},
    {55, "Dave", 500.00},
    {19, "Eve", 5.00}
};

void* threadFunc(void* threadId) {
    int tid = *((int*) threadId);
    printf("Thread %d querying database...\n", tid);
    for (int i = 0; i < 5; i++) {
        if (accounts[i].balance > 100.00) {
            printf("%s has a balance over $100.00\n", accounts[i].name);
        }
    }
    printf("Thread %d finished querying database.\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadIds[NUM_THREADS];

    printf("Starting database querying program...\n");

    for (int i = 0; i < NUM_THREADS; i++) {
        threadIds[i] = i;
        if (pthread_create(&threads[i], NULL, threadFunc, &threadIds[i])) {
            printf("Error creating thread %d\n", i);
            exit(-1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads finished executing.\n");

    return 0;
}