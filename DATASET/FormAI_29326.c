//FormAI DATASET v1.0 Category: Product Inventory System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declare the structure of the product
struct product {
    char name[50];
    int quantity;
    float price;
};

// function to add a product to inventory
void addProduct(struct product *inventory, int *count) {
    printf("Enter the product name: ");
    scanf("%s", inventory[*count].name);
    printf("Enter the quantity: ");
    scanf("%d", &inventory[*count].quantity);
    printf("Enter the price: ");
    scanf("%f", &inventory[*count].price);
    (*count)++;
}

// function to display all products in inventory
void displayInventory(struct product *inventory, int count) {
    printf("Product\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    struct product inventory[100]; // initialize a product array
    int count = 0; // initialize inventory count to 0

    int choice; // declare choice variable

    do {
        // print menu options
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Quit\n");

        printf("Enter choice: ");
        scanf("%d", &choice); // get user choice

        switch(choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                displayInventory(inventory, count);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 3); // loop until user chooses to quit

    return 0;
}