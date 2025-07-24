//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a struct to represent the menu item
struct MenuItem {
    char *name;
    double price;
};

// Declare a struct to represent the order item
struct OrderItem {
    struct MenuItem *menu_item;
    int quantity;
};

// Declare a function to print the menu
void printMenu(struct MenuItem *menu_items, int menu_size) {
    printf("MENU\n");
    printf("-------------------\n");
    for (int i = 0; i < menu_size; i++) {
        printf("%s - $%.2f\n", menu_items[i].name, menu_items[i].price);
    }
    printf("-------------------\n");
}

// Declare a function to create an order item
struct OrderItem *createOrderItem(struct MenuItem *menu_item, int quantity) {
    struct OrderItem *order_item = malloc(sizeof(struct OrderItem));
    order_item->menu_item = menu_item;
    order_item->quantity = quantity;
    return order_item;
}

// Declare a function to calculate the total for an order
double calculateTotal(struct OrderItem **order_items, int order_size) {
    double total = 0;
    for (int i = 0; i < order_size; i++) {
        total += order_items[i]->menu_item->price * order_items[i]->quantity;
    }
    return total;
}

int main() {
    // Define the menu
    struct MenuItem menu[] = {
        {"Coffee", 3.50},
        {"Tea", 2.75},
        {"Hot Chocolate", 4.25},
        {"Cappuccino", 4.50},
        {"Espresso", 3.75}
    };
    int menu_size = sizeof(menu) / sizeof(menu[0]);

    // Print the menu
    printMenu(menu, menu_size);

    // Initialize the order list
    struct OrderItem *order[10];
    int order_size = 0;

    // Get the user's order
    printf("Enter your order (enter 'done' when finished):\n");
    char input[100];
    while (1) {
        printf("> ");
        scanf("%s", input);
        if (strcmp(input, "done") == 0) {
            break;
        }
        int quantity;
        printf("Quantity: ");
        scanf("%d", &quantity);
        for (int i = 0; i < menu_size; i++) {
            if (strcmp(input, menu[i].name) == 0) {
                order[order_size++] = createOrderItem(&menu[i], quantity);
                break;
            }
        }
    }

    // Calculate the total and print the receipt
    double total = calculateTotal(order, order_size);
    printf("\nRECEIPT\n");
    printf("-------------------\n");
    for (int i = 0; i < order_size; i++) {
        printf("%dx %s - $%.2f\n", order[i]->quantity, order[i]->menu_item->name,
               order[i]->menu_item->price * order[i]->quantity);
    }
    printf("-------------------\n");
    printf("Total: $%.2f\n", total);

    // Free the memory
    for (int i = 0; i < order_size; i++) {
        free(order[i]);
    }

    return 0;
}