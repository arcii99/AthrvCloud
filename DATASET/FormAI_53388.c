//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_ITEM_NAME 50
#define MAX_ITEMS 10

typedef struct {
    char name[MAX_ITEM_NAME];
    double price;
    int quantity;
} MenuItem;

typedef struct {
    MenuItem items[MAX_ITEMS];
    int num_items;
} Menu;

typedef struct {
    Menu menu;
    double total_price;
    bool payment_received;
} Order;

typedef struct {
    Order orders[MAX_ITEMS];
    int num_orders;
} OrderList;

OrderList orders;

void add_item(Menu *menu, char name[], double price) {
    if (menu->num_items >= MAX_ITEMS) {
        printf("Menu is full. Cannot add item.\n");
        return;
    }
    MenuItem item;
    strcpy(item.name, name);
    item.price = price;
    item.quantity = 0;
    menu->items[menu->num_items++] = item;
    printf("Item added to the menu.\n");
}

void print_menu(Menu *menu) {
    printf("\n");
    printf("%-30s%-10s\n", "Item", "Price");
    for (int i = 0; i < menu->num_items; i++) {
        printf("%-30s$%-9.2f\n", menu->items[i].name, menu->items[i].price);
    }
    printf("\n");
}

bool is_valid_item_index(Menu *menu, int index) {
    return (index >= 0 && index < menu->num_items);
}

void place_order(Menu *menu, int item_index, int quantity) {
    if (!is_valid_item_index(menu, item_index)) {
        printf("Invalid item index.\n");
        return;
    }
    Order order;
    order.menu = *menu;
    MenuItem item = menu->items[item_index];
    order.total_price = item.price * quantity;
    item.quantity += quantity;
    order.menu.items[item_index] = item;
    order.payment_received = false;
    orders.orders[orders.num_orders++] = order;
    printf("Order placed successfully. Total price: $%.2f\n", order.total_price);
}

int search_order(int order_id) {
    for (int i = 0; i < orders.num_orders; i++) {
        if (i == order_id) {
            return i;
        }
    }
    return -1;
}

void receive_payment(int order_id) {
    int index = search_order(order_id);
    if (index == -1) {
        printf("Invalid order id.\n");
        return;
    }
    orders.orders[index].payment_received = true;
    printf("Payment received.\n");
}

void print_order(Order order) {
    printf("\nOrder Summary:\n");
    print_menu(&order.menu);
    printf("Total Price: $%.2f\n", order.total_price);
    if (order.payment_received) {
        printf("Payment received: Yes\n");
    } else {
        printf("Payment received: No\n");
    }
}

void print_all_orders() {
    if (orders.num_orders == 0) {
        printf("No orders placed yet.\n");
    } else {
        printf("\nAll Orders:\n");
        for (int i = 0; i < orders.num_orders; i++) {
            printf("Order %d:\n", i);
            print_order(orders.orders[i]);
        }
    }
}

int main() {
    Menu menu;
    menu.num_items = 0;

    // Initialize menu with some items
    add_item(&menu, "Coffee", 2.00);
    add_item(&menu, "Tea", 1.50);
    add_item(&menu, "Muffin", 2.50);

    bool done = false;
    while (!done) {
        printf("\nWhat would you like to do?\n");
        printf("1. View Menu\n");
        printf("2. Place Order\n");
        printf("3. Receive Payment\n");
        printf("4. View All Orders\n");
        printf("5. Quit\n\n");

        char choice_str[10];
        int choice = -1;
        while (choice == -1) {
            printf("Enter your choice: ");
            fgets(choice_str, 10, stdin);
            choice = atoi(choice_str);
            if (choice < 1 || choice > 5) {
                printf("Invalid choice. Try again.\n");
                choice = -1;
            }
        }

        switch (choice) {
            case 1:
                print_menu(&menu);
                break;
            case 2:
                printf("\nEnter Item Index: ");
                char item_index_str[10];
                int item_index = -1;
                while (item_index == -1) {
                    fgets(item_index_str, 10, stdin);
                    item_index = atoi(item_index_str);
                    if (!is_valid_item_index(&menu, item_index)) {
                        printf("Invalid item index. Try again.\n");
                        item_index = -1;
                    }
                }
                printf("Enter Quantity: ");
                char quantity_str[10];
                int quantity = -1;
                while (quantity == -1) {
                    fgets(quantity_str, 10, stdin);
                    quantity = atoi(quantity_str);
                    if (quantity < 1) {
                        printf("Invalid quantity. Try again.\n");
                        quantity = -1;
                    }
                }
                place_order(&menu, item_index, quantity);
                break;
            case 3:
                printf("\nEnter Order ID: ");
                char order_id_str[10];
                int order_id = -1;
                while (order_id == -1) {
                    fgets(order_id_str, 10, stdin);
                    order_id = atoi(order_id_str);
                    if (order_id < 0 || order_id >= orders.num_orders) {
                        printf("Invalid order id. Try again.\n");
                        order_id = -1;
                    }
                }
                receive_payment(order_id);
                break;
            case 4:
                print_all_orders();
                break;
            case 5:
                done = true;
                printf("\nThank you for using our cafe billing system.\n");
                break;
        }
    }

    return 0;
}