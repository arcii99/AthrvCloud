//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t mutex;
int items = 0; // total items in warehouse
int MAX_ITEMS = 20; // maximum items capacity

void *producer(){
    while(1){
        pthread_mutex_lock(&mutex);
        if(items == MAX_ITEMS){
            printf("Warehouse is full. Producer thread waiting\n");
            pthread_mutex_unlock(&mutex);
            sleep(2); // wait for consumer to clear some space
        } else {
            int produced = rand() % 5 + 1; // produce random number of items (1-5)
            items += produced;
            printf("Producer produced %d items. Total items in warehouse: %d\n", produced, items);
            pthread_mutex_unlock(&mutex);
            sleep(1); // wait for some time before producing again
        }
    }
}

void *consumer(){
    while(1){
        pthread_mutex_lock(&mutex);
        if(items == 0){
            printf("Warehouse is empty. Consumer thread waiting\n");
            pthread_mutex_unlock(&mutex);
            sleep(2); // wait for producer to produce some items
        } else {
            int consumed = rand() % 3 + 1; // consume random number of items (1-3)
            if(items < consumed){
                consumed = items; // if there are less items than consumed, consume only available items
            }
            items -= consumed;
            printf("Consumer consumed %d items. Total items in warehouse: %d\n", consumed, items);
            pthread_mutex_unlock(&mutex);
            sleep(1); // wait for some time before consuming again
        }
    }
}

int main(){
    srand(time(0));
    pthread_t producer_thread, consumer_thread;
    pthread_mutex_init(&mutex, NULL); // initialize mutex lock

    // create producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // wait for producer and consumer threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    pthread_mutex_destroy(&mutex); // destroy mutex lock
    return 0;
}