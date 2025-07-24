//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the max number of products that can be stored in the warehouse
#define MAX_PRODUCTS 100

// Define a struct for a product
typedef struct Product {
    int id;
    char name[50];
    int quantity;
    double cost;
} Product;

// Define the inventory array to store products
Product inventory[MAX_PRODUCTS];

// Define a function to add a product
void addProduct(int id, char* name, int quantity, double cost) {
    // Check if the product already exists
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (inventory[i].id == id) {
            printf("Product with ID %d already exists\n", id);
            return;
        }
    }
    
    // Add the product to the inventory
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (inventory[i].id == 0) {
            inventory[i].id = id;
            strcpy(inventory[i].name, name);
            inventory[i].quantity = quantity;
            inventory[i].cost = cost;
            printf("Product added successfully\n");
            return;
        }
    }
    
    // If there is no more space in the inventory
    printf("Warehouse is full!\n");
}

// Define a function to remove a product
void removeProduct(int id) {
    // Find the index of the product with the given ID
    int index = -1;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (inventory[i].id == id) {
            index = i;
            break;
        }
    }
    
    // If the product exists, remove it
    if (index != -1) {
        inventory[index].id = 0;
        inventory[index].quantity = 0;
        inventory[index].cost = 0;
        strcpy(inventory[index].name, "");
        printf("Product removed successfully\n");
    } else {
        printf("Product not found\n");
    }
}

// Define a function to update the quantity of a product
void updateQuantity(int id, int quantity) {
    // Find the index of the product with the given ID
    int index = -1;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (inventory[i].id == id) {
            index = i;
            break;
        }
    }
    
    // If the product exists, update its quantity
    if (index != -1) {
        inventory[index].quantity = quantity;
        printf("Quantity updated successfully\n");
    } else {
        printf("Product not found\n");
    }
}

// Define a function to update the cost of a product
void updateCost(int id, double cost) {
    // Find the index of the product with the given ID
    int index = -1;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (inventory[i].id == id) {
            index = i;
            break;
        }
    }
    
    // If the product exists, update its cost
    if (index != -1) {
        inventory[index].cost = cost;
        printf("Cost updated successfully\n");
    } else {
        printf("Product not found\n");
    }
}

// Define a function to view all products in the warehouse
void viewProducts() {
    printf("%-10s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Cost");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (inventory[i].id != 0) {
            printf("%-10d %-20s %-10d %-10.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].cost);
        }
    }
}

// Define the main function
int main() {
    // Initialize the inventory
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        inventory[i].id = 0;
        inventory[i].quantity = 0;
        inventory[i].cost = 0;
        strcpy(inventory[i].name, "");
    }
    
    // Display the main menu
    int choice;
    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. Update product quantity\n");
        printf("4. Update product cost\n");
        printf("5. View all products\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // Add a product
                printf("\nAdd a product\n");
                printf("Enter the ID: ");
                int id;
                scanf("%d", &id);
                char name[50];
                printf("Enter the name: ");
                scanf("%s", name);
                int quantity;
                printf("Enter the quantity: ");
                scanf("%d", &quantity);
                double cost;
                printf("Enter the cost: ");
                scanf("%lf", &cost);
                addProduct(id, name, quantity, cost);
                break;
            case 2:
                // Remove a product
                printf("\nRemove a product\n");
                printf("Enter the ID: ");
                scanf("%d", &id);
                removeProduct(id);
                break;
            case 3:
                // Update product quantity
                printf("\nUpdate product quantity\n");
                printf("Enter the ID: ");
                scanf("%d", &id);
                printf("Enter the new quantity: ");
                scanf("%d", &quantity);
                updateQuantity(id, quantity);
                break;
            case 4:
                // Update product cost
                printf("\nUpdate product cost\n");
                printf("Enter the ID: ");
                scanf("%d", &id);
                printf("Enter the new cost: ");
                scanf("%lf", &cost);
                updateCost(id, cost);
                break;
            case 5:
                // View all products
                printf("\nView all products\n");
                viewProducts();
                break;
            case 6:
                // Exit the program
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice! Please enter a number (1-6).\n");
        }
        
    } while (choice != 6);
    
    return 0;
}