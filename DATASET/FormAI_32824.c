//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define constants */
#define MAX_MENU_ITEMS 100
#define MAX_NAME_LENGTH 50

/* Define struct to hold menu items */
struct MenuItem {
    char name[MAX_NAME_LENGTH];
    int price;
    int quantity;
};

/* Declare functions */
int print_menu(struct MenuItem *menu, int size);
int select_item(struct MenuItem *menu, int size);
void add_item(struct MenuItem *menu, int index);
void remove_item(struct MenuItem *menu, int index);

int main() {
    /* Initialize menu */
    struct MenuItem menu[MAX_MENU_ITEMS];
    menu[0].price = 5;
    strcpy(menu[0].name, "Coffee");
    menu[1].price = 6;
    strcpy(menu[1].name, "Tea");
    menu[2].price = 4;
    strcpy(menu[2].name, "Water");

    /* Declare variables */
    int choice = 0, quantity = 0, total = 0;
    char option;

    /* Main program loop */
    while (choice != 4) {
        printf("Welcome to Retro Cafe Billing System!\n");
        printf("---------------------------------------\n");
        printf("1. View Menu\n");
        printf("2. Add Item\n");
        printf("3. Remove Item\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                /* Print menu */
                total = print_menu(menu, MAX_MENU_ITEMS);
                printf("Total: $%d\n", total);
                break;

            case 2:
                /* Select item */
                int index = select_item(menu, MAX_MENU_ITEMS);
                if (index == -1) {
                    printf("Invalid choice.\n");
                    break;
                }

                /* Prompt for quantity */
                printf("Enter quantity: ");
                scanf("%d", &quantity);

                /* Update menu */
                menu[index].quantity += quantity;
                printf("%d %s added to the order.\n", quantity, menu[index].name);
                break;

            case 3:
                /* Select item */
                index = select_item(menu, MAX_MENU_ITEMS);
                if (index == -1) {
                    printf("Invalid choice.\n");
                    break;
                }

                /* Prompt for quantity */
                printf("Enter quantity: ");
                scanf("%d", &quantity);

                /* Check quantity */
                if (quantity > menu[index].quantity) {
                    printf("Not enough %s in order.\n", menu[index].name);
                    break;
                }

                /* Update menu */
                menu[index].quantity -= quantity;
                printf("%d %s removed from the order.\n", quantity, menu[index].name);
                break;

            case 4:
                /* Exit */
                printf("Thank you for using Retro Cafe Billing System!\n");
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }

        /* Prompt to continue */
        printf("Press any key to continue...");
        scanf(" %c", &option);
        system("cls"); // for Windows
        // system("clear"); // for Linux/MacOS
    }

    return 0;
}

/* Function to print the menu */
int print_menu(struct MenuItem *menu, int size) {
    int total = 0;
    printf("Menu:\n");
    printf("-----\n");
    for (int i = 0; i < size; i++) {
        if (menu[i].price == 0) {
            break;
        }
        printf("%d. %s - $%d\n", i+1, menu[i].name, menu[i].price);
        total += (menu[i].price * menu[i].quantity);
    }
    return total;
}

/* Function to select an item from the menu */
int select_item(struct MenuItem *menu, int size) {
    int choice = 0;
    printf("Select an item:\n");
    for (int i = 0; i < size; i++) {
        if (menu[i].price == 0) {
            break;
        }
        printf("%d. %s\n", i+1, menu[i].name);
    }
    scanf("%d", &choice);
    if (choice < 1 || choice > size) {
        return -1;
    }
    return choice - 1;
}

/* Function to add an item to the order */
void add_item(struct MenuItem *menu, int index) {
    menu[index].quantity++;
}

/* Function to remove an item from the order */
void remove_item(struct MenuItem *menu, int index) {
    if (menu[index].quantity > 0) {
        menu[index].quantity--;
    }
}