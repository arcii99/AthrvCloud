//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the warehouse
#define MAX_WAREHOUSE_SIZE 1000

// Define the length of the SKU code
#define SKU_LENGTH 8

// Define the maximum size of a product name
#define MAX_PRODUCT_NAME 50

// Define the maximum number of products that can be added to the warehouse
#define MAX_PRODUCTS 500

// Define the maximum number of categories that can be added to the warehouse
#define MAX_CATEGORIES 100

// Define the maximum size of a category name
#define MAX_CATEGORY_NAME 30

// Define the maximum number of transactions that can be stored in the system
#define MAX_TRANSACTIONS 10000

// Define a struct for the product information
typedef struct product {
    char sku[SKU_LENGTH+1];
    char name[MAX_PRODUCT_NAME+1];
    float price;
    int quantity;
    char category[MAX_CATEGORY_NAME+1];
} product_t;

// Define a struct for the transaction information
typedef struct transaction {
    char sku[SKU_LENGTH+1];
    int quantity;
    float total_price;
    char transaction_type;
} transaction_t;

// Define an array to store the products in the warehouse
product_t products[MAX_PRODUCTS];

// Define an array to store the categories in the warehouse
char categories[MAX_CATEGORIES][MAX_CATEGORY_NAME+1];

// Define an array to store the transactions in the system
transaction_t transactions[MAX_TRANSACTIONS];

// Define a variable to keep track of the number of products in the warehouse
int num_products = 0;

// Define a variable to keep track of the number of categories in the warehouse
int num_categories = 0;

// Define a variable to keep track of the number of transactions in the system
int num_transactions = 0;

/**
 * Function to add a new product to the warehouse
 **/
void add_product() {
    // Check if the maximum number of products has been reached
    if (num_products == MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached!\n");
        return;
    }

    // Get the SKU code of the product
    printf("Enter SKU code (8 characters): ");
    fflush(stdout);
    scanf("%s", products[num_products].sku);

    // Check if the SKU code is valid
    if (strlen(products[num_products].sku) != SKU_LENGTH) {
        printf("Error: SKU code should be 8 characters!\n");
        return;
    }

    // Check if the SKU code already exists in the warehouse
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].sku, products[num_products].sku) == 0) {
            printf("Error: SKU code already exists in the warehouse!\n");
            return;
        }
    }

    // Get the name of the product
    printf("Enter name of the product (maximum 50 characters): ");
    fflush(stdout);
    scanf("%s", products[num_products].name);

    // Get the price of the product
    printf("Enter price of the product: ");
    fflush(stdout);
    scanf("%f", &products[num_products].price);

    // Get the quantity of the product
    printf("Enter quantity of the product: ");
    fflush(stdout);
    scanf("%d", &products[num_products].quantity);

    // Get the category of the product
    printf("Enter category of the product (maximum 30 characters): ");
    fflush(stdout);
    scanf("%s", products[num_products].category);

    // Check if the category already exists in the warehouse
    int category_exists = 0;
    for (int i = 0; i < num_categories; i++) {
        if (strcmp(categories[i], products[num_products].category) == 0) {
            category_exists = 1;
            break;
        }
    }
    if (!category_exists) {
        strcpy(categories[num_categories], products[num_products].category);
        num_categories++;
    }

    // Print a message to confirm that the product has been added
    printf("Product added to the warehouse successfully!\n");

    // Increment the number of products in the warehouse
    num_products++;
}

/**
 * Function to remove a product from the warehouse
 **/
void remove_product() {
    // Check if there are no products in the warehouse
    if (num_products == 0) {
        printf("Error: No products in the warehouse!\n");
        return;
    }

    // Get the SKU code of the product to be removed
    printf("Enter SKU code of the product to be removed: ");
    fflush(stdout);
    char sku[SKU_LENGTH+1];
    scanf("%s", sku);

    // Find the index of the product in the warehouse
    int index = -1;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].sku, sku) == 0) {
            index = i;
            break;
        }
    }

    // Check if the product was found in the warehouse
    if (index == -1) {
        printf("Error: Product not found in the warehouse!\n");
        return;
    }

    // Shift all the products to the left of the product to be removed by one position to the right
    for (int i = index; i < num_products-1; i++) {
        products[i] = products[i+1];
    }

    // Print a message to confirm that the product has been removed
    printf("Product removed from the warehouse successfully!\n");

    // Decrement the number of products in the warehouse
    num_products--;
}

/**
 * Function to display a list of all the products in the warehouse
 **/
