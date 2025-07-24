//FormAI DATASET v1.0 Category: Product Inventory System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the product inventory system
struct Product {
    char name[20];
    int id;
    int quantity;
    float price;
};

// Function to print the product details
void printProduct(struct Product *p) {
    printf("Name: %s\n", p->name);
    printf("ID: %d\n", p->id);
    printf("Quantity: %d\n", p->quantity);
    printf("Price: $%.2f\n", p->price);
}

int main() {

    // Create an array of product structures to store the inventory
    struct Product inventory[10];

    // Add some dummy products to the inventory
    strcpy(inventory[0].name, "Product 1");
    inventory[0].id = 1001;
    inventory[0].quantity = 10;
    inventory[0].price = 19.99;

    strcpy(inventory[1].name, "Product 2");
    inventory[1].id = 1002;
    inventory[1].quantity = 5;
    inventory[1].price = 29.99;

    strcpy(inventory[2].name, "Product 3");
    inventory[2].id = 1003;
    inventory[2].quantity = 15;
    inventory[2].price = 9.99;

    // Introduce the program with a mind-bending message
    printf("Welcome to the Product Inventory System!\n");
    printf("This program will keep track of your inventory in a way that bends the very laws of reality...\n");
    printf("Or at least makes it easy to manage your products!\n");

    // Loop through the program until the user chooses to exit
    int choice = 0;
    while (choice != 5) {
        // Prompt the user with the menu options
        printf("\nWhat would you like to do?\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. Update a product\n");
        printf("4. View inventory\n");
        printf("5. Exit\n");

        // Read the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle the user's choice
        switch(choice) {
            case 1: // Add a product
                // Find an empty slot in the inventory
                for(int i = 0; i < 10; i++) {
                    if(inventory[i].id == 0) {
                        // Prompt the user for the product details
                        printf("Enter the product name: ");
                        scanf("%s", inventory[i].name);
                        printf("Enter the product ID: ");
                        scanf("%d", &inventory[i].id);
                        printf("Enter the product quantity: ");
                        scanf("%d", &inventory[i].quantity);
                        printf("Enter the product price: ");
                        scanf("%f", &inventory[i].price);
                        break;
                    }
                }
                break;
            case 2: // Remove a product
                // Prompt the user for the product ID
                int removeID;
                printf("Enter the ID of the product you want to remove: ");
                scanf("%d", &removeID);
                // Find the product in the inventory and remove it
                for(int i = 0; i < 10; i++) {
                    if(inventory[i].id == removeID) {
                        inventory[i].id = 0;
                        inventory[i].quantity = 0;
                        inventory[i].price = 0.0;
                        strcpy(inventory[i].name, "");
                        break;
                    }
                }
                break;
            case 3: // Update a product
                // Prompt the user for the product ID
                int updateID;
                printf("Enter the ID of the product you want to update: ");
                scanf("%d", &updateID);
                // Find the product in the inventory and prompt the user for the new details
                for(int i = 0; i < 10; i++) {
                    if(inventory[i].id == updateID) {
                        printf("Enter the new product name: ");
                        scanf("%s", inventory[i].name);
                        printf("Enter the new product quantity: ");
                        scanf("%d", &inventory[i].quantity);
                        printf("Enter the new product price: ");
                        scanf("%f", &inventory[i].price);
                        break;
                    }
                }
                break;
            case 4: // View inventory
                // Loop through the inventory and print the details of each product
                for(int i = 0; i < 10; i++) {
                    if(inventory[i].id != 0) {
                        printf("Product %d:\n", i+1);
                        printProduct(&inventory[i]);
                        printf("\n");
                    }
                }
                break;
            case 5: // Exit the program
                printf("Exiting the program. Thanks for using the Product Inventory System!\n");
                break;
            default: // Invalid input
                printf("Invalid input. Please enter a number between 1 and 5.\n");
                break;
        }
    }

    return 0;
}