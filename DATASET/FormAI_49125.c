//FormAI DATASET v1.0 Category: Stock market tracker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_STOCKS 5

/* A struct to hold stock information */
typedef struct {
    char name[20];
    float price;
} stock_t;

/* Global variables */
stock_t stock_list[MAX_STOCKS];
pthread_mutex_t mutex_lock;
pthread_cond_t cond_var;
int total_stocks = 0;
int num_threads = 0;
int done_threads = 0;

/* Thread function to update stock prices */
void *update_stock(void *arg) {
    int index = *(int*)arg;
    while (1) {
        pthread_mutex_lock(&mutex_lock);
        stock_list[index].price += (float)(rand() % 100) / 100;
        printf("%s: $%.2f\n", stock_list[index].name, stock_list[index].price);
        pthread_cond_broadcast(&cond_var);
        pthread_mutex_unlock(&mutex_lock);
        usleep(500000);
    }
}

/* Thread function to print the stock tracker */
void *print_tracker(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex_lock);
        while (done_threads < num_threads) {
            pthread_cond_wait(&cond_var, &mutex_lock);
        }
        system("clear"); // Clear screen
        printf("\nStock Tracker\n");

        for (int i = 0; i < total_stocks; i++) {
            printf("%s: $%.2f\n", stock_list[i].name, stock_list[i].price);
        }

        pthread_mutex_unlock(&mutex_lock);
        usleep(500000);
    }
}

int main() {
    // Initialize stocks
    strcpy(stock_list[0].name, "AAPL");
    stock_list[0].price = 130.53;
    strcpy(stock_list[1].name, "GOOG");
    stock_list[1].price = 2345.75;
    strcpy(stock_list[2].name, "TSLA");
    stock_list[2].price = 680.30;
    strcpy(stock_list[3].name, "AMZN");
    stock_list[3].price = 3278.36;
    strcpy(stock_list[4].name, "FB");
    stock_list[4].price = 329.35;

    total_stocks = MAX_STOCKS;

    // Initialize mutex
    pthread_mutex_init(&mutex_lock, NULL);
    pthread_cond_init(&cond_var, NULL);

    // Create threads for each stock
    pthread_t threads[MAX_STOCKS];
    for (int i = 0; i < total_stocks; i++) {
        int *arg = malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&threads[i], NULL, &update_stock, arg);
        num_threads++;
    }

    // Create thread to print the stock tracker
    pthread_t print_thread;
    pthread_create(&print_thread, NULL, &print_tracker, NULL);

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
        done_threads++;
    }

    // Clean up mutex and condition variable
    pthread_mutex_destroy(&mutex_lock);
    pthread_cond_destroy(&cond_var);

    return 0;
}