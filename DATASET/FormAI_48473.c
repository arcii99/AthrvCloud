//FormAI DATASET v1.0 Category: Stock market tracker ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_STOCKS 5

pthread_mutex_t lock;
float stocks[MAX_STOCKS] = {100.0, 50.0, 75.0, 120.0, 200.0};
char stock_names[MAX_STOCKS][10] = {"AAPL", "GOOG", "TSLA", "AMZN", "FB"};

void* update_stock_prices(void* arg) {
    int index = *(int*)arg;
    while(1) {
        float price_change = ((float)rand()/(float)(RAND_MAX)) * 20 - 10; // random price change between -10 and 10
        pthread_mutex_lock(&lock);
        stocks[index] += price_change;
        printf("%s stock price updated to %.2f\n", stock_names[index], stocks[index]);
        pthread_mutex_unlock(&lock);
        usleep(2000000); // sleep for 2 seconds
    }
    return NULL;
}

int main() {
    pthread_t threads[MAX_STOCKS];
    int thread_args[MAX_STOCKS];
    int i;

    pthread_mutex_init(&lock, NULL);

    for(i=0; i<MAX_STOCKS; i++) {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, update_stock_prices, &thread_args[i]);
    }

    for(i=0; i<MAX_STOCKS; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&lock);
    return 0;
}