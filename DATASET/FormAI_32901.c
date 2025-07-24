//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product {
    char name[50];
    int quantity;
    float price;
    char description[200];
};

struct product inventory[MAX_PRODUCTS];
int num_products = 0;

int main() {
    int choice;

    while(1) {
        printf("Welcome to CyberMart! What would you like to do?\n");
        printf("1. Add a new product\n");
        printf("2. View product inventory\n");
        printf("3. Update a product\n");
        printf("4. Remove a product\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_product();
                break;
            case 2:
                view_inventory();
                break;
            case 3:
                update_product();
                break;
            case 4:
                remove_product();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void add_product() {
    struct product new_product;
    printf("Enter product name: ");
    scanf("%s", new_product.name);
    
    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);

    printf("Enter product price: ");
    scanf("%f", &new_product.price);

    printf("Enter product description: ");
    scanf(" %[^\n]s", new_product.description);

    inventory[num_products] = new_product;
    num_products++;
}

void view_inventory() {
    if(num_products == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("Product Inventory:\n");

    for(int i = 0; i < num_products; i++) {
        printf("Product #%d\n", i + 1);
        printf("Name: %s\n", inventory[i].name);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: $%.2f\n", inventory[i].price);
        printf("Description: %s\n", inventory[i].description);
        printf("=================================\n");
    }
}

void update_product() {
    int product_num;
    printf("Enter product number to update: ");
    scanf("%d", &product_num);

    if(product_num < 1 || product_num > num_products) {
        printf("Invalid product number.\n");
        return;
    }

    struct product updated_product;
    printf("Enter new product name (or press enter to keep current name): ");
    scanf("%[^\n]s", updated_product.name);

    if(strlen(updated_product.name) == 0) {
        strcpy(updated_product.name, inventory[product_num-1].name);
    }

    printf("Enter new product quantity (or press enter to keep current quantity): ");
    char quantity_str[50];
    scanf(" %[^\n]s", quantity_str);

    if(strlen(quantity_str) == 0) {
        updated_product.quantity = inventory[product_num-1].quantity;
    } else {
        updated_product.quantity = atoi(quantity_str);
    }

    printf("Enter new product price (or press enter to keep current price): ");
    char price_str[50];
    scanf(" %[^\n]s", price_str);

    if(strlen(price_str) == 0) {
        updated_product.price = inventory[product_num-1].price;
    } else {
        updated_product.price = atof(price_str);
    }

    printf("Enter new product description (or press enter to keep current description): ");
    scanf(" %[^\n]s", updated_product.description);

    inventory[product_num-1] = updated_product;
    printf("Product updated.\n");
}

void remove_product() {
    int product_num;
    printf("Enter product number to remove: ");
    scanf("%d", &product_num);

    if(product_num < 1 || product_num > num_products) {
        printf("Invalid product number.\n");
        return;
    }

    for(int i = product_num - 1; i < num_products - 1; i++) {
        inventory[i] = inventory[i+1];
    }

    num_products--;
    printf("Product removed.\n");
}