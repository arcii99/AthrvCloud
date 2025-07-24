//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: high level of detail
/*
C Medical store management system
The program helps the store owner manage inventory and sales
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products in the inventory
#define MAX_PRODUCTS 100

// Define the maximum size of the product name
#define MAX_NAME_SIZE 50

// Define the maximum size of the product vendor name
#define MAX_VENDOR_SIZE 50

// Define the maximum size of the product category name
#define MAX_CATEGORY_SIZE 50

// Define the maximum size of the customer name
#define MAX_CUSTOMER_NAME_SIZE 50

// Define the maximum size of the customer phone number
#define MAX_PHONE_NUMBER_SIZE 15

// Define the maximum number of sales that can be stored in memory
#define MAX_SALES 1000

// Define a struct for a product
struct Product {
    char name[MAX_NAME_SIZE];
    char vendor[MAX_VENDOR_SIZE];
    char category[MAX_CATEGORY_SIZE];
    int id;
    double price;
    int quantity;
};

// Define a struct for a sale
struct Sale {
    int productId;
    int quantity;
    double totalPrice;
    char customerName[MAX_CUSTOMER_NAME_SIZE];
    char phoneNumber[MAX_PHONE_NUMBER_SIZE];
};

// Define an array for storing products
struct Product inventory[MAX_PRODUCTS];

// Define an array for storing sales
struct Sale sales[MAX_SALES];

// Define a function to add a product to the inventory
void addProduct(int id, char* name, char* vendor, char* category, double price, int quantity) {
    inventory[id].id = id;
    strcpy(inventory[id].name, name);
    strcpy(inventory[id].vendor, vendor);
    strcpy(inventory[id].category, category);
    inventory[id].price = price;
    inventory[id].quantity = quantity;
}

// Define a function to display all products in the inventory
void displayProducts() {
    printf("ID\tName\tVendor\tCategory\tPrice\tQuantity\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (inventory[i].id != 0) {
            printf("%d\t%s\t%s\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].vendor, inventory[i].category, inventory[i].price, inventory[i].quantity);
        }
    }
    printf("\n");
}

// Define a function to search for a product by name
void searchProduct(char* name) {
    int found = 0;
    printf("ID\tName\tVendor\tCategory\tPrice\tQuantity\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("%d\t%s\t%s\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].vendor, inventory[i].category, inventory[i].price, inventory[i].quantity);
            found = 1;
        }
    }
    if (!found) {
        printf("Product not found\n");
    }
    printf("\n");
}

// Define a function to update the quantity of a product in the inventory
void updateQuantity(int id, int quantity) {
    if (inventory[id].id != 0) {
        inventory[id].quantity += quantity;
        printf("Quantity updated successfully\n");
    }
    else {
        printf("Product not found\n");
    }
}

// Define a function to make a sale
void makeSale(int productId, int quantity, char* customerName, char* phoneNumber) {
    int index = -1;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (inventory[i].id == productId) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Product not found\n");
        return;
    }
    if (inventory[index].quantity < quantity) {
        printf("Insufficient quantity\n");
        return;
    }
    inventory[index].quantity -= quantity;
    double totalPrice = inventory[index].price * quantity;
    int saleIndex = -1;
    for (int i = 0; i < MAX_SALES; i++) {
        if (sales[i].productId == 0) {
            saleIndex = i;
            break;
        }
    }
    if (saleIndex == -1) {
        printf("Sale cannot be made. Sale memory full.\n");
        return;
    }
    sales[saleIndex].productId = productId;
    sales[saleIndex].quantity = quantity;
    sales[saleIndex].totalPrice = totalPrice;
    strcpy(sales[saleIndex].customerName, customerName);
    strcpy(sales[saleIndex].phoneNumber, phoneNumber);
}

// Define a function to display all sales
void displaySales() {
    printf("ID\tProduct ID\tQuantity\tTotal Price\tCustomer Name\tPhone Number\n");
    for (int i = 0; i < MAX_SALES; i++) {
        if (sales[i].productId != 0) {
            printf("%d\t%d\t\t%d\t\t%.2f\t\t%s\t\t%s\n", i, sales[i].productId, sales[i].quantity, sales[i].totalPrice, sales[i].customerName, sales[i].phoneNumber);
        }
    }
    printf("\n");
}

// Define the main function
int main() {
    // Add some initial products to the inventory
    addProduct(1, "Paracetamol", "GSK", "Pain Relief", 1.50, 100);
    addProduct(2, "Ibuprofen", "Pfizer", "Pain Relief", 2.00, 75);
    addProduct(3, "Aspirin", "Bayer", "Pain Relief", 1.00, 50);
    addProduct(4, "Vitamin C", "Amway", "Supplements", 5.00, 200);
    addProduct(5, "Iron supplement", "Walgreens", "Supplements", 3.50, 150);

    // Display the main menu
    int option = 0;
    while (option != 6) {
        printf("Welcome to C Medical store\n");
        printf("1. Add a product\n2. Display all products\n3. Search for a product by name\n4. Update quantity of a product\n5. Make a sale\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter product details:\n");
                int id, quantity;
                double price;
                char name[MAX_NAME_SIZE], vendor[MAX_VENDOR_SIZE], category[MAX_CATEGORY_SIZE];
                printf("Enter product ID: ");
                scanf("%d", &id);
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter vendor name: ");
                scanf("%s", vendor);
                printf("Enter category name: ");
                scanf("%s", category);
                printf("Enter product price: ");
                scanf("%lf", &price);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                addProduct(id, name, vendor, category, price, quantity);
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                printf("Enter product name: ");
                char productName[MAX_NAME_SIZE];
                scanf("%s", productName);
                searchProduct(productName);
                break;
            case 4:
                printf("Enter product ID: ");
                int productId, productQuantity;
                scanf("%d", &productId);
                printf("Enter quantity to add/subtract: ");
                scanf("%d", &productQuantity);
                updateQuantity(productId, productQuantity);
                break;
            case 5:
                printf("Enter details of the sale:\n");
                int saleProductId, saleQuantity;
                char customerName[MAX_CUSTOMER_NAME_SIZE], phoneNumber[MAX_PHONE_NUMBER_SIZE];
                printf("Enter product ID: ");
                scanf("%d", &saleProductId);
                printf("Enter quantity: ");
                scanf("%d", &saleQuantity);
                printf("Enter customer name: ");
                scanf("%s", customerName);
                printf("Enter phone number: ");
                scanf("%s", phoneNumber);
                makeSale(saleProductId, saleQuantity, customerName, phoneNumber);
                break;
            case 6:
                break;
            default:
                printf("Invalid option\n");
        }
    }

    // Display all sales at the end
    displaySales();

    return 0;
}