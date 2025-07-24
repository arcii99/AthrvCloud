//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold information about a product
struct Product {
    int id;
    char name[100];
    int quantity;
};

// Function to add a new product to the inventory
void addProduct(struct Product inventory[], int *count) {
    // Get the product details from the user
    int id, quantity;
    char name[100];
    printf("Enter the product ID: ");
    scanf("%d", &id);
    printf("Enter the product name: ");
    scanf("%s", name);
    printf("Enter the product quantity: ");
    scanf("%d", &quantity);

    // Create the new product
    struct Product newProduct;
    newProduct.id = id;
    strcpy(newProduct.name, name);
    newProduct.quantity = quantity;

    // Add the new product to the inventory
    inventory[*count] = newProduct;
    *count += 1;

    // Print a success message
    printf("Product added successfully!\n");
}

// Function to remove a product from the inventory
void removeProduct(struct Product inventory[], int *count, int id) {
    // Find the product in the inventory
    int index = -1;
    for (int i = 0; i < *count; i++) {
        if (inventory[i].id == id) {
            index = i;
            break;
        }
    }

    // If the product was not found, print an error message and return
    if (index == -1) {
        printf("Product with ID %d not found.\n", id);
        return;
    }

    // Remove the product from the inventory
    for (int i = index; i < *count - 1; i++) {
        inventory[i] = inventory[i+1];
    }
    *count -= 1;

    // Print a success message
    printf("Product with ID %d removed successfully!\n", id);
}

// Function to display all the products in the inventory
void displayInventory(struct Product inventory[], int count) {
    // Print the header
    printf("ID\tName\t\tQuantity\n");

    // Loop through all the products and print their details
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%d\n", inventory[i].id, inventory[i].name, inventory[i].quantity);
    }
}

int main() {
    // Initialize an empty inventory
    struct Product inventory[100];
    int count = 0;

    // Loop through a menu of options
    int choice;
    do {
        printf("Warehouse Management System\n");
        printf("1. Add a new product\n");
        printf("2. Remove a product\n");
        printf("3. Display the inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch(choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                int id;
                printf("Enter the ID of the product to remove: ");
                scanf("%d", &id);
                removeProduct(inventory, &count, id);
                break;
            case 3:
                displayInventory(inventory, count);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}