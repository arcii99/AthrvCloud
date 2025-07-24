//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Medicine {
    char name[50];
    float price;
    int quantity;
};

struct Store {
    struct Medicine inventory[MAX_SIZE];
    int count;
};

void addMedicine(struct Store *store, char *name, float price, int quantity) {
    if (store->count >= MAX_SIZE) {
        printf("Store inventory is full!\n");
        return;
    }
    struct Medicine med;
    strcpy(med.name, name);
    med.price = price;
    med.quantity = quantity;
    store->inventory[store->count++] = med;
}

void printInventory(struct Store *store) {
    printf("Store Inventory:\n");
    printf("----------------------\n");
    printf("%-20s%-20s%-20s\n", "Name", "Price", "Quantity");
    for (int i = 0; i < store->count; i++) {
        struct Medicine med = store->inventory[i];
        printf("%-20s%-20.2f%-20d\n", med.name, med.price, med.quantity);
    }
    printf("----------------------\n");
}

void sellMedicine(struct Store *store, char *name, int quantity) {
    for (int i = 0; i < store->count; i++) {
        struct Medicine *med = &store->inventory[i];
        if (strcmp(med->name, name) == 0) {
            if (med->quantity < quantity) {
                printf("%s is out of stock!\n", name);
                return;
            }
            med->quantity -= quantity;
            printf("Sold %d of %s for %.2f each.\n", quantity, name, med->price);
            return;
        }
    }
    printf("Medicine not found!\n");
}

int main() {
    struct Store store = {0};
    addMedicine(&store, "Aspirin", 2.50, 100);
    addMedicine(&store, "Paracetamol", 1.50, 75);
    addMedicine(&store, "Ibuprofen", 3.00, 50);
    printInventory(&store);
    sellMedicine(&store, "Aspirin", 10);
    sellMedicine(&store, "Ibuprofen", 100);
    printInventory(&store);
    return 0;
}