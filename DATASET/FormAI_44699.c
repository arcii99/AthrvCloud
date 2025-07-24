//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of products
#define MAX_PRODUCTS 100

// Define the struct for a product
struct Product {
    char name[50];
    int id;
    int quantity;
    float price;
};

int main() {
    // Define array of products
    struct Product products[MAX_PRODUCTS];
    int numOfProducts = 0;

    // Display the main menu
    int menuSelection;
    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add a new product\n");
        printf("2. Edit a product\n");
        printf("3. Remove a product\n");
        printf("4. View all products\n");
        printf("5. Exit program\n");
        printf("Select an option: ");
        scanf("%d", &menuSelection);

        // Handle the menu options
        switch (menuSelection) {
            case 1: // Add a new product
                printf("\nEnter product name: ");
                scanf("%s", products[numOfProducts].name);
                printf("Enter product ID: ");
                scanf("%d", &products[numOfProducts].id);
                printf("Enter product quantity: ");
                scanf("%d", &products[numOfProducts].quantity);
                printf("Enter product price: ");
                scanf("%f", &products[numOfProducts].price);
                numOfProducts++;
                printf("Product added successfully.\n\n");
                break;
            case 2: // Edit a product
                int editSelection;
                printf("\nEnter product ID to edit: ");
                scanf("%d", &editSelection);
                for (int i = 0; i < numOfProducts; i++) {
                    if (products[i].id == editSelection) {
                        printf("Enter product name: ");
                        scanf("%s", products[i].name);
                        printf("Enter product quantity: ");
                        scanf("%d", &products[i].quantity);
                        printf("Enter product price: ");
                        scanf("%f", &products[i].price);
                        printf("Product edited successfully.\n\n");
                        break;
                    }
                }
                break;
            case 3: // Remove a product
                int removeSelection;
                printf("\nEnter product ID to remove: ");
                scanf("%d", &removeSelection);
                for (int i = 0; i < numOfProducts; i++) {
                    if (products[i].id == removeSelection) {
                        for (int j = i; j < numOfProducts - 1; j++) {
                            products[j] = products[j+1];
                        }
                        numOfProducts--;
                        printf("Product removed successfully.\n\n");
                        break;
                    }
                }
                break;
            case 4: // View all products
                printf("\nProduct List\n");
                printf("ID | NAME | QUANTITY | PRICE\n");
                for (int i = 0; i < numOfProducts; i++) {
                    printf("%d | %s | %d | $%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
                }
                printf("\n");
                break;
            case 5: // Exit program
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid selection. Please try again.\n\n");
                break;
        }
    }
    return 0;
}