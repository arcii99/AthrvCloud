//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define maximum number of menu items */
#define MAX_ITEMS 10

struct MenuItem {
    char name[50];
    int price;
    int quantity;
};

struct Menu {
    struct MenuItem items[MAX_ITEMS];
    int num_items;
};

struct Order {
    struct MenuItem items[MAX_ITEMS];
    int num_items;
    float total_price;
};

/* Function to add a menu item */
void add_item(struct Menu *menu, char *name, int price) {
    struct MenuItem new_item;
    strncpy(new_item.name, name, sizeof(new_item.name));
    new_item.price = price;
    new_item.quantity = 0;
    menu->items[menu->num_items] = new_item;
    menu->num_items++;
}

/* Function to display the menu */
void display_menu(struct Menu *menu) {
    printf("============================\n");
    printf("        CAFE MENU\n");
    printf("============================\n");
    printf("NAME               PRICE\n");
    printf("------------------------\n");
    for(int i=0; i<menu->num_items; i++) {
        printf("%-20s $%d\n", menu->items[i].name, menu->items[i].price);
    }
}

/* Function to place an order */
void place_order(struct Menu *menu, struct Order *order) {
    int item_num;
    int quantity;
    char choice[10];
    do {
        /* Display the menu */
        display_menu(menu);
        
        /* Ask the user for their selection */
        printf("Enter item number (0 to stop): ");
        scanf("%d", &item_num);
        if(item_num == 0) {
            break;
        }
        
        /* Ask the user for the quantity */
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        
        /* Add the item to the order */
        struct MenuItem item = menu->items[item_num-1];
        item.quantity = quantity;
        order->items[order->num_items] = item;
        order->num_items++;
        order->total_price += item.price * quantity;
        
        /* Ask the user if they want to add another item */
        printf("Add another item? (y/n): ");
        scanf("%s", choice); 
    } while(choice[0] == 'y' || choice[0] == 'Y');
}

/* Function to print an order */
void print_order(struct Order *order) {
    printf("============================\n");
    printf("         ORDER\n");
    printf("============================\n");
    printf("NAME               QTY   PRICE\n");
    printf("-----------------------------\n");
    for(int i=0; i<order->num_items; i++) {
        struct MenuItem item = order->items[i];
        printf("%-20s %3d x $%2d = $%5d\n", item.name, item.quantity, item.price, item.quantity * item.price);
    }
    printf("-----------------------------\n");
    printf("TOTAL                             $%5.2f\n", order->total_price);
}

int main() {
    /* Initialize the menu */
    struct Menu menu;
    menu.num_items = 0;
    add_item(&menu, "Coffee", 3);
    add_item(&menu, "Tea", 2);
    add_item(&menu, "Juice", 4);
    add_item(&menu, "Sandwich", 5);
    add_item(&menu, "Cake", 6);
    
    /* Initialize the order */
    struct Order order;
    order.num_items = 0;
    order.total_price = 0.0;
    
    /* Place the order */
    place_order(&menu, &order);
    
    /* Print the order */
    print_order(&order);
    
    return 0;
}