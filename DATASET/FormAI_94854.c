//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MENU_ITEMS 10
#define MAX_MENU_NAME_LENGTH 20

typedef struct {
    char name[MAX_MENU_NAME_LENGTH];
    float price;
} MenuItem;

typedef struct {
    MenuItem menu[MAX_MENU_ITEMS];
    int item_count;
} Menu;

Menu init_menu() {
    Menu menu;
    menu.item_count = 0;
    return menu;
}

void add_menu_item(Menu* menu, char name[], float price) {
    if (menu->item_count >= MAX_MENU_ITEMS) {
        printf("Menu is full, cannot add new item.");
        return;
    }

    strncpy(menu->menu[menu->item_count].name, name, MAX_MENU_NAME_LENGTH);
    menu->menu[menu->item_count].price = price;

    menu->item_count++;
}

void print_menu(Menu* menu) {
    printf("Menu\n");
    printf("====\n");
    printf("Item\tPrice\n");

    for (int i=0; i<menu->item_count; i++) {
        printf("%s\t%.2f\n", menu->menu[i].name, menu->menu[i].price);
    }
}

float calculate_bill(Menu* menu, int item_indexes[], int item_count) {
    float total = 0;

    for (int i=0; i<item_count; i++) {
        int index = item_indexes[i];
        if (index >= menu->item_count) {
            printf("Invalid item index: %d\n", index);
            continue;
        }

        total += menu->menu[index].price;
    }

    return total;
}

int main() {
    Menu menu = init_menu();

    add_menu_item(&menu, "Coffee", 1.50);
    add_menu_item(&menu, "Tea", 1.00);
    add_menu_item(&menu, "Muffin", 2.00);
    add_menu_item(&menu, "Bagel", 1.50);

    print_menu(&menu);

    int item_indexes[] = {0, 0, 2, 3};
    int item_count = sizeof(item_indexes) / sizeof(item_indexes[0]);

    float bill = calculate_bill(&menu, item_indexes, item_count);

    printf("Total bill: %.2f", bill);

    return 0;
}