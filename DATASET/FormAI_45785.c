//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: protected
#include <stdio.h>

typedef struct {
    char product_name[50];
    int quantity;
    float price;
} Product;

typedef struct {
    int id;
    char name[50];
    int capacity;
    int num_products;
    Product products[100];
} Warehouse;

int num_warehouses = 0;
Warehouse warehouses[50];

void add_warehouse() {
    if (num_warehouses >= 50) {
        printf("Error: Maximum number of warehouses reached\n");
        return;
    }
    Warehouse w;
    w.id = num_warehouses + 1;
    printf("Enter warehouse name: ");
    scanf("%s", w.name);
    printf("Enter maximum capacity: ");
    scanf("%d", &w.capacity);
    w.num_products = 0;
    warehouses[num_warehouses] = w;
    printf("Warehouse added successfully!\n");
    num_warehouses++;
}

void add_product() {
    int warehouse_id;
    printf("Enter warehouse ID: ");
    scanf("%d", &warehouse_id);
    if (warehouse_id < 1 || warehouse_id > num_warehouses) {
        printf("Error: Invalid warehouse ID\n");
        return;
    }
    Warehouse* w = &warehouses[warehouse_id - 1];
    if (w->capacity <= w->num_products) {
        printf("Error: Warehouse is full\n");
        return;
    }
    Product p;
    printf("Enter product name: ");
    scanf("%s", p.product_name);
    printf("Enter quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter price: ");
    scanf("%f", &p.price);
    w->products[w->num_products] = p;
    w->num_products++;
    printf("Product added successfully!\n");
}

void list_products() {
    int warehouse_id;
    printf("Enter warehouse ID: ");
    scanf("%d", &warehouse_id);
    if (warehouse_id < 1 || warehouse_id > num_warehouses) {
        printf("Error: Invalid warehouse ID\n");
        return;
    }
    Warehouse* w = &warehouses[warehouse_id - 1];
    printf("Warehouse Name: %s\n", w->name);
    printf("Product Name     Quantity    Price\n");
    for (int i = 0; i < w->num_products; i++) {
        Product* p = &w->products[i];
        printf("%-16s %-11d $%.2f\n", p->product_name, p->quantity, p->price);
    }
}

int main() {
    int choice;
    while (1) {
        printf("Warehouse Management System\n");
        printf("----------------------------\n");
        printf("1. Add Warehouse\n");
        printf("2. Add Product\n");
        printf("3. List Products\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_warehouse();
                break;
            case 2:
                add_product();
                break;
            case 3:
                list_products();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}