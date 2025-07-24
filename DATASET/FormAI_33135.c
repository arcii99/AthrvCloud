//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: lively
// A Warehouse Management System example program
#include <stdio.h>
#include <string.h>

// Define a struct for each product in the warehouse
struct Product {
    char name[50];
    int quantity;
    float price;
};

// Define a struct for each shipment of products
struct Shipment {
    char supplier[50];
    struct Product products[20];
};

// Define a struct for the entire warehouse inventory
struct Warehouse {
    struct Product products[100];
    int numProducts;
};

// Function to add a product to the warehouse inventory
void addProduct(struct Product product, struct Warehouse *warehouse) {
    // Add the new product to the end of the list
    warehouse->products[warehouse->numProducts] = product;
    warehouse->numProducts++;
}

// Function to add a shipment of products to the warehouse inventory
void addShipment(struct Shipment shipment, struct Warehouse *warehouse) {
    // Loop through each product in the shipment
    for (int i = 0; i < 20; i++) {
        // Add the product to the warehouse inventory
        addProduct(shipment.products[i], warehouse);
    }
}

int main() {
    // Initialize an empty warehouse inventory
    struct Warehouse warehouse = { {}, 0 };

    // Initialize a shipment of products from a supplier
    struct Shipment shipment = { "Acme Corp", {
        { "Loaf of bread", 50, 1.99 },
        { "Gallon of milk", 20, 3.99 },
        { "Dozen eggs", 100, 2.99 },
        { "Bag of apples", 75, 4.99 },
        { "Box of cereal", 30, 5.99 }
    }};

    // Add the shipment of products to the warehouse inventory
    addShipment(shipment, &warehouse);

    // Print out the entire warehouse inventory
    printf("Warehouse Inventory:\n");
    printf("--------------------\n");
    for (int i = 0; i < warehouse.numProducts; i++) {
        printf("%s: %d ($%.2f each)\n", warehouse.products[i].name,
               warehouse.products[i].quantity, warehouse.products[i].price);
    }

    return 0;
}