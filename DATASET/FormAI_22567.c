//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 5

pthread_mutex_t lock;

int network_bandwidth = 100; // in Mbps

void* check_network_qos(void* arg) {
    int* thread_id = (int*) arg;

    while(1) {
        // Attempt to acquire mutex lock
        pthread_mutex_lock(&lock);

        // Simulate network load
        int random_load = rand() % 30 + 1; // Random load from 1 to 30 Mbps
        network_bandwidth -= random_load;

        // Display network bandwidth and thread ID
        printf("Thread %d: Network bandwidth remaining: %d Mbps\n", *thread_id, network_bandwidth);

        // Release mutex lock
        pthread_mutex_unlock(&lock);

        // Sleep for random time between 1 and 5 seconds before checking again
        sleep(rand() % 5 + 1);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];

    // Initialize mutex lock
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Mutex init failed.");
        return 1;
    }

    // Initialize threads
    for(int i=0; i < MAX_THREADS; i++) {
        thread_ids[i] = i+1;
        if (pthread_create(&threads[i], NULL, check_network_qos, (void*) &thread_ids[i]) != 0) {
            printf("Thread creation failed.");
            return 1;
        }
    }

    // Wait for threads to finish
    for(int i=0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy mutex lock
    pthread_mutex_destroy(&lock);

    return 0;
}