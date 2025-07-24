//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a single item
struct item {
    char name[50];
    float price;
    int qty;
};

// Function to display the menu
void display_menu(struct item *menu, int size) {
    printf("\n\n------------- MENU ---------------\n\n");
    printf("%-30s %-10s \n", "ITEM", "PRICE");
    for(int i=0; i<size; i++) {
        printf("%-30s $%-10.2f \n", menu[i].name, menu[i].price);
    }
}

// Function to check if an item is valid
int is_valid_item(struct item *menu, int size, int choice) {
    if(choice < 1 || choice > size) {
        return 0;
    }
    return 1;
}

// Function to get customer order
void get_order(struct item *menu, int size, struct item *cart) {
    int choice;
    do {
        display_menu(menu, size);
        printf("Enter the item number (0 to checkout): ");
        scanf("%d", &choice);
        if(choice == 0) {
            return;
        }
        if(!is_valid_item(menu, size, choice)) {
            printf("Invalid item. Please try again.\n");
            continue;
        }
        printf("Enter the quantity: ");
        scanf("%d", &cart[choice-1].qty);
        strcpy(cart[choice-1].name, menu[choice-1].name);
        cart[choice-1].price = menu[choice-1].price;
    } while(choice != 0);
}

// Function to calculate the order total
float get_total(struct item *cart, int size) {
    float total = 0.0f;
    for(int i=0; i<size; i++) {
        total += cart[i].price * cart[i].qty;
    }
    return total;
}

// Function to print the bill
void print_bill(struct item *cart, int size) {
    printf("\n\n\n--------- CAFE BILL ---------\n\n");
    printf("%-6s %-20s %-10s %-10s \n", "QTY", "ITEM", "PRICE", "TOTAL");
    for(int i=0; i<size; i++) {
        if(cart[i].qty > 0) {
            printf("%-6d %-20s $%-9.2f $%-9.2f \n", cart[i].qty, cart[i].name, cart[i].price, cart[i].price*cart[i].qty);
        }
    }
    printf("\n%-36s $%-9.2f \n\n", "TOTAL:", get_total(cart, size));
}

int main() {
    // Create the menu
    struct item menu[] = {
        {"Coffee", 2.50f, 0},
        {"Tea", 1.50f, 0},
        {"Sandwich", 4.50f, 0},
        {"Cake", 3.50f, 0},
        {"Muffin", 2.00f, 0}
    };
    int menu_size = sizeof(menu) / sizeof(menu[0]);

    // Create the cart
    struct item cart[menu_size];

    // Get the order
    get_order(menu, menu_size, cart);

    // Print the bill
    print_bill(cart, menu_size);

    return 0;
}