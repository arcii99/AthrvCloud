//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: excited
// This is going to be the most exciting implementation of a Threading Library!
// Let's create a program that utilizes the power of threads to generate the "Hello World" message in a unique way.

#include <stdio.h>
#include <pthread.h>

void* generate_hello_world(void* arg) {
    int* id = (int*) arg;
    printf("Thread %d says: ", *id);
    if (*id % 3 == 0) {
        printf("H");
        pthread_exit(NULL);
    }
    if (*id % 3 == 1) {
        printf("e");
        pthread_exit(NULL);
    }
    if (*id % 3 == 2) {
        printf("llo World\n");
        pthread_exit(NULL);
    }
}

int main() {
    const int num_threads = 9;
    pthread_t threads[num_threads];

    printf("Generating the 'Hello World' message using %d threads!\n", num_threads);

    for (int i = 0; i < num_threads; i++) {
        int* id = (int*) malloc(sizeof(int));
        *id = i;
        pthread_create(&threads[i], NULL, generate_hello_world, (void*) id);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}