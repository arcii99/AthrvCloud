//FormAI DATASET v1.0 Category: Product Inventory System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int numProducts = 0;
pthread_mutex_t mutex;

void addProduct(char* name, int quantity, float price);
int findProduct(char* name);
void purchase(char* name, int quantity);
void displayInventory();

void* purchaseThread(void* name) {
    pthread_mutex_lock(&mutex);

    char* productName = (char*) name;
    int index = findProduct(productName);

    if (index == -1) {
        printf("Sorry, we don't carry %s.\n", productName);
    } else {
        Product* product = &inventory[index];
        printf("Purchasing %d %s.\n", product->quantity, product->name);
        product->quantity = 0;
    }

    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_mutex_init(&mutex, NULL);

    addProduct("Apple", 10, 0.99);
    addProduct("Banana", 20, 0.50);
    addProduct("Grapes", 5, 1.49);

    pthread_t t1, t2;
    pthread_create(&t1, NULL, purchaseThread, "Apple");
    pthread_create(&t2, NULL, purchaseThread, "Orange");
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    displayInventory();

    pthread_mutex_destroy(&mutex);
    return 0;
}

void addProduct(char* name, int quantity, float price) {
    if (numProducts == MAX_PRODUCTS) {
        printf("Sorry, inventory is full.\n");
        return;
    }

    strcpy(inventory[numProducts].name, name);
    inventory[numProducts].quantity = quantity;
    inventory[numProducts].price = price;
    numProducts++;
}

int findProduct(char* name) {
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void purchase(char* name, int quantity) {
    int index = findProduct(name);

    if (index == -1) {
        printf("Sorry, we don't carry %s.\n", name);
        return;
    }

    Product* product = &inventory[index];

    if (product->quantity < quantity) {
        printf("Sorry, we only have %d %s in stock.\n", product->quantity, product->name);
        return;
    }

    product->quantity -= quantity;
    printf("Purchased %d %s for $%.2f each.\n", quantity, product->name, product->price);
}

void displayInventory() {
    printf("\nCurrent Inventory:\n\n");
    printf("%-15s %-15s %-15s\n", "Product Name", "Quantity", "Price");

    for (int i = 0; i < numProducts; i++) {
        printf("%-15s %-15d $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }

    printf("\n");
}