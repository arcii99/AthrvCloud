//FormAI DATASET v1.0 Category: Product Inventory System ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#define MAX_PRODUCTS 100 // define the maximum product inventory capacity

typedef struct product { // define a struct for a product
    char name[50];
    float price;
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS]; // create an array of products for inventory
int numProducts = 0; // initialize the number of products in inventory

void addProduct(char name[], float price, int quantity) { // function to add new products to inventory
    if (numProducts < MAX_PRODUCTS) { // check if inventory is full
        Product newProduct; // create a new product
        strcpy(newProduct.name, name);
        newProduct.price = price;
        newProduct.quantity = quantity;
        inventory[numProducts] = newProduct; // add the new product to inventory
        numProducts++; // increment the number of products
        printf("Product '%s' successfully added to inventory.\n", name);
    } else {
        printf("Error: maximum inventory capacity reached.\n"); // print an error message if inventory is full
    }
}

void removeProduct(char name[]) { // function to remove a product from inventory
    for (int i = 0; i < numProducts; i++) { // loop through all products in inventory
        if (strcmp(inventory[i].name, name) == 0) { // check if the product names match
            for (int j = i; j < numProducts - 1; j++) { // shift all subsequent products down one index
                inventory[j] = inventory[j+1];
            }
            numProducts--; // decrement the number of products
            printf("Product '%s' successfully removed from inventory.\n", name);
            return;
        }
    }
    printf("Error: unable to find product '%s' in inventory.\n", name); // print an error message if the product is not found
}

void updateProduct(char name[], float price, int quantity) { // function to update a product in inventory
    for (int i = 0; i < numProducts; i++) { // loop through all products in inventory
        if (strcmp(inventory[i].name, name) == 0) { // check if the product names match
            inventory[i].price = price; // update the product price
            inventory[i].quantity = quantity; // update the product quantity
            printf("Product '%s' successfully updated in inventory.\n", name);
            return;
        }
    }
    printf("Error: unable to find product '%s' in inventory.\n", name); // print an error message if the product is not found
}

void displayInventory() { // function to display the current inventory
    printf("\nCurrent Inventory:\n");
    for (int i = 0; i < numProducts; i++) { // loop through all products in inventory
        printf("%s -- $%.2f -- %d in stock\n", inventory[i].name, inventory[i].price, inventory[i].quantity); // print the product info
    }
}

int main() {
    addProduct("iPhone", 999.99, 10);
    addProduct("MacBook Pro", 1499.99, 5);
    addProduct("Apple Watch", 399.99, 15);
    displayInventory();
    updateProduct("iPhone", 899.99, 5);
    removeProduct("MacBook Pro");
    displayInventory();
    return 0;
}