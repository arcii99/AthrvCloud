//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

int fuel = 100; // Initial fuel level
int distance = 0; // Initial distance travelled
int aliens = 0; // Initial number of aliens encountered

pthread_mutex_t fuel_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t distance_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t aliens_mutex = PTHREAD_MUTEX_INITIALIZER;

void* travel(void *thread_id) {
    long tid;
    tid = (long) thread_id;
    
    printf("Thread %ld starting space travel...\n", tid);
    
    while(fuel > 0) {
        
        // Simulate flying through space
        printf("Distance travelled: %d.\n", distance);
        distance += rand()%10 + 1;
        
        // Check for alien encounters
        if(rand()%10 == 0) {
            printf("Alien encountered!\n");
            pthread_mutex_lock(&aliens_mutex);
            aliens++;
            pthread_mutex_unlock(&aliens_mutex);
        }
        
        // Consume fuel
        pthread_mutex_lock(&fuel_mutex);
        fuel--;
        pthread_mutex_unlock(&fuel_mutex);
    }
    
    printf("Thread %ld finished space travel. Fuel empty.\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    
    for(t = 0; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, travel, (void*)t);
        if(rc) {
            printf("Error: return code from pthread_create() is %d", rc);
            exit(-1);
        }
    }
    
    // Wait for all threads to finish
    for(t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }
    
    // Print final results
    printf("Fuel remaining: %d.\n", fuel);
    printf("Distance travelled: %d.\n", distance);
    printf("Aliens encountered: %d.\n", aliens);
    
    // Destroy mutexes
    pthread_mutex_destroy(&fuel_mutex);
    pthread_mutex_destroy(&distance_mutex);
    pthread_mutex_destroy(&aliens_mutex);
    
    pthread_exit(NULL);
}