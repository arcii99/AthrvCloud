//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multivariable
#include <stdio.h>
#include <string.h>

// Define the maximum number of products that can be stored
#define MAX_PRODUCTS 100

// Product struct with the necessary information about each product
struct product {
    int id;
    char name[50];
    float price;
    int quantity;
};

// Global inventory array to store all products
struct product inventory[MAX_PRODUCTS];

// Function to add a new product to the inventory
int add_product(int id, char name[], float price, int quantity) {
    // Check if the product ID already exists in the inventory
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (inventory[i].id == id) {
            printf("Product already exists with that ID.\n");
            return 0;
        }
    }

    // Check if the inventory is full
    int i;
    for (i = 0; i < MAX_PRODUCTS; i++) {
        if (inventory[i].id == 0) {
            break;
        }
    }
    if (i == MAX_PRODUCTS) {
        printf("Inventory is full.\n");
        return 0;
    }

    // Add the new product to the inventory
    inventory[i].id = id;
    strcpy(inventory[i].name, name);
    inventory[i].price = price;
    inventory[i].quantity = quantity;

    printf("Product added to inventory.\n");

    return 1;
}

// Function to remove a product from the inventory
int remove_product(int id) {
    // Check if the product ID exists in the inventory
    int i;
    for (i = 0; i < MAX_PRODUCTS; i++) {
        if (inventory[i].id == id) {
            break;
        }
    }
    if (i == MAX_PRODUCTS) {
        printf("Product does not exist with that ID.\n");
        return 0;
    }

    // Remove the product from the inventory
    inventory[i].id = 0;
    inventory[i].name[0] = '\0';
    inventory[i].price = 0;
    inventory[i].quantity = 0;

    printf("Product removed from inventory.\n");

    return 1;
}

// Function to display all products in the inventory
void display_inventory() {
    printf("ID\tName\tPrice\tQuantity\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (inventory[i].id != 0) {
            printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
        }
    }
}

// Function to update the quantity of a product in the inventory
int update_quantity(int id, int quantity) {
    // Check if the product ID exists in the inventory
    int i;
    for (i = 0; i < MAX_PRODUCTS; i++) {
        if (inventory[i].id == id) {
            break;
        }
    }
    if (i == MAX_PRODUCTS) {
        printf("Product does not exist with that ID.\n");
        return 0;
    }

    // Update the quantity of the product in the inventory
    inventory[i].quantity += quantity;

    printf("Product quantity updated in inventory.\n");

    return 1;
}

// Main function to test the product inventory system
int main() {
    // Add a few products to the inventory
    add_product(1, "iPhone 12", 799.99, 10);
    add_product(2, "Samsung Galaxy S21", 899.99, 15);
    add_product(3, "Google Pixel 5", 699.99, 5);

    // Display the inventory
    display_inventory();

    // Remove a product from the inventory
    remove_product(2);

    // Display the inventory again
    display_inventory();

    // Update the quantity of a product in the inventory
    update_quantity(1, 5);

    // Display the inventory one last time
    display_inventory();

    return 0;
}