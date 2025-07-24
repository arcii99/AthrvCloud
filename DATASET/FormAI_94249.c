//FormAI DATASET v1.0 Category: Product Inventory System ; Style: lively
#include <stdio.h>
#include <string.h>

/* Define a structure to hold inventory item details */
struct InventoryItem {
    int id;
    char name[50];
    int quantity;
    float price;
};

int main() {
    /* Declare an array of inventory items */
    struct InventoryItem inventory[50];
    int count = 0;

    /* Add some sample items to the inventory */
    inventory[count].id = 1;
    strcpy(inventory[count].name, "Mouse");
    inventory[count].quantity = 10;
    inventory[count].price = 15.99;
    count++;

    inventory[count].id = 2;
    strcpy(inventory[count].name, "Keyboard");
    inventory[count].quantity = 5;
    inventory[count].price = 39.99;
    count++;

    /* Menu loop */
    while (1) {
        printf("\n\n");
        printf("Menu\n");
        printf("=====\n");
        printf("1. View inventory\n");
        printf("2. Add item to inventory\n");
        printf("3. Remove item from inventory\n");
        printf("4. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                /* Print the current inventory */
                printf("\n\nCurrent Inventory:\n");
                printf("===================\n");
                printf("%-5s    %-20s    %-8s    %-10s\n", "ID", "Item Name", "Quantity", "Price");
                printf("------------------------------------------------------\n");
                for (int i = 0; i < count; i++) {
                    printf("%-5d    %-20s    %-8d    $%-9.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
                }
                printf("\n\n");
                break;
            }
            case 2: {
                /* Add an item to the inventory */
                printf("\n\nAdd Item to Inventory:\n");
                printf("=======================\n");

                inventory[count].id = count + 1;

                printf("Enter the item name: ");
                scanf("%s", inventory[count].name);

                printf("Enter the quantity: ");
                scanf("%d", &inventory[count].quantity);

                printf("Enter the price: ");
                scanf("%f", &inventory[count].price);

                count++;
                printf("\n\nItem added to inventory.\n\n");
                break;
            }
            case 3: {
                /* Remove an item from the inventory */
                printf("\n\nRemove Item from Inventory:\n");
                printf("================================\n");

                int item_id;
                printf("Enter the item ID to remove: ");
                scanf("%d", &item_id);

                int found_item = 0;
                for (int i = 0; i < count; i++) {
                    if (inventory[i].id == item_id) {
                        found_item = 1;
                        for (int j = i; j < count - 1; j++) {
                            inventory[j] = inventory[j + 1];
                        }
                        count--;
                        printf("\n\nItem removed from inventory.\n\n");
                        break;
                    }
                }
                if (found_item == 0) {
                    printf("\n\nItem not found in inventory.\n\n");
                }
                break;
            }
            case 4: {
                /* Exit the program */
                printf("\n\nExiting program...\n\n");
                return 0;
            }
            default: {
                /* Invalid choice */
                printf("\n\nInvalid choice!\n\n");
                break;
            }
        }
    }
    return 0;
}