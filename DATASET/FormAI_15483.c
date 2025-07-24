//FormAI DATASET v1.0 Category: Product Inventory System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100 // Maximum items in the inventory
#define MAX_ITEM_NAME 50 // Maximum characters in the name of the item

// Structure of an item in the inventory
typedef struct item {
    int id;
    char name[MAX_ITEM_NAME];
    double price;
    int quantity;
} Item;

// Global variables
Item inventory[MAX_ITEMS];
int num_items = 0;

// Function declarations
void add_item();
void display_inventory();
void sell_item();
void search_item();

int main() {
    int choice = 0;

    while (choice != 5) {
        printf("\n  --- PRODUCT INVENTORY SYSTEM ---  ");
        printf("\n1. Add Item");
        printf("\n2. Display Inventory");
        printf("\n3. Sell Item");
        printf("\n4. Search Item");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                display_inventory();
                break;
            case 3:
                sell_item();
                break;
            case 4:
                search_item();
                break;
            case 5:
                printf("\nExiting Program...");
                exit(0);
            default:
                printf("\nInvalid choice, try again...");
                break;
        }
    }

    return 0;
}

// Function to add an item to the inventory
void add_item() {
    Item item;

    printf("\nEnter item name: ");
    scanf("%s", item.name);

    printf("Enter item price: ");
    scanf("%lf", &item.price);

    printf("Enter item quantity: ");
    scanf("%d", &item.quantity);

    item.id = num_items + 1;

    inventory[num_items] = item;
    num_items++;

    printf("\nItem added to inventory.");
}

// Function to display the inventory
void display_inventory() {
    int i;

    printf("\n%10s| %20s| %10s| %10s|", "ID", "Item Name", "Price", "Quantity");

    for (i = 0; i < num_items; i++) {
        printf("\n%10d| %20s| %10.2lf| %10d|", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

// Function to sell an item from the inventory
void sell_item() {
    int item_id, i, quantity;

    printf("\nEnter item ID to sell: ");
    scanf("%d", &item_id);

    for (i = 0; i < num_items; i++) {
        if (inventory[i].id == item_id) {
            if (inventory[i].quantity <= 0) {
                printf("\nItem out of stock.");
                break;
            }

            printf("Enter quantity to sell: ");
            scanf("%d", &quantity);

            if (inventory[i].quantity < quantity) {
                printf("\nInsufficient quantity of item.");
                break;
            }

            inventory[i].quantity -= quantity;
            printf("\n%d %s sold for $%.2lf", quantity, inventory[i].name, inventory[i].price * quantity);

            break;
        }
    }

    if (i == num_items) {
        printf("\nItem not found in inventory.");
    }
}

// Function to search for an item in the inventory
void search_item() {
    char name[MAX_ITEM_NAME];
    int i;

    printf("\nEnter item name to search: ");
    scanf("%s", name);

    for (i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("\n%10s| %20s| %10s| %10s|", "ID", "Item Name", "Price", "Quantity");
            printf("\n%10d| %20s| %10.2lf| %10d|", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);

            break;
        }
    }

    if (i == num_items) {
        printf("\nItem not found in inventory.");
    }
}