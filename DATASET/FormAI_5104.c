//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 20
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} item_t;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} order_t;

item_t menu[MAX_ITEMS] = {
    {"Coffee", 2.5},
    {"Mocha", 3.0},
    {"Latte", 3.5},
    {"Cappuccino", 3.0},
    {"Espresso", 2.0},
    {"Hot Chocolate", 3.0},
};

int num_items_menu = 6;

float calculate_total(order_t orders[], int num_orders);

int main() {
    float total = 0.0;
    order_t orders[MAX_ITEMS];
    int num_orders = 0;

    printf("Welcome to the C Cafe!\n");
    printf("Menu:\n");
    for (int i = 0; i < num_items_menu; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }

    while (1) {
        printf("Enter your order (item number, x quantity): ");
        int item_num, quantity;
        if(scanf("%d, %d", &item_num, &quantity) != 2) {
            printf("Invalid input. Try again.\n");
            continue;
        }
        if (item_num < 1 || item_num > num_items_menu) {
            printf("Invalid item number. Try again.\n");
            continue;
        }
        if (num_orders >= MAX_ITEMS) {
            printf("Maximum order limit reached.\n");
            break;
        }

        order_t order = {"", 0};
        strcpy(order.name, menu[item_num-1].name);
        order.quantity = quantity;
        orders[num_orders++] = order;

        printf("Item added to order.\n");

        char choice[50];
        printf("Would you like to order again? (y/n)\n");
        scanf("%s", choice);

        if(strcmp(choice, "y") == 0) {
            continue;
        } else if(strcmp(choice, "n") == 0) {
            break;
        } else {
            printf("Invalid input. Try again.\n");
            break;
        }
    }

    printf("\nOrder summary:\n");
    for (int i = 0; i < num_orders; i++) {
        printf("%d x %s - $%.2f\n", orders[i].quantity, orders[i].name, menu[i].price);
    }

    total = calculate_total(orders, num_orders);
    printf("\nTotal: $%.2f\n", total);

    printf("\nThank you for choosing the C Cafe! Have a nice day.\n");

    return 0;
}

float calculate_total(order_t orders[], int num_orders) {
    float total = 0.0;
    for (int i = 0; i < num_orders; i++) {
        for(int j = 0; j < num_items_menu; j++) {
            if(strcmp(orders[i].name, menu[j].name) == 0) {
                total += orders[i].quantity * menu[j].price;
                break;
            }
        }
    }
    return total;
}