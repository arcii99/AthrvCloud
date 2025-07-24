//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants used in our program
#define MAX_NUM_ITEMS 10
#define MAX_ITEM_NAME_LENGTH 50
#define MAX_ITEM_DESCRIPTION_LENGTH 100
#define MAX_WAREHOUSE_SIZE 100

typedef struct item {
    char name[MAX_ITEM_NAME_LENGTH];
    char description[MAX_ITEM_DESCRIPTION_LENGTH];
    int quantity;
    float price;
} Item;

int main() {
    // Initialize the items in our warehouse
    Item items[MAX_NUM_ITEMS];
    strcpy(items[0].name, "Shirt");
    items[0].quantity = 5;
    items[0].price = 24.99;
    strcpy(items[0].description, "A stylish and comfortable shirt for any occasion.");

    strcpy(items[1].name, "Jeans");
    items[1].quantity = 2;
    items[1].price = 59.99;
    strcpy(items[1].description, "High-quality jeans that fit like a glove and last for years.");

    int num_items = 2; // We have already initialized 2 items

    // Initialize the warehouse
    float warehouse[MAX_WAREHOUSE_SIZE];
    int warehouse_index = 0;

    // Print the main menu
    printf("Welcome to the Warehouse Management System!\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. List Items\n");
    printf("4. Exit\n");

    int choice;
    scanf("%d", &choice);

    while (choice != 4) {
        if (choice == 1) {
            // Add an item
            if (num_items >= MAX_NUM_ITEMS) {
                printf("Sorry, the warehouse is full.");
            } else {
                printf("Enter item name: ");
                scanf("%s", items[num_items].name);

                printf("Enter item description: ");
                scanf("%s", items[num_items].description);

                printf("Enter item quantity: ");
                scanf("%d", &items[num_items].quantity);

                printf("Enter item price: ");
                scanf("%f", &items[num_items].price);

                num_items++;
            }

        } else if (choice == 2) {
            // Remove an item
            printf("Enter item name to remove: ");
            char item_name[MAX_ITEM_NAME_LENGTH];
            scanf("%s", item_name);

            int index = -1;

            for (int i = 0; i < num_items; i++) {
                if (strcmp(items[i].name, item_name) == 0) {
                    index = i;
                    break;
                }
            }

            if (index == -1) {
                printf("Sorry, that item was not found.\n");
            } else {
                for (int i = index; i < num_items - 1; i++) {
                    items[i] = items[i+1];
                }

                num_items--;
                printf("Item removed successfully!\n");
            }

        } else if (choice == 3) {
            // List all items
            printf("\n%-20s %-20s %-10s %-10s", "Name", "Description", "Quantity", "Price");

            for (int i = 0; i < num_items; i++) {
                printf("\n%-20s %-20s %-10d $%-10.2f", items[i].name, items[i].description, items[i].quantity, items[i].price);
            }

            printf("\n");

        } else {
            printf("Invalid choice, please try again.\n");
        }

        // Print the main menu again
        printf("\n1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. List Items\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

    }

    printf("Thank you for using our Warehouse Management System!");

    return 0;
}