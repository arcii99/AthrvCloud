//FormAI DATASET v1.0 Category: Stock market tracker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 3 // number of threads we will create
#define STOCK_COUNT 5 // number of stocks we will track

// stock data struct
struct Stock {
    char symbol[5];
    float price;
};

// thread data struct
struct ThreadData {
    int tid; // thread id
    struct Stock* stocks; // array of stocks
};

// function to update stock prices randomly
void* update_prices(void* arg) {
    struct ThreadData* data = (struct ThreadData*) arg;
    int tid = data->tid;
    struct Stock* stocks = data->stocks;
    
    while (1) {
        for (int i = 0; i < STOCK_COUNT; i++) {
            float change = ((float)rand()/(float)(RAND_MAX)) * 2 - 1; // generate random number between -1 and 1
            stocks[i].price += change;
            printf("Thread %d updated stock %s to $%.2f\n", tid, stocks[i].symbol, stocks[i].price);
        }
        sleep(1); // sleep for 1 second between updates
    }
    
    pthread_exit(NULL);
}

// function to print current stock prices
void* print_prices(void* arg) {
    struct ThreadData* data = (struct ThreadData*) arg;
    int tid = data->tid;
    struct Stock* stocks = data->stocks;
    
    while (1) {
        printf("\n-------------------------\nThread %d stock prices:\n", tid);
        for (int i = 0; i < STOCK_COUNT; i++) {
            printf("%s: $%.2f\n", stocks[i].symbol, stocks[i].price);
        }
        printf("-------------------------\n");
        sleep(5); // sleep for 5 seconds between prints
    }
    
    pthread_exit(NULL);
}

int main() {
    // initialize stocks
    struct Stock stocks[STOCK_COUNT] = {
        {"AAPL", 150.00},
        {"GOOG", 250.00},
        {"MSFT", 100.00},
        {"AMZN", 300.00},
        {"FB", 75.00}
    };
    
    // initialize threads
    pthread_t threads[NUM_THREADS];
    struct ThreadData thread_data[NUM_THREADS];
    
    // create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].tid = i;
        thread_data[i].stocks = stocks;
        if (i == 0) {
            pthread_create(&threads[i], NULL, update_prices, &thread_data[i]);
        } else {
            pthread_create(&threads[i], NULL, print_prices, &thread_data[i]);
        }
    }
    
    // wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}