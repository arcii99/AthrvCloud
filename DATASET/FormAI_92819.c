//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define global constants and structures
#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

float calculate_total(Item items[], int num_items);
void print_receipt(Item items[], int num_items, float total);

int main() {
    // Declare local variables
    Item menu[MAX_ITEMS];
    Item order[MAX_ITEMS];
    int num_menu_items = 0;
    int num_order_items = 0;

    // Add menu items
    strcpy(menu[num_menu_items].name, "Coffee");
    menu[num_menu_items].quantity = 5;
    menu[num_menu_items].price = 2.5;
    num_menu_items++;

    strcpy(menu[num_menu_items].name, "Tea");
    menu[num_menu_items].quantity = 3;
    menu[num_menu_items].price = 1.5;
    num_menu_items++;

    // Display menu and accept order
    printf("Menu:\n");
    for (int i = 0; i < num_menu_items; i++) {
        printf("%s - $%.2f\n", menu[i].name, menu[i].price);
    }
    printf("\n");

    char input[MAX_NAME_LENGTH];
    do {
        printf("Enter item name (type 'done' to finish): ");
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        }

        int found_item = 0;
        for (int i = 0; i < num_menu_items; i++) {
            if (strcmp(input, menu[i].name) == 0) {
                found_item = 1;

                if (menu[i].quantity > 0) {
                    strcpy(order[num_order_items].name, menu[i].name);
                    order[num_order_items].price = menu[i].price;
                    order[num_order_items].quantity++;

                    menu[i].quantity--;
                    num_order_items++;

                    printf("%s added to order.\n", menu[i].name);
                } else {
                    printf("Sorry, we are out of %s at the moment.\n", menu[i].name);
                }

                break;
            }
        }

        if (!found_item) {
            printf("Sorry, we do not sell %s.\n", input);
        }
    } while (1);

    // Calculate total and print receipt
    float total = calculate_total(order, num_order_items);
    print_receipt(order, num_order_items, total);

    return 0;
}

float calculate_total(Item items[], int num_items) {
    float total = 0;

    for (int i = 0; i < num_items; i++) {
        total += items[i].price * items[i].quantity;
    }

    return total;
}

void print_receipt(Item items[], int num_items, float total) {
    printf("\nReceipt:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s x %d - $%.2f\n", items[i].name, items[i].quantity, items[i].price*items[i].quantity);
    }
    printf("Total: $%.2f\n", total);
}