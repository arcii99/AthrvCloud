//FormAI DATASET v1.0 Category: Product Inventory System ; Style: resource intensive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 10000
#define MAX_NAME_LEN 50

typedef struct Product {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];

int num_products = 0;

/* Function to add a new product to the inventory */
void add_product(char *name, int quantity, float price) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: maximum number of products reached.\n");
        return;
    }
    Product p;
    strncpy(p.name, name, MAX_NAME_LEN);
    p.quantity = quantity;
    p.price = price;
    inventory[num_products++] = p;
    printf("Product added successfully.\n");
}

/* Function to remove a product from the inventory */
void remove_product(int index) {
    if (index >= num_products || index < 0) {
        printf("Error: invalid product index.\n");
        return;
    }
    for (int i = index; i < num_products-1; i++) {
        inventory[i] = inventory[i+1];
    }
    num_products--;
    printf("Product removed successfully.\n");
}

/* Function to update a product's quantity */
void update_quantity(int index, int quantity) {
    if (index >= num_products || index < 0) {
        printf("Error: invalid product index.\n");
        return;
    }
    inventory[index].quantity += quantity;
    printf("Quantity updated successfully.\n");
}

/* Function to update a product's price */
void update_price(int index, float price) {
    if (index >= num_products || index < 0) {
        printf("Error: invalid product index.\n");
        return;
    }
    inventory[index].price = price;
    printf("Price updated successfully.\n");
}

/* Function to search for a product by name */
int search_product(char *name) {
    for (int i = 0; i < num_products; i++) {
        if (strncmp(inventory[i].name, name, MAX_NAME_LEN) == 0) {
            return i;
        }
    }
    return -1;
}

/* Function to display the inventory */
void display_inventory() {
    printf("\nInventory:\n");
    printf("-----------------------------\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s (Qty: %d, Price: %.2f)\n", i, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("-----------------------------\n");
}

int main() {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
    int option, index;

    while (1) {
        printf("\nProduct Inventory System");
        printf("\n---------------------------");
        printf("\n1. Add product");
        printf("\n2. Remove product");
        printf("\n3. Update quantity");
        printf("\n4. Update price");
        printf("\n5. Search product");
        printf("\n6. Display inventory");
        printf("\n7. Exit");
        printf("\n---------------------------");
        printf("\nEnter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nEnter name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%f", &price);
                add_product(name, quantity, price);
                break;
            case 2:
                printf("\nEnter product index: ");
                scanf("%d", &index);
                remove_product(index);
                break;
            case 3:
                printf("\nEnter product index: ");
                scanf("%d", &index);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                update_quantity(index, quantity);
                break;
            case 4:
                printf("\nEnter product index: ");
                scanf("%d", &index);
                printf("Enter price: ");
                scanf("%f", &price);
                update_price(index, price);
                break;
            case 5:
                printf("\nEnter name: ");
                scanf("%s", name);
                index = search_product(name);
                if (index == -1) {
                    printf("Product not found.\n");
                } else {
                    printf("Product found at index %d.\n", index);
                }
                break;
            case 6:
                display_inventory();
                break;
            case 7:
                exit(0);
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}