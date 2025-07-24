//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: modular
#include <stdio.h>

// Define Warehouse struct
struct Warehouse {
    char name[50];
    int capacity;
    int inventory;
};

// Function to add inventory to a Warehouse
void addInventory(struct Warehouse *warehouse, int amount) {
    // Check if adding the amount would exceed capacity
    if (warehouse->inventory + amount > warehouse->capacity) {
        printf("Error: Unable to add inventory. Exceeds warehouse capacity.\n");
    } else { // If not, add inventory
        warehouse->inventory += amount;
        printf("%s inventory increased by %d.\n", warehouse->name, amount);
    }
}

// Function to remove inventory from a Warehouse
void removeInventory(struct Warehouse *warehouse, int amount) {
    // Check if removing the amount would result in negative inventory
    if (warehouse->inventory - amount < 0) {
        printf("Error: Unable to remove inventory. Insufficient inventory.\n");
    } else { // If not, remove inventory
        warehouse->inventory -= amount;
        printf("%s inventory decreased by %d.\n", warehouse->name, amount);
    }
}

int main() {
    // Create Warehouse object
    struct Warehouse warehouse1 = {"Warehouse 1", 100, 50};

    // Display initial inventory
    printf("%s has an inventory of %d out of %d.\n", warehouse1.name, warehouse1.inventory, warehouse1.capacity);

    // Add 25 inventory
    addInventory(&warehouse1, 25);

    // Display updated inventory
    printf("%s has an inventory of %d out of %d.\n", warehouse1.name, warehouse1.inventory, warehouse1.capacity);

    // Attempt to remove 100 inventory (should fail due to insufficient inventory)
    removeInventory(&warehouse1, 100);

    // Display updated inventory
    printf("%s has an inventory of %d out of %d.\n", warehouse1.name, warehouse1.inventory, warehouse1.capacity);

    // Remove 75 inventory
    removeInventory(&warehouse1, 75);

    // Display updated inventory
    printf("%s has an inventory of %d out of %d.\n", warehouse1.name, warehouse1.inventory, warehouse1.capacity);

    return 0;
}