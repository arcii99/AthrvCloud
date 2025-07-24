//FormAI DATASET v1.0 Category: Product Inventory System ; Style: unmistakable
#include <stdio.h>
#include <string.h>

// Define Product Struct
struct Product {
    int id;
    char name[100];
    float price;
    int quantity;
};

// Initialize Product Array
struct Product products[10];

// Function to Add a Product
void addProduct(int id, char name[], float price, int quantity) {
    int index = -1;
    for (int i = 0; i < 10; i++) {
        if (products[i].id == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Product inventory is full.\n");
    } else {
        products[index].id = id;
        strcpy(products[index].name, name);
        products[index].price = price;
        products[index].quantity = quantity;
        printf("Product added successfully.\n");
    }
}

// Function to Remove a Product
void removeProduct(int id) {
    int index = -1;
    for (int i = 0; i < 10; i++) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Product not found.\n");
    } else {
        products[index].id = 0;
        strcpy(products[index].name, "");
        products[index].price = 0;
        products[index].quantity = 0;
        printf("Product removed successfully.\n");
    }
}

// Function to Update a Product
void updateProduct(int id, char name[], float price, int quantity) {
    int index = -1;
    for (int i = 0; i < 10; i++) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Product not found.\n");
    } else {
        strcpy(products[index].name, name);
        products[index].price = price;
        products[index].quantity = quantity;
        printf("Product updated successfully.\n");
    }
}

// Function to Display All Products
void displayProducts() {
    printf("Product Inventory:\n");
    for (int i = 0; i < 10; i++) {
        if (products[i].id != 0) {
            printf("%d | %s | $%.2f | %d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
        }
    }
}

// Main Function
int main() {
    // Set Initial Inventory
    products[0].id = 1;
    strcpy(products[0].name, "Apple");
    products[0].price = 0.5;
    products[0].quantity = 10;

    products[1].id = 2;
    strcpy(products[1].name, "Orange");
    products[1].price = 0.75;
    products[1].quantity = 7;

    products[2].id = 3;
    strcpy(products[2].name, "Banana");
    products[2].price = 0.4;
    products[2].quantity = 12;

    // Print Welcome Message
    printf("Welcome to the Product Inventory System!\n");

    // Main Loop
    while (1) {
        // Display Menu
        printf("\nMenu:\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Update Product\n");
        printf("4. Display Products\n");
        printf("5. Exit\n");

        // Get User Input
        printf("Enter a number to select an option: ");
        int option;
        scanf("%d", &option);

        if (option == 1) {
            // Add Product
            printf("Enter Product ID: ");
            int id;
            scanf("%d", &id);
            char name[100];
            printf("Enter Product Name: ");
            scanf("%s", name);
            float price;
            printf("Enter Product Price: ");
            scanf("%f", &price);
            int quantity;
            printf("Enter Product Quantity: ");
            scanf("%d", &quantity);
            addProduct(id, name, price, quantity);
        } else if (option == 2) {
            // Remove Product
            printf("Enter Product ID: ");
            int id;
            scanf("%d", &id);
            removeProduct(id);
        } else if (option == 3) {
            // Update Product
            printf("Enter Product ID: ");
            int id;
            scanf("%d", &id);
            char name[100];
            printf("Enter Product Name: ");
            scanf("%s", name);
            float price;
            printf("Enter Product Price: ");
            scanf("%f", &price);
            int quantity;
            printf("Enter Product Quantity: ");
            scanf("%d", &quantity);
            updateProduct(id, name, price, quantity);
        } else if (option == 4) {
            // Display Products
            displayProducts();
        } else if (option == 5) {
            // Exit Program
            break;
        } else {
            printf("Invalid option.\n");
        }
    }

    return 0;
}