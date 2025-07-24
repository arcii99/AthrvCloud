//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: modular
#include <stdio.h>

// Modular function to add items to the warehouse
int addItems(int inventory[], int itemCode, int quantity) {
    if (itemCode >= 0 && itemCode < 100) {
        inventory[itemCode] += quantity;
        return inventory[itemCode];
    } else {
        printf("Error: Invalid item code!\n");
        return -1;
    }
}

// Modular function to remove items from the warehouse
int removeItems(int inventory[], int itemCode, int quantity) {
    if (itemCode >= 0 && itemCode < 100 && inventory[itemCode] >= quantity) {
        inventory[itemCode] -= quantity;
        return inventory[itemCode];
    } else {
        printf("Error: Invalid item code or insufficient quantity!\n");
        return -1;
    }
}

// Modular function to display current inventory status
void displayInventory(int inventory[]) {
    printf("Current Inventory:\n");
    for (int i = 0; i < 100; i++) {
        if (inventory[i] > 0) {
            printf("Item %d - Quantity: %d\n", i, inventory[i]);
        }
    }
}

// Main function to run the program
int main() {
    
    // Initializing the inventory with 0 for all items
    int inventory[100] = {0};
    
    // Adding items to the warehouse
    addItems(inventory, 25, 100);
    addItems(inventory, 10, 50);
    addItems(inventory, 75, 200);
    
    // Removing items from the warehouse
    removeItems(inventory, 25, 50);
    removeItems(inventory, 10, 10);
    
    // Displaying current inventory status
    displayInventory(inventory);
    
    return 0;
}