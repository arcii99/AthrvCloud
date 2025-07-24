//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

// A struct for each product in the inventory
struct product {
    char name[50];
    int count;
    float price;
};

// The inventory itself, an array of product structs
struct product inventory[MAX_PRODUCTS];

// Track the current number of products in the inventory
int numProducts = 0;

// Function prototypes
void displayMenu();
void displayInventory();
void addProduct();
void removeProduct();
void updateProduct();

int main() {

    // Initialize the inventory with some default products
    strcpy(inventory[0].name, "Neural Implant");
    inventory[0].count = 10;
    inventory[0].price = 3500.00;

    strcpy(inventory[1].name, "Cyberdeck");
    inventory[1].count = 5;
    inventory[1].price = 5500.00;

    numProducts = 2;

    // Display the main menu and process user input
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayInventory();
                break;
            case 2:
                addProduct();
                break;
            case 3:
                removeProduct();
                break;
            case 4:
                updateProduct();
                break;
            case 5:
                // Exit the program
                printf("Exiting inventory system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\n");
    printf("CYBERPUNK INVENTORY SYSTEM\n");
    printf("------------------------------\n");
    printf("1. Display Inventory\n");
    printf("2. Add Product\n");
    printf("3. Remove Product\n");
    printf("4. Update Product\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void displayInventory() {
    printf("\n");
    printf("CURRENT INVENTORY\n");
    printf("---------------------------\n");
    printf("ID\tName\tCount\tPrice\n");
    printf("---------------------------\n");

    for (int i = 0; i < numProducts; i++) {
        printf("%d\t%s\t%d\t$%.2f\n", i, inventory[i].name, inventory[i].count, inventory[i].price);
    }
}

void addProduct() {
    if (numProducts == MAX_PRODUCTS) {
        printf("\n");
        printf("Error: inventory is full!\n");
        return;
    }

    struct product p;
    printf("\n");
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product count: ");
    scanf("%d", &p.count);
    printf("Enter product price: ");
    scanf("%f", &p.price);

    inventory[numProducts] = p;
    numProducts++;

    printf("Product added to inventory.\n");
}

void removeProduct() {
    printf("\n");
    printf("Enter product ID to remove: ");
    int id;
    scanf("%d", &id);

    if (id < 0 || id >= numProducts) {
        printf("\n");
        printf("Error: invalid product ID!\n");
        return;
    }

    struct product p = inventory[id];

    for (int i = id; i < numProducts - 1; i++) {
        inventory[i] = inventory[i+1];
    }

    numProducts--;

    printf("\n");
    printf("Product removed from inventory: %s\n", p.name);
}

void updateProduct() {
    printf("\n");
    printf("Enter product ID to update: ");
    int id;
    scanf("%d", &id);

    if (id < 0 || id >= numProducts) {
        printf("\n");
        printf("Error: invalid product ID!\n");
        return;
    }

    struct product p = inventory[id];

    printf("\n");
    printf("Updating product: %s\n", p.name);
    printf("Enter new product name (or leave blank to keep current name): ");
    char newName[50];
    scanf("%s", newName);
    if (strlen(newName) > 0) {
        strcpy(p.name, newName);
    }

    printf("Enter new product count (or -1 to keep current count): ");
    int newCount;
    scanf("%d", &newCount);
    if (newCount >= 0) {
        p.count = newCount;
    }

    printf("Enter new product price (or -1 to keep current price): ");
    float newPrice;
    scanf("%f", &newPrice);
    if (newPrice >= 0) {
        p.price = newPrice;
    }

    inventory[id] = p;

    printf("\n");
    printf("Product updated: %s\n", p.name);
}