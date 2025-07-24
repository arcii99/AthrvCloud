//FormAI DATASET v1.0 Category: Image compression ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4 // number of threads to use

// function to perform image compression
void *compress_image(void *thread_id) {
    // allocate memory for compressed image
    char *compressed_image = (char*) malloc(1000 * sizeof(char));

    // perform compression algorithm here

    // print thread ID and result
    printf("Thread %ld: Compressed image of size %d.\n", (long) thread_id, (int) sizeof(compressed_image));

    // exit thread
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS]; // array of threads
    int rc; // to check thread creation status
    long t; // thread ID variable

    // create threads
    for(t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, compress_image, (void*) t);
        if(rc) {
            printf("Error: Return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // wait for threads to finish
    for(t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    // print final message
    printf("All threads completed.\n");

    // exit main thread
    pthread_exit(NULL);
}