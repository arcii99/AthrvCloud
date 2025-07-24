//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_PRODUCTS 100 // maximum number of products that can be stored in inventory
#define MAX_NAME_LENGTH 30 // maximum length of product name
#define MAX_PRICE 1000 // maximum price of a product


// Structure to store product information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int price;
    int quantity;
} Product;

// Global array to store 'inventory' of products
Product inventory[MAX_PRODUCTS];

// Global variable to track the number of products currently in inventory
int num_products = 0;

// Global mutex to ensure safe access to inventory
pthread_mutex_t inventory_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to add a product to inventory
void add_product(char name[MAX_NAME_LENGTH], int price, int quantity) {
    pthread_mutex_lock(&inventory_mutex); // lock mutex to ensure safe access to inventory
    
    // Check if inventory is already full, if yes, print error message and return
    if (num_products == MAX_PRODUCTS) {
        printf("Error: Inventory is already full!\n");
        pthread_mutex_unlock(&inventory_mutex); // unlock mutex before returning
        return;
    }
    
    // Add new product to inventory
    strncpy(inventory[num_products].name, name, MAX_NAME_LENGTH);
    inventory[num_products].price = price;
    inventory[num_products].quantity = quantity;
    num_products++;
    
    // Unlock mutex before returning
    pthread_mutex_unlock(&inventory_mutex);
}

// Function to remove a product from inventory
void remove_product(int index) {
    pthread_mutex_lock(&inventory_mutex); // lock mutex to ensure safe access to inventory
    
    // Check if index is valid, if not, print error message and return
    if (index < 0 || index >= num_products) {
        printf("Error: Invalid index!\n");
        pthread_mutex_unlock(&inventory_mutex); // unlock mutex before returning
        return;
    }
    
    // Shift all elements after index by one position to the left
    for (int i = index; i < num_products - 1; i++) {
        inventory[i] = inventory[i+1];
    }
    num_products--;
    
    // Unlock mutex before returning
    pthread_mutex_unlock(&inventory_mutex);
}

// Function to update the price of a product in inventory
void update_price(int index, int new_price) {
    pthread_mutex_lock(&inventory_mutex); // lock mutex to ensure safe access to inventory
    
    // Check if index is valid, if not, print error message and return
    if (index < 0 || index >= num_products) {
        printf("Error: Invalid index!\n");
        pthread_mutex_unlock(&inventory_mutex); // unlock mutex before returning
        return;
    }
    
    // Update price of product
    inventory[index].price = new_price;
    
    // Unlock mutex before returning
    pthread_mutex_unlock(&inventory_mutex);
}

// Function to update the quantity of a product in inventory
void update_quantity(int index, int new_quantity) {
    pthread_mutex_lock(&inventory_mutex); // lock mutex to ensure safe access to inventory
    
    // Check if index is valid, if not, print error message and return
    if (index < 0 || index >= num_products) {
        printf("Error: Invalid index!\n");
        pthread_mutex_unlock(&inventory_mutex); // unlock mutex before returning
        return;
    }
    
    // Update quantity of product
    inventory[index].quantity = new_quantity;
    
    // Unlock mutex before returning
    pthread_mutex_unlock(&inventory_mutex);
}

// Function to display all products in inventory
void display_inventory() {
    pthread_mutex_lock(&inventory_mutex); // lock mutex to ensure safe access to inventory
    
    printf("Inventory:\n");
    printf("--------------------------------------------------\n");
    printf("%-5s %-30s %-10s %-10s\n", "Index", "Name", "Price", "Quantity");
    printf("--------------------------------------------------\n");
    
    for (int i = 0; i < num_products; i++) {
        printf("%-5d %-30s %-10d %-10d\n", i, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    
    // Unlock mutex before returning
    pthread_mutex_unlock(&inventory_mutex);
}

// Main function - test the inventory system
int main() {
    // Add some products to inventory
    add_product("Product 1", 100, 10);
    add_product("Product 2", 200, 5);
    add_product("Product 3", 300, 0);
    
    // Display inventory
    display_inventory();
    
    // Update price of product at index 1
    update_price(1, 250);
    
    // Update quantity of product at index 0
    update_quantity(0, 20);
    
    // Remove product at index 2
    remove_product(2);
    
    // Display inventory again
    display_inventory();
    
    return 0;
}