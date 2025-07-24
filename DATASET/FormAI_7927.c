//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: active
#include <stdio.h>

// Define constant variables
#define MAX_PRODUCTS 1000
#define MAX_ORDERS 1000

// Define struct for product
struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
};

// Define struct for order
struct Order {
    int id;
    char customer_name[50];
    struct Product products[10];
    int quantity;
};

// Declare global arrays for products and orders
struct Product products[MAX_PRODUCTS];
struct Order orders[MAX_ORDERS];
int num_products = 0;
int num_orders = 0;

// Function to add a new product to arrays
void addProduct(int id, char name[], int quantity, float price) {
    if (num_products < MAX_PRODUCTS) {
        products[num_products].id = id;
        strcpy(products[num_products].name, name);
        products[num_products].quantity = quantity;
        products[num_products].price = price;
        num_products++;
        printf("Product added successfully!\n");
    } else {
        printf("Error: maximum number of products reached.\n");
    }
}

// Function to search for a product by ID
struct Product* searchProduct(int id) {
    for (int i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            return &products[i];
        }
    }
    return NULL;
}

// Function to update a product's quantity
void updateQuantity(struct Product* product, int quantity) {
    if (product != NULL) {
        product->quantity += quantity;
        printf("Quantity updated successfully!\n");
    } else {
        printf("Error: product not found.\n");
    }
}

// Function to add a new order to arrays
void addOrder(int id, char name[], struct Product products[], int quantity) {
    if (num_orders < MAX_ORDERS) {
        orders[num_orders].id = id;
        strcpy(orders[num_orders].customer_name, name);
        for (int i = 0; i < quantity; i++) {
            orders[num_orders].products[i] = products[i];
        }
        orders[num_orders].quantity = quantity;
        num_orders++;
        printf("Order added successfully!\n");
    } else {
        printf("Error: maximum number of orders reached.\n");
    }
}

// Function to remove an order from arrays
void removeOrder(int id) {
    for (int i = 0; i < num_orders; i++) {
        if (orders[i].id == id) {
            for (int j = i; j < num_orders - 1; j++) {
                orders[j] = orders[j+1];
            }
            num_orders--;
            printf("Order removed successfully!\n");
            return;
        }
    }
    printf("Error: order not found.\n");
}

int main() {
    // Sample usage of functions
    addProduct(101, "Pen", 500, 1.50);
    addProduct(102, "Notebook", 300, 3.75);
    
    struct Product* product = searchProduct(101);
    if (product != NULL) {
        updateQuantity(product, -100);
    }
    
    struct Product products[] = {products[0], products[1]};
    addOrder(201, "John Smith", products, 2);
    removeOrder(201);
    
    return 0;
}