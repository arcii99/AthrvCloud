//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NAME_LEN 20
#define MAX_ORDER_SIZE 10

struct menu_item {
    char name[MAX_ITEM_NAME_LEN];
    double price;
};

struct order_item {
    char name[MAX_ITEM_NAME_LEN];
    double price;
};

struct order {
    int num_items;
    struct order_item items[MAX_ORDER_SIZE];
    double total_cost;
};

void print_menu(struct menu_item *menu, int menu_size) {
    printf("Menu:\n");
    for (int i = 0; i < menu_size; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
    printf("\n");
}

int get_menu_choice(int menu_size) {
    int choice;
    printf("Enter menu choice (1 - %d): ", menu_size);
    scanf("%d", &choice);
    getchar();  // consume newline character
    printf("\n");
    return choice;
}

void add_to_order(struct menu_item *menu, struct order *order, int menu_choice) {
    strcpy(order->items[order->num_items].name, menu[menu_choice-1].name);
    order->items[order->num_items].price = menu[menu_choice-1].price;
    order->num_items++;
    order->total_cost += menu[menu_choice-1].price;
}

void print_order(struct order *order) {
    printf("Order:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("%s - $%.2f\n", order->items[i].name, order->items[i].price);
    }
    printf("\nTotal Cost: $%.2f\n", order->total_cost);
}

int main() {
    printf("=====Welcome to Linus's Cafe!=====\n\n");

    // Initialize menu
    struct menu_item menu[] = {
            {"Espresso", 2.50},
            {"Latte", 3.00},
            {"Cappuccino", 3.50},
            {"Muffin", 2.00},
            {"Bagel", 1.50},
            {"Croissant", 2.25},
            {"Fruit Salad", 3.75},
            {"Yogurt Parfait", 4.00}
    };
    int menu_size = sizeof(menu) / sizeof(struct menu_item);

    // Initialize order
    struct order order = {
            .num_items = 0,
            .total_cost = 0.0
    };

    // Take order
    while (1) {
        print_menu(menu, menu_size);
        int menu_choice = get_menu_choice(menu_size);
        if (menu_choice < 1 || menu_choice > menu_size) {
            printf("Error: Invalid menu choice!\n");
            continue;
        }
        add_to_order(menu, &order, menu_choice);
        printf("Item added to order.\n\n");
        printf("Would you like to add another item? (y/n) ");
        char answer = getchar();
        printf("\n");
        getchar();  // consume newline character
        if (answer == 'n' || answer == 'N') {
            break;
        }
    }

    // Print order
    print_order(&order);

    return 0;
}