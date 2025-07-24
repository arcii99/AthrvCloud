//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_PRODUCTS 10
#define MAX_THREADS 5

int num_products = 0;
int product_list[MAX_PRODUCTS];

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void* producer(void* arg);
void* consumer(void* arg);

int main(){
    pthread_t producer_threads[MAX_THREADS];
    pthread_t consumer_threads[MAX_THREADS];

    // Creating producer threads
    for(int i=0; i<MAX_THREADS; i++){
        pthread_create(&producer_threads[i], NULL, producer, NULL);
    }

    // Creating consumer threads
    for(int i=0; i<MAX_THREADS; i++){
        pthread_create(&consumer_threads[i], NULL, consumer, NULL);
    }

    // Joining producer threads
    for(int i=0; i<MAX_THREADS; i++){
        pthread_join(producer_threads[i], NULL);
    }

    // Joining consumer threads
    for(int i=0; i<MAX_THREADS; i++){
        pthread_join(consumer_threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}

void* producer(void* arg){
    while(1){
        pthread_mutex_lock(&mutex);

        // Wait for products to become available
        while(num_products == MAX_PRODUCTS){
            pthread_cond_wait(&cond, &mutex);
        }

        // Produce new product
        int new_product = rand() % 1000;

        // Add product to list
        product_list[num_products++] = new_product;
        printf("Product %d produced.\n", new_product);

        // Signal the consumers
        pthread_cond_signal(&cond);

        pthread_mutex_unlock(&mutex);
    }
}

void* consumer(void* arg){
    while(1){
        pthread_mutex_lock(&mutex);

        // Wait for products to become available
        while(num_products == 0){
            pthread_cond_wait(&cond, &mutex);
        }

        // Consume product
        int consumed_product = product_list[--num_products];
        printf("Product %d consumed.\n", consumed_product);

        // Signal the producers
        pthread_cond_signal(&cond);

        pthread_mutex_unlock(&mutex);
    }
}