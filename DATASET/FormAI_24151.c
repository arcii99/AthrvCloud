//FormAI DATASET v1.0 Category: Product Inventory System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constant values for product attributes
#define PRODUCT_NAME_LENGTH 30
#define PRODUCT_CODE_LENGTH 10
#define MAX_PRODUCTS 100

// Create structure to represent a product
typedef struct Product {
    char name[PRODUCT_NAME_LENGTH];
    char code[PRODUCT_CODE_LENGTH];
    int quantity;
    double price;
} Product;

// Create an array to hold products
Product products[MAX_PRODUCTS];

// Define a function to display all products in the inventory
void displayInventory() {
    printf("| %-31s | %-11s | %-9s | %s |\n", "Product Name", "Product Code", "Quantity", "Price");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strlen(products[i].code) > 0) {
            printf("| %-31s | %-11s | %-9d | $%.2f |\n", products[i].name, products[i].code, products[i].quantity, products[i].price);
        }
    }
}

// Define a function to add a new product to the inventory
void addProduct() {
    printf("Enter the product name: ");
    scanf("%s", products[MAX_PRODUCTS-1].name);
    printf("Enter the product code: ");
    scanf("%s", products[MAX_PRODUCTS-1].code);
    printf("Enter the product quantity: ");
    scanf("%d", &products[MAX_PRODUCTS-1].quantity);
    printf("Enter the product price: ");
    scanf("%lf", &products[MAX_PRODUCTS-1].price);
    printf("\nProduct added successfully!\n");
}

// Define a function to remove a product from the inventory
void removeProduct() {
    char code[PRODUCT_CODE_LENGTH];
    printf("Enter the product code of the product you want to remove: ");
    scanf("%s", code);
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strcmp(products[i].code, code) == 0) {
            strcpy(products[i].name, "");
            strcpy(products[i].code, "");
            products[i].quantity = 0;
            products[i].price = 0;
            printf("\nProduct removed successfully!\n");
            return;
        }
    }
    printf("\nProduct with code %s not found.\n", code);
}

// Define a function to update the quantity of a product in the inventory
void updateQuantity() {
    char code[PRODUCT_CODE_LENGTH];
    int quantity;
    printf("Enter the product code of the product you want to update: ");
    scanf("%s", code);
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strcmp(products[i].code, code) == 0) {
            printf("Enter the new quantity: ");
            scanf("%d", &quantity);
            products[i].quantity = quantity;
            printf("\nQuantity updated successfully!\n");
            return;
        }
    }
    printf("\nProduct with code %s not found.\n", code);
}

int main() {
    // Initialize the inventory with three sample products
    strcpy(products[0].name, "Milk");
    strcpy(products[0].code, "001");
    products[0].quantity = 10;
    products[0].price = 2.99;
    strcpy(products[1].name, "Bread");
    strcpy(products[1].code, "002");
    products[1].quantity = 20;
    products[1].price = 1.99;
    strcpy(products[2].name, "Eggs");
    strcpy(products[2].code, "003");
    products[2].quantity = 30;
    products[2].price = 0.99;

    // Display the main menu and allow the user to select an option
    char choice;
    while (1) {
        printf("\nProduct Inventory System\n");
        printf("------------------------\n");
        printf("1. View Inventory\n");
        printf("2. Add a Product\n");
        printf("3. Remove a Product\n");
        printf("4. Update Quantity\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch(choice) {
            case '1': 
                displayInventory(); 
                break;
            case '2': 
                addProduct(); 
                break;
            case '3': 
                removeProduct(); 
                break;
            case '4': 
                updateQuantity(); 
                break;
            case '5':
                printf("Exiting Product Inventory System...");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}