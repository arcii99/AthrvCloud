//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_ITEMS 10
#define NUM_THREADS 3

struct Item {
    int id;
    int quantity;
};

struct Inventory {
    struct Item items[NUM_ITEMS];
    pthread_mutex_t mutex;
};

struct ThreadArg {
    struct Inventory *inventory;
    int threadId;
};

void *checkInventory(void *arg) {
    struct ThreadArg *threadArg = (struct ThreadArg*) arg;
    struct Inventory *inventory = threadArg->inventory;
    int threadId = threadArg->threadId;

    while(1) {
        printf("Thread %d is checking inventory...\n", threadId);

        pthread_mutex_lock(&inventory->mutex);

        int i;
        for(i=0; i<NUM_ITEMS; i++) {
            printf("Item %d has %d units\n", inventory->items[i].id, inventory->items[i].quantity);
        }

        pthread_mutex_unlock(&inventory->mutex);

        sleep(3);
    }

    return NULL;
}

void *addInventory(void *arg) {
    struct ThreadArg *threadArg = (struct ThreadArg*) arg;
    struct Inventory *inventory = threadArg->inventory;
    int threadId = threadArg->threadId;

    while(1) {
        printf("Thread %d is adding inventory...\n", threadId);

        pthread_mutex_lock(&inventory->mutex);

        int i;
        for(i=0; i<NUM_ITEMS; i++) {
            inventory->items[i].quantity += threadId;
        }

        pthread_mutex_unlock(&inventory->mutex);

        sleep(5);
    }

    return NULL;
}

int main() {
    struct Inventory inventory = {
        .items = {
            { .id = 1, .quantity = 10 },
            { .id = 2, .quantity = 20 },
            { .id = 3, .quantity = 30 },
            { .id = 4, .quantity = 40 },
            { .id = 5, .quantity = 50 },
            { .id = 6, .quantity = 60 },
            { .id = 7, .quantity = 70 },
            { .id = 8, .quantity = 80 },
            { .id = 9, .quantity = 90 },
            { .id = 10, .quantity = 100 }
        },
        .mutex = PTHREAD_MUTEX_INITIALIZER
    };

    pthread_t threads[NUM_THREADS];
    struct ThreadArg threadArgs[NUM_THREADS];

    int i;
    for(i=0; i<NUM_THREADS; i++) {
        threadArgs[i].inventory = &inventory;
        threadArgs[i].threadId = i+1;

        if(i == 0) {
            pthread_create(&threads[i], NULL, checkInventory, &threadArgs[i]);
        } else {
            pthread_create(&threads[i], NULL, addInventory, &threadArgs[i]);
        }
    }

    for(i=0; i<NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}