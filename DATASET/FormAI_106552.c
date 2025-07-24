//FormAI DATASET v1.0 Category: Product Inventory System ; Style: light-weight
#include<stdio.h>
#include<string.h>

#define MAX_PRODUCTS 100

struct Product {
    char name[50];
    int quantity;
    float price;
};

struct Inventory {
    struct Product products[MAX_PRODUCTS];
    int count;
};

// function to add a product to the inventory
void addProduct(struct Inventory* inventory, struct Product product) {
    if (inventory->count >= MAX_PRODUCTS) {
        printf("Inventory is full!\n");
        return;
    }
    
    inventory->products[inventory->count++] = product;
    printf("%s added to inventory successfully\n", product.name);
}

// function to remove a product from the inventory
void removeProduct(struct Inventory* inventory, char* name) {
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->products[i].name, name) == 0) {
            printf("%s removed from inventory successfully\n", name);
            for (int j = i; j < inventory->count - 1; j++) {
                inventory->products[j] = inventory->products[j+1];
            }
            inventory->count--;
            return;
        }
    }
    printf("%s not found in inventory\n", name);
}

// function to display all products in the inventory
void displayInventory(struct Inventory inventory) {
    printf("Product\tQuantity\tPrice\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < inventory.count; i++) {
        printf("%s\t%d\t\t%.2f\n", inventory.products[i].name, inventory.products[i].quantity, inventory.products[i].price);
    }
}

int main() {
    struct Inventory inventory;
    inventory.count = 0;
    
    // add some products to the inventory
    addProduct(&inventory, (struct Product){"Pen", 50, 1.25});
    addProduct(&inventory, (struct Product){"Pencil", 100, 0.75});
    
    // display inventory
    displayInventory(inventory);
    
    // remove a product from inventory
    removeProduct(&inventory, "Pen");
    
    // display inventory again
    displayInventory(inventory);
    
    return 0;
}