//FormAI DATASET v1.0 Category: Product Inventory System ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct product {
    char name[50];
    int quantity;
    float price;
};

int main() {
    struct product inventory[20]; // Create an array to hold up to 20 products
    int choice, index, quantity; // Variables for user input
    float price;
    char name[50];

    printf("Welcome to the Product Inventory System!\n");

    // Initialize the inventory to empty values
    for (int i = 0; i < 20; i++) {
        strcpy(inventory[i].name, "");  // Clear the name field
        inventory[i].quantity = 0;      // Set the quantity to 0
        inventory[i].price = 0.0;       // Set the price to 0
    }

    do {
        printf("\n1. Add a product\n2. Remove a product\n3. Display inventory\n4. Quit\n\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Ask for product details
                printf("\nEnter the name of the product: ");
                scanf("%s", name);

                printf("Enter the quantity of the product: ");
                scanf("%d", &quantity);
            
                printf("Enter the price of the product: ");
                scanf("%f", &price);

                // Find the first empty slot in the inventory
                index = -1;
                for (int i = 0; i < 20; i++) {
                    if (strcmp(inventory[i].name, "") == 0) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    printf("\nError: the inventory is full.\n");
                } else {
                    // Add the new product to the inventory
                    strcpy(inventory[index].name, name);
                    inventory[index].quantity = quantity;
                    inventory[index].price = price;
                    printf("\n%s has been added to the inventory.\n", name);
                }

                break;

            case 2:
                // Ask for the name of the product to remove
                printf("\nEnter the name of the product to remove: ");
                scanf("%s", name);

                // Find the index of the product in the inventory
                index = -1;
                for (int i = 0; i < 20; i++) {
                    if (strcmp(inventory[i].name, name) == 0) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    printf("\nError: %s was not found in the inventory.\n", name);
                } else {
                    // Remove the product from the inventory
                    strcpy(inventory[index].name, "");
                    inventory[index].quantity = 0;
                    inventory[index].price = 0.0;
                    printf("\n%s has been removed from the inventory.\n", name);
                }

                break;

            case 3:
                // Print the inventory
                printf("\n %-20s %10s %10s\n\n", "Product Name", "Quantity", "Price");
                for (int i = 0; i < 20; i++) {
                    if (strcmp(inventory[i].name, "") != 0) {
                        printf(" %-20s %10d %10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
                    }
                }

                break;

            case 4:
                printf("\nGoodbye!\n\n");
                break;

            default:
                printf("\nError: invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}