void list_products() {
    // Check if there are no products in the warehouse
    if (num_products == 0) {
        printf("No products in the warehouse!\n");
        return;
    }

    // Print the header
    printf("%-12s %-30s %-10s %-10s %-30s\n", "SKU", "Product Name", "Price", "Quantity", "Category");
    printf("----------------------------------------------------------------------------------------------------\n");

    // Loop through all the products in the warehouse and print their information
    for (int i = 0; i < num_products; i++) {
        printf("%-12s %-30s %-10.2f %-10d %-30s\n", products[i].sku, products[i].name, products[i].price, products[i].quantity, products[i].category);
    }
}

/**
 * Function to add a new transaction to the system
 **/
void add_transaction() {
    // Check if the maximum number of transactions has been reached
    if (num_transactions == MAX_TRANSACTIONS) {
        printf("Error: Maximum number of transactions reached!\n");
        return;
    }

    // Get the SKU code of the product
    printf("Enter SKU code of the product: ");
    fflush(stdout);
    scanf("%s", transactions[num_transactions].sku);

    // Check if the SKU code is valid
    if (strlen(transactions[num_transactions].sku) != SKU_LENGTH) {
        printf("Error: SKU code should be 8 characters!\n");
        return;
    }

    // Find the index of the product in the warehouse
    int product_index = -1;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].sku, transactions[num_transactions].sku) == 0) {
            product_index = i;
            break;
        }
    }

    // Check if the product exists in the warehouse
    if (product_index == -1) {
        printf("Error: Product not found in the warehouse!\n");
        return;
    }

    // Get the type of the transaction (Sale or Purchase)
    printf("Enter type of transaction (S for Sale, P for Purchase): ");
    fflush(stdout);
    scanf(" %c", &transactions[num_transactions].transaction_type);

    // Check if the transaction type is valid
    if (transactions[num_transactions].transaction_type != 'S' && transactions[num_transactions].transaction_type != 'P') {
        printf("Error: Invalid transaction type!\n");
        return;
    }

    // Get the quantity of the product
    printf("Enter quantity of the product: ");
    fflush(stdout);
    scanf("%d", &transactions[num_transactions].quantity);

    // Check if the quantity is valid
    if (transactions[num_transactions].quantity < 1) {
        printf("Error: Quantity should be greater than zero!\n");
        return;
    }

    // Calculate the total price of the transaction
    if (transactions[num_transactions].transaction_type == 'S') {
        transactions[num_transactions].total_price = products[product_index].price * transactions[num_transactions].quantity;
        products[product_index].quantity -= transactions[num_transactions].quantity;
    } else {
        transactions[num_transactions].total_price = -1 * products[product_index].price * transactions[num_transactions].quantity;
        products[product_index].quantity += transactions[num_transactions].quantity;
    }

    // Print a message to confirm that the transaction has been added
    printf("Transaction added to the system successfully!\n");

    // Increment the number of transactions in the system
    num_transactions++;
}

/**
 * Function to display all the transactions in the system
 **/
void list_transactions() {
    // Check if there are no transactions in the system
    if (num_transactions == 0) {
        printf("No transactions in the system!\n");
        return;
    }

    // Print the header
    printf("%-12s %-15s %-10s %-12s %-15s\n", "SKU", "Type", "Quantity", "Total Price", "Transaction Time");
    printf("-------------------------------------------------------------------------------------------\n");

    // Loop through all the transactions in the system and print their information
    for (int i = 0; i < num_transactions; i++) {
        printf("%-12s %-15c %-10d %-12.2f %-15ld\n", transactions[i].sku, transactions[i].transaction_type, transactions[i].quantity, transactions[i].total_price, time(NULL));
    }
}

/**
 * Function to display the total sales by category
 **/
void sales_by_category() {
    // Check if there are no transactions in the system
    if (num_transactions == 0) {
        printf("No transactions in the system!\n");
        return;
    }

    // Loop through all the categories and calculate the total sales for each category
    for (int i = 0; i < num_categories; i++) {
        float total_sales = 0;
        for (int j = 0; j < num_transactions; j++) {
            if (strcmp(products[j].category, categories[i]) == 0) {
                total_sales += transactions[j].total_price;
            }
        }
        printf("Total sales for %s category: %.2f\n", categories[i], total_sales);
    }
}

/**
 * Main function
 **/
int main() {
    // Print a welcome message
    printf("Welcome to the Warehouse Management System!\n");

    // Show the menu options
    char choice;
    do {
        printf("\nMenu options:\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. List all products\n");
        printf("4. Add a transaction\n");
        printf("5. List all transactions\n");
        printf("6. Show total sales by category\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        fflush(stdout);

        // Read the user's choice
        scanf(" %c", &choice);

        // Handle the user's choice
        switch (choice) {
            case '1':
                add_product();
                break;
            case '2':
                remove_product();
                break;
            case '3':
                list_products();
                break;
            case '4':
                add_transaction();
                break;
            case '5':
                list_transactions();
                break;
            case '6':
                sales_by_category();
                break;
            case '0':
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please try again!\n");
                break;
        }
    } while (1);

    return 0;
}