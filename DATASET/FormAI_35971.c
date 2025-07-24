//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_PRODUCTS 5
#define MAX_STOCK 10

int product_stock[NUM_PRODUCTS] = {0};
pthread_mutex_t stock_mutex = PTHREAD_MUTEX_INITIALIZER;

void* add_stock(void* arg) {
    int product_id = *((int*) arg);
    while (1) {
        pthread_mutex_lock(&stock_mutex);
        if (product_stock[product_id] >= MAX_STOCK) {
            pthread_mutex_unlock(&stock_mutex);
            continue;
        }
        product_stock[product_id]++;
        printf("Added 1 product to stock %d. Current stock: %d\n", product_id, product_stock[product_id]);
        pthread_mutex_unlock(&stock_mutex);
        sleep(1);
    }
    return NULL;
}

void* remove_stock(void* arg) {
    int product_id = *((int*) arg);
    while (1) {
        pthread_mutex_lock(&stock_mutex);
        if (product_stock[product_id] <= 0) {
            pthread_mutex_unlock(&stock_mutex);
            continue;
        }
        product_stock[product_id]--;
        printf("Removed 1 product from stock %d. Current stock: %d\n", product_id, product_stock[product_id]);
        pthread_mutex_unlock(&stock_mutex);
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t add_threads[NUM_PRODUCTS];
    pthread_t remove_threads[NUM_PRODUCTS];

    int product_ids[NUM_PRODUCTS];
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        product_ids[i] = i;
        pthread_create(&add_threads[i], NULL, add_stock, &product_ids[i]);
        pthread_create(&remove_threads[i], NULL, remove_stock, &product_ids[i]);
    }
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        pthread_join(add_threads[i], NULL);
        pthread_join(remove_threads[i], NULL);
    }
    return 0;
}