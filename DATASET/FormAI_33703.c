//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Inventory {
    char name[20];
    int quantity;
    float price;
    bool on_sale;
};

struct Warehouse {
    struct Inventory inv[50];
    int total_stock;
    float total_cost;
    float total_value;
};

void update_stock(struct Warehouse *w) {
    w->total_stock = 0;
    w->total_cost = 0;
    w->total_value = 0;
    for (int i = 0; i < 50; i++) {
        w->total_stock += w->inv[i].quantity;
        w->total_cost += w->inv[i].quantity * w->inv[i].price;
        if (w->inv[i].on_sale) {
            w->total_value += w->inv[i].quantity * w->inv[i].price * 0.8;
        } else {
            w->total_value += w->inv[i].quantity * w->inv[i].price;
        }
    }
}

void add_item(struct Warehouse *w, char *name, int quantity, float price) {
    for (int i = 0; i < 50; i++) {
        if (strcmp(w->inv[i].name, name) == 0) {
            w->inv[i].quantity += quantity;
            w->inv[i].price = price;
            update_stock(w);
            return;
        }
    }
    for (int i = 0; i < 50; i++) {
        if (strcmp(w->inv[i].name, "") == 0) {
            strcpy(w->inv[i].name, name);
            w->inv[i].quantity = quantity;
            w->inv[i].price = price;
            update_stock(w);
            return;
        }
    }
}

void remove_item(struct Warehouse *w, char *name, int quantity) {
    for (int i = 0; i < 50; i++) {
        if (strcmp(w->inv[i].name, name) == 0) {
            if (w->inv[i].quantity >= quantity) {
                w->inv[i].quantity -= quantity;
                update_stock(w);
                return;
            } else {
                printf("Error: Not enough %s in stock\n", name);
                return;
            }
        }
    }
    printf("Error: %s not found\n", name);
}

void print_inventory(struct Warehouse *w) {
    printf("==============================\n");
    printf("|   Inventory of the Warehouse   |\n");
    printf("==============================\n");
    printf("| Name          | Quantity | Price | On Sale |\n");
    printf("|===============|==========|=======|=========|\n");
    for (int i = 0; i < 50; i++) {
        if (strcmp(w->inv[i].name, "") == 0) {
            break;
        }
        printf("| %14s | %8d | $%5.2f | %7s |\n", w->inv[i].name, w->inv[i].quantity, w->inv[i].price, w->inv[i].on_sale ? "Yes" : "No");
    }
    printf("|============================================|\n");
    printf("| Total Stock: %26d |\n", w->total_stock);
    printf("| Total Cost : $%25.2f |\n", w->total_cost);
    printf("| Total Value: $%25.2f |\n", w->total_value);
    printf("|============================================|\n");
}

int main() {
    struct Warehouse warehouse = {{}, 0, 0, 0};
    add_item(&warehouse, "Apple", 10, 1.5);
    add_item(&warehouse, "Banana", 5, 2.0);
    add_item(&warehouse, "Orange", 15, 1.0);
    add_item(&warehouse, "Grapes", 20, 2.5);
    add_item(&warehouse, "Mango", 8, 3.0);
    print_inventory(&warehouse);
    remove_item(&warehouse, "Apple", 5);
    remove_item(&warehouse, "Banana", 7);
    add_item(&warehouse, "Apple", 20, 2.0);
    add_item(&warehouse, "Cherry", 12, 4.0);
    print_inventory(&warehouse);
    return 0;
}