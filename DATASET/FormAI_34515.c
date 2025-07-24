//FormAI DATASET v1.0 Category: Product Inventory System ; Style: mind-bending
#include <stdio.h>

// define a struct called 'Product' to hold product information
typedef struct {
    int id;
    char name[30];
    float price;
    int quantity;
} Product;

// function to print a product record
void printProduct(Product p) {
    printf("Product ID: %d\n", p.id);
    printf("Name: %s\n", p.name);
    printf("Price: $%.2f\n", p.price);
    printf("Quantity: %d\n", p.quantity);
    printf("--------------------\n");
}

int main() {
    // create an array of Product structs
    Product products[5];

    // initialize the products array with sample data
    products[0].id = 1;
    strcpy(products[0].name, "iPhone 11");
    products[0].price = 699.00;
    products[0].quantity = 10;

    products[1].id = 2;
    strcpy(products[1].name, "Samsung Galaxy S20");
    products[1].price = 799.99;
    products[1].quantity = 5;

    products[2].id = 3;
    strcpy(products[2].name, "Nintendo Switch");
    products[2].price = 299.99;
    products[2].quantity = 8;

    products[3].id = 4;
    strcpy(products[3].name, "Canon EOS Rebel T7 DSLR Camera");
    products[3].price = 449.00;
    products[3].quantity = 3;

    products[4].id = 5;
    strcpy(products[4].name, "Bose QuietComfort 35 II Wireless Headphones");
    products[4].price = 299.00;
    products[4].quantity = 6;

    // print out a menu for the user to interact with the program
    printf("Welcome to the Product Inventory System!\n");
    printf("What would you like to do?\n");
    printf("1. Add a product\n");
    printf("2. View all products\n");
    printf("3. Search for a product\n");
    printf("4. Update a product\n");
    printf("5. Delete a product\n");
    printf("6. Exit\n");

    // loop to allow the user to perform multiple actions
    int choice = 0;
    while (choice != 6) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // add a new product
                printf("Enter product ID: ");
                scanf("%d", &products[5].id);
                printf("Enter product name: ");
                scanf("%s", products[5].name);
                printf("Enter product price: ");
                scanf("%f", &products[5].price);
                printf("Enter product quantity: ");
                scanf("%d", &products[5].quantity);
                printf("Product added!\n");
                break;

            case 2:
                // view all products
                printf("=== ALL PRODUCTS ===\n");
                for (int i = 0; i < 5; i++) {
                    printProduct(products[i]);
                }
                break;

            case 3:
                // search for a product by name
                printf("Enter product name to search for: ");
                char searchName[30];
                scanf("%s", searchName);
                for (int i = 0; i < 5; i++) {
                    if (strcmp(searchName, products[i].name) == 0) {
                        printf("Product found!\n");
                        printProduct(products[i]);
                    }
                }
                break;

            case 4:
                // update a product by ID
                printf("Enter product ID to update: ");
                int updateID;
                scanf("%d", &updateID);
                for (int i = 0; i < 5; i++) {
                    if (updateID == products[i].id) {
                        printf("Enter new product name: ");
                        scanf("%s", products[i].name);
                        printf("Enter new product price: ");
                        scanf("%f", &products[i].price);
                        printf("Enter new product quantity: ");
                        scanf("%d", &products[i].quantity);
                        printf("Product updated!\n");
                    }
                }
                break;

            case 5:
                // delete a product by ID
                printf("Enter product ID to delete: ");
                int deleteID;
                scanf("%d", &deleteID);
                for (int i = 0; i < 5; i++) {
                    if (deleteID == products[i].id) {
                        for (int j = i; j < 4; j++) {
                            products[j] = products[j+1];
                        }
                        printf("Product deleted!\n");
                    }
                }
                break;

            case 6:
                // quit the program
                printf("Goodbye!\n");
                break;

            default:
                // invalid input
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}