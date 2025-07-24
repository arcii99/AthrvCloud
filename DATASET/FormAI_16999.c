//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_PRODUCTS 100

struct Product {
    int id;
    char name[50];
    int quantity;
};

struct Inventory {
    struct Product products[MAX_PRODUCTS];
    int size;
    pthread_mutex_t lock;
};

void add_product(struct Inventory *inv, struct Product p) {
    pthread_mutex_lock(&inv->lock);
    if (inv->size == MAX_PRODUCTS) {
        printf("Error: Max products reached\n");
        pthread_mutex_unlock(&inv->lock);
        return;
    }
    inv->products[inv->size++] = p;
    printf("Added product: %s\n", p.name);
    pthread_mutex_unlock(&inv->lock);
}

void remove_product(struct Inventory *inv, int id) {
    pthread_mutex_lock(&inv->lock);
    for (int i = 0; i < inv->size; i++) {
        if (inv->products[i].id == id) {
            for (int j = i; j < inv->size-1; j++) {
                inv->products[j] = inv->products[j+1];
            }
            inv->size--;
            printf("Removed product: %d\n", id);
            pthread_mutex_unlock(&inv->lock);
            return;
        }
    }
    printf("Error: Product not found\n");
    pthread_mutex_unlock(&inv->lock);
}

void *producer(void *arg) {
    struct Inventory *inv = (struct Inventory *) arg;
    for (int i = 0; i < 5; i++) {
        struct Product p;
        p.id = rand() % 1000;
        sprintf(p.name, "Product %d", p.id);
        p.quantity = rand() % 10 + 1;
        add_product(inv, p);
    }
    printf("Producer finished\n");
    return NULL;
}

void *consumer(void *arg) {
    struct Inventory *inv = (struct Inventory *) arg;
    int id = rand() % 1000;
    remove_product(inv, id);
    printf("Consumer finished\n");
    return NULL;
}

int main(void) {
    struct Inventory inv;
    inv.size = 0;
    pthread_mutex_init(&inv.lock, NULL);

    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, &inv);
    pthread_create(&consumer_thread, NULL, consumer, &inv);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    pthread_mutex_destroy(&inv.lock);
    return 0;
}