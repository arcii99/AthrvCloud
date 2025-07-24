//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: asynchronous
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Struct to hold warehouse inventory
typedef struct {
    int itemId;
    char itemName[50];
    int quantity;
} inventory;

// Function to update inventory quantity
void* updateInventory(void* arg) {
    inventory* inv = (inventory*)arg;
    printf("%s inventory updated.\n", inv->itemName);
    inv->quantity += 10; // Increment quantity by 10
    return NULL;
}

int main() {
    // Create inventory items
    inventory item1 = {1, "Pencils", 100};
    inventory item2 = {2, "Notebooks", 50};

    // Create threads to update inventory
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, updateInventory, (void*)&item1);
    pthread_create(&thread2, NULL, updateInventory, (void*)&item2);

    // Wait until threads finish executing
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Display updated inventory
    printf("\nInventory Update:\n");
    printf("------------------\n");
    printf("%-10s%-20s%s\n", "Item ID", "Item Name", "Quantity");
    printf("%-10d%-20s%d\n", item1.itemId, item1.itemName, item1.quantity);
    printf("%-10d%-20s%d\n", item2.itemId, item2.itemName, item2.quantity);

    return 0;
}