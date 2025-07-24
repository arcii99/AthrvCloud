//FormAI DATASET v1.0 Category: Interprocess communication ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 10
#define NUM_THREADS 5

typedef struct {
    char buffer[BUFFER_SIZE][256];
    int in;
    int out;
    sem_t empty;
    sem_t full;
    pthread_mutex_t mutex;
} CircularBuffer;

CircularBuffer cb;

void *producer(void *arg) {
    char msg[256];
    int index = 0;
    while (index < 10) {
        // generate message
        sprintf(msg, "Message %d from thread %d", index, *(int*)arg);

        sem_wait(&cb.empty);
        pthread_mutex_lock(&cb.mutex);

        // add message to buffer
        strcpy(cb.buffer[cb.in], msg);
        cb.in = (cb.in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&cb.mutex);
        sem_post(&cb.full);

        printf("Producer %d produced message: %s\n", *(int*)arg, msg);

        index++;
        sleep(1);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    char msg[256];
    int index = 0;
    while (index < 10) {
        sem_wait(&cb.full);
        pthread_mutex_lock(&cb.mutex);

        // remove message from buffer
        strcpy(msg, cb.buffer[cb.out]);
        cb.out = (cb.out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&cb.mutex);
        sem_post(&cb.empty);

        printf("Consumer %d consumed message: %s\n", *(int*)arg, msg);

        index++;
        sleep(2);
    }
    pthread_exit(NULL);
}

int main() {
    int i, rc;
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS] = {0, 1, 2, 3, 4};

    // initialization
    cb.in = 0;
    cb.out = 0;
    sem_init(&cb.empty, 0, BUFFER_SIZE);
    sem_init(&cb.full, 0, 0);
    pthread_mutex_init(&cb.mutex, NULL);

    // create producer threads
    for (i = 0; i < 3; i++) {
        rc = pthread_create(&threads[i], NULL, producer, (void*)&thread_ids[i]);
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // create consumer threads
    for (i = 3; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, consumer, (void*)&thread_ids[i]);
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // join threads
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error: return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }

    // cleanup
    sem_destroy(&cb.empty);
    sem_destroy(&cb.full);
    pthread_mutex_destroy(&cb.mutex);

    return 0;
}