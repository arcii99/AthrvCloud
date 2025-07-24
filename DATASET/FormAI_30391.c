//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Define Warehouse structure
struct Warehouse {
    char item[50];
    int quantity;
    float price;
};

// Define function to display inventory of the warehouse
void displayInventory(struct Warehouse w[]) {
    printf("\nWarehouse Inventory:\n");
    printf("Item\t\tQuantity\tPrice\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\t\t%d\t\t%.2f\n", w[i].item, w[i].quantity, w[i].price);
    }
}

int main() {
    // Create an array of Warehouse type objects
    struct Warehouse warehouse[5];

    // Add items to the warehouse
    strcpy(warehouse[0].item, "Laptops");
    warehouse[0].quantity = 50;
    warehouse[0].price = 750.00;

    strcpy(warehouse[1].item, "Smartphones");
    warehouse[1].quantity = 100;
    warehouse[1].price = 500.00;

    strcpy(warehouse[2].item, "Gaming Consoles");
    warehouse[2].quantity = 25;
    warehouse[2].price = 1000.00;

    strcpy(warehouse[3].item, "Drones");
    warehouse[3].quantity = 10;
    warehouse[3].price = 1500.00;

    strcpy(warehouse[4].item, "Virtual Reality Headsets");
    warehouse[4].quantity = 15;
    warehouse[4].price = 800.00;

    // Display initial inventory
    displayInventory(warehouse);

    // Simulate a purchase order
    printf("\nSimulating Purchase Order...\n");

    // Decrease quantity of laptops and smartphones
    warehouse[0].quantity -= 10;
    warehouse[1].quantity -= 20;

    // Increase quantity of gaming consoles and virtual reality headsets
    warehouse[2].quantity += 5;
    warehouse[4].quantity += 10;

    // Update inventory
    displayInventory(warehouse);

    return 0;
}