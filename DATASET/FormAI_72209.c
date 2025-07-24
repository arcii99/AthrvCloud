//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PRODUCTS 1000

struct Product {
    int id;
    char name[100];
    int quantity;
    int rackNo;
    float price;
};

struct Rack {
    int rackNo;
    struct Product* products[MAX_PRODUCTS];
    int current;
};

struct Warehouse {
    int numOfRacks;
    struct Rack* racks[MAX_PRODUCTS];
    struct Product* products[MAX_PRODUCTS];
    int currentProducts;
};

// Function prototypes
void addProduct(struct Warehouse* warehouse, char* name, int quantity, float price);
void addRack(struct Warehouse* warehouse, int rackNo);
void addProductToRack(struct Warehouse* warehouse, int productId, int rackNo);
void showProduct(struct Warehouse* warehouse, int id);

int main() {
    struct Warehouse warehouse;
    warehouse.numOfRacks = 0;
    warehouse.currentProducts = 0;

    // Adding products
    addProduct(&warehouse, "Chair", 120, 24.50);
    addProduct(&warehouse, "Table", 80, 49.99);
    addProduct(&warehouse, "Sofa", 50, 125.75);

    // Adding racks
    addRack(&warehouse, 1);
    addRack(&warehouse, 2);
    addRack(&warehouse, 3);

    // Adding products to rack
    addProductToRack(&warehouse, 1, 1);
    addProductToRack(&warehouse, 2, 1);
    addProductToRack(&warehouse, 3, 2);
    addProductToRack(&warehouse, 3, 3);

    // Showing product details
    showProduct(&warehouse, 1);
    showProduct(&warehouse, 2);
    showProduct(&warehouse, 3);

    return 0;
}

// Function definitions

// Adds a product to the warehouse
void addProduct(struct Warehouse* warehouse, char* name, int quantity, float price) {
    // Creating new product
    struct Product* newProduct = (struct Product*)malloc(sizeof(struct Product));
    newProduct->id = warehouse->currentProducts + 1;
    strcpy(newProduct->name, name);
    newProduct->quantity = quantity;
    newProduct->price = price;

    // Adding product to warehouse
    warehouse->products[warehouse->currentProducts] = newProduct;
    warehouse->currentProducts++;
    printf("Product added successfully!\n");
}

// Adds a new rack to the warehouse
void addRack(struct Warehouse* warehouse, int rackNo) {
    // Creating new rack
    struct Rack* newRack = (struct Rack*)malloc(sizeof(struct Rack));
    newRack->rackNo = rackNo;
    newRack->current = 0;

    // Adding new rack to warehouse
    warehouse->racks[warehouse->numOfRacks] = newRack;
    warehouse->numOfRacks++;
    printf("Rack added successfully!\n");
}

// Adds a product to a rack in the warehouse
void addProductToRack(struct Warehouse* warehouse, int productId, int rackNo) {
    int productIndex = -1;
    int rackIndex = -1;

    // Finding product
    for (int i = 0; i < warehouse->currentProducts; i++) {
        if (warehouse->products[i]->id == productId) {
            productIndex = i;
            break;
        }
    }

    // Finding rack
    for (int i = 0; i < warehouse->numOfRacks; i++) {
        if (warehouse->racks[i]->rackNo == rackNo) {
            rackIndex = i;
            break;
        }
    }

    if (productIndex == -1) {
        printf("Product not found!\n");
    }
    else if (rackIndex == -1) {
        printf("Rack not found!\n");
    }
    else {
        struct Product* product = warehouse->products[productIndex];
        struct Rack* rack = warehouse->racks[rackIndex];

        if (rack->current == MAX_PRODUCTS) {
            printf("Rack is full!\n");
        }
        else {
            rack->products[rack->current] = product;
            rack->current++;
            printf("Product added to rack successfully!\n");
        }
    }
}

// Shows the details of a product in the warehouse
void showProduct(struct Warehouse* warehouse, int id) {
    int index = -1;

    // Finding product
    for (int i = 0; i < warehouse->currentProducts; i++) {
        if (warehouse->products[i]->id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Product not found!\n");
    }
    else {
        struct Product* product = warehouse->products[index];
        printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n", product->id, product->name, product->quantity, product->price);
    }
}