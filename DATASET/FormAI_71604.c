//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: relaxed
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Define constants for the maximum capacity of the warehouse
#define MAX_ROWS 5
#define MAX_COLS 5

// Define constants for the types of products
#define PRODUCT_TYPE_A 0
#define PRODUCT_TYPE_B 1

// Define a struct to represent a product with a type and quantity
typedef struct {
    int type;
    int quantity;
} Product;

// Define a struct to represent a location on a shelf
typedef struct {
    int row; // 0-indexed row number
    int col; // 0-indexed column number
} Location;

// Define a struct to represent a shelf in the warehouse
typedef struct {
    Product products[MAX_ROWS][MAX_COLS];
} Shelf;

// Define a struct to represent the warehouse with shelves and available space
typedef struct {
    Shelf shelves[MAX_ROWS];
    int space[MAX_ROWS][MAX_COLS]; // 0 indicates available space, 1 indicates occupied space
} Warehouse;

// Declare the function prototypes
void initWarehouse(Warehouse *warehouse);
void printWarehouse(Warehouse warehouse);
bool addProduct(Warehouse *warehouse, Product product, Location location);
bool removeProduct(Warehouse *warehouse, Location location);

// Define the main function
int main() {
    Warehouse warehouse;
    initWarehouse(&warehouse);
    Product productA = {PRODUCT_TYPE_A, 10};
    Product productB = {PRODUCT_TYPE_B, 20};
    
    // Add productA to location (0, 0) on the shelf
    Location locationA = {0, 0};
    bool addedA = addProduct(&warehouse, productA, locationA);
    if (addedA) {
        printf("Product A added to location (%d, %d)\n", locationA.row, locationA.col);
    } else {
        printf("Product A could not be added to location (%d, %d)\n", locationA.row, locationA.col);
    }
    
    // Add productB to location (0, 1) on the shelf
    Location locationB = {0, 1};
    bool addedB = addProduct(&warehouse, productB, locationB);
    if (addedB) {
        printf("Product B added to location (%d, %d)\n", locationB.row, locationB.col);
    } else {
        printf("Product B could not be added to location (%d, %d)\n", locationB.row, locationB.col);
    }
    
    // Print the warehouse after adding the products
    printWarehouse(warehouse);
    
    // Remove productA from location (0, 0) on the shelf
    bool removedA = removeProduct(&warehouse, locationA);
    if (removedA) {
        printf("Product A removed from location (%d, %d)\n", locationA.row, locationA.col);
    } else {
        printf("Product A could not be removed from location (%d, %d)\n", locationA.row, locationA.col);
    }
    
    // Print the warehouse after removing productA
    printWarehouse(warehouse);
    
    return 0;
}

// Initialize the warehouse with all shelves and space available
void initWarehouse(Warehouse *warehouse) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            warehouse->space[i][j] = 0;
        }
    }
}

// Print the current state of the warehouse
void printWarehouse(Warehouse warehouse) {
    printf("Warehouse:\n");
    for (int i = 0; i < MAX_ROWS; i++) {
        printf("|");
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%c|", (warehouse.space[i][j] == 1) ? '#' : ' ');
        }
        printf("\n");
    }
}

// Add a product to the warehouse at a specific location
bool addProduct(Warehouse *warehouse, Product product, Location location) {
    // Check if the location is available
    if (warehouse->space[location.row][location.col] == 1) {
        return false;
    }
    
    // Add the product to the shelf
    warehouse->shelves[location.row].products[location.col][0] = product;
    
    // Mark the space as occupied
    warehouse->space[location.row][location.col] = 1;
    
    return true;
}

// Remove a product from the warehouse at a specific location
bool removeProduct(Warehouse *warehouse, Location location) {
    // Check if the location is occupied
    if (warehouse->space[location.row][location.col] == 0) {
        return false;
    }
    
    // Remove the product from the shelf
    warehouse->shelves[location.row].products[location.col][0].type = -1;
    warehouse->shelves[location.row].products[location.col][0].quantity = -1;
    
    // Mark the space as available
    warehouse->space[location.row][location.col] = 0;
    
    return true;
}