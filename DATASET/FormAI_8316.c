//FormAI DATASET v1.0 Category: Database simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int id;
    char name[50];
    float price;
} Product;

typedef struct {
    int id;
    char name[50];
    char address[100];
    float balance;
} Customer;

int main() {
    // Initialize product catalog
    Product products[5];
    products[0].id = 1;
    strcpy(products[0].name, "Apple");
    products[0].price = 0.5;

    products[1].id = 2;
    strcpy(products[1].name, "Banana");
    products[1].price = 0.3;

    products[2].id = 3;
    strcpy(products[2].name, "Orange");
    products[2].price = 0.4;

    products[3].id = 4;
    strcpy(products[3].name, "Grapes");
    products[3].price = 0.7;

    products[4].id = 5;
    strcpy(products[4].name, "Watermelon");
    products[4].price = 2.5;

    // Initialize customer database
    Customer customers[3];
    customers[0].id = 1;
    strcpy(customers[0].name, "John Smith");
    strcpy(customers[0].address, "123 Main St");
    customers[0].balance = 10.0;

    customers[1].id = 2;
    strcpy(customers[1].name, "Jane Doe");
    strcpy(customers[1].address, "456 Oak St");
    customers[1].balance = 5.0;

    customers[2].id = 3;
    strcpy(customers[2].name, "Bob Lee");
    strcpy(customers[2].address, "789 Elm St");
    customers[2].balance = 20.0;

    printf("Welcome to the store!\n");

    while (true) {
        printf("Enter your customer ID: ");
        int customerId;
        scanf("%d", &customerId);

        // Find customer by ID
        Customer* customer = NULL;
        for (int i = 0; i < 3; i++) {
            if (customers[i].id == customerId) {
                customer = &customers[i];
                break;
            }
        }

        if (customer == NULL) {
            printf("Customer not found. Please try again.\n");
            continue;
        }

        printf("Welcome, %s!\n", customer->name);
        printf("Your current balance is $%.2f\n", customer->balance);

        while (true) {
            printf("Available products:\n");
            printf("ID\tName\tPrice\n");
            for (int i = 0; i < 5; i++) {
                printf("%d\t%s\t$%.2f\n", products[i].id, products[i].name, products[i].price);
            }

            printf("Enter product ID (or 0 to check out): ");
            int productId;
            scanf("%d", &productId);

            if (productId == 0) {
                printf("Thanks for shopping with us, %s!\n", customer->name);
                break;
            }

            // Find product by ID
            Product* product = NULL;
            for (int i = 0; i < 5; i++) {
                if (products[i].id == productId) {
                    product = &products[i];
                    break;
                }
            }

            if (product == NULL) {
                printf("Product not found. Please try again.\n");
                continue;
            }

            if (product->price > customer->balance) {
                printf("Insufficient funds. Please try again.\n");
                continue;
            }

            // Update customer balance and display purchase confirmation
            customer->balance -= product->price;
            printf("Purchase confirmed: %s ($%.2f)\n", product->name, product->price);
        }
    }

    return 0;
}