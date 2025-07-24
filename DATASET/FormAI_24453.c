//FormAI DATASET v1.0 Category: Product Inventory System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char product_name[20];
    int product_id;
    float product_price;
    int product_quantity;
} product;

product inventory[100];
int num_products = 0;

void add_product(char name[], int id, float price, int quantity) {
    strncpy(inventory[num_products].product_name, name, 20);
    inventory[num_products].product_id = id;
    inventory[num_products].product_price = price;
    inventory[num_products].product_quantity = quantity;
    num_products++;
}

void delete_product(int id) {
    int i, index = -1;
    for (i = 0; i < num_products; i++) {
        if (inventory[i].product_id == id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (i = index; i < num_products-1; i++) {
            inventory[i] = inventory[i+1];
        }
        num_products--;
    }
}

void update_product(int id, int quantity) {
    int i;
    for (i = 0; i < num_products; i++) {
        if (inventory[i].product_id == id) {
            inventory[i].product_quantity = quantity;
            break;
        }
    }
}

void search_product(char name[]) {
    int i, found = 0;
    for (i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].product_name, name) == 0) {
            printf("%-20s %-5d $%-7.2f %-5d\n", inventory[i].product_name, inventory[i].product_id, inventory[i].product_price, inventory[i].product_quantity);
            found = 1;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

void print_inventory() {
    int i;
    printf("%-20s %-5s %-10s %s\n", "Name", "ID", "Price", "Quantity");
    for (i = 0; i < num_products; i++) {
        printf("%-20s %-5d $%-7.2f %-5d\n", inventory[i].product_name, inventory[i].product_id, inventory[i].product_price, inventory[i].product_quantity);
    }
}

int main() {
    add_product("Apple", 1, 0.50, 100);
    add_product("Banana", 2, 0.25, 50);
    add_product("Grapes", 3, 1.25, 25);

    printf("Initial Inventory:\n");
    print_inventory();

    delete_product(2);
    printf("\nInventory after deleting Banana:\n");
    print_inventory();

    update_product(1, 75);
    printf("\nInventory after updating Apple quantity:\n");
    print_inventory();

    printf("\nSearching for Grapes:\n");
    search_product("Grapes");

    printf("\nSearching for Watermelon:\n");
    search_product("Watermelon");

    return 0;
}