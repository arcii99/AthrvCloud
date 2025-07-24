//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Structures
typedef struct Menu_Item {
    int id;
    char name[50];
    float price;
} MenuItem;

typedef struct Order_Item {
    MenuItem menu_item;
    int quantity;
} OrderItem;

typedef struct Order {
    OrderItem order_items[50];
    int num_items;
    float total_price;
} Order;

// Function Prototypes
void display_menu(MenuItem menu[], int num_items);
float calculate_price(Order order);
void print_order(Order order);
void add_to_order(Order* order, MenuItem item, int quantity);

// Main function
int main() {

    // Initializations
    MenuItem menu[] = {
        { 1, "Black Coffee", 2.50 },
        { 2, "Latte", 3.00 },
        { 3, "Cappuccino", 3.20 },
        { 4, "Espresso", 2.00 },
        { 5, "Iced Coffee", 3.50 },
        { 6, "Hot Chocolate", 2.80 },
        { 7, "Tea", 2.00 }
    };

    Order order = {
        {},
        0,
        0.0
    };

    int menu_size = sizeof(menu) / sizeof(menu[0]);
    char choice;
    int item_id, quantity;
    MenuItem item;

    // Display menu to user
    display_menu(menu, menu_size);

    // Loop for user input
    while(1) {
        printf("\nEnter item id to add to order: ");
        scanf("%d", &item_id);

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Check if id is valid
        if(item_id < 1 || item_id > menu_size) {
            printf("Invalid item id. Please try again.\n");
            continue;
        }

        // Retrieve menu item
        item = menu[item_id - 1];

        // Add item to order
        add_to_order(&order, item, quantity);

        printf("\nItem added to order.\n");

        printf("\nAdd another item? (Y/N): ");
        scanf(" %c", &choice);

        // Check if user wants to add another item
        if(choice == 'Y' || choice == 'y') {
            continue;
        }
        else {
            break;
        }
    }

    printf("\n");

    // Calculate total order price
    order.total_price = calculate_price(order);

    // Print final order details
    printf("========= ORDER SUMMARY =========\n");
    print_order(order);
    printf("TOTAL: $%.2f\n", order.total_price);

    return 0;
}

// Function Definitions
void display_menu(MenuItem menu[], int num_items) {
    printf("============ MENU ============\n");
    printf("ID\tITEM\t\tPRICE\n");

    for(int i = 0; i < num_items; i++) {
        printf("%d\t%s\t\t$%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
}

void add_to_order(Order* order, MenuItem item, int quantity) {
    OrderItem order_item = { item, quantity };
    order->order_items[order->num_items] = order_item;
    order->num_items++;
}

float calculate_price(Order order) {
    float total = 0.0;

    for(int i = 0; i < order.num_items; i++) {
        total += order.order_items[i].menu_item.price * order.order_items[i].quantity;
    }

    return total;
}

void print_order(Order order) {
    printf("ITEM\t\tQUANTITY\tPRICE\n");

    for(int i = 0; i < order.num_items; i++) {
        printf("%s\t%d\t\t$%.2f\n", order.order_items[i].menu_item.name, order.order_items[i].quantity, order.order_items[i].menu_item.price * order.order_items[i].quantity);
    }
}