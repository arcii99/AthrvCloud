//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to define a product
struct Product {
    int id;
    char name[100];
    int quantity;
};

// Function to initialize the warehouse
void initWarehouse(struct Product *warehouse, int size) {
    for (int i=0; i<size; i++) {
        warehouse[i].id = i+1;
        strcpy(warehouse[i].name, "Empty");
        warehouse[i].quantity = 0;
    }
}

// Function to display the warehouse
void displayWarehouse(struct Product *warehouse, int size) {
    printf("Warehouse:\n");
    printf("ID  | Name             | Quantity\n");
    printf("----------------------------------\n");
    for (int i=0; i<size; i++) {
        printf("%-3d | %-16s | %d\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity);
    }
    printf("----------------------------------\n");
}

// Function to add a product to the warehouse
void addProduct(struct Product *warehouse, int size) {
    int id, quantity;
    char name[100];
    printf("Enter the ID of the product: ");
    scanf("%d", &id);
    printf("Enter the name of the product: ");
    scanf("%s", name);
    printf("Enter the quantity of the product: ");
    scanf("%d", &quantity);
    if (id > 0 && id <= size && strcmp(warehouse[id-1].name, "Empty") == 0) {
        warehouse[id-1].id = id;
        strcpy(warehouse[id-1].name, name);
        warehouse[id-1].quantity = quantity;
        printf("Product added successfully!\n");
    } else {
        printf("Invalid ID or product already exists in the warehouse.\n");
    }
}

// Function to remove a product from the warehouse
void removeProduct(struct Product *warehouse, int size) {
    int id;
    printf("Enter the ID of the product: ");
    scanf("%d", &id);
    if (id > 0 && id <= size && strcmp(warehouse[id-1].name, "Empty") != 0) {
        warehouse[id-1].id = id;
        strcpy(warehouse[id-1].name, "Empty");
        warehouse[id-1].quantity = 0;
        printf("Product removed successfully!\n");
    } else {
        printf("Invalid ID or product does not exist in the warehouse.\n");
    }
}

int main() {
    int size = 10; // size of the warehouse
    struct Product warehouse[size]; // creating an array of Product structures
    initWarehouse(warehouse, size); // initializing the warehouse with empty products

    int choice = 0;
    while (choice != 4) {
        printf("\nWhat would you like to do?\n");
        printf("1. Display the warehouse.\n");
        printf("2. Add a product to the warehouse.\n");
        printf("3. Remove a product from the warehouse.\n");
        printf("4. Quit the program.\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayWarehouse(warehouse, size);
                break;
            case 2:
                addProduct(warehouse, size);
                break;
            case 3:
                removeProduct(warehouse, size);
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                break;
        }
    }

    return 0;
}