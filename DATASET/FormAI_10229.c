//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

int network_qos = 0;
int threshold = 50;

pthread_mutex_t network_qos_lock;
pthread_cond_t network_qos_threshold;

void *monitor_network_qos(void *data) {
    int *id = (int *) data;
    printf("Thread %d started monitoring network QoS.\n", *id);

    while (1) {
        pthread_mutex_lock(&network_qos_lock);

        while (network_qos <= threshold) {
            pthread_cond_wait(&network_qos_threshold, &network_qos_lock);
        }

        printf("Thread %d: Network QoS (%d) is above threshold (%d)!\n", *id, network_qos, threshold);
        pthread_mutex_unlock(&network_qos_lock);
    }

    pthread_exit(NULL);
}

void *update_network_qos(void *data) {
    int *id = (int *) data;
    printf("Thread %d started updating network QoS.\n", *id);

    while (1) {
        int new_qos = rand() % 101;

        pthread_mutex_lock(&network_qos_lock);
        network_qos = new_qos;
        printf("Thread %d: Network QoS updated to %d.\n", *id, network_qos);

        if (network_qos > threshold) {
            pthread_cond_signal(&network_qos_threshold);
        }

        pthread_mutex_unlock(&network_qos_lock);

        usleep(500000); // Wait for 500 ms before updating again
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    pthread_mutex_init(&network_qos_lock, NULL);
    pthread_cond_init(&network_qos_threshold, NULL);

    // Start monitor and update threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i + 1;

        if (i == 0) {
            pthread_create(&threads[i], NULL, monitor_network_qos, &thread_ids[i]);
        } else {
            pthread_create(&threads[i], NULL, update_network_qos, &thread_ids[i]);
        }
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&network_qos_lock);
    pthread_cond_destroy(&network_qos_threshold);

    return 0;
}