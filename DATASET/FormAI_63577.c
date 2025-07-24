//FormAI DATASET v1.0 Category: Product Inventory System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 50
#define MAX_NAME_LENGTH 20
#define MAX_CATEGORY_LENGTH 15

struct Product {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    float price;
};

struct Inventory {
    struct Product products[MAX_PRODUCTS];
    int count;
};

void addProduct(struct Inventory *inventory) {
    struct Product product;
    printf("\nPlease enter product details:\n");
    printf("Name: ");
    scanf("%s", product.name);
    printf("Category: ");
    scanf("%s", product.category);
    printf("Quantity: ");
    scanf("%d", &product.quantity);
    printf("Price: ");
    scanf("%f", &product.price);
    
    if (inventory->count < MAX_PRODUCTS) {
        inventory->products[inventory->count] = product;
        inventory->count++;
        printf("\nProduct added successfully!\n");
    }
    else {
        printf("\nSorry, the inventory is full.\n");
    }
}

void listProducts(struct Inventory *inventory) {
    printf("\nAll Products:\n");
    printf("-------------------------\n");
    printf("| %-20s | %-10s | %-8s | %-8s |\n", "Name", "Category", "Quantity", "Price");
    printf("-------------------------\n");
    for (int i = 0; i < inventory->count; i++) {
        struct Product product = inventory->products[i];
        printf("| %-20s | %-10s | %-8d | $%-7.2f |\n", product.name, product.category, product.quantity, product.price);
    }
    printf("-------------------------\n");
}

void searchProduct(struct Inventory *inventory, char *name) {
    printf("\nSearch results for '%s':\n", name);
    printf("-------------------------\n");
    printf("| %-20s | %-10s | %-8s | %-8s |\n", "Name", "Category", "Quantity", "Price");
    printf("-------------------------\n");
    for (int i = 0; i < inventory->count; i++) {
        struct Product product = inventory->products[i];
        if (strcmp(product.name, name) == 0) {
            printf("| %-20s | %-10s | %-8d | $%-7.2f |\n", product.name, product.category, product.quantity, product.price);
        }
    }
    printf("-------------------------\n");
}

void sellProduct(struct Inventory *inventory, char *name, int quantity) {
    int i;
    for (i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->products[i].name, name) == 0) {
            if (inventory->products[i].quantity >= quantity) {
                inventory->products[i].quantity -= quantity;
                printf("\n%d %s sold successfully!\n", quantity, name);
            }
            else {
                printf("\nSorry, only %d %s available.\n", inventory->products[i].quantity, name);
            }
            return;
        }
    }
    printf("\nProduct not found in inventory.\n");
}

void mainMenu(struct Inventory *inventory) {
    int choice;
    do {
        printf("\n\nProduct Inventory System\n");
        printf("---------------------------\n");
        printf("1. Add a product\n");
        printf("2. List all products\n");
        printf("3. Search for a product\n");
        printf("4. Sell a product\n");
        printf("0. Exit\n");
        printf("---------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct(inventory);
                break;
            case 2:
                listProducts(inventory);
                break;
            case 3:
                char name[MAX_NAME_LENGTH];
                printf("\nEnter product name: ");
                scanf("%s", name);
                searchProduct(inventory, name);
                break;
            case 4:
                char sellName[MAX_NAME_LENGTH];
                int quantity;
                printf("\nEnter product name: ");
                scanf("%s", sellName);
                printf("Enter quantity to sell: ");
                scanf("%d", &quantity);
                sellProduct(inventory, sellName, quantity);
                break;
            case 0:
                printf("\nThank you for using Product Inventory System!\n\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);
}

int main() {
    struct Inventory inventory = { .count = 0 };
    mainMenu(&inventory);
    return 0;
}