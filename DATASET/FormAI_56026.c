//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: introspective
/* A Warehouse Management System program */

/* Inventory management allows businesses to track their inventory levels, orders, sales and deliveries, etc. 
in a way that helps them keep track of what they have in stock, what they need to order, and when they need 
to order it. This program is an example of a warehouse management system that helps track inventory levels.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTS 1000

struct Product {
    char name[100];
    char description[255];
    int quantity;
    float price;
};

struct Warehouse {
    struct Product inventory[MAX_PRODUCTS];
    int numProducts;
    float totalRevenue;
};

// function prototypes
void initializeWarehouse(struct Warehouse* warehouse);
void addProduct(struct Warehouse* warehouse);
void removeProduct(struct Warehouse* warehouse);
void updateProduct(struct Warehouse* warehouse);
void displayInventory(struct Warehouse* warehouse);
void calculateRevenue(struct Warehouse* warehouse, float price, int quantity);

// main function
int main()
{
    int choice;
    struct Warehouse warehouse;
    initializeWarehouse(&warehouse);
    
    do {
        printf("Warehouse Management System\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Update Product\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addProduct(&warehouse);
                break;
            case 2:
                removeProduct(&warehouse);
                break;
            case 3:
                updateProduct(&warehouse);
                break;
            case 4:
                displayInventory(&warehouse);
                break;
            case 5:
                printf("Exiting Warehouse Management System.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 5);
    
    return 0;
}

void initializeWarehouse(struct Warehouse* warehouse) {
    warehouse->numProducts = 0;
    warehouse->totalRevenue = 0;
}

void addProduct(struct Warehouse* warehouse) {
    char name[100], description[255];
    int quantity;
    float price;
    
    printf("Enter product name: ");
    scanf("%s", name);
    
    printf("Enter product description: ");
    scanf("%s", description);
    
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    
    printf("Enter price: ");
    scanf("%f", &price);
    
    if(warehouse->numProducts < MAX_PRODUCTS) {
        struct Product newProduct;
        strcpy(newProduct.name, name);
        strcpy(newProduct.description, description);
        newProduct.quantity = quantity;
        newProduct.price = price;
        warehouse->inventory[warehouse->numProducts] = newProduct;
        warehouse->numProducts++;
        printf("Product added successfully.\n");
    } else {
        printf("Maximum products limit reached. Cannot add product.\n");
    }
}

void removeProduct(struct Warehouse* warehouse) {
    char name[100];
    int found = 0, index, i;
    
    printf("Enter product name to remove: ");
    scanf("%s", name);
    
    for(i = 0; i < warehouse->numProducts; i++) {
        if(strcmp(warehouse->inventory[i].name, name) == 0) {
            found = 1;
            index = i;
            break;
        }
    }
    
    if(found == 1) {
        calculateRevenue(warehouse, warehouse->inventory[index].price, warehouse->inventory[index].quantity);
        
        for(i = index; i < warehouse->numProducts - 1; i++) {
            warehouse->inventory[i] = warehouse->inventory[i+1];
        }
        warehouse->numProducts--;
        printf("Product removed successfully.\n");
    } else {
        printf("Product not found.\n");
    }
}

void updateProduct(struct Warehouse* warehouse) {
    char name[100];
    int found = 0, index, quantity;
    float price;
    
    printf("Enter product name to update: ");
    scanf("%s", name);
    
    for(int i = 0; i < warehouse->numProducts; i++) {
        if(strcmp(warehouse->inventory[i].name, name) == 0) {
            found = 1;
            index = i;
            break;
        }
    }
    
    if(found == 1) {
        printf("Enter new quantity: ");
        scanf("%d", &quantity);
        warehouse->inventory[index].quantity = quantity;
        
        printf("Enter new price: ");
        scanf("%f", &price);
        calculateRevenue(warehouse, price, warehouse->inventory[index].quantity);
        warehouse->inventory[index].price = price;
        
        printf("Product updated successfully.\n");
    } else {
        printf("Product not found.\n");
    }
}

void calculateRevenue(struct Warehouse* warehouse, float price, int quantity) {
    float revenue = price * (float)quantity;
    warehouse->totalRevenue += revenue;
}

void displayInventory(struct Warehouse* warehouse) {
    printf("Warehouse Inventory:\n");
    printf("%-20s%-20s%-20s%-20s\n", "Product Name", "Description", "Quantity", "Price");
    
    for(int i = 0; i < warehouse->numProducts; i++) {
        printf("%-20s%-20s%-20d%-20.2f\n", warehouse->inventory[i].name,
                                            warehouse->inventory[i].description,
                                            warehouse->inventory[i].quantity,
                                            warehouse->inventory[i].price);
    }
    printf("\nTotal Revenue: $%.2f\n", warehouse->totalRevenue);
}