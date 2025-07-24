//FormAI DATASET v1.0 Category: Stock market tracker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_STOCKS 5

float stocks[NUM_STOCKS];
int update_count[NUM_STOCKS];
pthread_mutex_t stock_mutex[NUM_STOCKS];

void* track_stock(void* arg) {
    int stock_index = *((int*) arg);
    srand(time(NULL));
    while(1) {
        pthread_mutex_lock(&stock_mutex[stock_index]);
        stocks[stock_index] += (rand() % 10) - 5;
        update_count[stock_index]++;
        printf("Stock %d updated. Current value: %f\n", stock_index, stocks[stock_index]);
        pthread_mutex_unlock(&stock_mutex[stock_index]);
        sleep(2);
    }
}

int main() {
    pthread_t stock_threads[NUM_STOCKS];
    int stock_indices[NUM_STOCKS];
    int i;
    for(i = 0; i < NUM_STOCKS; i++) {
        stocks[i] = rand() % 100;
        pthread_mutex_init(&stock_mutex[i], NULL);
        update_count[i] = 0;
        stock_indices[i] = i;
        pthread_create(&stock_threads[i], NULL, track_stock, &stock_indices[i]);
    }
    for(i = 0; i < NUM_STOCKS; i++) {
        pthread_join(stock_threads[i], NULL);
    }
    return 0;
}