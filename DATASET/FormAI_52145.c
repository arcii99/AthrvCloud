//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

typedef struct {
    int id;
    char name[50];
    char address[100];
} Warehouse;

void add_product(Product *product, int quantity);
void remove_product(Product *product, int quantity);
void display_inventory(Product *products, int count);
void display_warehouses(Warehouse *warehouses, int count);

int main() {
    Warehouse warehouses[5];
    warehouses[0].id = 1;
    strcpy(warehouses[0].name, "Warehouse A");
    strcpy(warehouses[0].address, "123 Main St");

    warehouses[1].id = 2;
    strcpy(warehouses[1].name, "Warehouse B");
    strcpy(warehouses[1].address, "456 Elm St");

    Product products[100];
    int product_count = 0;
    int choice;
    char name[50];
    while (1) {
        printf("What do you want to do?\n");
        printf("1 - Add Product\n");
        printf("2 - Remove Product\n");
        printf("3 - Display Inventory\n");
        printf("4 - Display Warehouses\n");
        printf("5 - Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Product Name: ");
                scanf("%s", name);
                printf("Enter Product Price: ");
                float price;
                scanf("%f", &price);
                int quantity;
                printf("Enter Product Quantity: ");
                scanf("%d", &quantity);
                Product product;
                strcpy(product.name, name);
                product.price = price;
                product.quantity = quantity;
                add_product(&product, quantity);
                products[product_count++] = product;
                break;
            case 2:
                printf("Enter Product Name: ");
                scanf("%s", name);
                for (int i = 0; i < product_count; i++) {
                    if (strcmp(products[i].name, name) == 0) {
                        printf("Enter Quantity to Remove: ");
                        int quantity;
                        scanf("%d", &quantity);
                        remove_product(&products[i], quantity);
                        break;
                    }
                }
                break;
            case 3:
                display_inventory(products, product_count);
                break;
            case 4:
                display_warehouses(warehouses, 2);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
}

void add_product(Product *product, int quantity) {
    printf("%d %s added to inventory\n", quantity, product->name);
}

void remove_product(Product *product, int quantity) {
    printf("%d %s removed from inventory\n", quantity, product->name);
    product->quantity -= quantity;
}

void display_inventory(Product *products, int count) {
    printf("Product Name\tProduct Price\tProduct Quantity\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%.2f\t\t%d\n", products[i].name, products[i].price, products[i].quantity);
    }
}

void display_warehouses(Warehouse *warehouses, int count) {
    printf("Warehouse ID\tWarehouse Name\tWarehouse Address\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t\t%s\t\t%s\n", warehouses[i].id, warehouses[i].name, warehouses[i].address);
    }
}