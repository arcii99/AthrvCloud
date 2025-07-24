//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: happy
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Defining the struct for product */
struct product {
    char productName[100];
    int productID;
    float productPrice;
    int productQuantity;
};

/* Defining the struct for warehouse */
struct warehouse {
    char warehouseName[100];
    int warehouseID;
    struct product products[100];
    int productCount;
};

/* Function to initialize a product */
void initProduct(struct product *pProduct, char *name, int id, float price, int quantity) {
    strcpy(pProduct->productName, name);
    pProduct->productID = id;
    pProduct->productPrice = price;
    pProduct->productQuantity = quantity;
}

/* Function to add a product to a warehouse */
void addProductToWarehouse(struct warehouse *pWarehouse,struct product productToAdd) {
    pWarehouse->products[pWarehouse->productCount] = productToAdd;
    pWarehouse->productCount++;
}

/* Function to initialize a warehouse */
void initWarehouse(struct warehouse *pWarehouse, char *name, int id) {
    strcpy(pWarehouse->warehouseName, name);
    pWarehouse->warehouseID = id;
    pWarehouse->productCount = 0;
}

/* Function to print the details of a warehouse */
void printWarehouseDetails(struct warehouse *pWarehouse) {
    printf("Warehouse name: %s\nWarehouse ID: %d\n\n", pWarehouse->warehouseName, pWarehouse->warehouseID);
    printf("List of products:\n");
    for(int i = 0; i < pWarehouse->productCount; i++) {
        printf("%s(ID:%d) - $%.2f - Quantity: %d\n", pWarehouse->products[i].productName,
                                                      pWarehouse->products[i].productID,
                                                      pWarehouse->products[i].productPrice,
                                                      pWarehouse->products[i].productQuantity);
    }
    printf("\n");
}

/* The main function */
int main() {
    /* Initializing the warehouses */
    struct warehouse warehouse1;
    struct warehouse warehouse2;
    initWarehouse(&warehouse1, "Warehouse 1", 101);
    initWarehouse(&warehouse2, "Warehouse 2", 102);

    /* Initializing the products */
    struct product product1;
    struct product product2;
    struct product product3;
    struct product product4;
    initProduct(&product1, "Product 1", 201, 50.00, 100);
    initProduct(&product2, "Product 2", 202, 75.00, 50);
    initProduct(&product3, "Product 3", 203, 100.00, 25);
    initProduct(&product4, "Product 4", 204, 25.00, 200);

    /* Adding products to warehouses */
    addProductToWarehouse(&warehouse1, product1);
    addProductToWarehouse(&warehouse1, product2);
    addProductToWarehouse(&warehouse2, product3);
    addProductToWarehouse(&warehouse2, product4);

    /* Printing details of warehouses */
    printf("Welcome to our Warehouse Management System!\n\n");
    printWarehouseDetails(&warehouse1);
    printf("\n");
    printWarehouseDetails(&warehouse2);
    printf("Thank you for using our Warehouse Management System!\n");

    return 0;
}