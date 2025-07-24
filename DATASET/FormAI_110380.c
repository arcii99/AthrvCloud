//FormAI DATASET v1.0 Category: Product Inventory System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct ProductInventory {
    struct Product products[100];
    int count;
};

void addProduct(struct ProductInventory *inventory, struct Product product) {
    inventory->products[inventory->count] = product;
    inventory->count++;
}

void removeProduct(struct ProductInventory *inventory, int id) {
    int i, j;
    for(i = 0; i < inventory->count; i++) {
        if(inventory->products[i].id == id) {
            for(j = i; j < inventory->count - 1; j++) {
                inventory->products[j] = inventory->products[j+1];
            }
            inventory->count--;
            break;
        }
    }
}

void printInventory(struct ProductInventory *inventory) {
    int i;
    printf("----------------------------------------\n");
    printf(" PRODUCT ID      PRODUCT NAME    QUANTITY       PRICE\n");
    printf("----------------------------------------\n");
    for(i = 0; i < inventory->count; i++) {
        printf(" %d\t\t%-10s      %d\t\t%.2f\n",
                inventory->products[i].id,
                inventory->products[i].name,
                inventory->products[i].quantity,
                inventory->products[i].price);
    }
    printf("----------------------------------------\n");
}

int main() {
    struct ProductInventory inventory;
    inventory.count = 0;

    struct Product product1;
    product1.id = 1001;
    strcpy(product1.name, "Toothpaste");
    product1.quantity = 50;
    product1.price = 2.50;

    struct Product product2;
    product2.id = 1002;
    strcpy(product2.name, "Shampoo");
    product2.quantity = 30;
    product2.price = 5.00;

    addProduct(&inventory, product1);
    addProduct(&inventory, product2);

    printInventory(&inventory);

    removeProduct(&inventory, 1002);

    printInventory(&inventory);

    return 0;
}