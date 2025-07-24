//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_PRODUCT_NAME_LENGTH 50
#define MAX_LOCATION_NAME_LENGTH 20
#define MAX_ORDERS 100

typedef struct {
    char name[MAX_PRODUCT_NAME_LENGTH];
    int quantity;
    float price;
    char location[MAX_LOCATION_NAME_LENGTH];
} Product;

typedef struct {
    Product product;
    int quantity;
} OrderItem;

typedef struct {
    OrderItem items[MAX_PRODUCTS];
    int itemCount;
    float totalCost;
} Order;

Product products[MAX_PRODUCTS];
int productCount = 0;

Order orders[MAX_ORDERS];
int orderCount = 0;

void addProduct(char name[], int quantity, float price, char location[]) {
    Product product;
    strcpy(product.name, name);
    product.quantity = quantity;
    product.price = price;
    strcpy(product.location, location);
    products[productCount++] = product;
    printf("Product %s added\n", name);
}

void displayProducts() {
    printf("Product\tQuantity\tPrice\tLocation\n");
    for(int i = 0; i < productCount; i++) {
        Product product = products[i];
        printf("%s\t%d\t\t%.2f\t%s\n", product.name, product.quantity, product.price, product.location);
    }
}

void placeOrder(Order order) {
    orders[orderCount++] = order;
    printf("Order placed successfully for %.2f\n", order.totalCost);
}

void displayOrders() {
    printf("Order\tProduct\tQuantity\n");
    for(int i = 0; i < orderCount; i++) {
        Order order = orders[i];
        for(int j = 0; j < order.itemCount; j++) {
            OrderItem item = order.items[j];
            printf("%d\t%s\t%d\n", i+1, item.product.name, item.quantity);
        }
    }
}

int main() {
    addProduct("Apple", 20, 2.99, "A1");
    addProduct("Banana", 50, 1.99, "A2");

    displayProducts();

    Order order;
    order.itemCount = 0;
    order.totalCost = 0;

    OrderItem item1;
    item1.product = products[0];
    item1.quantity = 5;
    order.items[order.itemCount++] = item1;
    order.totalCost += item1.quantity * item1.product.price;

    OrderItem item2;
    item2.product = products[1];
    item2.quantity = 10;
    order.items[order.itemCount++] = item2;
    order.totalCost += item2.quantity * item2.product.price;

    placeOrder(order);

    displayOrders();

    return 0;
}