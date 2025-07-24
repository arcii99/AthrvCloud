//FormAI DATASET v1.0 Category: Stock market tracker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

float stockPrice;

pthread_mutex_t mutex;

void *monitorStock(void *arg){
    while(1){
        pthread_mutex_lock(&mutex);
        printf("Current stock price: %.2f\n", stockPrice);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void *updateStock(void *arg){
    while(1){
        float change = ((float)rand()/(float)(RAND_MAX)) * 2 - 1; //generating random change between -1 and 1
        pthread_mutex_lock(&mutex);
        stockPrice += change;
        pthread_mutex_unlock(&mutex);
        sleep(5);
    }
}

int main(){
    pthread_t monitor, update;
    pthread_mutex_init(&mutex, NULL);
    stockPrice = 100.0; //starting stock price
    pthread_create(&monitor, NULL, monitorStock, NULL);
    pthread_create(&update, NULL, updateStock, NULL);
    pthread_join(monitor, NULL);
    pthread_join(update, NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}