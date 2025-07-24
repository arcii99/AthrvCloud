//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3 // Number of threads to be created

// Global variables
int product_count = 0;         // Number of products in inventory
pthread_mutex_t mutex_lock;    // Mutex lock for synchronization

// Function declarations
void *add_product(void *arg);
void *remove_product(void *arg);

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int i, status;

    // Initialize the mutex lock
    if (pthread_mutex_init(&mutex_lock, NULL) != 0) {
        printf("Mutex Initialization Failed");
        return 1;
    }

    // Create threads for adding and removing products
    for (i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;
        if (i % 2 == 0) {
            status = pthread_create(&threads[i], NULL, add_product, (void *)&thread_args[i]);
            if (status != 0) {
                printf("Thread Creation Failed");
                return 1;
            }
        } else {
            status = pthread_create(&threads[i], NULL, remove_product, (void *)&thread_args[i]);
            if (status != 0) {
                printf("Thread Creation Failed");
                return 1;
            }
        }
    }

    // Wait for all threads to finish execution
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex lock
    pthread_mutex_destroy(&mutex_lock);

    return 0;
}

void *add_product(void *arg)
{
    int thread_num = *(int *)arg;
    int i;

    for (i = 0; i < 5; i++) {
        // Acquire the lock
        pthread_mutex_lock(&mutex_lock);

        // Add a new product to the inventory
        product_count++;
        printf("Thread %d added a new product. Total products: %d\n", thread_num, product_count);

        // Release the lock
        pthread_mutex_unlock(&mutex_lock);

        // Wait for some time (to simulate processing)
        sleep(1);
    }

    pthread_exit(NULL);
}

void *remove_product(void *arg)
{
    int thread_num = *(int *)arg;
    int i;

    for (i = 0; i < 5; i++) {
        // Acquire the lock
        pthread_mutex_lock(&mutex_lock);

        // Remove a product from the inventory
        if (product_count > 0) {
            product_count--;
            printf("Thread %d removed a product. Total products: %d\n", thread_num, product_count);
        }

        // Release the lock
        pthread_mutex_unlock(&mutex_lock);

        // Wait for some time (to simulate processing)
        sleep(2);
    }

    pthread_exit(NULL);
}