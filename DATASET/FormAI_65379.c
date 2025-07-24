//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_PRODUCTS 100
#define NUM_THREADS 5

//Structure to hold product information
struct Product {
    int id;
    char name[50];
    int quantity;
};

struct Product inventory[MAX_PRODUCTS];

int num_products = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

//Function to add a product to the inventory
void addProduct(struct Product product) {
    pthread_mutex_lock(&mutex);
    if(num_products < MAX_PRODUCTS) {
        inventory[num_products] = product;
        num_products++;
        printf("Product added to inventory: %s\n", product.name);
    }
    else {
        printf("Inventory is full. Product not added.\n");
    }
    pthread_mutex_unlock(&mutex);
}

//Function to remove a product from the inventory
void removeProduct(int id) {
    pthread_mutex_lock(&mutex);
    int index = -1;
    for(int i = 0; i < num_products; i++) {
        if(inventory[i].id == id) {
            index = i;
            break;
        }
    }
    if(index != -1) {
        printf("Product removed from inventory: %s\n", inventory[index].name);
        for(int i = index; i < num_products - 1; i++) {
            inventory[i] = inventory[i+1];
        }
        num_products--;
    }
    else {
        printf("Product with ID %d not found in inventory.\n", id);
    }
    pthread_mutex_unlock(&mutex);
}

//Thread function to add products
void *addThread(void *args) {
    for(int i = 0; i < 5; i++) {
        struct Product product;
        product.id = rand() % 1000;
        sprintf(product.name, "Product %d", product.id);
        product.quantity = rand() % 100;
        addProduct(product);
    }
    pthread_exit(NULL);
}

//Thread function to remove products
void *removeThread(void *args) {
    for(int i = 0; i < 5; i++) {
        int id = rand() % 1000;
        removeProduct(id);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int status;

    //Initialize inventory with some products
    struct Product p1 = {101, "Product 1", 10};
    struct Product p2 = {102, "Product 2", 20};
    struct Product p3 = {103, "Product 3", 30};
    addProduct(p1);
    addProduct(p2);
    addProduct(p3);

    //Create threads to add and remove products
    status = pthread_create(&threads[0], NULL, addThread, NULL);
    if(status != 0) {
        fprintf(stderr, "Error creating thread. Exiting program.\n");
        exit(-1);
    }

    status = pthread_create(&threads[1], NULL, addThread, NULL);
    if(status != 0) {
        fprintf(stderr, "Error creating thread. Exiting program.\n");
        exit(-1);
    }

    status = pthread_create(&threads[2], NULL, addThread, NULL);
    if(status != 0) {
        fprintf(stderr, "Error creating thread. Exiting program.\n");
        exit(-1);
    }

    status = pthread_create(&threads[3], NULL, removeThread, NULL);
    if(status != 0) {
        fprintf(stderr, "Error creating thread. Exiting program.\n");
        exit(-1);
    }

    status = pthread_create(&threads[4], NULL, removeThread, NULL);
    if(status != 0) {
        fprintf(stderr, "Error creating thread. Exiting program.\n");
        exit(-1);
    }

    //Join threads and exit
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Inventory after all threads completed:\n");
    for(int i = 0; i < num_products; i++) {
        printf("%d, %s, %d\n", inventory[i].id, inventory[i].name, inventory[i].quantity);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}