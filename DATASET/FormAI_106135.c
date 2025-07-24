//FormAI DATASET v1.0 Category: Interprocess communication ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
pthread_mutex_t mutex;
pthread_cond_t produce_condition;
pthread_cond_t consume_condition;

void produce(int item)
{
    pthread_mutex_lock(&mutex);
    while((in + 1) % BUFFER_SIZE == out)
        pthread_cond_wait(&produce_condition, &mutex);
    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;
    printf("Producer produces %d\n", item);
    pthread_cond_signal(&consume_condition);
    pthread_mutex_unlock(&mutex);
}

int consume()
{
    int item;
    pthread_mutex_lock(&mutex);
    while(in == out)
        pthread_cond_wait(&consume_condition, &mutex);
    item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    printf("Consumer consumes %d\n", item);
    pthread_cond_signal(&produce_condition);
    pthread_mutex_unlock(&mutex);
    return item;
}

void *producer(void *arg)
{
    int i, item;
    for(i = 1; i <= BUFFER_SIZE; i++){
        item = rand() % 50;
        produce(item);
        sleep(1);
    }
    return NULL;
}

void *consumer(void *arg)
{
    int i, item;
    for(i = 1; i <= BUFFER_SIZE; i++){
        item = consume();
        sleep(2);
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t thread_producer, thread_consumer;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&produce_condition, NULL);
    pthread_cond_init(&consume_condition, NULL);
    pthread_create(&thread_producer, NULL, producer, NULL);
    pthread_create(&thread_consumer, NULL, consumer, NULL);
    pthread_join(thread_producer, NULL);
    pthread_join(thread_consumer, NULL);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&produce_condition);
    pthread_cond_destroy(&consume_condition);
    return 0;
}