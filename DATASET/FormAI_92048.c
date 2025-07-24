//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Romeo and Juliet
// Scene: The Great Hall of a Product Company

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The Inventory
typedef struct {
    char product_name[50];
    int quantity;
} Product;

// Romeo
void give(Product *product, int count) {
    product->quantity += count;
    printf("O, give me %d of %s, my dear inventory!\n", count, product->product_name);
}

// Juliet
void take(Product *product, int count) {
    if (product->quantity >= count) {
        product->quantity -= count;
        printf("I will take %d of %s, thank you!\n", count, product->product_name);
    } else {
        printf("Alas, I cannot take %d of %s, for there is not enough inventory!\n", count, product->product_name);
    }
}

int main() {
    // The Inventory List
    Product inventory[3];
    strcpy(inventory[0].product_name, "Apples");
    inventory[0].quantity = 10;
    strcpy(inventory[1].product_name, "Oranges");
    inventory[1].quantity = 20;
    strcpy(inventory[2].product_name, "Bananas");
    inventory[2].quantity = 15;

    // Romeo Requests
    give(&inventory[0], 5);
    take(&inventory[1], 15);

    // Juliet Requests
    give(&inventory[2], 10);
    take(&inventory[0], 20);

    return 0;
}