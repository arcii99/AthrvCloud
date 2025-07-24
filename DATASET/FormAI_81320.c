//FormAI DATASET v1.0 Category: Product Inventory System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[50];
    int id;
    float price;
    int quantity;
};

int main() {
    int num_products;
    printf("How many products do you want to add to the inventory? ");
    scanf("%d", &num_products);

    struct product *inventory = (struct product *)malloc(num_products * sizeof(struct product));
    if (inventory == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < num_products; i++) {
        printf("\nProduct %d:\n", i+1);
        printf("Name: ");
        scanf("%s", inventory[i].name);
        printf("ID: ");
        scanf("%d", &inventory[i].id);
        printf("Price: ");
        scanf("%f", &inventory[i].price);
        printf("Quantity: ");
        scanf("%d", &inventory[i].quantity);
    }

    printf("\nPRODUCT INVENTORY:\n");
    printf("%-20s%-10s%-10s%s\n", "Name", "ID", "Price", "Quantity");
    for (int i = 0; i < num_products; i++) {
        printf("%-20s%-10d%-10.2f%d\n", inventory[i].name, inventory[i].id, inventory[i].price, inventory[i].quantity);
    }

    free(inventory);

    return 0;
}