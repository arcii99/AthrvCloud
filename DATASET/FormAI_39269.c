//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int count = 0;
int in = 0; //insert pointer
int out = 0; //remove pointer

pthread_mutex_t mutex;
pthread_cond_t full;
pthread_cond_t empty;

void *producer(void *arg) {
    int i;
    for(i = 0; i < 20; i++) {
        pthread_mutex_lock(&mutex);
        while(count == BUFFER_SIZE) {
            pthread_cond_wait(&empty, &mutex); //wait for consumer to consume
        }
        buffer[in] = rand() % 100; //producing item
        printf("Produced Item: %d\n", buffer[in]);
        in = (in + 1) % BUFFER_SIZE; //incrementing in pointer
        count++;
        pthread_cond_signal(&full); //allow consumer to consume
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int i, item;
    for(i = 0; i < 20; i++) {
        pthread_mutex_lock(&mutex);
        while(count == 0) {
            pthread_cond_wait(&full, &mutex); //wait for producer to produce
        }
        item = buffer[out]; //consuming item
        printf("Consumed Item: %d\n", item);
        out = (out + 1) % BUFFER_SIZE; //incrementing out pointer
        count--;
        pthread_cond_signal(&empty); //allow producer to produce
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc, t;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&full, NULL);
    pthread_cond_init(&empty, NULL);

    //creating producer thread
    rc = pthread_create(&threads[0], NULL, producer, NULL);
    if (rc) {
        printf("ERROR: return code from pthread_create() is %d\n", rc);
        exit(-1);
    }
    
    //creating consumer threads
    for (t = 1; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, consumer, NULL);
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    //joining threads
    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_join(threads[t], NULL);
        if (rc) {
            printf("ERROR: return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&full);
    pthread_cond_destroy(&empty);
    pthread_exit(NULL);

    return 0;
}