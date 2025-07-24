//FormAI DATASET v1.0 Category: Product Inventory System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[50];
    int quantity;
    float price;
};

void displayInventory(struct product* products, int numProducts) {
    printf("\n---------------------------\n");
    printf(" INVENTORY MANAGEMENT SYSTEM\n");
    printf("---------------------------\n");

    printf("%-20s%-10s%-10s\n", "Product Name", "Quantity", "Price");
    for(int i=0;i<numProducts;i++) {
        printf("%-20s%-10d%-10.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
    printf("---------------------------\n");
}

int main() {
    int numProducts;
    printf("Enter number of products in inventory: ");
    scanf("%d", &numProducts);

    struct product* products = malloc(numProducts * sizeof(struct product));

    for(int i=0;i<numProducts;i++) {
        printf("\nEnter product name: ");
        scanf("%s", products[i].name);
        printf("Enter quantity: ");
        scanf("%d", &(products[i].quantity));
        printf("Enter price: ");
        scanf("%f", &(products[i].price));
    }

    displayInventory(products, numProducts);

    free(products);

    return 0;
}