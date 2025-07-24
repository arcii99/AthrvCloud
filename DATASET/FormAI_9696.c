//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_ITEMS 10
#define MAX_WORKERS 5

int warehouse_stock = 0;
pthread_mutex_t warehouse_lock;

void* worker_thread(void* arg) {

    int items_to_add = rand() % 5 + 1;
    
    pthread_mutex_lock(&warehouse_lock);
    if (warehouse_stock + items_to_add > MAX_ITEMS) {
        printf("Worker thread could not add items. Warehouse is full.\n");
    } else {
        warehouse_stock += items_to_add;
        printf("Worker thread added %d items to the warehouse. New stock count: %d\n", items_to_add, warehouse_stock);
    }
    pthread_mutex_unlock(&warehouse_lock);
    
    return NULL;
}

int main() {
    
    pthread_t workers[MAX_WORKERS];
    pthread_mutex_init(&warehouse_lock, NULL);
    
    srand(time(NULL));
    
    for (int i = 0; i < MAX_WORKERS; i++) {
        pthread_create(&workers[i], NULL, worker_thread, NULL);
    }
    
    for (int i = 0; i < MAX_WORKERS; i++) {
        pthread_join(workers[i], NULL);
    }
    
    pthread_mutex_destroy(&warehouse_lock);
    
    return 0;
}