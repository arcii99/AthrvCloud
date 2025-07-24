//FormAI DATASET v1.0 Category: Stock market tracker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Global variable to track stock price */
volatile float stock_price = 100;

/* Mutex lock for stock price */
pthread_mutex_t stock_mutex = PTHREAD_MUTEX_INITIALIZER;

/* Thread function to update stock price */
void* update_stock_price(void* arg) {
    float last_price = stock_price;
    while(1) {
        float new_price = last_price + ((float)rand()/RAND_MAX)*10 - 5;
        pthread_mutex_lock(&stock_mutex);
        stock_price = new_price;
        pthread_mutex_unlock(&stock_mutex);
        last_price = new_price;
        usleep(200000);
    }
}

/* Thread function to track stock price */
void* track_stock_price(void* arg) {
    float last_price = -1;
    while(1) {
        pthread_mutex_lock(&stock_mutex);
        float current_price = stock_price;
        pthread_mutex_unlock(&stock_mutex);
        if (current_price != last_price) {
            printf("Current stock price: %.2f\n", current_price);
            last_price = current_price;
        }
        usleep(100000);
    }
}

int main() {
    /* Create two pthreads */
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, update_stock_price, NULL);
    pthread_create(&thread2, NULL, track_stock_price, NULL);

    /* Wait for both threads to finish */
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}