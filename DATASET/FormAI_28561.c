//FormAI DATASET v1.0 Category: Product Inventory System ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the maximum size of the product inventory
#define MAX_PRODUCTS 100

// Define the structure of a product
struct product {
    int id;
    char name[50];
    float price;
    int quantity;
};

// Define the product inventory as an array of structs
struct product inventory[MAX_PRODUCTS];

int num_products = 0;

// Function to add a product to the inventory
void add_product(int id, char name[], float price, int quantity) {
    // Check if the inventory is full
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Inventory is full\n");
        return;
    }
    // Check if the product already exists
    for (int i = 0; i < num_products; i++) {
        if (inventory[i].id == id) {
            printf("Error: Product already exists\n");
            return;
        }
    }
    // Add the product to the inventory
    struct product p;
    p.id = id;
    strcpy(p.name, name);
    p.price = price;
    p.quantity = quantity;
    inventory[num_products] = p;
    num_products++;
}

// Function to remove a product from the inventory
void remove_product(int id) {
    // Check if the product exists
    int index = -1;
    for (int i = 0; i < num_products; i++) {
        if (inventory[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Error: Product does not exist\n");
        return;
    }
    // Remove the product from the inventory
    for (int i = index; i < num_products - 1; i++) {
        inventory[i] = inventory[i+1];
    }
    num_products--;
}

// Function to update a product in the inventory
void update_product(int id, char name[], float price, int quantity) {
    // Check if the product exists
    int index = -1;
    for (int i = 0; i < num_products; i++) {
        if (inventory[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Error: Product does not exist\n");
        return;
    }
    // Update the product in the inventory
    strcpy(inventory[index].name, name);
    inventory[index].price = price;
    inventory[index].quantity = quantity;
}

// Function to display the inventory
void display_inventory() {
    printf("Id\tName\tPrice\tQuantity\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

int main() {
    // Add some initial products to the inventory
    add_product(1, "Product 1", 10.00, 5);
    add_product(2, "Product 2", 20.00, 10);
    add_product(3, "Product 3", 30.00, 15);
    
    // Display the initial inventory
    display_inventory();
    
    // Update a product
    update_product(2, "New Product 2", 25.00, 12);
    
    // Display the updated inventory
    display_inventory();
    
    // Remove a product
    remove_product(3);
    
    // Display the final inventory
    display_inventory();
    
    return 0;
}