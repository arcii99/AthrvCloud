//FormAI DATASET v1.0 Category: Computer Biology ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 4

int genome[100]; // array to hold genome
pthread_rwlock_t lock; // read-write lock

// function to mutate genome
void* mutate_genome(void* threadid) {
    long tid;
    tid = (long)threadid;
    sleep(1); // simulate a mutation process
    pthread_rwlock_wrlock(&lock); // acquire write lock
    genome[20*tid] = rand() % 4; // randomly change one base pair for each thread
    printf("Thread %ld mutated the genome at position %d\n", tid, 20*tid);
    pthread_rwlock_unlock(&lock); // release write lock
    pthread_exit(NULL);
}

// function to print genome
void* print_genome(void* msg) {
    pthread_rwlock_rdlock(&lock); // acquire read lock
    printf("%s", (char*)msg);
    for (int i = 0; i < 100; i++) {
        printf("%d ", genome[i]);
    }
    printf("\n");
    pthread_rwlock_unlock(&lock); // release read lock
    pthread_exit(NULL);
}

int main() {
    srand(time(0)); // seed random number generator
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    
    // initialize genome with random base pairs
    for (int i = 0; i < 100; i++) {
        genome[i] = rand() % 4;
    }
    
    // initialize read-write lock
    if (pthread_rwlock_init(&lock, NULL) != 0) {
        printf("Error initializing lock\n");
        exit(1);
    }
    
    // create threads to mutate the genome
    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, mutate_genome, (void*) t);
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(1);
        }
    }
    
    // join threads
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }
    
    // print mutated genome
    rc = pthread_create(&threads[NUM_THREADS], NULL, print_genome, "Mutated genome: ");
    if (rc) {
        printf("Error: return code from pthread_create() is %d\n", rc);
        exit(1);
    }
    
    // create threads to mutate the genome again
    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, mutate_genome, (void*) t);
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(1);
        }
    }
    
    // join threads
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }
    
    // print mutated genome again
    rc = pthread_create(&threads[NUM_THREADS], NULL, print_genome, "Mutated genome again: ");
    if (rc) {
        printf("Error: return code from pthread_create() is %d\n", rc);
        exit(1);
    }
    
    pthread_rwlock_destroy(&lock); // destroy read-write lock
    pthread_exit(NULL);
}