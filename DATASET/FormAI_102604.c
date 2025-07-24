//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_ITEMS 100  // maximum number of items that can be stored in warehouse
#define MAX_THREADS 10  // maximum number of worker threads

// struct to represent an item
typedef struct {
    int id;  // unique identifier for item
    char name[20];  // name of item
    int quantity;  // quantity of item
} item_t;

// shared resources
item_t warehouse[MAX_ITEMS];  // array of items in the warehouse
int num_items = 0;  // current number of items in warehouse
pthread_mutex_t warehouse_lock;  // mutex lock for accessing warehouse

// function prototypes
void add_item(int id, char* name, int quantity);
void remove_item(int id, int quantity);
void* worker_thread(void* arg);

int main() {
    pthread_t threads[MAX_THREADS];
    int thread_args[MAX_THREADS];
    int i;

    // initialize mutex lock
    pthread_mutex_init(&warehouse_lock, NULL);

    // create worker threads
    for (i = 0; i < MAX_THREADS; i++) {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, worker_thread, &thread_args[i]);
    }

    // main thread continuously adds items to warehouse
    while (1) {
        // simulate adding an item
        int id = rand() % 1000;
        char name[20];
        sprintf(name, "Item %d", id);
        int quantity = rand() % 10;
        add_item(id, name, quantity);

        // sleep for random amount of time
        int sleep_time = rand() % 5 + 1;
        sleep(sleep_time);
    }
}

// function to add an item to the warehouse
void add_item(int id, char* name, int quantity) {
    // acquire warehouse lock
    pthread_mutex_lock(&warehouse_lock);

    // check if warehouse is full
    if (num_items >= MAX_ITEMS) {
        printf("Warehouse is full, cannot add item!\n");
    } else {
        // create new item and add to warehouse
        item_t new_item;
        new_item.id = id;
        strcpy(new_item.name, name);
        new_item.quantity = quantity;
        warehouse[num_items++] = new_item;
        printf("Added item to warehouse: %s\n", name);
    }

    // release warehouse lock
    pthread_mutex_unlock(&warehouse_lock);
}

// function to remove an item from the warehouse
void remove_item(int id, int quantity) {
    // acquire warehouse lock
    pthread_mutex_lock(&warehouse_lock);

    int i;
    for (i = 0; i < num_items; i++) {
        if (warehouse[i].id == id) {
            // found item, check if quantity is available
            if (warehouse[i].quantity >= quantity) {
                // remove quantity from item
                warehouse[i].quantity -= quantity;
                printf("Removed %d of item %d from warehouse\n", quantity, id);
            } else {
                printf("Not enough quantity of item %d in warehouse\n", id);
            }
            break;
        }
    }

    if (i == num_items) {
        // item not found in warehouse
        printf("Item %d not found in warehouse\n", id);
    }

    // release warehouse lock
    pthread_mutex_unlock(&warehouse_lock);
}

// function for worker threads to remove items from warehouse
void* worker_thread(void* arg) {
    int thread_num = *((int*) arg);
    while (1) {
        // simulate removing an item
        int id = rand() % 1000;
        int quantity = rand() % 5 + 1;
        remove_item(id, quantity);

        // sleep for random amount of time
        int sleep_time = rand() % 5 + 1;
        sleep(sleep_time);
    }
    return NULL;
}