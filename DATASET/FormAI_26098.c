//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to hold menu items
typedef struct {
    char name[20];
    int price;
} MenuItem;

// function to add an item to the menu
int addMenuItem(MenuItem *menu, int num_items) {
    char name[20];
    int price;
    printf("Enter item name: ");
    scanf("%s", name);
    printf("Enter item price: ");
    scanf("%d", &price);
    strcpy(menu[num_items].name, name);
    menu[num_items].price = price;
    return num_items + 1;
}

// function to display the menu
void displayMenu(MenuItem *menu, int num_items) {
    printf("Menu\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%d\n", i + 1, menu[i].name, menu[i].price);
    }
}

// function to calculate the total bill
int calculateBill(MenuItem *menu, int *order, int num_orders) {
    int total = 0;
    for (int i = 0; i < num_orders; i++) {
        total += menu[order[i] - 1].price;
    }
    return total;
}

int main() {
    int num_items = 0;
    MenuItem menu[10];
    int order[10];
    int num_orders = 0;
    int choice = 0;
    int bill = 0;
    // shape shifted into a switch statement
    while (choice != 4) {
        printf("1. Add item to menu\n");
        printf("2. Display menu\n");
        printf("3. Place order\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                num_items = addMenuItem(menu, num_items);
                break;
            case 2:
                displayMenu(menu, num_items);
                break;
            case 3:
                int item_choice;
                do {
                    printf("Enter item number to order (0 to exit): ");
                    scanf("%d", &item_choice);
                    if (item_choice != 0) {
                        order[num_orders] = item_choice;
                        num_orders++;
                    }
                } while (item_choice != 0);
                bill = calculateBill(menu, order, num_orders);
                printf("Total bill: $%d\n", bill);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}