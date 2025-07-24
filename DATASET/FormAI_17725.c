//FormAI DATASET v1.0 Category: Product Inventory System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Product structure
struct Product {
    char name[50];
    double price;
    int quantity;
};

// Function prototypes
void addProduct(struct Product products[], int *pCount);
void displayProducts(struct Product products[], int count);
void searchProducts(struct Product products[], int count, char *keyword);
void sellProduct(struct Product products[], int count, char *name);

int main() {
    struct Product products[100]; // Maximum 100 products allowed
    int count = 0; // Number of products in the inventory
    int choice;

    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add a product\n");
        printf("2. Display all products\n");
        printf("3. Search for a product\n");
        printf("4. Sell a product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add a new product to the inventory
                addProduct(products, &count);
                break;
            case 2:
                // Display all products in the inventory
                displayProducts(products, count);
                break;
            case 3:
                // Search for a product in the inventory
                char keyword[50];
                printf("\nEnter the name of the product to search: ");
                scanf("%s", keyword);
                searchProducts(products, count, keyword);
                break;
            case 4:
                // Sell a product from the inventory
                char name[50];
                printf("\nEnter the name of the product to sell: ");
                scanf("%s", name);
                sellProduct(products, count, name);
                break;
            case 5:
                // Exit the program
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}

// Function to add a new product to the inventory
void addProduct(struct Product products[], int *pCount) {
    struct Product product;
    printf("\nEnter the details of the product:\n");
    printf("Name: ");
    scanf("%s", product.name);
    printf("Price: ");
    scanf("%lf", &product.price);
    printf("Quantity: ");
    scanf("%d", &product.quantity);
    products[*pCount] = product;
    (*pCount)++;
    printf("Product added successfully.\n");
}

// Function to display all products in the inventory
void displayProducts(struct Product products[], int count) {
    if (count == 0) {
        printf("\nNo products found in the inventory.\n");
        return;
    }
    printf("\nName\tPrice\tQuantity\n");
    printf("----\t-----\t--------\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t$%.2lf\t%d\n", products[i].name, products[i].price, products[i].quantity);
    }
}

// Function to search for a product in the inventory
void searchProducts(struct Product products[], int count, char *keyword) {
    int found = 0;
    printf("\nName\tPrice\tQuantity\n");
    printf("----\t-----\t--------\n");
    for (int i = 0; i < count; i++) {
        if (strstr(products[i].name, keyword) != NULL) {
            printf("%s\t$%.2lf\t%d\n", products[i].name, products[i].price, products[i].quantity);
            found = 1;
        }
    }
    if (!found) {
        printf("No products found.\n");
    }
}

// Function to sell a product from the inventory
void sellProduct(struct Product products[], int count, char *name) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(products[i].name, name) == 0) {
            found = 1;
            if (products[i].quantity > 0) {
                products[i].quantity--;
                printf("\n%s sold successfully!\n", name);
            } else {
                printf("\n%s is out of stock.\n", name);
            }
            break;
        }
    }
    if (!found) {
        printf("\n%s not found in the inventory.\n", name);
    }
}