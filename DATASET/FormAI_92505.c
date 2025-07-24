//FormAI DATASET v1.0 Category: Product Inventory System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    char name[50];
    int price;
    int quantity;
} Product;

void printProduct(Product p) {
    printf("Name: %s\nPrice: %d\nQuantity: %d\n", p.name, p.price, p.quantity);
}

void updateInventory(Product* p, int newQuantity) {
    p->quantity += newQuantity;
    printf("Inventory updated. New quantity: %d\n", p->quantity);
}

int main() {
    // Initialize inventory
    Product inventory[3] = {
        {"Bottled Water", 10, 50},
        {"Canned Food", 20, 30},
        {"First Aid Kit", 50, 5}
    };

    // Welcome message
    printf("Welcome to the post-apocalyptic product inventory system.\n");

    // User menu
    char input[50];
    int choice;
    while (1) {
        printf("\nEnter a command:\n1 - List all products\n2 - Search product by name\n3 - Update inventory\n4 - Quit\n");
        fgets(input, 50, stdin);
        choice = atoi(input);

        switch (choice) {
            case 1:
                printf("\nProduct List:\n");
                for (int i=0; i<3; i++) {
                    printProduct(inventory[i]);
                }
                break;
            case 2:
                printf("Enter product name: ");
                fgets(input, 50, stdin);
                for (int i=0; i<3; i++) {
                    if (strcmp(input, inventory[i].name) == 0) {
                        printf("\nSearch Result:\n");
                        printProduct(inventory[i]);
                        break;
                    }
                    if (i == 2) printf("\nProduct not found.\n");
                }
                break;
            case 3:
                printf("Enter product name to update inventory: ");
                fgets(input, 50, stdin);
                for (int i=0; i<3; i++) {
                    if (strcmp(input, inventory[i].name) == 0) {
                        printf("Enter new quantity: ");
                        fgets(input, 50, stdin);
                        int newQuantity = atoi(input);
                        updateInventory(&inventory[i], newQuantity);
                        break;
                    }
                    if (i == 2) printf("\nProduct not found.\n");
                }
                break;
            case 4:
                printf("Goodbye.\n");
                return 0;
            default:
                printf("Invalid command.\n");
                break;
        }
    }
}