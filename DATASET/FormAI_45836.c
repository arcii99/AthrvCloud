//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define MAX_BUFFER_SIZE 100
#define MAX_THREADS 10

// Global Variables
char* buffer;
int count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t notfull = PTHREAD_COND_INITIALIZER; 
pthread_cond_t notempty = PTHREAD_COND_INITIALIZER;

// Function to generate random buffer data
void generate_buffer_data(char* buffer) {
    int i;
    for(i=0; i<MAX_BUFFER_SIZE; i++){
        buffer[i] = '0' + rand()%10;
    }
}

// Function for producer thread
void* producer(void* arg) {
    while(1) {
        pthread_mutex_lock(&mutex);
        while(count == MAX_BUFFER_SIZE) {
            pthread_cond_wait(&notfull, &mutex);
        }
        generate_buffer_data(buffer);
        count++;
        printf("Produced: %s\n", buffer);
        pthread_cond_signal(&notempty);
        pthread_mutex_unlock(&mutex);
        usleep(1000); // Sleep for 1ms
    }
    return NULL;
}

// Function for consumer thread
void* consumer(void* arg) {
    while(1) {
        pthread_mutex_lock(&mutex);
        while(count == 0) {
            pthread_cond_wait(&notempty, &mutex);
        }
        count--;
        printf("Consumed: %s\n", buffer);
        pthread_cond_signal(&notfull);
        pthread_mutex_unlock(&mutex);
        usleep(1000); // Sleep for 1ms
    }
    return NULL;
}

int main() {
    // Dynamic Memory Allocation
    buffer = (char*) malloc(MAX_BUFFER_SIZE * sizeof(char));
    if(buffer == NULL) {
        printf("Memory Allocation error!\n");
        return -1;
    }

    // Thread Creation
    pthread_t threads[MAX_THREADS];
    int i;
    for(i=0; i<MAX_THREADS/2; i++) {
        pthread_create(&threads[i], NULL, producer, NULL);
    }
    for(i=MAX_THREADS/2; i<MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, consumer, NULL);
    }

    // Thread Wait
    for(i=0; i<MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}