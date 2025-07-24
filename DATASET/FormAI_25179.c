//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Dennis Ritchie
#include <stdio.h>

#define MAX_PRODUCTS 50
#define MAX_ORDERS 100

struct Product {
    int id;
    char name[50];
    int quantity;
};

struct Order {
    int id;
    int product_id;
    int quantity;
    char status[20];
};

struct Warehouse {
    struct Product products[MAX_PRODUCTS];
    struct Order orders[MAX_ORDERS];
};

void addProduct(struct Warehouse* warehouse, struct Product product) {
    for(int i = 0; i < MAX_PRODUCTS; i++) {
        if(warehouse->products[i].id == 0) {
            product.id = i + 1;
            warehouse->products[i] = product;
            printf("Product added successfully with ID %d\n", product.id);
            break;
        }
    }
}

void displayProducts(struct Warehouse warehouse) {
    printf("ID\tName\t\t\tQuantity\n");
    for(int i = 0; i < MAX_PRODUCTS; i++) {
        if(warehouse.products[i].id != 0) {
            printf("%d\t%-20s\t%d\n", warehouse.products[i].id, warehouse.products[i].name, warehouse.products[i].quantity);
        }
    }
}

void placeOrder(struct Warehouse* warehouse, struct Order order) {
    for(int i = 0; i < MAX_ORDERS; i++) {
        if(warehouse->orders[i].id == 0) {
            order.id = i + 1;
            warehouse->orders[i] = order;
            printf("Order placed successfully with ID %d\n", order.id);
            break;
        }
    }
}

void displayOrders(struct Warehouse warehouse) {
    printf("ID\tProduct ID\tQuantity\tStatus\n");
    for(int i = 0; i < MAX_ORDERS; i++) {
        if(warehouse.orders[i].id != 0) {
            printf("%d\t%d\t\t%d\t\t%s\n", warehouse.orders[i].id, warehouse.orders[i].product_id, warehouse.orders[i].quantity, warehouse.orders[i].status);
        }
    }
}

int main() {
    struct Warehouse warehouse = {0};
    struct Product product1 = {0};
    product1.id = 1;
    product1.quantity = 10;
    strcpy(product1.name, "Product 1");
    struct Product product2 = {0};
    product2.id = 2;
    product2.quantity = 5;
    strcpy(product2.name, "Product 2");
    addProduct(&warehouse, product1);
    addProduct(&warehouse, product2);
    displayProducts(warehouse);
    struct Order order1 = {0};
    order1.product_id = 1;
    order1.quantity = 2;
    strcpy(order1.status, "Pending");
    placeOrder(&warehouse, order1);
    displayOrders(warehouse);
    return 0;
}