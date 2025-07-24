//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;

void* producer(void* arg){
    int i;
    for(i=0; i<20; i++){
        pthread_mutex_lock(&mutex);
        while((in+1)%BUFFER_SIZE == out){
            printf("Buffer is full!\n");
            pthread_cond_wait(&full, &mutex);
        }
        buffer[in] = i;
        in = (in+1) % BUFFER_SIZE;
        printf("Producer produces: %d\n", i);
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* consumer(void* arg){
    int i, item;
    while(1){
        pthread_mutex_lock(&mutex);
        while(in == out){
            printf("Buffer is empty!\n");
            pthread_cond_wait(&empty, &mutex);
        }
        item = buffer[out];
        out = (out+1) % BUFFER_SIZE;
        printf("Consumer consumes: %d\n", item);
        pthread_cond_signal(&full);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(){
    pthread_t p1, c1;
    pthread_create(&p1, NULL, producer, NULL);
    pthread_create(&c1, NULL, consumer, NULL);

    pthread_join(p1, NULL);
    pthread_join(c1, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&full);
    pthread_cond_destroy(&empty);

    return 0;
}