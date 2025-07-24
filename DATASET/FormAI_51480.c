//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Sherlock Holmes
/* 
   The Case of the Missing Warehouse Inventory
   A Sherlock Holmes C Programming Adventure 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LENGTH 50

// Declare a struct for the warehouse items
struct item {
    char name[MAX_NAME_LENGTH];
    int quantity;
};

// Declare global variables
int num_items = 0;
struct item inventory[MAX_ITEMS];

// Function to add an item to the inventory
void add_item() {
    printf("Enter the name of the item: ");
    scanf("%s", inventory[num_items].name);

    printf("Enter the quantity: ");
    scanf("%d", &inventory[num_items].quantity);

    printf("Item added to inventory!\n");
    num_items++;
}

// Function to remove an item from the inventory
void remove_item() {
    char name[MAX_NAME_LENGTH];
    int found = 0;

    printf("Enter the name of the item to remove: ");
    scanf("%s", name);

    // Loop through the inventory to find the item
    for (int i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("%s found in inventory and removed!\n", name);
            found = 1;

            // Shift remaining items left to fill gap
            for (int j = i; j < num_items - 1; j++) {
                inventory[j] = inventory[j+1];
            }

            num_items--;
            break;
        }
    }

    if (!found) {
        printf("%s not found in inventory!\n", name);
    }
}

// Function to display all items in the inventory
void display_inventory() {
    printf("Inventory:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
    }
}

int main() {
    char decision[MAX_NAME_LENGTH];

    printf("Welcome to the Warehouse Management System!\n");

    // Initialize the inventory with some items
    strcpy(inventory[0].name, "Hammer");
    inventory[0].quantity = 10;
    
    strcpy(inventory[1].name, "Nails");
    inventory[1].quantity = 500;
    
    strcpy(inventory[2].name, "Saw");
    inventory[2].quantity = 5;

    num_items = 3;

    // Loop until user quits
    while (1) {
        printf("\nEnter 'A' to add an item, 'R' to remove an item, 'D' to display inventory, or 'Q' to quit: ");
        scanf("%s", decision);

        if (strcmp(decision, "A") == 0) {
            add_item();
        }
        else if (strcmp(decision, "R") == 0) {
            remove_item();
        }
        else if (strcmp(decision, "D") == 0) {
            display_inventory();
        }
        else if (strcmp(decision, "Q") == 0) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid decision. Please try again.\n");
        }
    }

    return 0;
}