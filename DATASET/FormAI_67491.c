//FormAI DATASET v1.0 Category: Product Inventory System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 50

struct product {
    int code;
    char name[30];
    int quantity;
    float price;
};

struct inventory {
    struct product products[MAX_PRODUCTS];
    int count;
};

void initialize_inventory(struct inventory *inv) {
    inv->count = 0;
}

void add_product(struct inventory *inv, struct product new_product) {
    if (inv->count == MAX_PRODUCTS) {
        printf("Error: inventory is full!\n");
        return;
    }

    inv->products[inv->count] = new_product;
    inv->count++;
}

void display_inventory(struct inventory inv) {
    printf("%-10s %-30s %-10s %-10s\n", "Code", "Product Name", "Quantity", "Price");

    for (int i = 0; i < inv.count; i++) {
        printf("%-10d %-30s %-10d %-10.2f\n",
               inv.products[i].code, inv.products[i].name, inv.products[i].quantity, inv.products[i].price);
    }
}

void search_product(struct inventory inv, int code) {
    for (int i = 0; i < inv.count; i++) {
        if (inv.products[i].code == code) {
            printf("%-10s %-30s %-10s %-10s\n", "Code", "Product Name", "Quantity", "Price");
            printf("%-10d %-30s %-10d %-10.2f\n",
                   inv.products[i].code, inv.products[i].name, inv.products[i].quantity, inv.products[i].price);
            return;
        }
    }

    printf("Error: product not found!\n");
}

void update_product(struct inventory *inv, int code, struct product updated_product) {
    for (int i = 0; i < inv->count; i++) {
        if (inv->products[i].code == code) {
            inv->products[i] = updated_product;
            return;
        }
    }

    printf("Error: product not found!\n");
}

int main() {
    int choice;
    int code;
    struct product new_product;
    struct product updated_product;
    struct inventory inv;

    initialize_inventory(&inv);

    do {
        printf("\n");
        printf("Product Inventory System - Menu\n");
        printf("================================\n");
        printf("1) Add Product\n");
        printf("2) Display Inventory\n");
        printf("3) Search Product\n");
        printf("4) Update Product\n");
        printf("5) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product code: ");
                scanf("%d", &new_product.code);
                getchar(); // flush newline from input buffer
                printf("Enter product name: ");
                fgets(new_product.name, 30, stdin);
                new_product.name[strcspn(new_product.name, "\n")] = 0; // remove newline from end of input
                printf("Enter quantity: ");
                scanf("%d", &new_product.quantity);
                printf("Enter price: ");
                scanf("%f", &new_product.price);

                add_product(&inv, new_product);

                printf("Product added successfully.\n");
                break;

            case 2:
                if (inv.count == 0) {
                    printf("Inventory is empty.\n");
                } else {
                    display_inventory(inv);
                }
                break;

            case 3:
                printf("Enter product code: ");
                scanf("%d", &code);

                search_product(inv, code);

                break;

            case 4:
                printf("Enter product code to update: ");
                scanf("%d", &code);
                getchar(); // flush newline from input buffer

                for (int i = 0; i < inv.count; i++) {
                    if (inv.products[i].code == code) {
                        printf("Enter updated product name (blank to keep the same): ");
                        fgets(updated_product.name, 30, stdin);
                        updated_product.name[strcspn(updated_product.name, "\n")] = 0; // remove newline from end of input
                        printf("Enter updated quantity (0 to keep the same): ");
                        scanf("%d", &updated_product.quantity);
                        printf("Enter updated price (0.00 to keep the same): ");
                        scanf("%f", &updated_product.price);

                        if (strlen(updated_product.name) > 0) {
                            strcpy(inv.products[i].name, updated_product.name); // update name if it's not blank
                        }

                        if (updated_product.quantity > 0) {
                            inv.products[i].quantity = updated_product.quantity; // update quantity if it's greater than 0
                        }

                        if (updated_product.price > 0.00) {
                            inv.products[i].price = updated_product.price; // update price if it's greater than 0.00
                        }

                        printf("Product updated successfully.\n");
                        break;
                    }
                }
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}