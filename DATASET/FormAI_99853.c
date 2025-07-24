//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NAME_LEN 50
#define MAX_ITEM_NUM 50

struct menu_item {
    char name[MAX_ITEM_NAME_LEN];
    double price;
};

struct order {
    char item_name[MAX_ITEM_NAME_LEN];
    int quantity;
};

void print_menu(struct menu_item menu[]) {
    printf("Menu:\n");
    for (int i = 0; i < MAX_ITEM_NUM; i++) {
        if (menu[i].price > 0) {
            printf("%s: $%.2f\n", menu[i].name, menu[i].price);
        }
    }
}

int is_valid_menu_item(char* item, struct menu_item menu[]) {
    for (int i = 0; i < MAX_ITEM_NUM; i++) {
        if (strcmp(item, menu[i].name) == 0) {
            return 1;
        }
    }
    return 0;
}

void print_order(struct order order_list[], int n) {
    printf("Order:\n");
    for (int i = 0; i < n; i++) {
        printf("%s x%d\n", order_list[i].item_name, order_list[i].quantity);
    }
}

double calculate_total(struct order order_list[], int n, struct menu_item menu[]) {
    double total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < MAX_ITEM_NUM; j++) {
            if (strcmp(order_list[i].item_name, menu[j].name) == 0) {
                total += order_list[i].quantity * menu[j].price;
            }
        }
    }
    return total;
}

int main() {
    struct menu_item menu[MAX_ITEM_NUM];
    memset(menu, 0, sizeof(menu)); // Initialize all prices to 0
    
    menu[0].price = 3.50;
    strcpy(menu[0].name, "Plain Coffee");
    
    menu[1].price = 4.00;
    strcpy(menu[1].name, "Latte");
    
    menu[2].price = 4.50;
    strcpy(menu[2].name, "Cappuccino");
    
    int order_capacity = 10;
    struct order order_list[order_capacity];
    int order_count = 0;

    printf("Welcome to the Cafe!\n\n");
    print_menu(menu);
    printf("\n");

    while (1) {
        printf("What would you like to order (quit to exit)? ");
        char input[MAX_ITEM_NAME_LEN];
        scanf("%s", input);
        
        if (strcmp(input, "quit") == 0) {
            break;
        }
        
        if (is_valid_menu_item(input, menu)) {
            printf("How many of %s would you like? ", input);
            int quantity;
            scanf("%d", &quantity);
            
            struct order new_order;
            strcpy(new_order.item_name, input);
            new_order.quantity = quantity;
            
            if (order_count < order_capacity) {
                order_list[order_count] = new_order;
                order_count++;
                printf("Added to order!\n");
            } else {
                printf("Order list is full!\n");
            }
            
        } else {
            printf("Invalid menu item!\n");
        }
        
        printf("\n");
        print_menu(menu);
        printf("\n");
    }
    
    printf("\n");
    print_order(order_list, order_count);
    printf("\n");
    
    double total = calculate_total(order_list, order_count, menu);
    printf("Total: $%.2f\n", total);
    
    return 0;
}