//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int bufferSize = 5;  // size of buffer
int buffer[5];      // buffer array
int itemCount = 0;  // number of items in buffer

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;   // mutex for buffer
pthread_cond_t full = PTHREAD_COND_INITIALIZER;     // condition variable for buffer full
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;    // condition variable for buffer empty

// producer function
void* producer(void* arg) {
    int item = 0;
    while(1) {
        pthread_mutex_lock(&mutex);  // acquire mutex

        while(itemCount == bufferSize) {  // wait if buffer is full
            printf("Buffer is full!\n");
            pthread_cond_wait(&full, &mutex);
        }

        buffer[itemCount] = item;  // add item to buffer
        itemCount++;               // increase number of items in buffer
        printf("Produced item %d\n", item);
        item++;

        pthread_cond_signal(&empty);    // signal that buffer is not empty
        pthread_mutex_unlock(&mutex);   // release mutex
    }
}

// consumer function
void* consumer(void* arg) {
    while(1) {
        pthread_mutex_lock(&mutex);  // acquire mutex

        while(itemCount == 0) {  // wait if buffer is empty
            printf("Buffer is empty!\n");
            pthread_cond_wait(&empty, &mutex);
        }

        int item = buffer[itemCount-1];  // get last item from buffer
        itemCount--;                    // decrease number of items in buffer
        printf("Consumed item %d\n", item);

        pthread_cond_signal(&full);     // signal that buffer is not full
        pthread_mutex_unlock(&mutex);   // release mutex
    }
}

int main() {
    pthread_t prod, cons;   // threads for producer and consumer
    pthread_create(&prod, NULL, producer, NULL);  // create producer thread
    pthread_create(&cons, NULL, consumer, NULL);  // create consumer thread
    pthread_join(prod, NULL);   // join producer thread
    pthread_join(cons, NULL);   // join consumer thread
    return 0;
}