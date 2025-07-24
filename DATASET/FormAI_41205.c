//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

// Constants
#define MAX_QOS_LEVEL 5
#define MIN_QOS_LEVEL 1
#define DEFAULT_QOS_LEVEL 3
#define MAX_THREADS 10

// Global variables
int qos_level = DEFAULT_QOS_LEVEL;
pthread_t threads[MAX_THREADS];
sem_t sem;

// Thread function
void *worker(void *ptr) {
    int thread_id = *(int*) ptr;
    printf("Thread %d started with QoS level %d\n", thread_id, qos_level);
    sem_wait(&sem); // wait for QoS change
    printf("Thread %d QoS level changed to %d\n", thread_id, qos_level);
    sem_post(&sem); // release semaphore
    printf("Thread %d exiting\n", thread_id);
    pthread_exit(NULL);
}

// QoS management function
void manage_qos() {
    int new_qos_level;
    printf("Enter new QoS level (1-5): ");
    scanf("%d", &new_qos_level);
    if (new_qos_level >= MIN_QOS_LEVEL && new_qos_level <= MAX_QOS_LEVEL) {
        qos_level = new_qos_level;
        sem_post(&sem); // release semaphore to allow threads to update QoS level
        printf("New QoS level set to %d\n", qos_level);
    } else {
        printf("Invalid QoS level\n");
    }
}

int main() {
    int i;
    // Initialize semaphore
    sem_init(&sem, 0, 0);
    // Create threads
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, &worker, &i);
    }
    // Wait for input and manage QoS
    while (1) {
        char c;
        printf("Press 'q' to quit or 'c' to change QoS level: ");
        scanf(" %c", &c);
        if (c == 'q') {
            break;
        } else if (c == 'c') {
            manage_qos();
        }
    }
    // Join threads
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    // Destroy semaphore
    sem_destroy(&sem);
    return 0;
}